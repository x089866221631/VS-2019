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
//	e_nUserNnm = 1;//��ʼ���û�����
//	int nlnput = 0;
//	cout << "��������" << endl;
//	cin >> nlnput;
//	InviteUser(nlnput);//��һ���û�
//	cout << "����" << e_nUserNnm << "���û���" << endl;
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