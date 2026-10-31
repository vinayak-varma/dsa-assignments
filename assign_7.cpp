#include <iostream>
#include <stack>
using namespace std;
class RoadNetwork
{
private:
    int numIntersections;
    int adjMatrix[100][100];
public:
    RoadNetwork(int n)
    {
        numIntersections=n;
        for (int i=0;i<numIntersections; i++)
        {
            for (int j=0; j<numIntersections;j++)
            {
                adjMatrix[i][j]=0;
            }
        }
    }
    void addRoad(int u, int v)
    {
        if (u>=0 && u<numIntersections && v>=0 && v<numIntersections)
        {
            adjMatrix[u][v]=1;
            adjMatrix[v][u]=1; // Assuming roads are two-way (undirected)
            cout<<"Successfully added a road between intersection " <<u<< " and " <<v<< "." <<endl;
        }
        else
        {
            cout<<"Invalid intersection identifiers!" << endl;
        }
    }
    void exploreNetworkDFS(int start)
    {
        if (start<0 || start>=numIntersections)
        {
            cout<<"Invalid starting intersection!" << endl;
            return;
        }
        bool visited[100] = {false};
        stack<int> s;
        s.push(start);
        cout<<"Network Exploration (DFS Traversal): ";
        while (!s.empty())
        {
            int current=s.top();
            s.pop();
            if (!visited[current])
            {
                cout<<current<< " ";
                visited[current]=true;
            }
            for (int i=numIntersections-1;i>=0;i--)
            {
                if (adjMatrix[current][i] == 1 && !visited[i])
                {
                    s.push(i);
                }
            }
        }
        cout<<endl;
    }
};
int main()
{
    int n;
    cout<<"Enter the total number of intersections in the city: ";
    cin>>n;
    RoadNetwork city(n);
    int choice;
    do
    {
        cout<<"\n--- City Road Network Menu ---"<<endl;
        cout<<"1. Add a Road (Connect intersections)"<<endl;
        cout<<"2. Explore Network (DFS Traversal)"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
            {
                int u, v;
                cout<<"Enter the two intersections to connect (e.g., 0 1): ";
                cin>>u>>v;
                city.addRoad(u, v);
                break;
            }
            case 2:
            {
                int startNode;
                cout<<"Enter the starting intersection for exploration: ";
                cin>>startNode;
                city.exploreNetworkDFS(startNode);
                break;
            }
            case 3:
                cout<<"Exiting the program..."<<endl;
                break;
            default:
                cout<<"Invalid choice! Please select a valid menu option."<<endl;
        }
    }
    while (choice!=3);
    return 0;
}