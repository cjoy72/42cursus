#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char dest[20] = "Hello, ";
    const char *src = "world!";
    size_t size = sizeof(dest);

    size_t result = strlcat(dest, src, size);

    if (result >= size) {
        // Handle buffer overflow
        printf("Buffer is too small.\n");
    } else {
        // Concatenation was successful
        printf("Concatenated string: %s\n", dest);
    }

    return 0;
}
