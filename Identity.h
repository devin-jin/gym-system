#pragma once
#include<iostream>
using namespace std;

//��ݳ������
class Identity
{
public:
	string username;  //�û������˺ţ�
	string password;  //����
	virtual void openMenu() = 0;  //�����˵� ���麯��
};