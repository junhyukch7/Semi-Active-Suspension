/*
 * Hybrid.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Hybrid".
 *
 * Model version              : 1.35
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Mon Mar  8 19:22:44 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Hybrid.h"
#include "Hybrid_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_Hybrid_T Hybrid_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Hybrid_T Hybrid_Y;

/* Real-time model */
RT_MODEL_Hybrid_T Hybrid_M_;
RT_MODEL_Hybrid_T *const Hybrid_M = &Hybrid_M_;

/*
 * Output and update for action system:
 *    '<S1>/If Action Subsystem'
 *    '<S1>/If Action Subsystem2'
 */
void Hybrid_IfActionSubsystem(real_T rtu_In1, real_T *rty_Csa)
{
  /* Inport: '<S2>/In1' */
  *rty_Csa = rtu_In1;
}

/*
 * Output and update for action system:
 *    '<S1>/If Action Subsystem1'
 *    '<S1>/If Action Subsystem3'
 */
void Hybrid_IfActionSubsystem1(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S3>/In1' */
  *rty_Out1 = rtu_In1;
}

/* Model step function */
void Hybrid_step(void)
{
  real_T rtb_Merge;
  real_T rtb_Merge1;

  /* If: '<S1>/If' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Inport: '<Root>/zc_dot'
   *  Inport: '<Root>/zc_dot - zf_dot'
   *  Product: '<S1>/Product'
   */
  if (Hybrid_U.zc_dot * Hybrid_U.zc_dotzf_dot >= 0.0) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    Hybrid_IfActionSubsystem(Hybrid_P.Constant_Value, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    Hybrid_IfActionSubsystem1(Hybrid_P.Constant1_Value, &rtb_Merge);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */
  }

  /* End of If: '<S1>/If' */

  /* If: '<S1>/If1' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   *  Inport: '<Root>/-zf_dot*(zc_dot-zf_dot)'
   */
  if (Hybrid_U.zf_dotzc_dotzf_dot >= 0.0) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    Hybrid_IfActionSubsystem(Hybrid_P.Constant2_Value, &rtb_Merge1);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem2' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    Hybrid_IfActionSubsystem1(Hybrid_P.Constant3_Value, &rtb_Merge1);

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem3' */
  }

  /* End of If: '<S1>/If1' */

  /* Outport: '<Root>/Csa' incorporates:
   *  Sum: '<S1>/Add'
   */
  Hybrid_Y.Csa = rtb_Merge + rtb_Merge1;

  /* Matfile logging */
  rt_UpdateTXYLogVars(Hybrid_M->rtwLogInfo, (&Hybrid_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(Hybrid_M)!=-1) &&
        !((rtmGetTFinal(Hybrid_M)-Hybrid_M->Timing.taskTime0) >
          Hybrid_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Hybrid_M, "Simulation finished");
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
  if (!(++Hybrid_M->Timing.clockTick0)) {
    ++Hybrid_M->Timing.clockTickH0;
  }

  Hybrid_M->Timing.taskTime0 = Hybrid_M->Timing.clockTick0 *
    Hybrid_M->Timing.stepSize0 + Hybrid_M->Timing.clockTickH0 *
    Hybrid_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Hybrid_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Hybrid_M, 0,
                sizeof(RT_MODEL_Hybrid_T));
  rtmSetTFinal(Hybrid_M, 10.0);
  Hybrid_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    Hybrid_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Hybrid_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Hybrid_M->rtwLogInfo, (NULL));
    rtliSetLogT(Hybrid_M->rtwLogInfo, "tout");
    rtliSetLogX(Hybrid_M->rtwLogInfo, "");
    rtliSetLogXFinal(Hybrid_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Hybrid_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Hybrid_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Hybrid_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Hybrid_M->rtwLogInfo, 1);
    rtliSetLogY(Hybrid_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Hybrid_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Hybrid_M->rtwLogInfo, (NULL));
  }

  /* external inputs */
  (void)memset(&Hybrid_U, 0, sizeof(ExtU_Hybrid_T));

  /* external outputs */
  Hybrid_Y.Csa = 0.0;

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Hybrid_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Hybrid_M), Hybrid_M->Timing.stepSize0, (&rtmGetErrorStatus(Hybrid_M)));
}

/* Model terminate function */
void Hybrid_terminate(void)
{
  /* (no terminate code required) */
}
