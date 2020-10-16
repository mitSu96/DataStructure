 #include<iostream>
using namespace std;

void insertionSort(int a[], int size)
{
    int i,key, j;
    for (i = 1; i < size; i++)
    {
        j = i;
		key=a[j];
        while (j > 0 && a[j-1] > key)
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = key;
    }
}


int main()
{
	cout<<"-----------------Insertion Sort------------------\n\n";
	int i,size;
	cout << "\nEnter The Size Of The Array To Be Sorted Using Insertion Sort.\n";
	cin >> size;
	int arr[size];
	cout << "\nEnter The Values to Be Entered In An Array Of Size"<<" " <<size<<"\n\n";
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }

    cout << "\nUnsorted Array :\n";
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    //int n = sizeof(arr[size]) / sizeof(arr[0]);
    insertionSort(arr, size);
    cout << "\nSorted array: \n";
    for (i = 0; i < size; i++)
    cout << arr[i] << " ";
    cout << endl;

    return 0;
}
