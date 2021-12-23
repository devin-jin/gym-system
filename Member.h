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

class Member :public Identity  //��Ա��
{
public:
	string name;  //����
	int score;  //����
	int level;  //��Ա�ȼ�
	float balance;  //�˻����
	int CouId[10];  //�γ̱��

	Member();  //Ĭ�Ϲ��캯��
	Member(string un, string pwd);  //�вι��캯��

	virtual void openMenu();

	//�鿴��Ϣ
	void printMember();

	//�޸���Ϣ
	void change();

	//�鿴�γ�
	void showCourse();

	//�γ̹���
	void manageCourse();

	//�γ�����
	vector<Course> vCou;
};