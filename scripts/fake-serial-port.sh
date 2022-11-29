#!/bin/bash

# Note that the ACS_PIL communicates through TTY_HOST
#      and the ACS algorithm (running in TASTE) though TTY_TARGET
TTY_HOST=/dev/ttyUSB0
TTY_TARGET=/dev/ttyOBC

# Check that socat is installed
command -V socat > /dev/null || exit "Install socat!"

# Creates fake ttys
sudo socat -d -d -v pty,rawer,mode=666,link=${TTY_HOST},b115200 \
                    pty,rawer,mode=666,link=${TTY_TARGET},b115200 \
                    &> /dev/null
