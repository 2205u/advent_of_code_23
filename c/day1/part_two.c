#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#define SUCCESS 0
#define FALSE 0
#define TRUE 1
#define ERR 1
#define TENS_PLACE_MODIFIER 10
#define BUFFER_SIZE 256
#define ASCII_VALUE_48 '0' 

int isLongerThan(int length_to_check, int index, ulong strlen) {
    if ((strlen - index) >= length_to_check) {
        return TRUE;
    }

    return FALSE;
}

char *strrev(char *str)
{
    if (!str || ! *str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

int match_word_reverse(int i, char buffer[]) {
    switch (buffer[i]) {

        case 'r': // Possible matches: four
            if (isLongerThan(4, i, strlen(buffer))) {
                int word_length = 4;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "ruof")) {
                    return 4;
                }
            }

            return -1;
            break;

        case 'x':
            if (isLongerThan(3, i, strlen(buffer))) {
                int word_length = 3;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "xis")) {
                    return 6;
                }
            }

            return -1;
            break;

        case 'e':
            if (isLongerThan(5, i, strlen(buffer))) {
                int word_length = 5;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "eerht")) {
                    return 3;
                }

            } 
            if (isLongerThan(4, i, strlen(buffer))) {
                int word_length = 4;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "enin")) {
                    return 9;
                } else if (!strcmp(word, "evif")) {
                    return 5;
                }
            } 
            if (isLongerThan(3, i, strlen(buffer))) {
                int word_length = 3;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "eno")) {
                    return 1;
                }
            }

            return -1;
            break;

        case 'n':
            if (isLongerThan(5, i, strlen(buffer))) {
                int word_length = 5;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "neves")) {
                    return 7;
                }
            } 
            if (isLongerThan(3, i, strlen(buffer))) {
                int word_length = 3;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "net")) {
                    return 10;
                }
            }

            return -1;
            break;

        case 'o':
            if (isLongerThan(3, i, strlen(buffer))) {
                int word_length = 3;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "owt")) {
                    return 2;
                }
            }
            return -1;
            break;

        case 't':
            if (isLongerThan(5, i, strlen(buffer))) {
                int word_length = 5;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "thgie")) {
                    return 8;
                }
            }
            return -1;
            break;


        default:
            return -1;
            break;
    }
}

int match_word(int i, char buffer[]) {
    switch (buffer[i]) {

        case 'o': // Possible matches: one

            if (isLongerThan(3, i, strlen(buffer))) {
                int word_length = 3;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "one")) {
                    return 1;
                }
            }

            return -1;
            break;

        case 'f': // Possible matches: four, five

            if (isLongerThan(4, i, strlen(buffer))) {
                int word_length = 4;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "four")) {
                    return 4;
                } else if (!strcmp(word, "five")) {
                    return 5;
                }
            }

            return -1;
            break;

        case 's':
            if (isLongerThan(3, i, strlen(buffer))) {
                int word_length = 3;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "six")) {
                    return 6;
                }
            } 
            if (isLongerThan(5, i, strlen(buffer))) {
                int word_length = 5;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "seven")) {
                    return 7;
                }
            }

            return -1;
            break;

        case 'e':
            if (isLongerThan(5, i, strlen(buffer))) {
                int word_length = 5;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "eight")) {
                    return 8;
                }
            }

            return -1;
            break;

        case 'n':
            if (isLongerThan(4, i, strlen(buffer))) {
                int word_length = 4;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "nine")) {
                    return 9;
                }
            }

            return -1;
            break;

        case 't':
            if (isLongerThan(3, i, strlen(buffer))) {
                int word_length = 3;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "ten")) {
                    return 10;
                } else if (!strcmp(word, "two")) {
                    return 2;
                }
            } 

            if (isLongerThan(5, i, strlen(buffer))) {
                int word_length = 5;
                char word[word_length + 1];
                word[word_length] = '\0';

                strncpy(word, &buffer[i], word_length);
                if (!strcmp(word, "three")) {
                    return 3;
                }
            }
            
            return -1;
            break;

        default:
            return -1;
            break;
    }
}

int main() {
    int sum = 0;
    char* digits_in_words[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

    FILE* fptr;
    char filename[] = "puzzle_input.txt";
    char buffer[BUFFER_SIZE];

    fptr = fopen(filename, "r");

    if (fptr == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        int value = 0; 

        for (int i = 0; i < strlen(buffer); i++) {
            if (isdigit(buffer[i])) {
                value += (buffer[i] - ASCII_VALUE_48) * TENS_PLACE_MODIFIER; // Convert ASCII value to decimal integer by subtracting ASCII value 48
                break;
            }

            int possible_digit = match_word(i, buffer);
            if (possible_digit != -1) {
                value += possible_digit * TENS_PLACE_MODIFIER;
                break;
            }

        }

        strrev(buffer);
        for (int j = 0; j < strlen(buffer); j++) {
            if (isdigit(buffer[j])) {
                value += buffer[j] - '0';
                break;
            }

            int possible_digit = match_word_reverse(j, buffer);
            if (possible_digit != -1) {
                value += possible_digit;
                break;
            }
        }

        sum += value;
    }

    printf("%d\n", sum);
    
    return 0;
}
