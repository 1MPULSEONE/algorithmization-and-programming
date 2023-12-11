#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int closestBinarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    int closest = INT_MAX;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x) {
            return arr[mid];
        }

        if (abs(arr[mid] - x) < abs(closest - x)) {
            closest = arr[mid];
        }

        if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return closest;
}

int main() {
    int n, m;
    scanf("%d", &n);
    
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int query;
        scanf("%d", &query);
        int closest = closestBinarySearch(arr, n, query);
        printf("%d ", closest);
    }

    free(arr);

    return 0;
}