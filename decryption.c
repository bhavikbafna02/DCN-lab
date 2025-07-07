#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char seq[36] = "qwertyuiopasdfghjklzxcvbnm1234567890";
    char data[100], decoded[100];
    int i, j, len, found;

    printf("Enter data: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0';

    len = strlen(data);
    for (i = 0; i < len; i++) {
        found = 0;
        for (j = 0; j < 36; j++) {
            if (tolower(data[i]) == seq[j]) {
                if (j < 26) {
                    decoded[i] = isupper(data[i]) ? ('A' + j) : ('a' + j);
                } else {
                    decoded[i] = '0' + (j - 26);
                }
                found = 1;
                break;
            }
        }
        if (!found) {
            decoded[i] = data[i];
        }
    }
    decoded[len] = '\0';
    printf("Decoded string is: %s\n", decoded);
    return 0;
}

