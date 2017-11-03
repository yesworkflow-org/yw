grammar YW ;

// YW annotation compositions
script          : na? block (na? block)* na? EOF ;
block           : begin (na? blockAttribute)* (na? io)* nestedBlocks na? end ;
nestedBlocks	: (na? block)* ;
blockAttribute  : blockDesc ;
io				: port (na? portAttribute)* ;
port  		    : portKeyword (SPACE+ portName)+ ;
portAttribute   : portDesc | alias | resource ;

// YW annotations
alias			: AsKeyword (SPACE)+ dataName ;
begin			: BeginKeyword (SPACE)+ blockName ;
blockDesc       : DescKeyword (SPACE)+ description ;
portDesc        : DescKeyword (SPACE)+ description ;
end				: EndKeyword ((SPACE)+ (blockName))? ;
file            : FileKeyword (SPACE)+ pathTemplate ;
uri             : UriKeyword (SPACE)+ uriTemplate;

misplacedEnd		: EndKeyword ;
misplacedBeginChild : DescKeyword | InKeyword | OutKeyword | ParamKeyword;
misplacedPortChild  : AsKeyword | DescKeyword | FileKeyword | UriKeyword ;
misplacedKeyword    : misplacedEnd | misplacedBeginChild | misplacedPortChild ;

resource        : uri | file ;

portKeyword		: inputKeyword | outputKeyword;
inputKeyword    : InKeyword | ParamKeyword ;
outputKeyword   : OutKeyword ;

// YW keyword arguments
blockName       : phrase ;
portName        : word ;
dataName        : phrase ;
description     : phrase;

pathElement     : (pathConstant | pathVariable)+ ;
pathVariable	: LEFTBRACE variableName RIGHTBRACE ;
pathConstant	: WORD ;
variableName	: WORD ;

pathTemplate    : SLASH? pathElement? (SLASH pathElement)* SLASH? ;
uriTemplate     : (scheme ':')? SLASH*? pathTemplate ;
scheme          : WORD ; 

phrase			: unquotedPhrase | (SQ unquotedPhrase SQ) | (DQ unquotedPhrase DQ) ;
unquotedPhrase  : WORD (SPACE+ WORD)* ;

word			: unquotedWord | (SQ unquotedWord SQ) | (DQ unquotedWord DQ) ;
unquotedWord	: WORD ;

// YW keywords
AsKeyword       : '@as'    | '@AS' ;
BeginKeyword    : '@begin' | '@BEGIN' ;
DescKeyword     : '@desc'  | '@DESC' ;
EndKeyword      : '@end'   | '@END';  
FileKeyword     : '@file'  | '@FILE' ;
InKeyword       : '@in'    | '@IN' ;
OutKeyword      : '@out'   | '@OUT' ;
ParamKeyword    : '@param' | '@PARAM' ;
UriKeyword      : '@uri'   | '@URI' ;

na				: (SPACE | NEWLINE | DQ | SQ | WORD | COLON | SLASH | LEFTBRACE| RIGHTBRACE | OTHER )+ ;

DQ				: '"' ;
SQ				: '\'' ;
SPACE           : [ \t] ;
SLASH			: '/' ;
LEFTBRACE		: '{' ;
RIGHTBRACE		: '}' ;
NEWLINE         : '\r'? '\n' ;
COLON			: ':' ;
WORD            : [a-zA-Z0-9\\_.]+ ;
OTHER			: .+? ;
