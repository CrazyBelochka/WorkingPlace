#include<iostream>
#include <iomanip>
#include<cmath>
using namespace std;
double f(double x) //�������
{
	return pow(2.0, x) - 5 * pow(x, 2.0) + 10;
}
double df(double x) //������ �����������
{
	return pow(2.0, x) * log(2.0) - 10 * x;
}
double dfdf(double x) //������ �����������
{
	return pow(2.0, x) * log(2.0) - 10;
}
double g(double x)
{
	return x + 0.5 * f(x);
}
double equivalent(double x) {
	return (x - (1 / df(x)) * f(x));
}
int metodNewton()
{
	int exit = 0, i = 0;//���������� ��� ������ � �����
	double x0, xn;// ����������� ����������� ��� �����
	double a, b, eps = 0.001;// ������� ������� � ����������� ��������
	i = 0;
	cout << "Please input [a;b]\n";
	cin >> a >> b; // ������ ������� �������, �� ������� ����� ������ ������
	for (eps = 0.001; eps <= 0.1;) {
		cout << "\nCurrent epsilon: " << eps << endl;
		if (f(a) * dfdf(a) > 0) x0 = a; // ��� ������ ��������� ����� ��������� f(x0)*dfdf(x0) > 0 ?
		else x0 = b;
		xn = x0 - f(x0) / df(x0); // ������� ������ �����������
		cout << ++i << "-th iteration = " << xn << "\n";
		while (fabs(x0 - xn) > eps) // ���� �� ��������� ����������� ��������, ����� ���������� ���������
		{
		x0 = xn;
		xn = x0 - f(x0) / df(x0); // ������� �������
		cout << ++i << "-th iteration = " << xn << "\n";
		}
		cout << "Answer = " << xn << endl; // ����� ������������ �����
		i = 0;
		eps = eps * 10;
	}
	return 0;
}
int metodIT()
{
	double x, s;
	int i = 0;
	double eps;
	cout << "Enter initial root value : "; cin >> x;
	s = x;
	for (eps = 0.001; eps <= 0.1;) {
		x = s;
		cout << "\nCurrent epsilon: " << setprecision(0) << eps << endl;
		for (double iter = 1; eps < fabs(f(x)); iter = iter + 1)
		{
			x = equivalent(x);
			cout << ++i << "-th iteration = " << x << "\n";
		}
		eps = eps * 10;
		i = 0;
	}
	return 0;
}
int methodSEC()
{
	double x0, x1, x2, xn, a, b, eps, r, xn1;
	int i = 0;
	cout << "Please input [a;b]\n";
	cin >> a >> b;
	for (eps = 0.001; eps <= 0.1; eps = eps * 10) {
		if (f(a) * dfdf(a) > 0) x0 = a; // ��� ������ ��������� ����� ��������� f(x0)*dfdf(x0) > 0 ?
		else x0 = b;
		cout << "\nCurrent epsilon: " << eps << endl;
		xn = x0 - f(x0) / df(x0); // ������� ������ �����������
		cout << ++i << "-th iteration = " << xn << "\n";
		do {
			xn1 = xn - (((xn - x0) * f(xn)) / (f(xn) - f(x0)));
			x0 = xn;
			xn = xn1;
			cout << ++i << "-th iteration = " << xn << "\n";
		} while ((fabs(f(xn - x0) >= eps) && (i < 6)));
		i = 0;
	}
	return 0;
}
int main()
{
	int choice;
	cout << "Make choice: " << endl;
	cout << "1-Method Newtona" << endl;
	cout << "2-Method PROSTIH_ITERACII" << endl;
	cout << "3-Method SECKUSHEI" << endl;
	cout << "4-EXIT" << endl;
	cin >> choice;
	if (choice == 1) metodNewton();
	if (choice == 2) metodIT();
	if (choice == 3) methodSEC();
	else return 0;
}