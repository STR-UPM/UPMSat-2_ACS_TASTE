# UPMSat-2 ACS in TASTE: A simple demo for the usage of QGen, Simulink, and TASTE.

This repository contains a simple demo to illustrate the bindings between the Simulink models and the QGen code generator, in the [TASTE](https://taste.tools/) architecture model. TASTE is an open-source tool-set developed and maintained by ESA for the development of heterogeneous real-time embedded software.

The demo includes the Simulink models used in the UPMSat-2 microsatellite, in orbit since the 3 September 2020. Essentially, the UPMSat-2 ACS subsystem determines the satellite's attitude, that is, its orientation relative to the Earth's surface. To do so, the satellite is equipped with three magnetometers, each measuring all three axes, and three magnetic torquers (AKA magnetorquers), one per axes.

For a detailed guideline and description of this demo, please refer to [the QGen tutorial from the TASTE wiki](https://taste.tuxfamily.org/wiki/index.php?title=QGen)
