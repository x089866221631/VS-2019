#include"WorkerManager.h"
#include"Boss.h"
#include"employee.h"
#include"manager.h"
#include"Worker.h"
constexpr auto fileName = "Person.txt";
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(fileName, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//统计人数变量
		num++;
	}
	return num;
}
WorkerManager::WorkerManager()
{
	//1、文件不存在时
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//2、文件存在 数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		cout << "文件为空！" << endl;
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3、当文件存在，并且记录数据
	int num = this->get_EmpNum();
	cout << "当前职工人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//讲文件中的数据，存到数组中
	this->init_Emp();

	for (int i = 0;i < this->m_EmpNum;i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_Id
			<< "\t姓名：" << this->m_EmpArray[i]->m_Name
			<< "\t部门编号：" << this->m_EmpArray[i]->m_postId << endl;
	}
}
	
void WorkerManager::Show_Menu()
{
	cout << "***********************************" << endl;
	cout << "******* 欢迎来到职工管理系统！*****" << endl;
	cout << "********* 0.退出管理程序 **********" << endl;
	cout << "********* 1.增加职工信息 **********" << endl;
	cout << "********* 2.显示职工信息 **********" << endl;
	cout << "********* 3.删除职工信息 **********" << endl;
	cout << "********* 4.修改职工信息 **********" << endl;
	cout << "********* 5.查找职工信息 **********" << endl;
	cout << "********* 6.职工编号排序 **********" << endl;
	cout << "********* 7.清空所有文档 **********" << endl;
	cout << "***********************************" << endl;
	
}
//退出系统
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;

	int addNum = 0;//保存用户的输入数量

	cin >> addNum;
	if (addNum > 0)
	{
		//添加

		int newSize = this->m_EmpNum + addNum;//新空间大小=原来记录人数+新增的人数

		//开辟新空间
		Worker**newspace  = new Worker* [newSize];

		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0;i < addNum;i++)
		{
			int id = 0;//职工编号
			string name;//职工姓名；
			int pSelect;//部门选择
			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1、员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> pSelect;
			Worker* worker = NULL;
			switch (pSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;

			default:
				break;
			}
			system("cls");
			//将创建职工职责，保存到数组中
			newspace[this->m_EmpNum +i] = worker; 
		}
		//释放原有的空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newspace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//更新职工不为空标志
		this->m_FileIsEmpty = false;

		//添加出成功
		cout << "添加成功" << addNum << "名新职工" << endl;

		//保存数据到文件中
		this->Save();
	}
	else
	{
		cout << "数据有误" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(fileName, ios::out);//用输入的方式打开文件 --写文件

	//将每个人数据写入到文件中
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_postId << endl;
	}
	//关闭文件

	ofs.close();

}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(fileName, ios::in);

	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;

		if (did == 1)//普通职工
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else if (did == 3)
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "该文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0;i <m_EmpNum;i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}
int  WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			//找到职工
			index = i;

			break;
		}
	}
	return index;
}
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		int id = 0;
		//按照职工编号删除成员
		cout << "请输入想要删除职工的编号：";
			cin >> id;
			int index = this->IsExist(id);
			if (index != -1)//说明职工存在，并且要删除掉index返回的位置上的人员
			{
				for (int i = index;i < this->m_EmpNum - 1;i++)
				{
					//数据前移
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--;//更新数据中记录人员个数
				//数据同步更新到文件中
				cout << "删除成功" << endl;
				this->Save();

			}
			else
			{
				cout << "删除失败，为找到改员工" << endl;
			}

	}
	system("pause");
	system("cls");
}
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName;
			int dSelect = 0;
			cout << "查找到：" << id << "号职工，请重新输入新职工号:" ;	
			cin >> newId;cout << endl;
			cout << "请输入新名字:";cin >> newName;
			cout << endl;
			cout << "请输入岗位：" << endl;;
			cout << "1、员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
				worker = new Boss(newId, newName, dSelect);
			case 3:
				break;
			default:
				break;
			}
			//更新数据 到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << endl;
			//保存到文件中
			this->Save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		
		}
	}
}
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式:" << endl;
		cout << "1、按职工编号查" << endl;
		cout << "2、按职工姓名查找" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//按照编号查
			int id;
			cout << "请输入查找的职工编号：";
				cin >> id;

				int ret = IsExist(id);
				if (ret != -1)
				{
					//找到职工
					cout << "查找成功！该职工信息如下" << endl;
					this->m_EmpArray[ret]->ShowInfo();
				}
				else
				{
					cout << "查无此人" << endl;
				}

		}
		else if (select == 2)
		{
			//按照姓名查
			string name;
			cout << "请输入要查找的姓名：";
			cin >> name;
			//加入判断是否查到的标志

			bool flag = false;

			for (int i = 0;i < m_EmpNum;i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，职工信息如下：" << endl;
					
					flag = true;
					this->m_EmpArray[i]->ShowInfo();
				}
			}
			if (flag == false)
			{
				cout << "查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select;
		cin >> select;
		
		for (int i = 0;i < m_EmpNum;i++)
		{
			int MinOrMax = i;
			for (int j = i + 1;j < this->m_EmpNum;j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else if (select == 2)//降序
				{
					if (this->m_EmpArray[MinOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else
				{
					cout << "输入有误" << endl;
				}
			}
			//判断一开始认定 最大或最小值 是不是 计算的最小值或最大值，如果不是交换数据
			if (i != MinOrMax)
			{
				Worker* temp = this->m_EmpArray[i];

				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = temp;
			}
		}
		
	}
	//更新数据
	this->Save();
	this->Show_Emp();

}
void WorkerManager::Clean_File()
{
	cout << "1、确认清空？" << endl;
	cout << "2、返回" << endl;
	int select=0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs(fileName,ios::trunc);//删除文件后再重新创新
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个职工对象
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray = NULL;
				//删除堆区数组指针
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_EmpNum = 0;
				this->m_FileIsEmpty = true;
			}
			cout << "文件清除成功" << endl;
		}
		
	}
	else if(select==2)
	{
		return;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
	}
	delete[]this->m_EmpArray;
	this->m_EmpArray = NULL;
}