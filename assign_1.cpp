#include <iostream>
#include <string>
using namespace std;
const int MAX_BOOKS=100;
class BookStack
{
    private:
        string books[MAX_BOOKS];
        int topIndex;
    public:
        BookStack()
        {
            topIndex=-1;
        }
        void push(const string bookName)
        {
            if(topIndex>=MAX_BOOKS)
            {
                cout<<"Stack Overflow! Cannot accept more returned books right now\n";
            }
            else
            {
                topIndex++;
                books[topIndex]=bookName;
                cout<<"Book returned: "<<bookName<<endl;
            }
        }
        void pop()
        {
            if(topIndex<0)
            {
                cout<<"Stack Underflow! No returned books to arrange\n";
            }
            else
            {
                cout<<"Arranged on shelf: "<<books[topIndex]<<endl;
                topIndex--;
            }
        }
        void peak()
        {
            if(topIndex<0)
            {
                cout<<"No books in the stack\n";
            }
            else
            {
                cout<<"Top book to be arranged: "<<books[topIndex]<<endl;
            }
        }
        void display()
        {
            if(topIndex<0)
            {
                cout<<"The stack of returned books is empty\n";
            }
            else
            {
                cout<<"\n--- Current Stack of Returned Books ---\n";
                for(int i=topIndex;i>=0;i--)
                {
                    cout<<" "<<books[i]<<endl;
                }
                cout<<"----------------------------------------\n";
            }
        }
};
int main()
{
    BookStack libraryStack;
    int choice;
    string bookName;
    do
    {
        cout<<"\n===== Library Book Return System =====\n";
        cout<<"1. Return Book (Push)\n";
        cout<<"2. Arrange Book (Pop)\n";
        cout<<"3. View Top Book (Peak)\n";
        cout<<"4. Display Stack\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore();
        switch(choice)
        {
            case 1:
                cout<<"Enter the name of the book to return: ";
                getline(cin,bookName);
                libraryStack.push(bookName);
                break;
            case 2:
                libraryStack.pop();
                break;
            case 3:
                libraryStack.peak();
                break;
            case 4:
                libraryStack.display();
                break;
            case 5:
                cout<<"Exiting the system. Goodbye!\n";
                break;
            default:
                cout<<"Invalid choice! Please enter a number between 1 and 5.\n";
        }
    }
    while(choice!=5);
    return 0;
}