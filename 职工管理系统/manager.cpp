#include"manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_postId = did;
}

void Manager::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ������:" << this->m_Name
		<< "\tְ����λ��" << this->getPostName()
		<< "\t��λְ��:����ϰ彻�������񣬲��·��������ͨԱ��" << endl;
}
string Manager::getPostName()
{
	return string("����");
}