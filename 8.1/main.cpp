#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> prefixSum(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (i == 0) {
            prefixSum[i] = A[i];
        } else {
            prefixSum[i] = prefixSum[i - 1] + A[i];
        }
    }
    
    int k;
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        int start, end;
        cin >> start >> end;
        if (start == 0) {
            cout << prefixSum[end] << endl;
        } else {
            cout << prefixSum[end] - prefixSum[start - 1] << endl;
        }
    }

    return 0;
}