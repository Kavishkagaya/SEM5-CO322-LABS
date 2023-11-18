#include <iostream>

#define ll long

using namespace std;

ll fib(ll num, ll mem[])
{
    if (num <= 2)
        return 1;
    if (mem[num])
        return mem[num];

    mem[num] = fib(num - 1, mem) + fib(num - 2, mem);
    cout << mem[num] << " " << num << endl;
    return mem[num];
}

int main()
{
    int cases;
    cin >> cases;

    ll *mem = new ll[200000000]();
    int numbers[cases];
    for (int i = 0; i < cases; i++)
    {
        cin >> numbers[i];
    }

    for (int i = 0; i < cases; i++)
    {
        cout << fib(fib(numbers[i], mem), mem) << endl;
    }

    return 0;
}