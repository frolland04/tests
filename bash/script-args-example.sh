#!/bin/bash

# Initialize variables
POSITIONAL_PARAM=""
APPLE_FLAG=false
BANANA_VALUE=""

# Parse parameters
while (( "$#" )); do
    case "$1" in
        -a|--apple)
            APPLE_FLAG=true
            shift
            ;;
        -b|--banana)
            if [ -z "$2" ] || [[ "$2" =~ ^-.* ]]; then
                echo "Error: -b or --banana requires an argument."
                exit 1
            fi
            BANANA_VALUE="$2"
            shift 2
            ;;
        *)
            if [ -z "$POSITIONAL_PARAM" ]; then
                POSITIONAL_PARAM="$1"
                shift
            else
                echo "Error: Invalid parameter $1"
                exit 1
            fi
            ;;
    esac
done

# Display values
echo "Positional Parameter: $POSITIONAL_PARAM"
echo "Apple Flag: $APPLE_FLAG"
echo "Banana Value: $BANANA_VALUE"

