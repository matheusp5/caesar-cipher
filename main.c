#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "cs50.h"
int main() {
    char alphabet[26] ={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string text = get_string("Texto: ");
    int offset = get_int("Offset: ");
    char newText[strlen(text - 1)];

    for (int i = 0; i < strlen(text); ++i) {
        char letter = toupper(text[i]);
        if (letter == ' ') {
            newText[i] = ' ';
            continue;
        }
        if (letter == '!') {
            newText[i] ='!';
            continue;
        }
        if (letter == '?') {
            newText[i] = '?';
            continue;
        }
        if (letter == '.') {
            newText[i] = '.';
            continue;
        }
        if (letter == ',') {
            newText[i] = ',';
            continue;
        }

        int index = 0;
        for (int j = 0; j < 26; ++j) {
            if(alphabet[j] == letter) {
                index = j;
            }
        }

        int alphabetOffset = index + offset;

        if(index + offset > 25) {
            alphabetOffset -= 26;
        }
        newText[i] = alphabet[alphabetOffset];
    }


    for (int i = 0; i < strlen(text); ++i) {
        printf("%c", newText[i]);
    }

    return 0;
}
