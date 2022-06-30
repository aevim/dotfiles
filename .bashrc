#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return
if [ -f $HOME/.bashrc_prompt ]; then
  . $HOME/.bashrc_prompt
fi

if [ -f $HOME/.bash_aliases ]; then
  . $HOME/.bash_aliases
fi

export PATH=$PATH:$HOME/.bin
export XDG_DATA_HOME=${XDG_DATA_HOME:="$HOME/.local/share"}
export XDG_CONFIG_HOME=${XDG_CONFIG_HOME:="$HOME/.config"}
export XDG_STATE_HOME=${XDG_STATE_HOME:="$HOME/.local/state"}
export XDG_CACHE_HOME=${XDG_CACHE_HOME:="$HOME/.cache"}
export INPUTRC="$XDG_CONFIG_HOME"/readline/inputrc
export HISTFILE="${XDG_STATE_HOME}"/bash/history
export CARGO_HOME="$XDG_DATA_HOME"/cargo
export GTK2_RC_FILES="$XDG_CONFIG_HOME"/gtk-2.0/gtkrc
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

# Use bash-completion, if available
[[ $PS1 && -f /usr/share/bash-completion/bash_completion ]] && \
	    . /usr/share/bash-completion/bash_completion

[ -f ~/.fzf.bash ] && source ~/.fzf.bash
