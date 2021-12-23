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

class Course  //�γ���
{
public:
	int CouId;  //�γ̱��
	string subject;  //�γ���
	string coachid;  //����id
	Date date;  //��������
	Time starttime;  //�Ͽ�ʱ��
	Time endtime;  //�¿�ʱ��
	float fee;  //����
	int students;  //ѧԱ��
	float classhour;  //��ʱ

	//�γ���Ϣ��ʼ��
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
//	cout << d.year << "��" << d.month << "��" << d.day << "��";
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