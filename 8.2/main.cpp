#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct SegmentTree {
    vector<int> tree;
    int n;

    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    void build(vector<int>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v*2, tl, tm);
            build(arr, v*2+1, tm+1, tr);
            tree[v] = min(tree[v*2], tree[v*2+1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return INT_MAX;
        if (l == tl && r == tr) 
            return tree[v];
        int tm = (tl + tr) / 2;
        return min(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    SegmentTree segmentTree(n);
    segmentTree.build(A, 1, 0, n-1);

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int start, end;
        cin >> start >> end;
        cout << segmentTree.query(1, 0, n-1, start, end - 1) << endl;
    }

    return 0;
}