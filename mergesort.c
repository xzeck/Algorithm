#include <stdio.h> 
#include <conio.h>

void merge(int data[], int l, int m, int r)
{
    int i, j, k;

    int n1 = (m - l) + 1; 
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for(i = 0;i < n1; i++)
        L[i] = data[l + i];
    for(j = 0; j< n2; j++)
        R[j] = data[m + 1 + j];

    i = 0; 
    j = 0;
    k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] < R[j])
        {
            data[k] = L[i];
            i++;
        }
        else 
        {
            data[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        data[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        data[k] = R[j];
        j++;
        k++;
    }    
}

void mergeSort(int data[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(data, l, m);
        mergeSort(data, m+1, r);

        merge(data, l, m, r);
    }
}

void printData(int data[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("\n%d", data[i]);
    }
}


int main()
{

    int data[100]; 
    int n; 

    printf("\nEnter the number of elemtns");
    scanf("%d", &n);

    for(int i =0; i < n ; i++)
    {
        scanf("%d",  &data[i]);
    }

    printf("\nBefore sorting : ");
    printData(data, n);

    mergeSort(data, 0, n);

    printf("\nAfter sorting : ");
    printData(data, n);

}