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
//int A_number(int&a,int&b,int&c,int&t, node spe[])//随机数
//{
//	int a1=0, b1=0;
//	do
//	{
//		a1 = rand() % 50 ;
//		b1 = rand()%50 ;
//	} while (!(a1 + b1 >= 0 && a1 + b1 <= 50 && a1 - b1 >= 0 && a1 - b1 <= 50));//如果不是则跳出循环
//	spe[t].num1 = a = a1;
//	spe[t].num2 = b = b1;
//	spe[t].tp = c = rand() % 2;
//	return 0;
//}
//void score(int sum)//设置总成绩
//{
//	cout << endl << endl;
//	cout << "总分：" << sum << endl;
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
//int spdwg3(int m)//对于每道题，学生第一次输入正确答案得10分，第二次输入正确答案得7分，第三次输入正确答案得5分，四次没分
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
//		cout << "小学二年级测试题" << endl;
//		int t = 1,cnt=0,sum=0,a,b,c,ans;
//		while (t <=10)
//		{
//			cnt = 0;
//			cout << "提问" << endl;
//			A_number(a, b, c,t,spe);
//			while (cnt <3)//错误次数循环
//			{
//				
//				if (c == 0)//加法
//				{
//					cout << a <<"+"<< b<<"=";
//					cin >> ans;
//					if (a + b == ans)
//					{
//						cout << "正确" << endl;
//						break;
//					}
//					else
//					{
//						cnt++;
//						cout << "错误" << endl;
//						if (cnt == 3)
//						{
//							cout << "答案是：" << a + b << endl;
//							break;
//						}
//					}
//				}
//				else if (c == 1)//减法
//				{
//					cout << a << "-" << b<<"=";
//					cin >> ans;
//					if (a - b == ans)
//					{
//						cout << "正确" << endl;
//						break;
//					}
//					else
//					{
//						cnt++;
//						cout << "错误" << endl;
//						if (cnt == 3)
//						{
//							cout << "答案是" << a - b << endl;
//							break;
//						}
//					}
//				}
//			}
//			spe[t].mistake = cnt;//错误后返回的分数
//			if (cnt == 0)sum += 10;
//			if (cnt == 1)sum += 7;
//			if (cnt == 2)sum += 5;
//			t++;
//			
//			cnt = 0;
//			cout << endl << endl;
//			cout << "-------------------------" << endl;
//		}
//		score(sum);//总分
//		for (int i = 1;i <=10;i++)
//		{
//			cout << "第" << i << "题" << spe[i].num1;
//			cheng(spe[i].tp);//运算符号显示
//			cout << spe[i].num2 << " =";
//			if (spe[i].tp == 0)//返回答案
//				cout << spe[i].num1 + spe[i].num2 << endl;
//			else if (spe[i].tp == 1)//返回答案
//				cout << spe[i].num1 - spe[i].num2 << endl;					
//			cout << "你错了" << spe[i].mistake << "次，得了" << spdwg3(spe[i].mistake);
//			cout << "分" << endl << endl;
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

