#ifndef COIN_SODELAYQUEUESENSOR_H
#define COIN_SODELAYQUEUESENSOR_H

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2003 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org> for  more information.
 *
 *  Systems in Motion, Teknobyen, Abels Gate 5, 7030 Trondheim, NORWAY.
 *  <URL:http://www.sim.no>.
 *
\**************************************************************************/

#include <Inventor/sensors/SoSensor.h>
#include <Inventor/SbBasic.h>
#include <Inventor/system/inttypes.h>

#ifdef __PIVY__
typedef int uint32_t;

%rename(SoDelayQueueSensor_scb_v) SoDelayQueueSensor::SoDelayQueueSensor(SoSensorCB * func, void * data);

%feature("shadow") SoDelayQueueSensor::SoDelayQueueSensor %{
def __init__(self,*args):
   if len(args) == 2:
      args = (args[0], (args[0], args[1]))
      self.this = apply(_pivy.new_SoDelayQueueSensor_scb_v,args)
      self.thisown = 1
      return
   self.this = apply(_pivy.new_SoDelayQueueSensor,args)
   self.thisown = 1
%}
#endif

class COIN_DLL_API SoDelayQueueSensor : public SoSensor {
  typedef SoSensor inherited;

public:
  SoDelayQueueSensor(void);
  SoDelayQueueSensor(SoSensorCB * func, void * data);
  virtual ~SoDelayQueueSensor(void);

  void setPriority(uint32_t pri);
  uint32_t getPriority(void) const;
  static uint32_t getDefaultPriority(void);
  virtual void schedule(void);
  virtual void unschedule(void);
  virtual SbBool isScheduled(void) const;

  virtual SbBool isIdleOnly(void) const;
  virtual void trigger(void);

protected:
  SbBool scheduled;

private:
  virtual SbBool isBefore(const SoSensor * s) const;
  uint32_t priority;
};

#endif // !COIN_SODELAYQUEUESENSOR_H