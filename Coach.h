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

class Coach :public Identity  //������
{
public:
	string name;  //����
	int CouId[10];  //�γ̱��

	Coach();  //Ĭ�Ϲ��캯��
	Coach(string pwd, string name);  //�вι��캯��

	virtual void openMenu();

	//�鿴��Ϣ
	void printCoach();

	//�޸���Ϣ
	void change();

	//�鿴�γ�
	void showCourse();

	//�γ�����
	vector<Course> vCou;
};