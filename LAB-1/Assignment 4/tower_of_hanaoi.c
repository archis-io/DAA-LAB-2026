#include <stdio.h>
#include <math.h>

long move_count = 0;

void solve_toh(int n, char source, char aux, char dest) {
    if (n == 1) {
        move_count++;
        return;
    }
    solve_toh(n - 1, source, dest, aux);
    move_count++;
    solve_toh(n - 1, aux, source, dest);
}

int main() {
    printf("Disks (n)\tMoves Required (Simulated)\tTheoretical (2^n - 1)\n");
    printf("------------------------------------------------------------------\n");

    for (int n = 1; n <= 15; n++) {
        move_count = 0;
        solve_toh(n, 'A', 'B', 'C');
        long theoretical = (long)pow(2, n) - 1;
        printf("%-10d\t%-26ld\t%-20ld\n", n, move_count, theoretical);
    }

    printf("\nConclusion: Total moves follow exponential time complexity O(2^n).\n");
    return 0;
}