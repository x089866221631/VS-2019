#pragma once
#include"WorkerManager.h"
#include"Worker.h"
using namespace std;
class WorkerManager
{
public:
	WorkerManager();
	
	//显示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;
	
	//职工数组指针
	Worker** m_EmpArray;

	bool m_FileIsEmpty;

	//添加职工
	void Add_Emp();

	//保存员工
	void Save();

	//统计人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在 如果存在返回职工所在数组中的位置，不存在返回-1
	int IsExist(int id);

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空数据
	void Clean_File();


	~WorkerManager();
};
