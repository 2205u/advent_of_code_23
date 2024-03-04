#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    FILE* file_ptr;
    char filename[] = "puzzle_input.txt";
    file_ptr = fopen(filename, "r");

    if (file_ptr == NULL) {
        printf("Error while reading file.\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int answer = 0;
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {

        int product;
        int red_min = INT_MIN;
        int green_min = INT_MIN; 
        int blue_min = INT_MIN;

        char *buffer_ptr = buffer;
        while (*buffer_ptr != ':') {
            buffer_ptr++;
        }
        buffer_ptr++;

        char *token_ptr = strtok(buffer_ptr, " ");
        while (token_ptr != NULL) {
            int int_token = atoi(token_ptr);
            token_ptr = strtok(NULL, " ");

            if (*token_ptr == 'r' && int_token >= red_min) {
                red_min = int_token;
            } else if (*token_ptr == 'g' && int_token >= green_min) {
                green_min = int_token;
            } else if (*token_ptr == 'b' && int_token >= blue_min) {
                blue_min = int_token;
            }
            token_ptr = strtok(NULL, " ");
        }

        product = red_min * green_min * blue_min;
        answer += product; 
    }

    printf("Answer: %d\n", answer);
}
