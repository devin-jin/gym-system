#include"Member.h"

//默认构造
Member::Member() 
{
	username = "";
	password = "";
	name = "";
	score = 0;
	level = 0;
	balance = 0.0;
	for (int i = 0; i < 10; i++) { CouId[i] = 0; }
}

//有参构造
Member::Member(string un, string pwd) 
{
	//初始化会员信息
	this->username = un;
	this->password = pwd;

	//初始化课程信息
	ifstream ifs;
	ifs.open(COURSE_FILE, ios::in);

	Course cou;
	while (ifs >> cou.CouId && ifs >> cou.subject && ifs >> cou.coachid
		&& ifs >> cou.date.year && ifs >> cou.date.month && ifs >> cou.date.day
		&& ifs >> cou.starttime.hour && ifs >> cou.starttime.minute && ifs >> cou.starttime.second
		&& ifs >> cou.endtime.hour && ifs >> cou.endtime.minute && ifs >> cou.endtime.second
		&& ifs >> cou.fee && ifs >> cou.students && ifs >> cou.classhour)
	{
		vCou.push_back(cou);
	}
	ifs.close();
}

//菜单界面
void Member::openMenu()
{
	cout << "欢迎会员：" << this->name << "登录" << endl;
	cout << "\t\t-------------------------------\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          1.查看信息         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          2.修改信息         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          3.查看课程         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          4.课程管理         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t-------------------------------\n";
	cout << "请输入您的选择：";
}

//查看信息
void Member::printMember()
{
	cout << "用户名：" << username << endl
		<< "密码：" << password << endl
		<< "姓名：" << name << endl
		<< "积分：" << score << endl
		<< "会员等级：" << level << endl
		<< "账户余额：" << balance << endl
		<< "已报课程ID：";
	for (int i = 0; i < 10 && CouId[i] != 0; i++)
	{
		cout << CouId[i] << " ";
	}
	cout << endl;
}

//修改信息
void Member::change()
{
	fstream fs;
	bool find = false;  //逻辑判断是否找到
	fs.open(MEM_FILE, ios::in | ios::out | ios::binary | ios::app);

	Member mem[50];
	int i = 0, j = 0;
	for (; i < 50; i++)
	{
		fs.read((char*)&mem[i], sizeof(mem[i]));  //从文件读取会员信息
		if (username == mem[i].username)
		{
			j = i;
			find = true;  //标示已找到
		}
		if (fs.eof())break;  //到达文件末尾时退出
	}
	fs.close();

	if (find)
	{
		cout << "请输入需要更改的信息：" << endl;
		cout << "1、密码" << endl;
		cout << "2、姓名" << endl;
		cout << "0、退出" << endl;

		int select;
		cin >> select;
		switch (select)
		{
		case 1:  //修改密码
		{
			bool flag = false;
			while (!flag)
			{
				string pwd1, pwd2;
				cout << "新密码：";
				cin >> pwd1;
				cout << "确认密码：";
				cin >> pwd2;
				if (pwd1 == pwd2)
				{
					password = mem[j].password = pwd1;
					flag = true;
					cout << "密码修改成功！" << endl;
				}
				else
				{
					cout << "两次密码输入不一致，请重新输入！" << endl;
				}
			}
			break;
		}
		case 2:  //修改姓名
		{
			string n;
			cout << "更改姓名为：";
			cin >> n;
			name = mem[j].name = n;
			cout << "姓名修改成功！" << endl;
			break;
		}
		case 0:  //退出
		{
			cout << "\n已退出修改界面\n\n";
			system("pause");
			break;
		}
		default:
		{
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");//清屏
			break;
		}
		}
	}
	else
	{
		cout << "404 Not Found!" << endl;
	}

	//修改好的数组输出到文件
	ofstream ofs;
	ofs.open(MEM_FILE, ios::in | ios::out | ios::binary);
	for (int k = 0; k <= i; k++)
	{
		ofs << mem[k].username << " " << mem[k].password << " " << mem[k].name << " " << mem[k].score
			<< " " << mem[k].level << " " << mem[k].balance << " ";
		for (int l = 0; l < 10 && mem[k].CouId[l] != 0; l++)
		{
			ofs << mem[k].CouId[l] << " ";
		}
	}
	ofs << endl;
	ofs.close();
}

//查看课程
void Member::showCourse()
{
	cout << "已报课程：" << endl;


	system("pause");
	system("cls");
}

//课程管理
void Member::manageCourse()
{
	cout << "全部课程信息如下：" << endl;



	cout << "请输入需要报名的课程编号：";
	int num;
	cin >> num;



	system("pause");
	system("cls");
}