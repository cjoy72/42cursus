#include <stdio.h>
#include <string.h>

const char *custom_strnstr(const char *haystack, const char *needle, size_t len) {
    size_t needle_len = strlen(needle);

    if (needle_len == 0) {
        return haystack;  // Empty needle is always found at the start.
    }

    for (size_t i = 0; haystack[i] != '\0' && i < len; i++) {
        if (strncmp(haystack + i, needle, needle_len) == 0) {
            return haystack + i;  // Found the substring.
        }
    }

    return NULL;  // Substring not found.
}

int main() {
    const char *haystack = "Hello, world!";
    const char *needle = "world";
    size_t haystack_len = strlen(haystack);

    const char *result = custom_strnstr(haystack, needle, haystack_len);

    if (result) {
        printf("Found: %s\n", result);
    } else {
        printf("Not found\n");
    }

    return 0;
}
