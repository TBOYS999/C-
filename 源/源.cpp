#include<iostream>
#include<graphics.h>
#include<fstream>
#include<conio.h>
#include<algorithm>
#include<iomanip>
#include <time.h>
#include <mmsystem.h>   
#include"button.h"
#include"Spot.h"
#include"Line.h"
#include"TwoLine.h"
#include"Circle.h"
#include"Polygon.h"
#include"myRectangle.h"
#include"myEllipse.h"
#pragma comment(lib,"Winmm.lib")//���þ�̬��
#define MAXSTAR 2000	// ��������
using namespace std;
int D;/*ʹ��˵�����û���Ĳ������̣�������һ��ʼ��ѡ���ߵ���ʽ��Ҳ���Բ�ѡ�񣬲�ѡ��Ĭ�Ϻ�ʵ�ߣ��û������
ʼλ��Ϊ150��50������ݻ����С������ͼ�����ڱ����������ޣ�ͼ�β������ص������ǿ��Ի���һ�𣬲�������ס
ԭ����һ�㲿�֣����㣬�ߣ�������Щ��������ͼ��ʱ����������Ϊ�����������꣬Ȼ������������ƶ����ƶ�����
�󣬼ǵð�esc���˳�������������Ҫ���������밴+=��- �������������Ҫ���мǣ���esc���˳����˳����������
ͼ�λ�����ѡ�����ȵȹ��ܣ����԰�����ʾ��ɣ�������������ò�������԰�backspaceɾ���������Ҫ���ƣ�
���ΪӢ��ģʽ��v����ɣ����ƺ��ͼ�ξ����ƶ����ܣ����๦�ܿ�����̽������л����ʹ��----���߳���*/
struct STAR
{
	double	x;
	int		y;
	double	step;
	int		color;
};

STAR star[MAXSTAR];

// ��ʼ������
void InitStar(int i)
{
	star[i].x = 0;
	star[i].y = rand() % 880;
	star[i].step = (rand() % 5000) / 1000.0 + 1;
	star[i].color = (int)(star[i].step * 255 / 6.0 + 0.5);	// �ٶ�Խ�죬��ɫԽ��
	star[i].color = RGB(star[i].color, star[i].color, star[i].color);
}

// �ƶ�����
void MoveStar(int i)
{
	// ����ԭ��������
	putpixel((int)star[i].x, star[i].y, 5);

	// ������λ��
	star[i].x += star[i].step;
	if (star[i].x > 1880)	InitStar(i);

	// ��������
	putpixel((int)star[i].x, star[i].y, YELLOW);
}

// ������
	int main()
	{
		srand((unsigned)time(NULL));	// �������
	initgraph(1880, 830);
	setbkmode(TRANSPARENT);// ������ͼ����
	TCHAR s0[50] = "�����ʼ����";
	button a;
	a.build(600, 350,200, 80, YELLOW, s0);
	a.drawbutton();
	ExMessage msg1;
	// ��ʼ����������
	for(int i = 0; i < MAXSTAR; i++)
	{
		InitStar(i);
		star[i].x = rand() % 830;
	}

	// �����ǿգ���������˳�
	while (1)
	{
		for (int i = 0; i < MAXSTAR; i++)
			MoveStar(i);
		Sleep(20);
		if (peekmessage(&msg1, EM_MOUSE) && msg1.message && WM_LBUTTONDOWN&&msg1.x >= 600 && msg1.x <= 600 + 200 && msg1.y >= 350 && msg1.y <= 350 + 80)
		{
			break;
			
		}
	}
	
		initgraph(1880, 830,SHOWCONSOLE);    // ������ͼ���ڣ���СΪ 1880*830����
		setbkcolor(WHITE);
		setbkmode(TRANSPARENT);
		cleardevice();
		TCHAR s[50] = "����";
		TCHAR s1[50] = "��";
		TCHAR s2[50] = "��";
		TCHAR s3[50] = "����";
		TCHAR s4[50] = "Բ";
		TCHAR s5[50] = "��Բ";
		TCHAR s6[50] = "����";
		TCHAR s7[50] = "�����";
		TCHAR s8[50] = "��ʽ����ɫ";
		TCHAR s9[50] = "����ͼƬ";
		TCHAR s10[50] = "����";
		TCHAR s11[50] = "��껭��";
		TCHAR s13[50] = "��Ƥ��";
		TCHAR s12[50] = "ȫ��";
		button b[14];
		b[0].build(0, 0, 100, 50,RGB(192,192,192),s);
		b[1].build(100, 0, 100, 50, RGB(192, 192, 192), s1);
		b[2].build(200, 0, 100,50, RGB(192, 192, 192), s2);
		b[3].build(300,0, 100, 50, RGB(192, 192, 192), s3);
		b[4].build(400, 0, 100, 50, RGB(192, 192, 192), s4);
		b[5].build(500, 0, 100, 50, RGB(192, 192, 192), s5);
		b[6].build(600, 0, 100, 50, RGB(192, 192, 192), s6);
		b[7].build(700, 0, 100, 50, RGB(192, 192, 192), s7);
		b[8].build(0, 50, 100, 50, RGB(192, 192, 192), s8);
		b[9].build(0, 100, 100, 50, RGB(192, 192, 192), s9);
		b[10].build(0, 150, 100, 50, RGB(192, 192, 192), s10);
		b[11].build(0, 200, 100, 50, RGB(192, 192, 192), s11);
		b[12].build(0, 250, 100, 50, RGB(192, 192, 192), s13);
		b[13].build(0, 300, 100, 50, RGB(192, 192, 192), s12);
		setlinecolor(BLACK);
		rectangle(100, 50, 1880, 830);
		line(0, 50, 1880, 50);
		line(100, 0, 100, 830);
		ExMessage msg;
		while (true) 
		{
			FlushBatchDraw();
			b[0].drawbutton();
			b[1].drawbutton();
			b[2].drawbutton();
			b[3].drawbutton();
			b[4].drawbutton();
			b[5].drawbutton();
			b[6].drawbutton();
			b[7].drawbutton();
			b[8].drawbutton();
			b[9].drawbutton();
			b[10].drawbutton();
			b[11].drawbutton();
			b[12].drawbutton();
			b[13].drawbutton();//����ť
			if (peekmessage(&msg, EM_MOUSE)) 
			{

				switch (msg.message)
				{
					case WM_LBUTTONDOWN://����������
					if (msg.x >= 0 && msg.x <= 0 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
					{
						cout << "������" << endl;

						mciSendString("open ./Iamyour.MP3", 0, 0, 0);//�������ļ�������Դ�ļ�ͬһĿ¼�£�alias  music����˼���ǽ���������ļ���������Ϊmusic
						mciSendString("play ./Iamyour.MP3 ", 0, 0, 0);//�������֣�play��Ϊ���ţ�ͬ���ɻ���pause:��ͣ��stop:ֹͣ��close:�رգ�Resume:������Repeat��Ϊ�ظ����š�
						int key = _getch();
						if (key == 32)
						{
							mciSendString("stop ./Iamyour.MP3", 0, 0, 0);
						}//��ͣ�������֡�




					}
					if (msg.x >= 100 && msg.x <= 100 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
					{
						Spot a;
						a.Drawn();

						//�ڴ˴�д�°�ť���ʱҪִ�еĺ�����ʵ����Ӧ�Ĺ���  
					}
					if (msg.x >= 200 && msg.x <= 200 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
					{

						Line b;
						b.Drawn();
						Line T = b;
						int c;
						c = T.a.x-T.x;
						int bey = _getch();
						if (bey == 118)
						{
							T.x += (c + 10);
							T.a.x += (c + 10);

							while (1)
							{
								
								line(T.x, T.y, T.a.x, T.a.y);
								FlushBatchDraw();
								if (GetAsyncKeyState(VK_UP))//�ϼ�
								{
									T.y -= 1;
									T.a.y -= 1;

								}
								if (GetAsyncKeyState(VK_DOWN))//�¼�
								{
									T.y += 1;
									T.a.y += 1;

								}
								if (GetAsyncKeyState(VK_LEFT))
								{
									T.x -= 1;
									T.a.x -= 1;

								}
								if (GetAsyncKeyState(VK_RIGHT))
								{
									T.x += 1;
									T.a.x += 1;

								}
								int key = _getch();
								if (key == 27)
								{
									break;
								}
								T.Delete();
							}
						}
						if (bey == 8)
						{
							T.Delete();
						}
						//�ڴ˴�д�°�ť���ʱҪִ�еĺ�����ʵ����Ӧ�Ĺ���
					}
					if (msg.x >= 300 && msg.x <= 300 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
					{
						TwoLine c;
						c.Drawn();
						TwoLine T = c;
						int b;
						b =T.l1.a.x-T.x;
						int bey = _getch();
						if (bey == 118)
						{
							T.x += (b + 10);
							T.a.x += (b + 10);
							T.l1.a.x += (b + 10);

							while (1)
							{

								line(T.x, T.y, T.a.x, T.a.y);
								line(T.a.x, T.a.y, T.l1.a.x, T.l1.a.y);
								FlushBatchDraw();
								if (GetAsyncKeyState(VK_UP))//�ϼ�
								{
									T.y -= 1;
									T.a.y -= 1;
									T.l1.a.y -= 1;

								}
								if (GetAsyncKeyState(VK_DOWN))//�¼�
								{
									T.y += 1;
									T.a.y += 1;
									T.l1.a.y += 1;

								}
								if (GetAsyncKeyState(VK_LEFT))
								{
									T.x -= 1;
									T.a.x -= 1;
									T.l1.a.x -= 1;

								}
								if (GetAsyncKeyState(VK_RIGHT))
								{
									T.x += 1;
									T.a.x += 1;
									T.l1.a.x += 1;

								}
								int key = _getch();
								if (key == 27)
								{
									break;
								}
								int e[3] = { T.x,T.a.x,T.l1.a.x };
								int f[3] = { T.y,T.a.y,T.l1.a.y };
								sort(e, e + 3);
								sort(f, f + 3);
								clearrectangle(e[0] - 1 - D, e[0] - 1 - D, f[2] + 1 + D, f[2] + D + 1);
							}
							
						}
						if (bey == 8)
						{
							T.Delete();
						}

						//�ڴ˴�д�°�ť���ʱҪִ�еĺ�����ʵ����Ӧ�Ĺ���
					}
					if (msg.x >= 400 && msg.x <= 400 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
					{
						Circle d;
						d.Drawn();
						cout << "0����䣬1���������" << endl;
						int k;
						cin >> k;
						switch (k)
						{
						case 0:
							d.fill();
							break;
						case 1:
							break;
						}
						Circle T = d;
						int a;
						a = T.R*2;
						int bey = _getch();
						if (bey == 118)
						{
							T.x += (a + 10);
							while (1)
							{
								if (k == 0)
								{
									solidcircle(T.x, T.y, T.R);
								}
								if (k == 1)
								{
									circle(T.x, T.y,T.R);
								}
								FlushBatchDraw();
								if (GetAsyncKeyState(VK_UP))//�ϼ�
								{
									T.y -= 1;
									
								}
								if (GetAsyncKeyState(VK_DOWN))//�¼�
								{
									T.y += 1;
									
								}
								if (GetAsyncKeyState(VK_LEFT))
								{
									T.x -= 1;
									
								}
								if (GetAsyncKeyState(VK_RIGHT))
								{
									T.x += 1;
									
								}
								int key = _getch();
								if (key == 27)
								{
									break;
								}
								clearrectangle(T.x - T.R - 1 - D, T.y - 1 - T.R - D, T.x + T.R + 1 + D, T.y + T.R + D + 1);
							}
						}
						if (bey == 8)
						{
							T.Delete();
						}

						//�ڴ˴�д�°�ť���ʱҪִ�еĺ�����ʵ����Ӧ�Ĺ���
					}
					if (msg.x >= 500 && msg.x <= 500 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
					{
						myEllipse e;
						e.Drawn();
						cout << "0����䣬1���������" << endl;
						int k;
						cin >> k;
						switch (k)
						{
						case 0:
							e.fill();
							break;
						case 1:
							break;
						}
						myEllipse T = e;
						int a;
						a = T.t.x - T.x;
						int bey = _getch();
						if (bey == 8)
						{
							T.myEllipse::Delete();
						}
						if (bey == 118)
						{
							T.x += (a + 10);
							T.t.x = T.x + a;
							while (1)
							{
								if (k == 0)
								{
									solidellipse(T.x, T.y, T.t.x, T.t.y);
								}
								if (k == 1)
								{
									ellipse(T.x, T.y, T.t.x, T.t.y);
								}
								FlushBatchDraw();
								if (GetAsyncKeyState(VK_UP))//�ϼ�
								{
									T.y -= 1;
									T.t.y -= 1;
								}
								if (GetAsyncKeyState(VK_DOWN))//�¼�
								{
									T.y += 1;
									T.t.y += 1;
								}
								if (GetAsyncKeyState(VK_LEFT))
								{
									T.x -= 1;
									T.t.x -= 1;
								}
								if (GetAsyncKeyState(VK_RIGHT))
								{
									T.x += 1;
									T.t.x += 1;
								}
								int key = _getch();
								if (key == 27)
								{
									break;
								}
								
									T.myEllipse::Delete();
							}
						
							
						}
					}
				
							if (msg.x >= 600 && msg.x <= 600 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
							{

								myRectangle f;
								f.Drawn();
								cout << "0����䣬1���������" << endl;
								int k;
								cin >> k;
								switch (k)
								{
								case 0:
									f.fill();
									break;
								case 1:
									break;
								}
								myRectangle T = f;
								int a;
								a = T.t.x - T.x;
								int bey = _getch();
								if (bey == 8)
								{
									T.myRectangle::Delete();
								}
								if (bey == 118)
								{
									T.x += (a + 10);
									T.t.x = T.x + a;

									while (1)
									{
										if (k == 0)
										{
											fillrectangle(T.x, T.y, T.t.x, T.t.y);
										}
										if (k == 1)
										{
											rectangle(T.x, T.y, T.t.x, T.t.y);
										}
										FlushBatchDraw();
										if (GetAsyncKeyState(VK_UP))//�ϼ�
										{
											T.y -= 1;
											T.t.y -= 1;
										}
										if (GetAsyncKeyState(VK_DOWN))//�¼�
										{
											T.y += 1;
											T.t.y += 1;
										}
										if (GetAsyncKeyState(VK_LEFT))
										{
											T.x -= 1;
											T.t.x -= 1;
										}
										if (GetAsyncKeyState(VK_RIGHT))
										{
											T.x += 1;
											T.t.x += 1;
										}
										int key = _getch();
										if (key == 27)
										{
											break;
										}
										clearrectangle(T.x - 1 - D, T.y - 1 - D, T.t.x + 1 + D, T.t.y + 1 + D);

										int ley = _getch();
										if (ley == 27)
										{
											break;
										}
									}

									
								}
								

								//�ڴ˴�д�°�ť���ʱҪִ�еĺ�����ʵ����Ӧ�Ĺ���
							}
							if (msg.x >= 700 && msg.x <= 700 + 100 && msg.y >= 0 && msg.y <= 0 + 50)
							{
								Polyon g;
								g.Drawn();
								cout << "0����䣬1���������" << endl;
								int k;
								cin >> k;
								switch (k)
								{
								case 0:
									g.fill();
									break;
								case 1:
									break;
								}
							   Polyon T = g;
							   int* c;
							   c = new int[T.n];
							   for (int i = 0; i < T.n; i++)
							   {
								   c[i] = T.a[i].x;
							   }
							   sort(c, c + T.n);
								int b;
								b = c[T.n - 1] - c[0];
								int bey = _getch();
								if (bey == 8)
								{
									T.Polyon::Delete();
								}
								if (bey == 118)
								{
									for (int i = 0; i < T.n; i++)
									{
										T.a[i].x += b;
									}

									while (1)
									{
										if (k == 0)
										{
											fillpolygon(T.a, T.n);
										}
										if (k == 1)
										{
											polygon(T.a, T.n);
										}
										FlushBatchDraw();
										if (GetAsyncKeyState(VK_UP))//�ϼ�
										{
											for (int i = 0; i < T.n; i++)
											{
												T.a[i].y -= 1;
											}
										}
										if (GetAsyncKeyState(VK_DOWN))//�¼�
										{
											for (int i = 0; i < T.n; i++)
											{
												T.a[i].y += 1;
											}
										}
										if (GetAsyncKeyState(VK_LEFT))
										{
											for (int i = 0; i < T.n; i++)
											{
												T.a[i].x -= 1;
											}
										}
										if (GetAsyncKeyState(VK_RIGHT))
										{
											for (int i = 0; i < T.n; i++)
											{
												T.a[i].x += 1;
											}
										}
										int* m;
										int* r;
										m = new int[T.n];
										r = new int[T.n];
										for (int i = 0; i < T.n; i++)
										{
											m[i] = T.a[i].x;
										}
										for (int i = 0; i < T.n; i++)
										{
											r[i] = T.a[i].y;
										}
										sort(m, m + T.n);
										sort(r, r + T.n);
										int ley = _getch();
										if (ley == 27)
										{
											break;
										}clearrectangle(m[0] - D-1, r[0] - D - 1, m[T.n - 1] + D + 1, r[T.n - 1] + D + 1);

									}
								}
								
								delete[]c;

								//�ڴ˴�д�°�ť���ʱҪִ�еĺ�����ʵ����Ӧ�Ĺ���
							}
							if (msg.x >= 0 && msg.x <= 0 + 100 && msg.y >= 50 && msg.y <= 50 + 50)
							{
								int c;
								cout << "��������Ҫѡ����ߵ����ࣺ0.ʵ�� 1��----- 2 ��....... 3:-.-.-.-.-�ʹ�ϸ��С" << endl;
								cin >> c >> D;
								setlinestyle(c, D);
								int R, G, B;
								cout << "������ɫ��" << endl;
								cin >> R >> G >> B;
								setlinecolor(RGB(R, G, B));


								//�ڴ˴�д�°�ť���ʱҪִ�еĺ�����ʵ����Ӧ�Ĺ���
							}
							if (msg.x >= 0 && msg.x <= 0 + 100 && msg.y >= 100 && msg.y <= 100 + 50)
							{

								IMAGE img;
								int c = 300; int d = 300;
								int a =220, b = 220; loadimage(&img, "C:\\Users\\DELL\\Pictures\\֤��\\111.jpg", c, d, true);
								while (true)
								{
									
									putimage(a, b, &img);
									if (GetAsyncKeyState(VK_UP))//�ϼ�
									{
										b -= 1;
									}
									if (GetAsyncKeyState(VK_DOWN))//�¼�
									{
										b += 1;
									}
									if (GetAsyncKeyState(VK_LEFT))
									{
										a -= 1;
									}
									if (GetAsyncKeyState(VK_RIGHT))
									{
										a += 1;
									}
									int key = _getche();
									if (key == 27)
									{
										break;
									}FlushBatchDraw();//��ֹ��Ļ����
									clearrectangle(a-2, b-2, a + c+2, b + d+2);
								}
									while(true)
									{
										loadimage(&img, "C:\\Users\\DELL\\Pictures\\֤��\\1111.jpg", c, d, true);
										putimage(a, b, &img);
										int key = _getche();
									if (key == 61)
									{
										c += 5;
										d += 5;
									}
									else if (key == 45)
									{
										FlushBatchDraw();
										clearrectangle(a, b, a + c,b + d);
										c -= 5;
										d -= 5;
									}
									if(key==27)
									{
										break;
									}
						

								    }
									int bey = _getche();
									if (bey == 8)
									{
										clearrectangle(a, b, a + c, b + d);
									}
								//�ڴ˴�д�°�ť���ʱҪִ�еĺ�����ʵ����Ӧ�Ĺ���*/
							}
							if (msg.x >= 0 && msg.x <= 100 && msg.y >= 150 && msg.y <= 150 + 50)
							{
								cout << "shanb1" << endl;
								saveimage("D:\\UJS housework\\house work\\����\\����\\Rhoto.bmp");
								//�ڴ˴�д�°�ť���ʱҪִ�еĺ�����ʵ����Ӧ�Ĺ���
							}
							if (msg.x >= 0 && msg.x <= 0 + 100 && msg.y >= 200 && msg.y <= 200 + 50)
							{
								int x = 250; int y = 250; int R = 10;
								setfillcolor(RGB(255,255,255));
								while (1)
								{
									circle(x, y, R);
									FlushBatchDraw();
									if (GetAsyncKeyState(VK_UP))//�ϼ�
									{
										y -= 3;

									}
									if (GetAsyncKeyState(VK_DOWN))//�¼�
									{
										y += 3;

									}
									if (GetAsyncKeyState(VK_LEFT))//���
									{
										x -= 3;

									}
									if (GetAsyncKeyState(VK_RIGHT))//�Ҽ�
									{
										x += 3;

									}
									int key = _getch();
									if (key == 27)
									{
										clearrectangle(x - R - 1 - D, y - 1 - R - D, x + R + 1 + D, y + R + D + 1);
										break;
									}
									clearrectangle(x - R - 1 - D, y - 1 - R - D, x + R + 1 + D, y + R + D + 1);
								}
								//������ʵ�ֱȽϼ�ª��ʹ�õķ����ǽ���ͼ��ɫ���غͱ�������ɫһ��
		//���Ž���ͼ�����Ļ��ߵĴ�ϸ��������һЩ


								//�ڴ˴�д�°�ť���ʱҪִ�еĺ�����ʵ����Ӧ�Ĺ���
							}
							
							if (msg.x >= 0 && msg.x <= 0 + 100 && msg.y >= 250 && msg.y <= 250 + 50)
							{
								int x = 250; int y = 250; int R = 10;
								setfillcolor(RGB(255, 255, 255));
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
										clearrectangle(x - R - 1 - D, y - 1 - R - D, x + R + 1 + D, y + R + D + 1);
										break;
									}
									clearrectangle(x - R - 1 - D, y - 1 - R - D, x + R + 1 + D, y + R + D + 1);
								}
								//�ڴ˴�д�°�ť���ʱҪִ�еĺ�����ʵ����Ӧ�Ĺ���
							}if (msg.x >= 0 && msg.x <= 0 + 100 && msg.y >= 300 && msg.y <= 300 + 50)
							{
								clearrectangle(100, 50, 1880, 830);
								//�ڴ˴�д�°�ť���ʱҪִ�еĺ�����ʵ����Ӧ�Ĺ���
							}

							break;
						default:
							break;
				}
			}

		}


				return 0;
	}