#ifndef FRAME_H_
#define FRAME_H_
#include<iostream>
using namespace std;
class Frame
{
public:
	enum
	{
		len=250,
		wid=250
	};
	void initialFrame();//��ʼ���߽� 
	void createFrame();//�����߽� 
	void setFrame(int x,int y,char c);//����ƽ������ϵ
	char location(int x,int y);//�õ�λ����Ϣ
private:
    char array[len][wid]; 
};
#endif

