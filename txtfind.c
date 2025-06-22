#include "headers.h"

/**
 * Main function for the text search program.
 * Reads a target word and operation type from stdin, then performs
 * the requested text search operation.
 * 
 * Usage:
 * - Enter target word
 * - Enter 'a' to find lines containing the word
 * - Enter 'b' to find similar words
 * 
 * @return 0 on successful execution
 */
int main()
{
    char target_word[MAX_WORD_LENGTH];
    char operation[2];
    
    // Read target word
    if (read_word(target_word) == 0) {
        fprintf(stderr, "Error: Failed to read target word\n");
        return 1;
    }
    
    // Read operation type
    if (read_word(operation) == 0) {
        fprintf(stderr, "Error: Failed to read operation type\n");
        return 1;
    }
    
    // Consume newline
    int c = getchar();
    if (c != '\n' && c != EOF) {
        fprintf(stderr, "Error: Invalid input format\n");
        return 1;
    }
    
    // Perform requested operation
    switch (operation[0]) {
        case 'a':
            print_lines_containing_word(target_word);
            break;
        case 'b':
            print_similar_words(target_word);
            break;
        default:
            fprintf(stderr, "Error: Invalid operation '%c'. Use 'a' or 'b'\n", operation[0]);
            return 1;
    }
    
    return 0;
}

/**
 * Prints all lines from stdin that contain the target word as a substring.
 * 
 * @param target_word The word to search for in lines
 */
void print_lines_containing_word(const char *target_word)
{
    if (target_word == NULL) {
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    
    while (read_line(line) > 0) {
        int line_length = strlen(line);
        int i = 0;
        bool found_word = FALSE;
        
        // Process each word in the line
        while (i < line_length) {
            int word_length = extract_word_from_line(line, word, i, line_length);
            if (word_length > 0) {
                if (is_substring(word, target_word)) {
                    found_word = TRUE;
                    break;
                }
            }
            i += word_length + 1; // Skip the word and the following whitespace
        }
        
        if (found_word) {
            printf("%s\n", line);
        }
    }
}

/**
 * Prints all words from stdin that are similar to the target word.
 * Similarity is defined as having at most 1 character difference.
 * 
 * @param target_word The word to find similar words for
 */
void print_similar_words(const char *target_word)
{
    if (target_word == NULL) {
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    
    while (read_line(line) > 0) {
        int line_length = strlen(line);
        int i = 0;
        
        // Process each word in the line
        while (i < line_length) {
            int word_length = extract_word_from_line(line, word, i, line_length);
            if (word_length > 0) {
                if (is_similar(word, target_word, 1)) {
                    printf("%s\n", word);
                }
            }
            i += word_length + 1; // Skip the word and the following whitespace
        }
    }
}

/**
 * Reads a line from stdin into the provided buffer.
 * 
 * @param line Buffer to store the read line
 * @return Number of characters read (excluding null terminator), or -1 on error
 */
int read_line(char line[])
{
    if (line == NULL) {
        return -1;
    }
    
    int i = 0;
    int c;
    
    while (i < MAX_LINE_LENGTH - 1 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = (char)c;
    }
    
    line[i] = '\0';
    
    if (c == EOF && i == 0) {
        return -1; // EOF reached
    }
    
    return i;
}

/**
 * Reads a word from stdin into the provided buffer.
 * A word is defined as a sequence of non-whitespace characters.
 * 
 * @param word Buffer to store the read word
 * @return Number of characters read (excluding null terminator), or 0 on error
 */
int read_word(char word[])
{
    if (word == NULL) {
        return 0;
    }
    
    int i = 0;
    int c;
    
    // Skip leading whitespace
    while ((c = getchar()) != EOF && (c == ' ' || c == '\t' || c == '\n')) {
        // Continue skipping
    }
    
    if (c == EOF) {
        return 0;
    }
    
    // Read the word
    while (i < MAX_WORD_LENGTH - 1 && c != EOF && c != ' ' && c != '\t' && c != '\n') {
        word[i++] = (char)c;
        c = getchar();
    }
    
    word[i] = '\0';
    return i;
}

/**
 * Checks if str1 is similar to str2 with at most max_differences character differences.
 * Uses a simple edit distance algorithm.
 * 
 * @param str1 First string to compare
 * @param str2 Second string to compare
 * @param max_differences Maximum allowed differences
 * @return TRUE if strings are similar, FALSE otherwise
 */
int is_similar(const char *str1, const char *str2, int max_differences)
{
    if (str1 == NULL || str2 == NULL || max_differences < 0) {
        return FALSE;
    }
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // If length difference is greater than max_differences, they can't be similar
    if (abs(len1 - len2) > max_differences) {
        return FALSE;
    }
    
    // Simple similarity check: count matching characters
    int matches = 0;
    int i = 0, j = 0;
    
    while (str1[i] != '\0' && str2[j] != '\0') {
        if (str1[i] == str2[j]) {
            matches++;
            j++;
        }
        i++;
    }
    
    // Check if we reached the end of str2 and the difference is within limits
    return (str2[j] == '\0' && (len1 - matches) <= max_differences);
}

/**
 * Extracts a word from a line starting at the given position.
 * 
 * @param line The line to extract from
 * @param word Buffer to store the extracted word
 * @param start_pos Starting position in the line
 * @param line_length Length of the line
 * @return Length of the extracted word
 */
int extract_word_from_line(const char line[], char word[], int start_pos, int line_length)
{
    if (line == NULL || word == NULL || start_pos < 0 || start_pos >= line_length) {
        return 0;
    }
    
    int i = start_pos;
    int j = 0;
    
    // Skip leading whitespace
    while (i < line_length && (line[i] == ' ' || line[i] == '\t')) {
        i++;
    }
    
    // Extract the word
    while (i < line_length && j < MAX_WORD_LENGTH - 1 && 
           line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
        word[j++] = line[i++];
    }
    
    word[j] = '\0';
    return j;
}

/**
 * Copies a string from source to destination up to end_pos characters.
 * 
 * @param source Source string
 * @param destination Destination buffer
 * @param end_pos Number of characters to copy
 */
void copy_string(const char source[], char destination[], int end_pos)
{
    if (source == NULL || destination == NULL || end_pos < 0) {
        return;
    }
    
    for (int i = 0; i < end_pos && source[i] != '\0'; i++) {
        destination[i] = source[i];
    }
    destination[end_pos] = '\0';
}

/**
 * Checks if str1 contains str2 as a substring.
 * 
 * @param str1 The string to search in
 * @param str2 The substring to search for
 * @return TRUE if str1 contains str2, FALSE otherwise
 */
int is_substring(const char *str1, const char *str2)
{
    if (str1 == NULL || str2 == NULL) {
        return FALSE;
    }
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    if (len2 > len1) {
        return FALSE;
    }
    
    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str1[i + j] != str2[j]) {
                break;
            }
        }
        if (j == len2) {
            return TRUE;
        }
    }
    
    return FALSE;
}