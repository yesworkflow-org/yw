
// Generated from ywcli.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace yw {


class  ywcliParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, NEWLINE = 9, SPACE = 10, DQ = 11, SQ = 12, WORD = 13
  };

  enum {
    RuleCommandLine = 0, RuleProgram = 1, RuleCommand = 2, RuleArgument = 3, 
    RulePflag = 4, RuleHelpflag = 5, RuleVersionflag = 6, RuleConfig = 7, 
    RuleCflag = 8, RuleConfigOption = 9, RuleConfigAssignment = 10, RuleConfigName = 11, 
    RuleConfigValue = 12, RuleUnquotedValue = 13
  };

  ywcliParser(antlr4::TokenStream *input);
  ~ywcliParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class CommandLineContext;
  class ProgramContext;
  class CommandContext;
  class ArgumentContext;
  class PflagContext;
  class HelpflagContext;
  class VersionflagContext;
  class ConfigContext;
  class CflagContext;
  class ConfigOptionContext;
  class ConfigAssignmentContext;
  class ConfigNameContext;
  class ConfigValueContext;
  class UnquotedValueContext; 

  class  CommandLineContext : public antlr4::ParserRuleContext {
  public:
    CommandLineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();
    std::vector<PflagContext *> pflag();
    PflagContext* pflag(size_t i);
    CommandContext *command();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<ArgumentContext *> argument();
    ArgumentContext* argument(size_t i);
    std::vector<ConfigContext *> config();
    ConfigContext* config(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CommandLineContext* commandLine();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();

  class  CommandContext : public antlr4::ParserRuleContext {
  public:
    CommandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CommandContext* command();

  class  ArgumentContext : public antlr4::ParserRuleContext {
  public:
    ArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentContext* argument();

  class  PflagContext : public antlr4::ParserRuleContext {
  public:
    PflagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    HelpflagContext *helpflag();
    VersionflagContext *versionflag();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PflagContext* pflag();

  class  HelpflagContext : public antlr4::ParserRuleContext {
  public:
    HelpflagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  HelpflagContext* helpflag();

  class  VersionflagContext : public antlr4::ParserRuleContext {
  public:
    VersionflagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VersionflagContext* versionflag();

  class  ConfigContext : public antlr4::ParserRuleContext {
  public:
    ConfigContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CflagContext *cflag();
    ConfigOptionContext *configOption();
    ConfigAssignmentContext *configAssignment();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConfigContext* config();

  class  CflagContext : public antlr4::ParserRuleContext {
  public:
    CflagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CflagContext* cflag();

  class  ConfigOptionContext : public antlr4::ParserRuleContext {
  public:
    ConfigOptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConfigNameContext *configName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConfigOptionContext* configOption();

  class  ConfigAssignmentContext : public antlr4::ParserRuleContext {
  public:
    ConfigAssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConfigNameContext *configName();
    ConfigValueContext *configValue();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConfigAssignmentContext* configAssignment();

  class  ConfigNameContext : public antlr4::ParserRuleContext {
  public:
    ConfigNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConfigNameContext* configName();

  class  ConfigValueContext : public antlr4::ParserRuleContext {
  public:
    ConfigValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnquotedValueContext *unquotedValue();
    std::vector<antlr4::tree::TerminalNode *> SQ();
    antlr4::tree::TerminalNode* SQ(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DQ();
    antlr4::tree::TerminalNode* DQ(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConfigValueContext* configValue();

  class  UnquotedValueContext : public antlr4::ParserRuleContext {
  public:
    UnquotedValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

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
