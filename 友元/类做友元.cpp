//#include<iostream>
//using namespace std;
//#include<string>

//class Building
//{
//	friend class GoodGuys;
//public:
//	Building();
//
//public:
//	string m_SittingRoom;
//private:
//	string m_BedRoom;
//};
//class GoodGuys
//{
//public:
//	GoodGuys();
//	void visit();//参观函数 用于访问Building中的属性
//
//	Building* building;
//};
//
////类外写成员函数
//Building::Building()
//{
//	m_BedRoom = "卧室";
//	m_SittingRoom = "客厅";
//}
//
//GoodGuys::GoodGuys()
//{
//	//创建建筑物对象
//	building = new Building;
//}
//
//void GoodGuys::visit()
//{
//	cout << "好朋友正在访问：" << building->m_SittingRoom << endl;
//	cout << "好朋友正在访问：" << building->m_BedRoom << endl;
//
//}
//
//void test01()
//{
//	GoodGuys gg;
//	gg.visit();
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}
//


