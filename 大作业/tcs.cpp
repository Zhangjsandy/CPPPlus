#include"tcs.h"
#include<iostream>
#include<Windows.h>
#include"frame.h"
using namespace std;
void gotoxy1(HANDLE hOut1, int x, int y)
{
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(hOut1, pos);
}
HANDLE hOut1 = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
tcs::tcs(Frame &tempFrame,Food& tempFood) : Frame(tempFrame), Food(tempFood)
{
	pHead = NULL;
	isRool = false;
}
void tcs::destroypoint()
{
	Point * pCur = pHead;
	while (pHead!=NULL)
	{
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
}

void tcs::addpoint(int x, int y)
{
	//�����½��
	Point * newpoint = new Point;
	newpoint->x = x;
	newpoint->y = y;
	newpoint->next = NULL;
	//���ԭ��ͷ��Ϊ�գ���Ϊ����
	if (pHead != NULL)
	{
		Frame.setFrame(pHead->x, pHead->y, '=');
		gotoxy1(hOut1, pHead->y * 2, pHead->x);
		cout << "=";
	}
	newpoint->next = pHead;
	pHead = newpoint;//����ͷ��
	Frame.setFrame(pHead->x, pHead->y, '0');
	gotoxy1(hOut1, pHead->y * 2, pHead->x);
	cout << "0";

}
void tcs::initialsnake()
{
	destroypoint();
	addpoint(5, 3);
	addpoint(5, 4);
	addpoint(5, 5);
}
//�ƶ�ʱɾ�����
void tcs::delpoint()
{
	//�������Ͻ�� ��ȥ��ɾ������
	if (pHead == NULL || pHead->next == NULL)
	{
		return;
	}
	//��ǰ���
	Point *pCur = pHead->next;
	//��һ�����
	Point *pPre = pHead;
	while (pCur->next!=NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	//ɾ��β���
	Frame.setFrame(pCur->x, pCur->y, ' ');
	gotoxy1(hOut1, pCur->y * 2, pCur->x);
	cout << " ";
	delete pCur;
	pCur = NULL;
	pPre->next = NULL;
}
bool tcs::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;
	switch (key)
	{
	case up:
		x--;
		break;
	case down:
		x++;
		break;
	case left:
		y--;
		break;
	case right:
		y++;
		break;
	default:
		break;
	}
	//�ж� �����һ����������β�ͣ���Ӧ������
	Point *pCur = pHead->next;
	//��һ�����
	Point *pPre = pHead;
	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (pCur->x == x&&pCur->y == y)
	{
		//����β�͵�ѭ��
		isRool = true;
	}
	else
	{
		//�ж��û�Ҫ�����λ���Ƿ�ɹ�
		if (Frame.location(x, y) == '*' || Frame.location(x, y) == '=')
		{
			addpoint(x, y);
			delpoint();
			system("cls");
			Frame.createFrame();
			cout << "�÷֣�" << getScore() << "��" << endl;
			cout << "GAME OVER" << endl;
			return false;
		}
	}
	//�ƶ��ɹ� ������
	//�Ե�ʳ�δ�Ե�ʳ��
	if (Frame.location(x, y) == '#')
	{
		addpoint(x, y);
		//��������ʳ��
		Food.Foodset();
	}
	else
	{
		addpoint(x, y);
		delpoint();
		if (isRool == true)
		{
			Frame.setFrame(x, y, '0');
			gotoxy1(hOut1, y * 2, x);
			cout << "0";
		}
	}
	return true;
}
int tcs::getsleeptime()
{
	int sleeptime=0;
	int size = countlist();
	if (size < 5)
	{
		sleeptime = 300;
	}
	else if (size >= 5 && size <= 10)
	{
		sleeptime = 200;
	}
	else
	{
		sleeptime = 100;
	}
	return sleeptime;
}
int tcs::countlist()
{
	int size = 0;
	Point * curPoint = pHead;
	while (curPoint!=NULL)
	{
		size++;
		curPoint = curPoint->next;
	}
	return size;
}
int tcs::getScore()
{
	int size = countlist();
	int score = (size-3) * 100;
	return score;
}
