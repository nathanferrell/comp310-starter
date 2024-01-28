#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[] = "example.txt";

    // Open the file for writing
    FILE *fw = fopen(filename, "w");
    if (fw == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    // Write to the file
    fprintf(fw, "Hello, World!");
    // Close the file after writing
    fclose(fw);

    // Open the file for reading
    FILE *fr = fopen(filename, "r");
    if (fr == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    // Read and print the contents of the file
    char line[1024]; // assuming each line is no more than 1023 characters
    while (fgets(line, sizeof(line), fr) != NULL) {
        printf("%s", line);
    }

    // Close the file after reading
    fclose(fr);

    return 0;
}
