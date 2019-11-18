#include <stdio.h>
#include <ctype.h>

int main() {
    char buf[32];
    while (scanf("%s", buf) != EOF) {
        buf[0] = toupper(buf[0]);
        for (int i = 1; buf[i]; i++)
            buf[i] = tolower(buf[i]);
        printf("%s ", buf);
    }
    return 0;
}