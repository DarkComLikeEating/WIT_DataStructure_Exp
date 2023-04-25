/*----------������solution.cpp��ʵ��----------*/
#include "queue.h"

using namespace std;

int main() {
    int n, k; //n����������k������
    int nowOut = 1; //Ҫ����ĳ�����
    cout << "input n:" << endl;
    cin >> n;
    cout << "input k:" << endl;
    cin >> k;
    cout << "input train:" << endl;
    SqQueue * dusk[k + 2]; //0��k-1����������k������죬k+1�������
    for (int i = 0; i < n; i ++) {
        int a;
        cin >> a;
        EnQueue(dusk[k], a);
        cout << "enter" << endl;
    }
    while (!QueueEmpty(dusk[k])) {  //���첻Ϊ�յ�ʱ��ѭ��
        cout << "enter" << endl;
        int flag = 0;//�жϽ����µĻ���컹�ǽ���ǿջ�����
        //0�����µĻ���������0����ǿջ�����
        int z = 0;//�ж��Ƿ���ֱ�ӳ��졣0Ϊ����ֱ�ӳ��죬��0Ϊ�ɳ���
        int flag_end = 0;//�Ƴ�ѭ���ж�
        //��������ͷ����ŵ�������Ҫ����ĳ����
        if (ShowFront(dusk[k]) == nowOut) { 
            for (int i = 0; i < k; i ++) {  //��������ѭ���죬�ҳ�һ���յ�
                if (QueueEmpty(dusk[i])) {  //�ҵ��յ�ѭ���죬���
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
        //�������ֱ�ӳ��죬�ҵ��ȵ�ǰҪ����ĳ���С�ķǿչ���������
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
        //����Ҳ�����ǰҪ����ĳ���С�ķǿչ�������ҿյĻ������������
        if (flag == 0) {
            for (int i = 0; i < k; i ++) {
                if (QueueEmpty(dusk[i])) {
                    cout << ShowFront(dusk[k]) << " train in " << i + 1 << " trace." << endl;
                    int j = ShowFront(dusk[k]);
                    EnQueue(dusk[i], j);
                    DeQueue(dusk[k], j);
                    break;
                }
                if (i == k - 1) {   //����Ҳ����µĻ���������ô���ERROR������ѭ��
                    cout << "ERROR!" << endl;
                    flag_end = 1;   //����ѭ���ı�־
                    break;
                }
            }
        }
        //�˳�whileѭ��
        if (flag_end == 1) {
            break;
        }
        //�������зǿչ����ͷ����ţ��������Ҫ���ӵĳ���ţ��ͳ��첢������ѭ��
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