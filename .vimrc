set nocompatible
set number
set hlsearch
set incsearch
set ignorecase
set smartcase
set showmatch

" Color scheme (terminal)
set background=dark
colorscheme gruvbox

" this will set path to the current dir.
set path=$PWD/**

" this will make tabbing on the command mode show a menu. This is usefull for find command.
set wildmenu
set wildmode=full
set wildignore+=*/node_modules/*,_site

" this wil add >>_ for each tab space.
set list
set lcs=tab:»_,trail:·

" this will make so when tab hitting tab, 2 spaces will be used.
set autoindent expandtab tabstop=2 shiftwidth=2

syntax on

" mappins
let mapleader = ","
map <leader><space> :let @/=''<cr> " clear search
nm <leader>f :vertical sfind *
nm <leader>t :tabfind *
nm <C><N> :tabNext
nm <C-H> <C-W>h
nm <C-J> <C-W>j
nm <C-K> <C-W>k
nm <C-L> <C-W>l
nm gn :bn<cr>
nm gp :bp<cr>
nm gd :bd<cr>

augroup numbertoggle
autocmd!
autocmd bufenter,focusgained,insertleave,winenter * if &nu && mode() != "i" | set rnu   | endif
autocmd bufleave,focuslost,insertenter,winleave   * if &nu                  | set nornu | endif
augroup end

