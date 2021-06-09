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
		//ͳ����������
		num++;
	}
	return num;
}
WorkerManager::WorkerManager()
{
	//1���ļ�������ʱ
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	
	//2���ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ�գ�" << endl;
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3�����ļ����ڣ����Ҽ�¼����
	int num = this->get_EmpNum();
	cout << "��ǰְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����ݣ��浽������
	this->init_Emp();

	for (int i = 0;i < this->m_EmpNum;i++)
	{
		cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id
			<< "\t������" << this->m_EmpArray[i]->m_Name
			<< "\t���ű�ţ�" << this->m_EmpArray[i]->m_postId << endl;
	}
}
	
void WorkerManager::Show_Menu()
{
	cout << "***********************************" << endl;
	cout << "******* ��ӭ����ְ������ϵͳ��*****" << endl;
	cout << "********* 0.�˳�������� **********" << endl;
	cout << "********* 1.����ְ����Ϣ **********" << endl;
	cout << "********* 2.��ʾְ����Ϣ **********" << endl;
	cout << "********* 3.ɾ��ְ����Ϣ **********" << endl;
	cout << "********* 4.�޸�ְ����Ϣ **********" << endl;
	cout << "********* 5.����ְ����Ϣ **********" << endl;
	cout << "********* 6.ְ��������� **********" << endl;
	cout << "********* 7.��������ĵ� **********" << endl;
	cout << "***********************************" << endl;
	
}
//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;

	int addNum = 0;//�����û�����������

	cin >> addNum;
	if (addNum > 0)
	{
		//���

		int newSize = this->m_EmpNum + addNum;//�¿ռ��С=ԭ����¼����+����������

		//�����¿ռ�
		Worker**newspace  = new Worker* [newSize];

		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				newspace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0;i < addNum;i++)
		{
			int id = 0;//ְ�����
			string name;//ְ��������
			int pSelect;//����ѡ��
			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1��Ա��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//������ְ��ְ�𣬱��浽������
			newspace[this->m_EmpNum +i] = worker; 
		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newspace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		//��ӳ��ɹ�
		cout << "��ӳɹ�" << addNum << "����ְ��" << endl;

		//�������ݵ��ļ���
		this->Save();
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(fileName, ios::out);//������ķ�ʽ���ļ� --д�ļ�

	//��ÿ��������д�뵽�ļ���
	for (int i = 0;i < this->m_EmpNum;i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_postId << endl;
	}
	//�ر��ļ�

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

		if (did == 1)//��ְͨ��
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
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "���ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0;i <m_EmpNum;i++)
		{
			//���ö�̬���ó���ӿ�
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
			//�ҵ�ְ��
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
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		int id = 0;
		//����ְ�����ɾ����Ա
		cout << "��������Ҫɾ��ְ���ı�ţ�";
			cin >> id;
			int index = this->IsExist(id);
			if (index != -1)//˵��ְ�����ڣ�����Ҫɾ����index���ص�λ���ϵ���Ա
			{
				for (int i = index;i < this->m_EmpNum - 1;i++)
				{
					//����ǰ��
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--;//���������м�¼��Ա����
				//����ͬ�����µ��ļ���
				cout << "ɾ���ɹ�" << endl;
				this->Save();

			}
			else
			{
				cout << "ɾ��ʧ�ܣ�Ϊ�ҵ���Ա��" << endl;
			}

	}
	system("pause");
	system("cls");
}
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName;
			int dSelect = 0;
			cout << "���ҵ���" << id << "��ְ����������������ְ����:" ;	
			cin >> newId;cout << endl;
			cout << "������������:";cin >> newName;
			cout << endl;
			cout << "�������λ��" << endl;;
			cout << "1��Ա��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//�������� ��������
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			//���浽�ļ���
			this->Save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		
		}
	}
}
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ:" << endl;
		cout << "1����ְ����Ų�" << endl;
		cout << "2����ְ����������" << endl;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//���ձ�Ų�
			int id;
			cout << "��������ҵ�ְ����ţ�";
				cin >> id;

				int ret = IsExist(id);
				if (ret != -1)
				{
					//�ҵ�ְ��
					cout << "���ҳɹ�����ְ����Ϣ����" << endl;
					this->m_EmpArray[ret]->ShowInfo();
				}
				else
				{
					cout << "���޴���" << endl;
				}

		}
		else if (select == 2)
		{
			//����������
			string name;
			cout << "������Ҫ���ҵ�������";
			cin >> name;
			//�����ж��Ƿ�鵽�ı�־

			bool flag = false;

			for (int i = 0;i < m_EmpNum;i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ����Ϣ���£�" << endl;
					
					flag = true;
					this->m_EmpArray[i]->ShowInfo();
				}
			}
			if (flag == false)
			{
				cout << "���޴���" << endl;
			}
		}
		else
		{
			cout << "��������" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

		int select;
		cin >> select;
		
		for (int i = 0;i < m_EmpNum;i++)
		{
			int MinOrMax = i;
			for (int j = i + 1;j < this->m_EmpNum;j++)
			{
				if (select == 1)//����
				{
					if (this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else if (select == 2)//����
				{
					if (this->m_EmpArray[MinOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						MinOrMax = j;
					}
				}
				else
				{
					cout << "��������" << endl;
				}
			}
			//�ж�һ��ʼ�϶� ������Сֵ �ǲ��� �������Сֵ�����ֵ��������ǽ�������
			if (i != MinOrMax)
			{
				Worker* temp = this->m_EmpArray[i];

				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = temp;
			}
		}
		
	}
	//��������
	this->Save();
	this->Show_Emp();

}
void WorkerManager::Clean_File()
{
	cout << "1��ȷ����գ�" << endl;
	cout << "2������" << endl;
	int select=0;
	cin >> select;
	if (select == 1)
	{
		//����ļ�
		ofstream ofs(fileName,ios::trunc);//ɾ���ļ��������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0;i < this->m_EmpNum;i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray = NULL;
				//ɾ����������ָ��
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_EmpNum = 0;
				this->m_FileIsEmpty = true;
			}
			cout << "�ļ�����ɹ�" << endl;
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