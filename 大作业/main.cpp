#include<iostream>
#include"tcs.h"
#include"food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>
#include"frame.h" 
void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(hOut, pos);
}
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
int main()
{
	//����������
	srand((unsigned int)time(NULL));
	//�Ƿ������ı�ʶ
	bool died = false;
	char preKey = NULL;
	Frame Frame;
	Frame.initialFrame();
	Frame.createFrame();
	Food Food(Frame);
	Food.Foodset();
	tcs tcs(Frame,Food);
	tcs.initialsnake();
	gotoxy(hOut, 0, Frame::len);
	cout << "�÷֣�" << tcs.getScore() << "��" << endl;
	//gotoxy(hOut, 10, 5);//y*2 x 
	//�����û�������
	while (!died)
	{
		char key = _getch();
		//�ж�����ǵ�һ�ΰ��ˣ�������Ų��ܼ�����Ϸ
		//�ж���һ���ƶ�����
		if (preKey == NULL&&key == tcs.left)
		{
			continue;
		}
		do
		{
			if (key == tcs.up || key == tcs.down || key == tcs.left || key == tcs.right)
			{
				//�жϱ��ΰ����Ƿ����ϴγ�ͻ
				if ((key == tcs.left&&preKey == tcs.right )||
					(key == tcs.right&&preKey == tcs.left )||
					(key == tcs.up&&preKey == tcs.down) ||
					(key == tcs.down&&preKey == tcs.up) 
					)
				{
					key = preKey;
				}
				else
				{
					preKey = key;//���ǳ�ͻ���������Ը��°���
			    }
				if (tcs.move(key) == true)
				{
					//�ƶ��ɹ�
					gotoxy(hOut, 0, Frame::len);
					cout << "�÷֣�" << tcs.getScore() << "��" << endl;
					Sleep(tcs.getsleeptime());
				}
				else
				{
					died = true;
					break;
				}
			}
			else
			{
				key = preKey;//ǿ�ƽ����󰴼���Ϊ��һ���ƶ��ķ���
			}
		} while (!_kbhit());//��û�м��������ʱ�򷵻�0
	}
	return 0;
}
