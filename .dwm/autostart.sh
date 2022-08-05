#!/bin/sh
hsetroot -cover ~/.wallpapers/rainnight.jpg &
xrandr --output VGA-1 --gamma 1.0:0.88:0.90 --brightness 0.95 &
unclutter &
dunst &
safeeyes &
xset led on &
keyd-application-mapper -d
run_xidlehook &
