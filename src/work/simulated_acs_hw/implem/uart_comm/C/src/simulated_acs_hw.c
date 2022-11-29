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

#include <unistd.h>  // read, write
#include <fcntl.h>   // File control definitions
#include <termios.h> // POSIX terminal control definitions

/*******************************************************************************
 * Local variables and constants
 ******************************************************************************/


const char *  SERIAL_PORT_NAME =
#if defined(RTEMS_POSIX) || defined(DLEON_RTEMS)
    "/dev/console_b"; /**> RTEMS serial ports ref.: https://devel.rtems.org/wiki/TBR/BSP/Leon3 */
#else
    "/dev/ttyOBC";
#endif

const speed_t SERIAL_PORT_BAUD_RATE = B115200;

int serial_port = -1; /**< serial port's file descriptor*/

/*******************************************************************************
 * Private functions
 ******************************************************************************/

/**
 * @brief sets baud rate, blocking I/O,
 *        and other relevant parameters using the Termios library.
 * @return 0 on success, 1 on failure
 */
static int config_serial_port()
{
    /**
     * \brief Undo O_NDELAY from initialization.
     *
     * We needed non-blocking mode only to open the device,
     * but blocking for I/O operations!
     */
    (void) fcntl(serial_port, F_SETFL, 0);

    struct termios serial_port_config;
    if (tcgetattr(serial_port, &serial_port_config) < 0) {
        perror("[Simulated_ACS_HW] ERROR: tcgetattr serial_port");
        return 1;
    }

    /** \name c_iflag: input mode
     * The following turns off input processing
     * @{
     */
    serial_port_config.c_iflag &= ~IGNBRK;
    serial_port_config.c_iflag &= ~BRKINT; /**> A break reads as null byte */
    serial_port_config.c_iflag &= ~IGNPAR;
    serial_port_config.c_iflag &= ~PARMRK; /**> Framing errors and parity errors read as null bytes */
    serial_port_config.c_iflag &= ~INPCK;  /**> Disable input parity checking */
    serial_port_config.c_iflag &= ~ISTRIP; /**> Do not strip off 8th bit */
    serial_port_config.c_iflag &= ~INLCR;  /**> No TL to CR translation */
    serial_port_config.c_iflag &= ~IGNCR;  /**> Do not ignore carriage return on input */
    serial_port_config.c_iflag &= ~ICRNL;  /**> No CR to NL translation */
    serial_port_config.c_iflag &= ~IXOFF;  /**> Disable xon/xoff on input */
    serial_port_config.c_iflag &= ~IXON;   /**> Disable xon/xoff on output */
    serial_port_config.c_iflag &= ~IXANY;  /**> Only START restarts the stopped output */
    /*@}*/

    /** \name c_oflag: output mode
     *  The following prevents special interpretation of output bytes (e.g. newline chars):
     *  no CR to NL translation, no NL to CR-NL translation,
     *  no NL to CR translation, no column 0 CR suppression,
     *  no Ctrl-D suppression, no fill characters, no case mapping.
     */
    serial_port_config.c_oflag = 0U;

    /** \name c_cflag: control modes
     *  8N1 configuration:
     *  @{
     */
    serial_port_config.c_cflag &= ~PARENB; /**> no parity bit */
    serial_port_config.c_cflag &= ~CSTOPB; /**> 1 Stop bit */
    serial_port_config.c_cflag &= ~CSIZE;  /**> clear previous bits per byte and */
    serial_port_config.c_cflag |= CS8;     /**> set 8 bits per byte */
    serial_port_config.c_cflag |= CLOCAL;  /**> ignore modem control lines */
    serial_port_config.c_cflag |= CREAD;   /**> enable receiver! */
    /*@}*/

    /** \name c_lflag: local modes
     *  We are NOT interested in cannonical mode since received messages are in binary format.
     *  @{
     */
    serial_port_config.c_lflag &= ~ICANON; /**> canonical mode off */
    serial_port_config.c_lflag &= ~ECHO;   /**> ECHO off */
    serial_port_config.c_lflag &= ~ECHONL; /**> ECHO newline off */
    serial_port_config.c_lflag &= ~ECHOK;  /**> do not echo NL after KILL character */
    serial_port_config.c_lflag &= ~ECHOE;  /**> disable erasure */
    serial_port_config.c_lflag &= ~IEXTEN; /**> extended input processing ignored */
    serial_port_config.c_lflag &= ~ISIG;   /**> disable interpretation of INTR, QUIT and SUSP */
    /*@}*/

    /** Configures the baud rate
     */
    if (cfsetspeed(&serial_port_config, SERIAL_PORT_BAUD_RATE)) {
        perror("[Simulated_ACS_HW] ERROR: Could not set the baud rate");
        return 1;
    }

    /** Apply configuration immediately and flush the  I/O buffers:
     */
    if (tcsetattr(serial_port, TCSAFLUSH, &serial_port_config) == 0) {
        puts("[Simulated_ACS_HW] SUCCESS: set tty config");
    } else {
        perror("[Simulated_ACS_HW] ERROR: tcsetattr");
        return 1;
    }

    return 0;
}

/**
 * @brief Opens SERIAL_PORT_NAME device
 * @return 0 on success, 1 on failure
 */
static int open_serial_port(void) {
    /**
     * O_NOCTTY:   prevent the serial device from becoming the controlling terminal,
     *             so this won't be the controlling process.
     * O_NONBLOCK: non-blocking mode for open, and I/O operations
     */
    serial_port = open(SERIAL_PORT_NAME, O_RDWR | O_NOCTTY | O_NONBLOCK);

    return serial_port == -1;
}

/*******************************************************************************
 * Provided interfaces implementation
 ******************************************************************************/

void simulated_acs_hw_startup(void) {
   puts ("[Simulated_ACS_HW] Startup");

   if (open_serial_port()) {
       printf("[Simulated_ACS_HW] ERROR: Could not open serial port %s\n", SERIAL_PORT_NAME);
   } else {
       printf("[Simulated_ACS_HW] Serial port %s is now open\n", SERIAL_PORT_NAME);
   }

   if (config_serial_port()) {
       printf("[Simulated_ACS_HW] ERROR: Could not configure the serial port %s\n", SERIAL_PORT_NAME);
   } else {
       printf("[Simulated_ACS_HW] Serial port %s is now configured\n", SERIAL_PORT_NAME);
   }
}

/**
 * @brief Reads magnetometer values from the serial line
 *
 * @note This is a blocking reading,
 *       the function won't return until a BBT is read
 *
 * @param OUT_bbt The results are stored in here
 */
void simulated_acs_hw_PI_Read_MGM(asn1SccT_B_b_T *OUT_bbt)
{
    if (serial_port < 0) {
        return;
    }

    for (int i = 0; i < 15; i++) {
        float received_value = 0.0;
        int nbytes = read(serial_port, (void *) &received_value, sizeof(received_value));

        printf("[Simulated_ACS_HW] Received %d bytes from client\n", nbytes);
        if (nbytes <= 0) {
            perror("[Simulated_ACS_HW] ERROR: read");
        } else {
            OUT_bbt->arr[i] = received_value;
            printf("|\t%f\t|", OUT_bbt->arr[i]);
        }
    }
}

/**
 * @brief Sends the received command \p IN_Control to the simulated environment
 *        via serial port connection.
 * @param IN_control
 */
void simulated_acs_hw_PI_control_MGT(const asn1SccT_Control *IN_control)
{
    if (serial_port < 0) {
        return;
    }

    float to_be_sent[3];

    printf("CTRL: {%f, %f, %f}\n", IN_control->arr[0], IN_control->arr[1], IN_control->arr[2]);
    for (int i = 0; i < 3; ++i) {
        to_be_sent[i] = IN_control->arr[i];
    }

    if (write(serial_port, (void *) &to_be_sent, sizeof(to_be_sent)) <= 0) {
        perror("[Simulated_ACS_HW] ERROR: send");
    } else {
        puts("[Simulated_ACS_HW] Send data went fine!\n");
    }
}


