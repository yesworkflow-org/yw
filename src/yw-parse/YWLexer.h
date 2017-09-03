
// Generated from YW.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace yw {


class  YWLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, AsKeyword = 3, BeginKeyword = 4, CallKeyword = 5, 
    DescKeyword = 6, EndKeyword = 7, FileKeyword = 8, InKeyword = 9, OutKeyword = 10, 
    ParamKeyword = 11, ReturnKeyword = 12, UriKeyword = 13, DQ = 14, SQ = 15, 
    SPACE = 16, NEWLINE = 17, COLON = 18, WORD = 19, OTHER = 20
  };

  YWLexer(antlr4::CharStream *input);
  ~YWLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace yw
