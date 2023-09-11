#include "main.h"

int main(void) {
    const char *input = "Hello World! I'm still Testing";
    int word_count; // Declare the word_count variable
    char **words = splitString(input, &word_count); // Pass word_count by reference

    // Now you can access both the array of words and the word_count
    for (int i = 0; i < word_count; i++) {
        printf("Word %d: %s\n", i + 1, words[i]);
        free(words[i]);
    }

    free(words);

    return 0;
}

