#!/bin/bash
wks=/tmp/workspaces
if [[ ! -e $wks ]]; then
  touch $wks
fi
previous=$(tail -n 2 $wks | head -n 1)
current=$(tail -n 1 $wks | head -n 1)

history() {
  echo $1 >> $wks
}

notify () {
  notify-send.sh -a workspaces -u normal --replace-file=/tmp/workspace -t 1500 $1 
}

choose() {
  case $1 in
    1) notify '';;
    2) notify '';;
    3) notify '';;
    4) notify '';;
    5) notify '';;
    6) notify '';;
    *)
    notify 'nope';;
  esac
}

if [[ $1 == 'back' ]]; then
  TOGGLE=$HOME/.toggle

  if [ ! -e $TOGGLE ]; then
      touch $TOGGLE
      echo $previous
      choose $previous
      exit 1
  else
      echo 'current: ' $current
      rm $TOGGLE
      choose $current
      exit 1
  fi
fi

choose $1
    
history $1
