#ifndef __ARRAY_H_DEFINED__
#define __ARRAY_H_DEFINED__

template <class T> class Array {
  public:
    Array(T& item);
    Array();

    void append(T& item);
    void bubbleSort();
    T& operator[](int const i);
    int findByDate(const T& target);
    int find(bool (*filter)(T& a));
    int find(T& a);
    int len();
    Array<T> mergeSort();

  private:
    int size;
    int length;
    T* array;
    void expand();
    Array<T> merge(Array<T>& left, Array<T>& right);
    void swap(T& a, T& b);
};

#endif
