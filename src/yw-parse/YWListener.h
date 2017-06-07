
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

  virtual void enterBlockQualifier(YWParser::BlockQualifierContext *ctx) = 0;
  virtual void exitBlockQualifier(YWParser::BlockQualifierContext *ctx) = 0;

  virtual void enterInputPort(YWParser::InputPortContext *ctx) = 0;
  virtual void exitInputPort(YWParser::InputPortContext *ctx) = 0;

  virtual void enterOutputPort(YWParser::OutputPortContext *ctx) = 0;
  virtual void exitOutputPort(YWParser::OutputPortContext *ctx) = 0;

  virtual void enterPortQualifier(YWParser::PortQualifierContext *ctx) = 0;
  virtual void exitPortQualifier(YWParser::PortQualifierContext *ctx) = 0;

  virtual void enterAs(YWParser::AsContext *ctx) = 0;
  virtual void exitAs(YWParser::AsContext *ctx) = 0;

  virtual void enterBegin(YWParser::BeginContext *ctx) = 0;
  virtual void exitBegin(YWParser::BeginContext *ctx) = 0;

  virtual void enterCall(YWParser::CallContext *ctx) = 0;
  virtual void exitCall(YWParser::CallContext *ctx) = 0;

  virtual void enterEnd(YWParser::EndContext *ctx) = 0;
  virtual void exitEnd(YWParser::EndContext *ctx) = 0;

  virtual void enterFile(YWParser::FileContext *ctx) = 0;
  virtual void exitFile(YWParser::FileContext *ctx) = 0;

  virtual void enterIn(YWParser::InContext *ctx) = 0;
  virtual void exitIn(YWParser::InContext *ctx) = 0;

  virtual void enterOut(YWParser::OutContext *ctx) = 0;
  virtual void exitOut(YWParser::OutContext *ctx) = 0;

  virtual void enterParam(YWParser::ParamContext *ctx) = 0;
  virtual void exitParam(YWParser::ParamContext *ctx) = 0;

  virtual void enterRet(YWParser::RetContext *ctx) = 0;
  virtual void exitRet(YWParser::RetContext *ctx) = 0;

  virtual void enterUri(YWParser::UriContext *ctx) = 0;
  virtual void exitUri(YWParser::UriContext *ctx) = 0;

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

  virtual void enterVariableName(YWParser::VariableNameContext *ctx) = 0;
  virtual void exitVariableName(YWParser::VariableNameContext *ctx) = 0;

  virtual void enterAlias(YWParser::AliasContext *ctx) = 0;
  virtual void exitAlias(YWParser::AliasContext *ctx) = 0;

  virtual void enterUriTemplate(YWParser::UriTemplateContext *ctx) = 0;
  virtual void exitUriTemplate(YWParser::UriTemplateContext *ctx) = 0;

  virtual void enterScheme(YWParser::SchemeContext *ctx) = 0;
  virtual void exitScheme(YWParser::SchemeContext *ctx) = 0;


};

