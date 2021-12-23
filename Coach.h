#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include <string>
#include"Course.h"
#include <fstream>
#include "globalFile.h"
#include <vector>

//ostream& operator<<(ostream& cout, Coach& c)
//{
//	cout << c.username << " " << c.password << " " << c.name << " " << c.course;
//	return cout;
//}

class Coach :public Identity  //教练类
{
public:
	string name;  //姓名
	int CouId[10];  //课程编号

	Coach();  //默认构造函数
	Coach(string pwd, string name);  //有参构造函数

	virtual void openMenu();

	//查看信息
	void printCoach();

	//修改信息
	void change();

	//查看课程
	void showCourse();

	//课程容器
	vector<Course> vCou;
};