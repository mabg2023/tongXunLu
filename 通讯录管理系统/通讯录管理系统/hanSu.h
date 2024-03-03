#pragma once
#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

//封装函数显示该界面 如void showMenu()
void showMenu();


//设计联系人结构体
struct Persion
{
	//姓名
	string m_Name;
	//性别 1.男  2.女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//家庭住址
	string m_Addr;
};


//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Persion persionArray[MAX];
	//通讯录中当前记录的联系人个数
	int m_Size;
};


//1、添加联系人
void addPersion(Addressbooks* abs);



//2、显示所有联系人
void showPersion(Addressbooks* abs);



//检测联系人是否存在，如果存在，返回联系人所在数组中的位置，不存在返回 -1 
//参数 1   通讯录    参数 2    检测姓名
int isExist(Addressbooks* abs, string name);


//3、删除指定联系人
void deletePersion(Addressbooks* abs);


//4、查找联系人
void findPersion(Addressbooks* abs);



//5、修改联系人
void modifyPersion(Addressbooks* abs);



//6、清空联系人
void cleanPersion(Addressbooks* abs);

