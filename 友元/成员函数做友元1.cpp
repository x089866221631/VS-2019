#include<iostream>
using namespace std;
#include<string>
class  Building;

class Goodguys
{
public:
	Goodguys();
	void visit();//�������
	void visit_other();//���������

	Building* building;
};
class Building
{
	friend void Goodguys::visit();//��Ա��������
public:
	Building()
	{

	}
public:

	string m_SittingRoom = "����";
private:

	string m_BedRoom = "����";
};

//����ʵ�ֳ�Ա����


Goodguys::Goodguys()
{
	building = new Building;
}

void Goodguys::visit()
{
	cout << "visit ���ڷ��ʣ�" << building->m_SittingRoom << endl;

	cout << "visit ���ڷ��ʣ�" << building->m_BedRoom << endl;
}
void Goodguys::visit_other()
{
	cout << "visit other���ڷ��ʣ�" << building->m_SittingRoom << endl;

	//cout << "visit ���ڷ��ʣ�" << building->m_BedRoom << endl;
}
void test01()
{
	Goodguys gg;
	gg.visit();
	gg.visit_other();
}
int main()
{
	test01();
	system("pause");
	return 0;
}
