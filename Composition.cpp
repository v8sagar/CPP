/*
 * Main.cpp
 *
 *  
 *      Author: v8
 */

#include<iostream>
#include<string>
using namespace std;

namespace NComposition
{
	class Date
	{
	private:
		int day;
		int month;
		int year;
	public:
		Date( void )
		{
			this->day = 0;
			this->month = 0;
			this->year = 0;
		}
		Date( int day, int month, int year )
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
		friend istream& operator>>( istream& cin, Date& other )
		{
			cout<<"Day	:	";
			cin>>other.day;
			cout<<"Month	:	";
			cin>>other.month;
			cout<<"Year	:	";
			cin>>other.year;
			return cin;
		}
		friend ostream& operator<<( ostream& cout, const Date& other )
		{
			cout<<other.day<<" / "<<other.month<<" / "<<other.year;
			return cout;
		}
	};
	class Employee
	{
	private:
		string name;	//24 bytes
		int empid;		//4 bytes
		float salary;	//4 bytes
		Date joinDate;	//12 bytes	: Composition-->Aggregation
	public:
		Employee( void ) : empid( 0 ),salary( 0 )
		{	}
		Employee( string name, int empid, float salary, Date joinDate  ) : name( name ), empid( empid ), salary( salary ), joinDate( joinDate )
		{	}
		Employee( string name, int empid, float salary, int day, int month, int year  ) : name( name ), empid( empid ), salary( salary ), joinDate( day, month, year )
		{	}
		friend istream& operator>>( istream& cin, Employee& other )
		{
			cout<<"Name	:	";
			cin>>other.name;
			cout<<"Empid	:	";
			cin>>other.empid;
			cout<<"Salary	:	";
			cin>>other.salary;
			cin>>other.joinDate;	//operator>>(cin, other.joinDate )
			return cin;
		}
		friend ostream& operator<<( ostream& cout, const Employee& other )
		{
			cout<<"Name	:	"<<other.name<<endl;
			cout<<"Empid	:	"<<other.empid<<endl;
			cout<<"Salary	:	"<<other.salary<<endl;
			cout<<"Date	:	"<<other.joinDate<<endl;
			return cout;
		}
	};
}
int main( void )
{
	using namespace NComposition;
	Employee emp( "v8", 33, 12345.50f, 1, 1, 2007 );
	cout<<emp;
	return 0;
}
/*int main( void )
{
	string name = "Sagar";
	int empid = 33;
	float salary = 12345.50f;
	Date joinDate( 1,1,1999);
	Employee emp( name, empid, salary, joinDate );
	cout<<emp;
	return 0;
}*/
/*int main( void )
{
	Employee emp;
	cout<<emp;
	return 0;
}*/
