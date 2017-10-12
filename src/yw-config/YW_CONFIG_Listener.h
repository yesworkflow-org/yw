
// Generated from YW_CONFIG_.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "YW_CONFIG_Parser.h"


namespace yw {

/**
 * This interface defines an abstract listener for a parse tree produced by YW_CONFIG_Parser.
 */
class  YW_CONFIG_Listener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterConfigFile(YW_CONFIG_Parser::ConfigFileContext *ctx) = 0;
  virtual void exitConfigFile(YW_CONFIG_Parser::ConfigFileContext *ctx) = 0;

  virtual void enterBlankLine(YW_CONFIG_Parser::BlankLineContext *ctx) = 0;
  virtual void exitBlankLine(YW_CONFIG_Parser::BlankLineContext *ctx) = 0;

  virtual void enterCommentLine(YW_CONFIG_Parser::CommentLineContext *ctx) = 0;
  virtual void exitCommentLine(YW_CONFIG_Parser::CommentLineContext *ctx) = 0;

  virtual void enterSettingLine(YW_CONFIG_Parser::SettingLineContext *ctx) = 0;
  virtual void exitSettingLine(YW_CONFIG_Parser::SettingLineContext *ctx) = 0;

  virtual void enterComment(YW_CONFIG_Parser::CommentContext *ctx) = 0;
  virtual void exitComment(YW_CONFIG_Parser::CommentContext *ctx) = 0;

  virtual void enterSetting(YW_CONFIG_Parser::SettingContext *ctx) = 0;
  virtual void exitSetting(YW_CONFIG_Parser::SettingContext *ctx) = 0;

  virtual void enterSettingName(YW_CONFIG_Parser::SettingNameContext *ctx) = 0;
  virtual void exitSettingName(YW_CONFIG_Parser::SettingNameContext *ctx) = 0;

  virtual void enterSettingValue(YW_CONFIG_Parser::SettingValueContext *ctx) = 0;
  virtual void exitSettingValue(YW_CONFIG_Parser::SettingValueContext *ctx) = 0;

  virtual void enterUnquotedValue(YW_CONFIG_Parser::UnquotedValueContext *ctx) = 0;
  virtual void exitUnquotedValue(YW_CONFIG_Parser::UnquotedValueContext *ctx) = 0;

  virtual void enterWord(YW_CONFIG_Parser::WordContext *ctx) = 0;
  virtual void exitWord(YW_CONFIG_Parser::WordContext *ctx) = 0;


};

}  // namespace yw
