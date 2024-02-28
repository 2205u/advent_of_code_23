    // traverse line from front till first digit
    // save x =first digit*10
    // traverse line from back till first digit
    // add digit to x
    // add to sum
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int sum = 0;

    FILE* fptr;
    char filename[] = "puzzle_input.txt";
    char buffer[256];

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        int value = 0; 

        for (int i = 0; i < strlen(buffer); i++) {
            if (isdigit(buffer[i])) {
                value += (buffer[i] - '0') * 10; // Convert ASCII value to decimal integer by subtracting ASCII value 48
                break;
            }
        }

        for (int j = strlen(buffer) - 1; j >= 0; j--) {
            if (isdigit(buffer[j])) {
                value += buffer[j] - '0';
                break;
            }
        }

        sum += value;
    }

    printf("%d\n", sum);
    
    return 0;
}
