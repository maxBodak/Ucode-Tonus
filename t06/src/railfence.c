#include "railfence.h"

int main (int argc, char *argv[]) {
    if (argc == 2 && argv[1]) {
       int length = mx_strlen(argv[1]);
        char *output = mx_strnew(length);
        int offset = 0;
        int key = 6;
        int cycle = (key * 2) - 2;
        int wave_q[key];

        for (int i = 0; i < key; i++) {
            wave_q[i] = length / cycle;
            if (i && i != key - 1)
                wave_q[i] *= 2;
        }
        //printf("length: %d (%d, %d, %d, %d, %d, %d)\n",length, wave_q[0], wave_q[1], wave_q[2], wave_q[3], wave_q[4], wave_q[5]);
        //printf("length/cycle = %d\n", length%cycle);
        if (length % cycle) {
            for (int i = 0; i < key; i++)
                wave_q[i]++;
            for (int i = 2; i + key <= length % cycle + 1; i++)
                wave_q[key - i]++;
        }
        printf("length: %d (%d + %d + %d + %d + %d + %d)\n",length, wave_q[0], wave_q[1], wave_q[2], wave_q[3],wave_q[4],wave_q[5]);
        for (int i = 0; i < length; i++)
                output[i] = '-';

        for (int i = 0; i < key; i ++) {
            int step = cycle;
            if (i != 0 && i != key - 1)
                step -= (i - 1) * 2;
            for (int j = i, k = 0; k < wave_q[i]; k++, j += step) {
                output[j] = argv[1][offset + k];
                if (i != 0 && i != key - 1)
                    step -= 2;
                if (step == 0)
                    step = cycle - 2;
            }
            offset += wave_q[i];
        }
        
        write(1, output, length);
        write(1, "\n", 1);
        return 0;
    }
    write(2, "usage: ./railfence \"str\"\n", 25);
    exit(0);
    return 0;
}
