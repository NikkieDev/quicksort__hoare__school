#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <typename T>
class DynamicArray {
    private:
        T* array;
        unsigned int size;
        unsigned int capacity;

    public:
        DynamicArray(unsigned int initialSize, unsigned int capacity);
        ~DynamicArray();
        unsigned int GetSize();
        unsigned int GetCapacity();
        T GetItem(size_t index);
        void SetItem(size_t index, T value);
};

#endif