//#include<iostream>
//#include<math.h>
//using namespace std;
//int main()
//{
//	int n = 500001;
//	double i = 1;
//	double sum = 0;
//	while (i <= n)
//	{
//		sum = sum + 1 / (4 * i - 3) - 1 / (4 * i - 1);
//		i++;
//	}
//	cout << sum * 4 << endl;
//}



#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double sum = 0;
	double i = 1.0;
	while (i < pow(10, 6))
	{
		sum += 1 / (4 * i - 3) - 1 / (4 * i - 1);
			i++;
	}cout << 4 * sum << endl;
}