#include <stdio.h>

struct Pair {
    int min;
    int max;
};

struct Pair get_min_max(int arr[], int low, int high) {
    struct Pair result, left, right;
    
    
    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }
    
    
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            result.max = arr[low];
            result.min = arr[high];
        } else {
            result.max = arr[high];
            result.min = arr[low];
        }
        return result;
    }
    
    
    int mid = low + (high - low) / 2;
    left = get_min_max(arr, low, mid);
    right = get_min_max(arr, mid + 1, high);
    
    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;
    
    return result;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    struct Pair minmax = get_min_max(arr, 0, n - 1);
    printf("Minimum element is %d\n", minmax.min);
    printf("Maximum element is %d\n", minmax.max);
    
    return 0;
}