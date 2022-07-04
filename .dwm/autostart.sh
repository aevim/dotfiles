#!/bin/sh
hsetroot -solid '#282a36' &
xrandr --output VGA-1 --gamma 1.0:0.88:0.60 --brightness 0.95 &
dunst &
unclutter &
run_xidlehook &
safeeyes &
xcape -e 'Control_L=Escape' &

