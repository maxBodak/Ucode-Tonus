#include "checkboard.h"

char *checkerboard(char *code, char *alphabet, char *n1, char *n2) {
    char *output;
    char cpr[3][10];
    int length;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 10; j++, alphabet++) {
            if (!i && (j == *n1 - 48 || j == *n2 - 48))
                cpr[i][j++] = ' ';
            cpr[i][j] = alphabet[0];
        }
   for (length = 0; length < mx_strlen(code); length++)
        if (code[length] == *n1 || code[length] == *n2)
            length++;
    output = mx_strnew(length);
    for (int i = 0, line = 0; i < length; i++, code++, line = 0) {
        if (mx_isdigit(*code)) {
            line = 1 * (*code == *n1) + 2 * (*code == *n2);
            code += (*code == *n1 || *code == *n2);
            output[i] = cpr[line][code[0] - 48];
        }
        else
            output[i] = code[0];
    }
    return output;
}

int main (int argc, char *argv[]) {
    if (argc == 5) {
        char *output = checkerboard(argv[1], argv[2], argv[3], argv[4]);
        write(1, output, mx_strlen(output));
        write(1, "\n", 1);
        return 0;
    }
    write(2, "usage: ./checkboard \"text\" \"alphabet\" \"num1\" \"num2\"", 25);
    exit(0);
    return 0;
}
