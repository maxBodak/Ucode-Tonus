#include "baconian.h"

char mx_lettershift (char c, int shift) {
    if (mx_islower(c)) {
        if (c + shift > 122)
            c = 96 + ((c + shift) - 122);
        else if (c + shift < 97)
            c = 123 - (97 - (c + shift));
        else
            c += shift;
    }
    else if (mx_isupper(c)) {
        if (c + shift > 90)
            c = 64 + ((c + shift) - 90);
        else if ((c + shift) < 65)
            c = 91 - (65 - (c + shift));
        else
            c += shift;
    }
    return c;
}
int mx_decode_bacon(char c[5]) {
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J','K', 'L', 'M', 
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '.', ','};
    char bacon[29][5] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaab", 
                        "ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb", "baaaa", "baaab", "baaba", "baabb", 
                        "babaa", "babab", "babba", "babbb", "bbaaa", "bbaab", "bbaba", "bbabb", "bbbaa"};

    for (int i = 0; i < 29; i++)
        if (mx_strncmp(c, bacon[i], 5) == 0)
            return letters[i];

    return 48;
}
int mx_count_letters(char *str) {
    int count = 0;

    while (*str) {
        if (mx_isalpha(*str))
            count++;
        str++;
    }
    return count;
}
int main (int argc, char *argv[]) {
    if (argc == 2 && argv[1]) {
        char *input = argv[1];
        int length = mx_count_letters(argv[1]) / 5;
        char output[length+1], buff[6];
        output[length] = '\0';
        buff[5] = '\0';

        for (int i = 0; i < length; i++) {
            for (int j = 0; j < 5;) {
                if (mx_islower(*input))
                    buff[j++] = 'a';
                else if (mx_isupper(*input))
                    buff[j++] = 'b';
                input++;
            }
            output[i] = mx_decode_bacon(buff);
        }

        write(1, output, mx_strlen(output));
        write(1, "\n", 1);
        return 0;
    }
    write(2, "usage: ./baconian \"str\"\n", 25);
    return 0;
}
