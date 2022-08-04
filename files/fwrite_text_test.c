#include<stdio.h>
#include<stdlib.h>
int main() {
    FILE* f_ptr = fopen("test_hello_world", "r+");
    if(!f_ptr) {
        perror("Could not open file\n");
        exit(-1);
    }
    fseek(f_ptr, 4, SEEK_SET);
    char *arr = "Hello world!";
    fwrite(arr, sizeof(char), 12, f_ptr);
    fclose(f_ptr);
    return 0;
}

// Read/Write from/to binary ppm file (P6)
// Git/ Github project tracking
// Makefile

// fopen/fread/fwrite/fseek/fgetc/fgets/fputc
// fputs/fclose/fprintf/fscanf

// open/read/write/close/lseek/dup/dup2