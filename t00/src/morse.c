#include "morse.h"

char mx_morseletter(char *input_letter, int length) {
    char morse[27][5] = {".", "-", ".-", "..", "--", "-.", 
                        "-..", "--.", "-.-", "---", ".-.", "...", "..-", ".--", 
                        "-...", "-.-.", "..-.", "....", ".---", ".-..", ".--.", "--.-", "...-", "-..-", "-.--", "--..", "....."};
    char letters[] = {'E', 'T', 'A', 'I', 'M', 'N', 
                        'D', 'G', 'K', 'O', 'R', 'S', 'U', 'W', 
                        'B', 'C', 'F', 'H', 'J', 'L', 'P', 'Q', 'V', 'X', 'Y', 'Z', '.'};

    for (int i = 0; i < 27; i++) {
        if (!mx_strncmp(input_letter, morse[i], length))
            return letters[i];
    }
    return 48;
}

int main (int argc, char *argv[]) {
    if (argc == 2 && argv[1]) {
        char *input = argv[1];
        int symbol_count = 1;
        int space_checker = 0;
        int length = mx_strlen(argv[1]);

        for (int i = 0; i < length; i++)
            if (input[i] != ' ' && input[i] != '-' && input[i] != '.' && input[i] != '\n') {
                write(2, "usage: ./morse \"str\"\n", 22);
                return 0;
            }
        while (*input) {
            if (input[0] == '\n')
                input[0] = ' ';
            else
                input++;
        }

        input = argv[1];
        while (input[0] == ' ')
            input++;
        while ((input = mx_strchr(input, ' '))) {
            while (input[0] == ' ') {
                input++;
                space_checker++;
            }
            if (input[0]) {
                symbol_count++;
                if (space_checker >= 7)
                    symbol_count++;
            }
            space_checker = 0;
        }

        char *output = mx_strnew(symbol_count);
        input = argv[1];
        while (input[0] == ' ') {
            input++;
            argv[1]++;
        }
        for (int i = 0; i < symbol_count - 1; i++) {
            input = mx_strchr(input, ' ');
            output[i] = mx_morseletter(argv[1], (int)(input - argv[1]));
            while (input[0] == ' ') {
                input++;
                space_checker++;
            }
            if (space_checker >= 7)
                output[++i] = ' ';
            argv[1] = input;
            space_checker = 0;
        }
        output[symbol_count - 1] = mx_morseletter(argv[1], (int)(input - argv[1]));
        
        write(1, output, symbol_count);
        write(1, "\n", 1);
        return 0;
    }
    write(2, "usage: ./morse \"str\"\n", 22);
    return 0;
}
