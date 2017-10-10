
// Generated from YW_CONFIG_.g4 by ANTLR 4.7


#include "YW_CONFIG_Listener.h"

#include "YW_CONFIG_Parser.h"


using namespace antlrcpp;
using namespace yw;
using namespace antlr4;

YW_CONFIG_Parser::YW_CONFIG_Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

YW_CONFIG_Parser::~YW_CONFIG_Parser() {
  delete _interpreter;
}

std::string YW_CONFIG_Parser::getGrammarFileName() const {
  return "YW_CONFIG_.g4";
}

const std::vector<std::string>& YW_CONFIG_Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& YW_CONFIG_Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ConfigFileContext ------------------------------------------------------------------

YW_CONFIG_Parser::ConfigFileContext::ConfigFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<YW_CONFIG_Parser::BlankLineContext *> YW_CONFIG_Parser::ConfigFileContext::blankLine() {
  return getRuleContexts<YW_CONFIG_Parser::BlankLineContext>();
}

YW_CONFIG_Parser::BlankLineContext* YW_CONFIG_Parser::ConfigFileContext::blankLine(size_t i) {
  return getRuleContext<YW_CONFIG_Parser::BlankLineContext>(i);
}

std::vector<YW_CONFIG_Parser::CommentLineContext *> YW_CONFIG_Parser::ConfigFileContext::commentLine() {
  return getRuleContexts<YW_CONFIG_Parser::CommentLineContext>();
}

YW_CONFIG_Parser::CommentLineContext* YW_CONFIG_Parser::ConfigFileContext::commentLine(size_t i) {
  return getRuleContext<YW_CONFIG_Parser::CommentLineContext>(i);
}

std::vector<YW_CONFIG_Parser::SettingLineContext *> YW_CONFIG_Parser::ConfigFileContext::settingLine() {
  return getRuleContexts<YW_CONFIG_Parser::SettingLineContext>();
}

YW_CONFIG_Parser::SettingLineContext* YW_CONFIG_Parser::ConfigFileContext::settingLine(size_t i) {
  return getRuleContext<YW_CONFIG_Parser::SettingLineContext>(i);
}

std::vector<tree::TerminalNode *> YW_CONFIG_Parser::ConfigFileContext::SPACE() {
  return getTokens(YW_CONFIG_Parser::SPACE);
}

tree::TerminalNode* YW_CONFIG_Parser::ConfigFileContext::SPACE(size_t i) {
  return getToken(YW_CONFIG_Parser::SPACE, i);
}


size_t YW_CONFIG_Parser::ConfigFileContext::getRuleIndex() const {
  return YW_CONFIG_Parser::RuleConfigFile;
}

void YW_CONFIG_Parser::ConfigFileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConfigFile(this);
}

void YW_CONFIG_Parser::ConfigFileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConfigFile(this);
}

YW_CONFIG_Parser::ConfigFileContext* YW_CONFIG_Parser::configFile() {
  ConfigFileContext *_localctx = _tracker.createInstance<ConfigFileContext>(_ctx, getState());
  enterRule(_localctx, 0, YW_CONFIG_Parser::RuleConfigFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(23);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(21);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
        case 1: {
          setState(18);
          blankLine();
          break;
        }

        case 2: {
          setState(19);
          commentLine();
          break;
        }

        case 3: {
          setState(20);
          settingLine();
          break;
        }

        } 
      }
      setState(25);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(29);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YW_CONFIG_Parser::SPACE) {
      setState(26);
      match(YW_CONFIG_Parser::SPACE);
      setState(31);
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

//----------------- BlankLineContext ------------------------------------------------------------------

YW_CONFIG_Parser::BlankLineContext::BlankLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YW_CONFIG_Parser::BlankLineContext::NEWLINE() {
  return getToken(YW_CONFIG_Parser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> YW_CONFIG_Parser::BlankLineContext::SPACE() {
  return getTokens(YW_CONFIG_Parser::SPACE);
}

tree::TerminalNode* YW_CONFIG_Parser::BlankLineContext::SPACE(size_t i) {
  return getToken(YW_CONFIG_Parser::SPACE, i);
}


size_t YW_CONFIG_Parser::BlankLineContext::getRuleIndex() const {
  return YW_CONFIG_Parser::RuleBlankLine;
}

void YW_CONFIG_Parser::BlankLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlankLine(this);
}

void YW_CONFIG_Parser::BlankLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlankLine(this);
}

YW_CONFIG_Parser::BlankLineContext* YW_CONFIG_Parser::blankLine() {
  BlankLineContext *_localctx = _tracker.createInstance<BlankLineContext>(_ctx, getState());
  enterRule(_localctx, 2, YW_CONFIG_Parser::RuleBlankLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YW_CONFIG_Parser::SPACE) {
      setState(32);
      match(YW_CONFIG_Parser::SPACE);
      setState(37);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(38);
    match(YW_CONFIG_Parser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommentLineContext ------------------------------------------------------------------

YW_CONFIG_Parser::CommentLineContext::CommentLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YW_CONFIG_Parser::CommentContext* YW_CONFIG_Parser::CommentLineContext::comment() {
  return getRuleContext<YW_CONFIG_Parser::CommentContext>(0);
}

tree::TerminalNode* YW_CONFIG_Parser::CommentLineContext::NEWLINE() {
  return getToken(YW_CONFIG_Parser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> YW_CONFIG_Parser::CommentLineContext::SPACE() {
  return getTokens(YW_CONFIG_Parser::SPACE);
}

tree::TerminalNode* YW_CONFIG_Parser::CommentLineContext::SPACE(size_t i) {
  return getToken(YW_CONFIG_Parser::SPACE, i);
}


size_t YW_CONFIG_Parser::CommentLineContext::getRuleIndex() const {
  return YW_CONFIG_Parser::RuleCommentLine;
}

void YW_CONFIG_Parser::CommentLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommentLine(this);
}

void YW_CONFIG_Parser::CommentLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommentLine(this);
}

YW_CONFIG_Parser::CommentLineContext* YW_CONFIG_Parser::commentLine() {
  CommentLineContext *_localctx = _tracker.createInstance<CommentLineContext>(_ctx, getState());
  enterRule(_localctx, 4, YW_CONFIG_Parser::RuleCommentLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YW_CONFIG_Parser::SPACE) {
      setState(40);
      match(YW_CONFIG_Parser::SPACE);
      setState(45);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(46);
    comment();
    setState(47);
    match(YW_CONFIG_Parser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SettingLineContext ------------------------------------------------------------------

YW_CONFIG_Parser::SettingLineContext::SettingLineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YW_CONFIG_Parser::SettingContext* YW_CONFIG_Parser::SettingLineContext::setting() {
  return getRuleContext<YW_CONFIG_Parser::SettingContext>(0);
}

tree::TerminalNode* YW_CONFIG_Parser::SettingLineContext::NEWLINE() {
  return getToken(YW_CONFIG_Parser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> YW_CONFIG_Parser::SettingLineContext::SPACE() {
  return getTokens(YW_CONFIG_Parser::SPACE);
}

tree::TerminalNode* YW_CONFIG_Parser::SettingLineContext::SPACE(size_t i) {
  return getToken(YW_CONFIG_Parser::SPACE, i);
}

YW_CONFIG_Parser::CommentContext* YW_CONFIG_Parser::SettingLineContext::comment() {
  return getRuleContext<YW_CONFIG_Parser::CommentContext>(0);
}


size_t YW_CONFIG_Parser::SettingLineContext::getRuleIndex() const {
  return YW_CONFIG_Parser::RuleSettingLine;
}

void YW_CONFIG_Parser::SettingLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSettingLine(this);
}

void YW_CONFIG_Parser::SettingLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSettingLine(this);
}

YW_CONFIG_Parser::SettingLineContext* YW_CONFIG_Parser::settingLine() {
  SettingLineContext *_localctx = _tracker.createInstance<SettingLineContext>(_ctx, getState());
  enterRule(_localctx, 6, YW_CONFIG_Parser::RuleSettingLine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(52);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YW_CONFIG_Parser::SPACE) {
      setState(49);
      match(YW_CONFIG_Parser::SPACE);
      setState(54);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(55);
    setting();
    setState(59);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YW_CONFIG_Parser::SPACE) {
      setState(56);
      match(YW_CONFIG_Parser::SPACE);
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(63);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YW_CONFIG_Parser::T__0

    || _la == YW_CONFIG_Parser::T__1) {
      setState(62);
      comment();
    }
    setState(65);
    match(YW_CONFIG_Parser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommentContext ------------------------------------------------------------------

YW_CONFIG_Parser::CommentContext::CommentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> YW_CONFIG_Parser::CommentContext::SPACE() {
  return getTokens(YW_CONFIG_Parser::SPACE);
}

tree::TerminalNode* YW_CONFIG_Parser::CommentContext::SPACE(size_t i) {
  return getToken(YW_CONFIG_Parser::SPACE, i);
}

std::vector<tree::TerminalNode *> YW_CONFIG_Parser::CommentContext::WORD() {
  return getTokens(YW_CONFIG_Parser::WORD);
}

tree::TerminalNode* YW_CONFIG_Parser::CommentContext::WORD(size_t i) {
  return getToken(YW_CONFIG_Parser::WORD, i);
}


size_t YW_CONFIG_Parser::CommentContext::getRuleIndex() const {
  return YW_CONFIG_Parser::RuleComment;
}

void YW_CONFIG_Parser::CommentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComment(this);
}

void YW_CONFIG_Parser::CommentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComment(this);
}

YW_CONFIG_Parser::CommentContext* YW_CONFIG_Parser::comment() {
  CommentContext *_localctx = _tracker.createInstance<CommentContext>(_ctx, getState());
  enterRule(_localctx, 8, YW_CONFIG_Parser::RuleComment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    _la = _input->LA(1);
    if (!(_la == YW_CONFIG_Parser::T__0

    || _la == YW_CONFIG_Parser::T__1)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(71);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YW_CONFIG_Parser::SPACE

    || _la == YW_CONFIG_Parser::WORD) {
      setState(68);
      _la = _input->LA(1);
      if (!(_la == YW_CONFIG_Parser::SPACE

      || _la == YW_CONFIG_Parser::WORD)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(73);
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

//----------------- SettingContext ------------------------------------------------------------------

YW_CONFIG_Parser::SettingContext::SettingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YW_CONFIG_Parser::SettingNameContext* YW_CONFIG_Parser::SettingContext::settingName() {
  return getRuleContext<YW_CONFIG_Parser::SettingNameContext>(0);
}

YW_CONFIG_Parser::SettingValueContext* YW_CONFIG_Parser::SettingContext::settingValue() {
  return getRuleContext<YW_CONFIG_Parser::SettingValueContext>(0);
}

std::vector<tree::TerminalNode *> YW_CONFIG_Parser::SettingContext::SPACE() {
  return getTokens(YW_CONFIG_Parser::SPACE);
}

tree::TerminalNode* YW_CONFIG_Parser::SettingContext::SPACE(size_t i) {
  return getToken(YW_CONFIG_Parser::SPACE, i);
}


size_t YW_CONFIG_Parser::SettingContext::getRuleIndex() const {
  return YW_CONFIG_Parser::RuleSetting;
}

void YW_CONFIG_Parser::SettingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetting(this);
}

void YW_CONFIG_Parser::SettingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetting(this);
}

YW_CONFIG_Parser::SettingContext* YW_CONFIG_Parser::setting() {
  SettingContext *_localctx = _tracker.createInstance<SettingContext>(_ctx, getState());
  enterRule(_localctx, 10, YW_CONFIG_Parser::RuleSetting);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(74);
    settingName();
    setState(78);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YW_CONFIG_Parser::SPACE) {
      setState(75);
      match(YW_CONFIG_Parser::SPACE);
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(81);
    match(YW_CONFIG_Parser::T__2);
    setState(85);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(82);
        match(YW_CONFIG_Parser::SPACE); 
      }
      setState(87);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
    setState(88);
    settingValue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SettingNameContext ------------------------------------------------------------------

YW_CONFIG_Parser::SettingNameContext::SettingNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YW_CONFIG_Parser::SettingNameContext::WORD() {
  return getToken(YW_CONFIG_Parser::WORD, 0);
}


size_t YW_CONFIG_Parser::SettingNameContext::getRuleIndex() const {
  return YW_CONFIG_Parser::RuleSettingName;
}

void YW_CONFIG_Parser::SettingNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSettingName(this);
}

void YW_CONFIG_Parser::SettingNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSettingName(this);
}

YW_CONFIG_Parser::SettingNameContext* YW_CONFIG_Parser::settingName() {
  SettingNameContext *_localctx = _tracker.createInstance<SettingNameContext>(_ctx, getState());
  enterRule(_localctx, 12, YW_CONFIG_Parser::RuleSettingName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(YW_CONFIG_Parser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SettingValueContext ------------------------------------------------------------------

YW_CONFIG_Parser::SettingValueContext::SettingValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YW_CONFIG_Parser::UnquotedValueContext* YW_CONFIG_Parser::SettingValueContext::unquotedValue() {
  return getRuleContext<YW_CONFIG_Parser::UnquotedValueContext>(0);
}

std::vector<tree::TerminalNode *> YW_CONFIG_Parser::SettingValueContext::SQ() {
  return getTokens(YW_CONFIG_Parser::SQ);
}

tree::TerminalNode* YW_CONFIG_Parser::SettingValueContext::SQ(size_t i) {
  return getToken(YW_CONFIG_Parser::SQ, i);
}

std::vector<tree::TerminalNode *> YW_CONFIG_Parser::SettingValueContext::DQ() {
  return getTokens(YW_CONFIG_Parser::DQ);
}

tree::TerminalNode* YW_CONFIG_Parser::SettingValueContext::DQ(size_t i) {
  return getToken(YW_CONFIG_Parser::DQ, i);
}


size_t YW_CONFIG_Parser::SettingValueContext::getRuleIndex() const {
  return YW_CONFIG_Parser::RuleSettingValue;
}

void YW_CONFIG_Parser::SettingValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSettingValue(this);
}

void YW_CONFIG_Parser::SettingValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSettingValue(this);
}

YW_CONFIG_Parser::SettingValueContext* YW_CONFIG_Parser::settingValue() {
  SettingValueContext *_localctx = _tracker.createInstance<SettingValueContext>(_ctx, getState());
  enterRule(_localctx, 14, YW_CONFIG_Parser::RuleSettingValue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(101);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YW_CONFIG_Parser::T__0:
      case YW_CONFIG_Parser::T__1:
      case YW_CONFIG_Parser::T__2:
      case YW_CONFIG_Parser::NEWLINE:
      case YW_CONFIG_Parser::SPACE:
      case YW_CONFIG_Parser::WORD: {
        enterOuterAlt(_localctx, 1);
        setState(92);
        unquotedValue();
        break;
      }

      case YW_CONFIG_Parser::SQ: {
        enterOuterAlt(_localctx, 2);
        setState(93);
        match(YW_CONFIG_Parser::SQ);
        setState(94);
        unquotedValue();
        setState(95);
        match(YW_CONFIG_Parser::SQ);
        break;
      }

      case YW_CONFIG_Parser::DQ: {
        enterOuterAlt(_localctx, 3);
        setState(97);
        match(YW_CONFIG_Parser::DQ);
        setState(98);
        unquotedValue();
        setState(99);
        match(YW_CONFIG_Parser::DQ);
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

YW_CONFIG_Parser::UnquotedValueContext::UnquotedValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> YW_CONFIG_Parser::UnquotedValueContext::SPACE() {
  return getTokens(YW_CONFIG_Parser::SPACE);
}

tree::TerminalNode* YW_CONFIG_Parser::UnquotedValueContext::SPACE(size_t i) {
  return getToken(YW_CONFIG_Parser::SPACE, i);
}

std::vector<tree::TerminalNode *> YW_CONFIG_Parser::UnquotedValueContext::WORD() {
  return getTokens(YW_CONFIG_Parser::WORD);
}

tree::TerminalNode* YW_CONFIG_Parser::UnquotedValueContext::WORD(size_t i) {
  return getToken(YW_CONFIG_Parser::WORD, i);
}


size_t YW_CONFIG_Parser::UnquotedValueContext::getRuleIndex() const {
  return YW_CONFIG_Parser::RuleUnquotedValue;
}

void YW_CONFIG_Parser::UnquotedValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnquotedValue(this);
}

void YW_CONFIG_Parser::UnquotedValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YW_CONFIG_Listener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnquotedValue(this);
}

YW_CONFIG_Parser::UnquotedValueContext* YW_CONFIG_Parser::unquotedValue() {
  UnquotedValueContext *_localctx = _tracker.createInstance<UnquotedValueContext>(_ctx, getState());
  enterRule(_localctx, 16, YW_CONFIG_Parser::RuleUnquotedValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(106);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(103);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << YW_CONFIG_Parser::T__2)
          | (1ULL << YW_CONFIG_Parser::SPACE)
          | (1ULL << YW_CONFIG_Parser::WORD))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        } 
      }
      setState(108);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
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
std::vector<dfa::DFA> YW_CONFIG_Parser::_decisionToDFA;
atn::PredictionContextCache YW_CONFIG_Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN YW_CONFIG_Parser::_atn;
std::vector<uint16_t> YW_CONFIG_Parser::_serializedATN;

std::vector<std::string> YW_CONFIG_Parser::_ruleNames = {
  "configFile", "blankLine", "commentLine", "settingLine", "comment", "setting", 
  "settingName", "settingValue", "unquotedValue"
};

std::vector<std::string> YW_CONFIG_Parser::_literalNames = {
  "", "'#'", "'//'", "'='", "", "", "'\"'", "'''"
};

std::vector<std::string> YW_CONFIG_Parser::_symbolicNames = {
  "", "", "", "", "NEWLINE", "SPACE", "DQ", "SQ", "WORD"
};

dfa::Vocabulary YW_CONFIG_Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> YW_CONFIG_Parser::_tokenNames;

YW_CONFIG_Parser::Initializer::Initializer() {
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
    0x3, 0xa, 0x70, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x18, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x1b, 0xb, 
    0x2, 0x3, 0x2, 0x7, 0x2, 0x1e, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x21, 0xb, 
    0x2, 0x3, 0x3, 0x7, 0x3, 0x24, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x27, 0xb, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x7, 0x4, 0x2c, 0xa, 0x4, 0xc, 0x4, 
    0xe, 0x4, 0x2f, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x7, 
    0x5, 0x35, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x38, 0xb, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x7, 0x5, 0x3c, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x3f, 0xb, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x42, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x7, 0x6, 0x48, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x4b, 0xb, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x7, 0x7, 0x4f, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x52, 0xb, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x56, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x59, 
    0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x5, 0x9, 0x68, 0xa, 0x9, 0x3, 0xa, 0x7, 0xa, 0x6b, 0xa, 0xa, 0xc, 0xa, 
    0xe, 0xa, 0x6e, 0xb, 0xa, 0x3, 0xa, 0x3, 0x6c, 0x2, 0xb, 0x2, 0x4, 0x6, 
    0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x2, 0x5, 0x3, 0x2, 0x3, 0x4, 0x4, 0x2, 
    0x7, 0x7, 0xa, 0xa, 0x5, 0x2, 0x5, 0x5, 0x7, 0x7, 0xa, 0xa, 0x2, 0x75, 
    0x2, 0x19, 0x3, 0x2, 0x2, 0x2, 0x4, 0x25, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x36, 0x3, 0x2, 0x2, 0x2, 0xa, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x4c, 0x3, 0x2, 0x2, 0x2, 0xe, 0x5c, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x67, 0x3, 0x2, 0x2, 0x2, 0x12, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x18, 0x5, 0x4, 0x3, 0x2, 0x15, 0x18, 0x5, 0x6, 0x4, 0x2, 0x16, 0x18, 
    0x5, 0x8, 0x5, 0x2, 0x17, 0x14, 0x3, 0x2, 0x2, 0x2, 0x17, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0x17, 0x16, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x19, 0x17, 0x3, 0x2, 0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0x1c, 0x1e, 0x7, 0x7, 0x2, 0x2, 0x1d, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1e, 
    0x21, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x3, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x22, 0x24, 0x7, 0x7, 0x2, 0x2, 0x23, 0x22, 0x3, 0x2, 
    0x2, 0x2, 0x24, 0x27, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x25, 0x26, 0x3, 0x2, 0x2, 0x2, 0x26, 0x28, 0x3, 0x2, 0x2, 0x2, 
    0x27, 0x25, 0x3, 0x2, 0x2, 0x2, 0x28, 0x29, 0x7, 0x6, 0x2, 0x2, 0x29, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2c, 0x7, 0x7, 0x2, 0x2, 0x2b, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x30, 0x3, 0x2, 
    0x2, 0x2, 0x2f, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x5, 0xa, 0x6, 
    0x2, 0x31, 0x32, 0x7, 0x6, 0x2, 0x2, 0x32, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x33, 0x35, 0x7, 0x7, 0x2, 0x2, 0x34, 0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 
    0x38, 0x3, 0x2, 0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 
    0x3, 0x2, 0x2, 0x2, 0x37, 0x39, 0x3, 0x2, 0x2, 0x2, 0x38, 0x36, 0x3, 
    0x2, 0x2, 0x2, 0x39, 0x3d, 0x5, 0xc, 0x7, 0x2, 0x3a, 0x3c, 0x7, 0x7, 
    0x2, 0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x41, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x42, 0x5, 0xa, 0x6, 0x2, 0x41, 0x40, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x7, 
    0x6, 0x2, 0x2, 0x44, 0x9, 0x3, 0x2, 0x2, 0x2, 0x45, 0x49, 0x9, 0x2, 
    0x2, 0x2, 0x46, 0x48, 0x9, 0x3, 0x2, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x50, 0x5, 0xe, 0x8, 0x2, 0x4d, 0x4f, 
    0x7, 0x7, 0x2, 0x2, 0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x52, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x51, 0x53, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 
    0x2, 0x53, 0x57, 0x7, 0x5, 0x2, 0x2, 0x54, 0x56, 0x7, 0x7, 0x2, 0x2, 
    0x55, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x59, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 0x2, 0x58, 0x5a, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x5, 
    0x10, 0x9, 0x2, 0x5b, 0xd, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0xa, 
    0x2, 0x2, 0x5d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x68, 0x5, 0x12, 0xa, 
    0x2, 0x5f, 0x60, 0x7, 0x9, 0x2, 0x2, 0x60, 0x61, 0x5, 0x12, 0xa, 0x2, 
    0x61, 0x62, 0x7, 0x9, 0x2, 0x2, 0x62, 0x68, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x64, 0x7, 0x8, 0x2, 0x2, 0x64, 0x65, 0x5, 0x12, 0xa, 0x2, 0x65, 0x66, 
    0x7, 0x8, 0x2, 0x2, 0x66, 0x68, 0x3, 0x2, 0x2, 0x2, 0x67, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x67, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x11, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6b, 0x9, 0x4, 0x2, 
    0x2, 0x6a, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6d, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0xf, 0x17, 
    0x19, 0x1f, 0x25, 0x2d, 0x36, 0x3d, 0x41, 0x49, 0x50, 0x57, 0x67, 0x6c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

YW_CONFIG_Parser::Initializer YW_CONFIG_Parser::_init;