#pragma once
#include<iostream>
using namespace std;
#include "globalFile.h"
#include <fstream>
#include <string>

struct Date
{
	int year;
	int month;
	int day;
};
struct Time
{
	int hour;
	int minute;
	int second;
};

class Course  //课程类
{
public:
	int CouId;  //课程编号
	string subject;  //课程名
	string coachid;  //教练id
	Date date;  //开课日期
	Time starttime;  //上课时间
	Time endtime;  //下课时间
	float fee;  //费用
	int students;  //学员数
	float classhour;  //课时

	//课程信息初始化
	Course()
	{
		CouId = 0;
		subject = "";
		coachid = 0;
		date = { 2000,1,1 };
		starttime = { 0,0,0 };
		endtime = { 0,0,0 };
		fee = 0.0;
		students = 0;
		classhour = 0.0;
	}
};

//ostream& operator<<(ostream&cout, Date& d) 
//{ 
//	cout << d.year << "年" << d.month << "月" << d.day << "日";
//	return cout;
//}
//istream& operator>>(istream&cin, Date& d) 
//{ 
//	cin >> d.year >> d.month >> d.day; 
//	return cin;
//}
//ostream& operator<<(ostream&cout, Time& t) 
//{
//	cout << t.hour << ":" << t.minute << ":" << t.second; 
//	return cout;
//}
//istream& operator>>(istream&cin, Time& t)
//{ 
//	cin >> t.hour >> t.minute >> t.second; 
//	return cin;
//}
//ostream& operator<<(ostream& cout, Course& c)
//{
//	cout << c.CouId << " " << c.subject << " " << c.coachname << " " << c.date << " "
//		<< c.starttime << " " << c.endtime << " " << c.fee << " " << c.students << " " << c.classhour;
//	return cout;
//}