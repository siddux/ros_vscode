#!/bin/bash
set -e

if [ -f ${TEST}devel/setup.bash ]; then source ${TEST}devel/setup.bash; fi

export ROS_MASTER_URI=http://localhost:11311
export ROS_HOSTNAME=localhost

cd ${TEST} && catkin test