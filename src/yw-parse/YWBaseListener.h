
// Generated from YW.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "YWListener.h"


namespace yw {

/**
 * This class provides an empty implementation of YWListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  YWBaseListener : public YWListener {
public:

  virtual void enterScript(YWParser::ScriptContext * /*ctx*/) override { }
  virtual void exitScript(YWParser::ScriptContext * /*ctx*/) override { }

  virtual void enterBlock(YWParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(YWParser::BlockContext * /*ctx*/) override { }

  virtual void enterNestedBlocks(YWParser::NestedBlocksContext * /*ctx*/) override { }
  virtual void exitNestedBlocks(YWParser::NestedBlocksContext * /*ctx*/) override { }

  virtual void enterBlockAttribute(YWParser::BlockAttributeContext * /*ctx*/) override { }
  virtual void exitBlockAttribute(YWParser::BlockAttributeContext * /*ctx*/) override { }

  virtual void enterIo(YWParser::IoContext * /*ctx*/) override { }
  virtual void exitIo(YWParser::IoContext * /*ctx*/) override { }

  virtual void enterPort(YWParser::PortContext * /*ctx*/) override { }
  virtual void exitPort(YWParser::PortContext * /*ctx*/) override { }

  virtual void enterPortAttribute(YWParser::PortAttributeContext * /*ctx*/) override { }
  virtual void exitPortAttribute(YWParser::PortAttributeContext * /*ctx*/) override { }

  virtual void enterAlias(YWParser::AliasContext * /*ctx*/) override { }
  virtual void exitAlias(YWParser::AliasContext * /*ctx*/) override { }

  virtual void enterBegin(YWParser::BeginContext * /*ctx*/) override { }
  virtual void exitBegin(YWParser::BeginContext * /*ctx*/) override { }

  virtual void enterBlockDesc(YWParser::BlockDescContext * /*ctx*/) override { }
  virtual void exitBlockDesc(YWParser::BlockDescContext * /*ctx*/) override { }

  virtual void enterPortDesc(YWParser::PortDescContext * /*ctx*/) override { }
  virtual void exitPortDesc(YWParser::PortDescContext * /*ctx*/) override { }

  virtual void enterEnd(YWParser::EndContext * /*ctx*/) override { }
  virtual void exitEnd(YWParser::EndContext * /*ctx*/) override { }

  virtual void enterFile(YWParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(YWParser::FileContext * /*ctx*/) override { }

  virtual void enterUri(YWParser::UriContext * /*ctx*/) override { }
  virtual void exitUri(YWParser::UriContext * /*ctx*/) override { }

  virtual void enterMisplacedEnd(YWParser::MisplacedEndContext * /*ctx*/) override { }
  virtual void exitMisplacedEnd(YWParser::MisplacedEndContext * /*ctx*/) override { }

  virtual void enterMisplacedBeginChild(YWParser::MisplacedBeginChildContext * /*ctx*/) override { }
  virtual void exitMisplacedBeginChild(YWParser::MisplacedBeginChildContext * /*ctx*/) override { }

  virtual void enterMisplacedPortChild(YWParser::MisplacedPortChildContext * /*ctx*/) override { }
  virtual void exitMisplacedPortChild(YWParser::MisplacedPortChildContext * /*ctx*/) override { }

  virtual void enterMisplacedKeyword(YWParser::MisplacedKeywordContext * /*ctx*/) override { }
  virtual void exitMisplacedKeyword(YWParser::MisplacedKeywordContext * /*ctx*/) override { }

  virtual void enterResource(YWParser::ResourceContext * /*ctx*/) override { }
  virtual void exitResource(YWParser::ResourceContext * /*ctx*/) override { }

  virtual void enterPortKeyword(YWParser::PortKeywordContext * /*ctx*/) override { }
  virtual void exitPortKeyword(YWParser::PortKeywordContext * /*ctx*/) override { }

  virtual void enterInputKeyword(YWParser::InputKeywordContext * /*ctx*/) override { }
  virtual void exitInputKeyword(YWParser::InputKeywordContext * /*ctx*/) override { }

  virtual void enterOutputKeyword(YWParser::OutputKeywordContext * /*ctx*/) override { }
  virtual void exitOutputKeyword(YWParser::OutputKeywordContext * /*ctx*/) override { }

  virtual void enterBlockName(YWParser::BlockNameContext * /*ctx*/) override { }
  virtual void exitBlockName(YWParser::BlockNameContext * /*ctx*/) override { }

  virtual void enterPortName(YWParser::PortNameContext * /*ctx*/) override { }
  virtual void exitPortName(YWParser::PortNameContext * /*ctx*/) override { }

  virtual void enterDataName(YWParser::DataNameContext * /*ctx*/) override { }
  virtual void exitDataName(YWParser::DataNameContext * /*ctx*/) override { }

  virtual void enterDescription(YWParser::DescriptionContext * /*ctx*/) override { }
  virtual void exitDescription(YWParser::DescriptionContext * /*ctx*/) override { }

  virtual void enterPathElement(YWParser::PathElementContext * /*ctx*/) override { }
  virtual void exitPathElement(YWParser::PathElementContext * /*ctx*/) override { }

  virtual void enterPathVariable(YWParser::PathVariableContext * /*ctx*/) override { }
  virtual void exitPathVariable(YWParser::PathVariableContext * /*ctx*/) override { }

  virtual void enterPathConstant(YWParser::PathConstantContext * /*ctx*/) override { }
  virtual void exitPathConstant(YWParser::PathConstantContext * /*ctx*/) override { }

  virtual void enterVariableName(YWParser::VariableNameContext * /*ctx*/) override { }
  virtual void exitVariableName(YWParser::VariableNameContext * /*ctx*/) override { }

  virtual void enterPathTemplate(YWParser::PathTemplateContext * /*ctx*/) override { }
  virtual void exitPathTemplate(YWParser::PathTemplateContext * /*ctx*/) override { }

  virtual void enterUriTemplate(YWParser::UriTemplateContext * /*ctx*/) override { }
  virtual void exitUriTemplate(YWParser::UriTemplateContext * /*ctx*/) override { }

  virtual void enterScheme(YWParser::SchemeContext * /*ctx*/) override { }
  virtual void exitScheme(YWParser::SchemeContext * /*ctx*/) override { }

  virtual void enterPhrase(YWParser::PhraseContext * /*ctx*/) override { }
  virtual void exitPhrase(YWParser::PhraseContext * /*ctx*/) override { }

  virtual void enterUnquotedPhrase(YWParser::UnquotedPhraseContext * /*ctx*/) override { }
  virtual void exitUnquotedPhrase(YWParser::UnquotedPhraseContext * /*ctx*/) override { }

  virtual void enterWord(YWParser::WordContext * /*ctx*/) override { }
  virtual void exitWord(YWParser::WordContext * /*ctx*/) override { }

  virtual void enterUnquotedWord(YWParser::UnquotedWordContext * /*ctx*/) override { }
  virtual void exitUnquotedWord(YWParser::UnquotedWordContext * /*ctx*/) override { }

  virtual void enterNa(YWParser::NaContext * /*ctx*/) override { }
  virtual void exitNa(YWParser::NaContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace yw
