//#include<iostream>
//using namespace std;
//#include<string>
////建筑物类
//class Building
//{
//	//Goodguys全局函数是 Building 的好朋友，可以访问Building中私有成员
//	friend void Goodguys(Building* building);
//public:
//	Building()
//	{
//		m_SittingRoom = "客厅";
//		m_BedRoom = "卧室";
//	}
//public:
//	string m_SittingRoom;//客厅
//private:
//	string m_BedRoom;//卧室
//};
////全局函数
//void Goodguys(Building *building)
//{
//	cout << "好朋友全局函数 正在访问：" << building->m_SittingRoom << endl;
//	cout << "好便宜全局函数 正在访问：" << building->m_BedRoom << endl;
//
//}
//void test01()
//{
//	Building building;
//	Goodguys(&building);
//
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}