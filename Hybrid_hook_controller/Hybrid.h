/*
 * Hybrid.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Hybrid".
 *
 * Model version              : 1.35
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Mon Mar  8 20:00:30 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Hybrid_h_
#define RTW_HEADER_Hybrid_h_
#include <cfloat>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "Hybrid_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T zc_dot;                       /* '<Root>/zc_dot' */
  real_T zc_dotzf_dot;                 /* '<Root>/zc_dot - zf_dot' */
  real_T zf_dotzc_dotzf_dot;           /* '<Root>/-zf_dot*(zc_dot-zf_dot)' */
} ExtU_Hybrid_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Csa;                          /* '<Root>/Csa' */
} ExtY_Hybrid_T;

/* Parameters (default storage) */
struct P_Hybrid_T_ {
  real_T Constant1_Value;              /* Expression: 258
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 2838
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 258
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant2_Value;              /* Expression: 2838
                                        * Referenced by: '<S1>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Hybrid_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Class declaration for model Hybrid */
class HybridModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  HybridModelClass();

  /* Destructor */
  ~HybridModelClass();

  /* Root-level structure-based inputs set method */

  /* Root inports set method */
  void setExternalInputs(const ExtU_Hybrid_T* pExtU_Hybrid_T)
  {
    Hybrid_U = *pExtU_Hybrid_T;
  }

  /* Root-level structure-based outputs get method */

  /* Root outports get method */
  const ExtY_Hybrid_T & getExternalOutputs() const
  {
    return Hybrid_Y;
  }

  /* Real-Time Model get method */
  RT_MODEL_Hybrid_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_Hybrid_T Hybrid_P;

  /* External inputs */
  ExtU_Hybrid_T Hybrid_U;

  /* External outputs */
  ExtY_Hybrid_T Hybrid_Y;

  /* Real-Time Model */
  RT_MODEL_Hybrid_T Hybrid_M;

  /* private member function(s) for subsystem '<S1>/If Action Subsystem'*/
  void Hybrid_IfActionSubsystem(real_T rtu_In1, real_T *rty_Csa);

  /* private member function(s) for subsystem '<S1>/If Action Subsystem1'*/
  void Hybrid_IfActionSubsystem1(real_T rtu_In1, real_T *rty_Out1);
};

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('suspension_controller_road_condition1/hybrid hook/front_sum/Hybrid controller')    - opens subsystem suspension_controller_road_condition1/hybrid hook/front_sum/Hybrid controller
 * hilite_system('suspension_controller_road_condition1/hybrid hook/front_sum/Hybrid controller/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'suspension_controller_road_condition1/hybrid hook/front_sum'
 * '<S1>'   : 'suspension_controller_road_condition1/hybrid hook/front_sum/Hybrid controller'
 * '<S2>'   : 'suspension_controller_road_condition1/hybrid hook/front_sum/Hybrid controller/If Action Subsystem'
 * '<S3>'   : 'suspension_controller_road_condition1/hybrid hook/front_sum/Hybrid controller/If Action Subsystem1'
 * '<S4>'   : 'suspension_controller_road_condition1/hybrid hook/front_sum/Hybrid controller/If Action Subsystem2'
 * '<S5>'   : 'suspension_controller_road_condition1/hybrid hook/front_sum/Hybrid controller/If Action Subsystem3'
 */
#endif                                 /* RTW_HEADER_Hybrid_h_ */
