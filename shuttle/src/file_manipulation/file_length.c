#include "libshuttle.h"

//Takes a file as parameter. 1: puts the file cursor at the end of the file. 2: puts the number of chars measured into a long int variable.
//3: puts the file cursor at the beginning of the file (its original place). 4: checks that the file is not empty, otherwise exits.
//5: return the long int - 1 (because the last char is not a char but an end of file(EOF) signal taken by the system reading functions and we must not try to read that else format error).
LI      flen(FILE* raw_file)
{
        long int        size;

        fseek(raw_file, 0L, SEEK_END);
        size = (long int)ftell(raw_file);
        rewind(raw_file);
        return (size - 1);
}
