/*
 * sky.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sky".
 *
 * Model version              : 1.35
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Mon Mar  8 19:59:06 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sky.h"
#include "sky_private.h"

/* Model step function */
void skyModelClass::step()
{
  /* Outputs for Atomic SubSystem: '<Root>/sky hook control' */
  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/zc_dot'
   *  Inport: '<Root>/zc_dot - zf_dot'
   *  Product: '<S1>/Product'
   */
  if (sky_U.zc_dot * sky_U.zc_dotzf_dot >= 0.0) {
    /* Outport: '<Root>/Csa' incorporates:
     *  Constant: '<S1>/Constant'
     */
    sky_Y.Csa = sky_P.Constant_Value;
  } else {
    /* Outport: '<Root>/Csa' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    sky_Y.Csa = sky_P.Constant1_Value;
  }

  /* End of If: '<S1>/If' */
  /* End of Outputs for SubSystem: '<Root>/sky hook control' */

  /* Matfile logging */
  rt_UpdateTXYLogVars((&sky_M)->rtwLogInfo, (&(&sky_M)->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal((&sky_M))!=-1) &&
        !((rtmGetTFinal((&sky_M))-(&sky_M)->Timing.taskTime0) > (&sky_M)
          ->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus((&sky_M), "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++(&sky_M)->Timing.clockTick0)) {
    ++(&sky_M)->Timing.clockTickH0;
  }

  (&sky_M)->Timing.taskTime0 = (&sky_M)->Timing.clockTick0 * (&sky_M)
    ->Timing.stepSize0 + (&sky_M)->Timing.clockTickH0 * (&sky_M)
    ->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void skyModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal((&sky_M), 10.0);
  (&sky_M)->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    (&sky_M)->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo((&sky_M)->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs((&sky_M)->rtwLogInfo, (NULL));
    rtliSetLogT((&sky_M)->rtwLogInfo, "tout");
    rtliSetLogX((&sky_M)->rtwLogInfo, "");
    rtliSetLogXFinal((&sky_M)->rtwLogInfo, "");
    rtliSetLogVarNameModifier((&sky_M)->rtwLogInfo, "rt_");
    rtliSetLogFormat((&sky_M)->rtwLogInfo, 4);
    rtliSetLogMaxRows((&sky_M)->rtwLogInfo, 0);
    rtliSetLogDecimation((&sky_M)->rtwLogInfo, 1);
    rtliSetLogY((&sky_M)->rtwLogInfo, "");
    rtliSetLogYSignalInfo((&sky_M)->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs((&sky_M)->rtwLogInfo, (NULL));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime((&sky_M)->rtwLogInfo, 0.0, rtmGetTFinal
    ((&sky_M)), (&sky_M)->Timing.stepSize0, (&rtmGetErrorStatus((&sky_M))));
}

/* Model terminate function */
void skyModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
skyModelClass::skyModelClass():
  sky_U()
  ,sky_Y()
  ,sky_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
skyModelClass::~skyModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_sky_T * skyModelClass::getRTM()
{
  return (&sky_M);
}
