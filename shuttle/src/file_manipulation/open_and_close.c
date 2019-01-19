#include "libshuttle.h"

//opens a file with a filename, checks if everything went well and return the file reference if so. Else exit.
FILE*   open_file(char *file_name)
{
        FILE *to_test_fd;


        to_test_fd = fopen(file_name, "r");
        if (!to_test_fd)
                test_exit(to_test_fd, "Problem at file opening.");
        return (to_test_fd);
}

//Closes a file stream.
void    close_file(FILE* raw_file)
{
        fclose(raw_file);
}
