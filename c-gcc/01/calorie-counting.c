#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/stat.h>

int main() {
    if(chmod("../../input/adventofcode.com_2022_day_1_input.txt", S_IRUSR | S_IWUSR) != 0) {
        perror("Could not change permissions of file");
        return 1;
    }
    FILE *file = fopen("../../input/adventofcode.com_2022_day_1_input.txt", "r");
    if (file==NULL) {
        printf("Failed to open file\n");
        return 2;
    }

    char line[256];
    int max = INT_MIN;
    int current_elf = 0;

    while (fgets(line, sizeof(line), file)) {
        if (line[0]=='\n') {
            if (current_elf > max) {
                max = current_elf;
            }
            current_elf = 0;
        } else {
            int cals = atoi(line);
            current_elf += cals;
        }
    }
    fclose(file);

    FILE *fout = fopen("output.txt", "w");
    fprintf(fout, "%d", max);
    fclose(fout);
    printf("%d", max);

    return 0;
}