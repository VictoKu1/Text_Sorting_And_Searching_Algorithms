#include "headers.h"

int main(){
    char w[] = "cat";
    print_lines(w);
    return 0;
}

void debug1(){
    char s[] = "abbbcd nuys\ttur\n";
    char s2[20];
    int i;
    printf("s = %s \n",s);
    i = getWord_fromLine(s,s2,0,18);
    printf("i = %i  ",i);
    char s3[i];
    copy(s2,s3,i);
    printf("*s2 = %s \n",s2);
    printf("s2 = %s \n",s3);
    i = getWord_fromLine(s,s2,6,18);
    printf("i = %i  ",i);
    char s4[i];
    copy(s2,s4,i);
    printf("*s2 = %s \n",s2);
    printf("s2 = %s \n",s4);
    i = getWord_fromLine(s,s2,7,18);
    printf("i = %i  ",i);
    char s5[i];
    copy(s2,s5,i);
    printf("*s2 = %s \n",s2);
    printf("s2 = %s \n",s5);
    i = getWord_fromLine(s,s2,11,18);
    printf("i = %i  ",i);
    char s6[i];
    copy(s2,s6,i);
    printf("s2 = %s \n",s6);
    i = getWord_fromLine(s,s2,12,18);
    printf("i = %i  ",i);
    char s7[i];
    copy(s2,s7,i);
    printf("*s2 = %s \n",s2);
    printf("s2 = %s \n",s7);
    i = getWord_fromLine(s,s2,15,18);
    printf("i = %i  ",i);
    char s8[i];
    copy(s2,s8,i);
    printf("*s2 = %s \n",s2);
    printf("s2 = %s \n",s8);
    i = getWord_fromLine(s,s2,15,18);
    printf("i = %i  ",i);
    char s9[i];
    copy(s2,s9,i);
    printf("*s2 = %s \n",s2);
    printf("s2 = %s \n",s9);
}