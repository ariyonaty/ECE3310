/*
* Ari Yonaty
* ECE3310
* 9.24.2020
* Midterm 1
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

#define SIZE 50

void displayArray(float[], int);
void swap(float* x, float* y);
void bubbleSort(float arr[], int n);
void mergeSort(float* arr1, float* arr2, int size);


int main(void)
{
	std::ifstream f("data.txt");
	std::string str, tmp;

	int arrIndex = 0;
	float data_x[SIZE], data_y[SIZE];

	if (!f.is_open())
	{
		std::cerr << "Error opening file." << std::endl;
	}

	while (getline(f, str) && !str.empty())
	{
		std::stringstream ss(str);
		std::getline(ss, tmp, ',');
		data_x[arrIndex] = std::stof(tmp);
		std::getline(ss, tmp, ',');
		data_y[arrIndex] = std::stof(tmp);
		arrIndex++;
	}


	/* CALCULATING MEAN*/
	float sum_x = 0, sum_y = 0;
	float mean_x, mean_y;

	for (int i = 0; i < SIZE; i++)
	{
		sum_x += data_x[i];
		sum_y += data_y[i];
	}

	mean_x = sum_x / SIZE;
	mean_y = sum_y / SIZE;

	std::cout << "Mean X: " << mean_x << std::endl;
	std::cout << "Mean Y: " << mean_y << std::endl;

	/* ESTIMATING B0 AND B1 */
	float b0, b1;
	float tmp1 = 0, tmp2 = 0, tmp3 = 0;
	for (int i = 0; i < SIZE; i++)
	{
		tmp1 += (data_x[i] - mean_x) * (data_y[i] - mean_y);
		tmp2 += pow((data_x[i] - mean_x), 2);
	}
	b1 = tmp1 / tmp2;
	b0 = mean_y - b1 * mean_x;

	std::cout << "B0: " << b0 << std::endl;
	std::cout << "B1: " << b1 << std::endl;

	/* SORT DATA - DESCENDING ; PRINT MEDIAN */
	bubbleSort(data_x, SIZE);
	bubbleSort(data_y, SIZE);

	float median_x, median_y;
	median_x = (data_x[SIZE / 2 - 1] + data_x[SIZE / 2]) / 2;
	median_y = (data_y[SIZE / 2 - 1] + data_y[SIZE / 2]) / 2;

	std::cout << "Median X: " << median_x << std::endl;
	std::cout << "Median Y: " << median_y << std::endl;

	/* MERGE SORT - DESCENDING */
	mergeSort(data_x, data_y, SIZE);

	return 0;
}

void displayArray(float arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i+1 << ".\t" << arr[i] << std::endl;
	}
	std::cout << std::endl;
}

void swap(float* x, float* y)
{
	float temp = *x;
	*x = *y;
	*y = temp;
}

void bubbleSort(float arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

void mergeSort(float* arr1, float* arr2, int size)
{
	float x = arr1[0];
	float y = arr2[0];
	float result[2 * SIZE];

	int i = 0, j = 0, k = 0;

	while (i < size && j < size)
	{
		if (arr1[i] >= arr2[j])
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

	std::cout << "Merged Arrays: \n";
	displayArray(result, 2 * SIZE);
}