
// Generated from YW_CLI_.g4 by ANTLR 4.7


#include "YW_CLI_Listener.h"

#include "YW_CLI_Parser.h"


using namespace antlrcpp;
using namespace yw;
using namespace antlr4;

YW_CLI_Parser::YW_CLI_Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

YW_CLI_Parser::~YW_CLI_Parser() {
  delete _interpreter;
}

std::string YW_CLI_Parser::getGrammarFileName() const {
  return "YW_CLI_.g4";
}

const std::vector<std::string>& YW_CLI_Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& YW_CLI_Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CommandLineContext ------------------------------------------------------------------

YW_CLI_Parser::CommandLineContext::CommandLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YW_CLI_Parser::ProgramContext* YW_CLI_Parser::CommandLineContext::program() {
  return getRuleContext<YW_CLI_Parser::ProgramContext>(0);
}

std::vector<YW_CLI_Parser::PflagContext *> YW_CLI_Parser::CommandLineContext::pflag() {
  return getRuleContexts<YW_CLI_Parser::PflagContext>();
}

YW_CLI_Parser::PflagContext* YW_CLI_Parser::CommandLineContext::pflag(size_t i) {
  return getRuleContext<YW_CLI_Parser::PflagContext>(i);
}

YW_CLI_Parser::CommandContext* YW_CLI_Parser::CommandLineContext::command() {
  return getRuleContext<YW_CLI_Parser::CommandContext>(0);
}

std::vector<tree::TerminalNode *> YW_CLI_Parser::CommandLineContext::NEWLINE() {
  return getTokens(YW_CLI_Parser::NEWLINE);
}

tree::TerminalNode* YW_CLI_Parser::CommandLineContext::NEWLINE(size_t i) {
  return getToken(YW_CLI_Parser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> YW_CLI_Parser::CommandLineContext::SPACE() {
  return getTokens(YW_CLI_Parser::SPACE);
}

tree::TerminalNode* YW_CLI_Parser::CommandLineContext::SPACE(size_t i) {
  return getToken(YW_CLI_Parser::SPACE, i);
}

std::vector<YW_CLI_Parser::ArgumentContext *> YW_CLI_Parser::CommandLineContext::argument() {
  return getRuleContexts<YW_CLI_Parser::ArgumentContext>();
}

YW_CLI_Parser::ArgumentContext* YW_CLI_Parser::CommandLineContext::argument(size_t i) {
  return getRuleContext<YW_CLI_Parser::ArgumentContext>(i);
}

std::vector<YW_CLI_Parser::ConfigContext *> YW_CLI_Parser::CommandLineContext::config() {
  return getRuleContexts<YW_CLI_Parser::ConfigContext>();
}

YW_CLI_Parser::ConfigContext* YW_CLI_Parser::CommandLineContext::config(size_t i) {
  return getRuleContext<YW_CLI_Parser::ConfigContext>(i);
}


size_t YW_CLI_Parser::CommandLineContext::getRuleIndex() const {
  return YW_CLI_Parser::RuleCommandLine;
}

void YW_CLI_Parser::CommandLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommandLine(this);
}

void YW_CLI_Parser::CommandLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommandLine(this);
}

YW_CLI_Parser::CommandLineContext* YW_CLI_Parser::commandLine() {
  CommandLineContext *_localctx = _tracker.createInstance<CommandLineContext>(_ctx, getState());
  enterRule(_localctx, 0, YW_CLI_Parser::RuleCommandLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(24);
    program();
    setState(33);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(26); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(25);
          match(YW_CLI_Parser::SPACE);
          setState(28); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == YW_CLI_Parser::SPACE);
        setState(30);
        pflag(); 
      }
      setState(35);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(56);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YW_CLI_Parser::SPACE) {
      setState(37); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(36);
        match(YW_CLI_Parser::SPACE);
        setState(39); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == YW_CLI_Parser::SPACE);
      setState(41);
      command();
      setState(53);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == YW_CLI_Parser::SPACE) {
        setState(43); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(42);
          match(YW_CLI_Parser::SPACE);
          setState(45); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == YW_CLI_Parser::SPACE);
        setState(49);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
        case 1: {
          setState(47);
          argument();
          break;
        }

        case 2: {
          setState(48);
          config();
          break;
        }

        }
        setState(55);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(61);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YW_CLI_Parser::NEWLINE) {
      setState(58);
      match(YW_CLI_Parser::NEWLINE);
      setState(63);
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

YW_CLI_Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YW_CLI_Parser::ProgramContext::WORD() {
  return getToken(YW_CLI_Parser::WORD, 0);
}


size_t YW_CLI_Parser::ProgramContext::getRuleIndex() const {
  return YW_CLI_Parser::RuleProgram;
}

void YW_CLI_Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void YW_CLI_Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

YW_CLI_Parser::ProgramContext* YW_CLI_Parser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 2, YW_CLI_Parser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(64);
    match(YW_CLI_Parser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommandContext ------------------------------------------------------------------

YW_CLI_Parser::CommandContext::CommandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YW_CLI_Parser::CommandContext::WORD() {
  return getToken(YW_CLI_Parser::WORD, 0);
}


size_t YW_CLI_Parser::CommandContext::getRuleIndex() const {
  return YW_CLI_Parser::RuleCommand;
}

void YW_CLI_Parser::CommandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommand(this);
}

void YW_CLI_Parser::CommandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommand(this);
}

YW_CLI_Parser::CommandContext* YW_CLI_Parser::command() {
  CommandContext *_localctx = _tracker.createInstance<CommandContext>(_ctx, getState());
  enterRule(_localctx, 4, YW_CLI_Parser::RuleCommand);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    match(YW_CLI_Parser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

YW_CLI_Parser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YW_CLI_Parser::ArgumentContext::WORD() {
  return getToken(YW_CLI_Parser::WORD, 0);
}


size_t YW_CLI_Parser::ArgumentContext::getRuleIndex() const {
  return YW_CLI_Parser::RuleArgument;
}

void YW_CLI_Parser::ArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument(this);
}

void YW_CLI_Parser::ArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument(this);
}

YW_CLI_Parser::ArgumentContext* YW_CLI_Parser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 6, YW_CLI_Parser::RuleArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(YW_CLI_Parser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PflagContext ------------------------------------------------------------------

YW_CLI_Parser::PflagContext::PflagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YW_CLI_Parser::HelpflagContext* YW_CLI_Parser::PflagContext::helpflag() {
  return getRuleContext<YW_CLI_Parser::HelpflagContext>(0);
}

YW_CLI_Parser::VersionflagContext* YW_CLI_Parser::PflagContext::versionflag() {
  return getRuleContext<YW_CLI_Parser::VersionflagContext>(0);
}


size_t YW_CLI_Parser::PflagContext::getRuleIndex() const {
  return YW_CLI_Parser::RulePflag;
}

void YW_CLI_Parser::PflagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPflag(this);
}

void YW_CLI_Parser::PflagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPflag(this);
}

YW_CLI_Parser::PflagContext* YW_CLI_Parser::pflag() {
  PflagContext *_localctx = _tracker.createInstance<PflagContext>(_ctx, getState());
  enterRule(_localctx, 8, YW_CLI_Parser::RulePflag);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(72);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YW_CLI_Parser::T__0:
      case YW_CLI_Parser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(70);
        helpflag();
        break;
      }

      case YW_CLI_Parser::T__2:
      case YW_CLI_Parser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(71);
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

YW_CLI_Parser::HelpflagContext::HelpflagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YW_CLI_Parser::HelpflagContext::getRuleIndex() const {
  return YW_CLI_Parser::RuleHelpflag;
}

void YW_CLI_Parser::HelpflagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHelpflag(this);
}

void YW_CLI_Parser::HelpflagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHelpflag(this);
}

YW_CLI_Parser::HelpflagContext* YW_CLI_Parser::helpflag() {
  HelpflagContext *_localctx = _tracker.createInstance<HelpflagContext>(_ctx, getState());
  enterRule(_localctx, 10, YW_CLI_Parser::RuleHelpflag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(74);
    _la = _input->LA(1);
    if (!(_la == YW_CLI_Parser::T__0

    || _la == YW_CLI_Parser::T__1)) {
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

YW_CLI_Parser::VersionflagContext::VersionflagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YW_CLI_Parser::VersionflagContext::getRuleIndex() const {
  return YW_CLI_Parser::RuleVersionflag;
}

void YW_CLI_Parser::VersionflagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVersionflag(this);
}

void YW_CLI_Parser::VersionflagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVersionflag(this);
}

YW_CLI_Parser::VersionflagContext* YW_CLI_Parser::versionflag() {
  VersionflagContext *_localctx = _tracker.createInstance<VersionflagContext>(_ctx, getState());
  enterRule(_localctx, 12, YW_CLI_Parser::RuleVersionflag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(76);
    _la = _input->LA(1);
    if (!(_la == YW_CLI_Parser::T__2

    || _la == YW_CLI_Parser::T__3)) {
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

YW_CLI_Parser::ConfigContext::ConfigContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YW_CLI_Parser::CflagContext* YW_CLI_Parser::ConfigContext::cflag() {
  return getRuleContext<YW_CLI_Parser::CflagContext>(0);
}

YW_CLI_Parser::ConfigNameContext* YW_CLI_Parser::ConfigContext::configName() {
  return getRuleContext<YW_CLI_Parser::ConfigNameContext>(0);
}

std::vector<tree::TerminalNode *> YW_CLI_Parser::ConfigContext::SPACE() {
  return getTokens(YW_CLI_Parser::SPACE);
}

tree::TerminalNode* YW_CLI_Parser::ConfigContext::SPACE(size_t i) {
  return getToken(YW_CLI_Parser::SPACE, i);
}

YW_CLI_Parser::ConfigValueContext* YW_CLI_Parser::ConfigContext::configValue() {
  return getRuleContext<YW_CLI_Parser::ConfigValueContext>(0);
}


size_t YW_CLI_Parser::ConfigContext::getRuleIndex() const {
  return YW_CLI_Parser::RuleConfig;
}

void YW_CLI_Parser::ConfigContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfig(this);
}

void YW_CLI_Parser::ConfigContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfig(this);
}

YW_CLI_Parser::ConfigContext* YW_CLI_Parser::config() {
  ConfigContext *_localctx = _tracker.createInstance<ConfigContext>(_ctx, getState());
  enterRule(_localctx, 14, YW_CLI_Parser::RuleConfig);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(93);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YW_CLI_Parser::T__5:
      case YW_CLI_Parser::T__6:
      case YW_CLI_Parser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(78);
        cflag();

        setState(80); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(79);
          match(YW_CLI_Parser::SPACE);
          setState(82); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == YW_CLI_Parser::SPACE);

        setState(84);
        configName();
        setState(87);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == YW_CLI_Parser::T__4) {
          setState(85);
          match(YW_CLI_Parser::T__4);
          setState(86);
          configValue();
        }
        break;
      }

      case YW_CLI_Parser::WORD: {
        enterOuterAlt(_localctx, 2);
        setState(89);
        configName();
        setState(90);
        match(YW_CLI_Parser::T__4);
        setState(91);
        configValue();
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

YW_CLI_Parser::CflagContext::CflagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YW_CLI_Parser::CflagContext::getRuleIndex() const {
  return YW_CLI_Parser::RuleCflag;
}

void YW_CLI_Parser::CflagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCflag(this);
}

void YW_CLI_Parser::CflagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCflag(this);
}

YW_CLI_Parser::CflagContext* YW_CLI_Parser::cflag() {
  CflagContext *_localctx = _tracker.createInstance<CflagContext>(_ctx, getState());
  enterRule(_localctx, 16, YW_CLI_Parser::RuleCflag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YW_CLI_Parser::T__5)
      | (1ULL << YW_CLI_Parser::T__6)
      | (1ULL << YW_CLI_Parser::T__7))) != 0))) {
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

//----------------- ConfigNameContext ------------------------------------------------------------------

YW_CLI_Parser::ConfigNameContext::ConfigNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YW_CLI_Parser::ConfigNameContext::WORD() {
  return getToken(YW_CLI_Parser::WORD, 0);
}


size_t YW_CLI_Parser::ConfigNameContext::getRuleIndex() const {
  return YW_CLI_Parser::RuleConfigName;
}

void YW_CLI_Parser::ConfigNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfigName(this);
}

void YW_CLI_Parser::ConfigNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfigName(this);
}

YW_CLI_Parser::ConfigNameContext* YW_CLI_Parser::configName() {
  ConfigNameContext *_localctx = _tracker.createInstance<ConfigNameContext>(_ctx, getState());
  enterRule(_localctx, 18, YW_CLI_Parser::RuleConfigName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(YW_CLI_Parser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConfigValueContext ------------------------------------------------------------------

YW_CLI_Parser::ConfigValueContext::ConfigValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YW_CLI_Parser::UnquotedValueContext* YW_CLI_Parser::ConfigValueContext::unquotedValue() {
  return getRuleContext<YW_CLI_Parser::UnquotedValueContext>(0);
}

std::vector<tree::TerminalNode *> YW_CLI_Parser::ConfigValueContext::SQ() {
  return getTokens(YW_CLI_Parser::SQ);
}

tree::TerminalNode* YW_CLI_Parser::ConfigValueContext::SQ(size_t i) {
  return getToken(YW_CLI_Parser::SQ, i);
}

std::vector<tree::TerminalNode *> YW_CLI_Parser::ConfigValueContext::DQ() {
  return getTokens(YW_CLI_Parser::DQ);
}

tree::TerminalNode* YW_CLI_Parser::ConfigValueContext::DQ(size_t i) {
  return getToken(YW_CLI_Parser::DQ, i);
}


size_t YW_CLI_Parser::ConfigValueContext::getRuleIndex() const {
  return YW_CLI_Parser::RuleConfigValue;
}

void YW_CLI_Parser::ConfigValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfigValue(this);
}

void YW_CLI_Parser::ConfigValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfigValue(this);
}

YW_CLI_Parser::ConfigValueContext* YW_CLI_Parser::configValue() {
  ConfigValueContext *_localctx = _tracker.createInstance<ConfigValueContext>(_ctx, getState());
  enterRule(_localctx, 20, YW_CLI_Parser::RuleConfigValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(108);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YW_CLI_Parser::WORD: {
        enterOuterAlt(_localctx, 1);
        setState(99);
        unquotedValue();
        break;
      }

      case YW_CLI_Parser::SQ: {
        enterOuterAlt(_localctx, 2);
        setState(100);
        match(YW_CLI_Parser::SQ);
        setState(101);
        unquotedValue();
        setState(102);
        match(YW_CLI_Parser::SQ);
        break;
      }

      case YW_CLI_Parser::DQ: {
        enterOuterAlt(_localctx, 3);
        setState(104);
        match(YW_CLI_Parser::DQ);
        setState(105);
        unquotedValue();
        setState(106);
        match(YW_CLI_Parser::DQ);
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

YW_CLI_Parser::UnquotedValueContext::UnquotedValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> YW_CLI_Parser::UnquotedValueContext::WORD() {
  return getTokens(YW_CLI_Parser::WORD);
}

tree::TerminalNode* YW_CLI_Parser::UnquotedValueContext::WORD(size_t i) {
  return getToken(YW_CLI_Parser::WORD, i);
}

std::vector<tree::TerminalNode *> YW_CLI_Parser::UnquotedValueContext::SPACE() {
  return getTokens(YW_CLI_Parser::SPACE);
}

tree::TerminalNode* YW_CLI_Parser::UnquotedValueContext::SPACE(size_t i) {
  return getToken(YW_CLI_Parser::SPACE, i);
}


size_t YW_CLI_Parser::UnquotedValueContext::getRuleIndex() const {
  return YW_CLI_Parser::RuleUnquotedValue;
}

void YW_CLI_Parser::UnquotedValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnquotedValue(this);
}

void YW_CLI_Parser::UnquotedValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CLI_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnquotedValue(this);
}

YW_CLI_Parser::UnquotedValueContext* YW_CLI_Parser::unquotedValue() {
  UnquotedValueContext *_localctx = _tracker.createInstance<UnquotedValueContext>(_ctx, getState());
  enterRule(_localctx, 22, YW_CLI_Parser::RuleUnquotedValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(123);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(110);
      match(YW_CLI_Parser::WORD);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(111);
      match(YW_CLI_Parser::WORD);
      setState(120);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(113); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(112);
            match(YW_CLI_Parser::SPACE);
            setState(115); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == YW_CLI_Parser::SPACE);
          setState(117);
          match(YW_CLI_Parser::WORD); 
        }
        setState(122);
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
std::vector<dfa::DFA> YW_CLI_Parser::_decisionToDFA;
atn::PredictionContextCache YW_CLI_Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN YW_CLI_Parser::_atn;
std::vector<uint16_t> YW_CLI_Parser::_serializedATN;

std::vector<std::string> YW_CLI_Parser::_ruleNames = {
  "commandLine", "program", "command", "argument", "pflag", "helpflag", 
  "versionflag", "config", "cflag", "configName", "configValue", "unquotedValue"
};

std::vector<std::string> YW_CLI_Parser::_literalNames = {
  "", "'-h'", "'--help'", "'-v'", "'--version'", "'='", "'-c'", "'-config'", 
  "'--config'", "", "", "'\"'", "'''"
};

std::vector<std::string> YW_CLI_Parser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "NEWLINE", "SPACE", "DQ", "SQ", "WORD"
};

dfa::Vocabulary YW_CLI_Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> YW_CLI_Parser::_tokenNames;

YW_CLI_Parser::Initializer::Initializer() {
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
    0x3, 0xf, 0x80, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x3, 0x2, 0x3, 0x2, 0x6, 
    0x2, 0x1d, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x1e, 0x3, 0x2, 0x7, 0x2, 0x22, 
    0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x25, 0xb, 0x2, 0x3, 0x2, 0x6, 0x2, 0x28, 
    0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x29, 0x3, 0x2, 0x3, 0x2, 0x6, 0x2, 0x2e, 
    0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x2f, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x34, 
    0xa, 0x2, 0x7, 0x2, 0x36, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x39, 0xb, 0x2, 
    0x5, 0x2, 0x3b, 0xa, 0x2, 0x3, 0x2, 0x7, 0x2, 0x3e, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x41, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x4b, 0xa, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x6, 0x9, 0x53, 0xa, 
    0x9, 0xd, 0x9, 0xe, 0x9, 0x54, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 
    0x5a, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x60, 
    0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0x6f, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x6, 0xd, 0x74, 
    0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0x75, 0x3, 0xd, 0x7, 0xd, 0x79, 0xa, 0xd, 
    0xc, 0xd, 0xe, 0xd, 0x7c, 0xb, 0xd, 0x5, 0xd, 0x7e, 0xa, 0xd, 0x3, 0xd, 
    0x2, 0x2, 0xe, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x2, 0x5, 0x3, 0x2, 0x3, 0x4, 0x3, 0x2, 0x5, 0x6, 0x3, 0x2, 
    0x8, 0xa, 0x2, 0x84, 0x2, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x4, 0x42, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x44, 0x3, 0x2, 0x2, 0x2, 0x8, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x4a, 0x3, 0x2, 0x2, 0x2, 0xc, 0x4c, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x12, 0x61, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x63, 0x3, 0x2, 0x2, 0x2, 0x16, 0x6e, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x23, 0x5, 0x4, 
    0x3, 0x2, 0x1b, 0x1d, 0x7, 0xc, 0x2, 0x2, 0x1c, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x1d, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x22, 0x5, 0xa, 0x6, 0x2, 0x21, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x22, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 0x24, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x26, 0x28, 0x7, 0xc, 0x2, 0x2, 0x27, 0x26, 0x3, 0x2, 0x2, 
    0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x29, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x37, 0x5, 0x6, 0x4, 0x2, 0x2c, 0x2e, 0x7, 0xc, 0x2, 0x2, 0x2d, 0x2c, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x2f, 0x30, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x31, 0x34, 0x5, 0x8, 0x5, 0x2, 0x32, 0x34, 0x5, 0x10, 0x9, 
    0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x32, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x39, 0x3, 0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 
    0x3, 0x2, 0x2, 0x2, 0x38, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x39, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x27, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0x3b, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3e, 0x7, 0xb, 0x2, 
    0x2, 0x3d, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 
    0x7, 0xf, 0x2, 0x2, 0x43, 0x5, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 
    0xf, 0x2, 0x2, 0x45, 0x7, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0xf, 
    0x2, 0x2, 0x47, 0x9, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4b, 0x5, 0xc, 0x7, 
    0x2, 0x49, 0x4b, 0x5, 0xe, 0x8, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4c, 
    0x4d, 0x9, 0x2, 0x2, 0x2, 0x4d, 0xd, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 
    0x9, 0x3, 0x2, 0x2, 0x4f, 0xf, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 0x5, 
    0x12, 0xa, 0x2, 0x51, 0x53, 0x7, 0xc, 0x2, 0x2, 0x52, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x59, 0x5, 0x14, 0xb, 0x2, 0x57, 0x58, 0x7, 0x7, 0x2, 0x2, 0x58, 
    0x5a, 0x5, 0x16, 0xc, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x60, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x5, 
    0x14, 0xb, 0x2, 0x5c, 0x5d, 0x7, 0x7, 0x2, 0x2, 0x5d, 0x5e, 0x5, 0x16, 
    0xc, 0x2, 0x5e, 0x60, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x60, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x61, 0x62, 0x9, 0x4, 0x2, 0x2, 0x62, 0x13, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x64, 0x7, 0xf, 0x2, 0x2, 0x64, 0x15, 0x3, 0x2, 0x2, 0x2, 0x65, 0x6f, 
    0x5, 0x18, 0xd, 0x2, 0x66, 0x67, 0x7, 0xe, 0x2, 0x2, 0x67, 0x68, 0x5, 
    0x18, 0xd, 0x2, 0x68, 0x69, 0x7, 0xe, 0x2, 0x2, 0x69, 0x6f, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x6b, 0x7, 0xd, 0x2, 0x2, 0x6b, 0x6c, 0x5, 0x18, 0xd, 
    0x2, 0x6c, 0x6d, 0x7, 0xd, 0x2, 0x2, 0x6d, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x65, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x66, 0x3, 0x2, 0x2, 0x2, 0x6e, 
    0x6a, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x17, 0x3, 0x2, 0x2, 0x2, 0x70, 0x7e, 
    0x7, 0xf, 0x2, 0x2, 0x71, 0x7a, 0x7, 0xf, 0x2, 0x2, 0x72, 0x74, 0x7, 
    0xc, 0x2, 0x2, 0x73, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 
    0x2, 0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x79, 0x7, 0xf, 0x2, 0x2, 
    0x78, 0x73, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7a, 
    0x78, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7e, 
    0x3, 0x2, 0x2, 0x2, 0x7c, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x70, 0x3, 
    0x2, 0x2, 0x2, 0x7d, 0x71, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x12, 0x1e, 0x23, 0x29, 0x2f, 0x33, 0x37, 0x3a, 0x3f, 0x4a, 
    0x54, 0x59, 0x5f, 0x6e, 0x75, 0x7a, 0x7d, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

YW_CLI_Parser::Initializer YW_CLI_Parser::_init;
