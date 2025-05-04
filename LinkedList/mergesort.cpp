#include <iostream>
using namespace std;

int* split(int*, int);
int* mergeSort(int*, int, int*, int);

int main(int argc, char* argv[]) {
    cout << "hello" << endl;
    int arr[] = {6, 4, 7, 3, 7, 1, 9, 8, 3, 2};
    int* srtedArr = split(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < 10; i++) {
        cout << srtedArr[i] << " ";
    }
    return 0;
}

int* split(int* arr, int length) {
    if (length == 1) {
        return arr;
    } // base condition

    int leftLength = length / 2;
    int rightLength = leftLength;
    if (length % 2 != 0)
        rightLength = leftLength + 1; // to account for non-even arrays

    int* leftArr = new int[leftLength];
    int* rightArr = new int[rightLength];

    for (int i = 0; i < length; i++) {
        if (i < length / 2)
            leftArr[i] = arr[i];
        else
            rightArr[i - (length / 2)] = arr[i];
    }

    leftArr = split(leftArr, leftLength);
    rightArr = split(rightArr, rightLength);
    arr = mergeSort(leftArr, leftLength, rightArr, rightLength);

    return arr;
}

int* mergeSort(int* leftArr, int leftLength, int* rightArr, int rightLength) {
    int fullLength = leftLength + rightLength;
    int* result = new int[fullLength];

    int rightCounter = 0;
    int leftCounter = 0;
    int resultCounter = 0;

    while (resultCounter < fullLength && rightCounter < rightLength &&
           leftCounter < leftLength) {
        if (leftArr[leftCounter] < rightArr[rightCounter]) {
            result[resultCounter] = leftArr[leftCounter];
            leftCounter++;
        } else {
            result[resultCounter] = rightArr[rightCounter];
            rightCounter++;
        }
        resultCounter++;
    }

    if (rightCounter < rightLength) {
        while (rightCounter < rightLength) {
            result[resultCounter] = rightArr[rightCounter];
            rightCounter++;
            resultCounter++;
        }
    } else if (leftCounter < leftLength) {
        while (leftCounter < leftLength) {
            result[resultCounter] = leftArr[leftCounter];
            leftCounter++;
            resultCounter++;
        }
    }

    for (int i = 0; i < fullLength; i++)
        cout << result[i] << " ";
    cout << endl;
    return result;
}
