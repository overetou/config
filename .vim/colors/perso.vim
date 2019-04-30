syntax clear

if exists("syntax_on")
	syntax reset
endif

set background=dark
let g:colors_name="perso"

hi Normal 		cterm=NONE ctermfg=NONE ctermbg=234
hi ColorColumn 	cterm=NONE ctermfg=NONE
hi Conceal 		cterm=NONE ctermfg=NONE
hi Cursor		cterm=NONE ctermfg=NONE
hi CursorIM 	cterm=NONE ctermfg=NONE
hi CursorColumn cterm=NONE ctermfg=NONE
hi CursorLine 	cterm=NONE ctermfg=NONE
hi Directory 	cterm=NONE ctermfg=NONE
hi DiffAdd 		cterm=NONE ctermfg=NONE
hi DiffChange 	cterm=NONE ctermfg=NONE
hi DiffDelete 	cterm=NONE ctermfg=NONE
hi DiffText 	cterm=NONE ctermfg=NONE
hi ErrorMsg 	cterm=NONE ctermfg=NONE
hi VertSplit 	cterm=NONE ctermfg=grey
hi Folded 		cterm=NONE ctermfg=NONE
hi FoldColumn 	cterm=NONE ctermfg=NONE
hi SignColumn 	cterm=NONE ctermfg=NONE
hi IncSearch 	cterm=NONE ctermfg=NONE
hi LineNr 		cterm=NONE ctermfg=243
hi CursorLineNr cterm=NONE ctermfg=243
hi MatchParen 	cterm=NONE ctermfg=220		ctermbg=NONE
hi ModeMsg 		cterm=NONE ctermfg=NONE
hi MoreMsg 		cterm=NONE ctermfg=NONE
hi NonText 		cterm=NONE ctermfg=234
hi Pmenu 		cterm=NONE ctermfg=NONE		ctermbg=NONE
hi PmenuSel		cterm=NONE ctermfg=black	ctermbg=grey
hi PmenuSbar	cterm=NONE ctermfg=NONE
hi PmenuThumb 	cterm=NONE ctermfg=NONE
hi Question 	cterm=NONE ctermfg=NONE
hi Search 		cterm=NONE ctermfg=NONE
hi SpecialKey 	cterm=NONE ctermfg=NONE
hi SpellBad 	cterm=NONE ctermfg=NONE
hi SpellCap 	cterm=NONE ctermfg=NONE
hi SpellLocal 	cterm=NONE ctermfg=NONE
hi SpellRare 	cterm=NONE ctermfg=NONE
hi StatusLine 	cterm=NONE ctermfg=238	ctermbg=111
hi StatusLineNC cterm=NONE ctermfg=black	ctermbg=106
hi TabLine 		cterm=NONE ctermfg=NONE ctermbg=240
hi TabLineFill 	cterm=NONE ctermfg=white ctermbg=234
hi TabLineSel 	cterm=NONE ctermfg=white ctermbg=111
hi Title 		cterm=NONE ctermfg=NONE
hi Visual 		cterm=NONE ctermfg=NONE
hi VisualNOS 	cterm=NONE ctermfg=NONE
hi WarningMsg 	cterm=NONE ctermfg=NONE
hi WildMenu 	cterm=NONE ctermfg=NONE
hi Menu			cterm=NONE ctermfg=NONE
hi Scrollbar 	cterm=NONE ctermfg=NONE
hi Tooltip 		cterm=NONE ctermfg=NONE

"Groups
hi Comment			cterm=NONE ctermfg=108
hi Constant    		cterm=NONE ctermfg=64
hi String     		cterm=NONE ctermfg=110
hi Character   		cterm=NONE ctermfg=141
hi Number     		cterm=NONE ctermfg=148
hi Boolean     		cterm=NONE ctermfg=220
hi Float     		cterm=NONE ctermfg=red
hi Function     	cterm=NONE ctermfg=138
hi Identifier   	cterm=NONE ctermfg=223
hi Ignore       	cterm=NONE ctermfg=NONE
hi Error        	cterm=NONE ctermfg=NONE
hi Todo         	cterm=bold ctermfg=0 ctermbg=220
hi Statement    	cterm=NONE ctermfg=214
hi Conditional  	cterm=NONE ctermfg=214
hi Repeat			cterm=NONE ctermfg=214
hi Label			cterm=NONE ctermfg=NONE
hi Operator			cterm=NONE ctermfg=red
hi Keyword			cterm=NONE ctermfg=NONE
hi Exception		cterm=NONE ctermfg=NONE
hi PreProc			cterm=NONE ctermfg=223
hi Include			cterm=NONE ctermfg=223
hi Define			cterm=NONE ctermfg=223
hi Macro			cterm=NONE ctermfg=NONE
hi PreCondit		cterm=NONE ctermfg=223
hi Type				cterm=NONE ctermfg=70
hi StorageClass		cterm=NONE ctermfg=NONE
hi Structure		cterm=NONE ctermfg=229
hi Typedef			cterm=NONE ctermfg=red
hi Special			cterm=NONE ctermfg=NONE
hi SpecialChar		cterm=NONE ctermfg=NONE
hi Tag				cterm=NONE ctermfg=NONE
hi Delimiter		cterm=NONE ctermfg=red
hi SpecialComment	cterm=NONE ctermfg=NONE
hi Debug			cterm=NONE ctermfg=NONE
hi Underlined		cterm=NONE ctermfg=NONE
hi parens ctermfg=red
"214 est pas mal pour apporter des touches florales orangees. Il faudrait une
"alternative plus claire a 130 pour les keywords.
