
// ^(o-o)^
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include <stdio.h> // debug purposes only
#include <string.h>


#define buffsize 100

int main (int argc,const char** argv) 
{
    // get file name
    if (argc < 2) 
    {
        printf("Please supply file to jw-cat");
        return 0;
    }

    const char* filename = argv[1];
    printf("%s\n", filename);

    int filedesc = open(filename, O_RDONLY);
    // char* errmsg = strerror(errno);
    // printf("%s\n", errmsg);

    // read & print contents
    int bytes_read = 0;
    char buf[buffsize];
    do
    {
        bytes_read = read(filedesc, buf, buffsize);
        write(1, buf, bytes_read);
    } while (bytes_read != 0);
    write(1, "\n", 1);

    if (close(filedesc) == -1) 
    {
        char* err_msg = strerror(errno);
        printf("%s\n", err_msg);
    }

    return 0;
}

