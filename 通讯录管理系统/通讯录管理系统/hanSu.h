#pragma once
#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

//��װ������ʾ�ý��� ��void showMenu()
void showMenu();


//�����ϵ�˽ṹ��
struct Persion
{
	//����
	string m_Name;
	//�Ա� 1.��  2.Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//��ͥסַ
	string m_Addr;
};


//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Persion persionArray[MAX];
	//ͨѶ¼�е�ǰ��¼����ϵ�˸���
	int m_Size;
};


//1�������ϵ��
void addPersion(Addressbooks* abs);



//2����ʾ������ϵ��
void showPersion(Addressbooks* abs);



//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������е�λ�ã������ڷ��� -1 
//���� 1   ͨѶ¼    ���� 2    �������
int isExist(Addressbooks* abs, string name);


//3��ɾ��ָ����ϵ��
void deletePersion(Addressbooks* abs);


//4��������ϵ��
void findPersion(Addressbooks* abs);



//5���޸���ϵ��
void modifyPersion(Addressbooks* abs);



//6�������ϵ��
void cleanPersion(Addressbooks* abs);

