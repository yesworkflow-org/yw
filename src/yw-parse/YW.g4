grammar YW ;

// YW annotation compositions
script          : ws? block (ws block)* ws?;
block           : begin (ws blockAttribute)* (ws block)* ws end ;
blockAttribute  : io | desc | call;
io				: port (ws portAttribute)* ;
port  		    : (inputKeyword | outputKeyword) (SPACE+ portName)+ ;
portAttribute   : desc | alias | resource ;

// YW annotations
begin			: BeginKeyword (SPACE)+ blockName ;
end				: EndKeyword ((SPACE)+ (blockName))? ;
desc            : DescKeyword (SPACE)+ description ;
alias			: AsKeyword (SPACE)+ dataName ;
call			: CallKeyword (SPACE)+ (blockName)+ ;
uri             : UriKeyword (SPACE)+ uriTemplate;
file            : FileKeyword (SPACE)+ pathTemplate ;
resource        : uri | file ;

inputKeyword    : InKeyword | ParamKeyword ;
outputKeyword   : OutKeyword | ReturnKeyword ;

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

SPACE           : [ \t] ;
NEWLINE         : '\r'? '\n' ;
Word            : [a-zA-Z0-9\\_]+ ;

