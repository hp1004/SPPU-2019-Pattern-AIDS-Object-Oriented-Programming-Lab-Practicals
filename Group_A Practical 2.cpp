/*Develop a program in C++ to create a database of student’s information system
containing the following information: Name, Roll number, Class, Division, Date
of Birth, Blood group, contact address, Telephone number, Driving license no.
and other. Construct the database with suitable member functions. Make use of
constructor, default constructor, copy constructor, destructor, static member
functions, friend class, this pointer, inline code and dynamic memory allocation
operators-new and delete as well as exception handling. */

#include<iostream>
#include<string.h>
using namespace std;

class student
{
  string name,blood_group,email,clas,dob,contact;
  int roll_no;
  static int roll;
  public:
    student()
    {
      roll_no=-99;
      this->roll_no;
    }
    
    void input();
    void display()
    {
      cout<<"Name of the Student is:"<<name<<endl;
      cout<<"Roll No. of the Student is:"<<roll_no<<endl;
      cout<<"Blood Group of the Student is:"<<blood_group<<endl;
      cout<<"Class of the Student is:"<<clas<<endl;
      cout<<"Birth Date of the Student is:"<<dob<<endl;
      cout<<"Contact No. of the student is:"<<contact<<endl;
      cout<<endl;
    }
    
};

int student::roll=2227701;

void student::input()
{
  cout<<"Enter the name of the student:\n";
  cin.ignore();
  getline(cin,name);
  cout<<"Enter the email of the student:\n";
  cin>>email;
  cout<<"Enter the contact number of the student:\n";
  cin.ignore();
  getline(cin,contact);
  cout<<"Enter the Class of the student:\n";
  cin.ignore();
  getline(cin,clas);
  cout<<"Enter the Birth Date of the student:\n";
  cin>>dob;
  cout<<"Enter the Blood group of the student:\n";
  cin>>blood_group;
  roll_no=student::roll;
  student::roll++;
}

int main()
{
  student ob[5];
  int i=0,ch,count;
  do
  {
  	cout<<"\n * * * S T U D E N T   I N F O R M A T I O N   S Y S T E M * * *"<<endl;
	cout<<"\n * * * M E N U * * *"<<endl;
	cout<<"1. Add Information ";
	cout<<"\n 2. Display Information ";
	//cout<<"\n 3. Exit ";
	cout<<"\n Enter Your Choice :  ";
	cin>>ch;
    //cout<<"1. Enter Information\n";
    //cout<<"2. Display Information\n";
    //cout<<"Enter your choice:\n";
    //cin>>ch;
    switch(ch)
    {
      case 1:ob[i].input();
             i++;
             break;
      case 2:for(count=0;count<i;count++)
             {
               ob[count].display();
             }
             break;
    }
  }while(ch!=3);
  return 0;
}

