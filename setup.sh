#!/bin/bash
set -e
ls
vcs import < ${TEST}src/ros.repos ${TEST}src
sudo apt-get update
rosdep update
rosdep install --from-paths ${TEST}src --ignore-src -y
