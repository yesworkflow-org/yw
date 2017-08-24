
// Generated from YW.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"


namespace yw {


class  YWParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, AsKeyword = 4, BeginKeyword = 5, CallKeyword = 6, 
    DescKeyword = 7, EndKeyword = 8, FileKeyword = 9, InKeyword = 10, OutKeyword = 11, 
    ParamKeyword = 12, ReturnKeyword = 13, UriKeyword = 14, DQ = 15, SQ = 16, 
    SPACE = 17, NEWLINE = 18, WORD = 19, OTHER = 20
  };

  enum {
    RuleScript = 0, RuleBlock = 1, RuleNestedBlocks = 2, RuleBlockAttribute = 3, 
    RuleIo = 4, RulePort = 5, RulePortAttribute = 6, RuleBegin = 7, RuleEnd = 8, 
    RuleDesc = 9, RuleAlias = 10, RuleCall = 11, RuleUri = 12, RuleFile = 13, 
    RuleResource = 14, RuleInputKeyword = 15, RuleOutputKeyword = 16, RuleBlockName = 17, 
    RulePortName = 18, RuleDataName = 19, RuleDescription = 20, RulePathTemplate = 21, 
    RuleUriTemplate = 22, RuleScheme = 23, RulePhrase = 24, RuleUnquotedPhrase = 25, 
    RuleWord = 26, RuleUnquotedWord = 27, RuleNa = 28
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
  class NestedBlocksContext;
  class BlockAttributeContext;
  class IoContext;
  class PortContext;
  class PortAttributeContext;
  class BeginContext;
  class EndContext;
  class DescContext;
  class AliasContext;
  class CallContext;
  class UriContext;
  class FileContext;
  class ResourceContext;
  class InputKeywordContext;
  class OutputKeywordContext;
  class BlockNameContext;
  class PortNameContext;
  class DataNameContext;
  class DescriptionContext;
  class PathTemplateContext;
  class UriTemplateContext;
  class SchemeContext;
  class PhraseContext;
  class UnquotedPhraseContext;
  class WordContext;
  class UnquotedWordContext;
  class NaContext; 

  class  ScriptContext : public antlr4::ParserRuleContext {
  public:
    ScriptContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    std::vector<NaContext *> na();
    NaContext* na(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ScriptContext* script();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BeginContext *begin();
    NestedBlocksContext *nestedBlocks();
    EndContext *end();
    std::vector<BlockAttributeContext *> blockAttribute();
    BlockAttributeContext* blockAttribute(size_t i);
    std::vector<NaContext *> na();
    NaContext* na(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockContext* block();

  class  NestedBlocksContext : public antlr4::ParserRuleContext {
  public:
    NestedBlocksContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    std::vector<NaContext *> na();
    NaContext* na(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NestedBlocksContext* nestedBlocks();

  class  BlockAttributeContext : public antlr4::ParserRuleContext {
  public:
    BlockAttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IoContext *io();
    DescContext *desc();
    CallContext *call();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockAttributeContext* blockAttribute();

  class  IoContext : public antlr4::ParserRuleContext {
  public:
    IoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PortContext *port();
    std::vector<PortAttributeContext *> portAttribute();
    PortAttributeContext* portAttribute(size_t i);
    std::vector<NaContext *> na();
    NaContext* na(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IoContext* io();

  class  PortContext : public antlr4::ParserRuleContext {
  public:
    PortContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InputKeywordContext *inputKeyword();
    OutputKeywordContext *outputKeyword();
    std::vector<PortNameContext *> portName();
    PortNameContext* portName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortContext* port();

  class  PortAttributeContext : public antlr4::ParserRuleContext {
  public:
    PortAttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DescContext *desc();
    AliasContext *alias();
    ResourceContext *resource();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortAttributeContext* portAttribute();

  class  BeginContext : public antlr4::ParserRuleContext {
  public:
    BeginContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BeginKeyword();
    BlockNameContext *blockName();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BeginContext* begin();

  class  EndContext : public antlr4::ParserRuleContext {
  public:
    EndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EndKeyword();
    BlockNameContext *blockName();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EndContext* end();

  class  DescContext : public antlr4::ParserRuleContext {
  public:
    DescContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DescKeyword();
    DescriptionContext *description();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DescContext* desc();

  class  AliasContext : public antlr4::ParserRuleContext {
  public:
    AliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AsKeyword();
    DataNameContext *dataName();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AliasContext* alias();

  class  CallContext : public antlr4::ParserRuleContext {
  public:
    CallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CallKeyword();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);
    std::vector<BlockNameContext *> blockName();
    BlockNameContext* blockName(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CallContext* call();

  class  UriContext : public antlr4::ParserRuleContext {
  public:
    UriContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UriKeyword();
    UriTemplateContext *uriTemplate();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UriContext* uri();

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FileKeyword();
    PathTemplateContext *pathTemplate();
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  ResourceContext : public antlr4::ParserRuleContext {
  public:
    ResourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UriContext *uri();
    FileContext *file();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ResourceContext* resource();

  class  InputKeywordContext : public antlr4::ParserRuleContext {
  public:
    InputKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *InKeyword();
    antlr4::tree::TerminalNode *ParamKeyword();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InputKeywordContext* inputKeyword();

  class  OutputKeywordContext : public antlr4::ParserRuleContext {
  public:
    OutputKeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OutKeyword();
    antlr4::tree::TerminalNode *ReturnKeyword();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OutputKeywordContext* outputKeyword();

  class  BlockNameContext : public antlr4::ParserRuleContext {
  public:
    BlockNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PhraseContext *phrase();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockNameContext* blockName();

  class  PortNameContext : public antlr4::ParserRuleContext {
  public:
    PortNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    WordContext *word();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PortNameContext* portName();

  class  DataNameContext : public antlr4::ParserRuleContext {
  public:
    DataNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PhraseContext *phrase();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DataNameContext* dataName();

  class  DescriptionContext : public antlr4::ParserRuleContext {
  public:
    DescriptionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PhraseContext *phrase();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DescriptionContext* description();

  class  PathTemplateContext : public antlr4::ParserRuleContext {
  public:
    PathTemplateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    WordContext *word();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PathTemplateContext* pathTemplate();

  class  UriTemplateContext : public antlr4::ParserRuleContext {
  public:
    UriTemplateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PathTemplateContext *pathTemplate();
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

  class  PhraseContext : public antlr4::ParserRuleContext {
  public:
    PhraseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnquotedPhraseContext *unquotedPhrase();
    std::vector<antlr4::tree::TerminalNode *> SQ();
    antlr4::tree::TerminalNode* SQ(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DQ();
    antlr4::tree::TerminalNode* DQ(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PhraseContext* phrase();

  class  UnquotedPhraseContext : public antlr4::ParserRuleContext {
  public:
    UnquotedPhraseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnquotedPhraseContext* unquotedPhrase();

  class  WordContext : public antlr4::ParserRuleContext {
  public:
    WordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnquotedWordContext *unquotedWord();
    std::vector<antlr4::tree::TerminalNode *> SQ();
    antlr4::tree::TerminalNode* SQ(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DQ();
    antlr4::tree::TerminalNode* DQ(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  WordContext* word();

  class  UnquotedWordContext : public antlr4::ParserRuleContext {
  public:
    UnquotedWordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WORD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnquotedWordContext* unquotedWord();

  class  NaContext : public antlr4::ParserRuleContext {
  public:
    NaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SPACE();
    antlr4::tree::TerminalNode* SPACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DQ();
    antlr4::tree::TerminalNode* DQ(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SQ();
    antlr4::tree::TerminalNode* SQ(size_t i);
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OTHER();
    antlr4::tree::TerminalNode* OTHER(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NaContext* na();


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
