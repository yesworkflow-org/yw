
// Generated from ywcli.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "ywcliParser.h"


namespace yw {

/**
 * This interface defines an abstract listener for a parse tree produced by ywcliParser.
 */
class  ywcliListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCommandLine(ywcliParser::CommandLineContext *ctx) = 0;
  virtual void exitCommandLine(ywcliParser::CommandLineContext *ctx) = 0;

  virtual void enterProgram(ywcliParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(ywcliParser::ProgramContext *ctx) = 0;

  virtual void enterCommand(ywcliParser::CommandContext *ctx) = 0;
  virtual void exitCommand(ywcliParser::CommandContext *ctx) = 0;

  virtual void enterArgument(ywcliParser::ArgumentContext *ctx) = 0;
  virtual void exitArgument(ywcliParser::ArgumentContext *ctx) = 0;

  virtual void enterPflag(ywcliParser::PflagContext *ctx) = 0;
  virtual void exitPflag(ywcliParser::PflagContext *ctx) = 0;

  virtual void enterHelpflag(ywcliParser::HelpflagContext *ctx) = 0;
  virtual void exitHelpflag(ywcliParser::HelpflagContext *ctx) = 0;

  virtual void enterVersionflag(ywcliParser::VersionflagContext *ctx) = 0;
  virtual void exitVersionflag(ywcliParser::VersionflagContext *ctx) = 0;

  virtual void enterConfig(ywcliParser::ConfigContext *ctx) = 0;
  virtual void exitConfig(ywcliParser::ConfigContext *ctx) = 0;

  virtual void enterCflag(ywcliParser::CflagContext *ctx) = 0;
  virtual void exitCflag(ywcliParser::CflagContext *ctx) = 0;

  virtual void enterConfigOption(ywcliParser::ConfigOptionContext *ctx) = 0;
  virtual void exitConfigOption(ywcliParser::ConfigOptionContext *ctx) = 0;

  virtual void enterConfigAssignment(ywcliParser::ConfigAssignmentContext *ctx) = 0;
  virtual void exitConfigAssignment(ywcliParser::ConfigAssignmentContext *ctx) = 0;

  virtual void enterConfigName(ywcliParser::ConfigNameContext *ctx) = 0;
  virtual void exitConfigName(ywcliParser::ConfigNameContext *ctx) = 0;

  virtual void enterConfigValue(ywcliParser::ConfigValueContext *ctx) = 0;
  virtual void exitConfigValue(ywcliParser::ConfigValueContext *ctx) = 0;

  virtual void enterUnquotedValue(ywcliParser::UnquotedValueContext *ctx) = 0;
  virtual void exitUnquotedValue(ywcliParser::UnquotedValueContext *ctx) = 0;


};

}  // namespace yw
