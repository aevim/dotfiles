#!/bin/bash

dir=$(pwd)
path=~/.dotfiles
home=$HOME

if [[ $1 = '--help' ]]; then
  echo "
  To add a config to the main my-configs dir use: filename(inside your home folder), thats it. Ex: save.sh .dwm

  To add a config that is inside the .config dir and to put it inside the .config dir on my-configs folder use: filename(inside your .config folder) path(inside your .config) cg. Ex: save.sh sway .config cg
  "
  exit 1
fi

copy() {
  cp $1 $2 -a
}

delete() {
  rm -rf "$@" 
}

in_config=$(echo "${@: -1}")
if [[ $in_config = 'cg' ]]; then
  if [[ $# -lt 3 ]]; then
    echo 'Need 3 arguments'
  fi
fi

save() {
  cd $path
  if [[ $3 = 'cg' ]] 
  then
    delete $path/$2/$1
    copy $home/.config/$1 $path/$2
  else 
    delete $path/$1
    copy $home/$1 $path/$2
  fi
  git add . ;
  git commit -m 'new changes!';
  git push -u origin main;
  cd $dir
}

save "$@"

