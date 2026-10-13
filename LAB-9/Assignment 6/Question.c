#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int freq;
} CharFreq;

typedef struct {
    CharFreq item;
    int availableIndex;
} QueueItem;

void rearrangeKDistance(char *str, int k) {
    int n = strlen(str);
    int freqMap[256] = {0};
    for (int i = 0; i < n; i++) freqMap[(unsigned char)str[i]]++;

    CharFreq heap[256];
    int heap_size = 0;
    for (int i = 0; i < 256; i++) {
        if (freqMap[i] > 0) {
            heap[heap_size].ch = (char)i;
            heap[heap_size].freq = freqMap[i];
            heap_size++;
        }
    }

    // Sort initial heap by frequency descending
    for (int i = 0; i < heap_size - 1; i++) {
        for (int j = i + 1; j < heap_size; j++) {
            if (heap[i].freq < heap[j].freq) {
                CharFreq temp = heap[i]; heap[i] = heap[j]; heap[j] = temp;
            }
        }
    }

    QueueItem coolingQueue[256];
    int q_front = 0, q_back = 0;

    char result[n + 1];
    result[n] = '\0';

    for (int i = 0; i < n; i++) {
        // Re-insert cooled characters into active candidate pool
        if (q_front < q_back && coolingQueue[q_front].availableIndex <= i) {
            heap[heap_size++] = coolingQueue[q_front++].item;
            // Maintain frequency order
            for (int x = heap_size - 1; x > 0 && heap[x].freq > heap[x - 1].freq; x--) {
                CharFreq temp = heap[x]; heap[x] = heap[x - 1]; heap[x - 1] = temp;
            }
        }

        if (heap_size == 0) {
            printf("Rearrangement Impossible for K = %d!\n", k);
            return;
        }

        CharFreq top = heap[0];
        // Shift heap
        for (int x = 0; x < heap_size - 1; x++) heap[x] = heap[x + 1];
        heap_size--;

        result[i] = top.ch;
        top.freq--;

        if (top.freq > 0) {
            coolingQueue[q_back].item = top;
            coolingQueue[q_back].availableIndex = i + k;
            q_back++;
        }
    }

    printf("Rearranged String (K = %d): %s\n", k, result);
}

int main() {
    char str[] = "aabbcc";
    int k = 3;

    printf("--- QUESTION 6: REORGANIZE STRING K-DISTANCE APART ---\n");
    printf("Original String: %s | K = %d\n", str, k);
    rearrangeKDistance(str, k);
    return 0;
}