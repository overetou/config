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

colorscheme janah
"colorscheme Tomorow-night

nnoremap ,tm :-1read ~/.vim/.testMain<CR>3l
inoremap ,a ->
nnoremap ,i i#include 
nnoremap ,tt :-1read ~/.vim/.test<CR>wa
inoremap { <Esc>o{<CR>}<Esc>O
inoremap ( ()<Esc>i
inoremap [ []<Esc>i
inoremap " ""<Esc>i
inoremap ; <Esc>A;
inoremap ,, <Esc>la,<Space>
nnoremap <<< ostd::cout << "" << std::endl;<Esc>5ba
nnoremap ,p :r ~/.vim/.protec<CR>kddA
nnoremap ,m :r ~/.vim/.main<CR>jo
inoremap ,w while ()<Esc>i
inoremap ,i if ()<Esc>i
nnoremap ,M :r ~/.vim/.Make<CR>2jA
nnoremap ç :tabp<CR>
nnoremap à :tabn<CR>
nnoremap ,( cf))<Esc>i
nnoremap // 0i//<Esc>
nnoremap ,/ 02x
inoremap ,r return ();<Esc>hi
nnoremap OO O<Esc>O
inoremap vv void
inoremap <CR> <Esc>o
