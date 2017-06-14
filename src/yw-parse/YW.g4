grammar YW ;

// YW annotation compositions
script              : (block)* ;
block               : (ws)* beginTag (ws)* (blockAttribute)* (ws)* (block)* (ws)* endTag (ws)*;
blockAttribute      : descTag | portTag | callTag;
portAttribute       : descTag | aliasTag | resourceTag ;

beginTag            : BeginKeyword (HS)+ blockName ;
endTag              : EndKeyword (HS)+ (blockName)? ;
descTag             : DescKeyword (HS)+ description ;
portTag             : (inputPortKeyword | outputPortKeyword) ((HS)+ portName ((HS)+ (portAttribute)*)?)+ ;
aliasTag            : AsKeyword (HS)+ dataName ;
callTag             : CallKeyword (HS)+ (blockName)+ ;
uriTag              : UriKeyword (HS)+ uriTemplate;
fileTag             : FileKeyword (HS)+ pathTemplate ;
resourceTag         : uriTag | fileTag ;

inputPortKeyword    : InKeyword | ParamKeyword ;
outputPortKeyword   : OutKeyword | ReturnKeyword ;

// YW keyword arguments
blockName       : phrase ;
portName        : Word ;
dataName        : Word ;
uriTemplate     : ((scheme) ':')? pathTemplate ;
scheme          : 'file' | 'http' ; 
description     : phrase;
phrase          : Word (HS+ Word)* ;
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

ws              : (HS)+ (NL)* (HS)* | (NL)+ (HS)* ;

VS              : (HS)* NL (HS)* ;
HS              : [ \t] ;
NL              : '\r'? '\n' ;
Word            : [a-zA-Z0-9\\_]+ ;

