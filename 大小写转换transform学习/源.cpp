//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//    std::string str = "Hello, World!";
//    cout << str << endl;
//
//    // toupper
//    std::string strUpper(str.length(), ' ');
//    std::transform(str.begin(), str.end(), strUpper.begin(), std::toupper);
//    cout << strUpper << endl;
//
//    // tolower
//    std::transform(str.begin(), str.end(), str.begin(), std::tolower);
//    cout << strUpper << endl;
//
//    system("pause");
//    return 0;
//}
//
//

//#include<iostream>
//#include<cctype>
//#include<algorithm>
//#include<string>
//using namespace std;
//int main()
//{
//	string str = "System Command";
//	cout << str << endl;
//	string strUpper(str.length(), ' ');
//	transform(str.begin(), str.end(), strUpper.begin(), toupper);
//	cout << strUpper << endl;
//	transform(str.begin(), str.end(), strUpper.begin(), tolower);
//	cout << strUpper << endl;
//}

//#include<iostream>
//#include<string>
//#include<cctype>
//#include<algorithm>
//using namespace std;
//int main() 
//{
//	string str = "System Command";
//		cout << str << endl;
//		string strUpper(str.length(), ' ');
//		transform(str.begin(), str.end(), strUpper.begin(), toupper);
//			cout << strUpper << endl;
//			transform(str.begin(), str.end(), strUpper.begin(), tolower);
//			cout << strUpper << endl;
//
//}


//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//int main()
//{
//	string str = "ljkfjnjlkasbsjkdf";
//	string strUpper(str.length(), ' ');
//		cout << str << endl;
//		transform(str.begin(), str.end(), strUpper.begin(), toupper);
//			cout << strUpper << endl;
//			transform(str.begin(), str.end(), strUpper.begin(), tolower);
//			cout << strUpper << endl;
//}

//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//int main()
//{
//	string str = "System Command";
//	string strUpper(str.length(), ' ');
//		cout << str << endl;
//		transform(str.begin(), str.end(), strUpper.begin(), toupper);
//		cout << strUpper << endl;
//		transform(str.begin(), str.end(), strUpper.begin(), tolower);
//		cout << strUpper << endl;
//}

#include <stdio.h>
#include<iostream>
using namespace std;
int fibonaci(int i)
{
    if (i == 0)
    {
        return 0;
    }
    if (i == 1)
    {
        return 1;
    }
    return fibonaci(i - 1) + fibonaci(i - 2);
}

int  main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        cout<<fibonaci(i)<<"\n";
    }
    return 0;
}