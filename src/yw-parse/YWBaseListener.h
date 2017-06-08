
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

  virtual void enterInputPort(YWParser::InputPortContext * /*ctx*/) override { }
  virtual void exitInputPort(YWParser::InputPortContext * /*ctx*/) override { }

  virtual void enterOutputPort(YWParser::OutputPortContext * /*ctx*/) override { }
  virtual void exitOutputPort(YWParser::OutputPortContext * /*ctx*/) override { }

  virtual void enterPortAttribute(YWParser::PortAttributeContext * /*ctx*/) override { }
  virtual void exitPortAttribute(YWParser::PortAttributeContext * /*ctx*/) override { }

  virtual void enterAs(YWParser::AsContext * /*ctx*/) override { }
  virtual void exitAs(YWParser::AsContext * /*ctx*/) override { }

  virtual void enterBegin(YWParser::BeginContext * /*ctx*/) override { }
  virtual void exitBegin(YWParser::BeginContext * /*ctx*/) override { }

  virtual void enterCall(YWParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(YWParser::CallContext * /*ctx*/) override { }

  virtual void enterEnd(YWParser::EndContext * /*ctx*/) override { }
  virtual void exitEnd(YWParser::EndContext * /*ctx*/) override { }

  virtual void enterFile(YWParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(YWParser::FileContext * /*ctx*/) override { }

  virtual void enterIn(YWParser::InContext * /*ctx*/) override { }
  virtual void exitIn(YWParser::InContext * /*ctx*/) override { }

  virtual void enterOut(YWParser::OutContext * /*ctx*/) override { }
  virtual void exitOut(YWParser::OutContext * /*ctx*/) override { }

  virtual void enterParam(YWParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(YWParser::ParamContext * /*ctx*/) override { }

  virtual void enterRet(YWParser::RetContext * /*ctx*/) override { }
  virtual void exitRet(YWParser::RetContext * /*ctx*/) override { }

  virtual void enterUri(YWParser::UriContext * /*ctx*/) override { }
  virtual void exitUri(YWParser::UriContext * /*ctx*/) override { }

  virtual void enterAsKeyword(YWParser::AsKeywordContext * /*ctx*/) override { }
  virtual void exitAsKeyword(YWParser::AsKeywordContext * /*ctx*/) override { }

  virtual void enterBeginKeyword(YWParser::BeginKeywordContext * /*ctx*/) override { }
  virtual void exitBeginKeyword(YWParser::BeginKeywordContext * /*ctx*/) override { }

  virtual void enterCallKeyword(YWParser::CallKeywordContext * /*ctx*/) override { }
  virtual void exitCallKeyword(YWParser::CallKeywordContext * /*ctx*/) override { }

  virtual void enterEndKeyword(YWParser::EndKeywordContext * /*ctx*/) override { }
  virtual void exitEndKeyword(YWParser::EndKeywordContext * /*ctx*/) override { }

  virtual void enterFileKeyword(YWParser::FileKeywordContext * /*ctx*/) override { }
  virtual void exitFileKeyword(YWParser::FileKeywordContext * /*ctx*/) override { }

  virtual void enterInKeyword(YWParser::InKeywordContext * /*ctx*/) override { }
  virtual void exitInKeyword(YWParser::InKeywordContext * /*ctx*/) override { }

  virtual void enterOutKeyword(YWParser::OutKeywordContext * /*ctx*/) override { }
  virtual void exitOutKeyword(YWParser::OutKeywordContext * /*ctx*/) override { }

  virtual void enterParamKeyword(YWParser::ParamKeywordContext * /*ctx*/) override { }
  virtual void exitParamKeyword(YWParser::ParamKeywordContext * /*ctx*/) override { }

  virtual void enterReturnKeyword(YWParser::ReturnKeywordContext * /*ctx*/) override { }
  virtual void exitReturnKeyword(YWParser::ReturnKeywordContext * /*ctx*/) override { }

  virtual void enterUriKeyword(YWParser::UriKeywordContext * /*ctx*/) override { }
  virtual void exitUriKeyword(YWParser::UriKeywordContext * /*ctx*/) override { }

  virtual void enterBlockName(YWParser::BlockNameContext * /*ctx*/) override { }
  virtual void exitBlockName(YWParser::BlockNameContext * /*ctx*/) override { }

  virtual void enterPortName(YWParser::PortNameContext * /*ctx*/) override { }
  virtual void exitPortName(YWParser::PortNameContext * /*ctx*/) override { }

  virtual void enterAlias(YWParser::AliasContext * /*ctx*/) override { }
  virtual void exitAlias(YWParser::AliasContext * /*ctx*/) override { }

  virtual void enterUriTemplate(YWParser::UriTemplateContext * /*ctx*/) override { }
  virtual void exitUriTemplate(YWParser::UriTemplateContext * /*ctx*/) override { }

  virtual void enterScheme(YWParser::SchemeContext * /*ctx*/) override { }
  virtual void exitScheme(YWParser::SchemeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

