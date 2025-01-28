#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define CURSOR_BIGGER_THAN_SIZE -1
#define SUCCESS 0
#define FALSE 0
#define TRUE 1

double avg(int *arr, size_t arr_size)
{
    int total = 0;
    for (int i = 0; i < arr_size; i++) {
        total += arr[i];
    }

    return (double)total / arr_size;
}

signed int append(int *arr, size_t *cur, size_t size, int num) // -> make struct for arrays
{
    if ((*cur) >= size) return CURSOR_BIGGER_THAN_SIZE;
    arr[*cur] = num;
    (*cur)++;

    return SUCCESS;
}

void *part(int *arr, size_t arr_size, int *buf, size_t buf_size)
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

    size_t buf_cursor = 0;
    for (int i = 0; i < loweq_size; i++) {
        append(sorted, &sorted_cursor, sorted_size, loweq[i]);
    }

    if (higher_size > 0) {
        int *new_arr = part(higher, higher_size);
        size_t new_arr_size = 0;

        for (int i = 0; i < sizeof(*new_arr) / sizeof(new_arr[0]); i++) {
            new_arr_size++;
        }

        for (int i = 0; i < new_arr_size; i++) {
            append(buf, &sorted_cursor, buf_size, new_arr[i]);
        }
    }


    free(higher);
    free(loweq);
}

int main(void)
{
    size_t numbers_size = 6;
    int numbers[6] = { 3, 1, 12, 95, 120, 4 };
    int *arr = malloc(6);

    part(numbers, numbers_size, arr);

    for (int i = 0; i < numbers_size; i++) {
        printf("%d\n", arr[i]);
    }
}
