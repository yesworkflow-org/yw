
// Generated from YW.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "YWParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by YWParser.
 */
class  YWListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterScript(YWParser::ScriptContext *ctx) = 0;
  virtual void exitScript(YWParser::ScriptContext *ctx) = 0;

  virtual void enterBlock(YWParser::BlockContext *ctx) = 0;
  virtual void exitBlock(YWParser::BlockContext *ctx) = 0;

  virtual void enterBlockAttribute(YWParser::BlockAttributeContext *ctx) = 0;
  virtual void exitBlockAttribute(YWParser::BlockAttributeContext *ctx) = 0;

  virtual void enterPort(YWParser::PortContext *ctx) = 0;
  virtual void exitPort(YWParser::PortContext *ctx) = 0;

  virtual void enterCall(YWParser::CallContext *ctx) = 0;
  virtual void exitCall(YWParser::CallContext *ctx) = 0;

  virtual void enterInputPortKeyword(YWParser::InputPortKeywordContext *ctx) = 0;
  virtual void exitInputPortKeyword(YWParser::InputPortKeywordContext *ctx) = 0;

  virtual void enterOutputPortKeyword(YWParser::OutputPortKeywordContext *ctx) = 0;
  virtual void exitOutputPortKeyword(YWParser::OutputPortKeywordContext *ctx) = 0;

  virtual void enterPortAttribute(YWParser::PortAttributeContext *ctx) = 0;
  virtual void exitPortAttribute(YWParser::PortAttributeContext *ctx) = 0;

  virtual void enterPortAlias(YWParser::PortAliasContext *ctx) = 0;
  virtual void exitPortAlias(YWParser::PortAliasContext *ctx) = 0;

  virtual void enterResourceDecl(YWParser::ResourceDeclContext *ctx) = 0;
  virtual void exitResourceDecl(YWParser::ResourceDeclContext *ctx) = 0;

  virtual void enterUriDecl(YWParser::UriDeclContext *ctx) = 0;
  virtual void exitUriDecl(YWParser::UriDeclContext *ctx) = 0;

  virtual void enterFileDecl(YWParser::FileDeclContext *ctx) = 0;
  virtual void exitFileDecl(YWParser::FileDeclContext *ctx) = 0;

  virtual void enterAsKeyword(YWParser::AsKeywordContext *ctx) = 0;
  virtual void exitAsKeyword(YWParser::AsKeywordContext *ctx) = 0;

  virtual void enterBeginKeyword(YWParser::BeginKeywordContext *ctx) = 0;
  virtual void exitBeginKeyword(YWParser::BeginKeywordContext *ctx) = 0;

  virtual void enterCallKeyword(YWParser::CallKeywordContext *ctx) = 0;
  virtual void exitCallKeyword(YWParser::CallKeywordContext *ctx) = 0;

  virtual void enterEndKeyword(YWParser::EndKeywordContext *ctx) = 0;
  virtual void exitEndKeyword(YWParser::EndKeywordContext *ctx) = 0;

  virtual void enterFileKeyword(YWParser::FileKeywordContext *ctx) = 0;
  virtual void exitFileKeyword(YWParser::FileKeywordContext *ctx) = 0;

  virtual void enterInKeyword(YWParser::InKeywordContext *ctx) = 0;
  virtual void exitInKeyword(YWParser::InKeywordContext *ctx) = 0;

  virtual void enterOutKeyword(YWParser::OutKeywordContext *ctx) = 0;
  virtual void exitOutKeyword(YWParser::OutKeywordContext *ctx) = 0;

  virtual void enterParamKeyword(YWParser::ParamKeywordContext *ctx) = 0;
  virtual void exitParamKeyword(YWParser::ParamKeywordContext *ctx) = 0;

  virtual void enterReturnKeyword(YWParser::ReturnKeywordContext *ctx) = 0;
  virtual void exitReturnKeyword(YWParser::ReturnKeywordContext *ctx) = 0;

  virtual void enterUriKeyword(YWParser::UriKeywordContext *ctx) = 0;
  virtual void exitUriKeyword(YWParser::UriKeywordContext *ctx) = 0;

  virtual void enterBlockName(YWParser::BlockNameContext *ctx) = 0;
  virtual void exitBlockName(YWParser::BlockNameContext *ctx) = 0;

  virtual void enterPortName(YWParser::PortNameContext *ctx) = 0;
  virtual void exitPortName(YWParser::PortNameContext *ctx) = 0;

  virtual void enterDataName(YWParser::DataNameContext *ctx) = 0;
  virtual void exitDataName(YWParser::DataNameContext *ctx) = 0;

  virtual void enterUriTemplate(YWParser::UriTemplateContext *ctx) = 0;
  virtual void exitUriTemplate(YWParser::UriTemplateContext *ctx) = 0;

  virtual void enterScheme(YWParser::SchemeContext *ctx) = 0;
  virtual void exitScheme(YWParser::SchemeContext *ctx) = 0;


};

