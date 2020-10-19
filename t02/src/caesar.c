#include "caesar.h"

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
int main (int argc, char *argv[]) {
    if (argc == 3 && argv[1]) {
        for (int i = 0, length = mx_strlen(argv[1]); i < length; i++) 
            argv[1][i] = mx_lettershift(argv[1][i], mx_atoi(argv[2]));

        write(1, argv[1], mx_strlen(argv[1]));
        write(1, "\n", 1);
        
        return 0;
    }
    write(2, "usage: ./caesar \"str\" \"key\"\n", 29);
    return 0;
}
