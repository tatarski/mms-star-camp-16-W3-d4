#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>
// File descriptor
// Each file --> file descriptor
// Number >= 0
// Standart input           --  stdin   -- 0
// Standart output          --  stdout  -- 1
// Standart error output    --  stderr  -- 2
int main() {
    int fd = open("test_binary", O_WRONLY | O_TRUNC);
    printf("new_fd: %d\n", fd); /// 3
    if(fd == -1) {
        perror("Could not open file\n");
    }
    // char *buf = "HELLO SYSCALLS!\n";
    int arr[] = {11, 12, 13, 14};
    // int sym_num = strlen(buf);
    int written_count;
    written_count = write(fd, arr, sizeof(int)*4);
    if(written_count != sizeof(int)*4) {
        write(2, "Could not write to file!\n", 26);
    }
    close(fd);
    return 0;
}