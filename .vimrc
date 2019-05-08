set nocompatible
set autoindent
set smartindent
set relativenumber
filetype indent plugin on
set completeopt-=preview
set incsearch
set history=20
set showcmd
"syntax on
"set path+=**
"set complete-=i
set wildmenu
set nohlsearch
let loaded_matchit = 1
packadd! matchit

"colorscheme janah

let mapleader = ","

"insert mode
inoremap <leader>a ->
inoremap ; <Esc>A;
inoremap ,, <Esc>la,<Space>
inoremap ,w while ()<cr>{<cr>}<Esc>2kf(a
inoremap ,i if ()<Esc>i
inoremap ,e else
inoremap ,r return (<Esc>A);<Esc>hi
inoremap <CR> <Esc>o
inoremap jk <Esc>
inoremap <Left> <nop>
inoremap <Right> <nop>
inoremap <Up> <nop>
inoremap <Down> <nop>
inoremap <Esc> <cr>
inoremap "" ""<Esc>i
inoremap '' ''<Esc>i
inoremap {{ {}<Esc>i
inoremap [[ []<Esc>i
inoremap << <><Esc>i
inoremap (( ()<Esc>i
inoremap jj <Esc>la
inoremap kk <Esc>jo
inoremap vv void
inoremap cc char
inoremap hh <Esc>o<Esc>O
inoremap yy <Esc>O{<Esc>jo}<Esc>k
inoremap YY <Esc>jddkkdd
inoremap /* /*<cr><Esc>xi**<cr>*/<Esc>kA
inoremap ,{ <Esc>o{<cr>}<Esc>O
inoremap <leader>m <Esc>:r ~/.vim/.main<CR>jo

"normal mode
nnoremap ,i i#include 
nnoremap ,tt :-1read ~/.vim/.test<CR>wa
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
nnoremap <leader>z :setl foldmethod=syntax<CR>
nnoremap <leader>S yiw{otypedef struct	<esc>pbrso{<esc>o}<tab><tab><esc>pa;<cr><esc>kO
nnoremap <leader>f yiwgg}o<tab><esc>pa()<cr>{<cr>}<cr><esc>3k0i
nnoremap <BS> ^
nnoremap ^ 0
nnoremap <Space> $
nnoremap <F5> i$(<Esc>ea)<Esc>

"Abbreviations
iabbrev wirte write

"Visual mode
vnoremap <leader>" <Esc>`>a"<Esc>`<i"<Esc>f"l
vnoremap <leader>' <Esc>`>a'<Esc>`<i'<Esc>f'l
vnoremap <leader>< <Esc>`>a><Esc>`<i<<Esc>f>l
vnoremap <leader>( <Esc>`>a)<Esc>`<i(<Esc>f)l
vnoremap <leader>{ <Esc>`>a}<Esc>`<i{<Esc>f}l
vnoremap <leader>} <Esc>`<O{<Esc>`>o}<Esc>=i{k%

"autocommands
function! s:insert_gates()
  let gatename = substitute(toupper(expand("%:t")), "\\.", "_", "g")
  execute "normal! i#ifndef " . gatename
  execute "normal! o# define " . gatename . "\n"
  execute "normal! o#endif"
  execute "normal! kO\n"
endfunction

augroup CFile
	autocmd!
	autocmd BufNewFile *.h call <SID>insert_gates()
augroup END

"commands <cr>
command Addprot execute "normal!yy:b store.h\<CR>GPA;\<Esc>:w\<CR>:e #\<CR>"
"command Addprot execute "normal!yy:b computor.h\<CR>GPA;\<Esc>:w\<CR>:e #\<CR>"
command Addtest execute "normal!$F<Tab>lyw:b test_main.c\<CR>gg?}<CR>nOT();\<Esc>hP{O\<CR>BOOL<Tab>_t(void)\<Esc>BPo{\<CR>return (1);\<Esc>o}\<Esc>:w\<CR>:e #\<CR>"
command Addfunc execute "normal!:Addprot<CR>:Addtest<CR>"

function! s:create_struct(strct_name)
	execute "normal! otypedef struct	s_" . a:strct_name
	execute "normal! o{"
	execute "normal! o}		t_" . a:strct_name
	execute "normal! a;\n\<esc>2k"
endfunction

command! -nargs=1 Struct call s:create_struct(<f-args>)
