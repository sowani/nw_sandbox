#!/bin/bash

# Add initialisation script for sitara.
cp upstream-init /etc/init.d
chmod a+x /etc/init.d/upstream-init
update-rc.d upstream-init defaults 97

# USB is not available on sitara, hence disabled.
# Set up usb detection mechanism
#usb-detection/run.sh

# Set up process re-spawning mechanism
proc-respawn/run.sh
