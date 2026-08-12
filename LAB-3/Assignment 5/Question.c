#include <stdio.h>

int main() {
    
    int A1 = 5, A2 = 3; 
    int B1 = 4, B2 = 2;
  
    int C1_std = A1 * B1 + A2 * B2; // 20 + 6 = 26
    int C2_std = A1 * B2 + A2 * B1; // 10 + 12 = 22
    
   
    int X = (A1 + A2) * (B1 + B2); // 8 * 6 = 48
    int Y = (A1 - A2) * (B1 - B2); // 2 * 2 = 4
    
    int C1_fast = (X + Y) / 2;     // 52 / 2 = 26
    int C2_fast = (X - Y) / 2;     // 44 / 2 = 22
    
    printf("Standard: C1=%d, C2=%d\n", C1_std, C2_std);
    printf("Fast D&C: C1=%d, C2=%d\n", C1_fast, C2_fast);
    printf("Both match! And we only used 2 multiplications!\n");
    
    return 0;
}