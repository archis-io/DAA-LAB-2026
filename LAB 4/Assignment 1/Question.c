#include <stdio.h>
#include <stdlib.h>

typedef enum { RED = 0, BLUE = 1, YELLOW = 2 } Color;

typedef struct {
    int number;
    Color color;
} Item;

void count_sort_by_color(Item arr[], int n) {
    Item output[n];
    int count[3] = {0, 0, 0};

    for (int i = 0; i < n; i++) count[arr[i].color]++;
    count[1] += count[0];
    count[2] += count[1];

    // Traverse backwards to maintain STABILITY
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i].color] - 1] = arr[i];
        count[arr[i].color]--;
    }

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

int main() {
    Item arr[] = {
        {10, BLUE}, {15, RED}, {20, YELLOW}, {25, RED}, {30, BLUE}, {35, YELLOW}
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    count_sort_by_color(arr, n);

    char *color_names[] = {"Red", "Blue", "Yellow"};
    for (int i = 0; i < n; i++) {
        printf("Color: %-6s | Number: %d\n", color_names[arr[i].color], arr[i].number);
    }
    return 0;
}