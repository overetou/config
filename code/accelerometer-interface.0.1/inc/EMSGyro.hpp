/**
 *  @file EMSGyro.hpp
 *
 *  @date 27 november, 2018
 *  @author Oscar Veretout
 *
 *  @brief Defines the EMSGyro class.
 *
 *
 */

#ifndef EMSGYRO_HPP
#define EMSGYRO_HPP

#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include "EMSDevice.hpp"
#define GYRO_STOP 1

/**EMSGyro is an object capable of interacting with a particular gyroscope via its python script.
Careful ! If you use read() without prealably using open() or after a close(), behavior is undefined. (Likely a crash or a wrong execution).*/
class  EMSGyro : public EMSDevice {
  public: 
  /**launch interactive calibration process.*/
  uint32_t iocontrol (const void* iocontroldata);
  /**reads sensor output.*/
  uint32_t read(void* buffer);
  /**Curently nothing to write to the accelerometer.*/
  uint32_t write(void* buffer);
  /**Turns on the sensor.*/
  bool open(const void* openData);
  /**Turns off the sensor.*/
  bool close(const void* data);
  /**The two folowing functions allow you to set callback functions to read() and write().*/
  bool setReadHandler(void (*readCallback)(void));
  bool setWriteHandler(void (*writeCallback)(void));
  /**It may be more secure to remove this when the program enters production.*/
  void  setScriptName(const char* script) {
    strcpy(this->script, script);
  }
  EMSGyro();
  ~EMSGyro();

  protected:
  void (*readCallback)(void);
  //void (*writeCallback)(void);
  int  p_out[2];
  pid_t  pid = 0;
  /**Useful for testing. Just put in an arbitrary script name (total length <= 14) to test a scenario without calling the sensor.ex : src/ex.py*/
  char  script[14] = "src/script.py";
};

#endif
