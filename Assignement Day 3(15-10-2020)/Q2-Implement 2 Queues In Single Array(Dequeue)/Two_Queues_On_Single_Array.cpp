/*Program To Create A Menu Driven Application Which Can Perform All Queue Operations On Such A Queue which Has 2 Queue Being Implemeted On Single Array,
that is if a array of 5 is created then one Queue can perform from zero while the other can perform operations from reverse*/

#include <iostream>
using namespace std;

class Deque {
public:
    int Q[100], MaxSize, front1, rear1, front2, rear2;          //front 7 rear of front & reverse queue

    Deque(int size) {                       //initiailse the queue
        initQueue(size);                        //size specified by user that size queue
    }

    void initQueue(int size) {                  //queue creation
        MaxSize = size;
        front1 = 0;                                 //since Q1 starts from start index is zero
        rear1 = -1;                                 //while its rear is a step back is -1
        front2 = MaxSize - 1;                       //same for the reverse queue index woukd be the end of queue szie
        rear2 = MaxSize;                            //while its rear would be the maxsize of given queue
    }

    bool isFull() {                            //checkinf for queue size is full or not
       if (rear2 - rear1 == 1)                       //if true it will say queue is full
            return 1 ;
       else
            return 0;                               //if not then let the queuing operation
    }

    void enqueue1(int e) {                      //insert into Q1
        if (isFull())                               //if full
            cout << "Queue  1 is full no more insertion possible." << endl;               //message
        else {
            Q[++rear1] = e;                             //if false let the insertion operation while incrementing the rear
        }
    }

    void enqueue2(int e) {                       //oinsert into Q2
        if (isFull())                               //if full
            cout << "Queue 2 is full no more insertion allowed." << endl;               //message
        else {
            Q[--rear2] = e;                         //if false let the insert operation while decrementing the rear as its in reverse order.
        }
    }

    int dequeue1() {                            //remove from Q1
        if (front1 > rear1) {                       //if f1 becomes more than r1 that means the queue has exceeded and is empty now
            cout << "Queue 1 Empty , No More Dequeueing Possible." << endl;
            return 0;
        }
        else {                                      //else dequeue operation
            int temp = Q[front1++];                     //put the value in temp then increment front
            if (front1 > rear1) {                       //check
                front1 = 0;
                rear1 = -1;
            }
            return temp;                                //return popped element
        }
    }

    int dequeue2() {                            //remove from Q2
        if (front2 < rear2) {                           //if f2 becomes less than r2 since in reverse means the queue has exceeded and cannot be further emptied.
            cout << "Queue 2 Empty,Dequeue No Longer Possible." << endl;  //message
            return 0;
        }
        else {                                      //else dequeue operation
            int temp = Q[front2--];                     //storing the value in temp and decrementing front as in reverse method the front would go back instead of front
            if (front2 < rear2) {                       //check
                front2 = MaxSize - 1;
                rear2 = MaxSize;
            }
            return temp;                                //return poopped element.
        }
    }

    void print1() {                             //printing elemets from Q1
        for (int i = front1; i <= rear1; i++) {
            cout << Q[i] << " ";
        }
    }

    void print2() {                             //printing elements from Q2
        for (int i = front2; i >= rear2; i--) {
            cout << Q[i] << " ";
        }
    }

    void print() {                              //printing both the Queue Simultaneously
        cout << "Queue 1 : [ ";
        print1();
        cout << " - Gap -"<<" ";
        print2();
        cout << " ] : Queue2" << endl;
    }
};

int main()                          //main application
{
        cout<<"----------Two Queue In SIngle Array/Deque---------------------\n\n";
    int size, ch;
    cout << "Enter size Of Queue: \n";
    cin >> size;
    cout << "Queue Of Size :" <<size<<" "<<"Created.\n";

    Deque d1(size);                 //deque of size s

    do {                            //main menu driven part
        int e;
        cout << "Enter choice\n1.Enqueue On Q1\n2.Dequeue On Q1.\n3.Print Elements From Q1\n4.Enqueue On Q2\n5.DeQueue On Q2\n6.Print Elements from Queue 2.\n7.Print Full Queue.\n8.Exit\n\n";
        cin >> ch;
        cout<<"\n";

        switch (ch) {
        case 1:                 //enqueue from q1
            if (d1.isFull())
                cout << "Queue 1 is  full,No More Enqueue possible" << endl;
            else {
                cout << "Enter element to be inserted in Q1: \n";
                cin >> e;
                cout << "Element"<<" "<<e<<" "<<"inserted inside Q1";
                d1.enqueue1(e);
                cout << "\n";
                d1.print1();
            }
            break;

        case 2:             //deque from q1
            cout << "Element Removed From Queue 1: " << d1.dequeue1() << endl;
            d1.print1();
            cout << "\nRemaining Elements From Queue 1\n";
            d1.print();
            break;

        case 3:             //print elements from q1
            cout <<"Elements From Q2 : [";
            d1.print1();
            cout <<",]";
            break;

        case 4:                 //enqueue in q2
            if (d1.isFull())
                cout << "Queue 2 is full ,No more  Enqueue possible." << endl;
            else {
                cout << "Enter element to be inserted in Q2: \n";
                cin >> e;
                cout << "Element"<<" "<<e<<" "<<"inserted inside Q2";
                d1.enqueue2(e);
                cout <<"\n";            }
            break;

        case 5:             //dequeu from q2
            cout << "Element Removed From Queue 2 : " << d1.dequeue2() << endl;
            d1.print2();
            cout << "\nRemaining Elements From Queue 2\n";
            d1.print();
            break;

        case 6:             //prints elements from queue 2
            cout <<"Elements From Q1 : [";
            d1.print2();
            cout <<",]";
            break;

        case 7:             //prints all elements if queue
            d1.print();
            break;

        case 8:             //exit from application
            cout << "Exiting Application..." << endl;
            break;

        default:            //if someone uses random choice words error message to be dispalyed
            cout << "Invalid Choice!!!Please Select Appropriate Choice From 1-8 Only."<< endl;
        }
    } while (ch!=6);

}
