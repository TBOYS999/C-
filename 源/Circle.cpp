#include "Circle.h"
Circle::Circle(int x1, int y1, int r) :Spot(x1, y1)
{
	R = r;
}
void Circle::Coulor()
{
	int R, G, B;
	cout << "������ɫ��" << endl;
	cin >> R >> G >> B;
	setlinecolor(RGB(R, G, B));

}
void Circle::Drawn()
{
	cout << "����������x,y,�뾶r" << endl;
	cin >> x >> y >> R;


	while (1)
	{
		circle(x, y, R);
		FlushBatchDraw();
		if (GetAsyncKeyState(VK_UP))//�ϼ�
		{
			y -= 1;

		}
		if (GetAsyncKeyState(VK_DOWN))//�¼�
		{
			y += 1;

		}
		if (GetAsyncKeyState(VK_LEFT))//���
		{
			x -= 1;

		}
		if (GetAsyncKeyState(VK_RIGHT))//�Ҽ�
		{
			x += 1;

		}
		int key = _getch();
		if (key == 27)
		{
			break;
		}
		clearrectangle(x - R - 1 - D, y - 1 - R - D, x + R + 1 + D, y + R + D + 1);
	}
	while (true)
	{
		int key = _getch();
		if (key == 61)//��+=���Ŵ�
		{
			R += 5;
			clearrectangle(x - R - D, y - R - D, x + R + D, y + R + D);
		}
		else if (key == 45)//��-����������С
		{
			FlushBatchDraw();
			clearrectangle(x - R - D, y - R - D, x + R + D, y + R + D);
			R -= 5;
		}
		if (key == 27)//��esc���˳�
		{
			break;
		}
		circle(x, y, R);
	}
}
void Circle::fill()
{
	cout << "0���ޱ߿�1���б߿����" << endl;//ѡ�������ʽ
	int a;
	cin >> a;
	int key = _getch();
	switch (a)
	{
	case 0:
		int r, g, b;
		cout << "������ɫ��" << endl;
		cin >> r >> g >> b;
		setfillcolor(RGB(r, g, b));
		fillcircle(x, y, R);
		
		break;
	case 1:
		int a, c, d;
		cout << "������ɫ��" << endl;
		cin >> a >> c >> d;
		setfillcolor(RGB(a, c, d));
		solidcircle(x, y, R);
		
		break;


	}
}
void Circle::Delete()
{
	clearrectangle(x - R - 1 - D, y - 1 - R - D, x + R + 1 + D, y + R + D + 1);
}

