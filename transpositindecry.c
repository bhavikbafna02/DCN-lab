#include <stdio.h>
#include <string.h>

int main() {
    char data[100], wrd[] = "MEGABUCK";
    char cipher[20][8];
    int seq[8], i, j, k, len = strlen(wrd);

    // Generate transposition sequence
    for (i = 0; i < len; i++) {
        seq[i] = 0;
        for (j = 0; j < len; j++) {
            if (wrd[i] > wrd[j]) seq[i]++;
        }
    }

    printf("Enter data: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';

    int cnt = strlen(data);
    if (cnt % len != 0) {
        printf("Error: Invalid input length.\n");
        return 1;
    }

    int rows = cnt / len;

    // Fill the cipher grid column-wise based on seq
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            if (seq[j] == i) break;
        }
        for (k = 0; k < rows; k++) {
            cipher[k][j] = data[i * rows + k];
        }
    }

    // Display row-wise
    printf("Decrypted data: ");
    for (i = 0; i < rows * len; i++) {
        if (cipher[i / len][i % len] != '.')
            printf("%c", cipher[i / len][i % len]);
    }
    printf("\n");
    return 0;
}
