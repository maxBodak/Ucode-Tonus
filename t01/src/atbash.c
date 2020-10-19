#include "atbash.h"

int main (int argc, char *argv[]) {
    if (argc == 2 && argv[1]) {
        int length = mx_strlen(argv[1]);

        for (int i = 0; i < length; i++) {
            if (mx_islower(argv[1][i]))
                argv[1][i] = 122 - (argv[1][i] - 97);
            else if (mx_isupper(argv[1][i]))
                argv[1][i] = 90 - (argv[1][i]- 65);
        }

        write(1, argv[1], mx_strlen(argv[1]));
        write(1, "\n", 1);
        
        return 0;
    }
    write(2, "usage: ./atbash \"str\"\n", 24);
    return 0;
}
