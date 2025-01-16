#define CURSOR_BIGGER_THAN_SIZE -1;

double avg(int *arr, size_t arr_size)
{
    int total = 0;
    for (int i = 0; i < arr_size; i++) {
        total += arr[i];
    }

    return total / arr_size;
}

signed int append(int *arr, size_t *cur, size_t size, int num)
{
    if ((*cur) > size) return CURSOR_BIGGER_THAN_SIZE;
    arr[*cur] = num;
    (*cur)++;

    return 0;
}

void *part(int *arr, size_t arr_size)
{
    int arr_filling = 0;
    double average = avg(arr, arr_size);

    size_t higher_size = 0;
    size_t higher_cursor = 0;
    size_t loweq_size = 0;
    size_t loweq_cursor = 0;

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] > averge) {
            higher_size++;
            if (arr_filling) {
                append(higher, &higher_cursor, higher_size, arr[i]);
            }
        } else {
            if (arr_filling) {
                append(loweq, &loweq_cursor, loweq_size, arr[i]);
            }
            loweq_size++;
        }

        if (i == arr_size && !arr_filling) {
            i = 0;
            arr_filling = 1;
        }
    }
}

int main(void)
{
    size_t numbers_size = 6;
    int numbers[6] = { 3, 1, 12, 95, 120, 4 };

    int numbers_sorted[arr_size] = malloc(sizeof(int) * arr_size);

    

    for (int i = 0; i < arr_size; i++) {
        printf("%i. %d\n", i+1, numbers_sorted[i]);
    }

    free(numbers_sorted);
}