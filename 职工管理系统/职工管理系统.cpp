#include"WorkerManager.h"
int main()
{
	
	WorkerManager wm;
	int select;
	
	while (true)
	{
		wm.Show_Menu();
		cout << "���������ѡ��" ;
		cin >> select;
		switch (select)
		{
		case 0://�˳�ְ��ϵͳ
			wm.ExitSystem();
				break;
		case 1://���ְ��ϵͳ
			wm.Add_Emp();
			break;
		case 2://��ʾְ��ϵͳ
			wm.Show_Emp();
			break;
		case 3://ɾ���ض�ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ����Ϣ
			wm.Mod_Emp();
			break;
		case 5://����ְ����Ϣ
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ļ�
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