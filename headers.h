#include <stdio.h>
void print_lines(char *str);
void print_similar_words(char * str);
int Line(char s[]);
int get_word(char w[]);
int contains(char *str1 , char * str2);
int similar(char * str1 , char *str2 , int n);
void print_lines(char * str);
int getWord_fromLine(char l[],char w[] , int s,int n);
void copy(char s1[] , char s2[], int i);