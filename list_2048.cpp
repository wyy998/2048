#include "list_2048.h"
#include <iostream>

list_2048::list_2048(int n)
{
	cc = n;
	for (int i = 0; i < cc; i++)
	{
		for (int j = 0; j < cc; j++)
		{
			num[i][j] = 0;
		}
	}
	_random();
}

list_2048::~list_2048()
{}

void list_2048::move_left()
{
	for (int i = 0; i < cc; i++)
	{
		_left(i);
	}
	_random();
}

void list_2048::move_right()
{
	for (int i = 0; i < cc; i++)
	{
		_right(i);
	}
	_random();
}

void list_2048::move_up()
{
	for (int i = 0; i < cc; i++)
	{
		_up(i);
	}
	_random();
}

void list_2048::move_down()
{
	for (int i = 0; i < cc; i++)
	{
		_down(i);
	}
	_random();
}

void list_2048::output()
{
	std::system("cls");
	for (int i = 0; i < cc; i++)
	{
		for (int j = 0; j < cc; j++)
		{
			std::cout << "\t" << num[i][j];
		}
		std::cout << std::endl;
	}
}

void list_2048::_left(int n)
{
	int tmp = 0, p = 0;
	for (int i = 0; i < cc - 1; i++)
	{
		if (num[n][i])
		{
			if (num[n][i] == tmp)
			{
				num[n][p++] = tmp * 2;
				tmp = 0;
			}
			else
			{
				if (tmp)
					num[n][p++] = tmp;
				tmp = num[n][i];
			}
		}
	}
	num[n][p++] = tmp;
	for (; p < cc - 1; p++)
		num[n][p] = 0;
}

void list_2048::_right(int n)
{
	int tmp = 0, p = cc - 1;
	for (int i = 0; i > 0; i--)
	{
		if (num[n][i])
		{
			if (num[n][i] == tmp)
			{
				num[n][p--] = tmp * 2;
				tmp = 0;
			}
			else
			{
				if (tmp)
					num[n][p--] = tmp;
				tmp = num[n][i];
			}
		}
	}
	num[n][p--] = tmp;
	for (; p > 0; p--)
		num[n][p] = 0;
}

void list_2048::_up(int n)
{
	int tmp = 0, p = 0;
	for (int i = 0; i < cc - 1; i++)
	{
		if (num[i][n])
		{
			if (num[i][n] == tmp)
			{
				num[p++][n] = tmp * 2;
				tmp = 0;
			}
			else
			{
				if (tmp)
					num[p++][n] = tmp;
				tmp = num[i][n];
			}
		}
	}
	num[p++][n] = tmp;
	for (; p < cc - 1; p++)
		num[p][n] = 0;
}

void list_2048::_down(int n)
{
	int tmp = 0, p = cc-1;
	for (int i = 0; i >0; i--)
	{
		if (num[i][n])
		{
			if (num[i][n] == tmp)
			{
				num[p--][n] = tmp * 2;
				tmp = 0;
			}
			else
			{
				if (tmp)
					num[p--][n] = tmp;
				tmp = num[i][n];
			}
		}
	}
	num[p--][n] = tmp;
	for (; p > 0; p--)
		num[p][n] = 0;
}

void list_2048::_random()
{
	int count = 0;
	for (int i = 0; i < cc - 1; i++)
	{
		for (int j = 0; j < cc - 1; j++)
		{
			if (!num[i][j])
				count++;
		}
	}
	count = cc*cc - count;
	int pos = rand() % count;
	count = 0;
	for (int i = 0; i < cc - 1; i++)
	{
		for (int j = 0; j < cc - 1; j++)
		{
			if (!num[i][j])
				count++;
			if (count == pos)
				num[i][j] = 2;
		}
	}
}