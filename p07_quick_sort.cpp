
#include <iostream>
using namespace std;

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pivot = a[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (a[j] < pivot) {
                i++;

                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        int temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        int p = i + 1;

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int a[5] = {5, 3, 8, 1, 2};

    quickSort(a, 0, 4);

    cout << "Sorted array: ";

    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
