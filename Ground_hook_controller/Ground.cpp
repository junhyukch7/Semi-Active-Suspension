/*
 * Ground.cpp
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Ground".
 *
 * Model version              : 1.35
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Mon Mar  8 19:59:50 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Ground.h"
#include "Ground_private.h"

/* Model step function */
void GroundModelClass::step()
{
  /* Outputs for Atomic SubSystem: '<Root>/Ground hook control' */
  /* If: '<S1>/If' incorporates:
   *  Inport: '<Root>/(zc_dot-zf_dot)*-zf_dot'
   */
  if (Ground_U.zc_dotzf_dotzf_dot >= 0.0) {
    /* Outport: '<Root>/Out1' incorporates:
     *  Constant: '<S1>/Constant'
     */
    Ground_Y.Out1 = Ground_P.Constant_Value;
  } else {
    /* Outport: '<Root>/Out1' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    Ground_Y.Out1 = Ground_P.Constant1_Value;
  }

  /* End of If: '<S1>/If' */
  /* End of Outputs for SubSystem: '<Root>/Ground hook control' */

  /* Matfile logging */
  rt_UpdateTXYLogVars((&Ground_M)->rtwLogInfo, (&(&Ground_M)->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal((&Ground_M))!=-1) &&
        !((rtmGetTFinal((&Ground_M))-(&Ground_M)->Timing.taskTime0) > (&Ground_M)
          ->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus((&Ground_M), "Simulation finished");
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
  if (!(++(&Ground_M)->Timing.clockTick0)) {
    ++(&Ground_M)->Timing.clockTickH0;
  }

  (&Ground_M)->Timing.taskTime0 = (&Ground_M)->Timing.clockTick0 * (&Ground_M)
    ->Timing.stepSize0 + (&Ground_M)->Timing.clockTickH0 * (&Ground_M)
    ->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void GroundModelClass::initialize()
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal((&Ground_M), 10.0);
  (&Ground_M)->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    (&Ground_M)->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo((&Ground_M)->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs((&Ground_M)->rtwLogInfo, (NULL));
    rtliSetLogT((&Ground_M)->rtwLogInfo, "tout");
    rtliSetLogX((&Ground_M)->rtwLogInfo, "");
    rtliSetLogXFinal((&Ground_M)->rtwLogInfo, "");
    rtliSetLogVarNameModifier((&Ground_M)->rtwLogInfo, "rt_");
    rtliSetLogFormat((&Ground_M)->rtwLogInfo, 4);
    rtliSetLogMaxRows((&Ground_M)->rtwLogInfo, 0);
    rtliSetLogDecimation((&Ground_M)->rtwLogInfo, 1);
    rtliSetLogY((&Ground_M)->rtwLogInfo, "");
    rtliSetLogYSignalInfo((&Ground_M)->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs((&Ground_M)->rtwLogInfo, (NULL));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime((&Ground_M)->rtwLogInfo, 0.0, rtmGetTFinal
    ((&Ground_M)), (&Ground_M)->Timing.stepSize0, (&rtmGetErrorStatus((&Ground_M))));
}

/* Model terminate function */
void GroundModelClass::terminate()
{
  /* (no terminate code required) */
}

/* Constructor */
GroundModelClass::GroundModelClass():
  Ground_U()
  ,Ground_Y()
  ,Ground_M()
{
  /* Currently there is no constructor body generated.*/
}

/* Destructor */
GroundModelClass::~GroundModelClass()
{
  /* Currently there is no destructor body generated.*/
}

/* Real-Time Model get method */
RT_MODEL_Ground_T * GroundModelClass::getRTM()
{
  return (&Ground_M);
}
