#include "headers.h"
#define FALSE 0
#define TRUE 1
#define LINE 256
#define WORD 30


/*
int main(){
    char c ;
    char w[30];
    char s[1];
    size_t s_w;
    s_w = getword(w);
    getword(s);
    while (c = getchar() != EOF)
    {
        switch (s[0])
        {
        case 'a':
            
            break;
        case 'b':
            break;
        default:
            break;
        }

        
    }
}
*/

void print_lines(char *str){
    char l[256];
    size_t s_l = get_line(l);
    int i = 0;
    int b = FALSE;
    while (i<s_l)
    {
        
    }
    

}

//////////////
//functions//
/////////////


int get_line(char s[]){
    int i = 0;
    char c;
    while (c = getchar() != '\n')
    {
        s[i] = c;
        i++;
    }
    return i;
}


int get_word(char w[]){
    char c;
    int i = 0;
    c = getchar();
    while (c != '\n' || c != '\t' || c != ' ')
    {
        w[i] = c;
        i++;
        c = getchar();
    }
    return i;
}


int substring( char * str1, char * str2){
    int i = 0;
    while (*str1 != '\0')
    {
        
    }
    
}

// this function returns if str1 contains str2
int contains(char *str1 , char * str2){
    while ( *str1 != '\0')
    { 
       if (*str1 == *str2)
       {
           str2++;
       }
        str1++;
    }
    return  *str2 == '\0';
}
// this function return if str1 is similar to str2 with n differences 
int similar(char * str1 , char *str2 , int n){
    int i1 = 0 ,i2 = 0;

    while ( *str1 != '\0')
    {
       if (*str1 == *str2)
       {
           str2++;
           i2++;
       }
        str1++;
        i1++;
    }
    return  (i1-i2) == n;
}

// this function get a word from a line from the given start 
int getWord_fromLine(char l[],char w[] , int start,int size){
    int i = start , j = 0;
    while ((l[i] != '\n') && (l[i] != '\t' )&& (l[i] != ' ')&&(i <size))
    {
        w[j] = l[i];
        i++;
        j++;
    }
    return j+1;
}
// this function copy a string s1 to s2 from 0 to end - 1  
void copy(char s1[] , char s2[], int end){
    for (size_t j = 0; j < end-1; j++)
    {
        s2[j] = s1[j];
    }
    s2[end-1] = '\0';
}