#!/bin/bash
set -e

export TEST=/repo/

/repo/setup.sh
ament_${LINTER} /repo/src/
