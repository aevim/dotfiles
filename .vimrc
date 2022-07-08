set nocompatible
set number
set hlsearch
set incsearch
set ignorecase
set smartcase
set encoding=utf-8
" this if to prevent the 'O' key from having a delay "
set ttimeoutlen=100

" this will highlight the ending match "
set showmatch

" this will disable 'insert' text at the bottom "
set noshowmode

" this is for lightline to work " 
set laststatus=2

let g:lightline = {
          \ 'colorscheme': 'gruvbox',
      \ }

" this is for the file browser "
let g:netrw_preview   = 1
let g:netrw_banner    = 0
let g:netrw_liststyle = 3
let g:netrw_winsize   = 30
nm <C-n> :Lexplore<cr>

" this is emmet configuration "
" autocmd is used to load only on specific files"
let g:user_emmet_install_global = 0
let g:user_emmet_leader_key=','
autocmd FileType html,css,scss,sass EmmetInstall

" highlight current line "
set cursorline
:highlight Cursorline cterm=bold ctermbg=black

" Color scheme (terminal)
set background=dark
colorscheme gruvbox

" this will set path to the current dir.
set path+=**                                                                    

" this will make tabbing on the command mode show a menu. This is usefull for find command.
set wildmenu
set wildmode=full
set wildignore+=**/node_modules/** 


" this will make so when tab hitting tab, 2 spaces will be used.
set autoindent expandtab tabstop=2 shiftwidth=2

filetype plugin indent on
syntax on

" mappins
let mapleader = ","
map <leader><space> :let @/=''<cr> " clear search

" this is for fiding files "
" it will split vertically "
nm <leader>v :vne **/*

" it will open the new file on top "
nm <C-f> :new **/*

" it will replace current file "
nm <S-f> :find **/*

" it will open new file in another tab "
nm <leader>t :tabfind *

" this will make easier to move between windows "
nm <C-H> <C-W>h
nm <C-J> <C-W>j
nm <C-K> <C-W>k
nm <C-L> <C-W>l

nm <C-s> :so ~/.vimrc<cr>

" this will switch between buffers "
nm gn :bn<cr>
nm gp :bp<cr>
nm gd :bd<cr>

" this is for setting vim for true colors "
let &t_8f = "\<Esc>[38;2;%lu;%lu;%lum"
let &t_8b = "\<Esc>[48;2;%lu;%lu;%lum"
set termguicolors

" # Close brackets automatically, with return
inoremap {<cr> {<cr>}<C-O><S-O>
inoremap (<cr> (<cr>)<c-o><s-o>
inoremap [<cr> [<cr>]<c-o><s-o>
" # Close brackets without return
inoremap ( ()<left>
inoremap { {}<left>
inoremap [ []<left>
" # Two cases below are covered by inoremap <exp>
" inoremap " ""<left>
" inoremap ' ''<left>
" # If you close a bracket that is already closed, it overwrites
inoremap <expr> ) strpart(getline('.'), col('.')-1, 1) == ")" ? "\<Right>" : ")"
inoremap <expr> } strpart(getline('.'), col('.')-1, 1) == "}" ? "\<Right>" : "}"
inoremap <expr> ] strpart(getline('.'), col('.')-1, 1) == "]" ? "\<Right>" : "]"
inoremap <expr> ' strpart(getline('.'), col('.')-1, 1) == "'" ? "\<Right>" : "''<left>"
inoremap <expr> " strpart(getline('.'), col('.')-1, 1) == "\"" ? "\<Right>" : "\"\"<left>"
" # enclose a word in normal mode with "'({[
nnoremap ' mmbi'<esc>ea'<esc>`m<right>
nnoremap " mmbi"<esc>ea"<esc>`m<right>
nnoremap ( mmbi(<esc>ea)<esc>`m<right>
nnoremap { mmbi{<esc>ea}<esc>`m<right>
nnoremap [ mmbi[<esc>ea]<esc>`m<right>
" # enclose a selection in visual mode with "'({[
vnoremap ' <Esc>`<i'<Esc>`>a<right>'<Esc>
vnoremap " <Esc>`<i"<Esc>`>a<right>"<Esc>
vnoremap ( <Esc>`<i(<Esc>`>a<right>)<Esc>
vnoremap { <Esc>`<i{<Esc>`>a<right>}<Esc>
vnoremap [ <Esc>`<i[<Esc>`>a<right>]<Esc>

" some directories to jump to"
nnoremap <leader>fp  :edit ~/.web/projects**/*
nnoremap <leader>fh  :edit ~/**
autocmd BufEnter * lcd %:p:h

augroup numbertoggle
autocmd!
autocmd bufenter,focusgained,insertleave,winenter * if &nu && mode() != "i" | set rnu   | endif
autocmd bufleave,focuslost,insertenter,winleave   * if &nu                  | set nornu | endif
augroup end

