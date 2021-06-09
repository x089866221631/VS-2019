#include"WorkerManager.h"
int main()
{
	
	WorkerManager wm;
	int select;
	
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入你的选择：" ;
		cin >> select;
		switch (select)
		{
		case 0://退出职工系统
			wm.ExitSystem();
				break;
		case 1://添加职工系统
			wm.Add_Emp();
			break;
		case 2://显示职工系统
			wm.Show_Emp();
			break;
		case 3://删除特定职工
			wm.Del_Emp();
			break;
		case 4://修改职工信息
			wm.Mod_Emp();
			break;
		case 5://查找职工信息
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文件
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}

	}
	system("pause");
	return 0;
}