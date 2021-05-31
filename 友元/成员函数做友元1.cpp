#include<iostream>
using namespace std;
#include<string>
class  Building;

class Goodguys
{
public:
	Goodguys();
	void visit();//允许访问
	void visit_other();//不允许访问

	Building* building;
};
class Building
{
	friend void Goodguys::visit();//成员函数访问
public:
	Building()
	{

	}
public:

	string m_SittingRoom = "客厅";
private:

	string m_BedRoom = "卧室";
};

//类外实现成员函数


Goodguys::Goodguys()
{
	building = new Building;
}

void Goodguys::visit()
{
	cout << "visit 正在访问：" << building->m_SittingRoom << endl;

	cout << "visit 正在访问：" << building->m_BedRoom << endl;
}
void Goodguys::visit_other()
{
	cout << "visit other正在访问：" << building->m_SittingRoom << endl;

	//cout << "visit 正在访问：" << building->m_BedRoom << endl;
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
