#include <iostream>


int Partition(int *array, int start, int end) {

    int pivot = array[end];
    int partitionIndex = start;
    int temp1, temp2;

    for (int i = start; i < end; i++) {
        if (array[i] <= pivot) {
            temp1 = array[i];
            temp2 = array[partitionIndex];
            array[i] = temp2;
            array[partitionIndex] = temp1;
            partitionIndex++;
        }
    }

    temp1 = array[partitionIndex];
    temp2 = array[end];
    array[end] = temp1;
    array[partitionIndex] = temp2;

    return partitionIndex;
}

void QuickSort(int *array, int start, int end) {

    if (start < end) {

        int partitionIndex = Partition(array, start, end);
        QuickSort(array, start, partitionIndex - 1);
        QuickSort(array, partitionIndex + 1, end);

    }
}

int main() {

    int array[] = {7, 2, 1, 6, 8, 5, 3, 4};
    QuickSort(array, 0, 7);
    for (int i : array) {
        std::cout << i << ' ';
    }

    return 0;
}