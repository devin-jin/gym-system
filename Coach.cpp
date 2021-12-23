#include"Coach.h"

//Ĭ�Ϲ���
Coach::Coach() 
{
	username = "";
	password = "";
	name = "";
	for (int i = 0; i < 10; i++) { CouId[i] = 0; }
}

 //�вι���
Coach::Coach(string un, string pwd)
{
	//��ʼ��������Ϣ
	this->username = un;
	this->password = pwd;

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
void Coach::openMenu()
{
	cout << "��ӭ������" << this->name << "��¼" << endl;
	cout << "\t\t-------------------------------\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          1.�鿴��Ϣ         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          2.�޸���Ϣ         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t|          3.�鿴�γ�         |\n";
	cout << "\t\t|                             |\n";
	cout << "\t\t-------------------------------\n";
	cout << "����������ѡ��";
}

//�鿴��Ϣ
void Coach::printCoach()
{
	cout << "�û�����ID����" << username << endl
		<< "���룺" << password << endl
		<< "������" << name << endl
		<< "�γ�ID��";
	for (int i = 0; i < 10 && CouId[i] != 0; i++)
	{
		cout << CouId[i] << " ";
	}
	cout << endl;
}

//�޸���Ϣ
void Coach::change()
{
	fstream fs;
	bool find = false;  //�߼��ж��Ƿ��ҵ�
	fs.open(COA_FILE, ios::in | ios::out | ios::binary | ios::app);

	Coach coa[10];
	int i = 0, j = 0;
	for (; i < 10; i++)
	{
		fs.read((char*)&coa[i], sizeof(coa[i]));  //���ļ���ȡ������Ϣ
		if (username == coa[i].username)
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
		cout << "2������" << endl;
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
					password = coa[j].password = pwd1;
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
			name = coa[j].name = n;
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
		cout << "404 Not Found!" << endl;
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

//�鿴�γ�
void Coach::showCourse()
{

}