#include<stdio.h>
#include<math.h>
#include<locale.h>
int main() {
	setlocale(LC_ALL, "RUS");
	double x;
	printf("������� X:");
	scanf("%lf", &x);//����� ������� ������������ ������ x
	double y = x * atan(x) - log(sqrt(1 + pow(x, 2)));

	double v = 0;
	if (fabs(x) > 1) {
		v = fabs(x);
	}
	else if (fabs(x) <= -1) {
		v = 1 + x;
	}
	else v = sin(x);
	
	printf("X=%.2lf\n\nY=%.2lf\n\nV=%.2lf\n\n\n", x, y, v);//����� ���� ���������� � �������
	
}