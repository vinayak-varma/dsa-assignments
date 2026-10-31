#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node* insert (int value)
{
    Node* newNode=new Node;
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    
    return newNode;
}
Node* createBST(Node* root, int value)
{
    if (root==NULL)
    {
        return insert(value);
    }
    if (value<root->data)
        root->left=createBST(root->left, value);

    else if (value>root->data)
        root->right = createBST (root->right, value);

    return root;
}
void inorder (Node* root)
{
    if (root==NULL)
        return;
    
    Node* current=root;
    Node* pre;

    while (current!=NULL)
    {
        if (current->left==NULL)
        {
            cout<<current->data<< " ";
            current=current->right;
        }
        else 
        {
            pre=current->left;
            while (pre->right!=NULL && pre->right!=current)
                pre=pre->right;

            if(pre->right==NULL)
            {
                pre->right=current;
                current=current->left;
            }
            else
            {
                pre->right=NULL;
                cout<<current->data<<" ";
                current=current->right;
            }
        }
    }
}
void preorder (Node* root)
{
    if (root==NULL)
        return;

    Node* current=root;
    Node* pre;
    while (current!=NULL)
    {
        if (current->left==NULL)
        {
            cout<<current->data<<" ";
            current=current->right;
        }
        else 
        {
            pre=current->left;
            while (pre->right!=NULL && pre->right!=current)
                pre=pre->right;
            if(pre->right==NULL)
            {
                cout<<current->data<< " ";
                pre->right=current;
                current=current->left;
            }
            else
            {
                pre->right=NULL;
                current=current->right;
            }
        }
    }
}
int main()
{
    Node* root=NULL;
    int choice, n, val;
    cout<<"----CREATE BST----"<<endl;
    cout<<"Enter number of nodes: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter value "<<(i+1)<<": ";
        cin>>val;
        root=createBST(root, val);
    }
    do
    {
        cout<<"\n\n ----BST MENU----"<<endl;
        cout<<"1.Inorder Traversal"<<endl;
        cout<<"2.Preorder Traversal"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            cout << "Inorder Traversal:";
            inorder(root);
            cout << endl;
            break;
            case 2:
            cout << "Preorder Traversal:";
            preorder(root);
            cout << endl;
            break;
            case 3: // Exit
            break;
            default:
            cout << "Invalid! Try again" << endl;
        }
    }
    while (choice!=3);
    return 0;
}