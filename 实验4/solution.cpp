/*----------以下是solution.cpp的实现----------*/
#include "queue.h"

using namespace std;

int main() {
    int n, k; //n代表车箱数，k代表轨道
    int nowOut = 1; //要输出的车厢编号
    cout << "input n:" << endl;
    cin >> n;
    cout << "input k:" << endl;
    cin >> k;
    cout << "input train:" << endl;
    SqQueue * dusk[k + 2]; //0到k-1代表缓冲轨道，k代表入轨，k+1代表出轨
    for (int i = 0; i < n; i ++) {
        int a;
        cin >> a;
        EnQueue(dusk[k], a);
        cout << "enter" << endl;
    }
    while (!QueueEmpty(dusk[k])) {  //出轨不为空的时候循环
        cout << "enter" << endl;
        int flag = 0;//判断进入新的缓冲轨还是进入非空缓冲轨道
        //0进入新的缓冲轨道，非0进入非空缓冲轨道
        int z = 0;//判断是否能直接出轨。0为不能直接出轨，非0为可出轨
        int flag_end = 0;//推出循环判定
        //如果出轨队头车厢号等于现在要出轨的车厢号
        if (ShowFront(dusk[k]) == nowOut) { 
            for (int i = 0; i < k; i ++) {  //遍历所有循环轨，找出一个空的
                if (QueueEmpty(dusk[i])) {  //找到空的循环轨，输出
                    int j = ShowFront(dusk[k]);
                    cout << j << " train by trace " << i + 1 << " out." << endl;
                    EnQueue(dusk[k + 1], j);
                    nowOut ++;
                    DeQueue(dusk[k], j);
                    z ++;
                    flag ++;
                }   
            }
        }
        cout << "enter" << endl;
        //如果不能直接出轨，找到比当前要出轨的车厢小的非空轨道，并入轨
        if (z == 0) {
            for (int i = 0; i < k; i ++) {
                if (!QueueEmpty(dusk[i]) && (ShowRear(dusk[i]) < ShowFront(dusk[k]))) {
                    cout << ShowFront(dusk[k]) << " train in " << i + 1 << " trace." << endl;
                    int j = ShowFront(dusk[k]);
                    EnQueue(dusk[i], j);
                    DeQueue(dusk[k], j);
                    flag ++;
                    break;
                }
            }
        }
        //如果找不到当前要出轨的车厢小的非空轨道，就找空的缓冲轨道，并入轨
        if (flag == 0) {
            for (int i = 0; i < k; i ++) {
                if (QueueEmpty(dusk[i])) {
                    cout << ShowFront(dusk[k]) << " train in " << i + 1 << " trace." << endl;
                    int j = ShowFront(dusk[k]);
                    EnQueue(dusk[i], j);
                    DeQueue(dusk[k], j);
                    break;
                }
                if (i == k - 1) {   //如果找不到新的缓冲轨道，那么输出ERROR，结束循环
                    cout << "ERROR!" << endl;
                    flag_end = 1;   //结束循环的标志
                    break;
                }
            }
        }
        //退出while循环
        if (flag_end == 1) {
            break;
        }
        //遍历所有非空轨道对头车厢号，如果等于要出队的车厢号，就出轨并且重新循环
        for (int i = 0; i < k; i ++) {
            if (!QueueEmpty(dusk[i]) && nowOut == ShowFront(dusk[i])) {
                cout << ShowFront(dusk[i]) << " train by trace " << i + 1 << " out." << endl;
                EnQueue(dusk[k + 1], ShowFront(dusk[i]));
                int j = 0;
                DeQueue(dusk[i], j);
                nowOut ++;
                i = -1;
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        int j = 0;
        DeQueue(dusk[k + 1], j);
        cout << j << " ";
    }
    Print(dusk[k + 1]);

    return 0;
}