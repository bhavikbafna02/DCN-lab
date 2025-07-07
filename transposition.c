#include <stdio.h>
#include <string.h>

int main() {
    char data[100], wrd[] = "MEGABUCK";
    char cipher[20][8]; // grid size
    int seq[8], i, j, k, cnt, len = strlen(wrd);

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
    cnt = strlen(data);

    // Fill the cipher grid row-wise
    int rows = (cnt + len - 1) / len; // ceil(cnt / len)
    for (i = 0; i < rows * len; i++) {
        if (i < cnt)
            cipher[i / len][i % len] = data[i];
        else
            cipher[i / len][i % len] = '.'; // padding
    }

    // Print column-wise based on sequence
    printf("Encrypted data: ");
    for (i = 0; i < len; i++) {
        for (j = 0; j < len; j++) {
            if (seq[j] == i) break;
        }
        for (k = 0; k < rows; k++) {
            printf("%c", cipher[k][j]);
        }
    }
    printf("\n");
    return 0;
}
