#!/bin/bash
set -e

export TEST=/repo/

rm -rf usr/src/gmock
rm -rf usr/src/gtest

/repo/setup.sh
/repo/build.sh
/repo/test.sh
