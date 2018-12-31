/**
 *  @file EMSDevice.hpp
 *
 *  @date 27 november, 2018
 *  @author Oscar Veretout
 *
 *  @brief Defines the EMSDevice class.
 *
 *
 */

#ifndef EMSDEVICE_HPP
#define EMSDEVICE_HPP

#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <mutex>
#include <thread>

class  EMSDevice {
  private:
  std::mutex	mtx;
  public:
  /**used to pass specific setup data to the sensor and do the setup procedure.*/
  virtual uint32_t iocontrol (const void* iocontroldata) =0;
  /**reads sensor's output.*/
  virtual  uint32_t read(void* buffer) =0;
  /**give commands to the sensor. Do nothing if there are none.*/
  virtual uint32_t write(void* buffer) =0;
  /**Turn on the sensor.*/
  virtual bool open(const void* openData) =0;
  /**Turn off the sensor.*/
  virtual bool close(const void* closeData) =0;
  /**Set callback functions off read().*/
  virtual bool setReadHandler(void (*readCallback)(void)) =0;
  /**Set callback functions off write().*/
  virtual bool setWriteHandler(void (*writeCallback)(void)) =0;
};
#endif
