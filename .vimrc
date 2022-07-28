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

" highlight current line "
set cursorline
:highlight Cursorline cterm=bold ctermbg=black

" Color scheme (terminal)
packadd! dracula
syntax enable
let g:dracula_colorterm = 0
colorscheme dracula

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
nm <C-p> :new **/*

" it will replace current file "
nm <S-p> :find **/*

" search for a file in buffer "
nm <leader>b :b *

" resize vim splits window "
nm <leader>i :res +5<cr>
nm <leader>d :res -5<cr>


" this will make easier to move between windows "
nm <C-H> <C-W>h
nm <C-J> <C-W>j
nm <C-K> <C-W>k
nm <C-L> <C-W>l

nm <C-s> :so ~/.vimrc<cr>

" this will open a terminal "
nm <leader>t :shell<cr>

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

augroup numbertoggle
autocmd!
autocmd bufenter,focusgained,insertleave,winenter * if &nu && mode() != "i" | set rnu   | endif
autocmd bufleave,focuslost,insertenter,winleave   * if &nu                  | set nornu | endif
augroup end

set laststatus=2
set statusline=
set statusline+=%2*
set statusline+=\ 
set statusline+=%{StatuslineMode()}
set statusline+=\ 
set statusline+=%1*
set statusline+=\ 
set statusline+=<>
set statusline+=\ 
set statusline+=%f
set statusline+=\ 
set statusline+=<>
set statusline+=%=
set statusline+=%m
set statusline+=%h
set statusline+=%r
set statusline+=\ 
set statusline+=%3*
set statusline+=\ 
set statusline+=%1*
set statusline+=%4*
set statusline+=%5*
set statusline+=\ 
set statusline+=%l
set statusline+=/
set statusline+=%L
set statusline+=-
set statusline+=%P
set statusline+=\ 
set statusline+=%1*
set statusline+=\ 
set statusline+=|
set statusline+=%y
set statusline+=\ 
set statusline+=%3*
set statusline+=%4*
set statusline+=%2*
set statusline+=%9*
set statusline+=%9*
set statusline+=%9*
hi User2 ctermbg=lightmagenta ctermfg=black guibg=lightmagenta guifg=black
hi User1 ctermbg=black ctermfg=white guibg=darkcyan guifg=white
hi User3 ctermbg=black ctermfg=lightblue guibg=darkcyan guifg=yellow
hi User4 ctermbg=black ctermfg=lightgreen guibg=cyan guifg=red
hi User5 ctermbg=cyan ctermfg=black guibg=lightmagenta guifg=black

function! StatuslineMode()
  let l:mode=mode()
  if l:mode==#"n"
    return "NORMAL"
  elseif l:mode==?"v"
    return "VISUAL"
  elseif l:mode==#"i"
    return "INSERT"
  elseif l:mode==#"R"
    return "REPLACE"
  elseif l:mode==?"s"
    return "SELECT"
  elseif l:mode==#"t"
    return "TERMINAL"
  elseif l:mode==#"c"
    return "COMMAND"
  elseif l:mode==#"!"
    return "SHELL"
  endif
endfunction
