#!/bin/bash
set -e


if [ "$LINTER" = true ]; then

    folders=()
    # Find immediate subfolders of src/ not containing .roslintignore
    while IFS= read -r -d '' folder; do
        if [[ ! -e "$folder/.roslintignore" ]]; then
            folders+=("${folder#src/}")
        fi
    done < <(find src/ -mindepth 1 -maxdepth 1 -type d -not -path '*/\.*' -not -name '.roslintignore' -print0)

    # Execute catkin build for each folder
    for folder in "${folders[@]}"; do
      command="catkin build $folder --no-deps --continue-on-failure --make-args roslint"
      eval "$command"
    done
    # catkin build --make-args roslint
else  
  catkin build \
  --cmake-args "-DCMAKE_BUILD_TYPE=$BUILD_TYPE" "-DCMAKE_EXPORT_COMPILE_COMMANDS=On" \
  -Wall -Wextra -Wpedantic
fi