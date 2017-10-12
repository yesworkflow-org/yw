grammar YW_CONFIG_ ;

// grammar rules
configFile      : (blankLine | commentLine | settingLine)* SPACE* ;
blankLine       : SPACE* NEWLINE ;
commentLine		: SPACE* comment NEWLINE ;
settingLine	    : SPACE* setting SPACE* comment? NEWLINE ;

comment			: ('#' | '//') (SPACE | WORD)* ;
setting          : settingName SPACE* '=' SPACE* settingValue ;
settingName      : WORD ;
settingValue     : unquotedValue | (SQ unquotedValue SQ) | (DQ unquotedValue DQ) ;
unquotedValue    : (SPACE | ',' | word )*? ;
word			: WORD ;

// lexical tokens
NEWLINE          : '\r'? '\n' ;
SPACE           : [ \t] ;
DQ               : '"' ;
SQ               : '\'' ;
WORD             : ~[ =,\t\r\n"']+ ;

