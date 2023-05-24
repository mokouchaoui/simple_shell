#include "main.h"
#include <unistd.h>

#define BUFFER_SIZE 1024

char* my_getline() {
    static char buffer[BUFFER_SIZE];
    static int position = 0;
    static int bytes_read = 0;

    char* line = NULL;
    int line_size = 0;

    while (1) {
        // Check if buffer needs to be refilled
        if (position >= bytes_read) {
            // Read data from stdin into buffer
            bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            position = 0;

            // Check for end of input
            if (bytes_read <= 0)
                break;
        }

        // Process each character in the buffer
        while (position < bytes_read) {
            // Check for newline character
            if (buffer[position] == '\n') {
                position++;  // Skip the newline character

                // Allocate memory for the line
                line = realloc(line, (line_size + 1) * sizeof(char));
                line[line_size] = '\0';  // Null-terminate the line
                return line;
            }

            // Append character to line
            line = realloc(line, (line_size + 1) * sizeof(char));
            line[line_size] = buffer[position];
            position++;
            line_size++;
        }
    }

    // Free memory if no more input is available
    if (line != NULL) {
        free(line);
        line = NULL;
    }

    return line;
}

int main() {
    char* line;

    while ((line = my_getline()) != NULL) {
        // Do something with the line
        // ...

        free(line);
    }

    return 0;
}

