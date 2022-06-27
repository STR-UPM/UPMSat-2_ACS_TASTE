T_Float = Simulink.AliasType;
T_Float.BaseType = 'double';
T_Float.Description = 'range is (-3.4e+38, 3.4e+38)';

T_B_b_T_member_data=Simulink.BusElement;
T_B_b_T_member_data.Name='element_data';
T_B_b_T_member_data.DataType='double';
T_B_b_T_member_data.Dimensions=15;

T_B_b_T=Simulink.Bus;
T_B_b_T.Elements = [T_B_b_T_member_data ];

T_Omega_member_data=Simulink.BusElement;
T_Omega_member_data.Name='element_data';
T_Omega_member_data.DataType='double';
T_Omega_member_data.Dimensions=3;

T_Omega=Simulink.Bus;
T_Omega.Elements = [T_Omega_member_data ];

T_MT_Working_member_data=Simulink.BusElement;
T_MT_Working_member_data.Name='element_data';
T_MT_Working_member_data.DataType='double';
T_MT_Working_member_data.Dimensions=3;

T_MT_Working=Simulink.Bus;
T_MT_Working.Elements = [T_MT_Working_member_data ];

T_Control_member_data=Simulink.BusElement;
T_Control_member_data.Name='element_data';
T_Control_member_data.DataType='double';
T_Control_member_data.Dimensions=3;

T_Control=Simulink.Bus;
T_Control.Elements = [T_Control_member_data ];

T_Int32 = Simulink.AliasType;
T_Int32.BaseType = 'int32';
T_Int32.Description = 'range is (-2147483648, 2147483647)';

T_UInt32 = Simulink.AliasType;
T_UInt32.BaseType = 'uint32';
T_UInt32.Description = 'range is (0, 4294967295)';

T_Int8 = Simulink.AliasType;
T_Int8.BaseType = 'int8';
T_Int8.Description = 'range is (-128, 127)';

T_UInt8 = Simulink.AliasType;
T_UInt8.BaseType = 'uint8';
T_UInt8.Description = 'range is (0, 255)';

T_Boolean = Simulink.AliasType;
T_Boolean.BaseType = 'boolean';
T_Boolean.Description = 'A simple BOOLEAN';

