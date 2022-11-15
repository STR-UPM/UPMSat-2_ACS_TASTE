# Simulated Data

This module contains the simualted data that feeds the ACS control algorithm.
This data was orginally obtained as the `control_Reference_Model.output.sl.txt` file from **QGen Debugger** and then it was transformed and embedded into a matrix gathering all those values.

The `simulated_data` module contains such matrix, named `test_vector`, where the 5001 rows represent each simulation step. The following describes each column meaning:

- `test_vector [ 0..14]`: `BBT`        input  signal.
- `test_vector [15..17]`: `Control`    output signal.
- `test_vector [18..20]`: `MT_Working` input  signal.
- `test_vector [21..23]`: `Omega`      input  signal.
- `test_vector [24]`    : `KPb`        input  signal.
- `test_vector [25]`    : `KPe`        input  signal.
- `test_vector [26]`    : `MM`         input  signal.
