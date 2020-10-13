/*Linear Queue ADT & Basic Assignment On Creating An Application*/


#include<iostream>
using namespace std;
int Q[100],Front,rear,MaxSize;

void createQueue(int Size)			//creates a queue of the size specified by user input
{
	MaxSize=Size;						//maxsize would be the size of the queue as given by user will be the queue size
	Front=0;							//we initialise the front to zero as value gets stored from start
	rear=-1;							//rear is -1 coz rear would be the last one in the queue which would get incremented everytime the value is enquued and front moves forward rear gets attached to its back
}

void Enqueue(int e)					//add element inside the queue
{
	rear++;								//rear gets incremented as the old rear has a value and is not the last one inisde the queue
	Q[rear]=e;							//stores the value inputted from user inside the new rear
}

int Dequeue()						//removes element from the queue
{
	int temp;
	temp=Q[Front];						//stores the front value inside temp which is to be dequeued
	Front++;							//increments the front as the value gets removed old front is no longer the front
	return temp;						//returns the dequeued value stored inside temp
}

int isFull()						//to check whether the queue is full
{
	if(rear==MaxSize-1)					//if rear becomes equal to max size then we cant add new values
		return 1;						//will return that queue is full
	else
		return 0;						//will let add the value/elements during enqueue so as the queue is not yet full
}

int isEmpty()						//to check whether the queue is empty or not
{
	if(Front>rear)						//if front crosses the rear than it means that whole queue has been emptied
		return 1;						//will return msg that queue is empty no more elements inside stack
	else
		return 0;						//will let the user to remove the elements duirng dequeue since the queue is not yet empty
}

void printQueue()					//simple print of queue elements
{
	int i;
	cout<<"Elements Of Queue Are:"<<" ";
	for(i=Front;i<=rear;i++)			//print will happen till fornt becomes equal to rear
		cout<<Q[i]<<" ";                //here array will print the elements stored inside the queue
		cout<<"\n\n";
}


int main()
{
    cout<<"------------------------------Linear Queue Operations--------------------------------\n\n";
	int Size,no,ch;					//size of queue input,number to be stored in queue,switch case choice value/option
	cout<<"\nEnter Size of Queue: \n";
	cin>>Size;
	cout<<"\n";
	cout<<"Queue Of Size"<<" "<<Size<<" "<<"Has Been Created.";

	createQueue(Size);				//creates a queue of the size entered by user

	do{
		cout<<"Choose One Of The Below Choices To Perform Queue Opeartions\n\n1.Enter Value To Be Stored \n2.Retrive Stored Value From Queue \n3.Print All Values Stored Inside Queue \n4.Exit The Application\n\n";
		cin>>ch;					//stores the choice to be checked for operation
        cout<<"\n";
	switch(ch)						//switch to check cases depedning on the user input & break to skip if not the option selected from user without iterating the case
	{
	case 1:							//case 1 to enter data inside the queue
		if(isFull()==1)					//s1-checks if the queue is full if true then would not add new data and return error msg
			{
			cout<<"Queue Is Full,No More Elements Can Be Stored \n\n";
			}
		else							//s2-if not true the vlaue is asked from user and saved at the end of the queue
			{
			cout<<"Enter Value To Be Saved In The Queue: \n";
			cin>>no;

			cout<<"\nThe Value"<<" "<<no<<" "<<"Has Been Stored Inside The Queue"<<"\n\n";
			Enqueue(no);				//s3-value from user gets stored inside the queue
			}
			break;

	case 2:							//case 2 to remove elements from the queue
		if(isEmpty()==1)				//s1-checks whether the queue is already empty if true it would not do opeartion nd give the message
			{
			cout<<"Queue Is Empty Nothing To DeDeque\n\n";
			}
		else							//s2- if not true the value from the queue would be removed from queue
			{
			no=Dequeue();				//s3- value from queue gets dequeued from the queue and is echoed
			cout<<"Value"<<" "<<no<<" "<<"Removed From Queue\n\n";
			}
			break;

	case 3:								//case 3 is to print the elements stored inside the queue
		if(isEmpty()==1)					//s1- checks if queue is empty and if true exits the printing and puts the message
			{
			cout<<"Queue Is Empty No Elements To Be Printed\n\n";
			}
		else								//s2- if not true it starts printing the elements of queue
			{
			printQueue();
			}
			break;

	case 4:								//case 4 is just to exit the application
		cout<<"Exiting The Application!!!\n\n";
		break;

	default:							//default case keeps a tab that user does not input any invalid choice
		cout<<"Error Occured: Please Select Appropriate Choice Code\n\n";
	}
	}while(ch!=4);						//while loop to keep a tab on the choice if its between 1-4 it will run else exit with default case error msg
}
