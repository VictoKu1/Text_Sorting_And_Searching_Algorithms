#include "headers.h"

//* Shifts all the cells in the array after cell arr[0] one cell to right , i.e. moves the content of cell arr[x] to arr[x+1] for each *(arr)<=x<=*(arr+i).
void shift_element(int* arr, int i){
    while(i>0){
        *(arr+i+1)=*(arr+i)+0;
        i--;
    }
}
//* TODO insertion sort.
void insertion_sort(int* arr ,int len){
    return ;
}
//* TODO main fucntion which gets 50 integers, puts them into array and sorts it using insertion_sort() .
int main (){
   return 0 ;  
}