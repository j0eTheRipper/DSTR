#include "Array.h"
template class Array<Transaction>;

template <typename T> Array<T>::Array(T& item) {
    array = new T[1];
    array[0] = item;
    size = 1;
    length = 1;
}

template <typename T> Array<T>::Array() {
    array = new T[1];
    size = 1;
    length = 0;
}

template <typename T> void Array<T>::expand() {
    T* newArr = new T[size * 2];
    for (int i = 0; i < size; i++) {
        newArr[i] = array[i];
    }
    delete[] array;
    array = newArr;
    size = size * 2;
}

template <typename T> void Array<T>::swap(T& a, T& b) {
    T c = a;
    a = b;
    b = c;
}

template <typename T> void Array<T>::append(T& item) {
    if (length == size) {
        expand();
    }

    array[length] = item;
    length += 1;
}

template <typename T> int Array<T>::len() { return length; }

template <typename T> T& Array<T>::operator[](int const i) { return array[i]; }

template <typename T> void Array<T>::bubbleSort() {
    for (int i = 0; i < length; i++) {
        T& a = array[i];
        for (int j = i + 1; j < length; j++) {
            T& b = array[j];
            if (a < b) {
                this->swap(a, b);
            }
        }
    }
}

template <typename T> Array<T> Array<T>::mergeSort() {
    if (length <= 1) {
        return *this;
    }

    int mid = length / 2;
    Array<T> left, right;

    for (int i = 0; i < mid; i++) {
        left.append((*this)[i]);
    }
    for (int i = mid; i < length; i++) {
        right.append((*this)[i]);
    }

    Array<T> sortedLeft = left.mergeSort();
    Array<T> sortedRight = right.mergeSort();
    return merge(sortedLeft, sortedRight);
}

template <typename T>
Array<T> Array<T>::merge(Array<T>& left, Array<T>& right) {
    Array<T> result;

    int leftCounter = 0;
    int rightCounter = 0;

    while (rightCounter < right.len() && leftCounter < left.len()) {
        if (left[leftCounter] > right[rightCounter]) {
            result.append(left[leftCounter]);
            leftCounter++;
        } else {
            result.append(right[rightCounter]);
            rightCounter++;
        }
    }

    while (rightCounter < right.len()) {
        result.append(right[rightCounter]);
        rightCounter++;
    }
    while (leftCounter < left.len()) {
        result.append(left[leftCounter]);
        leftCounter++;
    }
    return result;
}

template <typename T> int Array<T>::findByDate(const T& target) {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (array[mid] == target) {
            return mid;
        } else if (array[mid] > target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Not found
}

template <typename T> int Array<T>::find(bool (*filter)(T& a)) {
    T fallback = T();
    int count = 0;
    for (int i = 0; i < length; i++) {
        T b = array[i];
        if (filter(b)) {
            count++;
        }
    }
    return count;
}
