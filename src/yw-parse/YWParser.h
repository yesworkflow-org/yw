
// Generated from YW.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"




class  YWParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    ID = 15, PATH_TEMPLATE = 16
  };

  enum {
    RuleScript = 0, RuleBlock = 1, RuleBlockAttribute = 2, RuleDescription = 3, 
    RulePort = 4, RuleCall = 5, RuleInputPortKeyword = 6, RuleOutputPortKeyword = 7, 
    RulePortAttribute = 8, RulePortAlias = 9, RuleResourceDecl = 10, RuleUriDecl = 11, 
    RuleFileDecl = 12, RuleAsKeyword = 13, RuleBeginKeyword = 14, RuleCallKeyword = 15, 
    RuleEndKeyword = 16, RuleFileKeyword = 17, RuleInKeyword = 18, RuleOutKeyword = 19, 
    RuleParamKeyword = 20, RuleReturnKeyword = 21, RuleUriKeyword = 22, 
    RuleDescKeyword = 23, RuleBlockName = 24, RulePortName = 25, RuleDataName = 26, 
    RuleUriTemplate = 27, RuleScheme = 28, RuleText = 29
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
  class DescriptionContext;
  class PortContext;
  class CallContext;
  class InputPortKeywordContext;
  class OutputPortKeywordContext;
  class PortAttributeContext;
  class PortAliasContext;
  class ResourceDeclContext;
  class UriDeclContext;
  class FileDeclContext;
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
  class DescKeywordContext;
  class BlockNameContext;
  class PortNameContext;
  class DataNameContext;
  class UriTemplateContext;
  class SchemeContext;
  class TextContext; 

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
    BeginKeywordContext *beginKeyword();
    std::vector<BlockNameContext *> blockName();
    BlockNameContext* blockName(size_t i);
    EndKeywordContext *endKeyword();
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
    DescriptionContext *description();
    PortContext *port();
    CallContext *call();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockAttributeContext* blockAttribute();

  class  DescriptionContext : public antlr4::ParserRuleContext {
  public:
    DescriptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DescKeywordContext *descKeyword();
    TextContext *text();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DescriptionContext* description();

  class  PortContext : public antlr4::ParserRuleContext {
  public:
    PortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InputPortKeywordContext *inputPortKeyword();
    OutputPortKeywordContext *outputPortKeyword();
    std::vector<PortNameContext *> portName();
    PortNameContext* portName(size_t i);
    std::vector<PortAttributeContext *> portAttribute();
    PortAttributeContext* portAttribute(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortContext* port();

  class  CallContext : public antlr4::ParserRuleContext {
  public:
    CallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CallKeywordContext *callKeyword();
    std::vector<BlockNameContext *> blockName();
    BlockNameContext* blockName(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CallContext* call();

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

  class  PortAttributeContext : public antlr4::ParserRuleContext {
  public:
    PortAttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DescriptionContext *description();
    PortAliasContext *portAlias();
    ResourceDeclContext *resourceDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortAttributeContext* portAttribute();

  class  PortAliasContext : public antlr4::ParserRuleContext {
  public:
    PortAliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AsKeywordContext *asKeyword();
    DataNameContext *dataName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortAliasContext* portAlias();

  class  ResourceDeclContext : public antlr4::ParserRuleContext {
  public:
    ResourceDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UriDeclContext *uriDecl();
    FileDeclContext *fileDecl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ResourceDeclContext* resourceDecl();

  class  UriDeclContext : public antlr4::ParserRuleContext {
  public:
    UriDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UriKeywordContext *uriKeyword();
    UriTemplateContext *uriTemplate();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UriDeclContext* uriDecl();

  class  FileDeclContext : public antlr4::ParserRuleContext {
  public:
    FileDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FileKeywordContext *fileKeyword();
    antlr4::tree::TerminalNode *PATH_TEMPLATE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileDeclContext* fileDecl();

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

  class  DescKeywordContext : public antlr4::ParserRuleContext {
  public:
    DescKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DescKeywordContext* descKeyword();

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

  class  TextContext : public antlr4::ParserRuleContext {
  public:
    TextContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TextContext* text();


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

