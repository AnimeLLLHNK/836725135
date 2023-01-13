#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<stdlib.h>

double FUN_1(double x);
double FUN_2(double x);

double FUN_1(double x) {
	double y;
	y = x * atan(x) - log(sqrt(1 + pow(x, 2)));
	return y;
}

double FUN_2(double x) {
	double y;
	if (fabs(x) > 1) {
		y = fabs(x);
	}
	else if (fabs(x) <= -1) {
		y = 1 + x;
	}
	else y = sin(x);
	return y;
}
typedef double(*Tfunc)(double);

void tub(Tfunc f, double xn, double xk, double h)
{
	if (xn<0) {
		printf("|      X      |    F(x)    |");
	}
	else {
		printf("\n|     X     |     F(x)     |");
	}
	for (double x = xn; x <= xk; x += h)
	{
		printf("\n| %1.8f | %1.8f |", x, f(x));
	}
}

void plot(double x0, double x1, Tfunc f) {
	char SCREENW = 60, SCREENH = 40;

	char screen[60][40];

	double x, y[60];

	double ymin = 0, ymax = 0;

	double hx, hy;;

	int i, j;

	int xz, yz;

	hx = (x1 - x0) / (SCREENW - 1);

	for (i = 0, x = x0; i < SCREENW; ++i, x += hx) {

		y[i] = x; //������ �������� ������� ��� ������ ����� ���� ������ �������

		if (y[i] < ymin) ymin = y[i];

		if (y[i] > ymax) ymax = y[i];
	}
	hy = (ymax - ymin) / (SCREENH - 1);

	yz = (int)floor(ymax / hy + 0.5);

	xz = (int)floor((0. - x0) / hx + 0.5);

	//���������� ���� � ���������� ������� ����������� ���������

	for (j = 0; j < SCREENH; ++j)

		for (i = 0; i < SCREENW; ++i) {

			if (j == yz && i == xz) screen[i][j] = '+';

			else if (j == yz) screen[i][j] = '-';

			else if (i == xz) screen[i][j] = '|';

			else screen[i][j] = ' ';

		}

	//����������� ��������� �������� ������� �� ���� ������

	for (i = 0; i < SCREENW; ++i) {

		j = (int)floor((ymax - y[i]) / hy + 0.5);

		screen[i][j] = '*';

	}

	//������ ������� ��������

	for (j = 0; j < SCREENH; ++j) {

		for (i = 0; i < SCREENW; ++i) putchar(screen[i][j]);

		putchar('\n');

	}
}

void main() {

	setlocale(LC_ALL, "RUS");
	float x;
	float x1;
	float x2, shag;
	char k = '0';
	char c1;
	char c2;
	while (k != '7')
	{
		puts("\nY(x)=x*arctg(x)-lnsqrt(1+pow(x,2))\n\n     {|x| ��� |x|>1\nV(x)={1+x ��� |x|<=-1\n     {sin(x) ��� ���������\n\n\n����� ��������:\n 1.����� �������� ������� Y(x)\n 2.����� �������� ������� V(x)\n 3.��������� ������, ��������� ������� Y(x)\n 4.��������� ������, ��������� ������� V(x)\n 5.������� ������� �������������� �������� Y(x)\n 6.������� ������� �������������� �������� V(x)\n 7.��������� ������\n");
		scanf(" %c", &k);
		switch (k)
		{
		case'1':
			puts("������� ���������� x:");
			scanf("%f", &x);
			if (x <= 0)
				printf("�� ��������");
			printf("%f\n", FUN_1(x));
			break;
		case'2':
			puts("������� ���������� x:");
			scanf("%f", &x);
			if (x > 1)
				printf("�� ��������");
			printf("%f\n", FUN_2(x));
			break;
		case'3':
			puts("\n������� ��������(�� ��������):");
			scanf(" %c%f;%f%c", &c1, &x1, &x2, &c2);
			puts("\n������� ��� ���������:");
			scanf(" %f", &shag);
			if (c1 == '(') x1 += shag;
			if (c2 == ')') x2 -= shag;
			plot(x1, x2, FUN_1);
			break;
		case'4':
			puts("\n������� ��������(�� ��������):");
			scanf(" %c%f;%f%c", &c1, &x1, &x2, &c2);
			puts("\n������� ��� ���������:");
			scanf(" %f", &shag);
			if (c1 == '(') x1 += shag;
			if (c2 == ')') x2 -= shag;
			plot(x1, x2, FUN_2);
			break;
		case'5':
			puts("\n������� ��������(�� ��������):");
			scanf(" %c%f;%f%c", &c1, &x1, &x2, &c2);
			puts("\n������� ��� ���������:");
			scanf(" %f", &shag);
			if (c1 == '(') x1 += shag;
			if (c2 == ')') x2 -= shag;
			tub(FUN_1, x1, x2, shag);
			break;
		case'6':
			puts("\n������� ��������(�� ��������):");
			scanf(" %c%f;%f%c", &c1, &x1, &x2, &c2);
			puts("\n������� ��� ���������:");
			scanf(" %f", &shag);
			if (c1 == '(') x1 += shag;
			if (c2 == ')') x2 -= shag;
			tub(FUN_2, x1, x2, shag);
			break;
		default:
			puts("������� ������ ��������");
			break;
		}
	}
}