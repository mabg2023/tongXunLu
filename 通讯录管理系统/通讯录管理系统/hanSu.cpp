#include"hanSu.h"

//��װ������ʾ�ý��� ��void showMenu()
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}


//1�������ϵ��
void addPersion(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->persionArray[abs->m_Size].m_Name = name;

		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;

		while (true)
		{
			//���������� 1 �� 2 ������˳�ѭ��
			//��������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->persionArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�����������������룡" << endl;
			}
		}


		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->persionArray[abs->m_Size].m_Age = age;

		//�绰
		string phone = "000000000";
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->persionArray[abs->m_Size].m_Phone = phone;

		//סַ
		string address = "00000000";
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->persionArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ���" << endl;

		system("pause");    //�밴���������
		system("cls");    //��������

	}
}


//2����ʾ������ϵ��
void showPersion(Addressbooks* abs)
{
	//�ж�ͨѶ¼�������Ԫ�ظ����Ƿ�Ϊ 0�����Ϊ 0�� ��ʾ��¼Ϊ��
	// �����Ϊ 0�� ����ʾ��ϵ����Ϣ
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->persionArray[i].m_Name << "\t";
			cout << "�Ա� " << (abs->persionArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺 " << abs->persionArray[i].m_Age << "\t";
			cout << "�绰�� " << abs->persionArray[i].m_Phone << "\t";
			cout << "סַ�� " << abs->persionArray[i].m_Addr << endl;
		}
	}
	system("pause");    //�밴���������
	system("cls");    //��������
}


//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������е�λ�ã������ڷ��� -1 
//���� 1   ͨѶ¼    ���� 2    �������
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�����û�����������Ƿ����
		if (abs->persionArray[i].m_Name == name)
		{
			return i;    //���ҵ���������λ��
		}
	}
	return -1;    //û�ҵ������� -1
}


//3��ɾ��ָ����ϵ��
void deletePersion(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	//ret = -1 δ�鵽
	//ret != -1 �鵽��
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//���ҵ�����ˣ�Ҫ����ɾ������
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->persionArray[i] = abs->persionArray[i + 1];
		}
		abs->m_Size--;    //����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}


//4��������ϵ��
void findPersion(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)    //�ҵ���ϵ��
	{
		cout << "��ѯ�ɹ��� " << endl;
		cout << "������ " << abs->persionArray[ret].m_Name << "\t";
		cout << "�Ա� " << (abs->persionArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺 " << abs->persionArray[ret].m_Age << "\t";
		cout << "�绰�� " << abs->persionArray[ret].m_Phone << "\t";
		cout << "סַ�� " << abs->persionArray[ret].m_Addr << endl;
	}
	else    //δ��ѯ��
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}


//5���޸���ϵ��
void modifyPersion(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)    //�ҵ���ϵ��
	{
		cout << "�޸ĺ���ϢΪ��" << endl;
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->persionArray[ret].m_Name = name;

		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;

		while (true)
		{
			//���������� 1 �� 2 ������˳�ѭ��
			//��������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->persionArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�����������������룡" << endl;
			}
		}


		//����
		int age = 0;
		cout << "���������䣺" << endl;
		cin >> age;
		abs->persionArray[ret].m_Age = age;

		//�绰
		string phone = "000000000";
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->persionArray[ret].m_Phone = phone;

		//סַ
		string address = "00000000";
		cout << "�������ͥסַ��" << endl;
		cin >> address;
		abs->persionArray[ret].m_Addr = address;
	}

	else    //δ��ѯ��
	{
		cout << "���޴��ˣ�" << endl;
	}

	system("pause");
	system("cls");
}


//6�������ϵ��
void cleanPersion(Addressbooks* abs)
{
	cout << "��ȷ���Ƿ�Ҫ���ͨѶ¼����1 --- �ǣ�2 --- ��" << endl;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		abs->m_Size = 0;
		cout << "ͨѶ¼����գ�" << endl;
		break;

	case 2:
		break;

	default:
		break;
	}

	system("pause");
	system("cls");
}