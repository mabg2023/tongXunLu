#include <iostream>
#include <string>
#include"hanSu.h"
using namespace std;

//在main函数中调用封装好的函数
int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中的当前人员个数
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:    //1、添加联系人
			addPersion(&abs);    //利用地址传递，可以修饰实参
			break;

		case 2:    //2、显示联系人
			showPersion(&abs);
			break;

		case 3:    //3、删除联系人
		{
			/*cout << "请输出需要删除的联系人姓名：" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "查无此人！" << endl;
			}
			else
			{
				cout << "找到此人！" << endl;
			}*/
			deletePersion(&abs);
			break;
		}
			
		case 4:    //4、查找联系人
			findPersion(&abs);
			break;

		case 5:    //5、修改联系人
			modifyPersion(&abs);
			break;

		case 6:    //6、清空联系人
			cleanPersion(&abs);
			break;

		case 0:    //0、退出通讯录
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;

		default:
			break;
		}
	}
}
