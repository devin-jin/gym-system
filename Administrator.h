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

class Administrator :public Identity  //����Ա��
{
public:
	int id;
	Administrator();  //Ĭ�Ϲ��캯��
	Administrator(string un, string pwd); //�вι��캯��

	//�˵�����
	virtual void openMenu();  

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//��ӿγ���Ϣ
	void addCourse();

	//�鿴�γ���Ϣ
	void showCourse();

	//��տγ�
	void cleanCourse();

	//�޸��˻���Ϣ
	void change();

	//��ʼ������
	void initVector();

	//��Ա����
	vector<Member>vMem;

	//��������
	vector<Coach>vCoa;

	//�γ���Ϣ����
	vector<Course>vCou;
};