#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_postId = did;
}

void Manager::ShowInfo()
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名:" << this->m_Name
		<< "\t职工岗位：" << this->getPostName()
		<< "\t岗位职责:完成老板交给的任务，并下发任务给普通员工" << endl;
}
string Manager::getPostName()
{
	return string("经理");
}