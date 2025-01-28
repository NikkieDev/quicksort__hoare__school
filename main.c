#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define CURSOR_BIGGER_THAN_SIZE -1;
#define SUCCESS 0;
#define FALSE 0;
#define TRUE 1;

double avg(int *arr, size_t arr_size)
{
    int total = 0;
    for (int i = 0; i < arr_size; i++) {
        total += arr[i];
    }

    return total / arr_size;
}

signed int append(int *arr, size_t *cur, size_t size, int num) // -> make struct for arrays
{
    if ((*cur) >= size) return CURSOR_BIGGER_THAN_SIZE;
    arr[*cur] = num;
    (*cur)++;

    return SUCCESS;
}

void *part(int *arr, size_t arr_size)
{
    double average = avg(arr, arr_size);

    size_t higher_size = 0;
    size_t higher_cursor = 0;
    size_t loweq_size = 0;
    size_t loweq_cursor = 0;

    for (int i =0; i < arr_size; i++) {
        if (arr[i] > average) {
            higher_size++;
        } else {
            loweq_size++;
        }
    }

    int *higher = malloc(higher_size * sizeof(int));
    int *loweq = malloc(loweq_size * sizeof(int));

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] > average) {
            printf("Appending %d to higher than %f\n", arr[i], average);
            append(higher, &higher_cursor, higher_size, arr[i]);
        } else {
            printf("Appending %d to loweq than %f\n", arr[i], average);
            append(loweq, &loweq_cursor, loweq_size, arr[i]);
        }
    }
}

int main(void)
{
    size_t numbers_size = 6;
    int numbers[6] = { 3, 1, 12, 95, 120, 4 };

    part(numbers, numbers_size);

    // int numbers_sorted[numbers_size];

    // for (int i = 0; i < numbers_size; i++) {
    //     printf("%i. %d\n", i+1, numbers_sorted[i]);
    // }
}
