#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

typedef struct {
    char ch;
    int length;
    unsigned int code;
} CanonicalSymbol;

Node* createNode(char ch, int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->ch = ch;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

void getCodeLengths(Node* root, int depth, int lengths[]) {
    if (!root) return;
    if (!root->left && !root->right) {
        lengths[(unsigned char)root->ch] = depth;
        return;
    }
    getCodeLengths(root->left, depth + 1, lengths);
    getCodeLengths(root->right, depth + 1, lengths);
}

int compareCanonical(const void* a, const void* b) {
    CanonicalSymbol* s1 = (CanonicalSymbol*)a;
    CanonicalSymbol* s2 = (CanonicalSymbol*)b;
    if (s1->length != s2->length) return s1->length - s2->length;
    return s1->ch - s2->ch;
}

void printBinary(unsigned int num, int len) {
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freqs[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(chars) / sizeof(chars[0]);

    // Simple priority queue setup for Huffman tree
    Node* nodes[100];
    for (int i = 0; i < n; i++) nodes[i] = createNode(chars[i], freqs[i]);
    int size = n;

    while (size > 1) {
        // Find 2 lowest frequency nodes
        int min1 = 0, min2 = 1;
        if (nodes[min1]->freq > nodes[min2]->freq) { min1 = 1; min2 = 0; }
        for (int i = 2; i < size; i++) {
            if (nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->freq < nodes[min2]->freq) {
                min2 = i;
            }
        }
        Node* parent = createNode('$', nodes[min1]->freq + nodes[min2]->freq);
        parent->left = nodes[min1];
        parent->right = nodes[min2];

        nodes[min1] = parent;
        nodes[min2] = nodes[size - 1];
        size--;
    }

    int lengths[256] = {0};
    getCodeLengths(nodes[0], 0, lengths);

    CanonicalSymbol symbols[n];
    for (int i = 0; i < n; i++) {
        symbols[i].ch = chars[i];
        symbols[i].length = lengths[(unsigned char)chars[i]];
    }

    qsort(symbols, n, sizeof(CanonicalSymbol), compareCanonical);

    // Canonical Code Generation
    unsigned int code = 0;
    symbols[0].code = code;
    for (int i = 1; i < n; i++) {
        code = (code + 1) << (symbols[i].length - symbols[i - 1].length);
        symbols[i].code = code;
    }

    printf("--- QUESTION 2: CANONICAL HUFFMAN CODEBOOK ---\n");
    for (int i = 0; i < n; i++) {
        printf("Symbol: %c | Length: %d | Canonical Code: ", symbols[i].ch, symbols[i].length);
        printBinary(symbols[i].code, symbols[i].length);
        printf("\n");
    }
    return 0;
}