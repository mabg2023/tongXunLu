#include <iostream>
#include <string>
#include"hanSu.h"
using namespace std;

//��main�����е��÷�װ�õĺ���
int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�еĵ�ǰ��Ա����
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:    //1�������ϵ��
			addPersion(&abs);    //���õ�ַ���ݣ���������ʵ��
			break;

		case 2:    //2����ʾ��ϵ��
			showPersion(&abs);
			break;

		case 3:    //3��ɾ����ϵ��
		{
			/*cout << "�������Ҫɾ������ϵ��������" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "���޴��ˣ�" << endl;
			}
			else
			{
				cout << "�ҵ����ˣ�" << endl;
			}*/
			deletePersion(&abs);
			break;
		}
			
		case 4:    //4��������ϵ��
			findPersion(&abs);
			break;

		case 5:    //5���޸���ϵ��
			modifyPersion(&abs);
			break;

		case 6:    //6�������ϵ��
			cleanPersion(&abs);
			break;

		case 0:    //0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;

		default:
			break;
		}
	}
}
