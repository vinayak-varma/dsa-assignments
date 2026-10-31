#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, e;
    cout << "Enter number of users: ";
    cin >> n;
    cout << "Enter number of friendships: ";
    cin >> e;
    
    vector<vector<int>> adj(n);
    cout << "\nEnter friendships(user1 user2):\n";
    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout << "\nAdjacency List:\n";
    for(int i = 0; i < n; i++)
    {
        cout << "User " << i << " -> ";
        for(int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    
    int start;
    cout << "\nEnter starting user for BFS: ";
    cin >> start;
    
    vector<bool> visited(n, false);
    queue<int> q;
    
    // CORRECTED: Fixed spelling and used square brackets
    visited[start] = true; 
    q.push(start);
    
    cout << "\nBFS Traversal (level by level):\n";
    int level = 0;
    
    while (!q.empty())
    {
        int size = q.size();
        cout << "Level " << level << ": ";
        
        // CORRECTED: Changed << to <
        for(int i = 0; i < size; i++) 
        {
            int current = q.front();
            q.pop();
            cout << current << " ";
            
            for (int friendUser : adj[current])
            {
                // CORRECTED: Fixed spelling of 'visited'
                if(!visited[friendUser]) 
                {
                    visited[friendUser] = true;
                    q.push(friendUser);
                }
            }
        }
        cout << endl;
        level++;
    }
    return 0;
}