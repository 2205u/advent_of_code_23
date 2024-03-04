#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 2560

int main() {
    FILE* file_ptr;
    char filename[] = "puzzle_input.txt";
    file_ptr = fopen(filename, "r");

    if (file_ptr == NULL) {
        printf("Error while reading file.\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int game_count = 0;
    int answer = 0;
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        int flag = 0;
        game_count++;

        char *buffer_ptr = buffer;
        while (*buffer_ptr != ':') {
            buffer_ptr++;
        }
        buffer_ptr++;

        char *token_ptr = strtok(buffer_ptr, " ");
        while (token_ptr != NULL) {
            int int_token = atoi(token_ptr);

            if (int_token > 12) {
                token_ptr = strtok(NULL, " ");
                if (*token_ptr == 'r') {
                    flag = 1;
                }
                else if (*token_ptr == 'b' && int_token > 14) {
                    flag = 1;
                }
                else if (*token_ptr == 'g' && int_token > 13) {
                    flag = 1;
                }
            }
            token_ptr = strtok(NULL, " ");
        }

        if (!flag) {
            answer += game_count;
        }
    }

    printf("%d", answer);

}
