// #include <iostream>
// #include "queue.h"

// using namespace std;

// int main() {
//     int a[9] = {3, 6, 9, 2, 4, 7, 1, 8, 5};

//     SqQueue * q;
//     bool flag = true;
//     cout << flag;
//     for (int i = 0; i < 9; i ++) if (EnQueue(q, a[i])) cout << "1 ";
//     ShowFront(q);
//     ShowRear(q);
//     Print(q);
//     return 0;
// }

#include<iostream>
using namespace std;
class Queue
{
public:
    struct Node
    {
        int data;
        Node * next;
        Node():next(NULL) {}
        Node(int a):data(a),next(NULL) {}
    };
    Node * Front;
    Node * rear;
    int length;
    Queue()
    {
        Node * p = new Node();
        Front = p;
        rear = p;
        length = 0;
    }
    int inQueue(int a)
    {
        Node * p = new Node(a);
        rear -> next = p;
        rear = rear -> next;
        length ++;
    }
    int showrear()
    {
        return rear->data;
    }
    int showfront()
    {
        return Front->next->data;
    }
    void outQueue()
    {
 
        Node * p = Front -> next;
        Front -> next = p -> next;
        delete p;
        length--;
    }
    void printf()
    {
        Node * p = Front -> next;
        for(int i = 0 ; i < length ; i++)
        {
            cout<<p->data<<" ";
            p = p -> next;
        }
    }
    bool isEmpty()
    {
        return length == 0;
    }
 
};
int main()
{
    int n , k ;//n代表车厢数，k代表轨道
    int nowOut = 1;//要输出的车厢编号
    cout<<"input n:";
    cin >> n;
    cout<<"input k:";
    cin >> k;
    cout<<"input train"<<endl;
    Queue dusk[k+2];//0到k-1代表缓冲轨道，k代表入轨，k+1代表出轨
    for(int i = 0 ; i < n ; i++)//输入入队车厢号
    {
        int a ;
        cin>>a;
        dusk[k].inQueue(a);
    }
    while(!dusk[k].isEmpty())//出轨不为空的时候循环
    {
        int flag = 0;//判断进入新的缓冲轨还是进入非空缓冲轨道。
        //0进入新的缓冲轨道，非0进入非空缓冲轨道
        int z = 0;//判断是否能直接出轨。0为不能直接出轨，非0为可出轨。
        int flag_end = 0;//退出循环判定
        if(dusk[k].showfront()==nowOut)//如果出轨队头车厢号等于现在要出轨的车厢号
        {
            for(int i = 0 ; i < k ; i++)//遍历所有循环轨，找出一个空的
            {
                if(dusk[i].isEmpty())//找到空的循环轨，输出
                {
 
                    cout<<dusk[k].showfront()<<" train by trace "<<i+1<<" out."<<endl;
                    dusk[k+1].inQueue(dusk[k].showfront());
                    nowOut++;
                    dusk[k].outQueue();
                    z++;
                    flag++;
                    break;
                }
            }
        }
        if(z==0)//如果不能直接出轨，找到比当前要出轨的车厢小的非空轨道，并入轨
        {
            for(int i = 0 ; i < k ; i++)
            {
                if(!dusk[i].isEmpty()&&(dusk[i].showrear()<dusk[k].showfront()))
                {
                    cout<<dusk[k].showfront()<<" train in "<<i+1<<" trace."<<endl;
                    dusk[i].inQueue(dusk[k].showfront());
                    dusk[k].outQueue();
                    flag ++;
                    break;
                }
            }
        }
        //如果找不到比当前要出轨的车厢小的非空轨道，就找空的缓冲轨，并入轨
        if(flag == 0)
        {
            for(int i = 0 ; i < k ; i++)
            {
                if(dusk[i].isEmpty())
                {
                    cout<<dusk[k].showfront()<<" train in "<<i+1<<" trace."<<endl;
                    dusk[i].inQueue(dusk[k].showfront());
                    dusk[k].outQueue();
                    break;
                }
                if(i==k-1)//如果找不到新的缓冲轨，那么输出ERROR，结束循环
                {
                    cout<<"ERROR!"<<endl;
                    flag_end = 1;//结束循环的标志
                    break;
                }
            }
        }
        if(flag_end == 1)//退出while循环
        {
            break;
        }
        //遍历所有非空轨道队头车厢号，如果等于要出队的车厢号，就出轨并且重新循环
        for(int i = 0 ; i < k ; i++)
        {
            if(!dusk[i].isEmpty()&&dusk[i].showfront()==nowOut)
            {
                cout<<dusk[i].showfront()<<" train by trace "<<i+1<<" out."<<endl;
                dusk[k+1].inQueue(dusk[i].showfront());
                dusk[i].outQueue();
                nowOut++;
                i = -1;
            }
        }
    }
 
    dusk[k+1].printf();//打印出轨车厢顺序
}