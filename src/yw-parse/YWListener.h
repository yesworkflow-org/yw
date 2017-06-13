
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

  virtual void enterPortAttribute(YWParser::PortAttributeContext *ctx) = 0;
  virtual void exitPortAttribute(YWParser::PortAttributeContext *ctx) = 0;

  virtual void enterBeginTag(YWParser::BeginTagContext *ctx) = 0;
  virtual void exitBeginTag(YWParser::BeginTagContext *ctx) = 0;

  virtual void enterEndTag(YWParser::EndTagContext *ctx) = 0;
  virtual void exitEndTag(YWParser::EndTagContext *ctx) = 0;

  virtual void enterDescTag(YWParser::DescTagContext *ctx) = 0;
  virtual void exitDescTag(YWParser::DescTagContext *ctx) = 0;

  virtual void enterPortTag(YWParser::PortTagContext *ctx) = 0;
  virtual void exitPortTag(YWParser::PortTagContext *ctx) = 0;

  virtual void enterAliasTag(YWParser::AliasTagContext *ctx) = 0;
  virtual void exitAliasTag(YWParser::AliasTagContext *ctx) = 0;

  virtual void enterCallTag(YWParser::CallTagContext *ctx) = 0;
  virtual void exitCallTag(YWParser::CallTagContext *ctx) = 0;

  virtual void enterUriTag(YWParser::UriTagContext *ctx) = 0;
  virtual void exitUriTag(YWParser::UriTagContext *ctx) = 0;

  virtual void enterFileTag(YWParser::FileTagContext *ctx) = 0;
  virtual void exitFileTag(YWParser::FileTagContext *ctx) = 0;

  virtual void enterResourceTag(YWParser::ResourceTagContext *ctx) = 0;
  virtual void exitResourceTag(YWParser::ResourceTagContext *ctx) = 0;

  virtual void enterInputPortKeyword(YWParser::InputPortKeywordContext *ctx) = 0;
  virtual void exitInputPortKeyword(YWParser::InputPortKeywordContext *ctx) = 0;

  virtual void enterOutputPortKeyword(YWParser::OutputPortKeywordContext *ctx) = 0;
  virtual void exitOutputPortKeyword(YWParser::OutputPortKeywordContext *ctx) = 0;

  virtual void enterAsKeyword(YWParser::AsKeywordContext *ctx) = 0;
  virtual void exitAsKeyword(YWParser::AsKeywordContext *ctx) = 0;

  virtual void enterBeginKeyword(YWParser::BeginKeywordContext *ctx) = 0;
  virtual void exitBeginKeyword(YWParser::BeginKeywordContext *ctx) = 0;

  virtual void enterCallKeyword(YWParser::CallKeywordContext *ctx) = 0;
  virtual void exitCallKeyword(YWParser::CallKeywordContext *ctx) = 0;

  virtual void enterDescKeyword(YWParser::DescKeywordContext *ctx) = 0;
  virtual void exitDescKeyword(YWParser::DescKeywordContext *ctx) = 0;

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

  virtual void enterDescription(YWParser::DescriptionContext *ctx) = 0;
  virtual void exitDescription(YWParser::DescriptionContext *ctx) = 0;


};

