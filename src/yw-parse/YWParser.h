
// Generated from YW.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  YWParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    ID = 15, PATH_TEMPLATE = 16, HS = 17, NL = 18, WS = 19, SP = 20
  };

  enum {
    RuleScript = 0, RuleBlock = 1, RuleBlockAttribute = 2, RulePortAttribute = 3, 
    RuleBeginTag = 4, RuleEndTag = 5, RuleDescTag = 6, RulePortTag = 7, 
    RuleAliasTag = 8, RuleCallTag = 9, RuleUriTag = 10, RuleFileTag = 11, 
    RuleResourceTag = 12, RuleInputPortKeyword = 13, RuleOutputPortKeyword = 14, 
    RuleAsKeyword = 15, RuleBeginKeyword = 16, RuleCallKeyword = 17, RuleDescKeyword = 18, 
    RuleEndKeyword = 19, RuleFileKeyword = 20, RuleInKeyword = 21, RuleOutKeyword = 22, 
    RuleParamKeyword = 23, RuleReturnKeyword = 24, RuleUriKeyword = 25, 
    RuleBlockName = 26, RulePortName = 27, RuleDataName = 28, RuleUriTemplate = 29, 
    RuleScheme = 30, RuleDescription = 31
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
  class BlockAttributeContext;
  class PortAttributeContext;
  class BeginTagContext;
  class EndTagContext;
  class DescTagContext;
  class PortTagContext;
  class AliasTagContext;
  class CallTagContext;
  class UriTagContext;
  class FileTagContext;
  class ResourceTagContext;
  class InputPortKeywordContext;
  class OutputPortKeywordContext;
  class AsKeywordContext;
  class BeginKeywordContext;
  class CallKeywordContext;
  class DescKeywordContext;
  class EndKeywordContext;
  class FileKeywordContext;
  class InKeywordContext;
  class OutKeywordContext;
  class ParamKeywordContext;
  class ReturnKeywordContext;
  class UriKeywordContext;
  class BlockNameContext;
  class PortNameContext;
  class DataNameContext;
  class UriTemplateContext;
  class SchemeContext;
  class DescriptionContext; 

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
    BeginTagContext *beginTag();
    EndTagContext *endTag();
    std::vector<antlr4::tree::TerminalNode *> WS();
    antlr4::tree::TerminalNode* WS(size_t i);
    std::vector<BlockAttributeContext *> blockAttribute();
    BlockAttributeContext* blockAttribute(size_t i);
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockContext* block();

  class  BlockAttributeContext : public antlr4::ParserRuleContext {
  public:
    BlockAttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DescTagContext *descTag();
    PortTagContext *portTag();
    CallTagContext *callTag();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockAttributeContext* blockAttribute();

  class  PortAttributeContext : public antlr4::ParserRuleContext {
  public:
    PortAttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DescTagContext *descTag();
    AliasTagContext *aliasTag();
    ResourceTagContext *resourceTag();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortAttributeContext* portAttribute();

  class  BeginTagContext : public antlr4::ParserRuleContext {
  public:
    BeginTagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BeginKeywordContext *beginKeyword();
    BlockNameContext *blockName();
    std::vector<antlr4::tree::TerminalNode *> HS();
    antlr4::tree::TerminalNode* HS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BeginTagContext* beginTag();

  class  EndTagContext : public antlr4::ParserRuleContext {
  public:
    EndTagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EndKeywordContext *endKeyword();
    std::vector<antlr4::tree::TerminalNode *> HS();
    antlr4::tree::TerminalNode* HS(size_t i);
    BlockNameContext *blockName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EndTagContext* endTag();

  class  DescTagContext : public antlr4::ParserRuleContext {
  public:
    DescTagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DescKeywordContext *descKeyword();
    DescriptionContext *description();
    std::vector<antlr4::tree::TerminalNode *> HS();
    antlr4::tree::TerminalNode* HS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DescTagContext* descTag();

  class  PortTagContext : public antlr4::ParserRuleContext {
  public:
    PortTagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InputPortKeywordContext *inputPortKeyword();
    OutputPortKeywordContext *outputPortKeyword();
    std::vector<PortNameContext *> portName();
    PortNameContext* portName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> HS();
    antlr4::tree::TerminalNode* HS(size_t i);
    std::vector<PortAttributeContext *> portAttribute();
    PortAttributeContext* portAttribute(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortTagContext* portTag();

  class  AliasTagContext : public antlr4::ParserRuleContext {
  public:
    AliasTagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AsKeywordContext *asKeyword();
    DataNameContext *dataName();
    std::vector<antlr4::tree::TerminalNode *> HS();
    antlr4::tree::TerminalNode* HS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AliasTagContext* aliasTag();

  class  CallTagContext : public antlr4::ParserRuleContext {
  public:
    CallTagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CallKeywordContext *callKeyword();
    std::vector<antlr4::tree::TerminalNode *> HS();
    antlr4::tree::TerminalNode* HS(size_t i);
    std::vector<BlockNameContext *> blockName();
    BlockNameContext* blockName(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CallTagContext* callTag();

  class  UriTagContext : public antlr4::ParserRuleContext {
  public:
    UriTagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UriKeywordContext *uriKeyword();
    UriTemplateContext *uriTemplate();
    std::vector<antlr4::tree::TerminalNode *> HS();
    antlr4::tree::TerminalNode* HS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UriTagContext* uriTag();

  class  FileTagContext : public antlr4::ParserRuleContext {
  public:
    FileTagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FileKeywordContext *fileKeyword();
    antlr4::tree::TerminalNode *PATH_TEMPLATE();
    std::vector<antlr4::tree::TerminalNode *> HS();
    antlr4::tree::TerminalNode* HS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileTagContext* fileTag();

  class  ResourceTagContext : public antlr4::ParserRuleContext {
  public:
    ResourceTagContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UriTagContext *uriTag();
    FileTagContext *fileTag();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ResourceTagContext* resourceTag();

  class  InputPortKeywordContext : public antlr4::ParserRuleContext {
  public:
    InputPortKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InKeywordContext *inKeyword();
    ParamKeywordContext *paramKeyword();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InputPortKeywordContext* inputPortKeyword();

  class  OutputPortKeywordContext : public antlr4::ParserRuleContext {
  public:
    OutputPortKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    OutKeywordContext *outKeyword();
    ReturnKeywordContext *returnKeyword();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OutputPortKeywordContext* outputPortKeyword();

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

  class  DescKeywordContext : public antlr4::ParserRuleContext {
  public:
    DescKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DescKeywordContext* descKeyword();

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

  class  PortNameContext : public antlr4::ParserRuleContext {
  public:
    PortNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortNameContext* portName();

  class  DataNameContext : public antlr4::ParserRuleContext {
  public:
    DataNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DataNameContext* dataName();

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

  class  DescriptionContext : public antlr4::ParserRuleContext {
  public:
    DescriptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DescriptionContext* description();


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

