// PID: 730507803
// I pledge the COMP 211 honor code.

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100
#define MAXCHAR 50

//function to output the result with correct format
void toString(const int *p, const int *arr);

int main() {
    
    //declaration for variables
    int c, char_counter, line_counter, array_index;
    
    //initialization for variables
    char_counter = 0;

    line_counter = 0;

    array_index= 0;

    //declaration the array to record the oversized lines
    int arr[MAXLINE];

    //loop to count the characters and output lines under fifty characters
    while((c = getchar()) != EOF) {

        //condition for characters counting under fifty
        if (char_counter <= (MAXCHAR - 1)) {
            putchar(c);
            char_counter += 1;

            //condition for lines under fifty characters
            if (c == '\n') {

                //reset the character counter
                char_counter = 0;

                //increment the line counter
                line_counter += 1;
            }

        //condition for characters counting over fifty
        } else {

            //condition for lines with fifty characters
            if (c == '\n') {
                putchar(c);
                
                //reset the character counter
                char_counter = 0;

                //increment the line counter
                line_counter += 1;
                
            //condition for lines over fifty characters
            } else {
                putchar('\n');
                putchar(c);
                
                //set the char_counter to one
                char_counter = 1;
                
                //condition to add the first oversized line to the array
                if (array_index == 0) {
                    arr[array_index] = line_counter;
                    array_index += 1;
                
                //record the oversized line to the array
                } else if (arr[array_index - 1] != line_counter) {
                    arr[array_index] = line_counter;
                    array_index += 1;
                }
            }
        }
    };

    //output the result  
    toString(&array_index, arr);

    //return 0; end of the program
    return 0;
}

//output the result with the correct format
void toString(const int *p, const int *arr) {
    //print out a new line for the correct format
    printf("\n");
    
    //print out the total number of oversized lines
    printf("Total lines over 50 chars: %d\n", *p);

    //print out the result for the correct format
    printf("Offending lines: ");

    //print out the oversized line one by one
    for(int i = 0; i < *p; i++) {
       printf("%d, ", *(arr+i));
    }
    
    //print out a new line for the correct format
    printf("\n");
} 
