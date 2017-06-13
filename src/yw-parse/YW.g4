grammar YW ;

// YW annotation compositions
script              : (block)* ;
block               : beginTag (WS)* (blockAttribute)* (WS)* (block)* (WS)* endTag ;
blockAttribute      : descTag | portTag | callTag;
portAttribute       : descTag | aliasTag | resourceTag ;

beginTag            : BeginKeyword (HS)+ blockName ;
endTag              : EndKeyword (HS)+ (blockName)? ;
descTag             : DescKeyword (HS)+ description ;
portTag             : (inputPortKeyword | outputPortKeyword) ((HS)+ portName ((HS)+ (portAttribute)*)?)+ ;
aliasTag            : AsKeyword (HS)+ dataName ;
callTag             : CallKeyword (HS)+ (blockName)+ ;
uriTag              : UriKeyword (HS)+ uriTemplate;
fileTag             : FileKeyword (HS)+ PathTemplate ;
resourceTag         : uriTag | fileTag ;

inputPortKeyword    : InKeyword | ParamKeyword ;
outputPortKeyword   : OutKeyword | ReturnKeyword ;

// YW keyword arguments
blockName       : phrase ;
portName        : ID ;
dataName        : ID ;
uriTemplate     : ((scheme) ':')? PathTemplate ;
scheme          : 'file' | 'http' ; 
description     : phrase;
phrase          : ID (HS+ ID)* ;

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

VS              : (HS)* NL (HS)* ;
HS              : [ \t] ;
NL              : '\r'? '\n' ;

ID              : [a-zA-Z0-9\\_]+ ;
PathTemplate    : ID ;
WS              : [ \t\r\n] ;
SP              : ' ' | '\t' ;
