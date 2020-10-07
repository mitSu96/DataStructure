#include <iostream> 
using namespace std; 
int s[100], MaxSize, tos;

void initStack(int size) {
	MaxSize = size;
	tos = -1;
}

void push(int e) {
	tos++;
	s[tos] = e;
}

int isFull() {
	if (tos == MaxSize) {
		return 1;
	}
	else
		return 0;
}

int pop() {
	int temp;
	temp = s[tos];
	tos--;
	return temp;
}

int isEmpty() {
	if (tos == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int atTop() {
	return s[tos];
}

void printStack() {
	int i;
	for (i = tos; i > -1; i--) {
		cout << s[i];

	}
}

void dtb(int n)                 //decimal to binary conversion prg
{
  int rem, tos=-1, e;
    while(n!=0)
    {
      rem = n%2;                //remainder
      push(rem);                //pushes the remainder
      n=n/2;                    // number gets halved since for binary we have to divide by two
    }  
}

int main() 
{ 
    int n,e ;           //n-decimal number from user ; e-converted binary number
    cout<<"Enter A Decimal Number To be converted:";
    cin>>n;
    cout<<"The Binary Form Of "<<n <<" "<<"is" <<" "<<":"; 
    dtb(n);            //function to convert call
    while(tos!=0)
    {
      e=pop();
      cout<<e;
    }      
  return 0; 
}