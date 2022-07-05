#!/bin/sh
emacs --daemon &
hsetroot -solid '#282828' &
xmodmap ~/.Xmodmap &
xrandr --output VGA-1 --gamma 1.0:0.88:0.60 --brightness 0.95 &
unclutter &
run_xidlehook &
xcape -e 'Control_L=Escape' &
dunst &
safeeyes &
xset led on &
