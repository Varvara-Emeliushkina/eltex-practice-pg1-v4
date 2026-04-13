#include<stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Использование: %s <строка1> <строка2> ... <строкаN>\n", argv[0]);
        return 1;
    }

    printf("\nРезультат склеивания: ");
    for (int i = 1; i < argc; i++) {
        printf("%s", argv[i]);
    }
    printf("\n");

    return 0;
}