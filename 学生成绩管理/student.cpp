#include "student.h"
#include <string>
#include <iostream>
#include <iomanip>

Student::Student ( string _term, string _name, string _number, double _math, double _sports, double _java, int _ranking ) : name (_name), number (_number), term (_term), math (_math), sports (_sports), java (_java), average ( (_math + _sports + _java) / 3 ), ranking (_ranking) { }

void Student::Change_ranking ( int _rank )
{
	ranking = _rank;
}

double Student::Get_math ()
{
	return math;
}

double Student::Get_sports ()
{
	return sports;
}

double Student::Get_java ()
{
	return java;
}

double Student::Get_average ()
{
	return average;
}

int Student::Get_ranking ()
{
	return ranking;
}

string Student::Get_name ()
{
	return name;
}

string Student::Get_number ()
{
	return number;
}

string Student::Get_term ()
{
	return term;
}

ostream &operator<< ( ostream &os, const Student &stu )
{
	os << stu.term << '\t' << stu.name << '\t' << stu.number << '\t' << setiosflags(ios::fixed) << setprecision(1) << stu.math << '\t' << stu.sports << '\t' << stu.java << '\t' << stu.average << '\t' << stu.ranking;	//固定输出格式为小数点后一位
	return os;
}

istream &operator>> ( istream &is, Student &stu )
{
	string _term, _name, _number;
	double _math, _sports, _java;
	double _average, _ranking;

	is >> _term >> _name >> _number >> _math >> _sports >> _java >> _average >> _ranking;
	if ( is )
	{
		stu.term = _term;
		stu.name = _name;
		stu.number = _number;
		stu.math = _math;
		stu.sports = _sports;
		stu.java = _java;
		stu.average = _average;
		stu.ranking = _ranking;
	}

	return is;
}
