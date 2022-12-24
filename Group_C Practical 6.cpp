/*Write C++ program using STL for sorting and searching user defined records such as personal
records (Name, DOB, Telephone number etc) using vector container
STEPS:-
1. creating a record of student using class.
2. creating objects using vectors.
3. adding records in vector using >> operator.
4. displaying records by overloading << operator.
5. searching record using find() member function.
6. sorting record using sort() member functions.
*/
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class student
{
	public:
		int rollno;
		string name;
		char mob[20];
		
		// == operator overloading needed for search record (find) function
		bool operator==(const student &student1)
		{
			return(rollno==student1.rollno);
		}
		
		// overloading operator << to display student record 
		friend ostream& operator << (ostream &out, const student &);
		
		// overloading operator >> to accept student record
		friend istream& operator >> (istream &in, student &k);
};

//---------- overloading operator << to display student record -----------//
ostream & operator << (ostream &out, const student &k)
{
	out<<"\n\t\t"<<k.rollno<<"\t\t"<<k.name<<"\t\t"<<k.mob;
	return out;
}

//----------overloading operator >> to accept student record-------------//
istream & operator >> (istream &in , student &k)
{
	cout<<"Enter Roll No : "<<endl;
	in>>k.rollno;
	cout<<"Enter Name : "<<endl;
	in>>k.name;
	cout<<"Enter mob : "<<endl;
	in>>k.mob;
	return in;
}
//-----------------function to accept record ----------------------------//
vector<student> read()
{
	int n;
	student k;
	vector<student> j;
	cout<<"\n Enter total no of students : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		j.push_back (k);//add element to the end of vector 
	}
	return j;
}
//------------- Function for display records-----------//
void printfunction(const student &k)
{
	cout<<k;
}
//-------------function for display records-----------------//
void print(const vector<student> &j)
{
	cout<<"\n\t\tROLL NO\t\tNAME\t\tMOBILE NUMBER";
	//execute print function from start to end of j
	for_each (j.begin(),j.end(),printfunction);
}
//-- function for search record ---------//
void search(vector<student> &j)
{
	student k;
	cout<<"enter roll no to search : ";
	cin>>k.rollno;
	cout<<"\n\n\t\tROLL NO\t\tNAME\t\tMOBILE NO";
	vector<student>::iterator p;
	p=find(j.begin(),j.end(),k);
	if(p!=j.end())
		cout<<*p;
	else
		cout<<"\nNOT FOUND ";
}
//===============SORTING OF THE RECORD WILL BE DONE BASED ON ROLL_NO OF STUDENT=============//
bool sort_func(const student &x, const student &y)
{
	return(x.rollno<y.rollno);
}
//--function to sort record------------//
void sort(vector<student> &j)
{
	sort(j.begin(),j.end(),sort_func);
}
//--------- M A I N    F U N C T I O N----------------//
int main()
{
	vector<student> s;
	int ch;
	do
	{
		cout<<"\n\t * * * PERSONAL RECORD DATABASE * * * "<<endl;
		cout<<"1. Create Record"<<endl;
		cout<<"2. Display Record"<<endl;
		cout<<"3. Search Record"<<endl;
		cout<<"4. Sort Record"<<endl;
		cout<<"5. Quite Menu"<<endl;
		cout<<"----------------------------"<<endl;
		cout<<"\t Enter your choice : "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				s=read();
				break;
			case 2:
				print(s);
				break;
			case 3:
				search(s);
				break;
			case 4:
				sort(s);
				print(s);
				break;
		}
	}while(ch!=5);
	return 0;
}


