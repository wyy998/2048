#include <iostream>
#include "list_2048.h"
using namespace std;

int main()
{
	cout << "==========��ӭʹ��N��2048��Ϸ==========" << endl;
	cout << "ʹ��˵��:[w]  �����ƶ�" << endl;
	cout << "\t[s]  �����ƶ�" << endl;
	cout << "\t[a]  �����ƶ�" << endl;
	cout << "\t[d]  �����ƶ�" << endl;
	cout << "\t[e]  �˳�" << endl;
	cout << "���������[3-10]��ʼ��Ϸ:";
	int n,exit_value=0;
	cin >> n;
	list_2048 list =list_2048(n);
	while (1)
	{
		list.output();
		switch (cin.get())
		{
		case 'w':list.move_up(); break;
		case 's':list.move_down(); break;
		case 'a':list.move_left(); break;
		case 'd':list.move_right(); break;
		case 'e':exit_value = 1; break;
		default:break;
		}
		if (exit_value)
			break;
	}

	return 0;
}