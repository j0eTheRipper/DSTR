#ifndef __ARRAY_H_DEFINED__
#define __ARRAY_H_DEFINED__

#include "Node/Transaction.h"
#include <iostream>

template <class T> class Array {
  public:
    Array(T& item);
    Array();

    void append(T& item);
    void swap(T& a, T& b);
    void bubbleSort();
    T& operator[](int const i);
    int len();
    Array<T> mergeSort();

  private:
    int size;
    int length;
    T* array;
    void expand();
    Array<T> merge(Array<T>& left, Array<T>& right);
};

#endif
