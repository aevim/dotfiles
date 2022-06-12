#!/bin/bash
if [[ $(echo "$1 > $2" | bc) -ne 0 ]]; then
  echo Sim
  else
  echo Nope
fi
