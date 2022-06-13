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
export EDITOR=vim
export VISUAL=vim
export PF_INFO="ascii kernel pkgs memory editor shell"

set -o vi

man() {
  /usr/bin/man $* | \
    col -b | \
    vim -R -c 'set ft=man nomod nolist' -
}

shopt -s autocd

alias ls='ls --color=auto'
