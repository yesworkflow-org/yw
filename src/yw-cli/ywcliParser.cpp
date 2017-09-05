
// Generated from ywcli.g4 by ANTLR 4.7


#include "ywcliListener.h"

#include "ywcliParser.h"


using namespace antlrcpp;
using namespace yw;
using namespace antlr4;

ywcliParser::ywcliParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ywcliParser::~ywcliParser() {
  delete _interpreter;
}

std::string ywcliParser::getGrammarFileName() const {
  return "ywcli.g4";
}

const std::vector<std::string>& ywcliParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ywcliParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CommandLineContext ------------------------------------------------------------------

ywcliParser::CommandLineContext::CommandLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ywcliParser::ProgramContext* ywcliParser::CommandLineContext::program() {
  return getRuleContext<ywcliParser::ProgramContext>(0);
}

std::vector<ywcliParser::PflagContext *> ywcliParser::CommandLineContext::pflag() {
  return getRuleContexts<ywcliParser::PflagContext>();
}

ywcliParser::PflagContext* ywcliParser::CommandLineContext::pflag(size_t i) {
  return getRuleContext<ywcliParser::PflagContext>(i);
}

ywcliParser::CommandContext* ywcliParser::CommandLineContext::command() {
  return getRuleContext<ywcliParser::CommandContext>(0);
}

std::vector<tree::TerminalNode *> ywcliParser::CommandLineContext::NEWLINE() {
  return getTokens(ywcliParser::NEWLINE);
}

tree::TerminalNode* ywcliParser::CommandLineContext::NEWLINE(size_t i) {
  return getToken(ywcliParser::NEWLINE, i);
}

std::vector<ywcliParser::ArgumentContext *> ywcliParser::CommandLineContext::argument() {
  return getRuleContexts<ywcliParser::ArgumentContext>();
}

ywcliParser::ArgumentContext* ywcliParser::CommandLineContext::argument(size_t i) {
  return getRuleContext<ywcliParser::ArgumentContext>(i);
}

std::vector<ywcliParser::ConfigContext *> ywcliParser::CommandLineContext::config() {
  return getRuleContexts<ywcliParser::ConfigContext>();
}

ywcliParser::ConfigContext* ywcliParser::CommandLineContext::config(size_t i) {
  return getRuleContext<ywcliParser::ConfigContext>(i);
}

std::vector<tree::TerminalNode *> ywcliParser::CommandLineContext::SPACE() {
  return getTokens(ywcliParser::SPACE);
}

tree::TerminalNode* ywcliParser::CommandLineContext::SPACE(size_t i) {
  return getToken(ywcliParser::SPACE, i);
}


size_t ywcliParser::CommandLineContext::getRuleIndex() const {
  return ywcliParser::RuleCommandLine;
}

void ywcliParser::CommandLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommandLine(this);
}

void ywcliParser::CommandLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommandLine(this);
}

ywcliParser::CommandLineContext* ywcliParser::commandLine() {
  CommandLineContext *_localctx = _tracker.createInstance<CommandLineContext>(_ctx, getState());
  enterRule(_localctx, 0, ywcliParser::RuleCommandLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(28);
    program();
    setState(37);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(30); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(29);
          match(ywcliParser::SPACE);
          setState(32); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == ywcliParser::SPACE);
        setState(34);
        pflag(); 
      }
      setState(39);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(46);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(41); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(40);
        match(ywcliParser::SPACE);
        setState(43); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == ywcliParser::SPACE);
      setState(45);
      command();
      break;
    }

    }
    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ywcliParser::SPACE) {
      setState(49); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(48);
        match(ywcliParser::SPACE);
        setState(51); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == ywcliParser::SPACE);
      setState(55);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
      case 1: {
        setState(53);
        argument();
        break;
      }

      case 2: {
        setState(54);
        config();
        break;
      }

      }
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(65);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ywcliParser::NEWLINE) {
      setState(62);
      match(ywcliParser::NEWLINE);
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

ywcliParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ywcliParser::ProgramContext::WORD() {
  return getToken(ywcliParser::WORD, 0);
}


size_t ywcliParser::ProgramContext::getRuleIndex() const {
  return ywcliParser::RuleProgram;
}

void ywcliParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void ywcliParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

ywcliParser::ProgramContext* ywcliParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 2, ywcliParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(ywcliParser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommandContext ------------------------------------------------------------------

ywcliParser::CommandContext::CommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ywcliParser::CommandContext::WORD() {
  return getToken(ywcliParser::WORD, 0);
}


size_t ywcliParser::CommandContext::getRuleIndex() const {
  return ywcliParser::RuleCommand;
}

void ywcliParser::CommandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommand(this);
}

void ywcliParser::CommandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommand(this);
}

ywcliParser::CommandContext* ywcliParser::command() {
  CommandContext *_localctx = _tracker.createInstance<CommandContext>(_ctx, getState());
  enterRule(_localctx, 4, ywcliParser::RuleCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(ywcliParser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

ywcliParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ywcliParser::ArgumentContext::WORD() {
  return getToken(ywcliParser::WORD, 0);
}


size_t ywcliParser::ArgumentContext::getRuleIndex() const {
  return ywcliParser::RuleArgument;
}

void ywcliParser::ArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument(this);
}

void ywcliParser::ArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument(this);
}

ywcliParser::ArgumentContext* ywcliParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 6, ywcliParser::RuleArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    match(ywcliParser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PflagContext ------------------------------------------------------------------

ywcliParser::PflagContext::PflagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ywcliParser::HelpflagContext* ywcliParser::PflagContext::helpflag() {
  return getRuleContext<ywcliParser::HelpflagContext>(0);
}

ywcliParser::VersionflagContext* ywcliParser::PflagContext::versionflag() {
  return getRuleContext<ywcliParser::VersionflagContext>(0);
}


size_t ywcliParser::PflagContext::getRuleIndex() const {
  return ywcliParser::RulePflag;
}

void ywcliParser::PflagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPflag(this);
}

void ywcliParser::PflagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPflag(this);
}

ywcliParser::PflagContext* ywcliParser::pflag() {
  PflagContext *_localctx = _tracker.createInstance<PflagContext>(_ctx, getState());
  enterRule(_localctx, 8, ywcliParser::RulePflag);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ywcliParser::T__0:
      case ywcliParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(74);
        helpflag();
        break;
      }

      case ywcliParser::T__2:
      case ywcliParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(75);
        versionflag();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HelpflagContext ------------------------------------------------------------------

ywcliParser::HelpflagContext::HelpflagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ywcliParser::HelpflagContext::getRuleIndex() const {
  return ywcliParser::RuleHelpflag;
}

void ywcliParser::HelpflagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHelpflag(this);
}

void ywcliParser::HelpflagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHelpflag(this);
}

ywcliParser::HelpflagContext* ywcliParser::helpflag() {
  HelpflagContext *_localctx = _tracker.createInstance<HelpflagContext>(_ctx, getState());
  enterRule(_localctx, 10, ywcliParser::RuleHelpflag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    _la = _input->LA(1);
    if (!(_la == ywcliParser::T__0

    || _la == ywcliParser::T__1)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VersionflagContext ------------------------------------------------------------------

ywcliParser::VersionflagContext::VersionflagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ywcliParser::VersionflagContext::getRuleIndex() const {
  return ywcliParser::RuleVersionflag;
}

void ywcliParser::VersionflagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVersionflag(this);
}

void ywcliParser::VersionflagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVersionflag(this);
}

ywcliParser::VersionflagContext* ywcliParser::versionflag() {
  VersionflagContext *_localctx = _tracker.createInstance<VersionflagContext>(_ctx, getState());
  enterRule(_localctx, 12, ywcliParser::RuleVersionflag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    _la = _input->LA(1);
    if (!(_la == ywcliParser::T__2

    || _la == ywcliParser::T__3)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConfigContext ------------------------------------------------------------------

ywcliParser::ConfigContext::ConfigContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ywcliParser::CflagContext* ywcliParser::ConfigContext::cflag() {
  return getRuleContext<ywcliParser::CflagContext>(0);
}

ywcliParser::ConfigOptionContext* ywcliParser::ConfigContext::configOption() {
  return getRuleContext<ywcliParser::ConfigOptionContext>(0);
}

ywcliParser::ConfigAssignmentContext* ywcliParser::ConfigContext::configAssignment() {
  return getRuleContext<ywcliParser::ConfigAssignmentContext>(0);
}

std::vector<tree::TerminalNode *> ywcliParser::ConfigContext::SPACE() {
  return getTokens(ywcliParser::SPACE);
}

tree::TerminalNode* ywcliParser::ConfigContext::SPACE(size_t i) {
  return getToken(ywcliParser::SPACE, i);
}


size_t ywcliParser::ConfigContext::getRuleIndex() const {
  return ywcliParser::RuleConfig;
}

void ywcliParser::ConfigContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfig(this);
}

void ywcliParser::ConfigContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfig(this);
}

ywcliParser::ConfigContext* ywcliParser::config() {
  ConfigContext *_localctx = _tracker.createInstance<ConfigContext>(_ctx, getState());
  enterRule(_localctx, 14, ywcliParser::RuleConfig);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ywcliParser::T__4:
      case ywcliParser::T__5:
      case ywcliParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(82);
        cflag();

        setState(84); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(83);
          match(ywcliParser::SPACE);
          setState(86); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == ywcliParser::SPACE);
        setState(90);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          setState(88);
          configOption();
          break;
        }

        case 2: {
          setState(89);
          configAssignment();
          break;
        }

        }
        break;
      }

      case ywcliParser::WORD: {
        enterOuterAlt(_localctx, 2);
        setState(92);
        configAssignment();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CflagContext ------------------------------------------------------------------

ywcliParser::CflagContext::CflagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ywcliParser::CflagContext::getRuleIndex() const {
  return ywcliParser::RuleCflag;
}

void ywcliParser::CflagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCflag(this);
}

void ywcliParser::CflagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCflag(this);
}

ywcliParser::CflagContext* ywcliParser::cflag() {
  CflagContext *_localctx = _tracker.createInstance<CflagContext>(_ctx, getState());
  enterRule(_localctx, 16, ywcliParser::RuleCflag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ywcliParser::T__4)
      | (1ULL << ywcliParser::T__5)
      | (1ULL << ywcliParser::T__6))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConfigOptionContext ------------------------------------------------------------------

ywcliParser::ConfigOptionContext::ConfigOptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ywcliParser::ConfigNameContext* ywcliParser::ConfigOptionContext::configName() {
  return getRuleContext<ywcliParser::ConfigNameContext>(0);
}


size_t ywcliParser::ConfigOptionContext::getRuleIndex() const {
  return ywcliParser::RuleConfigOption;
}

void ywcliParser::ConfigOptionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfigOption(this);
}

void ywcliParser::ConfigOptionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfigOption(this);
}

ywcliParser::ConfigOptionContext* ywcliParser::configOption() {
  ConfigOptionContext *_localctx = _tracker.createInstance<ConfigOptionContext>(_ctx, getState());
  enterRule(_localctx, 18, ywcliParser::RuleConfigOption);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    configName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConfigAssignmentContext ------------------------------------------------------------------

ywcliParser::ConfigAssignmentContext::ConfigAssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ywcliParser::ConfigNameContext* ywcliParser::ConfigAssignmentContext::configName() {
  return getRuleContext<ywcliParser::ConfigNameContext>(0);
}

ywcliParser::ConfigValueContext* ywcliParser::ConfigAssignmentContext::configValue() {
  return getRuleContext<ywcliParser::ConfigValueContext>(0);
}


size_t ywcliParser::ConfigAssignmentContext::getRuleIndex() const {
  return ywcliParser::RuleConfigAssignment;
}

void ywcliParser::ConfigAssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfigAssignment(this);
}

void ywcliParser::ConfigAssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfigAssignment(this);
}

ywcliParser::ConfigAssignmentContext* ywcliParser::configAssignment() {
  ConfigAssignmentContext *_localctx = _tracker.createInstance<ConfigAssignmentContext>(_ctx, getState());
  enterRule(_localctx, 20, ywcliParser::RuleConfigAssignment);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    configName();
    setState(100);
    match(ywcliParser::T__7);
    setState(101);
    configValue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConfigNameContext ------------------------------------------------------------------

ywcliParser::ConfigNameContext::ConfigNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ywcliParser::ConfigNameContext::WORD() {
  return getToken(ywcliParser::WORD, 0);
}


size_t ywcliParser::ConfigNameContext::getRuleIndex() const {
  return ywcliParser::RuleConfigName;
}

void ywcliParser::ConfigNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfigName(this);
}

void ywcliParser::ConfigNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfigName(this);
}

ywcliParser::ConfigNameContext* ywcliParser::configName() {
  ConfigNameContext *_localctx = _tracker.createInstance<ConfigNameContext>(_ctx, getState());
  enterRule(_localctx, 22, ywcliParser::RuleConfigName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(ywcliParser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConfigValueContext ------------------------------------------------------------------

ywcliParser::ConfigValueContext::ConfigValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ywcliParser::UnquotedValueContext* ywcliParser::ConfigValueContext::unquotedValue() {
  return getRuleContext<ywcliParser::UnquotedValueContext>(0);
}

std::vector<tree::TerminalNode *> ywcliParser::ConfigValueContext::SQ() {
  return getTokens(ywcliParser::SQ);
}

tree::TerminalNode* ywcliParser::ConfigValueContext::SQ(size_t i) {
  return getToken(ywcliParser::SQ, i);
}

std::vector<tree::TerminalNode *> ywcliParser::ConfigValueContext::DQ() {
  return getTokens(ywcliParser::DQ);
}

tree::TerminalNode* ywcliParser::ConfigValueContext::DQ(size_t i) {
  return getToken(ywcliParser::DQ, i);
}


size_t ywcliParser::ConfigValueContext::getRuleIndex() const {
  return ywcliParser::RuleConfigValue;
}

void ywcliParser::ConfigValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfigValue(this);
}

void ywcliParser::ConfigValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfigValue(this);
}

ywcliParser::ConfigValueContext* ywcliParser::configValue() {
  ConfigValueContext *_localctx = _tracker.createInstance<ConfigValueContext>(_ctx, getState());
  enterRule(_localctx, 24, ywcliParser::RuleConfigValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(114);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ywcliParser::WORD: {
        enterOuterAlt(_localctx, 1);
        setState(105);
        unquotedValue();
        break;
      }

      case ywcliParser::SQ: {
        enterOuterAlt(_localctx, 2);
        setState(106);
        match(ywcliParser::SQ);
        setState(107);
        unquotedValue();
        setState(108);
        match(ywcliParser::SQ);
        break;
      }

      case ywcliParser::DQ: {
        enterOuterAlt(_localctx, 3);
        setState(110);
        match(ywcliParser::DQ);
        setState(111);
        unquotedValue();
        setState(112);
        match(ywcliParser::DQ);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnquotedValueContext ------------------------------------------------------------------

ywcliParser::UnquotedValueContext::UnquotedValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ywcliParser::UnquotedValueContext::WORD() {
  return getTokens(ywcliParser::WORD);
}

tree::TerminalNode* ywcliParser::UnquotedValueContext::WORD(size_t i) {
  return getToken(ywcliParser::WORD, i);
}

std::vector<tree::TerminalNode *> ywcliParser::UnquotedValueContext::SPACE() {
  return getTokens(ywcliParser::SPACE);
}

tree::TerminalNode* ywcliParser::UnquotedValueContext::SPACE(size_t i) {
  return getToken(ywcliParser::SPACE, i);
}


size_t ywcliParser::UnquotedValueContext::getRuleIndex() const {
  return ywcliParser::RuleUnquotedValue;
}

void ywcliParser::UnquotedValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnquotedValue(this);
}

void ywcliParser::UnquotedValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ywcliListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnquotedValue(this);
}

ywcliParser::UnquotedValueContext* ywcliParser::unquotedValue() {
  UnquotedValueContext *_localctx = _tracker.createInstance<UnquotedValueContext>(_ctx, getState());
  enterRule(_localctx, 26, ywcliParser::RuleUnquotedValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(129);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(116);
      match(ywcliParser::WORD);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(117);
      match(ywcliParser::WORD);
      setState(126);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(119); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(118);
            match(ywcliParser::SPACE);
            setState(121); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == ywcliParser::SPACE);
          setState(123);
          match(ywcliParser::WORD); 
        }
        setState(128);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ywcliParser::_decisionToDFA;
atn::PredictionContextCache ywcliParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ywcliParser::_atn;
std::vector<uint16_t> ywcliParser::_serializedATN;

std::vector<std::string> ywcliParser::_ruleNames = {
  "commandLine", "program", "command", "argument", "pflag", "helpflag", 
  "versionflag", "config", "cflag", "configOption", "configAssignment", 
  "configName", "configValue", "unquotedValue"
};

std::vector<std::string> ywcliParser::_literalNames = {
  "", "'-h'", "'--help'", "'-v'", "'--version'", "'-c'", "'-config'", "'--config'", 
  "'='", "", "", "'\"'", "'''"
};

std::vector<std::string> ywcliParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "NEWLINE", "SPACE", "DQ", "SQ", "WORD"
};

dfa::Vocabulary ywcliParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ywcliParser::_tokenNames;

ywcliParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xf, 0x86, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x21, 0xa, 0x2, 0xd, 0x2, 
    0xe, 0x2, 0x22, 0x3, 0x2, 0x7, 0x2, 0x26, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x29, 0xb, 0x2, 0x3, 0x2, 0x6, 0x2, 0x2c, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 
    0x2d, 0x3, 0x2, 0x5, 0x2, 0x31, 0xa, 0x2, 0x3, 0x2, 0x6, 0x2, 0x34, 
    0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x35, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x3a, 
    0xa, 0x2, 0x7, 0x2, 0x3c, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x3f, 0xb, 0x2, 
    0x3, 0x2, 0x7, 0x2, 0x42, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x45, 0xb, 0x2, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x4f, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x9, 0x3, 0x9, 0x6, 0x9, 0x57, 0xa, 0x9, 0xd, 0x9, 0xe, 0x9, 
    0x58, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x5d, 0xa, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0x60, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 
    0xe, 0x75, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x6, 0xf, 0x7a, 0xa, 
    0xf, 0xd, 0xf, 0xe, 0xf, 0x7b, 0x3, 0xf, 0x7, 0xf, 0x7f, 0xa, 0xf, 0xc, 
    0xf, 0xe, 0xf, 0x82, 0xb, 0xf, 0x5, 0xf, 0x84, 0xa, 0xf, 0x3, 0xf, 0x2, 
    0x2, 0x10, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x2, 0x5, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x5, 0x6, 
    0x3, 0x2, 0x7, 0x9, 0x2, 0x88, 0x2, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x46, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x48, 0x3, 0x2, 0x2, 0x2, 0x8, 0x4a, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x4e, 0x3, 0x2, 0x2, 0x2, 0xc, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x52, 0x3, 0x2, 0x2, 0x2, 0x10, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0x14, 0x63, 0x3, 0x2, 0x2, 0x2, 0x16, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x74, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x83, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x27, 0x5, 0x4, 
    0x3, 0x2, 0x1f, 0x21, 0x7, 0xc, 0x2, 0x2, 0x20, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x20, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x23, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x26, 0x5, 0xa, 0x6, 0x2, 0x25, 0x20, 0x3, 0x2, 0x2, 0x2, 0x26, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x28, 0x3, 
    0x2, 0x2, 0x2, 0x28, 0x30, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x2c, 0x7, 0xc, 0x2, 0x2, 0x2b, 0x2a, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 
    0x31, 0x5, 0x6, 0x4, 0x2, 0x30, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x31, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x32, 0x34, 0x7, 
    0xc, 0x2, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0x35, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3a, 0x5, 0x8, 0x5, 0x2, 
    0x38, 0x3a, 0x5, 0x10, 0x9, 0x2, 0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x40, 0x42, 0x7, 0xb, 0x2, 
    0x2, 0x41, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 
    0x7, 0xf, 0x2, 0x2, 0x47, 0x5, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 
    0xf, 0x2, 0x2, 0x49, 0x7, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0xf, 
    0x2, 0x2, 0x4b, 0x9, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4f, 0x5, 0xc, 0x7, 
    0x2, 0x4d, 0x4f, 0x5, 0xe, 0x8, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x50, 
    0x51, 0x9, 0x2, 0x2, 0x2, 0x51, 0xd, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 
    0x9, 0x3, 0x2, 0x2, 0x53, 0xf, 0x3, 0x2, 0x2, 0x2, 0x54, 0x56, 0x5, 
    0x12, 0xa, 0x2, 0x55, 0x57, 0x7, 0xc, 0x2, 0x2, 0x56, 0x55, 0x3, 0x2, 
    0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x5d, 0x5, 0x14, 0xb, 0x2, 0x5b, 0x5d, 0x5, 0x16, 0xc, 0x2, 0x5c, 
    0x5a, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x60, 0x5, 0x16, 0xc, 0x2, 0x5f, 0x54, 0x3, 
    0x2, 0x2, 0x2, 0x5f, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 0x11, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x62, 0x9, 0x4, 0x2, 0x2, 0x62, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x64, 0x5, 0x18, 0xd, 0x2, 0x64, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0x65, 0x66, 0x5, 0x18, 0xd, 0x2, 0x66, 0x67, 0x7, 0xa, 0x2, 0x2, 0x67, 
    0x68, 0x5, 0x1a, 0xe, 0x2, 0x68, 0x17, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 
    0x7, 0xf, 0x2, 0x2, 0x6a, 0x19, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x75, 0x5, 
    0x1c, 0xf, 0x2, 0x6c, 0x6d, 0x7, 0xe, 0x2, 0x2, 0x6d, 0x6e, 0x5, 0x1c, 
    0xf, 0x2, 0x6e, 0x6f, 0x7, 0xe, 0x2, 0x2, 0x6f, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x71, 0x7, 0xd, 0x2, 0x2, 0x71, 0x72, 0x5, 0x1c, 0xf, 0x2, 
    0x72, 0x73, 0x7, 0xd, 0x2, 0x2, 0x73, 0x75, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x74, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x74, 0x70, 
    0x3, 0x2, 0x2, 0x2, 0x75, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x76, 0x84, 0x7, 
    0xf, 0x2, 0x2, 0x77, 0x80, 0x7, 0xf, 0x2, 0x2, 0x78, 0x7a, 0x7, 0xc, 
    0x2, 0x2, 0x79, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x3, 0x2, 0x2, 0x2, 
    0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7f, 0x7, 0xf, 0x2, 0x2, 0x7e, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x82, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7e, 
    0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x83, 0x76, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x77, 0x3, 0x2, 0x2, 0x2, 0x84, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x22, 0x27, 0x2d, 0x30, 0x35, 0x39, 0x3d, 0x43, 0x4e, 0x58, 
    0x5c, 0x5f, 0x74, 0x7b, 0x80, 0x83, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ywcliParser::Initializer ywcliParser::_init;
