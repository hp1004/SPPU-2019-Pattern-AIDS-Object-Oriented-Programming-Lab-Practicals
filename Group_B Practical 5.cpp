/*Write a function template for selection sort that inputs, sorts and outputs an integer array and a
float array.
STEPS:-
1.Writing a function template for selection sort.
2.call function tempalte for integer value
3.call function template for float value

selection sort is a technique in which we kept smaalest elements at left postion(ascending order formate

*/

#include<iostream>
using namespace std;
// Create function template for selection sort.
template<typename T>
void sort(T a[],int n)
{
	int min_pos, i;
	T temp;
	//selection sort logic...
	for (int i=0; i< n-1; i++)
	{
		min_pos = i;
		for (int j=i+1; j< n;j++)
		{
			if (a[j] < a[min_pos])
				min_pos=j;
		}
		if (min_pos != i)
		{
			temp=a[i];
			a[i]=a[min_pos];
			a[min_pos]=temp;
		}
		
	}
	//display sorted elements
	cout<<"\n Sorted Elements : "<<endl;
	for(int i=0; i<n; i++)
		cout<<"\t"<<a[i];
	cout<<" "<<endl;
		
}
int main()
{
	int n,i,ch;
	int a[10];
	float b[10];
	
	do
	{
		cout<<"---Selection sort using function template---"<<endl;
		cout<<"1. Sort integer numbers: "<<endl;
		cout<<"2. Sort Float Numbers: "<<endl;
		cout<<"3. Exit "<<endl;
		cout<<"Enter your choice: "<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"Sorting integer numbers"<<endl;
				cout<<"Enter How many numbers wanted to sort: ";
				cin>>n;
				for(i=00;i<n;i++){
					cin>>a[i];
				}
				sort<int>(a, n); // call function template using int values
				break;
				
			case 2:
				cout<<"Sorting floating point numbers"<<endl;
				cout<<"Enter How many numbers wanted to sort: ";
				cin>>n;
				for(i=00;i<n;i++){
					cin>>b[i];
				}
				sort<float>(b, n); // call function template using int values
				break;
			case 3:
				exit(0);
				
				

		}
		
		
	}while (ch !=3);
	return 0;
	
	
}

