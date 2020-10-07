#include <iostream>
using namespace std;

char s[100];
int MaxSize, tos;

void initStack(int size) {
    MaxSize = size;
    tos = -1;
}

int isEmpty() {
    if (tos == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if (tos == MaxSize)
        return 1;
    else
        return 0;
}

void push(char c){
    tos++;
    s[tos] = c;
}

char pop() {
    char temp = s[tos];
    tos--;
    return temp;
}

char atTop() {
    return s[tos];
}

void printStack() {
    int i;
    for (i = tos; i > -1; i--) {
        cout << s[i];
    }
}

int main()
{
    string name;
    cout << "Enter The String To Be Reversed :";
    cin >> name;
    int size = name.size();
    initStack(size);
    for (int i = 0; i < size; i++) {
        push(name.at(i));
    }
    cout<<"\nThe Reverse Of Given String"<<"\nOrignial String:"<<" "<<name<<"\nReveresed String"<<":";
   printStack();

}