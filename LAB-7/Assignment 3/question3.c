#include <stdio.h>
#include <math.h>

int moves_count = 0;

void hanoi3(int n, char src, char dst, char aux) {
    if (n == 0) return;
    hanoi3(n - 1, src, aux, dst);
    moves_count++;
    hanoi3(n - 1, aux, dst, src);
}

// Frame-Stewart Algorithm for 4 pegs
void reve_frame_stewart(int n, char src, char dst, char aux1, char aux2) {
    if (n == 0) return;
    if (n == 1) {
        moves_count++;
        return;
    }
    int k = n + 1 - (int)round(sqrt(2 * n + 1));
    reve_frame_stewart(k, src, aux1, aux2, dst);
    hanoi3(n - k, src, dst, aux2);
    reve_frame_stewart(k, aux1, dst, src, aux2);
}

int main() {
    int n = 8;
    moves_count = 0;
    printf("--- QUESTION 3: REVE'S PUZZLE (4 PEGS) ---\n");
    reve_frame_stewart(n, 'A', 'D', 'B', 'C');
    printf("Disks: %d, Target Pegs: 4\n", n);
    printf("Total Moves: %d\n", moves_count);
    return 0;
}