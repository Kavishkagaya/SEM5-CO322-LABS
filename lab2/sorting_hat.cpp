#include <iostream>

using namespace std;

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void swap(string array[], int i, int j)
{
    string temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void quickSort(int array[], string name[], int start, int end)
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
            swap(name, i, j);
        }
    }
    i++;
    swap(array, i, end);
    swap(name, i, end);

    quickSort(array, name, start, i - 1);
    quickSort(array, name, i + 1, end);
}

void print_arr(int array[], int len)
{
    cout << '[';
    for (int i = len - 1; i >= 0; i--)
    {
        cout << array[i];
        if (i != 0)
        {
            cout << ", ";
        }
    }
    cout << ']';
    cout << endl;
}

void print_arr(string array[], int len)
{
    cout << '[';
    for (int i = len - 1; i >= 0; i--)
    {
        cout << '\'' << array[i] << '\'';
        if (i != 0)
        {
            cout << ", ";
        }
    }
    cout << ']';
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

    quickSort(brave, name, 0, len - 1);

    print_arr(name, len);
    print_arr(brave, len);

    for (int i = len - 1; i >= 0; i--)
    {
        if (i < len - 5)
            break;
        if (brave[i] > 500)
            cout << name[i] << endl;
    }

    return 0;
}