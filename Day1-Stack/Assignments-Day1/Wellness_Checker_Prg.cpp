#include <iostream>
using namespace std;

char s[100];
int MaxSize, tos;

void initStack(int size) {
	MaxSize = size;
	tos = -1;
}

void push(char e) {
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

char pop() {
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

char atTop() {
	return s[tos];
}

void printStack() {
	int i;
	for (i = tos; i > -1; i--) {
		cout << s[i]<<endl;
		
	}
}
int main()
{
	
	char br;
	
	cout << "Enter brackets to check wellness of given code:" << endl;
	initStack(100);
	
	do
	{
		cin >> br;
		if (br == '{') {
			push(br);
			
		}
		else if (br == '}') {
			pop();	
		}
    cout << "Enter 'c' to check wellness.\n";
	} while (br != 'c');

	if (isEmpty()) {
		cout << "Your code has no issues\n";
	}
	else
	{
		cout << "\nException! : "<<tos<<" '}' needed!";
        cout << "here -ve indicates missing brackets while +ve inidcates extra brackets";	
	}
}