#include"food.h"
#include<Windows.h>
void gotoxy2(HANDLE hOut2, int x, int y)
{
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(hOut2, pos);
}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);
void Food::Foodset()
{
	while (true)
	{
		FoodX = rand() % (Frame::len - 2) + 1;
		FoodY = rand() % (Frame::wid - 2) + 1;
		//��������λ������ͷ���������������������
		if (Frame.location(FoodX, FoodY) == ' ')
		{
			Frame.setFrame(FoodX, FoodY, '#');
			gotoxy2(hOut2, FoodY * 2, FoodX);
			cout << '#';
			break;
		}
	}	
}
