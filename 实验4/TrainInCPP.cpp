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
    int n , k ;//n����������k������
    int nowOut = 1;//Ҫ����ĳ�����
    cout<<"input n:";
    cin >> n;
    cout<<"input k:";
    cin >> k;
    cout<<"input train"<<endl;
    Queue dusk[k+2];//0��k-1����������k������죬k+1�������
    for(int i = 0 ; i < n ; i++)//������ӳ����
    {
        int a ;
        cin>>a;
        dusk[k].inQueue(a);
    }
    while(!dusk[k].isEmpty())//���첻Ϊ�յ�ʱ��ѭ��
    {
        int flag = 0;//�жϽ����µĻ���컹�ǽ���ǿջ�������
        //0�����µĻ���������0����ǿջ�����
        int z = 0;//�ж��Ƿ���ֱ�ӳ��졣0Ϊ����ֱ�ӳ��죬��0Ϊ�ɳ��졣
        int flag_end = 0;//�˳�ѭ���ж�
        if(dusk[k].showfront()==nowOut)//��������ͷ����ŵ�������Ҫ����ĳ����
        {
            for(int i = 0 ; i < k ; i++)//��������ѭ���죬�ҳ�һ���յ�
            {
                if(dusk[i].isEmpty())//�ҵ��յ�ѭ���죬���
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
        if(z==0)//�������ֱ�ӳ��죬�ҵ��ȵ�ǰҪ����ĳ���С�ķǿչ���������
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
        //����Ҳ����ȵ�ǰҪ����ĳ���С�ķǿչ�������ҿյĻ���죬�����
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
                if(i==k-1)//����Ҳ����µĻ���죬��ô���ERROR������ѭ��
                {
                    cout<<"ERROR!"<<endl;
                    flag_end = 1;//����ѭ���ı�־
                    break;
                }
            }
        }
        if(flag_end == 1)//�˳�whileѭ��
        {
            break;
        }
        //�������зǿչ����ͷ����ţ��������Ҫ���ӵĳ���ţ��ͳ��첢������ѭ��
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
 
    dusk[k+1].printf();//��ӡ���쳵��˳��
}