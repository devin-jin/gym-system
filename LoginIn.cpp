#include<iostream>
using namespace std;
#include "Identity.h"
#include<fstream>
#include<string>
#include "globalFile.h"
#include "Member.h"
#include "Coach.h"
#include "Administrator.h"

//�����Ա�Ӳ˵�����
void MemberMenu(Identity*& member)
{
	while (true)
	{
		//���û�Ա�Ӳ˵�
		member->openMenu();

		Member* mem = (Member*)member;

		int select = 0;
		cin >> select; //�����û�ѡ��

		if (select == 1) //�鿴��Ϣ
		{
			mem->printMember();
		}
		else if (select == 2) //�޸���Ϣ
		{
			mem->change();
		}
		else if (select == 3) //�鿴�γ�
		{
			mem->showCourse();
		}
		else if (select == 4) //�γ̹���
		{
			mem->manageCourse();
		}
		else
		{
			//ע����¼
			delete member;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��������Ӳ˵�����
void CoachMenu(Identity*& coach)
{
	while (true)
	{
		//���ý����Ӳ˵�
		coach->openMenu();

		Coach* coa = (Coach*)coach;

		int select = 0; //�����û�ѡ��
		cin >> select;

		if (select == 1) //�鿴��Ϣ
		{
			coa->printCoach();
		}
		else if (select == 2) //�޸���Ϣ
		{
			coa->change();
		}
		else if (select == 3) //�鿴�γ�
		{
			coa->showCourse();
		}
		else
		{
			delete coach;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�Ӳ˵�����
void AdminMenu(Identity*& admin) 
{
	while (true) 
	{
		//���ù���Ա�Ӳ˵�
		admin->openMenu();

		Administrator* adm = (Administrator*)admin;

		int select = 0;
		cin >> select;

		if (select == 1)  //����˺�
		{
			adm->addPerson();
		}
		else if (select == 2)  //�鿴�˺�
		{
			adm->showPerson();
		}
		else if (select == 3)  //��ӿγ�
		{
			adm->addCourse();
		}
		else if (select == 4)  //�鿴�γ�
		{
			adm->showCourse();
		}
		else if (select == 5)  //��տγ�
		{
			adm->cleanCourse();
		}
		else if (select == 6)  //�޸���Ϣ
		{
			adm->change();
		}
		else 
		{
			delete admin;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//��¼����
void LoginIn(string fileName, int type)
{
	//����ָ�룬����ָ�����������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//�����û�����Ϣ
	string name;
	string pwd;
	if (type)
	{
		cout << "����������û�����" << endl;
		cin >> name;
		cout << "������������룺" << endl;
		cin >> pwd;
	}

	//��Ա��¼��֤
	if (type == 1) 
	{
		string fName;  //���ļ��л�ȡ���û���
		string fPwd;  //���ļ��л�ȡ����
		string fn;  //����
		int fscore;  //����
		int flevel;  //��Ա�ȼ�
		float fbalance;  //�˻����
		int fCouId[10];  //�γ̱��

		while (ifs >> fName && ifs >> fPwd && ifs >> fn && ifs >> fscore && ifs >> flevel
			&& ifs >> fbalance && ifs >> fCouId[0] && ifs >> fCouId[1] && ifs >> fCouId[2]
			&& ifs >> fCouId[3] && ifs >> fCouId[4] && ifs >> fCouId[5] && ifs >> fCouId[6]
			&& ifs >> fCouId[7] && ifs >> fCouId[8] && ifs >> fCouId[9])
		{	
			//���û��������Ϣ���Ա�
			if (name == fName && pwd == fPwd) 
			{
				cout << "��Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Member(name, pwd);

				//�����Ա�Ӳ˵�
				MemberMenu(person);
				return;
			}
		}
	}
	//������¼��֤
	else if (type == 2) 
	{
		string fName;  //���ļ��л�ȡ���û���
		string fPwd;  //���ļ��л�ȡ������
		string fn;  //���ļ��л�ȡ������
		int fCouId[10];  //���ļ��л�ȡ�Ŀγ̱��

		while (ifs >> fName && ifs >> fPwd && ifs >> fn && ifs >> fCouId[0]
			&& ifs >> fCouId[1] && ifs >> fCouId[2] && ifs >> fCouId[3] 
			&& ifs >> fCouId[4] && ifs >> fCouId[5] && ifs >> fCouId[6] 
			&& ifs >> fCouId[7]&& ifs >> fCouId[8] && ifs >> fCouId[9])
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "������֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Coach(name, pwd);

				//��������Ӳ˵�
				CoachMenu(person);
				return;
			}
		}
	}
	//����Ա��¼��֤
	else if (type == 3)
	{
		string fName;  //���ļ��л�ȡ�û���
		string fPwd;  //���ļ��л�ȡ����
		int fId;  //���ļ��л�ȡ����ԱID

		while (ifs >> fName && ifs >> fPwd && ifs >> fId)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");

				person = new Administrator(name, pwd);

				//�������Ա�Ӳ˵�ҳ��
				AdminMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ��!" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0;  //ѡ��
	while (true)
	{
		cout << "================ ��ӭ������������ϵͳ ================" << endl;
		cout << endl << "������������ݣ�" << endl;
		cout << "\t\t--------------------------------\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          1.��    Ա          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          2.��    ��          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          3.�� �� Ա          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t|          0.��    ��          |\n";
		cout << "\t\t|                              |\n";
		cout << "\t\t--------------------------------\n";
		cout << "����������ѡ��";
		cin >> select;

		switch (select)
		{
		case 1:
			LoginIn(MEM_FILE, 1);
			break;//��Ա���
		case 2:
			LoginIn(COA_FILE, 2);
			break;//�������
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;//����Ա���
		case 0:  //�˳�ϵͳ
			cout << "\n��ӭ��һ��ʹ��\n\n";
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");  //����
			break;
		}
	}
	system("pause");
	return 0;
}