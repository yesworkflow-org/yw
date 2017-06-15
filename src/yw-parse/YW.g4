grammar YW ;

// YW annotation compositions
script              : (block)* ;
block               : (ws)* beginTag (ws)* (blockAttribute)* (ws)* (block)* (ws)* endTag (ws)*;
blockAttribute      : port | descTag | callTag;
port                : (inputPortKeyword | outputPortKeyword) (SPACE+ portName)+ (SPACE+ portAttribute)* ;
portAttribute       : descTag | aliasTag | resourceTag ;

beginTag            : BeginKeyword (SPACE)+ blockName ;
endTag              : EndKeyword (SPACE)+ (blockName)? ;
descTag             : DescKeyword (SPACE)+ description ;
aliasTag            : AsKeyword (SPACE)+ dataName ;
callTag             : CallKeyword (SPACE)+ (blockName)+ ;
uriTag              : UriKeyword (SPACE)+ uriTemplate;
fileTag             : FileKeyword (SPACE)+ pathTemplate ;
resourceTag         : uriTag | fileTag ;

inputPortKeyword    : InKeyword | ParamKeyword ;
outputPortKeyword   : OutKeyword | ReturnKeyword ;

// YW keyword arguments
blockName       : phrase ;
portName        : Word ;
dataName        : phrase ;
uriTemplate     : ((scheme) ':')? pathTemplate ;
scheme          : 'file' | 'http' ; 
description     : phrase;
phrase          : Word (SPACE+ Word)* ;
pathTemplate    : Word ;

// YW keywords
AsKeyword       : '@as' ;
BeginKeyword    : '@begin' ;
CallKeyword     : '@call' ;
DescKeyword     : '@desc' ;
EndKeyword      : '@end'; 
FileKeyword     : '@file' ;
InKeyword       : '@in' ;
OutKeyword      : '@out' ;
ParamKeyword    : '@param' ;
ReturnKeyword   : '@return' ;
UriKeyword      : '@uri' ;

ws              : (SPACE | NEWLINE)+ ;

VS              : (SPACE)* NEWLINE (SPACE)* ;
SPACE           : [ \t] ;
NEWLINE         : '\r'? '\n' ;
Word            : [a-zA-Z0-9\\_]+ ;

