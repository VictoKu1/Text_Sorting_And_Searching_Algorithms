#include "headers.h"

int main()
{
    char w[WORD]; // the target word
    char s[2];    // the situation
    //size_t s_w;
    //s_w = get_word(w);
    get_word(w);
    get_word(s);
    getchar();
    printf("word = %s \n", w);
    printf("si = %s \n", s);
    switch (s[0])
    {
    case 'a':
        print_lines(w);
        break;
    case 'b':
        print_similar_words(w);
        break;
    }
    return 0;
}

// this function prints lines that contains similar words to the given word
void print_lines(char *str)
{
    char l[LINE];
    char w[WORD];
    l[0] = 'i';
    // need checking
    while (l[0] != EOF)
    {
        size_t s_l = Line(l);
        int i = 0;
        int j;
        int b = FALSE;
        while (i < s_l)
        {
            j = getWord_fromLine(l, w, i, s_l);
            i += j;
            ++i;
            if (substring(w, str))
            {
                b = TRUE;
            }
        }
        if (b)
        {
            printf("%s\n", l);
        }
    }
}

// this function prints similar words to the given word
void print_similar_words(char *str)
{
    char l[LINE];
    char w[WORD];
    l[0] = 'i';
    // need checking
    while (l[0] != EOF)
    {
        size_t s_l = Line(l);
        int i = 0;
        int j;
        while (i < s_l)
        {
            j = getWord_fromLine(l, w, i, s_l);
            i += j;
            ++i;
            if (similar(w, str, 1))
            {
                printf("%s\n", w);
            }
        }
    }
}

//////////////
//functions//
/////////////

// this function read a line from the user
int Line(char s[])
{
    int i = 0;
    char c;
    while (((c = getchar()) != '\n') && (c != 13) && (c != EOF))
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    if (c == EOF)
    {
        s[0] = EOF;
        return 0;
    }
    return i;
}

// this function read a word from the user
int get_word(char w[])
{
    char c;
    int i = 0;
    c = getchar();
    while ((c != '\n') && (c != '\t') && (c != ' ') && (c != 13))
    {
        w[i] = c;
        ++i;
        c = getchar();
    }
    w[i] = 0;
    return i;
}

// this function return if str1 is similar to str2 with n differences
int similar(char *str1, char *str2, int n)
{
    int i1 = 0, i2 = 0;
    while (*str1 != '\0')
    {
        if (*str1 == *str2)
        {
            ++str2;
            ++i2;
        }
        ++str1;
        ++i1;
    }
    return (((i1 - i2) <= n) && (*str2 == '\0'));
}

// this function get a word from a line from the given start
int getWord_fromLine(char l[], char w[], int start, int size)
{
    int i = start, j = 0;
    while ((l[i] != '\n') && (l[i] != '\t') && (l[i] != ' ') && (l[i] != 13) && (i < size))
    {
        w[j] = l[i];
        ++i;
        ++j;
    }
    w[j] = '\0';
    return j;
}
// this function copy a string s1 to s2 from 0 to end - 1
void copy(char s1[], char s2[], int end)
{
    for (size_t j = 0; j < end - 1; j++)
    {
        s2[j] = s1[j];
    }
    s2[end] = '\0';
}

// not sure if needed

int substring(char *str1, char *str2)
{
    int i = 0;
    while (*str1 != '\0')
    {
        if (*str2 == '\0')
        {
            return 1;
        }
        if (*str1 == *str2)
        {
            ++str2;
            ++i;
        }
        else
        {
            while (i > 0)
            {
                --str2;
                --i;
            }
        }
        ++str1;
    }
    if (*str2 == '\0')
    {
        return 1;
    }
    return 0;
}

// this function returns if str1 contains str2
int contains(char *str1, char *str2)
{
    while (*str1 != '\0')
    {
        if (*str1 == *str2)
        {
            ++str2;
        }
        ++str1;
    }
    return *str2 == '\0';
}