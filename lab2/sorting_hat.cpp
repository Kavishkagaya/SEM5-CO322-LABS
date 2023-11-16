#include <iostream>

using namespace std;

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void quickSort(int array[], int start, int end)
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
        }
    }
    i++;
    swap(array, i, end);

    quickSort(array, start, i - 1);
    quickSort(array, i + 1, end);
}

void print_arr(int array[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << array[i];
        if (i < len - 1)
        {
            cout << ',';
        }
    }
    cout << endl;
}

int main()
{
    int len;

    cin >> len;

    string name[len];
    int brave[len];

    for (int i = 0; i < len; i++)
    {
        cin >> name[i];
    }

    for (int i = 0; i < len; i++)
    {
        cin >> brave[i];
    }

    cout << name[0] << endl;
    print_arr(brave, len);

    return 0;
}