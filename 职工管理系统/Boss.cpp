#include"Boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_postId = did;
}
void Boss:: ShowInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名" << this->m_Name
		<< "\t职工岗位：" << this->getPostName()
		<< "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::getPostName()
{
	return string("总裁");
}