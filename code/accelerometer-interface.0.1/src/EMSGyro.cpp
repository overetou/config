/**
 *  @file EMSGyro.cpp
 *
 *  @date 27 november, 2018
 *  @author Oscar Veretout
 *
 *  @brief Defines the member functions of EMSGyro class.
 *
 *
 */

#include "EMSGyro.hpp"
#define WRITE 1
#define READ 0

/**This function allows to open a subprocess with a command, and get its pid, and optionnal pipes for writing and reading from it.*/
pid_t popen2(char **command, int *infp, int *outfp) {
  int p_stdin[2], p_stdout[2];//Those two int are pipe file descriptors. Used to communicate with the python subprocess.
  pid_t pid;//This pid will be used to kill the subprocess when we are finished using it.

  if (pipe(p_stdin) != 0 || pipe(p_stdout) != 0)//Initializes pipes and make sure that they are okay. -1 means error, 0 means success.
    return -1;
  pid = fork();//Creates a subprocess and stores 0 (in child process) or child pid (in parent process).
  if (pid < 0)//Checks that noting unusual is happening. -1 means error.
    return -1;
  else if (pid == 0) {
    close(p_stdin[WRITE]);//This pipe will replace stdin in child. Only the read end will be used so we immediately close the write end.
    dup2(p_stdin[READ], READ);//dup is used to copy a file descriptor. The following line overwrites the standard input fd with the read pipe.
    close(p_stdout[READ]);//We will write in stdout, so the read end is not needed in the child. We close it.
    dup2(p_stdout[WRITE], WRITE);//We overwrite standard output file descriptor with the write pipe.
    execvp(*command, command);//Executes our command.
    perror("execvp");//We are not supposed to reach the folowing line so we print an error and escape the function.
    exit(1);
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
  return pid;//Finally we return the pid of the child process.
}

/**Creates a python subprocess with pipes. The python script will interact with the sensor and send data trough the pipe.*/
bool EMSGyro::open(const void* data) {
  char* command[4];
  char c1[7] = "python";
  char arg1[3] = "-u";
  command[0] = c1;
  command[1] = arg1;
  command[2] = this->script;
  command[3] = NULL;
  this->pid = popen2(command, NULL, this->p_out);
//  std::cout << "Subprocess PID = " << this->pid << std::endl;
  return true;
}

/**Kills the subprocess driving the sensor. Does nothing if there is no subprocess in activity, but returns false.*/
bool EMSGyro::close(const void* data) {
  if (pid != 0)
  {
    kill(this->pid, SIGKILL);
    this->pid = 0;
    return true;
  }
  return false;
}

/**Puts read data into the buffer and returns 1 for success. If file end is reached, returns 0. If everything went well, trashes the newline and launches the callback function.*/
uint32_t EMSGyro::read(void* buffer) {
  char*  c_ptr = (char*)buffer;
  ::read(this->p_out[READ], c_ptr, 1);
  if (*c_ptr == '\0')
    return 0;
  this->readCallback();
  return 1;
}

/**There is currently nothing to write to the subprocess. This function can be quicly implemented just by looking at read().*/
uint32_t EMSGyro::write(void* buffer) {
  return 0;
}

/**Gyro will need calibration. This func displays calibration data needed to complete it. It stops displaying when receiving the 'S' caracter. It should be possible t simplify it by calling read and stoping when 0 is returned.*/
uint32_t EMSGyro::iocontrol (const void* iocontroldata) {
  char  c;

  ::read(this->p_out[READ], &c, 1);
  while (c != 'Z') {
    std::cout << c;
    ::read(this->p_out[READ], &c, 1);
  }
  return 1;
}

/**Sets a callback to read.*/
bool EMSGyro::setReadHandler(void (*readCallback)(void)) {
  this->readCallback = readCallback;
}

/**Write is currently not used.*/
bool EMSGyro::setWriteHandler(void (*writeCallback)(void)) {
  return false;
}

/**This function is called when there is no callback set by the user.*/
void  do_nothing() {
}

/**sets up the object to a ready to use set. open() and iocontrol() are currently not autmoted. -u parameter disables python buffering, wich mess up the output of complex python subprocess.*/
EMSGyro::EMSGyro() {
//  this->script = "src/script.py";
  this->readCallback = do_nothing;
}

/**Makes sure that no subprocess is leaved alone after destoying the object.*/
EMSGyro::~EMSGyro() {
  this->close(NULL);
}
