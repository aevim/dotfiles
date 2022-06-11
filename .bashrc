#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return
if [ -f $HOME/.bashrc_prompt ]; then
  . $HOME/.bashrc_prompt
fi

if [ -f $HOME/.aliases ]; then
  . $HOME/.aliases
fi

export PATH=$PATH:$HOME/.bin

set -o vi

alias ls='ls --color=auto'
