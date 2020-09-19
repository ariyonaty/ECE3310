/*
* Ari Yonaty
* ECE3310
* MergeSort
*/

#include <iostream>

#define N 10

void display(double*, int);
void mergeSort(double*, double*, int);
void bubbleSort(double*, int n);
void swap(double* x, double* y);

int main()
{
	int x1[N], y1[N], x2[N], y2[N];
	double a[N], b[N];

	for (int i = 0; i < N; i++)
	{
		x1[i] = rand() % 301;
		y1[i] = -10 + rand() % 21;
		x2[i] = rand() % 301;
		y2[i] = -10 + rand() % 21;
		a[i] = 7.03 + 0.05 * x1[i] + y1[i];
		b[i] = 7.03 + 0.05 * x2[i] + y2[i];
	}
	
	std::cout << "Array A before sort: ";
	display(a, N);
	std::cout << "Array B before sort: ";
	display(b, N);
	bubbleSort(a, N);
	bubbleSort(b, N);
	std::cout << "Array A after sort: ";
	display(a, N);
	std::cout << "Array B after sort: ";
	display(b, N);

	mergeSort(a, b, N);

	return 0;
}

void swap(double* x, double* y)
{
	double temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(double* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

void mergeSort(double* arr1, double* arr2, int size)
{
	double x = arr1[0];
	double y = arr2[0];
	double result[2 * N];
	
	int i = 0, j = 0, k = 0;

	while (i < size && j < size)
	{
		if (arr1[i] <= arr2[j])
		{
			result[k] = arr1[i];
			i++;
		}
		else
		{
			result[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < size)
	{
		result[k] = arr1[i];
		i++;
		k++;
	}

	while (j < size)
	{
		result[k] = arr2[j];
		j++;
		k++;
	}

	std::cout << "Array A+B after sorted merge: ";
	display(result, 2 * N);
}

void display(double* arr, int size)
{
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl << std::endl;
}