#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != '\n') putchar(c);
    printf("\n%i", EOF);
    printf("\n%i", (EOF == -1));
    return 0;
}
