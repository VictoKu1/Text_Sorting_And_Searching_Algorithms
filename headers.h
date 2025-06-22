#ifndef TEXT_SORTING_AND_SEARCHING_ALGORITHMS_H
#define TEXT_SORTING_AND_SEARCHING_ALGORITHMS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* Constants */
#define ARRAY_SIZE 50
#define FALSE 0
#define TRUE 1
#define MAX_LINE_LENGTH 257
#define MAX_WORD_LENGTH 31

/* Function declarations */

/* Text processing functions */
void print_lines_containing_word(const char *target_word);
void print_similar_words(const char *target_word);
int read_line(char line[]);
int read_word(char word[]);
int is_substring(const char *str1, const char *str2);
int is_similar(const char *str1, const char *str2, int max_differences);
int extract_word_from_line(const char line[], char word[], int start_pos, int line_length);
void copy_string(const char source[], char destination[], int end_pos);

/* Sorting functions */
void shift_array_elements(int *array, int position);
void insertion_sort(int *array, int length);
int find_insertion_position(int *array, int bound, int value);

#endif /* TEXT_SORTING_AND_SEARCHING_ALGORITHMS_H */