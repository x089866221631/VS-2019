#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>
//职工抽象基类
class Worker
{
public:

	//显示个人信息
	virtual void ShowInfo() = 0;

	//获取岗位名称
	virtual string getPostName() = 0;

	int m_Id;//职工编号
	string m_Name;//职工姓名
	int m_postId;//职工所在部门名称编号
};