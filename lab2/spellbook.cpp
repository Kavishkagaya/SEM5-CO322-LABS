#include <iostream>

using namespace std;

int max(int val1, int val2)
{
    if (val1 > val2)
        return val1;
    else
        return val2;
}

int main()
{
    int p, q;
    cin >> p >> q;

    int l[p], m[q], LCS[p][q];

    for (int i = 0; i < p; i++)
    {
        cin >> l[i];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> m[i];
    }

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            if (l[i] == m[j])
            {
                if (i == 0 || j == 0)
                    LCS[i][j] = 1;
                else
                    LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else
            {
                if (i == 0 && j == 0)
                    LCS[i][j] = 0;
                else if (i == 0)
                    LCS[i][j] = LCS[i][j - 1];
                else if (j == 0)
                    LCS[i][j] = LCS[i - 1][j];
                else
                    LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    // for (int i = 0; i < p; i++)
    // {
    //     for (int j = 0; j < q; j++)
    //     {
    //         cout << LCS[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int len = p > q ? p : q;
    int arr[len];
    int i = p - 1, j = q - 1, index = 0;

    while (LCS[i][j] != 0 && i >= 0 && j >= 0)
    {
        if (LCS[i - 1][j] == LCS[i][j])
        {
            i--;
        }
        else if (LCS[i][j] == LCS[i][j - 1])
        {
            j--;
        }
        else if (LCS[i - 1][j - 1] < LCS[i][j])
        {
            arr[index] = m[j];
            index++;
            j--;
            i--;
        }
        else
        {
            arr[index] = m[j];
            index++;
            break;
        }
    }

    for (int i = index - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    return 0;
}