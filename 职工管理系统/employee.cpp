#include"employee.h"
	//���캯��
Employee::Employee(int id, string name ,int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_postId = did;
	
}
//��ʾ������Ϣ
void Employee::ShowInfo()
{
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ������:" << this->m_Name
		<< "\tְ����λ��" << this->getPostName()
		<< "\t��λְ����ɾ�����������" << endl;
}
//��ȡ��λ����
string Employee::getPostName()
{
	return string("Ա��");
}

