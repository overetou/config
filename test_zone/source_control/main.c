#include "libshuttle.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	char prototype_buffer[80];
	int file_descriptor = open("prototype.h", O_RDWR);
	if (find_prototype(file_descriptor, prototype_buffer))
	{
		putendl("Prototype found :");
		putendl(prototype_buffer);
	}
	return (0);
}
