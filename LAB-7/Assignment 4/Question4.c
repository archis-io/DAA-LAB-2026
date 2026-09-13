#include <stdio.h>

int switch_moves = 0;

void turn_off(int n);
void turn_on(int n);

void turn_off(int n) {
    if (n <= 0) return;
    if (n == 1) {
        switch_moves++;
        return;
    }
    turn_off(n - 2);
    switch_moves++;
    turn_on(n - 2);
    turn_off(n - 1);
}

void turn_on(int n) {
    if (n <= 0) return;
    if (n == 1) {
        switch_moves++;
        return;
    }
    turn_on(n - 1);
    turn_off(n - 2);
    switch_moves++;
    turn_on(n - 2);
}

int main() {
    int n = 4;
    switch_moves = 0;
    printf("--- QUESTION 4: SECURITY SWITCHES ---\n");
    turn_off(n);
    printf("Switches (n): %d\n", n);
    printf("Minimum Toggles to Turn Off All: %d\n", switch_moves);
    return 0;
}