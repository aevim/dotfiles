#!/bin/bash
date=$(date "+%T")
notify-send.sh --replace-file=/tmp/getHours "$date" -t 1500

