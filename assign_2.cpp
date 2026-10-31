/* Vinayak Sameer Varma
Roll No: 59
Div: SY12 B
Topic: Assignment 2 */
#include <iostream>
using namespace std;
#define MAX 5
class Queue
{
    private:
        int queue[MAX];
        int front,rear;
    
    public:
        Queue()
        {
            front=rear=-1;
        }
        void enqueue(int value)
        {
            if(rear==MAX-1)
            {
                cout<<"Queue Overflow"<<endl;
                return;
            }
            if(front==-1)
            {
                front=0;
            }
            rear++;
            queue[rear]=value;
            cout<<value<<" added to the queue"<<endl;
        }
        void dequeue()
        {
            if(front==-1||front>rear)
            {
                cout<<"Queue Underflow"<<endl;
                return;
            }
            cout<<queue[front]<<" served and removed from the queue"<<endl;
            front++;
            if(front>rear)
            {
                front=rear=-1;
            }
        }
        void display()
        {
            if(front==-1)
            {
                cout<<"Queue is empty"<<endl;
                return;
            }
            cout<<"Customers in Queue:"<<endl;
            for(int i=front;i<=rear;i++)
            {
                cout<<queue[i]<<" ";
            }
            cout<<endl;
        }
};
int main()
{
    Queue q;
    int choice,customer;
    do
    {
        cout<<"\n===== Ticket Booking Queue====="<<endl;
        cout<<"\n1. Enqueue Customer"<<endl;
        cout<<"2. Dequeue Customer"<<endl;
        cout<<"3. Display Queue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter Customer ID:";
                cin>>customer;
                q.enqueue(customer);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout<<"Exiting Program..."<<endl;
                break;
            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
    while(choice!=4);
    return 0;
}