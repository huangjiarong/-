#include "interface.h"
#include "student.h"
#include <iostream>
#include <fstream>
#include <algorithm>	//copy, sort
#include <iterator>	//istream_iterator, back_inserter

using namespace std;

Interface::Interface ()
{
	Readfile ();
}

void Interface::Display ()
{
	cout << '\t' << "欢迎来到学生成绩管理系统" << endl;
	cout << '\t' << " 0.保存并退出本系统 " << endl;
	cout << '\t' << " 1.添加学生信息" << endl;
	cout << '\t' << " 2.查询学生信息" << endl;
	cout << '\t' << " 3.统计学生信息" << endl;
	cout << '\t' << " 4.删除学生信息" << endl;
	cout << '\t' << " 5.输出所有信息" << endl;
}

void Interface::Run ()
{
	int choice;

	do
	{
		Display ();
		cout << "请输入你的选择 : ";
		cin >> choice;
		switch ( choice )
		{
			case 0 :
				cout << "感谢您的使用,再见" << endl;
				break;
			case 1 :
				Insert ();
				break;
			case 2 :
				Search ();
				break;
			case 3 :
				Statistics ();
				break;
			case 4 :
				Delete ();
				break;
			case 5 :
				Output ();
				break;
			default	:
				cout << "请输入正确的选择(1到5) " << endl;
				continue;
		}
	} while ( choice );

	Save ();
}

void Interface::Save ()
{
	ofstream out ( "record.txt" );
	if ( !out )
	{
		cout << "Can't open the file." << endl;
		return;
	}

	Sort ();	//每次操作后都重新排序

	for ( auto &stu : stu_vec )	//C++11标准,范围循环,需要编译器支持C++11标准
	{
		out << stu << endl;
	}

	out.close ();
}

void Interface::Insert ()	
{
	string name, number, term;
	double math, sports, java;
	char choice;

	do
	{
		cout << "请按顺序输入学生信息 (学期, 姓名, 学号, 高数成绩, 体育成绩, java成绩 )" << endl;
		cin >> term >> name >> number;
		cin >> math >> sports >> java;

		Student temp ( term, name, number, math, sports, java );
		stu_vec.push_back ( temp );
		if ( term == "第一" )
			stu_vec1.push_back ( temp );
		else
			stu_vec2.push_back ( temp );

		cout << "继续输入? (y/n) : ";
		cin >> choice;
	} while ( choice == 'y' || choice == 'Y' );

	Sort (); //插入信息后进行排序分类,将第一学期和第二学期的区分开
}

void Interface::Readfile ()
{
	ifstream in ( "record.txt");
	if ( !in )
	{
		cerr << "Can't open the file." << endl;
		return;
	}

	copy ( istream_iterator<Student> (in), istream_iterator<Student> (), back_inserter (stu_vec) );	//拷贝文件当前的数据

	for ( auto s : stu_vec )
	{
		if ( s.Get_term() == "第一" )
			stu_vec1.push_back ( s );
		else
			stu_vec2.push_back ( s );
	}
	in.close ();
}

void Interface::Search ()
{
	string name, number;
	int choice;
	for ( ; ; )
	{
		cout << '\t' << "0.返回上一层. " << endl;
		cout << '\t' << "1.按学生学号查询 " << endl;
		cout << '\t' << "2.按学生名字查询 " << endl;
		cout << "请输入您的选择 : ";
		cin >> choice;
		switch ( choice )
		{
			case 0 : return;
			case 1 : cout << "请输入要查询的学生学号 : ";
					 cin >> number;
					 cout << "学期" << '\t' << "姓名" << '\t' << "      "  << "学号" << '\t' << "高数" << '\t' << "体育" << '\t' << "java" << '\t' << "平均分" << '\t' << "名次" << endl;
				
					 for ( auto &s : stu_vec )	//C++11标准范围循环
					 {
					 	if ( s.Get_number() == number )
					 	{
					 		cout << s << endl;
					 	}
					 }
					 break;
			case 2 : cout << "请输入要查询的学生姓名 : ";
					 cin >> name;
				
					 cout << "学期" << '\t' << "姓名" << '\t' << "      "  << "学号" << '\t' << "高数" << '\t' << "体育" << '\t' << "java" << '\t' << "平均分" << '\t' << "名次" << endl;
					 for ( auto &s : stu_vec )	//C++11标准范围循环
					 {
					 	if ( s.Get_name() == name )
					 	{
					 		cout << s << endl;
					 	}
					 }
					 break;
			default : cout << "请输入正确的选择 ( 0,1或2 )" << endl;
					  break;
		}
	}
}

void Interface::Delete ()
{
	cout << "请输入要删除的学生的学号 : ";
	string _number;
	cin >> _number;

	//从第一学期中把该同学数据删除
	vector<Student>::iterator iter1 = stu_vec1.begin ();
	vector<Student>::iterator iter1_temp = stu_vec1.begin ();
	while ( iter1 != stu_vec1.end() )
	{
		if ( iter1->Get_number() == _number)
		{
			stu_vec1.erase (iter1);
			cout << "删除成功" << endl;
			iter1 = iter1_temp;
		}
		else
		{
			++iter1;
			++iter1_temp;
		}
	}

	//从第二学期中把该同学数据删除
	vector<Student>::iterator iter2 = stu_vec2.begin ();
	vector<Student>::iterator iter2_temp = stu_vec2.begin ();
	while ( iter2 != stu_vec2.end() )
	{
		if ( iter2->Get_number() == _number)
		{
			stu_vec2.erase (iter2);
			cout << "删除成功" << endl;
			iter2 = iter2_temp;
		}
		else
		{
			++iter2;
			++iter2_temp;
		}
	}
	
	//从总的vector中把该同学数据删除
	vector<Student>::iterator iter = stu_vec.begin ();
	vector<Student>::iterator iter_temp = stu_vec.begin ();
	while ( iter != stu_vec.end() )
	{
		if ( iter->Get_number() == _number)
		{
			stu_vec.erase (iter);
			iter = iter_temp;
		}
		else
		{
			++iter;
			++iter_temp;
		}
	}
	Sort ();
}

void Interface::Sort ()
{
	sort ( stu_vec1.begin(), stu_vec1.end(),
			[] ( Student a, Student b )
			{ return a.Get_average() > b.Get_average(); }
		 );	//sort的第三个参数是lambda表达式,需要编译器支持并开启C++11标准
	sort ( stu_vec2.begin(), stu_vec2.end(),
			[] ( Student a, Student b )
			{ return a.Get_average() > b.Get_average(); }
		 );	//sort的第三个参数是lambda表达式,需要编译器支持并开启C++11标准

	int ranking1 = 0;
	vector<Student>::iterator iter1 = stu_vec1.begin ();
	for ( auto end_iter = stu_vec1.end(); iter1 != end_iter; ++iter1 )
	{
		++ranking1;
		iter1->Change_ranking ( ranking1 );
	}

	int ranking2 = 0;
	vector<Student>::iterator iter2 = stu_vec2.begin ();
	for ( auto end_iter = stu_vec2.end(); iter2 != end_iter; ++iter2 )
	{
		++ranking2;
		iter2->Change_ranking ( ranking2 );
	}

	stu_vec.clear();
	stu_vec = stu_vec1;
	for ( auto s : stu_vec2 )
		stu_vec.push_back ( s );
}

void Interface::Output ()
{
	cout << "学期" << '\t' << "姓名" << '\t' << "      "  << "学号" << '\t' << "高数" << '\t' << "体育" << '\t' << "java" << '\t' << "平均分" << '\t' << "名次" << endl;
	for ( auto s : stu_vec )
		cout << s << endl;
}

void Interface::Statistics ()
{
	int choice;
	for (;;)
	{
		cout << '\t' << "请选择要统计的信息 : " << endl;
		cout << '\t' << "0. 返回主界面" << endl;
		cout << '\t' << "1. 某学期不及格学生 " << endl;
		cout << '\t' << "2. 某学期有资格评奖学金的学生 " << endl;
		cout << "请输入您的选择 : ";
		cin >> choice;
		switch ( choice )
		{
			case 0 :
				return;
			case 1 :
				Under_sixty ();
				break;
			case 2 :
				Great_stu ();
				break;
		}
	}
}

void Interface::Under_sixty ()
{
	cout << "请输入学期和科目 ( 例:第一 数学 ) : ";
	string term, project;
	int count = 0;
	cin >> term >> project;
	if ( term == "第一" )
	{
		if ( project == "数学" )
		{
			cout << "第一学期数学不及格的学生 : " << endl;
			cout << "学期" << '\t' << "姓名" << '\t' << "学号" << '\t' << '\t' << "数学" << endl;
			for ( auto &s : stu_vec1 )
			{
				if ( s.Get_math() < 60 )
				{
					cout << s.Get_term() << '\t' << s.Get_name() << '\t' << s.Get_number() << '\t' << s.Get_math() << endl;
					++count;
				}
			}
			cout << "一共有 " << count << " 人." << endl;
		}
		if ( project == "体育" )
		{
			cout << "第一学期体育不及格的学生 : " << endl;
			cout << "学期" << '\t' << "姓名" << '\t' << "学号" << '\t' << '\t' << "体育" << endl;
			for ( auto &s : stu_vec1 )
			{
				if ( s.Get_sports() < 60 )
				{
					cout << s.Get_term() << '\t' << s.Get_name() << '\t' << s.Get_number() << '\t' << s.Get_sports() << endl;
					++count;
				}
			}
			cout << "一共有 " << count << " 人." << endl;
		}
		if ( project == "java" )
		{
			cout << "第一学期java不及格的学生 : " << endl;
			cout << "学期" << '\t' << "姓名" << '\t' << "学号" << '\t' << '\t' << "java" << endl;
			for ( auto &s : stu_vec1 )
			{
				if ( s.Get_java() < 60 )
				{
					cout << s.Get_term() << '\t' << s.Get_name() << '\t' << s.Get_number() << '\t' << s.Get_java() << endl;
					++count;
				}
			}
			cout << "一共有 " << count << " 人." << endl;
		}
	}
	else
	{
		if ( project == "数学" )
		{
			cout << "第二学期数学不及格的学生 : " << endl;
			cout << "学期" << '\t' << "姓名" << '\t' << "学号" << '\t' << '\t' << "数学" << endl;
			for ( auto &s : stu_vec2 )
			{
				if ( s.Get_math() < 60 )
				{
					cout << s.Get_term() << '\t' << s.Get_name() << '\t' << s.Get_number() << '\t' << s.Get_math() << endl;
					++count;
				}
			}
			cout << "一共有 " << count << " 人." << endl;
		}
		if ( project == "体育" )
		{
			cout << "第一学期体育不及格的学生 : " << endl;
			cout << "学期" << '\t' << "姓名" << '\t' << "学号" << '\t' << '\t' << "体育" << endl;
			for ( auto &s : stu_vec2 )
			{
				if ( s.Get_sports() < 60 )
				{
					cout << s.Get_term() << '\t' << s.Get_name() << '\t' << s.Get_number() << '\t' << s.Get_sports() << endl;
					++count;
				}
			}
			cout << "一共有 " << count << " 人." << endl;
		}
		if ( project == "java" )
		{
			cout << "第一学期java不及格的学生 : " << endl;
			cout << "学期" << '\t' << "姓名" << '\t' << "学号" << '\t' << '\t' << "java" << endl;
			for ( auto &s : stu_vec2 )
			{
				if ( s.Get_java() < 60 )
				{
					cout << s.Get_term() << '\t' << s.Get_name() << '\t' << s.Get_number() << '\t' << s.Get_java() << endl;
					++count;
				}
			}
			cout << "一共有 " << count << " 人." << endl;
		}
	}
}

void Interface::Great_stu ()
{
	string term;
	cout << "请输入学期 ( 第一或者第二 ) : " ;
	cin >> term;

	if ( term == "第一" )
	{
		cout << "学期" << '\t' << "姓名" << '\t' << "      "  << "学号" << '\t' << "高数" << '\t' << "体育" << '\t' << "java" << '\t' << "平均分" << '\t' << "名次" << endl;
		for ( auto s : stu_vec1 )
		{
			if ( s.Get_math() >= 85 && s.Get_sports() >= 85 && s.Get_java() >= 85 )
				cout << s << endl;
		}
	}
	else if ( term == "第二" )
	{
		cout << "学期" << '\t' << "姓名" << '\t' << "      "  << "学号" << '\t' << "高数" << '\t' << "体育" << '\t' << "java" << '\t' << "平均分" << '\t' << "名次" << endl;
		for ( auto s : stu_vec2 )
		{
			if ( s.Get_math() >= 85 && s.Get_sports() >= 85 && s.Get_java() >= 85 )
				cout << s << endl;
		}
	}
	else
		cout << "请输入正确的学期 (第一或者第二) " << endl;
}
