#include"Boss.h"

Boss::Boss(int id, string name, int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_postId = did;
}
void Boss:: ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ������" << this->m_Name
		<< "\tְ����λ��" << this->getPostName()
		<< "\t��λְ�𣺹���˾��������" << endl;
}

string Boss::getPostName()
{
	return string("�ܲ�");
}