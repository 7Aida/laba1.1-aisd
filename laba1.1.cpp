#include "set1.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m;
	int col, d;
	int* a, * x;
	cout << "Введите количество элементов в 1 множестве " << endl;
	cin >> n;
	a = new int[n];
	cout << "Введите элементы первого множества " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
	se m1(a, n);

	cout << "Введите количество элементов во 2 множестве" << endl;
	cin >> m;
	x = new int[m];
	cout << "Введите элементы второго множества " << endl;
	for (int i = 0; i < m; i++)
	{

		cout << "a[" << i << "]=";
		cin >> x[i];
	}
	se m2(x, m);

	cout << "Исходные множества" << endl;
	cout << m1 << endl;
	cout << m2 << endl;
	do {
		cout << "Введите индекс  " << endl;
		cin >> col;
	} while (col >= n || col < 0);
	cout << "Вывод числа по индексу  " << endl;
	cout << m1(col) << endl;
	cout << "Введите число " << endl;
	cin >> d;
	cout << "Результат вычитания числа из  матрицы" << endl;
	cout << m1 / d << endl;
	cout << "Результат добавления числа в матрицу" << endl;
	cout << m1 % d << endl;
	cout << "Результат сложения матриц" << endl;
	cout << m1 + m2 << endl;
	cout << "Результат вычитания  матриц" << endl;
	cout << m1 - m2 << endl;
	cout << "Результат пересечение матриц" << endl;
	cout << m1 * m2 << endl;
	system("pause");
	return 0;
}