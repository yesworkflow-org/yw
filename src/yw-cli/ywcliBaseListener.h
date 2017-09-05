
// Generated from ywcli.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "ywcliListener.h"


namespace yw {

/**
 * This class provides an empty implementation of ywcliListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ywcliBaseListener : public ywcliListener {
public:

  virtual void enterCommandLine(ywcliParser::CommandLineContext * /*ctx*/) override { }
  virtual void exitCommandLine(ywcliParser::CommandLineContext * /*ctx*/) override { }

  virtual void enterProgram(ywcliParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(ywcliParser::ProgramContext * /*ctx*/) override { }

  virtual void enterCommand(ywcliParser::CommandContext * /*ctx*/) override { }
  virtual void exitCommand(ywcliParser::CommandContext * /*ctx*/) override { }

  virtual void enterArgument(ywcliParser::ArgumentContext * /*ctx*/) override { }
  virtual void exitArgument(ywcliParser::ArgumentContext * /*ctx*/) override { }

  virtual void enterPflag(ywcliParser::PflagContext * /*ctx*/) override { }
  virtual void exitPflag(ywcliParser::PflagContext * /*ctx*/) override { }

  virtual void enterHelpflag(ywcliParser::HelpflagContext * /*ctx*/) override { }
  virtual void exitHelpflag(ywcliParser::HelpflagContext * /*ctx*/) override { }

  virtual void enterVersionflag(ywcliParser::VersionflagContext * /*ctx*/) override { }
  virtual void exitVersionflag(ywcliParser::VersionflagContext * /*ctx*/) override { }

  virtual void enterConfig(ywcliParser::ConfigContext * /*ctx*/) override { }
  virtual void exitConfig(ywcliParser::ConfigContext * /*ctx*/) override { }

  virtual void enterCflag(ywcliParser::CflagContext * /*ctx*/) override { }
  virtual void exitCflag(ywcliParser::CflagContext * /*ctx*/) override { }

  virtual void enterConfigOption(ywcliParser::ConfigOptionContext * /*ctx*/) override { }
  virtual void exitConfigOption(ywcliParser::ConfigOptionContext * /*ctx*/) override { }

  virtual void enterConfigAssignment(ywcliParser::ConfigAssignmentContext * /*ctx*/) override { }
  virtual void exitConfigAssignment(ywcliParser::ConfigAssignmentContext * /*ctx*/) override { }

  virtual void enterConfigName(ywcliParser::ConfigNameContext * /*ctx*/) override { }
  virtual void exitConfigName(ywcliParser::ConfigNameContext * /*ctx*/) override { }

  virtual void enterConfigValue(ywcliParser::ConfigValueContext * /*ctx*/) override { }
  virtual void exitConfigValue(ywcliParser::ConfigValueContext * /*ctx*/) override { }

  virtual void enterUnquotedValue(ywcliParser::UnquotedValueContext * /*ctx*/) override { }
  virtual void exitUnquotedValue(ywcliParser::UnquotedValueContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace yw
