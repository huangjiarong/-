#ifndef _INTERFACE
#define _INTERFACE

#include <vector>
#include "student.h"

class Interface
{
	protected :
		vector<Student> stu_vec;	//总的学生信息
		vector<Student> stu_vec1;	//第一学期的学生信息
		vector<Student> stu_vec2;	//第二学期的学生信息

	public :
		Interface ();
		void Readfile (); 	//读取文件	
		void Display ();	//显示菜单
		void Run ();		//运行
		void Save ();		//保存信息
		void Insert ();		//插入信息
		void Search ();		//查询信息
		void Delete ();		//删除信息
		void Sort ();		//对信息进行分类
		void Output ();		//显示全部数据
		void Statistics ();	//统计数据
		void Under_sixty ();//分数低于60分的同学
		void Great_stu ();	//有领奖学金资格的同学
};

#endif
