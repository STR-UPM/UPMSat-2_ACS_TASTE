/* Copyright (C) Your Company Name */
/*
 * @generated with QGen Code Generator 22.1 (20220109)
 * Command line arguments: ./xmi/Step.xmi
 *   --gen-entrypoint
 *   --wrap-io
 *   --pre-process-xmi
 *   --incremental
 *   --no-misra
 *   --language c
 *   --output src
*/

#ifndef STEP_STATES_H
#define STEP_STATES_H
#include "qgen_types.h"
#include "q_1_fail_states.h"

typedef struct {
   GASINGLE q_1_Fail_M_xyz[3];
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/1 Fail/OutDataPort1 */

   GASINGLE q_2_Fails_M_xyz[3];
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/2 Fails/OutDataPort1 */

   GASINGLE Noone_Fails1_M_xyz[3];
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/Noone Fails1/OutDataPort1 */

   GABOOL q_1_Fail_enabled;
   GABOOL q_2_Fails_enabled;
   GABOOL Noone_Fails1_enabled;
   GASINGLE Memory_memory[3];
   /* Memory from Step/ACS_Algorithm/discretization/Memory */

   GAUINT8 Compare_To_Constant2_out1;
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/Compare To Constant2/OutDataPort1 */

   GAUINT8 Compare_To_Constant1_out1;
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/Compare To Constant1/OutDataPort1 */

   GAUINT8 Compare_To_Constant3_out1;
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/Compare To Constant3/OutDataPort1 */

   GASINGLE Sum_3_out1[3];
   /* Output from Step/ACS_Algorithm/discretization/Sum/OutDataPort1 */

   q_1_Fail_State q_1_Fail_memory;
} Step_State;

#endif
/*  @EOF  */
