#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#define WRITE 1
#define READ 0

pid_t popen2(const char *command, int *infp, int *outfp)
{
	//Those two int are pipe file descriptors. Used to communicate with the python subprocess.
	int p_stdin[2], p_stdout[2];
	//This pid will be used to kill the subprocess when we are finished using it.
	pid_t pid;

	//Initializes pipes and make sure that they are okay. -1 means error, 0 means success.
	if (pipe(p_stdin) != 0 || pipe(p_stdout) != 0)
		return (-1);
	//Creates a subprocess and stores 0 (in child process) or child pid (in parent process).
	pid = fork();
	//Checks that noting unusual is happening. -1 means error.
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		//This pipe will replace stdin in child. Only the read end will be used so we immediately close the write end.
		close(p_stdin[WRITE]);
		//dup is used to copy a file descriptor. The following line overwrites the standard input fd with the read pipe.
		dup2(p_stdin[READ], READ);
		//We will write in stdout, so the read end is not needed in the child. We close it.
		close(p_stdout[READ]);
		//We overwrite standard output file descriptor with the write pipe.
		dup2(p_stdout[WRITE], WRITE);
		//Executes our command.
		execl("/bin/sh", "sh", "-c", command, NULL);
		//We are not supposed to reach the folowing line so we print an error and escape the function.
		perror("execvp");
		exit(-1);
	}
	//Here we enter the last case possible, we are in the parent process and pid is > 0. The folowing lines affect the pipe file descriptors
	//into the arguments or destroy the pipes if no adress is given (wich could mean that we only want the subprocess to run without using pipes)
	if (infp == NULL)
		close(p_stdin[WRITE]);
	else
		*infp = p_stdin[WRITE];
	if (outfp == NULL)
		close(p_stdout[READ]);
	else
		*outfp = p_stdout[READ];
	//Finally we return the pid of the child process.
	return pid;
}


int	main(void)
{
	int	p_out[2];
	popen2("python script.py", NULL,  p_out);
	char c;
	
	read(p_out[READ], &c, 1);
	std::cout << c << std::endl;
	return (0);
}
