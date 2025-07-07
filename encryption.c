#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char seq[36] = "qwertyuiopasdfghjklzxcvbnm1234567890";
    char data[100], encoded[100];
    int i, len;

    printf("Enter data: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0'; // remove newline

    len = strlen(data);
    for (i = 0; i < len; i++) {
        if (isupper(data[i]))
            encoded[i] = toupper(seq[data[i] - 'A']);
        else if (islower(data[i]))
            encoded[i] = seq[data[i] - 'a'];
        else if (isdigit(data[i]))
            encoded[i] = seq[data[i] - '0' + 26];
        else
            encoded[i] = data[i]; // keep other chars as-is
    }
    encoded[len] = '\0';
    printf("Encoded string is: %s\n", encoded);
    return 0;
}