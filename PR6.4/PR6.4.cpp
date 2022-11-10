#include <iostream>
#include <time.h>

using namespace std;

void create(double*& mas, int n, double  A, double B, int i)
{
	mas[i] = A + rand() * (B - A) / RAND_MAX;
	if (i < n - 1)
		create(mas, n, A, B, i + 1);
}
void print(double*& mas, int n, int i)
{
	cout << mas[i] << ", ";
	if (i < n - 1)
		print(mas, n, i + 1);
}
double Suma(double*& mas, const int n, int i, double s) {
	if (mas[i] < 0) {
		s += mas[i];
	}
	if (i < n) {
		return Suma(mas, n, i + 1, s);
	}
	else {
		return s;
	}
}
void Found_Max(double*& mas, const int n, double& max_el, int& index_max, int i) {
	if (mas[i] > max_el) {
		max_el = mas[i];
		index_max = i;
	}
	if (i < n) {
		Found_Max(mas, n, max_el, index_max, i + 1);
	}
}
void  Found_Min(double*& mas, const int n, double& min_el, int& index_min, int i) {
	if (mas[i] < min_el) {
		min_el = mas[i];
		index_min = i;
	}
	if (i < n) {
		Found_Min(mas, n, min_el, index_min, i + 1);
	}
}
void hz(int& index_max, int& index_min, int& in1, int& in2) {
	if (index_min < index_max) {
		in1 = index_min;
		in2 = index_max;
	}
	else {
		in1 = index_min;
		in2 = index_max;
	}

}
double dob_prom(double*& mas, int in1, int in2, double d) {
	if (in1 <= in2) {
		return d * mas[in1] * dob_prom(mas, in1 + 1, in2, d);
	}
	else {

		return d;
	}
}
void Sort(double*& mas, const int n, int i)
{
	double min = mas[i];
	int imin = i;
	for (int j = i + 1; j < n; j++)
		if (min > mas[j]) {
			min = mas[j];
			imin = j;
		}
	mas[imin] = mas[i];
	mas[i] = min;
	if (i < n - 2)
		Sort(mas, n, i + 1);
}
int main()
{
	srand((unsigned)time(NULL));
	int n = 10;
	double* a;
	a = new double[n];
	create(a, n, -20, 50, 0);
	cout << "a = { ";	print(a, n, 0); cout << " }" << endl;
	cout << "suma = " << Suma(a, n, 0, 0) << endl;

	int index_max = 0;
	double max_el = a[0];
	int index_min = 0;
	double min_el = a[0];
	Found_Max(a, n, max_el, index_max, 0);
	Found_Min(a, n, min_el, index_min, 0);
	cout << "max_el " << max_el << "  index_max " << index_max << endl;
	cout << "min_el " << min_el << "  index_min " << index_min << endl;

	int in1 = 0;
	int in2 = 0;
	hz(index_max, index_min, in1, in2);
	cout << "dob_prom = " << dob_prom(a, in1, in2, 1.0) << endl;

	int size_b;
	cout << "size_b = "; cin >> size_b;
	double* b;
	b = new double[n];
	create(b, size_b, -20, 50, 0);
	cout << "b = { ";	print(b, size_b, 0); cout << " }" << endl;
	Sort(b, size_b, 0);
	cout << "b = { ";	print(b, size_b, 0); cout << " }" << endl;

	delete[]a;
	delete[]b;
	return 0;
}