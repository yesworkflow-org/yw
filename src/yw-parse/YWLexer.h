
// Generated from YW.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace yw {


class  YWLexer : public antlr4::Lexer {
public:
  enum {
    AsKeyword = 1, BeginKeyword = 2, DescKeyword = 3, EndKeyword = 4, FileKeyword = 5, 
    InKeyword = 6, OutKeyword = 7, ParamKeyword = 8, UriKeyword = 9, DQ = 10, 
    SQ = 11, SPACE = 12, SLASH = 13, LEFTBRACE = 14, RIGHTBRACE = 15, NEWLINE = 16, 
    COLON = 17, WORD = 18, OTHER = 19
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
