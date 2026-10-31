#include <iostream>
using namespace std;
void heapifyMax(int arr[], int n, int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left<n && arr[left]>arr[largest])
        largest=left;
    if (right<n && arr[right]>arr[largest])
        largest=right;
    if (largest!=i)
    {
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapifyMax(arr, n, largest);
    }
}
void heapSortAsc(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapifyMax(arr, i, 0);
    }
}
void heapifyMin(int arr[], int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] < arr[smallest])
        smallest = left;
    if (right < n && arr[right] < arr[smallest])
        smallest = right;
    if (smallest!=i)
    {
        int temp=arr[i];
        arr[i]=arr[smallest];
        arr[smallest]=temp;
        heapifyMin(arr, n, smallest);
    }
}
void heapSortDesc(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapifyMin(arr, i, 0);
    }
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int n;
    cout<<"Enter the number of players:";
    cin>>n;
    if (n<=0)
    {
        cout<<"Invalid number of players"<<endl;;
        return 0;
    }
    int* scores=new int[n];
    cout<<"Enter the scores of the players:"<<endl;;
    for (int i=0;i<n;i++)
    {
        cout<<"Score " <<i+1 << ": ";
        cin>> scores[i];
    }
    int choice;
    do
    {
        cout<<"\n--- Online Leaderboard Menu ---"<<endl;
        cout<<"1. Display Scores in Ascending Order (Max Heap)"<<endl;
        cout<<"2. Display Scores in Descending Order (Min Heap)"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
            {
                int* tempArr=new int[n];
                for(int i=0;i<n;i++)
                {
                    tempArr[i]=scores[i];
                }
                heapSortAsc(tempArr, n);
                cout<<"Leaderboard (Ascending):"<<endl;
                display(tempArr, n);
                delete[] tempArr;
                break;
            }
            case 2:
            {
                int* tempArr=new int[n];
                for(int i=0;i< n;i++)
                {
                    tempArr[i]=scores[i];
                }
                heapSortDesc(tempArr, n);
                cout<<"Leaderboard (Descending):"<<endl;
                display(tempArr, n);
                delete[] tempArr;
                break;
            }
            case 3:
                cout<<"Exiting leaderboard system..."<<endl;
                break;
            default:
                cout<<"Invalid choice! Please select a valid menu option"<<endl;;
        }
    }
    while (choice!=3);
    delete[] scores;
    return 0;
}