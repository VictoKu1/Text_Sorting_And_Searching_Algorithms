#include "headers.h"

/**
 * Shifts array elements to the right starting from the given position.
 * This function moves all elements from arr[0] to arr[position] one position to the right.
 * 
 * @param array Pointer to the integer array
 * @param position The position from which to start shifting
 */
void shift_array_elements(int *array, int position)
{
    if (array == NULL || position < 0) {
        return;
    }
    
    for (int i = position; i >= 0; i--) {
        array[i + 1] = array[i];
    }
}

/**
 * Performs insertion sort on an integer array.
 * Time complexity: O(n²) in worst case, O(n) in best case
 * Space complexity: O(1)
 * 
 * @param array Pointer to the integer array to sort
 * @param length Number of elements in the array
 */
void insertion_sort(int *array, int length)
{
    if (array == NULL || length <= 0) {
        return;
    }
    
    for (int i = 1; i < length; i++) {
        int current_element = array[i];
        int j = i - 1;
        
        // Move elements greater than current_element one position ahead
        while (j >= 0 && array[j] > current_element) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current_element;
    }
}

/**
 * Finds the correct insertion position for a value in a sorted array.
 * 
 * @param array Pointer to the sorted array
 * @param bound Upper bound for the search
 * @param value The value to find position for
 * @return The index where the value should be inserted
 */
int find_insertion_position(int *array, int bound, int value)
{
    if (array == NULL || bound < 0) {
        return 0;
    }
    
    while (bound >= 0 && array[bound] > value) {
        bound--;
    }
    return bound + 1;
}

/**
 * Main function for the insertion sort program.
 * Reads 50 integers from stdin, sorts them using insertion sort,
 * and prints the sorted array to stdout.
 * 
 * @return 0 on successful execution
 */
int main()
{
    int *array = malloc(ARRAY_SIZE * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return 1;
    }
    
    // Read integers from stdin
    printf("Enter %d integers (one per line):\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (scanf("%d", &array[i]) != 1) {
            fprintf(stderr, "Error: Invalid input at position %d\n", i);
            free(array);
            return 1;
        }
    }
    
    // Sort the array
    insertion_sort(array, ARRAY_SIZE);
    
    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d", array[i]);
        if (i < ARRAY_SIZE - 1) {
            printf(",");
        }
    }
    printf("\n");
    
    free(array);
    return 0;
}
