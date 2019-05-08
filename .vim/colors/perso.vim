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
hi VertSplit 	cterm=NONE ctermfg=234 ctermbg=234
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
hi Pmenu 		cterm=NONE ctermfg=NONE	ctermbg=236
hi PmenuSel		cterm=NONE ctermfg=232	ctermbg=217
hi PmenuSbar	cterm=NONE ctermfg=234	ctermbg=234
hi PmenuThumb 	cterm=NONE ctermfg=234	ctermbg=234
hi Question 	cterm=NONE ctermfg=NONE
hi Search 		cterm=NONE ctermfg=NONE
hi SpecialKey 	cterm=NONE ctermfg=NONE
hi SpellBad 	cterm=NONE ctermfg=NONE
hi SpellCap 	cterm=NONE ctermfg=NONE
hi SpellLocal 	cterm=NONE ctermfg=NONE
hi SpellRare 	cterm=NONE ctermfg=NONE
hi StatusLine 	cterm=NONE ctermfg=106	ctermbg=234
hi StatusLineNC cterm=NONE ctermfg=NONE	ctermbg=234
hi TabLine 		cterm=NONE ctermfg=NONE ctermbg=234
hi TabLineFill 	cterm=NONE ctermfg=white ctermbg=234
hi TabLineSel 	cterm=NONE ctermfg=white ctermbg=234
hi Title 		cterm=NONE ctermfg=NONE
hi Visual 		cterm=NONE ctermfg=NONE
hi VisualNOS 	cterm=NONE ctermfg=NONE
hi WarningMsg 	cterm=NONE ctermfg=NONE
hi WildMenu 	cterm=NONE ctermfg=220 ctermbg=234
hi Menu			cterm=NONE ctermfg=NONE" ctermbg=234
hi Scrollbar 	cterm=NONE ctermfg=NONE" ctermbg=234
hi Tooltip 		cterm=NONE ctermfg=NONE "ctermbg=234

"Groups
hi Comment			cterm=NONE ctermfg=223
hi Constant    		cterm=NONE ctermfg=141"64
hi String     		cterm=NONE ctermfg=153"180
hi Character   		cterm=NONE ctermfg=NONE"141
hi Number     		cterm=NONE ctermfg=148
hi Boolean     		cterm=NONE ctermfg=NONE"220
hi Float     		cterm=NONE ctermfg=NONE
hi Function     	cterm=NONE ctermfg=183
hi Identifier   	cterm=NONE ctermfg=106
hi Ignore       	cterm=NONE ctermfg=NONE
hi Error        	cterm=NONE ctermfg=234
hi Todo         	cterm=NONE ctermfg=0 ctermbg=220
hi Statement    	cterm=NONE ctermfg=111"174
hi Conditional  	cterm=NONE ctermfg=111"174
hi Repeat			cterm=NONE ctermfg=111"174
hi Label			cterm=NONE ctermfg=red
hi Operator			cterm=NONE ctermfg=red
hi Keyword			cterm=NONE ctermfg=red
hi Exception		cterm=NONE ctermfg=red
hi PreProc			cterm=NONE ctermfg=225
hi Include			cterm=NONE ctermfg=147
hi Define			cterm=NONE ctermfg=147
hi Macro			cterm=NONE ctermfg=147
hi PreCondit		cterm=NONE ctermfg=147
hi Type				cterm=NONE ctermfg=216
hi StorageClass		cterm=NONE ctermfg=NONE
hi Structure		cterm=NONE ctermfg=147
hi Typedef			cterm=NONE ctermfg=174
hi Special			cterm=NONE ctermfg=214"69
hi SpecialChar		cterm=NONE ctermfg=214"69
hi Tag				cterm=NONE ctermfg=214"69
hi Delimiter		cterm=NONE ctermfg=red
hi SpecialComment	cterm=NONE ctermfg=NONE
hi Debug			cterm=NONE ctermfg=NONE
hi Underlined		cterm=NONE ctermfg=NONE
