#pragma once
#include<iostream>
using namespace std;

//身份抽象基类
class Identity
{
public:
	string username;  //用户名（账号）
	string password;  //密码
	virtual void openMenu() = 0;  //操作菜单 纯虚函数
};