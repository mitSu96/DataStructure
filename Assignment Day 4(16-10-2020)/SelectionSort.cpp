#include<iostream>
using namespace std;

void selectionSort(int a[], int size)
{
    int i, j, min,pos;

    for (i = 0; i < size; i++)
    {
        min = a[i];
		pos=i;
        for (j = i+1; j < size; j++)
        if (a[j] < min)
		{
            min = a[j];
			pos=j;
		}
        a[pos]=a[i];
		a[i]=min;
    }
}


int main()
{
    cout<<"-----------------Selection Sort------------------\n\n";
    int i,size;
	cout << "\nEnter The Size Of The Array To Be Sorted Using Insertion Sort.\n";
	cin >> size;
	int a[size];
	cout << "\nEnter The Values to Be Entered In An Array Of Size"<<" " <<size<<"\n\n";
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element "<<i+1<<": ";
        cin>>a[i];
    }

    cout << "\nUnsorted Array :\n";
    for (i=0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;


    selectionSort(a, size);
    cout << "\nSorted array: \n";
    for (i=0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
