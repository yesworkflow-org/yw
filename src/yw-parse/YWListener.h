
// Generated from YW.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "YWParser.h"


namespace yw {

/**
 * This interface defines an abstract listener for a parse tree produced by YWParser.
 */
class  YWListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterScript(YWParser::ScriptContext *ctx) = 0;
  virtual void exitScript(YWParser::ScriptContext *ctx) = 0;

  virtual void enterBlock(YWParser::BlockContext *ctx) = 0;
  virtual void exitBlock(YWParser::BlockContext *ctx) = 0;

  virtual void enterNestedBlocks(YWParser::NestedBlocksContext *ctx) = 0;
  virtual void exitNestedBlocks(YWParser::NestedBlocksContext *ctx) = 0;

  virtual void enterBlockAttribute(YWParser::BlockAttributeContext *ctx) = 0;
  virtual void exitBlockAttribute(YWParser::BlockAttributeContext *ctx) = 0;

  virtual void enterIo(YWParser::IoContext *ctx) = 0;
  virtual void exitIo(YWParser::IoContext *ctx) = 0;

  virtual void enterPort(YWParser::PortContext *ctx) = 0;
  virtual void exitPort(YWParser::PortContext *ctx) = 0;

  virtual void enterPortAttribute(YWParser::PortAttributeContext *ctx) = 0;
  virtual void exitPortAttribute(YWParser::PortAttributeContext *ctx) = 0;

  virtual void enterAlias(YWParser::AliasContext *ctx) = 0;
  virtual void exitAlias(YWParser::AliasContext *ctx) = 0;

  virtual void enterBegin(YWParser::BeginContext *ctx) = 0;
  virtual void exitBegin(YWParser::BeginContext *ctx) = 0;

  virtual void enterBlockDesc(YWParser::BlockDescContext *ctx) = 0;
  virtual void exitBlockDesc(YWParser::BlockDescContext *ctx) = 0;

  virtual void enterPortDesc(YWParser::PortDescContext *ctx) = 0;
  virtual void exitPortDesc(YWParser::PortDescContext *ctx) = 0;

  virtual void enterEnd(YWParser::EndContext *ctx) = 0;
  virtual void exitEnd(YWParser::EndContext *ctx) = 0;

  virtual void enterFile(YWParser::FileContext *ctx) = 0;
  virtual void exitFile(YWParser::FileContext *ctx) = 0;

  virtual void enterUri(YWParser::UriContext *ctx) = 0;
  virtual void exitUri(YWParser::UriContext *ctx) = 0;

  virtual void enterMisplacedEnd(YWParser::MisplacedEndContext *ctx) = 0;
  virtual void exitMisplacedEnd(YWParser::MisplacedEndContext *ctx) = 0;

  virtual void enterMisplacedBeginChild(YWParser::MisplacedBeginChildContext *ctx) = 0;
  virtual void exitMisplacedBeginChild(YWParser::MisplacedBeginChildContext *ctx) = 0;

  virtual void enterMisplacedPortChild(YWParser::MisplacedPortChildContext *ctx) = 0;
  virtual void exitMisplacedPortChild(YWParser::MisplacedPortChildContext *ctx) = 0;

  virtual void enterMisplacedKeyword(YWParser::MisplacedKeywordContext *ctx) = 0;
  virtual void exitMisplacedKeyword(YWParser::MisplacedKeywordContext *ctx) = 0;

  virtual void enterResource(YWParser::ResourceContext *ctx) = 0;
  virtual void exitResource(YWParser::ResourceContext *ctx) = 0;

  virtual void enterInputKeyword(YWParser::InputKeywordContext *ctx) = 0;
  virtual void exitInputKeyword(YWParser::InputKeywordContext *ctx) = 0;

  virtual void enterOutputKeyword(YWParser::OutputKeywordContext *ctx) = 0;
  virtual void exitOutputKeyword(YWParser::OutputKeywordContext *ctx) = 0;

  virtual void enterBlockName(YWParser::BlockNameContext *ctx) = 0;
  virtual void exitBlockName(YWParser::BlockNameContext *ctx) = 0;

  virtual void enterPortName(YWParser::PortNameContext *ctx) = 0;
  virtual void exitPortName(YWParser::PortNameContext *ctx) = 0;

  virtual void enterDataName(YWParser::DataNameContext *ctx) = 0;
  virtual void exitDataName(YWParser::DataNameContext *ctx) = 0;

  virtual void enterDescription(YWParser::DescriptionContext *ctx) = 0;
  virtual void exitDescription(YWParser::DescriptionContext *ctx) = 0;

  virtual void enterPathTemplate(YWParser::PathTemplateContext *ctx) = 0;
  virtual void exitPathTemplate(YWParser::PathTemplateContext *ctx) = 0;

  virtual void enterPathVariable(YWParser::PathVariableContext *ctx) = 0;
  virtual void exitPathVariable(YWParser::PathVariableContext *ctx) = 0;

  virtual void enterPathConstant(YWParser::PathConstantContext *ctx) = 0;
  virtual void exitPathConstant(YWParser::PathConstantContext *ctx) = 0;

  virtual void enterVariableName(YWParser::VariableNameContext *ctx) = 0;
  virtual void exitVariableName(YWParser::VariableNameContext *ctx) = 0;

  virtual void enterUriTemplate(YWParser::UriTemplateContext *ctx) = 0;
  virtual void exitUriTemplate(YWParser::UriTemplateContext *ctx) = 0;

  virtual void enterScheme(YWParser::SchemeContext *ctx) = 0;
  virtual void exitScheme(YWParser::SchemeContext *ctx) = 0;

  virtual void enterPhrase(YWParser::PhraseContext *ctx) = 0;
  virtual void exitPhrase(YWParser::PhraseContext *ctx) = 0;

  virtual void enterUnquotedPhrase(YWParser::UnquotedPhraseContext *ctx) = 0;
  virtual void exitUnquotedPhrase(YWParser::UnquotedPhraseContext *ctx) = 0;

  virtual void enterWord(YWParser::WordContext *ctx) = 0;
  virtual void exitWord(YWParser::WordContext *ctx) = 0;

  virtual void enterUnquotedWord(YWParser::UnquotedWordContext *ctx) = 0;
  virtual void exitUnquotedWord(YWParser::UnquotedWordContext *ctx) = 0;

  virtual void enterNa(YWParser::NaContext *ctx) = 0;
  virtual void exitNa(YWParser::NaContext *ctx) = 0;


};

}  // namespace yw
