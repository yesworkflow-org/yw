
// Generated from YW_CONFIG_.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace yw {


class  YW_CONFIG_Parser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, NEWLINE = 4, SPACE = 5, DQ = 6, SQ = 7, 
    WORD = 8
  };

  enum {
    RuleConfigFile = 0, RuleBlankLine = 1, RuleCommentLine = 2, RuleSettingLine = 3, 
    RuleComment = 4, RuleSetting = 5, RuleSettingName = 6, RuleSettingValue = 7, 
    RuleUnquotedValue = 8
  };

  YW_CONFIG_Parser(antlr4::TokenStream *input);
  ~YW_CONFIG_Parser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ConfigFileContext;
  class BlankLineContext;
  class CommentLineContext;
  class SettingLineContext;
  class CommentContext;
  class SettingContext;
  class SettingNameContext;
  class SettingValueContext;
  class UnquotedValueContext; 

  class  ConfigFileContext : public antlr4::ParserRuleContext {
  public:
    ConfigFileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlankLineContext *> blankLine();
    BlankLineContext* blankLine(size_t i);
    std::vector<CommentLineContext *> commentLine();
    CommentLineContext* commentLine(size_t i);
    std::vector<SettingLineContext *> settingLine();
    SettingLineContext* settingLine(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConfigFileContext* configFile();

  class  BlankLineContext : public antlr4::ParserRuleContext {
  public:
    BlankLineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlankLineContext* blankLine();

  class  CommentLineContext : public antlr4::ParserRuleContext {
  public:
    CommentLineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CommentContext *comment();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CommentLineContext* commentLine();

  class  SettingLineContext : public antlr4::ParserRuleContext {
  public:
    SettingLineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SettingContext *setting();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);
    CommentContext *comment();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SettingLineContext* settingLine();

  class  CommentContext : public antlr4::ParserRuleContext {
  public:
    CommentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CommentContext* comment();

  class  SettingContext : public antlr4::ParserRuleContext {
  public:
    SettingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SettingNameContext *settingName();
    SettingValueContext *settingValue();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SettingContext* setting();

  class  SettingNameContext : public antlr4::ParserRuleContext {
  public:
    SettingNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SettingNameContext* settingName();

  class  SettingValueContext : public antlr4::ParserRuleContext {
  public:
    SettingValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnquotedValueContext *unquotedValue();
    std::vector<antlr4::tree::TerminalNode *> SQ();
    antlr4::tree::TerminalNode* SQ(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DQ();
    antlr4::tree::TerminalNode* DQ(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SettingValueContext* settingValue();

  class  UnquotedValueContext : public antlr4::ParserRuleContext {
  public:
    UnquotedValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnquotedValueContext* unquotedValue();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace yw
