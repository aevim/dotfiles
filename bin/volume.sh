#!/bin/bash

if [ "$1" == "up" ]; then
  pactl set-sink-volume @DEFAULT_SINK@ +2%
fi

if [ "$1" == "down" ]; then
  pactl set-sink-volume @DEFAULT_SINK@ -2%
fi

if [ "$1" == "mute" ]; then
  pactl set-sink-mute @DEFAULT_SINK@ toggle
fi

VOLUME=$(pamixer --get-volume)
echo $VOLUME
MUTE=$(echo $AMIXER | grep -o '\[off\]' | tail -n 1)
if [ "$VOLUME" -le 20 ]; then
    ICON=audio-volume-low
else if [ "$VOLUME" -le 60 ]; then
         ICON=audio-volume-medium
     else
         ICON=audio-volume-high
     fi
fi
if [ "$MUTE" == "[off]" ]; then
    ICON=audio-volume-muted
fi

notify-send.sh $VOLUME% \
  --replace=22 \
  -u low \
  -a volume \
  -i /usr/share/icons/Adwaita/32x32/legacy/$ICON.png

