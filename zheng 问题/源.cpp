//#include<iostream>
//using namespace std;
//static int e_nUserNnm;
//void InviteUser(int nDay)
//{
//	for (int i = 0;i <nDay;i++)
//	{
//		if (i >7)
//		{
//			int nTmpDay = (i - 7) % 3;
//			if (nTmpDay == 0)
//			{
//				e_nUserNnm++;                                                                                                            
//				InviteUser(nDay - i);
//				continue;
//			}
//		}
//		if (i == 7)
//		{
//			e_nUserNnm++;
//			InviteUser(nDay - i);
//		}
//	}
//}
//void main()
//{
//	
//	e_nUserNnm = 1;//初始化用户数量
//	int nlnput = 0;
//	cout << "输入天数" << endl;
//	cin >> nlnput;
//	InviteUser(nlnput);//第一个用户
//	cout << "共有" << e_nUserNnm << "个用户。" << endl;
//}
//
//


#include<iostream>
using namespace std;
static int e_InviteUser=1;
void InviteUser(int nDay)
{
	for (int i = 0;i < nDay;i++)
	{
		if (i > 7)
		{
			int nTDay = (i - 7) % 3;
			if (nTDay == 0)
			{
				e_InviteUser++;
				InviteUser(nDay - i);
				continue;
			}
		}
		if (i == 7)
		{
			e_InviteUser++;
			InviteUser(nDay - i);
		}
		
	}
}
void main()
{
	int nday=0;
	cin >> nday;
	InviteUser(nday);
	cout << e_InviteUser << endl;
}