//#include<iostream>
//#include<ctime>
//using namespace std;
//struct node
//{
//	int num1;
//	int num2;
//	int tp;//cheng
//	int mistake;
//};
//int A_number(int&a,int&b,int&c,int&t, node spe[])//�����
//{
//	int a1=0, b1=0;
//	do
//	{
//		a1 = rand() % 50 ;
//		b1 = rand()%50 ;
//	} while (!(a1 + b1 >= 0 && a1 + b1 <= 50 && a1 - b1 >= 0 && a1 - b1 <= 50));//�������������ѭ��
//	spe[t].num1 = a = a1;
//	spe[t].num2 = b = b1;
//	spe[t].tp = c = rand() % 2;
//	return 0;
//}
//void score(int sum)//�����ܳɼ�
//{
//	cout << endl << endl;
//	cout << "�ܷ֣�" << sum << endl;
//	if (sum >= 90) cout << "SMART" << endl;
//	else if (sum >= 80 && sum < 90) cout << "GOOD" << endl;
//	else if (sum >= 70 && sum < 80) cout << "OK" << endl;
//	else if (sum < 70 && sum >= 60) cout << "PASS" << endl;
//	else cout << "TRY AGAIN" << endl;
//}
//void cheng(int p)
//{
//	if (p == 0)cout << "+";
//	if (p == 1)cout << "-";
//}
//int spdwg3(int m)//����ÿ���⣬ѧ����һ��������ȷ�𰸵�10�֣��ڶ���������ȷ�𰸵�7�֣�������������ȷ�𰸵�5�֣��Ĵ�û��
//{
//	if (m == 0)return 10;
//	if (m == 1)return 7;
//	if (m == 2)return 5;
//	if (m == 3)return 0;
//}
//int main()
//{
//	srand((unsigned)time(NULL));
//	 node spe[10+1];
//		cout << "Сѧ���꼶������" << endl;
//		int t = 1,cnt=0,sum=0,a,b,c,ans;
//		while (t <=10)
//		{
//			cnt = 0;
//			cout << "����" << endl;
//			A_number(a, b, c,t,spe);
//			while (cnt <3)//�������ѭ��
//			{
//				
//				if (c == 0)//�ӷ�
//				{
//					cout << a <<"+"<< b<<"=";
//					cin >> ans;
//					if (a + b == ans)
//					{
//						cout << "��ȷ" << endl;
//						break;
//					}
//					else
//					{
//						cnt++;
//						cout << "����" << endl;
//						if (cnt == 3)
//						{
//							cout << "���ǣ�" << a + b << endl;
//							break;
//						}
//					}
//				}
//				else if (c == 1)//����
//				{
//					cout << a << "-" << b<<"=";
//					cin >> ans;
//					if (a - b == ans)
//					{
//						cout << "��ȷ" << endl;
//						break;
//					}
//					else
//					{
//						cnt++;
//						cout << "����" << endl;
//						if (cnt == 3)
//						{
//							cout << "����" << a - b << endl;
//							break;
//						}
//					}
//				}
//			}
//			spe[t].mistake = cnt;//����󷵻صķ���
//			if (cnt == 0)sum += 10;
//			if (cnt == 1)sum += 7;
//			if (cnt == 2)sum += 5;
//			t++;
//			
//			cnt = 0;
//			cout << endl << endl;
//			cout << "-------------------------" << endl;
//		}
//		score(sum);//�ܷ�
//		for (int i = 1;i <=10;i++)
//		{
//			cout << "��" << i << "��" << spe[i].num1;
//			cheng(spe[i].tp);//���������ʾ
//			cout << spe[i].num2 << " =";
//			if (spe[i].tp == 0)//���ش�
//				cout << spe[i].num1 + spe[i].num2 << endl;
//			else if (spe[i].tp == 1)//���ش�
//				cout << spe[i].num1 - spe[i].num2 << endl;					
//			cout << "�����" << spe[i].mistake << "�Σ�����" << spdwg3(spe[i].mistake);
//			cout << "��" << endl << endl;
//			
//		}
//}
//
//



//#include<stdio.h>
//int fune(int a, int b);
//int main()
//{
//	int k = 4, m = 1, p;
//	p = fune(k, m);
//	printf("%d", p);
//	p = fune(k, m);
//	printf("%d\n", p);
//}
//int fune(int a, int b)
//{
//	int m = 0;int i = 2;
//	i += m + 1;
//	m = i + a + b;
//	return m;
//
//}

