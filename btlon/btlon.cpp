// btlon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <conio.h>

float ktpr(float pr, int hp, int d, int s)
{
	int a;
	if ((pr < 0))
	{
		pr = 0;
		printf("in :%f ", pr);
	}
	else if ((999 < (hp)) | ((hp) < 1) | ((d) < 1) | ((d)>1000) | ((s) < 1) | ((s)>100))
	{
		pr = -1;
		printf("in :%f ", pr);
	}
	else if (pr > 1)
	{
		pr = 1;
		printf("in :%f ", pr);
	}

	else
	{
		
		printf("in :%f ", pr);
	}
	return pr;
}
float ktran(int d, float p1, float p2)
{
	int b;
	float a;
	b =(d) + p1 + p2;
	a = float(b / 1000);
	if (a > 0.8)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
int ktstg(int s)
{
	int a = 0;
	int stg = 0;
	while (a < (s))
	{
		a = a + 1;
		stg = stg + a;

	}
	return stg;

}
int kt_s(int s)
{
	int r;
	int a = 0;
	int g = 0;
	if ((s) % 6 == 0)
	{
		g =( s )/ 2;
	}
	else if ((s )% 6 == 1)
	{
		g = 2 *( s);
	}
	else if ((s) % 6 == 2)
	{
		g = ((-(s) % 9)*((s) % 9)*((s) % 9)) / 5;
	}
	else if ((s) % 6 == 3)
	{
		g = -((s) % 30)*((s) % 30) + 3 * (s);
	}
	else if ((s) % 6 == 4)
	{
		g = -(s);
	}
	else if ((s) % 6 == 5)
	{
		r = (s) % 5 + 5;
		g = -ktstg(r);
	}


	return g;
}
int ktfb(int a)
{
	int f3 = 0;
	int f1 = 1;
	int f2 = 1;

	while (f3 < (a))
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;

	}
	if ((a)==1)
	{
		return 1;
	}
	if ((a) == f3)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int ktsnt(int hp)
{
	if (hp < 2)
		return 0;

	for (int i = 2; i < hp; i++)
	{
		if ((hp)%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
float tinh(int p1, int p2, int f)
{
	float a, c;
	c = p1 + p2*f;
	a= c / (1000 + abs(p2*f));
	return a;
}
int tinhran(int hp,int d,int s, int p1, int p2)
{
	float f;
	float pr;
	if (((d) >= 200)&((d) <= 300)&(ktran(d, p1, p2) == 1))
	{

		pr = 0;
		printf("in: %f", 0 * 0);
	}
	else 
	{


		f = 40 - ((abs((d) - 500) / 20)) + kt_s((s));
		pr = tinh(p1, p2, f);
		printf("in :%f", ktpr(pr,(hp),(d),(s)));
	}
	return 0;
}
int main()
{
	int p1, p2;
	int w = 0,b;
	float pr=0;
	int f;
	float a,c,h;
	int hp;
	int d;
	int s;
	
	
	printf_s("nhap hp:");
	scanf_s("%d", &hp);
	printf_s("nhap d:");
	scanf_s("%d", &d);
	printf_s("nhap s:");
	scanf_s("%d", &s);
	



	if (ktsnt(hp) == 1)
	{
		p1 = 1000;
		p2 = ((hp) + (s)) % 1000;w = ktran((d), p1, p2);b = (d) + p1 + p2;
	    c = b / 1000;
		if ((d) < 200)
		{
			if (ktfb((d) + (s)) == 0)
			{
				f = 0;
				pr = tinh(p1, p2, f);;
				printf("in :", ktpr(pr, hp, d, s));
			}
			else if(ktfb((d)+(s))==1)
			{
				f = 40 - ((abs(d - 500) / 20)) + kt_s((s));
				pr=tinh(p1, p2, f);
				
				printf("in :", ktpr(pr, hp, d, s));

			}
		}
		
		else if(((d)>=200)&((d)<=800))
		{
			if ((d >= 200)&((d) <= 300)&ktran(d,p1,p2)==1)
			{
				pr = 0;
				printf("in: %d",0);
			}
			else
			{ 
				f = 40 - ((abs(d) - 500) / 20) + kt_s((s));
				pr = tinh(p1, p2, f);
				printf("in :", ktpr(pr, hp, d, (s)));
			}
		}
		else if ((d)>800)
		{
			f = -(((d)*(s)) / 1000);
			pr = tinh(p1, p2, f);
			printf("in : ", ktpr(pr, hp, d, s));
		}

		

	}
	else if (ktsnt(hp) == 0)
	{
		p1 = hp;
		p2 = (hp + d) % 100;w = ktran(d, p1, p2);b = d + p1 + p2;
		c = b / 1000;h = 0.8;
		
			
				if (d < 200)
				{
					if (ktfb(d + s) == 0)
					{
						f = 0;
						pr = tinh(p1, p2, f);
						printf("in :", ktpr(pr, hp, d, s));
					}
					else if (ktfb(d + s) == 1)
					{
						f = 40 - (abs(d - 500) / 20) + kt_s(s);
						pr = tinh(p1, p2, f);
						printf("in :", ktpr(pr, hp, d, s));

					}
				}

				else if ((d >= 200)&(d <= 800))
				{
					tinhran(hp, d, s, p1, p2);

				}
				else if (d > 800)
				{
					f = -((d*s) / 1000);
					pr = tinh(p1, p2, f);
					printf("in : ", ktpr(pr, hp, d, s));
				}
			}
		
	

	_getch();
	return main();
}

