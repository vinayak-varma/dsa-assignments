#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct Node
{
    int employeeId;
    Node *left;
    Node *right;
    Node (int id)
    {
        employeeId=id;
        left=nullptr;
        right=nullptr;
    }
};
Node *insert(Node *root,int id)
{
    if(root==nullptr)
    {
        return new Node(id);
    }
    if(id<root->employeeId)
    {
        root->left=insert(root->left,id);
    }
    else if(id>root->employeeId)
    {
        root->right=insert(root->right,id);
    }
    else
    {
        cout<<"Duplicate Employee ID "<<id<<" not allowed"<<endl;
    }
    return root;
}
void levelOrder(Node *root)
{
    if(root==nullptr)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    int level=0;
    while(!q.empty())
    {
        int size=q.size();
        cout<<"Level "<<level<<": ";
        for(int i=0;i<size;i++)
        {
            Node *current=q.front();
            q.pop();
            cout<<current->employeeId<<" ";
            if(current->left!=nullptr)
            {
                q.push(current->left);
            }
            if(current->right!=nullptr)
            {
                q.push(current->right);
            }
        }
        cout<<endl;
        level++;
    }
}
int height(Node *root)
{
    if(root==nullptr)
    {
        return -1;
    }
    return 1+max(height(root->left),height(root->right));
}
void displayLeafNodes(Node *root)
{
    if(root==nullptr)
    {
        return;
    }
    if(root->left==nullptr && root->right==nullptr)
    {
        cout<<root->employeeId<<" ";
        return;
    }
    displayLeafNodes(root->left);
    displayLeafNodes(root->right);
}
int main()
{
    Node *root=nullptr;
    int n,id;
    cout<<"Enter number of employees: ";
    cin>>n;
    cout<<"Enter "<<n<<" employee IDs: ";
    for(int i=0;i<n;i++)
    {
        cin>>id;
        root=insert(root,id);
    }
    cout<<"\n===== ORIGINAL BST ====="<<endl;
    cout<<"\nOriginal Tree Level-wise:\n";
    levelOrder(root);
    int newId;
    cout<<"\nEnter new employee ID to insert: ";
    cin>>newId;
    root=insert(root,newId);
    cout<<"\n===== NEW BST ====="<<endl;
    cout<<"\nNew Tree Level-wise:\n";
    levelOrder(root);
    cout<<"\nHeight of the tree: "<<height(root)<<" edges\n";
    cout<<"\nLeaf Nodes (Employees with no subordinates):";
    displayLeafNodes(root);
    cout<<endl;
}