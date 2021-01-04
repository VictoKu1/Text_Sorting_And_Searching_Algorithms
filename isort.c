#include "headers.h"

//* Shifts all the cells in the array after cell arr[0] one cell to right , i.e. moves the content of cell arr[x] to arr[x+1] for each *(arr)<=x<=*(arr+i).

void shift_element(int *arr, int i)
{
    while (i >= 0)
    {
        *(arr + i + 1) = *(arr + i) + 0;
        i--;
    }
}

//* Insertion sort .

void insertion_sort(int *arr, int len)
{
    if (len == 0)
    {
        return;
    }
    int index = 0;
    int current = *arr;
    while (index < len)
    {
        index++;
        current = *(arr + index);
        current = current + 0;
        if (*(arr + index) < *(arr + index - 1))
        {
            int bound = index - 1;
            while (*(arr + bound - 1) > current && bound != 0)
            {
                bound--;
            }
            if (bound == 0)
            {
                shift_element((arr), index - 1);
                *(arr) = current;
            }
            else
            {
                shift_element((arr + bound), index - bound - 1);
                *(arr + bound) = current;
            }
        }
    }
}

//* Helper fucntion to find the right position to the searched parameter in the bounded area of the array ( from arr[0] to arr[bound] ) .

int loc(int *arr, int bound, int searched)
{
    while (*(arr + bound) > searched)
    {
        bound--;
    }
    return bound;
}

//* Main fucntion which gets 50 integers, puts them into array and sorts it using insertion_sort().

int main()
{
    int *arr = malloc(SIZOFARRAY * sizeof(int));
    int *p = arr;
    for (int i = 0; i < 50; i++)
    {
        scanf("%d", &(*(p + i)));
    }
    insertion_sort(p, 50);
    for (int i = 0; i < 50; i++)
    {
        printf("%d", *(arr + i));
        if (i < 49)
        {
            printf(",");
        }
    }
    printf("\n");
    free(arr);
}
