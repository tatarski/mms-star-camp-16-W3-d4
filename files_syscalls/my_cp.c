// ./my_cp in_file out_file
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>   // perror

int main(int arc, char * argp[]) {
    // Linked list - pop_back, push_front
    // fwrite/fread text files/ binary files
    // Syscalls: open/read/write/close/lseek

    // Open in_file for reading
    int fd_in = open(argp[1], O_RDONLY);
    int fd_out = open(argp[2], O_WRONLY | O_CREAT | O_EXCL,
                     S_IRUSR | S_IWUSR);

    int file_byte_size = lseek(fd_in, 0, SEEK_END);
    lseek(fd_in, file_byte_size/2 ,SEEK_SET);
    if(fd_in == -1) {
        perror("Could not open in_file\n");
        return -1;
    }
    if(fd_out == -1) {
        perror("Could not open out_file\n");
        return -1;
    }
    char cur_sym;
    int read_count = 1;
    int written_count;
    // while (read_count != 0)
    while ((read_count = read(fd_in, &cur_sym, 1)) != 0)
    {
        
        if (read_count == -1)
        {
            perror("Could not read from in_file\n");
            return -1;
        }
        written_count = write(fd_out, &cur_sym, 1);
        if (written_count == 0)
        {
            perror("Write error\n");
            return -1;
        }
    }
    close(fd_in);
    close(fd_out);
    return 0;
}
