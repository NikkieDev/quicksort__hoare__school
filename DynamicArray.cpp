#include "DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray(unsigned int initialSize, unsigned int capacity)
{
    if (initialSize > capacity) {
        throw std::out_of_range("Initial size exceeds max size");
    }

    this->size = initialSize;
    this->capacity = capacity;
    this->array = static_cast<T*>(malloc(capacity * sizeof(T)));
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    this->size = 0;
    this->capacity = 0;
    free(this->array);
}

template <typename T>
unsigned int DynamicArray<T>::GetSize()
{
    return this->size;
}

template <typename T>
T DynamicArray<T>::GetItem(size_t index)
{
    if (index >= this->GetSize()) {
        throw std::out_of_range("Index exceeds array max size");
    }

    return this->array[index];
}

