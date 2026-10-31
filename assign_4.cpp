#include <iostream>
using namespace std;
struct Node 
{
    int bookID;
    Node *left;
    Node *right;
};
Node *createNode(int value)
{
    Node *newNode=new Node;
    newNode->bookID=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
Node *insert(Node *root,int value)
{
    if(root==NULL)
    {
        return createNode(value);
    }
    if(value<root->bookID)
    {
        root->left=insert(root->left,value);
    }
    else
    {
        root->right=insert(root->right,value);
    }
    return root;
}
void inorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->bookID<<" ";
        inorder(root->left);
        inorder(root->right);
    }
}
void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->bookID<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->bookID<<" ";
    }
}
int main()
{
    Node *root=NULL;
    int choice,value;
    do
    {
        cout<<"\n===== University Library Catalog =====\n";
        cout<<"1. Insert Book ID\n";
        cout<<"2. Inorder Traversal\n";
        cout<<"3. Preorder Traversal\n";
        cout<<"4. Postorder Traversal\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter Book ID:";
                cin>>value;
                root=insert(root,value);
                cout<<"Book ID "<<value<<" inserted successfully\n";
                break;
            case 2:
                cout<<"Inorder Traversal: ";
                inorder(root);
                cout<<endl;
                break;
            case 3:
                cout<<"Preorder Traversal: ";
                preorder(root);
                cout<<endl;
                break;
            case 4:
                cout<<"Postorder Traversal: ";
                postorder(root);
                cout<<endl;
                break;
            case 5:
                cout<<"Exiting the program\n";
                break;
            default:
                cout<<"Invalid choice!\n";
        }
    }
    while(choice!=5);
    return 0;
}