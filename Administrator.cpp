#include"Administrator.h"

//默认构造
Administrator::Administrator() 
{
	username = ""; 
	password = ""; 
	id = 0; 
}

//有参构造
Administrator::Administrator(string un, string pwd)
{
	//初始化管理员信息
	this->username = un;
	this->password = pwd;

	//初始化容器，获取到所有文件中会员、教练信息
	this->initVector();

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
void Administrator::openMenu()
{
	cout << "欢迎管理员：" << this->id << "登录" << endl;
	cout << "\t\t-------------------------------\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          1.添加账号         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          2.查看账号         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          3.添加课程         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          4.查看课程         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          5.清空课程         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          6.修改信息         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t-------------------------------\n";
	cout << "请输入您的选择：";
}

//添加账号
void Administrator::addPerson()
{
	cout << "请输入添加账号类型" << endl;
	cout << "1、添加会员" << endl;
	cout << "2、添加教练" << endl;

	string fileName;
	ofstream ofs;
	
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = MEM_FILE;
	}
	else if (select == 2)
	{
		fileName = COA_FILE;
	}

	//利用追加的方式 写文件
	ofs.open(fileName, ios::out|ios::app);
	string username;
	string password;
	cout << "请输入账号：" << endl;
	cin >> username;
	cout<< "请输入密码：" << endl;
	cin >> password;

	//向文件中添加数据
	ofs << username << " " << password << " " <<endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");
	ofs.close();

	//调用初始化容器接口，从新获取文件中的数据
	this->initVector();
}

void printMember(Member& m)
{
	cout << "用户名：" << m.username << endl
		<< "  密码：" << m.password << endl
		<< "  姓名：" << m.name << endl
		<< "  积分：" << m.score << endl
		<< "  会员等级：" << m.level << endl
		<< "  账户余额：" << m.balance << endl;
}
void printCoach(Coach& c)
{
	cout << "用户名：" << c.username << endl
		<< "  密码：" << c.password << endl
		<< "  姓名：" << c.name << endl;
}
void printAdmin(Administrator& a)
{
	cout << "用户名：" << a.username << endl
		<< "  密码：" << a.password << endl
		<< "ID：" << a.id << endl;
} 
void printCourse(Course& cou)
{
	cout << "课程编号：" << cou.CouId << endl
		<< "课程名：" << cou.subject << endl
		<< "教练id：" << cou.coachid << endl
		<< "开课日期：" << cou.date.year << "年" << cou.date.month << "月" << cou.date.day << "日" << endl
		<< "上课时间：" << cou.starttime.hour << ":" << cou.starttime.minute << ":" << cou.starttime.second << endl
		<< "下课时间：" << cou.endtime.hour << ":" << cou.endtime.minute << ":" << cou.endtime.second << endl
		<< "费用：" << cou.fee << "元" << endl
		<< "学员数：" << cou.students << endl
		<< "课时：" << cou.classhour << "h" << endl;
}

//查看账号
void Administrator::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1.查看所有会员" << endl;
	cout << "2.查看所有教练" << endl;
	
	int select = 0;  //接受用户选择
	cin >> select;
	while(select)
	{
		if (select == 1)  //查看会员
		{
			cout << "所有会员信息如下：" << endl;
			for_each(vMem.begin(), vMem.end(), printMember);
			break;
		}
		else if (select == 2)  //查看教练
		{
			cout << "所有教练信息如下：" << endl;
			for_each(vCoa.begin(), vCoa.end(), printCoach);
			break;
		}
		else
		{
			cout << "输入有误，请重新选择！" << endl;
			cin >> select;
		}
	}

	system("pause");
	system("cls");
}

//添加课程
void Administrator::addCourse()
{
	cout << "请输入课程编号：";
	int CouId = 0; cin >> CouId;
	cout << "请输入课程名：";
	string subject = ""; cin >> subject;
	cout << "请输入教练ID：";
	int coachid = 0; cin >> coachid;
	cout << "请输入开课日期：";
	Date date = { 0,0,0 }; cin >> date.year >> date.month >> date.day;
	cout << "请输入上课时间：";
	Time starttime = { 0,0,0 }; cin >> starttime.hour >> starttime.minute >> starttime.second;
	cout << "请输入下课时间：";
	Time endtime = { 0,0,0 }; cin >> endtime.hour >> endtime.minute >> endtime.second;
	cout << "请输入课程费用：";
	float fee = 0; cin >> fee;
	int students = 0;
	float classhour = 0;

	//利用追加的方式 写文件
	ofstream ofs;
	ofs.open(COURSE_FILE, ios::out | ios::app);

	ofs << CouId << " " << subject << " " << coachid << " " 
		<< date.year<<" "<<date.month<<" "<<date.day << " " 
		<< starttime.hour<<" "<<starttime.minute<<" "<<starttime.second << " " 
		<< endtime.hour<<" " <<endtime.minute<<" "<<endtime.second << " " 
		<< fee << " " << students << " " << classhour << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");
	ofs.close();
}

//查看课程信息
void Administrator::showCourse()
{
	cout << "课程信息如下：" << endl;
	for (vector<Course>::iterator it = vCou.begin(); it <= vCou.end(); it += sizeof(Course))
	{
		printCourse(*it);
	}
	system("pause");
	system("cls");
}

//清空课程
void Administrator::cleanCourse()
{
	ofstream ofs(COURSE_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

//修改账户信息
void Administrator::change()
{
	cout << "请输入更改账户类型" << endl;
	cout << "1、更改会员账户信息" << endl;
	cout << "2、更改教练账户信息" << endl;
	cout << "3、更改管理员账户信息" << endl;

	fstream fs;
	string un;
	bool find = false;  //逻辑判断是否找到

	int select = 0;
	cin >> select;
	while (select)
	{
		if (select == 1)
		{
			//更改会员账户信息
			fs.open(MEM_FILE, ios::in | ios::out | ios::binary | ios::app);
			cout << "请输入要更改的会员账户用户名：";
			cin >> un;

			Member mem[50];
			int i = 0, j = 0;
			for (; i < 50; i++)
			{
				fs.read((char*)&mem[i], sizeof(mem[i]));  //从文件读取会员信息
				if (un == mem[i].username)
				{
					j = i;
					cout << "账户 " << un << " 的信息为：" << endl;
					printMember(mem[j]);  //输出该会员的全部信息
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
				cout << "3、积分" << endl;
				cout << "4、账户余额" << endl;
				cout << "0、退出" << endl;

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
							mem[j].password = pwd1;
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
					mem[j].name = n;
					cout << "姓名修改成功！" << endl;
					break;
				}
				case 3:  //积分管理
				{
					int s;
					cout << "积分变动（增加/扣除）";
					cin >> s;
					mem[j].score += s;
					cout << "积分增加或扣除成功！" << endl;
					cout << "当前积分：" << mem[i].score << endl;
					break;
				}
				case 4:  //储值管理
				{
					float b;
					cout << "充值/消费（元）：";
					cin >> b;
					mem[j].balance += b;
					cout << "账户余额充值或消费成功！" << endl;
					cout << "当前余额：" << mem[i].balance << "元" << endl;
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
				cout << "不存在该账户！" << endl;
				break;
			}

			//修改好的数组输出到文件
			ofstream ofs;
			ofs.open(MEM_FILE, ios::in | ios::out | ios::binary);
			for (int k = 0; k <= i; k++)
			{
				ofs << mem[k].username << " " << mem[k].password << " " << mem[k].name << " " << mem[k].score
					<< " " << mem[k].level << " " << mem[k].balance << " ";
				for (int l = 0; l < 50 && mem[k].CouId[l] != 0; l++)
				{
					ofs << mem[k].CouId[l] << " ";
				}
			}
			ofs << endl;
			ofs.close();
		}
		else if (select == 2)
		{
			//更改教练账户信息
			fs.open(COA_FILE, ios::in | ios::out | ios::binary | ios::app);
			cout << "请输入要更改的教练账户用户名（ID）：";
			cin >> un;

			Coach coa[10];
			int i = 0, j = 0;
			for (; i < 10; i++)
			{
				fs.read((char*)&coa[i], sizeof(coa[i]));  //从文件读取会员信息
				if (un == coa[i].username)
				{
					j = i;
					cout << "账户 " << un << " 的信息为：" << endl;
					printCoach(coa[j]);  //输出该会员的全部信息
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
							coa[j].password = pwd1;
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
					coa[j].name = n;
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
				cout << "不存在该账户！" << endl;
				break;
			}

			//修改好的数组输出到文件
			ofstream ofs;
			ofs.open(COA_FILE, ios::in | ios::out | ios::binary);
			for (int k = 0; k <= i; k++)
			{
				ofs << coa[k].username << " " << coa[k].password << " " << coa[k].name << " ";
				for (int l = 0; l < 10 && coa[k].CouId[l] != 0; l++)
				{
					ofs << coa[k].CouId[l] << " ";
				}
			}
			ofs << endl;
			ofs.close();
		}
		else if (select == 3)
		{
			//更改管理员账户信息(修改自己的账户)
			fs.open(ADMIN_FILE, ios::in | ios::out | ios::binary | ios::app);

			Administrator admin[3];
			int i = 0, j = 0;
			for (; i < 3; i++)
			{
				fs.read((char*)&admin[i], sizeof(admin[i]));  //从文件读取管理员信息
				if (username == admin[i].username)
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
							password = admin[j].password = pwd1;
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
			ofs.open(ADMIN_FILE, ios::in | ios::out | ios::binary);
			for (int k = 0; k <= i; k++)
			{
				ofs << admin[k].username << " " << admin[k].password << " " << admin[k].id;
			}
			ofs << endl;
			ofs.close();
			break;
		}
		else
		{
			cout << "输入有误，请重新选择！" << endl;
		}
		cin >> select;
	}
	cout << endl;
}

//初始化容器
void Administrator::initVector()
{
	//确保容器清空状态
	vMem.clear();
	vCoa.clear();

	//读取信息   会员
	ifstream ifs;
	ifs.open(MEM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Member文件读取失败" << endl;
		return;
	}

	Member m; 
	while (ifs >> m.username&& ifs >> m.password&& ifs >> m.name&& ifs >> m.score
		&& ifs >> m.level&& ifs >> m.balance&& ifs >> m.CouId[0] && ifs >> m.CouId[1]
		&& ifs >> m.CouId[2] && ifs >> m.CouId[3] && ifs >> m.CouId[4] && ifs >> m.CouId[5]
		&& ifs >> m.CouId[6] && ifs >> m.CouId[7] && ifs >> m.CouId[8] && ifs >> m.CouId[9])
	{
		vMem.push_back(m);
	}
	ifs.close();

	//读取信息   教练
	ifs.open(COA_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Coach文件读取失败" << endl;
		return;
	}

	Coach c;
	while (ifs >> c.username&& ifs >> c.password && ifs >> m.name && ifs >> m.CouId[0] && ifs >> m.CouId[1]
		&& ifs >> m.CouId[2] && ifs >> m.CouId[3] && ifs >> m.CouId[4] && ifs >> m.CouId[5]
		&& ifs >> m.CouId[6] && ifs >> m.CouId[7] && ifs >> m.CouId[8] && ifs >> m.CouId[9])
	{
		vCoa.push_back(c);
	}
	ifs.close();
}