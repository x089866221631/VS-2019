#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
//ְ���������
class Worker
{
public:

	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;

	//��ȡ��λ����
	virtual string getPostName() = 0;

	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_postId;//ְ�����ڲ������Ʊ��
};