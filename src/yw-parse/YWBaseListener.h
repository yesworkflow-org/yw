
// Generated from YW.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "YWListener.h"


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

  virtual void enterBlockAttribute(YWParser::BlockAttributeContext * /*ctx*/) override { }
  virtual void exitBlockAttribute(YWParser::BlockAttributeContext * /*ctx*/) override { }

  virtual void enterPort(YWParser::PortContext * /*ctx*/) override { }
  virtual void exitPort(YWParser::PortContext * /*ctx*/) override { }

  virtual void enterPortAttribute(YWParser::PortAttributeContext * /*ctx*/) override { }
  virtual void exitPortAttribute(YWParser::PortAttributeContext * /*ctx*/) override { }

  virtual void enterBeginTag(YWParser::BeginTagContext * /*ctx*/) override { }
  virtual void exitBeginTag(YWParser::BeginTagContext * /*ctx*/) override { }

  virtual void enterEndTag(YWParser::EndTagContext * /*ctx*/) override { }
  virtual void exitEndTag(YWParser::EndTagContext * /*ctx*/) override { }

  virtual void enterDescTag(YWParser::DescTagContext * /*ctx*/) override { }
  virtual void exitDescTag(YWParser::DescTagContext * /*ctx*/) override { }

  virtual void enterAliasTag(YWParser::AliasTagContext * /*ctx*/) override { }
  virtual void exitAliasTag(YWParser::AliasTagContext * /*ctx*/) override { }

  virtual void enterCallTag(YWParser::CallTagContext * /*ctx*/) override { }
  virtual void exitCallTag(YWParser::CallTagContext * /*ctx*/) override { }

  virtual void enterUriTag(YWParser::UriTagContext * /*ctx*/) override { }
  virtual void exitUriTag(YWParser::UriTagContext * /*ctx*/) override { }

  virtual void enterFileTag(YWParser::FileTagContext * /*ctx*/) override { }
  virtual void exitFileTag(YWParser::FileTagContext * /*ctx*/) override { }

  virtual void enterResourceTag(YWParser::ResourceTagContext * /*ctx*/) override { }
  virtual void exitResourceTag(YWParser::ResourceTagContext * /*ctx*/) override { }

  virtual void enterInputPortKeyword(YWParser::InputPortKeywordContext * /*ctx*/) override { }
  virtual void exitInputPortKeyword(YWParser::InputPortKeywordContext * /*ctx*/) override { }

  virtual void enterOutputPortKeyword(YWParser::OutputPortKeywordContext * /*ctx*/) override { }
  virtual void exitOutputPortKeyword(YWParser::OutputPortKeywordContext * /*ctx*/) override { }

  virtual void enterBlockName(YWParser::BlockNameContext * /*ctx*/) override { }
  virtual void exitBlockName(YWParser::BlockNameContext * /*ctx*/) override { }

  virtual void enterPortName(YWParser::PortNameContext * /*ctx*/) override { }
  virtual void exitPortName(YWParser::PortNameContext * /*ctx*/) override { }

  virtual void enterDataName(YWParser::DataNameContext * /*ctx*/) override { }
  virtual void exitDataName(YWParser::DataNameContext * /*ctx*/) override { }

  virtual void enterUriTemplate(YWParser::UriTemplateContext * /*ctx*/) override { }
  virtual void exitUriTemplate(YWParser::UriTemplateContext * /*ctx*/) override { }

  virtual void enterScheme(YWParser::SchemeContext * /*ctx*/) override { }
  virtual void exitScheme(YWParser::SchemeContext * /*ctx*/) override { }

  virtual void enterDescription(YWParser::DescriptionContext * /*ctx*/) override { }
  virtual void exitDescription(YWParser::DescriptionContext * /*ctx*/) override { }

  virtual void enterPhrase(YWParser::PhraseContext * /*ctx*/) override { }
  virtual void exitPhrase(YWParser::PhraseContext * /*ctx*/) override { }

  virtual void enterPathTemplate(YWParser::PathTemplateContext * /*ctx*/) override { }
  virtual void exitPathTemplate(YWParser::PathTemplateContext * /*ctx*/) override { }

  virtual void enterWs(YWParser::WsContext * /*ctx*/) override { }
  virtual void exitWs(YWParser::WsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

