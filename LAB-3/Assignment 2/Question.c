#include <stdio.h>


int weigh(int coins[], int l1, int r1, int l2, int r2) {
    int sum1 = 0, sum2 = 0;
    for(int i = l1; i <= r1; i++) sum1 += coins[i];
    for(int i = l2; i <= r2; i++) sum2 += coins[i];
    
    if (sum1 < sum2) return -1;
    if (sum1 > sum2) return 1;
    return 0;
}

int find_defective(int coins[], int low, int high) {
    if (low == high) return low; 

    int n = high - low + 1;
    int mid = low + (n / 2) - 1;

    if (n % 2 == 0) {
        int w = weigh(coins, low, mid, mid + 1, high);
        if (w == 0) return -1; 
        if (w == -1) return find_defective(coins, low, mid);
        return find_defective(coins, mid + 1, high);
    } else {
        int w = weigh(coins, low, mid, mid + 1, high - 1);
        if (w == 0) return high; 
        if (w == -1) return find_defective(coins, low, mid);
        return find_defective(coins, mid + 1, high - 1);
    }
}

int main() {
    int coins[] = {10, 10, 10, 9, 10, 10, 10, 10}; 
    int n = sizeof(coins) / sizeof(coins[0]);

    int defective_idx = find_defective(coins, 0, n - 1);
    if (defective_idx != -1)
        printf("Defective coin found at index: %d\n", defective_idx);
    else
        printf("No defective coin. All coins are perfect.\n");

    return 0;
}