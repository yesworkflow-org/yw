
// Generated from YW_CLI_.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "YW_CLI_Listener.h"


namespace yw {

/**
 * This class provides an empty implementation of YW_CLI_Listener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  YW_CLI_BaseListener : public YW_CLI_Listener {
public:

  virtual void enterCommandLine(YW_CLI_Parser::CommandLineContext * /*ctx*/) override { }
  virtual void exitCommandLine(YW_CLI_Parser::CommandLineContext * /*ctx*/) override { }

  virtual void enterProgram(YW_CLI_Parser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(YW_CLI_Parser::ProgramContext * /*ctx*/) override { }

  virtual void enterCommand(YW_CLI_Parser::CommandContext * /*ctx*/) override { }
  virtual void exitCommand(YW_CLI_Parser::CommandContext * /*ctx*/) override { }

  virtual void enterArgument(YW_CLI_Parser::ArgumentContext * /*ctx*/) override { }
  virtual void exitArgument(YW_CLI_Parser::ArgumentContext * /*ctx*/) override { }

  virtual void enterPflag(YW_CLI_Parser::PflagContext * /*ctx*/) override { }
  virtual void exitPflag(YW_CLI_Parser::PflagContext * /*ctx*/) override { }

  virtual void enterHelpflag(YW_CLI_Parser::HelpflagContext * /*ctx*/) override { }
  virtual void exitHelpflag(YW_CLI_Parser::HelpflagContext * /*ctx*/) override { }

  virtual void enterVersionflag(YW_CLI_Parser::VersionflagContext * /*ctx*/) override { }
  virtual void exitVersionflag(YW_CLI_Parser::VersionflagContext * /*ctx*/) override { }

  virtual void enterConfig(YW_CLI_Parser::ConfigContext * /*ctx*/) override { }
  virtual void exitConfig(YW_CLI_Parser::ConfigContext * /*ctx*/) override { }

  virtual void enterCflag(YW_CLI_Parser::CflagContext * /*ctx*/) override { }
  virtual void exitCflag(YW_CLI_Parser::CflagContext * /*ctx*/) override { }

  virtual void enterConfigOption(YW_CLI_Parser::ConfigOptionContext * /*ctx*/) override { }
  virtual void exitConfigOption(YW_CLI_Parser::ConfigOptionContext * /*ctx*/) override { }

  virtual void enterConfigAssignment(YW_CLI_Parser::ConfigAssignmentContext * /*ctx*/) override { }
  virtual void exitConfigAssignment(YW_CLI_Parser::ConfigAssignmentContext * /*ctx*/) override { }

  virtual void enterConfigName(YW_CLI_Parser::ConfigNameContext * /*ctx*/) override { }
  virtual void exitConfigName(YW_CLI_Parser::ConfigNameContext * /*ctx*/) override { }

  virtual void enterConfigValue(YW_CLI_Parser::ConfigValueContext * /*ctx*/) override { }
  virtual void exitConfigValue(YW_CLI_Parser::ConfigValueContext * /*ctx*/) override { }

  virtual void enterUnquotedValue(YW_CLI_Parser::UnquotedValueContext * /*ctx*/) override { }
  virtual void exitUnquotedValue(YW_CLI_Parser::UnquotedValueContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace yw
