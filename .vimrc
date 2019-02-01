set nocompatible
set autoindent
set smartindent
set relativenumber
filetype plugin on
filetype indent on
set completeopt-=preview
syntax on
"set path+=**
"set complete-=i
set wildmenu
setl foldmethod=syntax

colorscheme janah

let mapleader = ","

"insert mode
inoremap ,a ->
inoremap ; <Esc>A;
inoremap ,, <Esc>la,<Space>
inoremap ,w while ()<cr>{<cr>}<Esc>2kf(a
inoremap ,i if ()<Esc>i
inoremap ,r return (<Esc>A);<Esc>hi
inoremap <CR> <Esc>o
inoremap jk <Esc>
inoremap <Left> <nop>
inoremap <Right> <nop>
inoremap <Up> <nop>
inoremap <Down> coucou
inoremap <Esc> <cr>
inoremap "" ""<Esc>i
inoremap '' ''<Esc>i
inoremap {{ {}<Esc>i
inoremap [[ []<Esc>i
inoremap << <><Esc>i
inoremap (( ()<Esc>i
inoremap <cr><cr> <cr><Esc>O
inoremap jj <Esc>la
inoremap kk <Esc>jo

"normal mode
nnoremap ,i i#include 
nnoremap ,tt :-1read ~/.vim/.test<CR>wa
nnoremap ,m :r ~/.vim/.main<CR>jo
nnoremap ,M :r ~/.vim/.MakeEx<CR>kdd2jA
nnoremap - ddp
nnoremap + ddkP
nnoremap 0 viwU
nnoremap <leader>h :help 
nnoremap <leader>, ,
nnoremap <leader>ev :vsplit $MYVIMRC<cr>G
nnoremap <leader>sv :source $MYVIMRC<cr>
nnoremap <Left> <nop>
nnoremap <Right> <nop>
nnoremap <Up> <nop>
nnoremap <Down> <nop>
nnoremap <S-Left> :tabp<cr>
nnoremap <S-Right> :tabn<cr>

"Abbreviations
iabbrev vv void

vnoremap <leader>" <Esc>`>a"<Esc>`<i"<Esc>f"l
vnoremap <leader>' <Esc>`>a'<Esc>`<i'<Esc>f'l
vnoremap <leader>< <Esc>`>a><Esc>`<i<<Esc>f>l

"autocommands
function! s:insert_gates()
  let gatename = substitute(toupper(expand("%:t")), "\\.", "_", "g")
  execute "normal! i#ifndef " . gatename
  execute "normal! o#define " . gatename . "\n"
  execute "normal! o#endif"
  execute "normal! kO\n"
endfunction

augroup CFile
	autocmd!
	autocmd BufNewFile *.h call <SID>insert_gates()
	autocmd BufWritePre *.{c,h} :normal gg=G''
augroup END

"commands <cr>
command Addprot execute "normal!yy:b fortress.h\<CR>GPA;\<Esc>:w\<CR>:e #\<CR>"
command Addtest execute "normal!^f<Tab>lyw:b main.c\<CR>G?}<CR>nOT();\<Esc>hP{O\<CR>BOOL<Tab>(void)\<Esc>BPo{\<CR>return (1);\<Esc>o}\<Esc>:w\<CR>:e #\<CR>"
