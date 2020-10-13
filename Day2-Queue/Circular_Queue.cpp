/*Circular Queue ADT & Basic Assignment On Creating An Opeartion Application*/

#include<iostream>
using namespace std;
int Q[100],Front,rear,MaxSize,cnt;

void createQueue(int Size)		//1	//creates a queue of the size specified by user input
{
	MaxSize=Size;						//maxsize would be the size of the queue as given by user will be the queue size
	Front=0;							//we initialise the front to zero as value gets stored from start
	rear=-1;							//rear is -1 coz rear would be the last one in the queue which would get incremented everytime the value is enquued and front moves forward rear gets attached to its back
	cnt=0;								//adding a counter and setting to zero
}


bool isFull(){					//2	//to check whether the queue is full
	if(cnt==MaxSize)
		return true;						//will return that queue is full
	else
		return false;						//will let add the value/elements during enqueue so as the queue is not yet full
}

bool isEmpty()					//3	//to check whether the queue is empty or not
{
	if(cnt==0)							//if front crosses the rear than it means that whole queue has been emptied
		return true;						//will return msg that queue is empty no more elements inside stack
	else
		return false;						//will let the user to remove the elements duirng dequeue since the queue is not yet empty
}

void Enqueue(int e)				//4	//add element inside the queue
{
	if (isFull())
		cout<<"Queue Is Full.\n"<<endl;
	else
	{
		rear=(rear+1)%MaxSize;			//rear gets incremented as the old rear has a value and is not the last one inisde the queue
		Q[rear]=e;						//stores the value inputted from user inside the new rear
		cnt++;							//incrementing the counter
	}
}


int Dequeue()					//5	//removes element from the queue
{
	if (isEmpty()) {
		cout<<"Queue Is Empty.\n"<<endl;
		return 0;
	}
	else {
		int temp;
		temp=Q[Front];						//stores the front value inside temp which is to be dequeued
		Front=(Front+1)%MaxSize;
		cnt--;								//decrementing the counter
		return temp;						//returns the dequeued value stored inside temp
	}
}

void printQueue()				//6	//simple print of queue elements
{
	if(isEmpty())
		cout<<"Queue Is Empty.Nothing To Print Add Something To Print.\n"<<endl;
	else
	{
		cout<<"Elements Of Queue Are:"<<" ";
		cout<<"\n";
		for(int i=Front,c=0;c<cnt;i=(i+1)%MaxSize,c++)					//print will happen till fornt becomes equal to rear
		cout<<Q[i]<<" "<<",";              								    //here array will print the elements stored inside the queue
		cout<<"\n";
	}

}

int main()
{
	int Size,no,ch;
	cout<<"------------------------------Circular Queue Operations--------------------------------\n\n";
	cout<<"Enter Size of Queue: "<<"\n";
	cin>>Size;
	cout<<"\nQueue Of Size"<<" "<<Size<<" "<<"Has Been Created.\n";
	createQueue(Size);

	do{
		cout<<"\nEnter Your Choice: \n\n1.Enter Value To Be Entered In Queue\n2.Retreive Value From Queue\n3.Print All Values From Queue\n4.Exit The Application\n\n";
		cin>>ch;
		cout<<"\nEntered Choice :"<<" "<<ch<<"\n\n";

	switch(ch)
	{
	case 1:                         //Enqueue Operation
		if(isFull()==1)                 //checks if queue is full if true doesnt accpts value
			cout<<"Queue Is Full,Can't Add Anymore Elements\n";
		else                            //if false takes i/p from user to be inserted in queue
			{
			cout<<"Enter Value To Enter: "<<"\n";
			cin>>no;
			cout<<"\nValue"<<" "<<no<<" "<<"inserted inside the queue."<<"\n";
			Enqueue(no);                //goes to enqueue ie. 4
			}
		break;

	case 2:                        //Dequeue Operation
		cout<<Dequeue()<<endl;          //goes to dequeue ie. 5
		break;

	case 3:                       //Printing Operation
		printQueue();                  //goes to printing ie. 6
		break;

	case 4:                      //Exits th application
		cout<<"Exiting The Application!!!"<<endl;       //message
		break;

	default:                    //default case to check if user choices from the given options only if not returns error message
		cout<<"Error Occured:Choose Valid Option.";
	}
	}while(ch!=4);              //checks if option is betweeen 1to4 or not
}
