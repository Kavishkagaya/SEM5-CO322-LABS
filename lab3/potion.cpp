// E/19/309
// E/19/452

#include <iostream>

using namespace std;

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void quickSort(int array[], int index[], int start, int end)
{
    if (end <= start)
        return;

    int pivot = array[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
    {
        if (pivot > array[j])
        {
            i++;
            swap(array, i, j);
            swap(index, i, j);
        }
    }
    i++;
    swap(array, i, end);
    swap(index, i, end);

    quickSort(array, index, start, i - 1);
    quickSort(array, index, i + 1, end);
}

int binarySearch(int *array, int start, int end, int value)
{
    int mid = start + (end - start) / 2;
    if (start >= end)
        return -1;
    if (array[mid] == value)
        return mid;
    if (array[mid] < value)
        return binarySearch(array, mid + 1, end, value);
    else
        return binarySearch(array, start, mid - 1, value);
}

int main()
{
    int value;
    int len;

    cin >> value >> len;

    int arr[len];
    int index[len];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
        index[i] = i;
    }

    quickSort(arr, index, 0, len - 1);
    if (int ind = binarySearch(arr, 0, len - 1, value))
        cout << "Bicorn Horn is present at index " << index[ind] << endl;

    return 0;
}