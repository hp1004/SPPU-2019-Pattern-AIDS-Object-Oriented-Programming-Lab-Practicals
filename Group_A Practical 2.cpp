/*Develop a program in C++ to create a database of student’s information system
containing the following information: Name, Roll number, Class, Division, Date
of Birth, Blood group, contact address, Telephone number, Driving license no.
and other. Construct the database with suitable member functions. Make use of
constructor, default constructor, copy constructor, destructor, static member
functions, friend class, this pointer, inline code and dynamic memory allocation
operators-new and delete as well as exception handling. */

#include<iostream>
using namespace std;

class student{
	private:
		string name, DoB, blood_grp, address, year_class, mob;
		int rollno, div;
		
	public:
		//defualt constructor
		student(){
			rollno = -1; 
			div =-1;
			name = blood_grp = DoB = address = year_class = mob ="";
		}
		void add_data(){
			cout<<"\n Enter Student Information:";
			cin.ignore(); //to clear input buffer
			getline(cin,name);
			cout<<"Enter Roll_No:";
				cin>>rollno;
			cout<<"Enter Year(SE/Be/TE): ";
				cin>>year_class;
			cout<<"Enter Division (1/2/3/4/5/6): ";
				cin>>div;
			cout<<"Enter Blood Group: ";
				cin>>blood_grp;
			cout<<"Enter Mobile Number: "; 
				cin>>mob;
			cout<<"Enter Address: ";
				cin>>address;
		}
		//function to display student information
		void display(){
			cout<<"\n -------------------------------------------------";
			cout<<"\nName                :"<<name;
			cout<<"\nRoll_no             :"<<rollno;
			cout<<"\nYear(SE/TE/BE)      :"<<year_class;
			cout<<"\nDiv (1/2/3/4/5/6)   :"<<div;
			cout<<"\nDoB                 :"<<DoB;
			cout<<"\nBlood group         :"<<blood_grp;
			cout<<"\nMobile no           :"<<mob;
			cout<<"Address               :"<<address;
			cout<<"\n -------------------------------------------------";
		}
};
int main()
{
	student st[5];
	int ch=0; int count=0;
	do
	{
		cout<<"\n * * * S T U D E N T   I N F O R M A T I O N   S Y S T E M * * *"<<endl;
		cout<<"\n * * * M E N U * * *"<<endl;
		cout<<"1. Add Information ";
		cout<<"\n 2. Display Information ";
		cout<<"\n 3. Exit ";
		cout<<"\n Enter Your Choice :  ";
		cin>>ch;
	
	 
		switch (ch)
		{
			case 1: 
				st[count].add_data();
				count++;
				break;
			
			case 2:
				for(int j=0; j<count; j++){
					st[j].display();
				}
				break;
			case 3:
				exit(0);
		}

	}while( ch!=3);
	
	return 0;
}

