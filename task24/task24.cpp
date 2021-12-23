// Даны две матрицы, построить матрицу C, где элемент C[i][j] равен сумме элементов i-й строке матрицы А, которых нет в j-том столбце матрицы В, и нулю,
//если таких элементов нет

#include <iostream>
using namespace std;
int** memory(int n, int m);
void fill(int** a, int n, int m);
int sum(int** a, int** B, int n, int m, int i, int j);
bool chek(int** b, int chislo, int j, int n);
void fill_sum(int**A, int**B, int**C, int n, int m);
int main()
{
	int n,m;
	printf("vvedite razmer\n");
	scanf_s("%d%d", &n,&m);
	int** A = memory(n, m);
	fill(A, n, m);
	int** B = memory(n, m);
	fill(B, n, m);
	int** C = memory(n, m);
	fill_sum(A, B, C, n, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	/*if (chek(A, 1, 2, 3))		//отладка функции chek
	{
		printf("1");
	}*/ 
}

//выделение памяти
int** memory(int n, int m)
{
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	return a;
}
//заполнение элементов
void fill(int** a, int n, int m)
{
	printf("zapolnite massiv\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
}
//накопление суммы 
int sum(int** a,int**B, int n, int m, int i, int j)
{
	int sum = 0;
	for (int k = 0; k < n; k++)
	{
		if (chek(B,a[i][k],j,n))
		{
			sum+=a[i][k];
		}
	}
	return sum;
}
//проверка на наличие в столбце матрицы В элемента из строки матрицы А
bool chek(int** b, int chislo, int j, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (chislo==b[i][j])
		{
			return false;
		}
	}
	return true;
}
// заполнение нового массива
void fill_sum(int** A, int** B, int** C, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			C[i][j] = sum(A, B, n, m, i, j);
		}
	}
}