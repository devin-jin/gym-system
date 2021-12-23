#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include <string>
#include"Course.h"
#include <fstream>
#include "globalFile.h"
#include <vector>

//ostream& operator<<(ostream&cout, Member& m)
//{ 
//	cout << m.username << " " << m.password << " " << m.name << " " << m.score << " " << m.level << " " << m.balance << " " << m.course;
//	return cout;
//}

class Member :public Identity  //会员类
{
public:
	string name;  //姓名
	int score;  //积分
	int level;  //会员等级
	float balance;  //账户余额
	int CouId[10];  //课程编号

	Member();  //默认构造函数
	Member(string un, string pwd);  //有参构造函数

	virtual void openMenu();

	//查看信息
	void printMember();

	//修改信息
	void change();

	//查看课程
	void showCourse();

	//课程管理
	void manageCourse();

	//课程容器
	vector<Course> vCou;
};