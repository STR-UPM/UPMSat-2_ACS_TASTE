--  Copyright (C) Your Company Name
--
--  @generated with QGen Code Generator 22.1 (20220109)
--  Command line arguments: ./xmi/Step.xmi
--    --gen-entrypoint
--    --wrap-io
--    --pre-process-xmi
--    --incremental
--    --no-misra
--    --language ada
--    --output src

pragma Style_Checks ("M999");  --  ignore long lines

package body Step is

   procedure comp
      (BBT : T_B_b_T;
       Omega : T_Omega;
       K_PB : T_Float;
       K_PE : T_Float;
       M_M : T_Float;
       MT_Working : T_MT_Working;
       Control : out T_Control)
   is
      Control_T_Control_BusCre_out1 : T_Control;
   --  Output from Step/Control_T_Control_BusCre/OutDataPort1

   begin
      --  Block 'Step/DummyGround'
      --  Block 'Step/Control_T_Control_BusCre'

      for i in 1 .. 3 loop
         Control_T_Control_BusCre_out1.element_data (i) := 0.0E+00;
      end loop;

      --  End Block 'Step/Control_T_Control_BusCre'
      --  End Block 'Step/DummyGround'

      --  Block 'Step/Control'
      Control := Control_T_Control_BusCre_out1;
      --  End Block 'Step/Control'
   end comp;
end Step;
--  @EOF
