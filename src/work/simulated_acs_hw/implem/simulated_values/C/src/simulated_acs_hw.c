//  ------------------------------------------------------------------------
//
//                           Q G e n   T u t o r i a l
//
//                       Simulated ACS Hardware component
//
//           Copyright (C) 2022 Universidad Politécnica de Madrid
//
//  This is free software;  you can redistribute it  and/or modify it  under
//  terms of the  GNU General Public License as published  by the Free Soft-
//  ware  Foundation;  either version 3,  or (at your option) any later ver-
//  sion.  This software is distributed in the hope  that it will be useful,
//  but WITHOUT ANY WARRANTY;  without even the implied warranty of MERCHAN-
//  TABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
//  License for  more details.  You should have  received  a copy of the GNU
//  General  Public  License  distributed  with  this  software;   see  file
//  COPYING3.  If not, go to http://www.gnu.org/licenses for a complete copy
//  of the license.
//
//  ------------------------------------------------------------------------

#include "simulated_acs_hw.h"

#include "simulated_data.h" // test_vector

#include <stdio.h>
#include <stdbool.h>

// -- Private types & constants:

static const size_t nrows = sizeof(test_vector) / sizeof(test_vector[0]);

static const size_t bbt_offset =  0U;
static const size_t bbt_length = 15U;
static const size_t control_offset = 15U;
static const size_t control_length =  3U;

static const double tolerance = 0.0F;
static size_t step = 0U;

// -- Private functions:

static float v_abs(float x) {
    return (x < 0.0F) ? -(x) : (x);
}

// Obtained from QGen Debugger compare_support:
static bool Are_Equal (float Expected, float Actual) {
    static float PInf =  1/0.0;
    static float NInf = -1/0.0;

    /* Take into account +Inf, -Inf and NaN for C and Simulink */
    return ((Expected == PInf) && (Actual == PInf))
        || ((Expected == NInf) && (Actual == NInf))
        || ((Expected != Expected) && (Actual != Actual))
        || (v_abs(Expected - Actual) <= tolerance);
}

static bool has_next() {
    bool can_continue = step < nrows;

    if (!can_continue) {
        static bool msg_printed = false;
        if (!msg_printed) {
            puts("End of simulation");
            msg_printed = true;
        }
    }

    return can_continue;
}

// Provided interfaces implementation:

void simulated_acs_hw_startup(void) {
   puts ("[Simulated_ACS_HW] Startup");
}

void simulated_acs_hw_PI_Read_MGM (asn1SccT_B_b_T *OUT_bbt) {
    size_t i;
    for (i = 0U; i < bbt_length; ++i) {
        OUT_bbt->arr[i] = (asn1SccT_Float) test_vector[step][bbt_offset + i];
    }
}

void simulated_acs_hw_PI_control_MGT (const asn1SccT_Control *IN_control) {
    if (has_next()) {
        bool any_failure = false;
        size_t i;
        for (i = 0U; i < control_length; ++i) {
            float expected = test_vector[step][control_offset + i];
            float actual   = (float) IN_control->arr[i];
            if (!Are_Equal(expected, actual)) {
                any_failure = true;
                fprintf(stderr,
                        "[ERROR] Fail in step %ld at Control[%ld].\n"
                        "  * Actual    = %0.7ge\n"
                        "  * Expected  = %0.7ge\n"
                        "  * Tolerance = %0.7ge\n\n",
                        step, i, actual, expected, tolerance);
            }
        }

        if (!any_failure) {
            printf("Success in step %ld\n", step);
        }

        step++;
    }
}


