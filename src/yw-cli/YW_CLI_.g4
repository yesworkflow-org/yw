grammar YW_CLI_ ;

// command line
commandLine      : program (SPACE+ pflag)* ( SPACE+ command (SPACE+ (argument | config))* )? NEWLINE*;
program          : WORD ;
command          : WORD ;
argument         : WORD ;

// program flags
pflag            : helpflag | versionflag ;
helpflag         : '-h' | '--help' ;
versionflag      : '-v' | '--version' ;

// command configuration options
config           : (cflag (SPACE+ (configName ('=' configValue)? ))) | (configName '=' configValue) ;
cflag            : '-c' | '-config' | '--config' ;
configName       : WORD ;
configValue      : unquotedValue | (SQ unquotedValue SQ) | (DQ unquotedValue DQ) ;
unquotedValue    : WORD | WORD (SPACE+ WORD)* ;

// lexical tokens
NEWLINE          : '\r'? '\n' ;
SPACE            : [ ] ;
DQ               : '"' ;
SQ               : '\'' ;
WORD             : ~[= \t\r\n"']+ ;

