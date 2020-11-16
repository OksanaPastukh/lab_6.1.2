// Lab_6.1.2
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
/// <summary>
/// Формування масива з рандомних чисел
/// </summary>
/// <param name="p">масив який формуємо </param>
/// <param name="n">кількість елементів масиву </param>
/// <param name="A">мінімальне значення елемента</param>
/// <param name="B">максимальне значення елемента</param>
void Random(int* p, int n, int A, int B, int i)
{
	p[i] = rand() % (B - A + 1) + A;
	if (i < n - 1)
		Random(p, n, A, B, i + 1);
}
bool isValid(int value, int i)
{
	bool result = true;
    //if (value % 2 == 0 && value % 13 == 0)
	if (value % 2 == 0 && i % 13 == 0)
	{
		result = false;
	}
	return result;
}
int Count(int* p, int n, int i)
{
	if (i < n)
	{
		return ((isValid(p[i], i)) ? 1 : 0) + Count(p, n, i + 1);
	}
	else
		return 0;
}
int Sum(int* p, int n, int i)
{
	if (i < n)
	{
		return ((isValid(p[i], i)) ? p[i] : 0) + Sum(p, n, i + 1);
	}
	else
		return 0;
}

void Replace(int* p, int n, int i)
{
	if (i < n)
	{
		Replace(p, n, i+1);
		if (isValid(p[i], i))
			p[i] = 0;

	}
}
/// <summary>
/// Вивід масиву
/// </summary>
/// <param name="p">масив який виводимо</param>
/// <param name="n">кількість елементів масиву</param>
void Print(int* p, int n, int i)
{
	cout << setw(3) << p[i] << " ";
	if (i < n - 1)
		Print(p, n, i + 1);
	else
		cout << endl;
}
int main()
{
	srand(time(NULL));
	const int n = 25;
	int p[n];
	int A = 15, B = 94;

	Random(p, n, A, B, 0);
	Print(p, n, 0);
	cout << "count = " << Count(p, n,0) << "\n";
	cout << "sum = " << Sum(p, n,0) << "\n";
	Replace(p, n, 0);
	Print(p, n, 0);

	system("pause");
	return 0;
} 