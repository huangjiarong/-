#ifndef _STUDENT
#define _STUDENT

#include <string>
using namespace std;

class Student
{
	protected :
		string term;
		string name;
		string number;
		double math;
		double sports;
		double java;
		double average;
		int    ranking;

	public :
		Student ( string _term, string _name, string _number, double _math, double _sports, double _java, int _ranking = 0 );
		Student () = default;	//默认构造函数，需要编译器支持并开启C++11标准
		void   Change_ranking ( int _rank );	//刚输入的学生默认名次为0，该函数给予正确名次
		double Get_math ();
		double Get_sports ();
		double Get_java ();
		double Get_average ();
		int    Get_ranking ();
		string Get_name ();
		string Get_number ();
		string Get_term ();
		friend ostream &operator<< ( ostream &os, const Student &stu );
		friend istream &operator>> ( istream &is, Student &stu );
};

#endif
