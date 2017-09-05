
// Generated from YW_CLI_.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "YW_CLI_Parser.h"


namespace yw {

/**
 * This interface defines an abstract listener for a parse tree produced by YW_CLI_Parser.
 */
class  YW_CLI_Listener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCommandLine(YW_CLI_Parser::CommandLineContext *ctx) = 0;
  virtual void exitCommandLine(YW_CLI_Parser::CommandLineContext *ctx) = 0;

  virtual void enterProgram(YW_CLI_Parser::ProgramContext *ctx) = 0;
  virtual void exitProgram(YW_CLI_Parser::ProgramContext *ctx) = 0;

  virtual void enterCommand(YW_CLI_Parser::CommandContext *ctx) = 0;
  virtual void exitCommand(YW_CLI_Parser::CommandContext *ctx) = 0;

  virtual void enterArgument(YW_CLI_Parser::ArgumentContext *ctx) = 0;
  virtual void exitArgument(YW_CLI_Parser::ArgumentContext *ctx) = 0;

  virtual void enterPflag(YW_CLI_Parser::PflagContext *ctx) = 0;
  virtual void exitPflag(YW_CLI_Parser::PflagContext *ctx) = 0;

  virtual void enterHelpflag(YW_CLI_Parser::HelpflagContext *ctx) = 0;
  virtual void exitHelpflag(YW_CLI_Parser::HelpflagContext *ctx) = 0;

  virtual void enterVersionflag(YW_CLI_Parser::VersionflagContext *ctx) = 0;
  virtual void exitVersionflag(YW_CLI_Parser::VersionflagContext *ctx) = 0;

  virtual void enterConfig(YW_CLI_Parser::ConfigContext *ctx) = 0;
  virtual void exitConfig(YW_CLI_Parser::ConfigContext *ctx) = 0;

  virtual void enterCflag(YW_CLI_Parser::CflagContext *ctx) = 0;
  virtual void exitCflag(YW_CLI_Parser::CflagContext *ctx) = 0;

  virtual void enterConfigOption(YW_CLI_Parser::ConfigOptionContext *ctx) = 0;
  virtual void exitConfigOption(YW_CLI_Parser::ConfigOptionContext *ctx) = 0;

  virtual void enterConfigAssignment(YW_CLI_Parser::ConfigAssignmentContext *ctx) = 0;
  virtual void exitConfigAssignment(YW_CLI_Parser::ConfigAssignmentContext *ctx) = 0;

  virtual void enterConfigName(YW_CLI_Parser::ConfigNameContext *ctx) = 0;
  virtual void exitConfigName(YW_CLI_Parser::ConfigNameContext *ctx) = 0;

  virtual void enterConfigValue(YW_CLI_Parser::ConfigValueContext *ctx) = 0;
  virtual void exitConfigValue(YW_CLI_Parser::ConfigValueContext *ctx) = 0;

  virtual void enterUnquotedValue(YW_CLI_Parser::UnquotedValueContext *ctx) = 0;
  virtual void exitUnquotedValue(YW_CLI_Parser::UnquotedValueContext *ctx) = 0;


};

}  // namespace yw
