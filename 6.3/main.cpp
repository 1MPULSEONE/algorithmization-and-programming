#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int w, h, n;
    scanf("%d %d %d", &n, &w, &h);
    int left = max(w, h);
    int right = left * n;

    while (right - left > 1) {
        int mid = (right + left) / 2;
        int res = (mid / w) * (mid / h);
        if (res < n) {
            left = mid;
        } else {
            right = mid;
        }
    }

    printf("%d\n", right);

    return 0;
}