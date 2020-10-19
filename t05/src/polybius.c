#include "polybius.h"

char mx_decode_polibius(char *c) {
    int axis[2] = {0, 0};
    char poli[6][6] = {"abcdef", "ghijkl", "mnopqr", "stuvwx", "yz0123", "456789"};
    for (int i = 0; i < 2; i++) {
        if (c[i] == 'A' || c [i] == 'a')
            axis[i] = 0;
        else if (c[i] == 'B' || c [i] == 'b')
            axis[i] = 1;
        else if (c[i] == 'C' || c [i] == 'c')
            axis[i] = 2;
        else if (c[i] == 'D' || c [i] == 'd')
            axis[i] = 3;
        else if (c[i] == 'E' || c [i] == 'e')
            axis[i] = 4;
        else if (c[i] == 'F' || c [i] == 'f')
            axis[i] = 5;
    }
    return poli[axis[0]][axis[1]];

}

int main (int argc, char *argv[]) {
    if (argc == 2 && argv[1]) {
        char *input = argv[1];
        int length = 0;

        while (*input) {
            if (mx_isalpha(*input) && mx_isalpha(*(input + 1)))
                input++;
            length++;
            input++;
        }
        
        char *output = mx_strnew(length);
        input = argv[1];
        
        while (*input) {
            if (mx_isalpha(*input) && mx_isalpha(*(input + 1)))
                output[0] = mx_decode_polibius(input++);
            else if (!mx_isalpha(*input))
                output[0] = input[0]; 
            input++;
            output++;
        }
        output -= length;

        write(1, output, mx_strlen(output));
        write(1, "\n", 1);

        return 0;
    }
    write(2, "usage: ./polibius \"str\"\n", 25);
    exit(0);
    return 0;
}
