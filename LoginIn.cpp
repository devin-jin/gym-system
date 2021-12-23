#include<iostream>
using namespace std;
#include "Identity.h"
#include<fstream>
#include<string>
#include "globalFile.h"
#include "Member.h"
#include "Coach.h"
#include "Administrator.h"

//进入会员子菜单界面
void MemberMenu(Identity*& member)
{
	while (true)
	{
		//调用会员子菜单
		member->openMenu();

		Member* mem = (Member*)member;

		int select = 0;
		cin >> select; //接受用户选择

		if (select == 1) //查看信息
		{
			mem->printMember();
		}
		else if (select == 2) //修改信息
		{
			mem->change();
		}
		else if (select == 3) //查看课程
		{
			mem->showCourse();
		}
		else if (select == 4) //课程管理
		{
			mem->manageCourse();
		}
		else
		{
			//注销登录
			delete member;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入教练子菜单界面
void CoachMenu(Identity*& coach)
{
	while (true)
	{
		//调用教练子菜单
		coach->openMenu();

		Coach* coa = (Coach*)coach;

		int select = 0; //接受用户选择
		cin >> select;

		if (select == 1) //查看信息
		{
			coa->printCoach();
		}
		else if (select == 2) //修改信息
		{
			coa->change();
		}
		else if (select == 3) //查看课程
		{
			coa->showCourse();
		}
		else
		{
			delete coach;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员子菜单界面
void AdminMenu(Identity*& admin) 
{
	while (true) 
	{
		//调用管理员子菜单
		admin->openMenu();

		Administrator* adm = (Administrator*)admin;

		int select = 0;
		cin >> select;

		if (select == 1)  //添加账号
		{
			adm->addPerson();
		}
		else if (select == 2)  //查看账号
		{
			adm->showPerson();
		}
		else if (select == 3)  //添加课程
		{
			adm->addCourse();
		}
		else if (select == 4)  //查看课程
		{
			adm->showCourse();
		}
		else if (select == 5)  //清空课程
		{
			adm->cleanCourse();
		}
		else if (select == 6)  //修改信息
		{
			adm->change();
		}
		else 
		{
			delete admin;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能
void LoginIn(string fileName, int type)
{
	//基类指针，用于指向派生类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//接受用户的信息
	string name;
	string pwd;
	if (type)
	{
		cout << "请输入你的用户名：" << endl;
		cin >> name;
		cout << "请输入你的密码：" << endl;
		cin >> pwd;
	}

	//会员登录验证
	if (type == 1) 
	{
		string fName;  //从文件中获取的用户名
		string fPwd;  //从文件中获取密码
		string fn;  //姓名
		int fscore;  //积分
		int flevel;  //会员等级
		float fbalance;  //账户余额
		int fCouId[10];  //课程编号

		while (ifs >> fName && ifs >> fPwd && ifs >> fn && ifs >> fscore && ifs >> flevel
			&& ifs >> fbalance && ifs >> fCouId[0] && ifs >> fCouId[1] && ifs >> fCouId[2]
			&& ifs >> fCouId[3] && ifs >> fCouId[4] && ifs >> fCouId[5] && ifs >> fCouId[6]
			&& ifs >> fCouId[7] && ifs >> fCouId[8] && ifs >> fCouId[9])
		{	
			//与用户输入的信息做对比
			if (name == fName && pwd == fPwd) 
			{
				cout << "会员验证登录成功！" << endl;
				system("pause");
				system("cls");

				person = new Member(name, pwd);

				//进入会员子菜单
				MemberMenu(person);
				return;
			}
		}
	}
	//教练登录验证
	else if (type == 2) 
	{
		string fName;  //从文件中获取的用户名
		string fPwd;  //从文件中获取的密码
		string fn;  //从文件中获取的姓名
		int fCouId[10];  //从文件中获取的课程编号

		while (ifs >> fName && ifs >> fPwd && ifs >> fn && ifs >> fCouId[0]
			&& ifs >> fCouId[1] && ifs >> fCouId[2] && ifs >> fCouId[3] 
			&& ifs >> fCouId[4] && ifs >> fCouId[5] && ifs >> fCouId[6] 
			&& ifs >> fCouId[7]&& ifs >> fCouId[8] && ifs >> fCouId[9])
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "教练验证登录成功！" << endl;
				system("pause");
				system("cls");

				person = new Coach(name, pwd);

				//进入教练子菜单
				CoachMenu(person);
				return;
			}
		}
	}
	//管理员登录验证
	else if (type == 3)
	{
		string fName;  //从文件中获取用户名
		string fPwd;  //从文件中获取密码
		int fId;  //从文件中获取管理员ID

		while (ifs >> fName && ifs >> fPwd && ifs >> fId)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");

				person = new Administrator(name, pwd);

				//进入管理员子菜单页面
				AdminMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败!" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;  //选项
	while (true)
	{
		cout << "================ 欢迎来到健身房管理系统 ================" << endl;
		cout << endl << "请输入您的身份：" << endl;
		cout << "\t\t--------------------------------\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          1.会    员          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          2.教    练          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          3.管 理 员          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          0.退    出          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t--------------------------------\n";
		cout << "请输入您的选择：";
		cin >> select;

		switch (select)
		{
		case 1:
			LoginIn(MEM_FILE, 1);
			break;//会员身份
		case 2:
			LoginIn(COA_FILE, 2);
			break;//教练身份
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;//管理员身份
		case 0:  //退出系统
			cout << "\n欢迎下一次使用\n\n";
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");  //清屏
			break;
		}
	}
	system("pause");
	return 0;
}