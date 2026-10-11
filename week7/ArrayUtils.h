
#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

namespace ArrayUtils {

    int* createArray(int size, int initialValue);

    void updateElement(int* arr, int size,
                       int index, int value);

    int findMax(const int* arr, int size);

    int sumArray(const int* arr, int size);

    void destroyArray(int*& arr);

}

#endif
