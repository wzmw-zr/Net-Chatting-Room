#!/bin/bash
if [[ $# -lt 1 ]]; then
    echo "Usage: ./push message"
else
    git add *
    git commit -m ${1}
    git push
fi
