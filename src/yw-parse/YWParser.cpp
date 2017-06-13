
// Generated from YW.g4 by ANTLR 4.7


#include "YWListener.h"

#include "YWParser.h"


using namespace antlrcpp;
using namespace antlr4;

YWParser::YWParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

YWParser::~YWParser() {
  delete _interpreter;
}

std::string YWParser::getGrammarFileName() const {
  return "YW.g4";
}

const std::vector<std::string>& YWParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& YWParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ScriptContext ------------------------------------------------------------------

YWParser::ScriptContext::ScriptContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<YWParser::BlockContext *> YWParser::ScriptContext::block() {
  return getRuleContexts<YWParser::BlockContext>();
}

YWParser::BlockContext* YWParser::ScriptContext::block(size_t i) {
  return getRuleContext<YWParser::BlockContext>(i);
}


size_t YWParser::ScriptContext::getRuleIndex() const {
  return YWParser::RuleScript;
}

void YWParser::ScriptContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScript(this);
}

void YWParser::ScriptContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScript(this);
}

YWParser::ScriptContext* YWParser::script() {
  ScriptContext *_localctx = _tracker.createInstance<ScriptContext>(_ctx, getState());
  enterRule(_localctx, 0, YWParser::RuleScript);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(67);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YWParser::T__1) {
      setState(64);
      block();
      setState(69);
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

//----------------- BlockContext ------------------------------------------------------------------

YWParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::BeginTagContext* YWParser::BlockContext::beginTag() {
  return getRuleContext<YWParser::BeginTagContext>(0);
}

YWParser::EndTagContext* YWParser::BlockContext::endTag() {
  return getRuleContext<YWParser::EndTagContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::BlockContext::WS() {
  return getTokens(YWParser::WS);
}

tree::TerminalNode* YWParser::BlockContext::WS(size_t i) {
  return getToken(YWParser::WS, i);
}

std::vector<YWParser::BlockAttributeContext *> YWParser::BlockContext::blockAttribute() {
  return getRuleContexts<YWParser::BlockAttributeContext>();
}

YWParser::BlockAttributeContext* YWParser::BlockContext::blockAttribute(size_t i) {
  return getRuleContext<YWParser::BlockAttributeContext>(i);
}

std::vector<YWParser::BlockContext *> YWParser::BlockContext::block() {
  return getRuleContexts<YWParser::BlockContext>();
}

YWParser::BlockContext* YWParser::BlockContext::block(size_t i) {
  return getRuleContext<YWParser::BlockContext>(i);
}


size_t YWParser::BlockContext::getRuleIndex() const {
  return YWParser::RuleBlock;
}

void YWParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void YWParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

YWParser::BlockContext* YWParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 2, YWParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(70);
    beginTag();
    setState(74);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(71);
        match(YWParser::WS); 
      }
      setState(76);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(80);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YWParser::T__2)
      | (1ULL << YWParser::T__3)
      | (1ULL << YWParser::T__6)
      | (1ULL << YWParser::T__7)
      | (1ULL << YWParser::T__8)
      | (1ULL << YWParser::T__9))) != 0)) {
      setState(77);
      blockAttribute();
      setState(82);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(86);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(83);
        match(YWParser::WS); 
      }
      setState(88);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
    setState(92);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YWParser::T__1) {
      setState(89);
      block();
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(98);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YWParser::WS) {
      setState(95);
      match(YWParser::WS);
      setState(100);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(101);
    endTag();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockAttributeContext ------------------------------------------------------------------

YWParser::BlockAttributeContext::BlockAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::DescTagContext* YWParser::BlockAttributeContext::descTag() {
  return getRuleContext<YWParser::DescTagContext>(0);
}

YWParser::PortTagContext* YWParser::BlockAttributeContext::portTag() {
  return getRuleContext<YWParser::PortTagContext>(0);
}

YWParser::CallTagContext* YWParser::BlockAttributeContext::callTag() {
  return getRuleContext<YWParser::CallTagContext>(0);
}


size_t YWParser::BlockAttributeContext::getRuleIndex() const {
  return YWParser::RuleBlockAttribute;
}

void YWParser::BlockAttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockAttribute(this);
}

void YWParser::BlockAttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockAttribute(this);
}

YWParser::BlockAttributeContext* YWParser::blockAttribute() {
  BlockAttributeContext *_localctx = _tracker.createInstance<BlockAttributeContext>(_ctx, getState());
  enterRule(_localctx, 4, YWParser::RuleBlockAttribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(106);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__3: {
        enterOuterAlt(_localctx, 1);
        setState(103);
        descTag();
        break;
      }

      case YWParser::T__6:
      case YWParser::T__7:
      case YWParser::T__8:
      case YWParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(104);
        portTag();
        break;
      }

      case YWParser::T__2: {
        enterOuterAlt(_localctx, 3);
        setState(105);
        callTag();
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

//----------------- PortAttributeContext ------------------------------------------------------------------

YWParser::PortAttributeContext::PortAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::DescTagContext* YWParser::PortAttributeContext::descTag() {
  return getRuleContext<YWParser::DescTagContext>(0);
}

YWParser::AliasTagContext* YWParser::PortAttributeContext::aliasTag() {
  return getRuleContext<YWParser::AliasTagContext>(0);
}

YWParser::ResourceTagContext* YWParser::PortAttributeContext::resourceTag() {
  return getRuleContext<YWParser::ResourceTagContext>(0);
}


size_t YWParser::PortAttributeContext::getRuleIndex() const {
  return YWParser::RulePortAttribute;
}

void YWParser::PortAttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortAttribute(this);
}

void YWParser::PortAttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortAttribute(this);
}

YWParser::PortAttributeContext* YWParser::portAttribute() {
  PortAttributeContext *_localctx = _tracker.createInstance<PortAttributeContext>(_ctx, getState());
  enterRule(_localctx, 6, YWParser::RulePortAttribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(111);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__3: {
        enterOuterAlt(_localctx, 1);
        setState(108);
        descTag();
        break;
      }

      case YWParser::T__0: {
        enterOuterAlt(_localctx, 2);
        setState(109);
        aliasTag();
        break;
      }

      case YWParser::T__5:
      case YWParser::T__10: {
        enterOuterAlt(_localctx, 3);
        setState(110);
        resourceTag();
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

//----------------- BeginTagContext ------------------------------------------------------------------

YWParser::BeginTagContext::BeginTagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::BeginKeywordContext* YWParser::BeginTagContext::beginKeyword() {
  return getRuleContext<YWParser::BeginKeywordContext>(0);
}

YWParser::BlockNameContext* YWParser::BeginTagContext::blockName() {
  return getRuleContext<YWParser::BlockNameContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::BeginTagContext::HS() {
  return getTokens(YWParser::HS);
}

tree::TerminalNode* YWParser::BeginTagContext::HS(size_t i) {
  return getToken(YWParser::HS, i);
}


size_t YWParser::BeginTagContext::getRuleIndex() const {
  return YWParser::RuleBeginTag;
}

void YWParser::BeginTagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBeginTag(this);
}

void YWParser::BeginTagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBeginTag(this);
}

YWParser::BeginTagContext* YWParser::beginTag() {
  BeginTagContext *_localctx = _tracker.createInstance<BeginTagContext>(_ctx, getState());
  enterRule(_localctx, 8, YWParser::RuleBeginTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    beginKeyword();
    setState(115); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(114);
      match(YWParser::HS);
      setState(117); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(119);
    blockName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndTagContext ------------------------------------------------------------------

YWParser::EndTagContext::EndTagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::EndKeywordContext* YWParser::EndTagContext::endKeyword() {
  return getRuleContext<YWParser::EndKeywordContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::EndTagContext::HS() {
  return getTokens(YWParser::HS);
}

tree::TerminalNode* YWParser::EndTagContext::HS(size_t i) {
  return getToken(YWParser::HS, i);
}

YWParser::BlockNameContext* YWParser::EndTagContext::blockName() {
  return getRuleContext<YWParser::BlockNameContext>(0);
}


size_t YWParser::EndTagContext::getRuleIndex() const {
  return YWParser::RuleEndTag;
}

void YWParser::EndTagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEndTag(this);
}

void YWParser::EndTagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEndTag(this);
}

YWParser::EndTagContext* YWParser::endTag() {
  EndTagContext *_localctx = _tracker.createInstance<EndTagContext>(_ctx, getState());
  enterRule(_localctx, 10, YWParser::RuleEndTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    endKeyword();
    setState(123); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(122);
      match(YWParser::HS);
      setState(125); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(128);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YWParser::ID) {
      setState(127);
      blockName();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DescTagContext ------------------------------------------------------------------

YWParser::DescTagContext::DescTagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::DescKeywordContext* YWParser::DescTagContext::descKeyword() {
  return getRuleContext<YWParser::DescKeywordContext>(0);
}

YWParser::DescriptionContext* YWParser::DescTagContext::description() {
  return getRuleContext<YWParser::DescriptionContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::DescTagContext::HS() {
  return getTokens(YWParser::HS);
}

tree::TerminalNode* YWParser::DescTagContext::HS(size_t i) {
  return getToken(YWParser::HS, i);
}


size_t YWParser::DescTagContext::getRuleIndex() const {
  return YWParser::RuleDescTag;
}

void YWParser::DescTagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDescTag(this);
}

void YWParser::DescTagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDescTag(this);
}

YWParser::DescTagContext* YWParser::descTag() {
  DescTagContext *_localctx = _tracker.createInstance<DescTagContext>(_ctx, getState());
  enterRule(_localctx, 12, YWParser::RuleDescTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    descKeyword();
    setState(132); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(131);
      match(YWParser::HS);
      setState(134); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(136);
    description();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortTagContext ------------------------------------------------------------------

YWParser::PortTagContext::PortTagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::InputPortKeywordContext* YWParser::PortTagContext::inputPortKeyword() {
  return getRuleContext<YWParser::InputPortKeywordContext>(0);
}

YWParser::OutputPortKeywordContext* YWParser::PortTagContext::outputPortKeyword() {
  return getRuleContext<YWParser::OutputPortKeywordContext>(0);
}

std::vector<YWParser::PortNameContext *> YWParser::PortTagContext::portName() {
  return getRuleContexts<YWParser::PortNameContext>();
}

YWParser::PortNameContext* YWParser::PortTagContext::portName(size_t i) {
  return getRuleContext<YWParser::PortNameContext>(i);
}

std::vector<tree::TerminalNode *> YWParser::PortTagContext::HS() {
  return getTokens(YWParser::HS);
}

tree::TerminalNode* YWParser::PortTagContext::HS(size_t i) {
  return getToken(YWParser::HS, i);
}

std::vector<YWParser::PortAttributeContext *> YWParser::PortTagContext::portAttribute() {
  return getRuleContexts<YWParser::PortAttributeContext>();
}

YWParser::PortAttributeContext* YWParser::PortTagContext::portAttribute(size_t i) {
  return getRuleContext<YWParser::PortAttributeContext>(i);
}


size_t YWParser::PortTagContext::getRuleIndex() const {
  return YWParser::RulePortTag;
}

void YWParser::PortTagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortTag(this);
}

void YWParser::PortTagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortTag(this);
}

YWParser::PortTagContext* YWParser::portTag() {
  PortTagContext *_localctx = _tracker.createInstance<PortTagContext>(_ctx, getState());
  enterRule(_localctx, 14, YWParser::RulePortTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(140);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__6:
      case YWParser::T__8: {
        setState(138);
        inputPortKeyword();
        break;
      }

      case YWParser::T__7:
      case YWParser::T__9: {
        setState(139);
        outputPortKeyword();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(161); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(143); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(142);
        match(YWParser::HS);
        setState(145); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == YWParser::HS);
      setState(147);
      portName();
      setState(159);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(149); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(148);
                  match(YWParser::HS);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(151); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        setState(156);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(153);
            portAttribute(); 
          }
          setState(158);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
        }
        break;
      }

      }
      setState(163); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasTagContext ------------------------------------------------------------------

YWParser::AliasTagContext::AliasTagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::AsKeywordContext* YWParser::AliasTagContext::asKeyword() {
  return getRuleContext<YWParser::AsKeywordContext>(0);
}

YWParser::DataNameContext* YWParser::AliasTagContext::dataName() {
  return getRuleContext<YWParser::DataNameContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::AliasTagContext::HS() {
  return getTokens(YWParser::HS);
}

tree::TerminalNode* YWParser::AliasTagContext::HS(size_t i) {
  return getToken(YWParser::HS, i);
}


size_t YWParser::AliasTagContext::getRuleIndex() const {
  return YWParser::RuleAliasTag;
}

void YWParser::AliasTagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAliasTag(this);
}

void YWParser::AliasTagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAliasTag(this);
}

YWParser::AliasTagContext* YWParser::aliasTag() {
  AliasTagContext *_localctx = _tracker.createInstance<AliasTagContext>(_ctx, getState());
  enterRule(_localctx, 16, YWParser::RuleAliasTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    asKeyword();
    setState(167); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(166);
      match(YWParser::HS);
      setState(169); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(171);
    dataName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallTagContext ------------------------------------------------------------------

YWParser::CallTagContext::CallTagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::CallKeywordContext* YWParser::CallTagContext::callKeyword() {
  return getRuleContext<YWParser::CallKeywordContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::CallTagContext::HS() {
  return getTokens(YWParser::HS);
}

tree::TerminalNode* YWParser::CallTagContext::HS(size_t i) {
  return getToken(YWParser::HS, i);
}

std::vector<YWParser::BlockNameContext *> YWParser::CallTagContext::blockName() {
  return getRuleContexts<YWParser::BlockNameContext>();
}

YWParser::BlockNameContext* YWParser::CallTagContext::blockName(size_t i) {
  return getRuleContext<YWParser::BlockNameContext>(i);
}


size_t YWParser::CallTagContext::getRuleIndex() const {
  return YWParser::RuleCallTag;
}

void YWParser::CallTagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallTag(this);
}

void YWParser::CallTagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallTag(this);
}

YWParser::CallTagContext* YWParser::callTag() {
  CallTagContext *_localctx = _tracker.createInstance<CallTagContext>(_ctx, getState());
  enterRule(_localctx, 18, YWParser::RuleCallTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(173);
    callKeyword();
    setState(175); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(174);
      match(YWParser::HS);
      setState(177); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(180); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(179);
      blockName();
      setState(182); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UriTagContext ------------------------------------------------------------------

YWParser::UriTagContext::UriTagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::UriKeywordContext* YWParser::UriTagContext::uriKeyword() {
  return getRuleContext<YWParser::UriKeywordContext>(0);
}

YWParser::UriTemplateContext* YWParser::UriTagContext::uriTemplate() {
  return getRuleContext<YWParser::UriTemplateContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::UriTagContext::HS() {
  return getTokens(YWParser::HS);
}

tree::TerminalNode* YWParser::UriTagContext::HS(size_t i) {
  return getToken(YWParser::HS, i);
}


size_t YWParser::UriTagContext::getRuleIndex() const {
  return YWParser::RuleUriTag;
}

void YWParser::UriTagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUriTag(this);
}

void YWParser::UriTagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUriTag(this);
}

YWParser::UriTagContext* YWParser::uriTag() {
  UriTagContext *_localctx = _tracker.createInstance<UriTagContext>(_ctx, getState());
  enterRule(_localctx, 20, YWParser::RuleUriTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    uriKeyword();
    setState(186); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(185);
      match(YWParser::HS);
      setState(188); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(190);
    uriTemplate();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FileTagContext ------------------------------------------------------------------

YWParser::FileTagContext::FileTagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::FileKeywordContext* YWParser::FileTagContext::fileKeyword() {
  return getRuleContext<YWParser::FileKeywordContext>(0);
}

tree::TerminalNode* YWParser::FileTagContext::PATH_TEMPLATE() {
  return getToken(YWParser::PATH_TEMPLATE, 0);
}

std::vector<tree::TerminalNode *> YWParser::FileTagContext::HS() {
  return getTokens(YWParser::HS);
}

tree::TerminalNode* YWParser::FileTagContext::HS(size_t i) {
  return getToken(YWParser::HS, i);
}


size_t YWParser::FileTagContext::getRuleIndex() const {
  return YWParser::RuleFileTag;
}

void YWParser::FileTagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFileTag(this);
}

void YWParser::FileTagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFileTag(this);
}

YWParser::FileTagContext* YWParser::fileTag() {
  FileTagContext *_localctx = _tracker.createInstance<FileTagContext>(_ctx, getState());
  enterRule(_localctx, 22, YWParser::RuleFileTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    fileKeyword();
    setState(194); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(193);
      match(YWParser::HS);
      setState(196); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(198);
    match(YWParser::PATH_TEMPLATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResourceTagContext ------------------------------------------------------------------

YWParser::ResourceTagContext::ResourceTagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::UriTagContext* YWParser::ResourceTagContext::uriTag() {
  return getRuleContext<YWParser::UriTagContext>(0);
}

YWParser::FileTagContext* YWParser::ResourceTagContext::fileTag() {
  return getRuleContext<YWParser::FileTagContext>(0);
}


size_t YWParser::ResourceTagContext::getRuleIndex() const {
  return YWParser::RuleResourceTag;
}

void YWParser::ResourceTagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResourceTag(this);
}

void YWParser::ResourceTagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResourceTag(this);
}

YWParser::ResourceTagContext* YWParser::resourceTag() {
  ResourceTagContext *_localctx = _tracker.createInstance<ResourceTagContext>(_ctx, getState());
  enterRule(_localctx, 24, YWParser::RuleResourceTag);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(202);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__10: {
        enterOuterAlt(_localctx, 1);
        setState(200);
        uriTag();
        break;
      }

      case YWParser::T__5: {
        enterOuterAlt(_localctx, 2);
        setState(201);
        fileTag();
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

//----------------- InputPortKeywordContext ------------------------------------------------------------------

YWParser::InputPortKeywordContext::InputPortKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::InKeywordContext* YWParser::InputPortKeywordContext::inKeyword() {
  return getRuleContext<YWParser::InKeywordContext>(0);
}

YWParser::ParamKeywordContext* YWParser::InputPortKeywordContext::paramKeyword() {
  return getRuleContext<YWParser::ParamKeywordContext>(0);
}


size_t YWParser::InputPortKeywordContext::getRuleIndex() const {
  return YWParser::RuleInputPortKeyword;
}

void YWParser::InputPortKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInputPortKeyword(this);
}

void YWParser::InputPortKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInputPortKeyword(this);
}

YWParser::InputPortKeywordContext* YWParser::inputPortKeyword() {
  InputPortKeywordContext *_localctx = _tracker.createInstance<InputPortKeywordContext>(_ctx, getState());
  enterRule(_localctx, 26, YWParser::RuleInputPortKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(206);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(204);
        inKeyword();
        break;
      }

      case YWParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(205);
        paramKeyword();
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

//----------------- OutputPortKeywordContext ------------------------------------------------------------------

YWParser::OutputPortKeywordContext::OutputPortKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::OutKeywordContext* YWParser::OutputPortKeywordContext::outKeyword() {
  return getRuleContext<YWParser::OutKeywordContext>(0);
}

YWParser::ReturnKeywordContext* YWParser::OutputPortKeywordContext::returnKeyword() {
  return getRuleContext<YWParser::ReturnKeywordContext>(0);
}


size_t YWParser::OutputPortKeywordContext::getRuleIndex() const {
  return YWParser::RuleOutputPortKeyword;
}

void YWParser::OutputPortKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOutputPortKeyword(this);
}

void YWParser::OutputPortKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOutputPortKeyword(this);
}

YWParser::OutputPortKeywordContext* YWParser::outputPortKeyword() {
  OutputPortKeywordContext *_localctx = _tracker.createInstance<OutputPortKeywordContext>(_ctx, getState());
  enterRule(_localctx, 28, YWParser::RuleOutputPortKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(210);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__7: {
        enterOuterAlt(_localctx, 1);
        setState(208);
        outKeyword();
        break;
      }

      case YWParser::T__9: {
        enterOuterAlt(_localctx, 2);
        setState(209);
        returnKeyword();
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

//----------------- AsKeywordContext ------------------------------------------------------------------

YWParser::AsKeywordContext::AsKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YWParser::AsKeywordContext::getRuleIndex() const {
  return YWParser::RuleAsKeyword;
}

void YWParser::AsKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsKeyword(this);
}

void YWParser::AsKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsKeyword(this);
}

YWParser::AsKeywordContext* YWParser::asKeyword() {
  AsKeywordContext *_localctx = _tracker.createInstance<AsKeywordContext>(_ctx, getState());
  enterRule(_localctx, 30, YWParser::RuleAsKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(YWParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BeginKeywordContext ------------------------------------------------------------------

YWParser::BeginKeywordContext::BeginKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YWParser::BeginKeywordContext::getRuleIndex() const {
  return YWParser::RuleBeginKeyword;
}

void YWParser::BeginKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBeginKeyword(this);
}

void YWParser::BeginKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBeginKeyword(this);
}

YWParser::BeginKeywordContext* YWParser::beginKeyword() {
  BeginKeywordContext *_localctx = _tracker.createInstance<BeginKeywordContext>(_ctx, getState());
  enterRule(_localctx, 32, YWParser::RuleBeginKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(214);
    match(YWParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallKeywordContext ------------------------------------------------------------------

YWParser::CallKeywordContext::CallKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YWParser::CallKeywordContext::getRuleIndex() const {
  return YWParser::RuleCallKeyword;
}

void YWParser::CallKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallKeyword(this);
}

void YWParser::CallKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallKeyword(this);
}

YWParser::CallKeywordContext* YWParser::callKeyword() {
  CallKeywordContext *_localctx = _tracker.createInstance<CallKeywordContext>(_ctx, getState());
  enterRule(_localctx, 34, YWParser::RuleCallKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    match(YWParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DescKeywordContext ------------------------------------------------------------------

YWParser::DescKeywordContext::DescKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YWParser::DescKeywordContext::getRuleIndex() const {
  return YWParser::RuleDescKeyword;
}

void YWParser::DescKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDescKeyword(this);
}

void YWParser::DescKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDescKeyword(this);
}

YWParser::DescKeywordContext* YWParser::descKeyword() {
  DescKeywordContext *_localctx = _tracker.createInstance<DescKeywordContext>(_ctx, getState());
  enterRule(_localctx, 36, YWParser::RuleDescKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(YWParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndKeywordContext ------------------------------------------------------------------

YWParser::EndKeywordContext::EndKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YWParser::EndKeywordContext::getRuleIndex() const {
  return YWParser::RuleEndKeyword;
}

void YWParser::EndKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEndKeyword(this);
}

void YWParser::EndKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEndKeyword(this);
}

YWParser::EndKeywordContext* YWParser::endKeyword() {
  EndKeywordContext *_localctx = _tracker.createInstance<EndKeywordContext>(_ctx, getState());
  enterRule(_localctx, 38, YWParser::RuleEndKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(220);
    match(YWParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FileKeywordContext ------------------------------------------------------------------

YWParser::FileKeywordContext::FileKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YWParser::FileKeywordContext::getRuleIndex() const {
  return YWParser::RuleFileKeyword;
}

void YWParser::FileKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFileKeyword(this);
}

void YWParser::FileKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFileKeyword(this);
}

YWParser::FileKeywordContext* YWParser::fileKeyword() {
  FileKeywordContext *_localctx = _tracker.createInstance<FileKeywordContext>(_ctx, getState());
  enterRule(_localctx, 40, YWParser::RuleFileKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(222);
    match(YWParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InKeywordContext ------------------------------------------------------------------

YWParser::InKeywordContext::InKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YWParser::InKeywordContext::getRuleIndex() const {
  return YWParser::RuleInKeyword;
}

void YWParser::InKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInKeyword(this);
}

void YWParser::InKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInKeyword(this);
}

YWParser::InKeywordContext* YWParser::inKeyword() {
  InKeywordContext *_localctx = _tracker.createInstance<InKeywordContext>(_ctx, getState());
  enterRule(_localctx, 42, YWParser::RuleInKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    match(YWParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OutKeywordContext ------------------------------------------------------------------

YWParser::OutKeywordContext::OutKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YWParser::OutKeywordContext::getRuleIndex() const {
  return YWParser::RuleOutKeyword;
}

void YWParser::OutKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOutKeyword(this);
}

void YWParser::OutKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOutKeyword(this);
}

YWParser::OutKeywordContext* YWParser::outKeyword() {
  OutKeywordContext *_localctx = _tracker.createInstance<OutKeywordContext>(_ctx, getState());
  enterRule(_localctx, 44, YWParser::RuleOutKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    match(YWParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamKeywordContext ------------------------------------------------------------------

YWParser::ParamKeywordContext::ParamKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YWParser::ParamKeywordContext::getRuleIndex() const {
  return YWParser::RuleParamKeyword;
}

void YWParser::ParamKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamKeyword(this);
}

void YWParser::ParamKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamKeyword(this);
}

YWParser::ParamKeywordContext* YWParser::paramKeyword() {
  ParamKeywordContext *_localctx = _tracker.createInstance<ParamKeywordContext>(_ctx, getState());
  enterRule(_localctx, 46, YWParser::RuleParamKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    match(YWParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnKeywordContext ------------------------------------------------------------------

YWParser::ReturnKeywordContext::ReturnKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YWParser::ReturnKeywordContext::getRuleIndex() const {
  return YWParser::RuleReturnKeyword;
}

void YWParser::ReturnKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnKeyword(this);
}

void YWParser::ReturnKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnKeyword(this);
}

YWParser::ReturnKeywordContext* YWParser::returnKeyword() {
  ReturnKeywordContext *_localctx = _tracker.createInstance<ReturnKeywordContext>(_ctx, getState());
  enterRule(_localctx, 48, YWParser::RuleReturnKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    match(YWParser::T__9);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UriKeywordContext ------------------------------------------------------------------

YWParser::UriKeywordContext::UriKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YWParser::UriKeywordContext::getRuleIndex() const {
  return YWParser::RuleUriKeyword;
}

void YWParser::UriKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUriKeyword(this);
}

void YWParser::UriKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUriKeyword(this);
}

YWParser::UriKeywordContext* YWParser::uriKeyword() {
  UriKeywordContext *_localctx = _tracker.createInstance<UriKeywordContext>(_ctx, getState());
  enterRule(_localctx, 50, YWParser::RuleUriKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(YWParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockNameContext ------------------------------------------------------------------

YWParser::BlockNameContext::BlockNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::BlockNameContext::ID() {
  return getToken(YWParser::ID, 0);
}


size_t YWParser::BlockNameContext::getRuleIndex() const {
  return YWParser::RuleBlockName;
}

void YWParser::BlockNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockName(this);
}

void YWParser::BlockNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockName(this);
}

YWParser::BlockNameContext* YWParser::blockName() {
  BlockNameContext *_localctx = _tracker.createInstance<BlockNameContext>(_ctx, getState());
  enterRule(_localctx, 52, YWParser::RuleBlockName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    match(YWParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortNameContext ------------------------------------------------------------------

YWParser::PortNameContext::PortNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::PortNameContext::ID() {
  return getToken(YWParser::ID, 0);
}


size_t YWParser::PortNameContext::getRuleIndex() const {
  return YWParser::RulePortName;
}

void YWParser::PortNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortName(this);
}

void YWParser::PortNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortName(this);
}

YWParser::PortNameContext* YWParser::portName() {
  PortNameContext *_localctx = _tracker.createInstance<PortNameContext>(_ctx, getState());
  enterRule(_localctx, 54, YWParser::RulePortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    match(YWParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DataNameContext ------------------------------------------------------------------

YWParser::DataNameContext::DataNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::DataNameContext::ID() {
  return getToken(YWParser::ID, 0);
}


size_t YWParser::DataNameContext::getRuleIndex() const {
  return YWParser::RuleDataName;
}

void YWParser::DataNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDataName(this);
}

void YWParser::DataNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDataName(this);
}

YWParser::DataNameContext* YWParser::dataName() {
  DataNameContext *_localctx = _tracker.createInstance<DataNameContext>(_ctx, getState());
  enterRule(_localctx, 56, YWParser::RuleDataName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(YWParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UriTemplateContext ------------------------------------------------------------------

YWParser::UriTemplateContext::UriTemplateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::UriTemplateContext::PATH_TEMPLATE() {
  return getToken(YWParser::PATH_TEMPLATE, 0);
}

YWParser::SchemeContext* YWParser::UriTemplateContext::scheme() {
  return getRuleContext<YWParser::SchemeContext>(0);
}


size_t YWParser::UriTemplateContext::getRuleIndex() const {
  return YWParser::RuleUriTemplate;
}

void YWParser::UriTemplateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUriTemplate(this);
}

void YWParser::UriTemplateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUriTemplate(this);
}

YWParser::UriTemplateContext* YWParser::uriTemplate() {
  UriTemplateContext *_localctx = _tracker.createInstance<UriTemplateContext>(_ctx, getState());
  enterRule(_localctx, 58, YWParser::RuleUriTemplate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YWParser::T__12

    || _la == YWParser::T__13) {
      setState(240);
      scheme();
      setState(241);
      match(YWParser::T__11);
    }
    setState(245);
    match(YWParser::PATH_TEMPLATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SchemeContext ------------------------------------------------------------------

YWParser::SchemeContext::SchemeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t YWParser::SchemeContext::getRuleIndex() const {
  return YWParser::RuleScheme;
}

void YWParser::SchemeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScheme(this);
}

void YWParser::SchemeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScheme(this);
}

YWParser::SchemeContext* YWParser::scheme() {
  SchemeContext *_localctx = _tracker.createInstance<SchemeContext>(_ctx, getState());
  enterRule(_localctx, 60, YWParser::RuleScheme);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    _la = _input->LA(1);
    if (!(_la == YWParser::T__12

    || _la == YWParser::T__13)) {
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

//----------------- DescriptionContext ------------------------------------------------------------------

YWParser::DescriptionContext::DescriptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::DescriptionContext::ID() {
  return getToken(YWParser::ID, 0);
}


size_t YWParser::DescriptionContext::getRuleIndex() const {
  return YWParser::RuleDescription;
}

void YWParser::DescriptionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDescription(this);
}

void YWParser::DescriptionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDescription(this);
}

YWParser::DescriptionContext* YWParser::description() {
  DescriptionContext *_localctx = _tracker.createInstance<DescriptionContext>(_ctx, getState());
  enterRule(_localctx, 62, YWParser::RuleDescription);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(YWParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> YWParser::_decisionToDFA;
atn::PredictionContextCache YWParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN YWParser::_atn;
std::vector<uint16_t> YWParser::_serializedATN;

std::vector<std::string> YWParser::_ruleNames = {
  "script", "block", "blockAttribute", "portAttribute", "beginTag", "endTag", 
  "descTag", "portTag", "aliasTag", "callTag", "uriTag", "fileTag", "resourceTag", 
  "inputPortKeyword", "outputPortKeyword", "asKeyword", "beginKeyword", 
  "callKeyword", "descKeyword", "endKeyword", "fileKeyword", "inKeyword", 
  "outKeyword", "paramKeyword", "returnKeyword", "uriKeyword", "blockName", 
  "portName", "dataName", "uriTemplate", "scheme", "description"
};

std::vector<std::string> YWParser::_literalNames = {
  "", "'@as'", "'@begin'", "'@call'", "'@desc'", "'@end'", "'@file'", "'@in'", 
  "'@out'", "'@param'", "'@return'", "'@uri'", "':'", "'file'", "'http'"
};

std::vector<std::string> YWParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ID", "PATH_TEMPLATE", 
  "HS", "NL", "WS", "SP"
};

dfa::Vocabulary YWParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> YWParser::_tokenNames;

YWParser::Initializer::Initializer() {
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
    0x3, 0x16, 0xfe, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 
    0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 
    0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 
    0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x3, 0x2, 0x7, 
    0x2, 0x44, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x47, 0xb, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x7, 0x3, 0x4b, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x4e, 0xb, 0x3, 0x3, 
    0x3, 0x7, 0x3, 0x51, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x54, 0xb, 0x3, 0x3, 
    0x3, 0x7, 0x3, 0x57, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x5a, 0xb, 0x3, 0x3, 
    0x3, 0x7, 0x3, 0x5d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x60, 0xb, 0x3, 0x3, 
    0x3, 0x7, 0x3, 0x63, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x66, 0xb, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x6d, 0xa, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x72, 0xa, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x6, 0x6, 0x76, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x77, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x7e, 0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 
    0x7f, 0x3, 0x7, 0x5, 0x7, 0x83, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x6, 0x8, 
    0x87, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x88, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0x8f, 0xa, 0x9, 0x3, 0x9, 0x6, 0x9, 0x92, 0xa, 0x9, 
    0xd, 0x9, 0xe, 0x9, 0x93, 0x3, 0x9, 0x3, 0x9, 0x6, 0x9, 0x98, 0xa, 0x9, 
    0xd, 0x9, 0xe, 0x9, 0x99, 0x3, 0x9, 0x7, 0x9, 0x9d, 0xa, 0x9, 0xc, 0x9, 
    0xe, 0x9, 0xa0, 0xb, 0x9, 0x5, 0x9, 0xa2, 0xa, 0x9, 0x6, 0x9, 0xa4, 
    0xa, 0x9, 0xd, 0x9, 0xe, 0x9, 0xa5, 0x3, 0xa, 0x3, 0xa, 0x6, 0xa, 0xaa, 
    0xa, 0xa, 0xd, 0xa, 0xe, 0xa, 0xab, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x6, 0xb, 0xb2, 0xa, 0xb, 0xd, 0xb, 0xe, 0xb, 0xb3, 0x3, 0xb, 0x6, 
    0xb, 0xb7, 0xa, 0xb, 0xd, 0xb, 0xe, 0xb, 0xb8, 0x3, 0xc, 0x3, 0xc, 0x6, 
    0xc, 0xbd, 0xa, 0xc, 0xd, 0xc, 0xe, 0xc, 0xbe, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x6, 0xd, 0xc5, 0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0xc6, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xcd, 0xa, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x5, 0xf, 0xd1, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0xd5, 0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x5, 0x1f, 0xf6, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x2, 0x2, 0x22, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x40, 0x2, 0x3, 0x3, 0x2, 0xf, 0x10, 0x2, 0xfa, 0x2, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x4, 0x48, 0x3, 0x2, 0x2, 0x2, 0x6, 0x6c, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x71, 0x3, 0x2, 0x2, 0x2, 0xa, 0x73, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x7b, 0x3, 0x2, 0x2, 0x2, 0xe, 0x84, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x12, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xaf, 0x3, 0x2, 0x2, 0x2, 0x16, 0xba, 0x3, 0x2, 0x2, 0x2, 0x18, 0xc2, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xcc, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x20, 0xd6, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xd8, 0x3, 0x2, 0x2, 0x2, 0x24, 0xda, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x28, 0xde, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xe2, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0x30, 0xe6, 0x3, 0x2, 0x2, 0x2, 0x32, 0xe8, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0xea, 0x3, 0x2, 0x2, 0x2, 0x36, 0xec, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0xee, 0x3, 0x2, 0x2, 0x2, 0x3a, 0xf0, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x3e, 0xf9, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x42, 0x44, 0x5, 0x4, 0x3, 0x2, 
    0x43, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x47, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x3, 0x2, 0x2, 0x2, 0x46, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4c, 0x5, 
    0xa, 0x6, 0x2, 0x49, 0x4b, 0x7, 0x15, 0x2, 0x2, 0x4a, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x52, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x5, 0x6, 0x4, 0x2, 0x50, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x54, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x3, 0x2, 0x2, 0x2, 0x53, 0x58, 0x3, 
    0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x55, 0x57, 0x7, 0x15, 
    0x2, 0x2, 0x56, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5b, 
    0x5d, 0x5, 0x4, 0x3, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 
    0x2, 0x2, 0x2, 0x5f, 0x64, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0x61, 0x63, 0x7, 0x15, 0x2, 0x2, 0x62, 0x61, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 0x67, 0x3, 0x2, 0x2, 0x2, 0x66, 
    0x64, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x5, 0xc, 0x7, 0x2, 0x68, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6d, 0x5, 0xe, 0x8, 0x2, 0x6a, 0x6d, 0x5, 
    0x10, 0x9, 0x2, 0x6b, 0x6d, 0x5, 0x14, 0xb, 0x2, 0x6c, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x6d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x72, 0x5, 0xe, 0x8, 0x2, 
    0x6f, 0x72, 0x5, 0x12, 0xa, 0x2, 0x70, 0x72, 0x5, 0x1a, 0xe, 0x2, 0x71, 
    0x6e, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x70, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x9, 0x3, 0x2, 0x2, 0x2, 0x73, 0x75, 0x5, 
    0x22, 0x12, 0x2, 0x74, 0x76, 0x7, 0x13, 0x2, 0x2, 0x75, 0x74, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x79, 0x7a, 0x5, 0x36, 0x1c, 0x2, 0x7a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7b, 
    0x7d, 0x5, 0x28, 0x15, 0x2, 0x7c, 0x7e, 0x7, 0x13, 0x2, 0x2, 0x7d, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 
    0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x83, 0x5, 0x36, 0x1c, 0x2, 0x82, 0x81, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x86, 0x5, 0x26, 0x14, 0x2, 0x85, 0x87, 0x7, 0x13, 0x2, 0x2, 0x86, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x8b, 0x5, 0x40, 0x21, 0x2, 0x8b, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x8c, 0x8f, 0x5, 0x1c, 0xf, 0x2, 0x8d, 0x8f, 0x5, 0x1e, 0x10, 
    0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x8f, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x90, 0x92, 0x7, 0x13, 0x2, 0x2, 0x91, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x91, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 
    0x2, 0x2, 0x2, 0x95, 0xa1, 0x5, 0x38, 0x1d, 0x2, 0x96, 0x98, 0x7, 0x13, 
    0x2, 0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9d, 0x5, 0x8, 0x5, 0x2, 0x9c, 
    0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa1, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0xa3, 0x91, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 
    0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa9, 0x5, 0x20, 0x11, 0x2, 0xa8, 0xaa, 
    0x7, 0x13, 0x2, 0x2, 0xa9, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 
    0x2, 0x2, 0x2, 0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 
    0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x5, 0x3a, 0x1e, 
    0x2, 0xae, 0x13, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb1, 0x5, 0x24, 0x13, 0x2, 
    0xb0, 0xb2, 0x7, 0x13, 0x2, 0x2, 0xb1, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb2, 
    0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xb4, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb7, 0x5, 
    0x36, 0x1c, 0x2, 0xb6, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 
    0x2, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0xb9, 0x15, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbc, 0x5, 0x34, 0x1b, 0x2, 
    0xbb, 0xbd, 0x7, 0x13, 0x2, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 
    0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x5, 
    0x3c, 0x1f, 0x2, 0xc1, 0x17, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc4, 0x5, 0x2a, 
    0x16, 0x2, 0xc3, 0xc5, 0x7, 0x13, 0x2, 0x2, 0xc4, 0xc3, 0x3, 0x2, 0x2, 
    0x2, 0xc5, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 
    0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 
    0xc9, 0x7, 0x12, 0x2, 0x2, 0xc9, 0x19, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcd, 
    0x5, 0x16, 0xc, 0x2, 0xcb, 0xcd, 0x5, 0x18, 0xd, 0x2, 0xcc, 0xca, 0x3, 
    0x2, 0x2, 0x2, 0xcc, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0xce, 0xd1, 0x5, 0x2c, 0x17, 0x2, 0xcf, 0xd1, 0x5, 0x30, 0x19, 
    0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xcf, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd5, 0x5, 0x2e, 0x18, 0x2, 0xd3, 
    0xd5, 0x5, 0x32, 0x1a, 0x2, 0xd4, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd3, 
    0x3, 0x2, 0x2, 0x2, 0xd5, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0x7, 
    0x3, 0x2, 0x2, 0xd7, 0x21, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x4, 
    0x2, 0x2, 0xd9, 0x23, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x5, 0x2, 
    0x2, 0xdb, 0x25, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x7, 0x6, 0x2, 0x2, 
    0xdd, 0x27, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x7, 0x2, 0x2, 0xdf, 
    0x29, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x8, 0x2, 0x2, 0xe1, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x9, 0x2, 0x2, 0xe3, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0xa, 0x2, 0x2, 0xe5, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0xe7, 0x7, 0xb, 0x2, 0x2, 0xe7, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0xe9, 0x7, 0xc, 0x2, 0x2, 0xe9, 0x33, 0x3, 0x2, 0x2, 0x2, 
    0xea, 0xeb, 0x7, 0xd, 0x2, 0x2, 0xeb, 0x35, 0x3, 0x2, 0x2, 0x2, 0xec, 
    0xed, 0x7, 0x11, 0x2, 0x2, 0xed, 0x37, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 
    0x7, 0x11, 0x2, 0x2, 0xef, 0x39, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x7, 
    0x11, 0x2, 0x2, 0xf1, 0x3b, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x3e, 
    0x20, 0x2, 0xf3, 0xf4, 0x7, 0xe, 0x2, 0x2, 0xf4, 0xf6, 0x3, 0x2, 0x2, 
    0x2, 0xf5, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 0x2, 0x2, 
    0xf6, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x7, 0x12, 0x2, 0x2, 0xf8, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x9, 0x2, 0x2, 0x2, 0xfa, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x11, 0x2, 0x2, 0xfc, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x1d, 0x45, 0x4c, 0x52, 0x58, 0x5e, 0x64, 0x6c, 0x71, 
    0x77, 0x7f, 0x82, 0x88, 0x8e, 0x93, 0x99, 0x9e, 0xa1, 0xa5, 0xab, 0xb3, 
    0xb8, 0xbe, 0xc6, 0xcc, 0xd0, 0xd4, 0xf5, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

YWParser::Initializer YWParser::_init;
