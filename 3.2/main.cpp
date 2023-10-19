#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int getDigit(int num, int i)
{
    return (num / static_cast<int>(pow(10, i - 1))) % 10;
}

void radixSort(vector<int> &a)
{
    const int digits = 20;
    for (int exp = 1; exp <= digits; exp++)
    {
        vector<int> count(10, 0);
        vector<int> output(a.size());

        for (int i = 0; i < a.size(); i++)
        {
            int digit = getDigit(a[i], exp);
            count[digit]++;
        }

        for (int i = 1; i < count.size(); i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = a.size() - 1; i >= 0; i--)
        {
            int digit = getDigit(a[i], exp);
            output[count[digit] - 1] = a[i];
            count[digit]--;
        }

        for (int i = 0; i < a.size(); i++)
        {
            a[i] = output[i];
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    radixSort(a);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}