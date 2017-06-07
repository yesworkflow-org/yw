
// Generated from YW.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  YWParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, ID = 14, 
    PATH_TEMPLATE = 15, EOL = 16, WS = 17
  };

  enum {
    RuleScript = 0, RuleBlock = 1, RuleBlockAnnotation = 2, RuleInputPort = 3, 
    RuleOutputPort = 4, RulePortAnnotation = 5, RuleAs = 6, RuleBegin = 7, 
    RuleCall = 8, RuleEnd = 9, RuleFile = 10, RuleIn = 11, RuleOut = 12, 
    RuleParam = 13, RuleRet = 14, RuleUri = 15, RuleAsKeyword = 16, RuleBeginKeyword = 17, 
    RuleCallKeyword = 18, RuleEndKeyword = 19, RuleFileKeyword = 20, RuleInKeyword = 21, 
    RuleOutKeyword = 22, RuleParamKeyword = 23, RuleReturnKeyword = 24, 
    RuleUriKeyword = 25, RuleBlockName = 26, RuleVariableName = 27, RuleAlias = 28, 
    RuleUriTemplate = 29, RuleScheme = 30
  };

  YWParser(antlr4::TokenStream *input);
  ~YWParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ScriptContext;
  class BlockContext;
  class BlockAnnotationContext;
  class InputPortContext;
  class OutputPortContext;
  class PortAnnotationContext;
  class AsContext;
  class BeginContext;
  class CallContext;
  class EndContext;
  class FileContext;
  class InContext;
  class OutContext;
  class ParamContext;
  class RetContext;
  class UriContext;
  class AsKeywordContext;
  class BeginKeywordContext;
  class CallKeywordContext;
  class EndKeywordContext;
  class FileKeywordContext;
  class InKeywordContext;
  class OutKeywordContext;
  class ParamKeywordContext;
  class ReturnKeywordContext;
  class UriKeywordContext;
  class BlockNameContext;
  class VariableNameContext;
  class AliasContext;
  class UriTemplateContext;
  class SchemeContext; 

  class  ScriptContext : public antlr4::ParserRuleContext {
  public:
    ScriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScriptContext* script();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BeginContext *begin();
    EndContext *end();
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    std::vector<BlockAnnotationContext *> blockAnnotation();
    BlockAnnotationContext* blockAnnotation(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockContext* block();

  class  BlockAnnotationContext : public antlr4::ParserRuleContext {
  public:
    BlockAnnotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InputPortContext *inputPort();
    OutputPortContext *outputPort();
    CallContext *call();
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockAnnotationContext* blockAnnotation();

  class  InputPortContext : public antlr4::ParserRuleContext {
  public:
    InputPortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InContext *in();
    ParamContext *param();
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);
    std::vector<PortAnnotationContext *> portAnnotation();
    PortAnnotationContext* portAnnotation(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InputPortContext* inputPort();

  class  OutputPortContext : public antlr4::ParserRuleContext {
  public:
    OutputPortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OutContext *out();
    RetContext *ret();
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);
    std::vector<PortAnnotationContext *> portAnnotation();
    PortAnnotationContext* portAnnotation(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OutputPortContext* outputPort();

  class  PortAnnotationContext : public antlr4::ParserRuleContext {
  public:
    PortAnnotationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AsContext *as();
    UriContext *uri();
    std::vector<antlr4::tree::TerminalNode *> EOL();
    antlr4::tree::TerminalNode* EOL(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortAnnotationContext* portAnnotation();

  class  AsContext : public antlr4::ParserRuleContext {
  public:
    AsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AsKeywordContext *asKeyword();
    AliasContext *alias();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AsContext* as();

  class  BeginContext : public antlr4::ParserRuleContext {
  public:
    BeginContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BeginKeywordContext *beginKeyword();
    BlockNameContext *blockName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BeginContext* begin();

  class  CallContext : public antlr4::ParserRuleContext {
  public:
    CallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CallKeywordContext *callKeyword();
    BlockNameContext *blockName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CallContext* call();

  class  EndContext : public antlr4::ParserRuleContext {
  public:
    EndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EndKeywordContext *endKeyword();
    BlockNameContext *blockName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EndContext* end();

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FileKeywordContext *fileKeyword();
    antlr4::tree::TerminalNode *PATH_TEMPLATE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  InContext : public antlr4::ParserRuleContext {
  public:
    InContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InKeywordContext *inKeyword();
    VariableNameContext *variableName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InContext* in();

  class  OutContext : public antlr4::ParserRuleContext {
  public:
    OutContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OutKeywordContext *outKeyword();
    VariableNameContext *variableName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OutContext* out();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamKeywordContext *paramKeyword();
    VariableNameContext *variableName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParamContext* param();

  class  RetContext : public antlr4::ParserRuleContext {
  public:
    RetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ReturnKeywordContext *returnKeyword();
    VariableNameContext *variableName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RetContext* ret();

  class  UriContext : public antlr4::ParserRuleContext {
  public:
    UriContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UriKeywordContext *uriKeyword();
    UriTemplateContext *uriTemplate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UriContext* uri();

  class  AsKeywordContext : public antlr4::ParserRuleContext {
  public:
    AsKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AsKeywordContext* asKeyword();

  class  BeginKeywordContext : public antlr4::ParserRuleContext {
  public:
    BeginKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BeginKeywordContext* beginKeyword();

  class  CallKeywordContext : public antlr4::ParserRuleContext {
  public:
    CallKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CallKeywordContext* callKeyword();

  class  EndKeywordContext : public antlr4::ParserRuleContext {
  public:
    EndKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EndKeywordContext* endKeyword();

  class  FileKeywordContext : public antlr4::ParserRuleContext {
  public:
    FileKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileKeywordContext* fileKeyword();

  class  InKeywordContext : public antlr4::ParserRuleContext {
  public:
    InKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InKeywordContext* inKeyword();

  class  OutKeywordContext : public antlr4::ParserRuleContext {
  public:
    OutKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OutKeywordContext* outKeyword();

  class  ParamKeywordContext : public antlr4::ParserRuleContext {
  public:
    ParamKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParamKeywordContext* paramKeyword();

  class  ReturnKeywordContext : public antlr4::ParserRuleContext {
  public:
    ReturnKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ReturnKeywordContext* returnKeyword();

  class  UriKeywordContext : public antlr4::ParserRuleContext {
  public:
    UriKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UriKeywordContext* uriKeyword();

  class  BlockNameContext : public antlr4::ParserRuleContext {
  public:
    BlockNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockNameContext* blockName();

  class  VariableNameContext : public antlr4::ParserRuleContext {
  public:
    VariableNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableNameContext* variableName();

  class  AliasContext : public antlr4::ParserRuleContext {
  public:
    AliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AliasContext* alias();

  class  UriTemplateContext : public antlr4::ParserRuleContext {
  public:
    UriTemplateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PATH_TEMPLATE();
    SchemeContext *scheme();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UriTemplateContext* uriTemplate();

  class  SchemeContext : public antlr4::ParserRuleContext {
  public:
    SchemeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SchemeContext* scheme();


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

