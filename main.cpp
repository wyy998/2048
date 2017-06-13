#include <iostream>
#include "list_2048.h"
using namespace std;

int main()
{
	cout << "==========欢迎使用N阶2048游戏==========" << endl;
	cout << "使用说明:[w]  向上移动" << endl;
	cout << "\t[s]  向下移动" << endl;
	cout << "\t[a]  向左移动" << endl;
	cout << "\t[d]  向右移动" << endl;
	cout << "\t[e]  退出" << endl;
	cout << "请输入阶数[3-10]开始游戏:";
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