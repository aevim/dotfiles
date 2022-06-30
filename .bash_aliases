sud=doas

alias sgm='$sud grub-mkconfig -o /boot/grub/grub.cfg'
alias swac='nvim ~/.config/sway/config'
alias swaco='nvim ~/.config/sway/config.d/'
alias getId='swaymsg -t get_tree'
alias yarn='yarn --use-yarnrc $XDG_CONFIG_HOME/yarn/config'

# arch
alias search='pacman -Ss'
alias lsm="exa -al --color=always --group-directories-first"
alias ls="exa"
alias up='$sud pacman -Syu && gopreload-batch-refresh.sh'
alias im='yay -S'
alias i='$sud pacman -S '
alias r='$sud pacman -Rs '
alias orphans='$sud pacman -Qtdq | $sud pacman -Rns -'

#yt-dlp
alias mp3='yt-dlp -x --audio-format mp3 '

# git
alias ga='git add .'
alias gc='git clone'
alias gco='git commit -m'
alias gp='git push -u origin main'

# python
alias pyi='pip install'
alias pyr='pip uninstall'

# simple commands
alias cl='clear'

# make
alias smi='doas rm config.h; make; doas make install'

# xclip
alias pbcopy='xclip -selection clipboard'

# zsh
alias sc='vim ~/.zshrc'
alias sz='source ~/.zshrc'

# cpupower
alias boost="sudo cpupower frequency-set -g performance"
alias powersave="sudo cpupower frequency-set -g powersave"

# terminal apps
alias sv='sudo -e'
alias v='vim'
alias vimwiki='nvim ~/.vimwki/index.wiki'

# Anki
alias ae='canki.sh English'
alias ap='canki.sh Portuguese'
alias am='canki.sh Math'
alias aa='canki.sh Pixel'
alias ag='canki.sh Godot'

# translate shell
alias t="trans -sp -brief en:pt-br"
alias tb="trans -p -brief pt-br:en"

# translate shell
translate() {
  trans -brief $1:$2 $3
}

# easyeffects
music() {
  easyeffects -l 'Bass Boosted'
}

audio() {
  easyeffects -l 'Advanced Auto Gain'
}

