
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

  virtual void enterCall(YWParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(YWParser::CallContext * /*ctx*/) override { }

  virtual void enterInputPortKeyword(YWParser::InputPortKeywordContext * /*ctx*/) override { }
  virtual void exitInputPortKeyword(YWParser::InputPortKeywordContext * /*ctx*/) override { }

  virtual void enterOutputPortKeyword(YWParser::OutputPortKeywordContext * /*ctx*/) override { }
  virtual void exitOutputPortKeyword(YWParser::OutputPortKeywordContext * /*ctx*/) override { }

  virtual void enterPortAttribute(YWParser::PortAttributeContext * /*ctx*/) override { }
  virtual void exitPortAttribute(YWParser::PortAttributeContext * /*ctx*/) override { }

  virtual void enterPortAlias(YWParser::PortAliasContext * /*ctx*/) override { }
  virtual void exitPortAlias(YWParser::PortAliasContext * /*ctx*/) override { }

  virtual void enterResourceDecl(YWParser::ResourceDeclContext * /*ctx*/) override { }
  virtual void exitResourceDecl(YWParser::ResourceDeclContext * /*ctx*/) override { }

  virtual void enterUriDecl(YWParser::UriDeclContext * /*ctx*/) override { }
  virtual void exitUriDecl(YWParser::UriDeclContext * /*ctx*/) override { }

  virtual void enterFileDecl(YWParser::FileDeclContext * /*ctx*/) override { }
  virtual void exitFileDecl(YWParser::FileDeclContext * /*ctx*/) override { }

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

  virtual void enterDataName(YWParser::DataNameContext * /*ctx*/) override { }
  virtual void exitDataName(YWParser::DataNameContext * /*ctx*/) override { }

  virtual void enterUriTemplate(YWParser::UriTemplateContext * /*ctx*/) override { }
  virtual void exitUriTemplate(YWParser::UriTemplateContext * /*ctx*/) override { }

  virtual void enterScheme(YWParser::SchemeContext * /*ctx*/) override { }
  virtual void exitScheme(YWParser::SchemeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

