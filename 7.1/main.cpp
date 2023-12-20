#include <iostream>
#include <vector>
#include <limits.h>
#include <string>

using namespace std;

void start(const vector<int> &field, size_t n, size_t m)
{

    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n + 1; i++)
    {
        matrix[i][0] = INT_MIN;
    }
    for (int j = 0; j < m + 1; j++)
    {
        matrix[0][j] = INT_MIN;
    }

    matrix[1][1] = field[0];

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (i != 1 || j != 1)
            {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]) + field[(i - 1) * m + (j - 1)];
            }
        }
    }

    cout << "Максимальное количество монет: " << matrix[n][m] << endl;
    string path = "";
    int i = n;
    int j = m;
    while (i > 1 || j > 1)
    {
        if (matrix[i - 1][j] > matrix[i][j - 1])
        {
            path.insert(0, "D");
            i--;
        }
        else
        {
            path.insert(0, "R");
            j--;
        }
    }
    cout << path;
}

int main()
{
    size_t n, m;
    cin >> n >> m;

    vector<int> field(n * m);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> field.at(i * m + j);
        }
    }

    start(field, n, m);

    return 0;
}