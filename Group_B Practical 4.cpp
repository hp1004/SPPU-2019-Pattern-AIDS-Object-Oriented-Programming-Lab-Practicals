/*Write a C++ program that creates an output file, writes information to it, closes the file, open it
again as an input file and read the information from the file.*/
#include<iostream>
#include<fstream>
using namespace std;
class Employee
{
	char Name[20];
	int ID;
	double salary;
	public:
		void accept()
		{
			cin>>Name;
			cin>>ID;
			cin>>salary;
		}
		void display()
		{
			cout<<"\n Enter Name: "<<Name;
			cout<<"\n Enter ID: "<<ID;
			cout<<"\n Enter Salary: "<<salary;		
		}
};
int main()
{
	Employee o[5];
	fstream f;
	int i,n;
	
	f.open("employee.txt");
	cout<<" \n How many employee information do you need to store?"<<endl;
	cin>>n;
	cout<<"\n Enter information of employee in this format (Name/ID/Salary)"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter information of:"<<i<<"\nEmployee  "<<endl;
		o[i].accept();
		f.write((char*)&o[i],sizeof o[i]);
	}
	f.close();
	f.open("employee.txt",ios::in);
	cout<<"\n Information of employee is as follow: "<<endl;
	for(i=0;i<n;i++)
	{
		f.write((char*)&o[i],sizeof o[i]);
		o[i].display();
	}
    f.close();
	return 0;
}


