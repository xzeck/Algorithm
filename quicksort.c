
#include <stdio.h>
#include <conio.h>


#pragma warning(disable : 4996)
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int data[], int low, int high)
{
	int pivot = data[high];
	int i = low - 1;

	for (int j = low; j <= high-1; j++)
	{
		if (data[j] <= pivot)
		{
			i++;
			swap(&data[i], &data[j]);
		}
	}
	swap(&data[i + 1], &data[high]);
	return i+1;
}

void quicksort(int data[], int low, int high)
{ 
	if (low < high)
	{
		int p = partition(data, low, high);

		quicksort(data, low, p - 1);
		quicksort(data, p + 1, high);
	}
}

int main()
{
	int data[100];  //Array to hold size, holds 100 elements
	int n; // used to store the size of the array

	printf("\nEnter the number of elements");
	scanf("%d", &n);

	if (n > 99) //preventing buffer overflow by checking if n is greater than the array size
		return -1;

	for (int i = 0; i < n; i++)
	{
		printf("\nEnter element no %d : ", i);
		scanf("%d", &data[i]);
	}

	quicksort(data, 0, n - 1);


	printf("\nThe sorted elements are : ");

	for (int i = 0; i < n; i++)
	{
		printf("\n%d", data[i]);

	}
}
