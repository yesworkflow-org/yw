
// Generated from YW_CONFIG_.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "YW_CONFIG_Listener.h"


namespace yw {

/**
 * This class provides an empty implementation of YW_CONFIG_Listener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  YW_CONFIG_BaseListener : public YW_CONFIG_Listener {
public:

  virtual void enterConfigFile(YW_CONFIG_Parser::ConfigFileContext * /*ctx*/) override { }
  virtual void exitConfigFile(YW_CONFIG_Parser::ConfigFileContext * /*ctx*/) override { }

  virtual void enterBlankLine(YW_CONFIG_Parser::BlankLineContext * /*ctx*/) override { }
  virtual void exitBlankLine(YW_CONFIG_Parser::BlankLineContext * /*ctx*/) override { }

  virtual void enterCommentLine(YW_CONFIG_Parser::CommentLineContext * /*ctx*/) override { }
  virtual void exitCommentLine(YW_CONFIG_Parser::CommentLineContext * /*ctx*/) override { }

  virtual void enterSettingLine(YW_CONFIG_Parser::SettingLineContext * /*ctx*/) override { }
  virtual void exitSettingLine(YW_CONFIG_Parser::SettingLineContext * /*ctx*/) override { }

  virtual void enterComment(YW_CONFIG_Parser::CommentContext * /*ctx*/) override { }
  virtual void exitComment(YW_CONFIG_Parser::CommentContext * /*ctx*/) override { }

  virtual void enterSetting(YW_CONFIG_Parser::SettingContext * /*ctx*/) override { }
  virtual void exitSetting(YW_CONFIG_Parser::SettingContext * /*ctx*/) override { }

  virtual void enterSettingName(YW_CONFIG_Parser::SettingNameContext * /*ctx*/) override { }
  virtual void exitSettingName(YW_CONFIG_Parser::SettingNameContext * /*ctx*/) override { }

  virtual void enterSettingValue(YW_CONFIG_Parser::SettingValueContext * /*ctx*/) override { }
  virtual void exitSettingValue(YW_CONFIG_Parser::SettingValueContext * /*ctx*/) override { }

  virtual void enterUnquotedValue(YW_CONFIG_Parser::UnquotedValueContext * /*ctx*/) override { }
  virtual void exitUnquotedValue(YW_CONFIG_Parser::UnquotedValueContext * /*ctx*/) override { }

  virtual void enterWord(YW_CONFIG_Parser::WordContext * /*ctx*/) override { }
  virtual void exitWord(YW_CONFIG_Parser::WordContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace yw
