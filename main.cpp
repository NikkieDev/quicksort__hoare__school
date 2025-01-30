#include <stdio.h>
#include <iostream>

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
                throw "Size out of capacity bounds";
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

        void IncreaseCapacity(unsigned int extraCapacity)
        {
            this->capacity += extraCapacity;
        }

        unsigned int GetSize()
        {
            return this->size;
        }

        T GetItem(size_t index)
        {
            if (static_cast<int>(index) >= this->size) {
                throw std::out_of_range("Index exceeds array size");
            }

            return static_cast<T>(this->array[index]);
        }

        void SetItem(size_t index, T val)
        {
            if (static_cast<int>(index) >= this->size) {
                throw std::out_of_range("Index exceeds array capacity");
            }

            this->array[index] = val;
        }

};

int main(void) {
    DynamicArray<int> arr(2,5);
    arr.SetItem(0, 15);

    int firstItemInArray = static_cast<int>(arr.GetItem(0));

    printf("%d\n", firstItemInArray);
}