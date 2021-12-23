#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include<vector>
#include"Member.h"
#include"Coach.h"
#include<algorithm>
#include"Course.h"

//ostream& operator<<(ostream& cout, Administrator& a)
//{
//	cout << a.username << " " << a.password << " " << a.id;
//	return cout;
//}

class Administrator :public Identity  //管理员类
{
public:
	int id;
	Administrator();  //默认构造函数
	Administrator(string un, string pwd); //有参构造函数

	//菜单界面
	virtual void openMenu();  

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//添加课程信息
	void addCourse();

	//查看课程信息
	void showCourse();

	//清空课程
	void cleanCourse();

	//修改账户信息
	void change();

	//初始化容器
	void initVector();

	//会员容器
	vector<Member>vMem;

	//教练容器
	vector<Coach>vCoa;

	//课程信息容器
	vector<Course>vCou;
};