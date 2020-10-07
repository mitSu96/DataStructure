#include <iostream>
using namespace std;
int s[100],MaxSize,tos;

void initStack(int size){                   //Initialize The Stack
	MaxSize = size;
	tos = -1;
}

void push(int e){                      //pushes the element in stack
	tos++;
	s[tos]=e;
}

int isFull(){                              //checks whether stack is full or not
	if(tos==MaxSize){
		return 1;
	}
	else 
	return 0;
}

int pop(){                             //pops the element from stack
	int temp;
	temp =s[tos];
	tos--;
	return temp;
}

int isEmpty(){                             //checks whether the stack is empty por not
	if(tos==-1){
		return 1;
	}else{
		return 0;
	}
}

int atTop(){                           //Returns the top element
	return s[tos];
}

void printStack(){                         //prints the stack
	int i;
	for(i=tos;i>-1;i--){
		cout<<s[i]<<endl;
	}
}


int main()
{
	char ch;
	int size,e;                            //size pf stack form user
    cout<<"Enter The Size Of Stack : ";
    cin>>size;
    initStack(size);
    cout<<"Stack of size : "<<size<<" created\n";
    do{
    	cout<<"Enter your choice to do stack operations :\na.push\nb.pop\nc.At Top\nd.Print Stack\ne.Exit\n";
    	cin>>ch;
    	cout<<endl;
    	switch(ch){
    		case 'a':
    			if(isFull()){
    				cout<<"Stack Is Full"<<endl;
				}
				else{
					cout<<"Enter new value"<<endl;
					cin>>e;
					push(e);		
				}
				break;
			
			case 'b':
				if(isEmpty){
					cout<<"Stack is Empty"<<endl;
				}else{
					cout<<"Pop element : "<<pop()<<endl;
				}
				break;
			
			case 'c':
				if(isEmpty()){
					cout<<"Stack is empty"<<endl;
				}
				else{
					cout<<atTop()<<endl;
				}
				break;
			
			case 'd':
				if(isEmpty()){
					cout<<"Stack is Empty"<<endl;
				}
				else{
					printStack();
				}
				break;
				
			case 'e':
				cout<<"Exiting The Application...."<<endl;
				break;
			default:
				cout<<"Invalid Entry Note: Case Sensitive Selection Use Small Caps and or Alphabets Only"<<endl;
		}
	}while(ch!='e'||ch!='E');
	cout << endl;
}