/*Priority Queue ADt & Basic Application*/

#include <iostream>
using namespace std;

int Q[100], MaxSize, Front, Rear;

void initQueue(int size)            //queue creation
{
    Front = 0;
    Rear = -1;
    MaxSize = size;
}

bool isFull()                       //checking for queue full or not
{
    return (Rear == MaxSize) ? true :false;
}

bool isEmpty()                      //checking for queue empty or not
{
    return (Front > Rear) ? true : false;
}

void sortByPriority()               //sorting of queue by priority
{

    for (int i = Front; i < Rear; i++)          //passes
        {
            for (int j = i + 1; j <= Rear; j++)     //sorting loop
            {
                if (Q[i] > Q[j])                    //if i greater than j then swap them
                {
                    int temp = Q[i];
                    Q[i] = Q[j];
                    Q[j] = temp;
                }
            }
        }
}

void EnQueue(int e)                 //enqueue operation
{
    if (isFull())
        cout << "Queue is Full.Can't Add anymore Elements" << endl;
    else
        {
            Rear++;
            Q[Rear] = e;
            sortByPriority();       //sort the inserted elements inside the queue
        }
}

int DeQueue()                       //dequeue operation
{
    if (isEmpty())                  //if the queue is empty msg would be displayed
        {
            cout << "Queue is Empty,Cant dequeue anymore elements.";
            return 0;
        }
        else                        //if false it removes the elements from queue
        {
            int temp = Q[Front++];
            return temp;
        }
}

void PrintQueue()                   //printing queue
{
    if (isEmpty())                  //if empty returns msg
        cout << "Queue is empty,cant print any elements." << endl;
    else                            //else it starts the print loop
        {
            for (int i = Front; i <= Rear; i++)
                {
                    cout << Q[i] << " ";
                }
        }
}

int main()                  //main application code
{
    cout <<"------------------------------Priority Queue Operations--------------------------------\n\n";
    int size;
    cout << "Enter the size of queue :\n";
    cin >> size;
	cout<<"\nQueue Of Size"<<" "<<size<<" "<<"Has Been Created.";
    initQueue(size);        //initialise queue

    int ch;
    do {
        cout << endl;
        cout << "\nEnter your choice\n1.EnQueue Operation\n2.DeQueue Operation\n3.PrintQueue Operation\n4.ExitApplication\n" << endl;
        cin >> ch;
        cout << endl;
        switch (ch) {
        case 1:
            if (isFull())
                cout << "Queue is full" << endl;
            else {
                int t;
                cout << "Enter the element : ";
                cin >> t;
                EnQueue(t);
            }
            break;

        case 2:
            cout<<DeQueue()<<endl;
            break;

        case 3:
            PrintQueue();
            break;

        case 4:
            cout << "Exiting...." << endl;
            break;

        default:
            cout << "Wrong choice!" << endl;
        }
    } while (ch != 4);
}
