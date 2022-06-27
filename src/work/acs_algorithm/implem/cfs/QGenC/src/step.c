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

#include "step.h"

void Step_initStates
  (Step_State* const State)
{
   GAUINT8 i;

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail' */
   State->q_1_Fail_enabled = GATRUE;
   q_1_Fail_initStates (&State->q_1_Fail_memory);
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/2 Fails' */
   State->q_2_Fails_enabled = GATRUE;
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/2 Fails' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/Noone Fails1' */
   State->Noone_Fails1_enabled = GATRUE;
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/Noone Fails1' */

   /* Block 'Step/ACS_Algorithm/discretization/Memory' */
   for (i = 0; i <= 2; i++) {
      State->Memory_memory[i] = 0.0E+00;
   }
   /* End Block 'Step/ACS_Algorithm/discretization/Memory' */

}
void Step_initOutputs
  (Step_State* const State)
{
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail' */
   q_1_Fail_initOutputs (State->q_1_Fail_M_xyz, &State->q_1_Fail_memory);
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/2 Fails' */
   q_2_Fails_initOutputs (State->q_2_Fails_M_xyz);
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/2 Fails' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/Noone Fails1' */
   Noone_Fails1_initOutputs (State->Noone_Fails1_M_xyz);
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/Noone Fails1' */

}
void Step_comp
  (T_B_b_T const* const BBT,
   T_Omega const* const Omega,
   T_Float const K_PB,
   T_Float const K_PE,
   T_Float const M_M,
   T_MT_Working const* const MT_Working,
   T_Control* const Control,
   Step_State* const State)
{
   GASINGLE Cast_To_Single1_out1[3];
   /* Output from Step/Cast To Single1/OutDataPort1 */

   GASINGLE a_elements_out1[6];
   /* Output from Step/ACS_Algorithm/Control law/Cross Product/a elements/OutDataPort1 */

   GASINGLE Cast_To_Single_out1[15];
   /* Output from Step/Cast To Single/OutDataPort1 */

   GASINGLE Selector3_out1[5];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Selector3/OutDataPort1 */

   GASINGLE Selector4_out1[5];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Selector4/OutDataPort1 */

   GASINGLE Selector5_out1[5];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Selector5/OutDataPort1 */

   GASINGLE Gain_1_1_out1[3];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Media/Gain/OutDataPort1 */

   GASINGLE b_elements_out1[6];
   /* Output from Step/ACS_Algorithm/Control law/Cross Product/b elements/OutDataPort1 */

   GASINGLE Element_product_out1[6];
   /* Output from Step/ACS_Algorithm/Control law/Cross Product/Element product/OutDataPort1 */

   GASINGLE time_out1[5];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/time/OutDataPort1 */

   GASINGLE Sxy_out1[5];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sxy/OutDataPort1 */

   GASINGLE Sum1_1_out1;
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum1/OutDataPort1 */

   GASINGLE Sxx_out1[5];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sxx/OutDataPort1 */

   GASINGLE time_1_out1[5];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/time/OutDataPort1 */

   GASINGLE Sxy_1_out1[5];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sxy/OutDataPort1 */

   GASINGLE Sum1_1_1_out1;
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum1/OutDataPort1 */

   GASINGLE Sxx_1_out1[5];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sxx/OutDataPort1 */

   GASINGLE time_2_out1[5];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/time/OutDataPort1 */

   GASINGLE Sxy_2_out1[5];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sxy/OutDataPort1 */

   GASINGLE Sum1_2_out1;
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum1/OutDataPort1 */

   GASINGLE Sxx_2_out1[5];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sxx/OutDataPort1 */

   GASINGLE Mux_1_out1[3];
   /* Output from Step/ACS_Algorithm/Magnetic field calculation/Derivative/Mux/OutDataPort1 */

   GASINGLE Gain3_out1[3];
   /* Output from Step/ACS_Algorithm/Control law/Gain3/OutDataPort1 */

   GASINGLE Cast_To_Single5_out1[3];
   /* Output from Step/Cast To Single5/OutDataPort1 */

   GASINGLE Mux_out1[3];
   /* Output from Step/ACS_Algorithm/Limitation/Mux/OutDataPort1 */

   GASINGLE Gain_out1[3];
   /* Output from Step/ACS_Algorithm/Limitation/Gain/OutDataPort1 */

   T_Control Control_T_Control_BusCre_out1;
   /* Output from Step/Control_T_Control_BusCre/OutDataPort1 */

   GASINGLE Sum1_out1[3];
   /* Output from Step/ACS_Algorithm/If Fail Recalculate/Sum1/OutDataPort1 */

   GABOOL Relational_Operator_out1[3];
   /* Output from Step/ACS_Algorithm/Limitation/Relational Operator/OutDataPort1 */

   GABOOL Relational_Operator1_out1[3];
   /* Output from Step/ACS_Algorithm/Limitation/Relational Operator1/OutDataPort1 */

   GASINGLE Sum1_4_out1[3];
   /* Output from Step/ACS_Algorithm/discretization/Sum1/OutDataPort1 */

   GASINGLE Gain3_1_out1[3];
   /* Output from Step/ACS_Algorithm/discretization/Gain3/OutDataPort1 */

   GASINGLE Product_2_out1[3];
   /* Output from Step/ACS_Algorithm/discretization/Product/OutDataPort1 */

   const GAREAL a_elements_map1[6] = {2.0E+00, 3.0E+00, 1.0E+00, 3.0E+00, 1.0E+00, 2.0E+00};
   const GAREAL Selector3_map1[5] = {1.0E+00, 4.0E+00, 7.0E+00, 1.0E+01, 1.3E+01};
   const GAREAL Selector4_map1[5] = {2.0E+00, 5.0E+00, 8.0E+00, 1.1E+01, 1.4E+01};
   const GAREAL Selector5_map1[5] = {3.0E+00, 6.0E+00, 9.0E+00, 1.2E+01, 1.5E+01};
   const GAREAL b_elements_map1[6] = {3.0E+00, 1.0E+00, 2.0E+00, 2.0E+00, 3.0E+00, 1.0E+00};
   GAREAL Tmp[5];
   GAREAL Tmp_1[5];
   GAREAL Tmp_2[5];
   GAUINT8 i;
   GAUINT8 Idx1;
   GAUINT8 Idx;

   /* Block 'Step/DummyGround' */
   /* Block 'Step/Cast To Single1' */
   for (i = 0; i <= 2; i++) {
      Cast_To_Single1_out1[i] = 0.0E+00;
   }
   /* End Block 'Step/Cast To Single1' */
   /* End Block 'Step/DummyGround' */

   /* Block 'Step/ACS_Algorithm/Control law/Cross Product/a elements' */
   for (Idx1 = 0; Idx1 <= 5; Idx1++) {
      a_elements_out1[Idx1] = Cast_To_Single1_out1[(GAUINT32) (a_elements_map1[Idx1] - 1.0E+00)];
   }
   /* End Block 'Step/ACS_Algorithm/Control law/Cross Product/a elements' */

   /* Block 'Step/DummyGround' */
   /* Block 'Step/Cast To Single' */
   for (i = 0; i <= 14; i++) {
      Cast_To_Single_out1[i] = 0.0E+00;
   }
   /* End Block 'Step/Cast To Single' */
   /* End Block 'Step/DummyGround' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Selector3' */
   for (Idx1 = 0; Idx1 <= 4; Idx1++) {
      Selector3_out1[Idx1] = Cast_To_Single_out1[(GAUINT32) (Selector3_map1[Idx1] - 1.0E+00)];
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Selector3' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Selector4' */
   for (Idx1 = 0; Idx1 <= 4; Idx1++) {
      Selector4_out1[Idx1] = Cast_To_Single_out1[(GAUINT32) (Selector4_map1[Idx1] - 1.0E+00)];
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Selector4' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Selector5' */
   for (Idx1 = 0; Idx1 <= 4; Idx1++) {
      Selector5_out1[Idx1] = Cast_To_Single_out1[(GAUINT32) (Selector5_map1[Idx1] - 1.0E+00)];
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Selector5' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Media/Sum1' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Media/Demux' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Media/Gain' */
   for (i = 0; i <= 2; i++) {
      Gain_1_1_out1[i] = (GASINGLE) (1.0E+00 / 5.0E+00 * (GAREAL) (Cast_To_Single_out1[i] + Cast_To_Single_out1[i + 3] + Cast_To_Single_out1[i + 6] + Cast_To_Single_out1[i + 9] + Cast_To_Single_out1[i + 12]));
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Media/Gain' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Media/Demux' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Media/Sum1' */

   /* Block 'Step/ACS_Algorithm/Control law/Cross Product/b elements' */
   for (Idx1 = 0; Idx1 <= 5; Idx1++) {
      b_elements_out1[Idx1] = Gain_1_1_out1[(GAUINT32) (b_elements_map1[Idx1] - 1.0E+00)];
   }
   /* End Block 'Step/ACS_Algorithm/Control law/Cross Product/b elements' */

   /* Block 'Step/ACS_Algorithm/Control law/Cross Product/Element product' */
   for (i = 0; i <= 5; i++) {
      Element_product_out1[i] = a_elements_out1[i] * b_elements_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/Control law/Cross Product/Element product' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/time' */
   for (Idx = 0; Idx <= 4; Idx++) {
      Tmp[Idx] = (GAREAL) (1 + Idx);
   }
   for (i = 0; i <= 4; i++) {
      time_out1[i] = (GASINGLE) qgen_safe_div_gareal (Tmp[i], 5.0E+00);
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/time' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sxy' */
   for (i = 0; i <= 4; i++) {
      Sxy_out1[i] = time_out1[i] * Selector3_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sxy' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum1' */
   Sum1_1_out1 = time_out1[0] + time_out1[1] + time_out1[2] + time_out1[3] + time_out1[4];
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum1' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sxx' */
   for (i = 0; i <= 4; i++) {
      Sxx_out1[i] = time_out1[i] * time_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sxx' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/time' */
   for (Idx = 0; Idx <= 4; Idx++) {
      Tmp_1[Idx] = (GAREAL) (1 + Idx);
   }
   for (i = 0; i <= 4; i++) {
      time_1_out1[i] = (GASINGLE) qgen_safe_div_gareal (Tmp_1[i], 5.0E+00);
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/time' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sxy' */
   for (i = 0; i <= 4; i++) {
      Sxy_1_out1[i] = time_1_out1[i] * Selector4_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sxy' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum1' */
   Sum1_1_1_out1 = time_1_out1[0] + time_1_out1[1] + time_1_out1[2] + time_1_out1[3] + time_1_out1[4];
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum1' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sxx' */
   for (i = 0; i <= 4; i++) {
      Sxx_1_out1[i] = time_1_out1[i] * time_1_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sxx' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/time' */
   for (Idx = 0; Idx <= 4; Idx++) {
      Tmp_2[Idx] = (GAREAL) (1 + Idx);
   }
   for (i = 0; i <= 4; i++) {
      time_2_out1[i] = (GASINGLE) qgen_safe_div_gareal (Tmp_2[i], 5.0E+00);
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/time' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sxy' */
   for (i = 0; i <= 4; i++) {
      Sxy_2_out1[i] = time_2_out1[i] * Selector5_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sxy' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum1' */
   Sum1_2_out1 = time_2_out1[0] + time_2_out1[1] + time_2_out1[2] + time_2_out1[3] + time_2_out1[4];
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum1' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sxx' */
   for (i = 0; i <= 4; i++) {
      Sxx_2_out1[i] = time_2_out1[i] * time_2_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sxx' */

   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Gain2' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum4' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum5' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/NSxx' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/SxSx' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum3' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum2' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/N' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/NSxy' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/SxSy ' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/NSx2' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Gain1' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum4' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum5' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/NSxx' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/SxSx' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum3' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum2' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/N' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/NSxy' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/SxSy ' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/NSx2' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Gain' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum4' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum5' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/NSxx' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/SxSx' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum3' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum2' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/N' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/NSxy' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/SxSy ' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/NSx2' */
   /* Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Mux' */
   Mux_1_out1[0] = (GASINGLE) (-1.0E+00 * ((5.0E+00 * (Sxy_out1[0] + Sxy_out1[1] + Sxy_out1[2] + Sxy_out1[3] + Sxy_out1[4]) - Sum1_1_out1 * (Selector3_out1[0] + Selector3_out1[1] + Selector3_out1[2] + Selector3_out1[3] + Selector3_out1[4])) / (5.0E+00 * (Sxx_out1[0] + Sxx_out1[1] + Sxx_out1[2] + Sxx_out1[3] + Sxx_out1[4]) - Sum1_1_out1 * Sum1_1_out1)));
   Mux_1_out1[1] = (GASINGLE) (-1.0E+00 * ((5.0E+00 * (Sxy_1_out1[0] + Sxy_1_out1[1] + Sxy_1_out1[2] + Sxy_1_out1[3] + Sxy_1_out1[4]) - Sum1_1_1_out1 * (Selector4_out1[0] + Selector4_out1[1] + Selector4_out1[2] + Selector4_out1[3] + Selector4_out1[4])) / (5.0E+00 * (Sxx_1_out1[0] + Sxx_1_out1[1] + Sxx_1_out1[2] + Sxx_1_out1[3] + Sxx_1_out1[4]) - Sum1_1_1_out1 * Sum1_1_1_out1)));
   Mux_1_out1[2] = (GASINGLE) (-1.0E+00 * ((5.0E+00 * (Sxy_2_out1[0] + Sxy_2_out1[1] + Sxy_2_out1[2] + Sxy_2_out1[3] + Sxy_2_out1[4]) - Sum1_2_out1 * (Selector5_out1[0] + Selector5_out1[1] + Selector5_out1[2] + Selector5_out1[3] + Selector5_out1[4])) / (5.0E+00 * (Sxx_2_out1[0] + Sxx_2_out1[1] + Sxx_2_out1[2] + Sxx_2_out1[3] + Sxx_2_out1[4]) - Sum1_2_out1 * Sum1_2_out1)));
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Mux' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/NSx2' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/SxSy ' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/NSxy' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/N' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum2' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum3' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/SxSx' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/NSxx' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum5' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit/Sum4' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Gain' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/NSx2' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/SxSy ' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/NSxy' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/N' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum2' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum3' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/SxSx' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/NSxx' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum5' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit1/Sum4' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Gain1' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/NSx2' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/SxSy ' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/NSxy' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/N' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum2' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum3' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/SxSx' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/NSxx' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum5' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Polyfit2/Sum4' */
   /* End Block 'Step/ACS_Algorithm/Magnetic field calculation/Derivative/Gain2' */

   /* Block 'Step/ACS_Algorithm/Control law/Product' */
   /* Block 'Step/ACS_Algorithm/Control law/Cross Product/Add3' */
   /* Block 'Step/ACS_Algorithm/Control law/Cross Product/Demux2' */
   /* Block 'Step/ACS_Algorithm/Control law/Sum' */
   /* Block 'Step/DummyGround' */
   /* Block 'Step/Cast To Single2' */
   /* Block 'Step/Cast To Single3' */
   /* Block 'Step/ACS_Algorithm/Control law/Math Function' */
   /* Block 'Step/ACS_Algorithm/Control law/Gain3' */
   for (i = 0; i <= 2; i++) {
      Gain3_out1[i] = 0.0E+00;
   }
   /* End Block 'Step/ACS_Algorithm/Control law/Gain3' */
   /* End Block 'Step/ACS_Algorithm/Control law/Math Function' */
   /* End Block 'Step/Cast To Single3' */
   /* End Block 'Step/Cast To Single2' */
   /* End Block 'Step/DummyGround' */
   /* End Block 'Step/ACS_Algorithm/Control law/Sum' */
   /* End Block 'Step/ACS_Algorithm/Control law/Cross Product/Demux2' */
   /* End Block 'Step/ACS_Algorithm/Control law/Cross Product/Add3' */
   /* End Block 'Step/ACS_Algorithm/Control law/Product' */

   /* Block 'Step/DummyGround' */
   /* Block 'Step/Cast To Single5' */
   for (i = 0; i <= 2; i++) {
      Cast_To_Single5_out1[i] = 0.0E+00;
   }
   /* End Block 'Step/Cast To Single5' */
   /* End Block 'Step/DummyGround' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/Sum of Elements3' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/Compare To Constant1' */
   State->Compare_To_Constant1_out1 = (GAUINT8) (Cast_To_Single5_out1[0] + Cast_To_Single5_out1[1] + Cast_To_Single5_out1[2] == 1.0E+00);
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/Compare To Constant1' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/Sum of Elements3' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/Sum of Elements1' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/Compare To Constant2' */
   State->Compare_To_Constant2_out1 = (GAUINT8) (Cast_To_Single5_out1[0] + Cast_To_Single5_out1[1] + Cast_To_Single5_out1[2] == 2.0E+00);
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/Compare To Constant2' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/Sum of Elements1' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/Sum of Elements2' */
   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/Compare To Constant3' */
   State->Compare_To_Constant3_out1 = (GAUINT8) (Cast_To_Single5_out1[0] + Cast_To_Single5_out1[1] + Cast_To_Single5_out1[2] == 3.0E+00);
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/Compare To Constant3' */
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/Sum of Elements2' */

   /* Block 'Step/Cast To Single4' */
   /* Block 'Step/DummyGround' */
   /* Block 'Step/ACS_Algorithm/Limitation/Mux' */
   Mux_out1[0] = 0.0E+00;
   Mux_out1[1] = 0.0E+00;
   Mux_out1[2] = 0.0E+00;
   /* End Block 'Step/ACS_Algorithm/Limitation/Mux' */
   /* End Block 'Step/DummyGround' */
   /* End Block 'Step/Cast To Single4' */

   /* Block 'Step/ACS_Algorithm/Limitation/Gain' */
   for (i = 0; i <= 2; i++) {
      Gain_out1[i] = 2.5E-01 * Mux_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/Limitation/Gain' */

   /* Block 'Step/DummyGround' */
   /* Block 'Step/Control_T_Control_BusCre' */
   for (i = 0; i <= 2; i++) {
      Control_T_Control_BusCre_out1.element_data[i] = 0.0E+00;
   }
   /* End Block 'Step/Control_T_Control_BusCre' */
   /* End Block 'Step/DummyGround' */

   /* Block 'Step/Control' */
   *Control = Control_T_Control_BusCre_out1;
   /* End Block 'Step/Control' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail' */
   if (State->Compare_To_Constant2_out1 > 0) {
      State->q_1_Fail_enabled = GATRUE;
      q_1_Fail_comp (Cast_To_Single5_out1, Gain3_out1, Gain_1_1_out1, State->q_1_Fail_M_xyz, &State->q_1_Fail_memory);
   }
   else {
      State->q_1_Fail_enabled = GAFALSE;
   }
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/1 Fail' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/2 Fails' */
   if (State->Compare_To_Constant1_out1 > 0) {
      State->q_2_Fails_enabled = GATRUE;
      q_2_Fails_comp (Cast_To_Single5_out1, Gain3_out1, State->q_2_Fails_M_xyz);
   }
   else {
      State->q_2_Fails_enabled = GAFALSE;
   }
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/2 Fails' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/Noone Fails1' */
   if (State->Compare_To_Constant3_out1 > 0) {
      State->Noone_Fails1_enabled = GATRUE;
      Noone_Fails1_comp (Gain3_out1, State->Noone_Fails1_M_xyz);
   }
   else {
      State->Noone_Fails1_enabled = GAFALSE;
   }
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/Noone Fails1' */

   /* Block 'Step/ACS_Algorithm/If Fail Recalculate/Sum1' */
   for (i = 0; i <= 2; i++) {
      Sum1_out1[i] = State->Noone_Fails1_M_xyz[i] + State->q_1_Fail_M_xyz[i] + State->q_2_Fails_M_xyz[i];
   }
   /* End Block 'Step/ACS_Algorithm/If Fail Recalculate/Sum1' */

   /* Block 'Step/ACS_Algorithm/Limitation/Relational Operator' */
   for (i = 0; i <= 2; i++) {
      Relational_Operator_out1[i] = Sum1_out1[i] >= Gain_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/Limitation/Relational Operator' */

   /* Block 'Step/ACS_Algorithm/Limitation/Gain1' */
   /* Block 'Step/ACS_Algorithm/Limitation/Relational Operator1' */
   for (i = 0; i <= 2; i++) {
      Relational_Operator1_out1[i] = Sum1_out1[i] <= -1.0E+00 * Gain_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/Limitation/Relational Operator1' */
   /* End Block 'Step/ACS_Algorithm/Limitation/Gain1' */

   /* Block 'Step/ACS_Algorithm/discretization/Gain4' */
   /* Block 'Step/ACS_Algorithm/discretization/Gain5' */
   /* Block 'Step/ACS_Algorithm/Limitation/Product1' */
   /* Block 'Step/ACS_Algorithm/Limitation/Gain2' */
   /* Block 'Step/ACS_Algorithm/Limitation/Data Type Conversion2' */
   /* Block 'Step/ACS_Algorithm/Limitation/Product2' */
   /* Block 'Step/ACS_Algorithm/Limitation/Logical Operator2' */
   /* Block 'Step/ACS_Algorithm/Limitation/Logical Operator' */
   /* Block 'Step/ACS_Algorithm/Limitation/Logical Operator1' */
   /* Block 'Step/ACS_Algorithm/Limitation/Data Type Conversion1' */
   /* Block 'Step/ACS_Algorithm/Limitation/Product' */
   /* Block 'Step/ACS_Algorithm/Limitation/Data Type Conversion' */
   /* Block 'Step/ACS_Algorithm/Limitation/Add' */
   /* Block 'Step/Cast To Single4' */
   /* Block 'Step/DummyGround' */
   /* Block 'Step/ACS_Algorithm/discretization/Product1' */
   /* Block 'Step/ACS_Algorithm/discretization/Memory' */
   /* Block 'Step/ACS_Algorithm/discretization/Sum1' */
   for (i = 0; i <= 2; i++) {
      Sum1_4_out1[i] = (GASINGLE) ((GAREAL) State->Memory_memory[i] + 5.0E-01 * (1.0E+00 / 2.5E-01 * (GAREAL) ((GASINGLE) Relational_Operator_out1[i] * Gain_out1[i] + Sum1_out1[i] * (GASINGLE) (!Relational_Operator_out1[i] && !Relational_Operator1_out1[i]) + -1.0E+00 * Gain_out1[i] * (GASINGLE) Relational_Operator1_out1[i]) / 0.0E+00));
   }
   /* End Block 'Step/ACS_Algorithm/discretization/Sum1' */
   /* End Block 'Step/ACS_Algorithm/discretization/Memory' */
   /* End Block 'Step/ACS_Algorithm/discretization/Product1' */
   /* End Block 'Step/DummyGround' */
   /* End Block 'Step/Cast To Single4' */
   /* End Block 'Step/ACS_Algorithm/Limitation/Add' */
   /* End Block 'Step/ACS_Algorithm/Limitation/Data Type Conversion' */
   /* End Block 'Step/ACS_Algorithm/Limitation/Product' */
   /* End Block 'Step/ACS_Algorithm/Limitation/Data Type Conversion1' */
   /* End Block 'Step/ACS_Algorithm/Limitation/Logical Operator1' */
   /* End Block 'Step/ACS_Algorithm/Limitation/Logical Operator' */
   /* End Block 'Step/ACS_Algorithm/Limitation/Logical Operator2' */
   /* End Block 'Step/ACS_Algorithm/Limitation/Product2' */
   /* End Block 'Step/ACS_Algorithm/Limitation/Data Type Conversion2' */
   /* End Block 'Step/ACS_Algorithm/Limitation/Gain2' */
   /* End Block 'Step/ACS_Algorithm/Limitation/Product1' */
   /* End Block 'Step/ACS_Algorithm/discretization/Gain5' */
   /* End Block 'Step/ACS_Algorithm/discretization/Gain4' */

   /* Block 'Step/ACS_Algorithm/discretization/Rounding Function' */
   /* Block 'Step/ACS_Algorithm/discretization/Gain1' */
   /* Block 'Step/ACS_Algorithm/discretization/Gain3' */
   for (i = 0; i <= 2; i++) {
      Gain3_1_out1[i] = 1.0E-01 * qgen_round_gasingle (1.0E+01 * Sum1_4_out1[i]);
   }
   /* End Block 'Step/ACS_Algorithm/discretization/Gain3' */
   /* End Block 'Step/ACS_Algorithm/discretization/Gain1' */
   /* End Block 'Step/ACS_Algorithm/discretization/Rounding Function' */

   /* Block 'Step/ACS_Algorithm/discretization/Data Type Conversion' */
   /* Block 'Step/ACS_Algorithm/discretization/Abs' */
   /* Block 'Step/ACS_Algorithm/discretization/Compare To Constant' */
   /* Block 'Step/ACS_Algorithm/discretization/Product' */
   for (i = 0; i <= 2; i++) {
      Product_2_out1[i] = Gain3_1_out1[i] * (GASINGLE) (qgen_abs_gasingle (Gain3_1_out1[i]) >= 2.0E-01);
   }
   /* End Block 'Step/ACS_Algorithm/discretization/Product' */
   /* End Block 'Step/ACS_Algorithm/discretization/Compare To Constant' */
   /* End Block 'Step/ACS_Algorithm/discretization/Abs' */
   /* End Block 'Step/ACS_Algorithm/discretization/Data Type Conversion' */

   /* Block 'Step/ACS_Algorithm/discretization/Sum' */
   for (i = 0; i <= 2; i++) {
      State->Sum_3_out1[i] = Sum1_4_out1[i] - Product_2_out1[i];
   }
   /* End Block 'Step/ACS_Algorithm/discretization/Sum' */

}
void Step_up
  (Step_State* const State)
{
   GAUINT8 i;

   /* update 'Step/ACS_Algorithm/discretization/Memory' */
   for (i = 0; i <= 2; i++) {
      State->Memory_memory[i] = State->Sum_3_out1[i];
   }
   /* End update 'Step/ACS_Algorithm/discretization/Memory' */

}
/*  @EOF  */
