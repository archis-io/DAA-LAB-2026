#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

void editDistance(char *str1, char *str2, int m, int n) {
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }

    printf("Minimum Edit Distance: %d\n", dp[m][n]);
    printf("Traceback Operations:\n");

    int i = m, j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && str1[i - 1] == str2[j - 1]) {
            i--; j--;
        } else if (i > 0 && j > 0 && dp[i][j] == dp[i - 1][j - 1] + 1) {
            printf("  Replace '%c' with '%c'\n", str1[i - 1], str2[j - 1]);
            i--; j--;
        } else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
            printf("  Delete '%c'\n", str1[i - 1]);
            i--;
        } else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
            printf("  Insert '%c'\n", str2[j - 1]);
            j--;
        }
    }
}

int main() {
    char str1[] = "SUNDAY";
    char str2[] = "SATURDAY";
    printf("--- QUESTION 6: EDIT DISTANCE WITH TRACEBACK ---\n");
    printf("String 1: %s\nString 2: %s\n", str1, str2);
    editDistance(str1, str2, strlen(str1), strlen(str2));
    return 0;
}