syn match    cCustomParen    "(" contains=cParen
syn match    cCustomFunc     "\w\+\s*(" contains=cCustomParen
syn match    cCustomScope    "::"
syn match    cCustomClass    "\w\+\s*::" contains=cCustomScope
hi def link cCustomFunc  Function
hi def link cCustomClass Function
syn keyword	CustType BOOL UINT UCHR USHT
syn keyword	cCustTypedef typedef const
syn match	cCustTypedefs "\<\(s\|t\)_\w*\|\<\([A-Z]\|_\)*\>"
syn match	cOper    "!\|->\|\.\|&\|\*\|+\|-\|\\\|=\|<\|>"
hi cOper ctermfg=106
hi def link CustType Type
hi def link cCustTypedefs Typedef
hi def link cCustTypedef Typedef
