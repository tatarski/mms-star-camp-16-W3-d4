#include<stdio.h>
#include<stdlib.h>
int main() {
    FILE* f_ptr = fopen("test_binary_file", "wb");
    if(!f_ptr) {
        perror("Could not open file\n");
        exit(-1);
    }
    long arr[] = {21498712151, 214748364900, 896124987123, 12411612413};
    fwrite(arr, sizeof(long), 4, f_ptr);
    fclose(f_ptr);
    return 0;
}