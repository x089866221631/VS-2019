//#include<algorithm>
//using namespace std;
//int main()
//{
//    int a[10] = { 10,11,12,13,14,15 };
//    reverse(a, a + 4);
//    for (int i = 0;i < 6;i++) {
//        printf("%d ", a[i]);
//    }
//    return 0;
//}
//#include<string>
//#include<algorithm>
//#include<iostream>
//using namespace std;
//int main()
//{
//    string str = "abcdefghi";
//    cout << str << endl;
//    reverse(str.begin() + 3, str.begin() + 6);
//    for (int i = 0;i < str.length();i++) {
//        printf("%c", str[i]);
//    }
//    return 0;
//}
//
//#include<iostream>
//#include<algorithm>
//#include<cctype>
//#include <vector>
//using namespace std;
//int main()
//{
//	vector<int>v1 = { 23,98,24,14,56,34,67 };
//
//	reverse(v1.begin() + 2, v1.begin() + 6);
//	for (int i = 0;i < 7;i++)
//	{
//		cout << v1[i] << " ";
//	}cout << endl;
//	
//}
////reverse(it,it2) ���Խ�����ָ����[it,it2)֮���Ԫ�ػ������ĵ�������[it,it2)��Χ�ڵ�Ԫ�ؽ��з�ת��
//#include<iostream>
//#include<algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//	vector<int>v1= {10, 20, 30, 40, 50, 60};
//	reverse(v1.begin() + 2, v1.begin() + 5);
//	for (int i = 0;i < 6;i++)
//	{
//		cout << v1[i] << " ";
//	}cout << endl;
//}
//next_permutation() ����һ��������ȫ�����е���һ������
//#include<stdio.h>
//#include<string>
//#include<algorithm>
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a[10] = { 1,2,3 };
//	do {
//		cout << a[0] << " " << a[1] << " " << a[2] << " \n";
//	} while (next_permutation(a, a + 3));
//	return 0;
//}

////fill() ���԰�����������е�ĳһ�����丳Ϊĳ����ͬ��ֵ����memset��ͬ������ĸ�ֵ����ʹ�������Ͷ�Ӧ��Χ�е�����ֵ
//#include<stdio.h>
//#include<string>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int a[10] = { 1,2,3,4,5 };
//    fill(a, a + 5, 233);
//    for (int i = 0;i < 5;i++) {
//        printf("%d ", a[i]);
//    }
//    return 0;
//}
//
//#include<vector>
//#include<algorithm>
//#include<iterator>
//#include<iostream>
//using namespace std;
//int main()
//{
//    int a[10] = { 1,2,2,3,3,3,5,5,5,5 };
//    printf("%d,%d\n", lower_bound(a, a + 10, 3) - a, upper_bound(a, a + 10, 3) - a);
//    cout<<abs(a[9]);//����ֵ
//    return 0;
//}

#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
void main()
{
	vector<int>v;
	for (int i = 0;i < 5;i++)
	
		v.push_back(i);

		reverse(v.begin(), v.end());
		for (int i = 0;i < v.size();i++)
		{
			cout << v[i] << ' ' ;
		}
	
}