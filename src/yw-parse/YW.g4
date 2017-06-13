grammar YW ;

// YW annotation compositions
script              : (block)* ;
block               : beginTag (WS)* (blockAttribute)* (WS)* (block)* (WS)* endTag ;
blockAttribute      : descTag | portTag | callTag;
portAttribute       : descTag | aliasTag | resourceTag ;

beginTag            : beginKeyword (HS)+ blockName ;
endTag              : endKeyword (HS)+ (blockName)? ;
descTag             : descKeyword (HS)+ description ;
portTag             : (inputPortKeyword | outputPortKeyword) ((HS)+ portName ((HS)+ (portAttribute)*)?)+ ;
aliasTag            : asKeyword (HS)+ dataName ;
callTag             : callKeyword (HS)+ (blockName)+ ;
uriTag              : uriKeyword (HS)+ uriTemplate;
fileTag             : fileKeyword (HS)+ PATH_TEMPLATE ;
resourceTag         : uriTag | fileTag ;

inputPortKeyword    : inKeyword | paramKeyword ;
outputPortKeyword   : outKeyword | returnKeyword ;

// YW keywords
asKeyword       : '@as' ;
beginKeyword    : '@begin' ;
callKeyword     : '@call' ;
descKeyword     : '@desc' ;
endKeyword      : '@end' ; 
fileKeyword     : '@file' ;
inKeyword       : '@in' ;
outKeyword      : '@out' ;
paramKeyword    : '@param' ;
returnKeyword   : '@return' ;
uriKeyword      : '@uri' ;

// YW keyword arguments
blockName       : ID ;
portName        : ID ;
dataName        : ID ;
uriTemplate     : ((scheme) ':')? PATH_TEMPLATE ;
scheme          : 'file' | 'http' ; 
description     : ID;

// lexer rules
ID              : [a-zA-Z0-9\\_]+ ;
PATH_TEMPLATE   : ID ;
HS              : [ \t] ;
NL              : '\r'? '\n' ;
WS              : [ \t\r\n] ;
SP              : ' ' | '\t' ;
