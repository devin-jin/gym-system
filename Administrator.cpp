#include"Administrator.h"

//Ĭ�Ϲ���
Administrator::Administrator() 
{
	username = ""; 
	password = ""; 
	id = 0; 
}

//�вι���
Administrator::Administrator(string un, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->username = un;
	this->password = pwd;

	//��ʼ����������ȡ�������ļ��л�Ա��������Ϣ
	this->initVector();

	//��ʼ���γ���Ϣ
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

//�˵�����
void Administrator::openMenu()
{
	cout << "��ӭ����Ա��" << this->id << "��¼" << endl;
	cout << "\t\t-------------------------------\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          1.����˺�         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          2.�鿴�˺�         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          3.��ӿγ�         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          4.�鿴�γ�         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          5.��տγ�         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          6.�޸���Ϣ         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t-------------------------------\n";
	cout << "����������ѡ��";
}

//����˺�
void Administrator::addPerson()
{
	cout << "����������˺�����" << endl;
	cout << "1����ӻ�Ա" << endl;
	cout << "2����ӽ���" << endl;

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

	//����׷�ӵķ�ʽ д�ļ�
	ofs.open(fileName, ios::out|ios::app);
	string username;
	string password;
	cout << "�������˺ţ�" << endl;
	cin >> username;
	cout<< "���������룺" << endl;
	cin >> password;

	//���ļ����������
	ofs << username << " " << password << " " <<endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");
	ofs.close();

	//���ó�ʼ�������ӿڣ����»�ȡ�ļ��е�����
	this->initVector();
}

void printMember(Member& m)
{
	cout << "�û�����" << m.username << endl
		<< "  ���룺" << m.password << endl
		<< "  ������" << m.name << endl
		<< "  ���֣�" << m.score << endl
		<< "  ��Ա�ȼ���" << m.level << endl
		<< "  �˻���" << m.balance << endl;
}
void printCoach(Coach& c)
{
	cout << "�û�����" << c.username << endl
		<< "  ���룺" << c.password << endl
		<< "  ������" << c.name << endl;
}
void printAdmin(Administrator& a)
{
	cout << "�û�����" << a.username << endl
		<< "  ���룺" << a.password << endl
		<< "ID��" << a.id << endl;
} 
void printCourse(Course& cou)
{
	cout << "�γ̱�ţ�" << cou.CouId << endl
		<< "�γ�����" << cou.subject << endl
		<< "����id��" << cou.coachid << endl
		<< "�������ڣ�" << cou.date.year << "��" << cou.date.month << "��" << cou.date.day << "��" << endl
		<< "�Ͽ�ʱ�䣺" << cou.starttime.hour << ":" << cou.starttime.minute << ":" << cou.starttime.second << endl
		<< "�¿�ʱ�䣺" << cou.endtime.hour << ":" << cou.endtime.minute << ":" << cou.endtime.second << endl
		<< "���ã�" << cou.fee << "Ԫ" << endl
		<< "ѧԱ����" << cou.students << endl
		<< "��ʱ��" << cou.classhour << "h" << endl;
}

//�鿴�˺�
void Administrator::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1.�鿴���л�Ա" << endl;
	cout << "2.�鿴���н���" << endl;
	
	int select = 0;  //�����û�ѡ��
	cin >> select;
	while(select)
	{
		if (select == 1)  //�鿴��Ա
		{
			cout << "���л�Ա��Ϣ���£�" << endl;
			for_each(vMem.begin(), vMem.end(), printMember);
			break;
		}
		else if (select == 2)  //�鿴����
		{
			cout << "���н�����Ϣ���£�" << endl;
			for_each(vCoa.begin(), vCoa.end(), printCoach);
			break;
		}
		else
		{
			cout << "��������������ѡ��" << endl;
			cin >> select;
		}
	}

	system("pause");
	system("cls");
}

//��ӿγ�
void Administrator::addCourse()
{
	cout << "������γ̱�ţ�";
	int CouId = 0; cin >> CouId;
	cout << "������γ�����";
	string subject = ""; cin >> subject;
	cout << "���������ID��";
	int coachid = 0; cin >> coachid;
	cout << "�����뿪�����ڣ�";
	Date date = { 0,0,0 }; cin >> date.year >> date.month >> date.day;
	cout << "�������Ͽ�ʱ�䣺";
	Time starttime = { 0,0,0 }; cin >> starttime.hour >> starttime.minute >> starttime.second;
	cout << "�������¿�ʱ�䣺";
	Time endtime = { 0,0,0 }; cin >> endtime.hour >> endtime.minute >> endtime.second;
	cout << "������γ̷��ã�";
	float fee = 0; cin >> fee;
	int students = 0;
	float classhour = 0;

	//����׷�ӵķ�ʽ д�ļ�
	ofstream ofs;
	ofs.open(COURSE_FILE, ios::out | ios::app);

	ofs << CouId << " " << subject << " " << coachid << " " 
		<< date.year<<" "<<date.month<<" "<<date.day << " " 
		<< starttime.hour<<" "<<starttime.minute<<" "<<starttime.second << " " 
		<< endtime.hour<<" " <<endtime.minute<<" "<<endtime.second << " " 
		<< fee << " " << students << " " << classhour << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");
	ofs.close();
}

//�鿴�γ���Ϣ
void Administrator::showCourse()
{
	cout << "�γ���Ϣ���£�" << endl;
	for (vector<Course>::iterator it = vCou.begin(); it <= vCou.end(); it += sizeof(Course))
	{
		printCourse(*it);
	}
	system("pause");
	system("cls");
}

//��տγ�
void Administrator::cleanCourse()
{
	ofstream ofs(COURSE_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

//�޸��˻���Ϣ
void Administrator::change()
{
	cout << "����������˻�����" << endl;
	cout << "1�����Ļ�Ա�˻���Ϣ" << endl;
	cout << "2�����Ľ����˻���Ϣ" << endl;
	cout << "3�����Ĺ���Ա�˻���Ϣ" << endl;

	fstream fs;
	string un;
	bool find = false;  //�߼��ж��Ƿ��ҵ�

	int select = 0;
	cin >> select;
	while (select)
	{
		if (select == 1)
		{
			//���Ļ�Ա�˻���Ϣ
			fs.open(MEM_FILE, ios::in | ios::out | ios::binary | ios::app);
			cout << "������Ҫ���ĵĻ�Ա�˻��û�����";
			cin >> un;

			Member mem[50];
			int i = 0, j = 0;
			for (; i < 50; i++)
			{
				fs.read((char*)&mem[i], sizeof(mem[i]));  //���ļ���ȡ��Ա��Ϣ
				if (un == mem[i].username)
				{
					j = i;
					cout << "�˻� " << un << " ����ϢΪ��" << endl;
					printMember(mem[j]);  //����û�Ա��ȫ����Ϣ
					find = true;  //��ʾ���ҵ�
				}
				if (fs.eof())break;  //�����ļ�ĩβʱ�˳�
			}
			fs.close();

			if (find)
			{
				cout << "��������Ҫ���ĵ���Ϣ��" << endl;
				cout << "1������" << endl;
				cout << "2������" << endl;
				cout << "3������" << endl;
				cout << "4���˻����" << endl;
				cout << "0���˳�" << endl;

				cin >> select;
				switch (select)
				{
				case 1:  //�޸�����
				{
					bool flag = false;
					while (!flag)
					{
						string pwd1, pwd2;
						cout << "�����룺";
						cin >> pwd1;
						cout << "ȷ�����룺";
						cin >> pwd2;
						if (pwd1 == pwd2)
						{
							mem[j].password = pwd1;
							flag = true;
							cout << "�����޸ĳɹ���" << endl;
						}
						else
						{
							cout << "�����������벻һ�£����������룡" << endl;
						}
					}
					break;
				}
				case 2:  //�޸�����
				{
					string n;
					cout << "��������Ϊ��";
					cin >> n;
					mem[j].name = n;
					cout << "�����޸ĳɹ���" << endl;
					break;
				}
				case 3:  //���ֹ���
				{
					int s;
					cout << "���ֱ䶯������/�۳���";
					cin >> s;
					mem[j].score += s;
					cout << "�������ӻ�۳��ɹ���" << endl;
					cout << "��ǰ���֣�" << mem[i].score << endl;
					break;
				}
				case 4:  //��ֵ����
				{
					float b;
					cout << "��ֵ/���ѣ�Ԫ����";
					cin >> b;
					mem[j].balance += b;
					cout << "�˻�����ֵ�����ѳɹ���" << endl;
					cout << "��ǰ��" << mem[i].balance << "Ԫ" << endl;
					break;
				}
				case 0:  //�˳�
				{
					cout << "\n���˳��޸Ľ���\n\n";
					system("pause");
					break;
				}
				default:
				{
					cout << "��������������ѡ��" << endl;
					system("pause");
					system("cls");//����
					break;
				}
				}
			}
			else
			{
				cout << "�����ڸ��˻���" << endl;
				break;
			}

			//�޸ĺõ�����������ļ�
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
			//���Ľ����˻���Ϣ
			fs.open(COA_FILE, ios::in | ios::out | ios::binary | ios::app);
			cout << "������Ҫ���ĵĽ����˻��û�����ID����";
			cin >> un;

			Coach coa[10];
			int i = 0, j = 0;
			for (; i < 10; i++)
			{
				fs.read((char*)&coa[i], sizeof(coa[i]));  //���ļ���ȡ��Ա��Ϣ
				if (un == coa[i].username)
				{
					j = i;
					cout << "�˻� " << un << " ����ϢΪ��" << endl;
					printCoach(coa[j]);  //����û�Ա��ȫ����Ϣ
					find = true;  //��ʾ���ҵ�
				}
				if (fs.eof())break;  //�����ļ�ĩβʱ�˳�
			}
			fs.close();

			if (find)
			{
				cout << "��������Ҫ���ĵ���Ϣ��" << endl;
				cout << "1������" << endl;
				cout << "2������" << endl;
				cout << "0���˳�" << endl;
				cin >> select;
				switch (select)
				{
				case 1:  //�޸�����
				{
					bool flag = false;
					while (!flag)
					{
						string pwd1, pwd2;
						cout << "�����룺";
						cin >> pwd1;
						cout << "ȷ�����룺";
						cin >> pwd2;
						if (pwd1 == pwd2)
						{
							coa[j].password = pwd1;
							flag = true;
							cout << "�����޸ĳɹ���" << endl;
						}
						else
						{
							cout << "�����������벻һ�£����������룡" << endl;
						}
					}
					break;
				}
				case 2:  //�޸�����
				{
					string n;
					cout << "��������Ϊ��";
					cin >> n;
					coa[j].name = n;
					cout << "�����޸ĳɹ���" << endl;
					break;
				}
				case 0:  //�˳�
				{
					cout << "\n���˳��޸Ľ���\n\n";
					system("pause");
					break;
				}
				default:
				{
					cout << "��������������ѡ��" << endl;
					system("pause");
					system("cls");//����
					break;
				}
				}
			}
			else
			{
				cout << "�����ڸ��˻���" << endl;
				break;
			}

			//�޸ĺõ�����������ļ�
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
			//���Ĺ���Ա�˻���Ϣ(�޸��Լ����˻�)
			fs.open(ADMIN_FILE, ios::in | ios::out | ios::binary | ios::app);

			Administrator admin[3];
			int i = 0, j = 0;
			for (; i < 3; i++)
			{
				fs.read((char*)&admin[i], sizeof(admin[i]));  //���ļ���ȡ����Ա��Ϣ
				if (username == admin[i].username)
				{
					j = i;
					find = true;  //��ʾ���ҵ�
				}
				if (fs.eof())break;  //�����ļ�ĩβʱ�˳�
			}
			fs.close();

			if (find)
			{
				cout << "��������Ҫ���ĵ���Ϣ��" << endl;
				cout << "1������" << endl;
				cout << "0���˳�" << endl;

				int select;
				cin >> select;
				switch (select)
				{
				case 1:  //�޸�����
				{
					bool flag = false;
					while (!flag)
					{
						string pwd1, pwd2;
						cout << "�����룺";
						cin >> pwd1;
						cout << "ȷ�����룺";
						cin >> pwd2;
						if (pwd1 == pwd2)
						{
							password = admin[j].password = pwd1;
							flag = true;
							cout << "�����޸ĳɹ���" << endl;
						}
						else
						{
							cout << "�����������벻һ�£����������룡" << endl;
						}
					}
					break;
				}
				case 0:  //�˳�
				{
					cout << "\n���˳��޸Ľ���\n\n";
					system("pause");
					break;
				}
				default:
				{
					cout << "��������������ѡ��" << endl;
					system("pause");
					system("cls");//����
					break;
				}
				}
			}
			else
			{
				cout << "404 Not Found!" << endl;
			}

			//�޸ĺõ�����������ļ�
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
			cout << "��������������ѡ��" << endl;
		}
		cin >> select;
	}
	cout << endl;
}

//��ʼ������
void Administrator::initVector()
{
	//ȷ���������״̬
	vMem.clear();
	vCoa.clear();

	//��ȡ��Ϣ   ��Ա
	ifstream ifs;
	ifs.open(MEM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Member�ļ���ȡʧ��" << endl;
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

	//��ȡ��Ϣ   ����
	ifs.open(COA_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "Coach�ļ���ȡʧ��" << endl;
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