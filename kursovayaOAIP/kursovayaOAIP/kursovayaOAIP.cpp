#include <iostream>
#include <cmath> // для round

using namespace std;

int n, i, j, k, konec;

double d, s;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Порядок матрицы: " << endl;
	cin >> n;
	double** a = new double* [n];
	for (i = 0; i <= n; i++)
		a[i] = new double[n];
	double* b = new double[n];
	double* x = new double[n];
	cout << "Введит коэфициенты и свободные члены " << endl;
	for (i = 1; i <= n; i++)

	{

		for (j = 1; j <= n; j++)
		{

			cout << "a[ " << i << "," << j << "]= ";
			cin >> a[i][j];

			while (cin.fail()) {
				cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << "Введите значение элемента  a[" << i << "][" << j << "] повторно:";
				cin >> a[i][j];
			}

		}

		cout << "b,[ " << i << "]= ";

		cin >> b[i];

		while (cin.fail()) {
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Введите значение элемента  b[" << i << "] повторно:";
			cin >> b[i];
		}

	}
	cout << "матрица имеет вид " << endl;

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
		{
			cout << "a[ " << i << "," << j << "]= " << a[i][j] << "  ";
		}
		cout << "b[" << i << "] " << b[i];
		cout << endl;

	}

	for (k = 1; k <= n; k++) // прямой ход

	{

		for (j = k + 1; j <= n; j++)

		{

			d = a[j][k] / a[k][k]; // формула (2.1)

			for (i = k; i <= n; i++)

			{

				a[j][i] = a[j][i] - d * a[k][i]; // формула (2.2)

			}

			b[j] = b[j] - d * b[k]; // формула (2.3)

		}

	}
	cout << "прямой ход " << endl;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
		{
			cout << "a[ " << i << "," << j << "]= " << a[i][j] << " ";
		}
		cout << endl;

	}

	for (k = n; k >= 1; k--) // обратный ход

	{

		d = 0;

		for (j = k + 1; j <= n; j++)

		{

			s = a[k][j] * x[j]; // формула (2.4)

			d = d + s; // формула (2.4)

		}

		x[k] = (b[k] - d) / a[k][k]; // формула (2.4)

	}


	cout << "Корни системы: " << endl;

	for (i = 1; i <= n; i++)

		cout << "x[" << i << "]=" << round(x[i]*100)/100 << " " << endl;

	cin >> konec;
	return 0;
	

}