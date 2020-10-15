/*Program To Create A Menu Driven Application Which Can Perform All Stack Operations On Such A Stack which Has 2 Stacks Being Implemeted On Single Array,
that is if a array of 5 is created then one stack can perform from zero while the other can perform operations from reverse*/

#include <iostream>
using namespace std;

class Stack {                           //class stack conatining stack opeartions
public:
     int tos1, tos2 ,MaxSize;           //top elements of stack 1 & 2 tracker,maxsize of stack specified by user
     int arr[10];                       //creating array of size 10

    Stack(int size) {                   //Initialize The Stack
        this->MaxSize = size;           //setting the maxsize as the size given by user
        tos1 = -1;                      //setting the top of stack1 as -1 because it starts from index 0
        tos2 = MaxSize;                 //setting the top of stack2 as maxsize because it starts from index n-1
    }


    bool isFull() {                     //checks whether stack is full or not to do
        if (tos2 - tos1 == 1)           //if stack 1 & 2 meets at a point
            return 1;                   //will return true that stack is full
        else
            return 0;                   //else return true that stack is not full & let the pushing operation
    }

    bool isEmpty1() {                   //checks whether the stack1 is empty or not
        if (tos1 == -1)                 //if top of element reaches index for stack1 0
            return 1;                   //will say stack is empty
        else
            return 0;                   //else lets the poping opeartion
    }

    bool isEmpty2() {                   //checks whether the stack2 is empty or not
        if (tos2 == MaxSize)            //if top of element reaches index for stack2 maxsize
            return 1;                   //will say stack is empty
        else
            return 0;                   //else lets the poping opeartion
    }

    void push1(int e) {                 //Push Operation for stack1
        if (isFull())                   //if the stacks have completely filled the array
            cout << "Stack is full can't further push elements"<<endl;      //if true cant let anymore pushing operation
        else {
            arr[++tos1] = e;            //pushes the element on array &increments the tos for stack1
        }
    }

    void push2(int e) {                 //Push Operation for stack2
        if (isFull())                      //if the stacks have completely filled the array
            cout << "Stack is full can't further push elements"<<endl;       //if true cant let anymore pushing operation
        else {
            arr[--tos2] = e;                //pushes the element on array & decrements the tos for stack2
        }
    }

    int pop1() {                        //Pop Operations for stcak1
        if (isEmpty1()) {                   //if the stack is empty
            cout << "Stack 1 is empty cant pop elements anymore"<<endl;        //will not let popping operation
            return 0;
        }
        else {
            int temp = arr[tos1--];             //else lets the elemnts from stack1 to be popped from array & decrment the tos
            return temp;
        }
    }

    int pop2() {                        //pop opeartions for stack2
        if (isEmpty2()) {
            cout << "Stack2 is empty cant pop elements anymore"<<endl;
            return 0;
        }
        else {
            int temp = arr[tos2++];     //else lets the elemnts from stack2 to be popped from array & increment the tos(as the stack2 performs operation in reverse direction)
            return temp;
        }
    }

    void print1() {                     //Print stack 1 elements
        for (int i = tos1; i > -1; i--) {
            cout << arr[i] << " ";
        }
    }

    void print2() {                     //prints stack 2 elements
        for (int i = tos2; i < MaxSize; i++) {          //print from reverse order so i is incremented
            cout << arr[i] << " ";
        }
    }

    void print() {                      //print both stack in single command
        cout << " Stack  1 : ";
        print1();                       //calls print operation1
        cout << "- Gap-"<<" ";
        print2();                       //calls print 2 opeartion
        cout << " : 2nd stack"<<endl;
    }


};

int main()
{
    cout<<"----------Two Stack On SIngle Array---------------------\n\n";
    int size,ch;
    cout << "Enter Size Of Stack : \n";
    cin >> size;
    cout<<"Stack of size : "<<size<<" created\n";

    Stack s(size);              //sytack s of size

    do {                //main application part
        int e;
        cout << "\nEnter Your choice:\n\n1.Push into Stack 1.\n2.Pop from Stack 1\n3.Print Stack 1 Elements.\n4.Push Into Stack 2.\n5.Pop From Stack 2.\n6.Print Stack 2 Elements\n7.Print Both Stack.\n8.Exit.\n" << endl;
        cin >> ch;
        cout <<"\n";

        switch (ch) {
        case 1:                 //push into stack 1
            if (s.isFull())
                cout << "Stack is Full cant push elements in stack 1."<<endl;
            else {
                cout << "Enter element to be inserted in stack 1 : " << endl;
                cin >> e;
                cout << "Element"<<" "<<e<<" "<<"inserted on stack 1";
                s.push1(e);
                s.print1();
            }
            break;

        case 2:                 //pop from stack 1
            cout<<"Element "<<" "<<s.pop1()<<" "<<"poped from stack 1."<<endl;
            s.print1();
            break;

        case 3:                //Print elements from stack 1
            cout << "Elements Of Stack 1 : [";
            s.print1();
            cout << ",]";
            break;

        case 4:                 //push into stack 2
            if (s.isFull())
                cout << "Stack Is Full cannot push any new elements" << endl;
            else {
                cout << "Enter element to be inserted in stack 2 : " << endl;
                cin >> e;
                cout << "Element"<<" "<<e<<" "<<"Inserted in stack 2";
                s.push2(e);
                s.print2();
            }
            break;

        case 5:                //pop from stack 2
            cout<<"Element "<<" "<<s.pop2()<<" "<<"poped from stack 2."<<endl;
            s.print2();
            break;

        case 6:                //Print elements from stack 2
            cout << "Elements Of Stack 2 : [";
            s.print2();
            cout << ",]";
            break;

        case 7:               //print both the stack elements
            s.print();
            break;

        case 8:              //Exit the Application
            cout << "Exiting Appliction..."<<endl;
            break;

        default:            //if someone uses random choice words error message to be dispalyed
            cout << "Invalid Choice!!!Please Select Appropriate Choice From 1-8 Only." << endl;

        }
    } while (ch!=8);



}
