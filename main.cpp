#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <cmath>

template <typename T>
class DynamicArray {
    private:
        T* array;
        unsigned int size;
        unsigned int capacity;

    public:
        DynamicArray(unsigned int initialSize, unsigned int capacity)
        {

            if (initialSize > capacity) {
                throw std::out_of_range("Initial size exceeds array capacity");
            }

            this->size = initialSize;
            this->capacity = capacity;
            this->array = static_cast<T *>(malloc(capacity * sizeof(T)));
        }

        ~DynamicArray() {
            this->size = 0;
            this->capacity = 0;
            free(this->array);
        }

        unsigned int GetSize()
        {
            return this->size;
        }

        unsigned int GetCapacity()
        {
            return this->capacity;
        }

        T GetItem(size_t index)
        {
            if (index >= this->GetSize()) {
                throw std::out_of_range("Index exceeds array size");
            }

            return this->array[index];
        }

        void SetItem(size_t index, T val)
        {
            if (index >= this->GetCapacity()) {
                throw std::out_of_range("Index exceeds array capacity");
            }

            this->array[index] = val;
            if (index >= this->GetSize()) {
                this->size = index + 1;
            }
        }
};

int main(void) {
    DynamicArray<int> arr(2,5);
    arr.SetItem(0, 15);

    int firstItemInArray = int(arr.GetItem(0));

    for (int i = 0; i < arr.GetCapacity(); i++) {
        arr.SetItem(static_cast<size_t>(i), i+1);
    }

    printf("%d\n", firstItemInArray);

    for (int i = 0; i < arr.GetSize(); i++) {
        printf("%d\n", arr.GetItem(static_cast<size_t>(i)));
    }
}