#include "myRectangle.h"
myRectangle::myRectangle(int x1, int y1, int x2, int y2) :Spot(x1, y1), t(x2, y2)
{
}
void myRectangle::Coulor()
{
	int R, G, B;
	cout << "������ɫ��" << endl;
	cin >> R >> G >> B;
	setlinecolor(RGB(R, G, B));
}
void  myRectangle::Drawn()
{
	cout << "���������Ͻ�����x1,y1,���Ͻ�����x2,y2" << endl;
	cin >> x >> y >> t.x >> t.y;
	/*int c, d;
	cout << "��������Ҫѡ����ߵ����ࣺ0.ʵ�� 1��----- 2 ��....... 3:-.-.-.-.-�ʹ�ϸ��С" << endl;
	cin >> c >> d;
	setlinestyle(c, d);
	Coulor();*/
	while (1)
	{
		rectangle(x, y, t.x, t.y);
		FlushBatchDraw();
		if (GetAsyncKeyState(VK_UP))//�ϼ�
		{
			y -= 1;
			t.y -= 1;
		}
		if (GetAsyncKeyState(VK_DOWN))//�¼�
		{
			y += 1;
			t.y += 1;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			x -= 1;
			t.x -= 1;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			x += 1;
			t.x += 1;
		}
		int key = _getch();
		if (key == 27)
		{
			break;
		}
		clearrectangle(x - 1 - D, y - 1 - D, t.x + D + 1, t.y + D + 1);
	}
	while (true)
	{


		int key = _getche();
		if (key == 61)
		{
			x -= 5;
			y -= 5;
			t.x += 5;
			t.y += 5; clearrectangle(x - 1 - D, y - 1 - D, t.x + 1 + D, t.y + 1 + D);
		}
		else if (key == 45)
		{
			FlushBatchDraw();
			clearrectangle(x - 1 - D, y - 1 - D, t.x + 1 + D, t.y + 1 + D);
			x += 5;
			y += 5;
			t.x -= 5;
			t.y -= 5;

		}
		if (key == 27)
		{
			break;
		}rectangle(x, y, t.x, t.y);


	}
}
void  myRectangle::fill()
{
	cout << "0���ޱ߿�1���б߿����" << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 0:
		int r, g, b;
		cout << "������ɫ��" << endl;
		cin >> r >> g >> b;
		setfillcolor(RGB(r, g, b));
		fillrectangle(x, y, t.x, t.y);
		break;
	case 1:
		int R, G, B;
		cout << "������ɫ��" << endl;
		cin >> R >> G >> B;
		setfillcolor(RGB(R, G, B));
		solidrectangle(x, y, t.x, t.y);
		break;


	}
}
void  myRectangle::Delete()
{
	clearrectangle(x - 1 - D, y - 1 - D, t.x + D + 1, t.y + D + 1);
}


