#include <graphics.h>
#include <conio.h>

void main()
{
	initgraph(640, 480);
	
	int x = 320;
	
	// ����ʼͼ��
	setlinecolor(YELLOW);
	setfillcolor(GREEN);
	fillcircle(x, 240, 20);
	
	char c;
	while(c != 27)
	{
		// ��ȡ����
		c = getch();
		
		// �Ȳ����ϴ���ʾ�ľ�ͼ��
		setlinecolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, 240, 20);
		
		// �������룬�����µ�����
		switch(c)
		{
			case 'a': x-=2; break;
			case 'd': x+=2; break;
			case 27: break;
		}
		
		// �����µ�ͼ��
		setlinecolor(YELLOW);
		setfillcolor(GREEN);
		fillcircle(x, 240, 20);
		
		// ��ʱ
		Sleep(10);
	}
	
	closegraph();
}