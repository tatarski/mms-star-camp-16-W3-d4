#include<stdio.h>
#include<stdlib.h>
// Static 
// Local variables - call stack
// Dynamic memory - heap

int arr[1000];
void fun() {
    int local_counter = 0;
    static int static_counter = 0;

    static_counter++;
    local_counter++;
    printf("%d  %d\n", local_counter, static_counter);
}
int main() {
    // array of 10 chars
    char* arr = (char*)malloc(10*sizeof(char));
    if(!arr) {
        perror("Could not malloc\n");
        exit(-1);
    }
    //*arr = 97;
    // arr[0] = 97
    *arr = 'a';

    // arr[1] = 123
    *(arr+1) = 123;

    free(arr);
    return 0;
}