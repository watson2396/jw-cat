
// ^(o-o)^
#include <fcntl.h>
#include <stdio.h> // debug purposes only

int main (int argc,const char** argv) 
{
    // get file name
    // assume local directory for now
    if (argc < 2) 
    {
        printf("Please supply file to jw-cat");
        return 0;
    }

    const char* filename = argv[1];
    printf("%s\n", filename);

    int fileid = open(filename, O_RDONLY);
    printf("%d\n", fileid);

    return 0;
}

