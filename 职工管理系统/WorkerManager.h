#pragma once
#include"WorkerManager.h"
#include"Worker.h"
using namespace std;
class WorkerManager
{
public:
	WorkerManager();
	
	//��ʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;
	
	//ְ������ָ��
	Worker** m_EmpArray;

	bool m_FileIsEmpty;

	//���ְ��
	void Add_Emp();

	//����Ա��
	void Save();

	//ͳ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���� ������ڷ���ְ�����������е�λ�ã������ڷ���-1
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	//�������
	void Clean_File();


	~WorkerManager();
};
