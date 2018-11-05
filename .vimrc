set nocompatible              " be iMproved, required
set autoindent
set smartindent
"set number
syntax on
set complete-=i

colorscheme nord

nnoremap ,tm :-1read ~/.vim/.testMain<CR>3l
inoremap ,a ->
nnoremap ,i i#include 
nnoremap ,tt :-1read ~/.vim/.test<CR>wa
inoremap { <Esc>o{<CR>}<Esc>O
inoremap ( ()<Esc>i
inoremap [ []<Esc>i
inoremap " ""<Esc>i
inoremap ;; <Esc>A;
inoremap ,, <Esc>la,<Space>
nnoremap <<< ostd::cout << "" << std::endl;<Esc>5ba
nnoremap ,p :r ~/.vim/.protec<CR>kddA
nnoremap ,m :r ~/.vim/.main<CR>jo
nnoremap ,M :r ~/.vim/.Make<CR>2jA
inoremap sss std::string
nnoremap ç :tabp<CR>
nnoremap à :tabn<CR>
nnoremap ,( cf))<Esc>i
nnoremap // 0i//<Esc>
nnoremap ,/ 02x
inoremap ttt this->
inoremap rrr return ();<Esc>hi
nnoremap OO O<Esc>O
inoremap vv void
