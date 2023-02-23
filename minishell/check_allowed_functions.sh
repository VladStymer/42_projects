#!/usr/bin/env bash

USED_FUNCTIONS=`nm -u minishell | awk '{sub(/@.*/, "")} { print $2 }' | sed '/^_/d'`
for func in $USED_FUNCTIONS; do grep "$func" allowed_functions.txt > /dev/null || echo "$func is not allowed"; done
echo "Check done"
