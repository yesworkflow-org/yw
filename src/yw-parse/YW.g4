grammar YW ;

// YW annotation compositions
script              : (block)* ;
block               : beginKeyword blockName (blockAttribute)* (block)* endKeyword (blockName)? ;
blockAttribute      : description | port | call;
description         : descKeyword text ;
port                : (inputPortKeyword | outputPortKeyword) (portName (portAttribute)*)+ ;
call                : callKeyword (blockName)+ ;
inputPortKeyword    : inKeyword | paramKeyword ;
outputPortKeyword   : outKeyword | returnKeyword ;
portAttribute       : description | portAlias | resourceDecl ;
portAlias           : asKeyword dataName ;
resourceDecl        : uriDecl | fileDecl ;
uriDecl             : uriKeyword uriTemplate;
fileDecl            : fileKeyword PATH_TEMPLATE ;

// YW keywords
asKeyword       : '@as' ;
beginKeyword    : '@begin' ;
callKeyword     : '@call' ;
endKeyword      : '@end' ; 
fileKeyword     : '@file' ;
inKeyword       : '@in' ;
outKeyword      : '@out' ;
paramKeyword    : '@param' ;
returnKeyword   : '@return' ;
uriKeyword      : '@uri' ;
descKeyword     : '@desc' ;

// YW keyword arguments
blockName       : ID ;
portName        : ID ;
dataName        : ID ;
uriTemplate     : ((scheme) ':')? PATH_TEMPLATE ;
scheme          : 'file' | 'http' ; 
text            : ID ;

// lexer rules
ID              : [a-zA-Z0-9\\_]+ ;
PATH_TEMPLATE   : ID ;
