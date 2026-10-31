#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *head=NULL;
void insertBeginning(int value)
{
    Node *newNode=new Node;
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    cout<<"Book ID "<<value<<" inserted at the beginning"<<endl;
}
void insertEnd(int value)
{
    Node *newNode=new Node;
    newNode->data=value;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    cout<<"Book ID "<<value<<" inserted at the end"<<endl;
}
void deleteBeginning()
{
    if(head==NULL)
    {
        cout<<"Library list is empty\n"<<endl;
        return;
    }
    Node *temp=head;
    cout<<"Deleted Book ID "<<head->data<<" from the beginning"<<endl;
    head=head->next;
    delete temp;
}
void display()
{
    if(head==NULL)
    {
        cout<<"Library list is empty\n"<<endl;
        return;
    }
    cout<<"Book IDS in Library:";
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
    int choice,value;
    while(1)
    {
        cout<<"\nLibrary Management System\n";
        cout<<"1. Insert Book ID at Beginning\n";
        cout<<"2. Insert Book ID at End\n";
        cout<<"3. Delete Book ID from Beginning\n";
        cout<<"4. Display Book IDs\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter Book ID to insert at beginning: ";
                cin>>value;
                insertBeginning(value);
                break;
            case 2:
                cout<<"Enter Book ID to insert at end: ";
                cin>>value;
                insertEnd(value);
                break;
            case 3:
                deleteBeginning();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                cout<<"Invalid choice! Please try again.\n"<<endl;
        }
    }
    return 0;
}