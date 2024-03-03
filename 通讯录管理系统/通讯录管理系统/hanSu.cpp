#include"hanSu.h"

//封装函数显示该界面 如void showMenu()
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}


//1、添加联系人
void addPersion(Addressbooks* abs)
{
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->persionArray[abs->m_Size].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;

		while (true)
		{
			//如果输入的是 1 或 2 则可以退出循环
			//输入有误则需重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->persionArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入！" << endl;
			}
		}


		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->persionArray[abs->m_Size].m_Age = age;

		//电话
		string phone = "000000000";
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->persionArray[abs->m_Size].m_Phone = phone;

		//住址
		string address = "00000000";
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->persionArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功！" << endl;

		system("pause");    //请按任意键继续
		system("cls");    //清屏操作

	}
}


//2、显示所有联系人
void showPersion(Addressbooks* abs)
{
	//判断通讯录数组里的元素个数是否为 0，如果为 0， 提示记录为空
	// 如果不为 0， 则显示联系人信息
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->persionArray[i].m_Name << "\t";
			cout << "性别： " << (abs->persionArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄： " << abs->persionArray[i].m_Age << "\t";
			cout << "电话： " << abs->persionArray[i].m_Phone << "\t";
			cout << "住址： " << abs->persionArray[i].m_Addr << endl;
		}
	}
	system("pause");    //请按任意键继续
	system("cls");    //清屏操作
}


//检测联系人是否存在，如果存在，返回联系人所在数组中的位置，不存在返回 -1 
//参数 1   通讯录    参数 2    检测姓名
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//查找用户输入的姓名是否存在
		if (abs->persionArray[i].m_Name == name)
		{
			return i;    //查找到返回所在位置
		}
	}
	return -1;    //没找到，返回 -1
}


//3、删除指定联系人
void deletePersion(Addressbooks* abs)
{
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	//ret = -1 未查到
	//ret != -1 查到了
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//查找到这个人，要进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->persionArray[i] = abs->persionArray[i + 1];
		}
		abs->m_Size--;    //更新通讯录中的人员数
		cout << "删除成功！" << endl;
	}
	else
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}


//4、查找联系人
void findPersion(Addressbooks* abs)
{
	cout << "请输入你要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)    //找到联系人
	{
		cout << "查询成功！ " << endl;
		cout << "姓名： " << abs->persionArray[ret].m_Name << "\t";
		cout << "性别： " << (abs->persionArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->persionArray[ret].m_Age << "\t";
		cout << "电话： " << abs->persionArray[ret].m_Phone << "\t";
		cout << "住址： " << abs->persionArray[ret].m_Addr << endl;
	}
	else    //未查询到
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}


//5、修改联系人
void modifyPersion(Addressbooks* abs)
{
	cout << "请输入你要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)    //找到联系人
	{
		cout << "修改后信息为：" << endl;
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->persionArray[ret].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;

		while (true)
		{
			//如果输入的是 1 或 2 则可以退出循环
			//输入有误则需重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->persionArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入！" << endl;
			}
		}


		//年龄
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->persionArray[ret].m_Age = age;

		//电话
		string phone = "000000000";
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->persionArray[ret].m_Phone = phone;

		//住址
		string address = "00000000";
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->persionArray[ret].m_Addr = address;
	}

	else    //未查询到
	{
		cout << "查无此人！" << endl;
	}

	system("pause");
	system("cls");
}


//6、清空联系人
void cleanPersion(Addressbooks* abs)
{
	cout << "请确认是否要清空通讯录：（1 --- 是；2 --- 否）" << endl;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		abs->m_Size = 0;
		cout << "通讯录已清空！" << endl;
		break;

	case 2:
		break;

	default:
		break;
	}

	system("pause");
	system("cls");
}