#include <iostream>
#include <Windows.h>
using namespace std;

class color
{public:
	char white()
		{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//设置三色相加
		return 0;
		}
	char red()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);//设置红色
		return 0;
	}
	char green()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);//设置绿色
		return 0;
	}
	char blue()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);//设置蓝色
		return '\0';
	}
	char yellow()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |FOREGROUND_GREEN);	//设置黄色
		return 0;
	}
	char pink()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
			FOREGROUND_BLUE);//设置红色和蓝色相加
		return 0;
	}
	char indigo()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
			FOREGROUND_BLUE);//设置绿色和蓝色相加
		return 0;
	}
};