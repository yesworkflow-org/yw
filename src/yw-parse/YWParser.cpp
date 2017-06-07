
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
    setState(63); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(62);
      block();
      setState(65); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::T__1

    || _la == YWParser::EOL);
   
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

YWParser::BeginContext* YWParser::BlockContext::begin() {
  return getRuleContext<YWParser::BeginContext>(0);
}

YWParser::EndContext* YWParser::BlockContext::end() {
  return getRuleContext<YWParser::EndContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::BlockContext::EOL() {
  return getTokens(YWParser::EOL);
}

tree::TerminalNode* YWParser::BlockContext::EOL(size_t i) {
  return getToken(YWParser::EOL, i);
}

std::vector<YWParser::BlockContext *> YWParser::BlockContext::block() {
  return getRuleContexts<YWParser::BlockContext>();
}

YWParser::BlockContext* YWParser::BlockContext::block(size_t i) {
  return getRuleContext<YWParser::BlockContext>(i);
}

std::vector<YWParser::BlockAnnotationContext *> YWParser::BlockContext::blockAnnotation() {
  return getRuleContexts<YWParser::BlockAnnotationContext>();
}

YWParser::BlockAnnotationContext* YWParser::BlockContext::blockAnnotation(size_t i) {
  return getRuleContext<YWParser::BlockAnnotationContext>(i);
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
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YWParser::EOL) {
      setState(67);
      match(YWParser::EOL);
      setState(72);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(73);
    begin();
    setState(77);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(74);
        match(YWParser::EOL); 
      }
      setState(79);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(84);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YWParser::T__1)
      | (1ULL << YWParser::T__2)
      | (1ULL << YWParser::T__5)
      | (1ULL << YWParser::T__6)
      | (1ULL << YWParser::T__7)
      | (1ULL << YWParser::T__8)
      | (1ULL << YWParser::EOL))) != 0)) {
      setState(82);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case YWParser::T__1:
        case YWParser::EOL: {
          setState(80);
          block();
          break;
        }

        case YWParser::T__2:
        case YWParser::T__5:
        case YWParser::T__6:
        case YWParser::T__7:
        case YWParser::T__8: {
          setState(81);
          blockAnnotation();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(86);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(87);
    end();
    setState(91);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(88);
        match(YWParser::EOL); 
      }
      setState(93);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockAnnotationContext ------------------------------------------------------------------

YWParser::BlockAnnotationContext::BlockAnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::InputPortContext* YWParser::BlockAnnotationContext::inputPort() {
  return getRuleContext<YWParser::InputPortContext>(0);
}

YWParser::OutputPortContext* YWParser::BlockAnnotationContext::outputPort() {
  return getRuleContext<YWParser::OutputPortContext>(0);
}

YWParser::CallContext* YWParser::BlockAnnotationContext::call() {
  return getRuleContext<YWParser::CallContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::BlockAnnotationContext::EOL() {
  return getTokens(YWParser::EOL);
}

tree::TerminalNode* YWParser::BlockAnnotationContext::EOL(size_t i) {
  return getToken(YWParser::EOL, i);
}


size_t YWParser::BlockAnnotationContext::getRuleIndex() const {
  return YWParser::RuleBlockAnnotation;
}

void YWParser::BlockAnnotationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockAnnotation(this);
}

void YWParser::BlockAnnotationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockAnnotation(this);
}

YWParser::BlockAnnotationContext* YWParser::blockAnnotation() {
  BlockAnnotationContext *_localctx = _tracker.createInstance<BlockAnnotationContext>(_ctx, getState());
  enterRule(_localctx, 4, YWParser::RuleBlockAnnotation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(97);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__5:
      case YWParser::T__7: {
        setState(94);
        inputPort();
        break;
      }

      case YWParser::T__6:
      case YWParser::T__8: {
        setState(95);
        outputPort();
        break;
      }

      case YWParser::T__2: {
        setState(96);
        call();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(102);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(99);
        match(YWParser::EOL); 
      }
      setState(104);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InputPortContext ------------------------------------------------------------------

YWParser::InputPortContext::InputPortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::InContext* YWParser::InputPortContext::in() {
  return getRuleContext<YWParser::InContext>(0);
}

YWParser::ParamContext* YWParser::InputPortContext::param() {
  return getRuleContext<YWParser::ParamContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::InputPortContext::EOL() {
  return getTokens(YWParser::EOL);
}

tree::TerminalNode* YWParser::InputPortContext::EOL(size_t i) {
  return getToken(YWParser::EOL, i);
}

std::vector<YWParser::PortAnnotationContext *> YWParser::InputPortContext::portAnnotation() {
  return getRuleContexts<YWParser::PortAnnotationContext>();
}

YWParser::PortAnnotationContext* YWParser::InputPortContext::portAnnotation(size_t i) {
  return getRuleContext<YWParser::PortAnnotationContext>(i);
}


size_t YWParser::InputPortContext::getRuleIndex() const {
  return YWParser::RuleInputPort;
}

void YWParser::InputPortContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInputPort(this);
}

void YWParser::InputPortContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInputPort(this);
}

YWParser::InputPortContext* YWParser::inputPort() {
  InputPortContext *_localctx = _tracker.createInstance<InputPortContext>(_ctx, getState());
  enterRule(_localctx, 6, YWParser::RuleInputPort);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(107);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__5: {
        setState(105);
        in();
        break;
      }

      case YWParser::T__7: {
        setState(106);
        param();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(112);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(109);
        match(YWParser::EOL); 
      }
      setState(114);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    }
    setState(118);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YWParser::T__0

    || _la == YWParser::T__9) {
      setState(115);
      portAnnotation();
      setState(120);
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

//----------------- OutputPortContext ------------------------------------------------------------------

YWParser::OutputPortContext::OutputPortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::OutContext* YWParser::OutputPortContext::out() {
  return getRuleContext<YWParser::OutContext>(0);
}

YWParser::RetContext* YWParser::OutputPortContext::ret() {
  return getRuleContext<YWParser::RetContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::OutputPortContext::EOL() {
  return getTokens(YWParser::EOL);
}

tree::TerminalNode* YWParser::OutputPortContext::EOL(size_t i) {
  return getToken(YWParser::EOL, i);
}

std::vector<YWParser::PortAnnotationContext *> YWParser::OutputPortContext::portAnnotation() {
  return getRuleContexts<YWParser::PortAnnotationContext>();
}

YWParser::PortAnnotationContext* YWParser::OutputPortContext::portAnnotation(size_t i) {
  return getRuleContext<YWParser::PortAnnotationContext>(i);
}


size_t YWParser::OutputPortContext::getRuleIndex() const {
  return YWParser::RuleOutputPort;
}

void YWParser::OutputPortContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOutputPort(this);
}

void YWParser::OutputPortContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOutputPort(this);
}

YWParser::OutputPortContext* YWParser::outputPort() {
  OutputPortContext *_localctx = _tracker.createInstance<OutputPortContext>(_ctx, getState());
  enterRule(_localctx, 8, YWParser::RuleOutputPort);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(123);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__6: {
        setState(121);
        out();
        break;
      }

      case YWParser::T__8: {
        setState(122);
        ret();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(128);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(125);
        match(YWParser::EOL); 
      }
      setState(130);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
    setState(134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YWParser::T__0

    || _la == YWParser::T__9) {
      setState(131);
      portAnnotation();
      setState(136);
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

//----------------- PortAnnotationContext ------------------------------------------------------------------

YWParser::PortAnnotationContext::PortAnnotationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::AsContext* YWParser::PortAnnotationContext::as() {
  return getRuleContext<YWParser::AsContext>(0);
}

YWParser::UriContext* YWParser::PortAnnotationContext::uri() {
  return getRuleContext<YWParser::UriContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::PortAnnotationContext::EOL() {
  return getTokens(YWParser::EOL);
}

tree::TerminalNode* YWParser::PortAnnotationContext::EOL(size_t i) {
  return getToken(YWParser::EOL, i);
}


size_t YWParser::PortAnnotationContext::getRuleIndex() const {
  return YWParser::RulePortAnnotation;
}

void YWParser::PortAnnotationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortAnnotation(this);
}

void YWParser::PortAnnotationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortAnnotation(this);
}

YWParser::PortAnnotationContext* YWParser::portAnnotation() {
  PortAnnotationContext *_localctx = _tracker.createInstance<PortAnnotationContext>(_ctx, getState());
  enterRule(_localctx, 10, YWParser::RulePortAnnotation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(139);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__0: {
        setState(137);
        as();
        break;
      }

      case YWParser::T__9: {
        setState(138);
        uri();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(144);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(141);
        match(YWParser::EOL); 
      }
      setState(146);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AsContext ------------------------------------------------------------------

YWParser::AsContext::AsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::AsKeywordContext* YWParser::AsContext::asKeyword() {
  return getRuleContext<YWParser::AsKeywordContext>(0);
}

YWParser::AliasContext* YWParser::AsContext::alias() {
  return getRuleContext<YWParser::AliasContext>(0);
}


size_t YWParser::AsContext::getRuleIndex() const {
  return YWParser::RuleAs;
}

void YWParser::AsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAs(this);
}

void YWParser::AsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAs(this);
}

YWParser::AsContext* YWParser::as() {
  AsContext *_localctx = _tracker.createInstance<AsContext>(_ctx, getState());
  enterRule(_localctx, 12, YWParser::RuleAs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
    asKeyword();
    setState(148);
    alias();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BeginContext ------------------------------------------------------------------

YWParser::BeginContext::BeginContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::BeginKeywordContext* YWParser::BeginContext::beginKeyword() {
  return getRuleContext<YWParser::BeginKeywordContext>(0);
}

YWParser::BlockNameContext* YWParser::BeginContext::blockName() {
  return getRuleContext<YWParser::BlockNameContext>(0);
}


size_t YWParser::BeginContext::getRuleIndex() const {
  return YWParser::RuleBegin;
}

void YWParser::BeginContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBegin(this);
}

void YWParser::BeginContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBegin(this);
}

YWParser::BeginContext* YWParser::begin() {
  BeginContext *_localctx = _tracker.createInstance<BeginContext>(_ctx, getState());
  enterRule(_localctx, 14, YWParser::RuleBegin);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    beginKeyword();
    setState(151);
    blockName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallContext ------------------------------------------------------------------

YWParser::CallContext::CallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::CallKeywordContext* YWParser::CallContext::callKeyword() {
  return getRuleContext<YWParser::CallKeywordContext>(0);
}

YWParser::BlockNameContext* YWParser::CallContext::blockName() {
  return getRuleContext<YWParser::BlockNameContext>(0);
}


size_t YWParser::CallContext::getRuleIndex() const {
  return YWParser::RuleCall;
}

void YWParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}

void YWParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}

YWParser::CallContext* YWParser::call() {
  CallContext *_localctx = _tracker.createInstance<CallContext>(_ctx, getState());
  enterRule(_localctx, 16, YWParser::RuleCall);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    callKeyword();
    setState(154);
    blockName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EndContext ------------------------------------------------------------------

YWParser::EndContext::EndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::EndKeywordContext* YWParser::EndContext::endKeyword() {
  return getRuleContext<YWParser::EndKeywordContext>(0);
}

YWParser::BlockNameContext* YWParser::EndContext::blockName() {
  return getRuleContext<YWParser::BlockNameContext>(0);
}


size_t YWParser::EndContext::getRuleIndex() const {
  return YWParser::RuleEnd;
}

void YWParser::EndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnd(this);
}

void YWParser::EndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnd(this);
}

YWParser::EndContext* YWParser::end() {
  EndContext *_localctx = _tracker.createInstance<EndContext>(_ctx, getState());
  enterRule(_localctx, 18, YWParser::RuleEnd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    endKeyword();
    setState(157);
    blockName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FileContext ------------------------------------------------------------------

YWParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::FileKeywordContext* YWParser::FileContext::fileKeyword() {
  return getRuleContext<YWParser::FileKeywordContext>(0);
}

tree::TerminalNode* YWParser::FileContext::PATH_TEMPLATE() {
  return getToken(YWParser::PATH_TEMPLATE, 0);
}


size_t YWParser::FileContext::getRuleIndex() const {
  return YWParser::RuleFile;
}

void YWParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void YWParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

YWParser::FileContext* YWParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 20, YWParser::RuleFile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    fileKeyword();
    setState(160);
    match(YWParser::PATH_TEMPLATE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InContext ------------------------------------------------------------------

YWParser::InContext::InContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::InKeywordContext* YWParser::InContext::inKeyword() {
  return getRuleContext<YWParser::InKeywordContext>(0);
}

YWParser::VariableNameContext* YWParser::InContext::variableName() {
  return getRuleContext<YWParser::VariableNameContext>(0);
}


size_t YWParser::InContext::getRuleIndex() const {
  return YWParser::RuleIn;
}

void YWParser::InContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIn(this);
}

void YWParser::InContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIn(this);
}

YWParser::InContext* YWParser::in() {
  InContext *_localctx = _tracker.createInstance<InContext>(_ctx, getState());
  enterRule(_localctx, 22, YWParser::RuleIn);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(162);
    inKeyword();
    setState(163);
    variableName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OutContext ------------------------------------------------------------------

YWParser::OutContext::OutContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::OutKeywordContext* YWParser::OutContext::outKeyword() {
  return getRuleContext<YWParser::OutKeywordContext>(0);
}

YWParser::VariableNameContext* YWParser::OutContext::variableName() {
  return getRuleContext<YWParser::VariableNameContext>(0);
}


size_t YWParser::OutContext::getRuleIndex() const {
  return YWParser::RuleOut;
}

void YWParser::OutContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOut(this);
}

void YWParser::OutContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOut(this);
}

YWParser::OutContext* YWParser::out() {
  OutContext *_localctx = _tracker.createInstance<OutContext>(_ctx, getState());
  enterRule(_localctx, 24, YWParser::RuleOut);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    outKeyword();
    setState(166);
    variableName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

YWParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::ParamKeywordContext* YWParser::ParamContext::paramKeyword() {
  return getRuleContext<YWParser::ParamKeywordContext>(0);
}

YWParser::VariableNameContext* YWParser::ParamContext::variableName() {
  return getRuleContext<YWParser::VariableNameContext>(0);
}


size_t YWParser::ParamContext::getRuleIndex() const {
  return YWParser::RuleParam;
}

void YWParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void YWParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}

YWParser::ParamContext* YWParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 26, YWParser::RuleParam);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    paramKeyword();
    setState(169);
    variableName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RetContext ------------------------------------------------------------------

YWParser::RetContext::RetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::ReturnKeywordContext* YWParser::RetContext::returnKeyword() {
  return getRuleContext<YWParser::ReturnKeywordContext>(0);
}

YWParser::VariableNameContext* YWParser::RetContext::variableName() {
  return getRuleContext<YWParser::VariableNameContext>(0);
}


size_t YWParser::RetContext::getRuleIndex() const {
  return YWParser::RuleRet;
}

void YWParser::RetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRet(this);
}

void YWParser::RetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRet(this);
}

YWParser::RetContext* YWParser::ret() {
  RetContext *_localctx = _tracker.createInstance<RetContext>(_ctx, getState());
  enterRule(_localctx, 28, YWParser::RuleRet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    returnKeyword();
    setState(172);
    variableName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UriContext ------------------------------------------------------------------

YWParser::UriContext::UriContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::UriKeywordContext* YWParser::UriContext::uriKeyword() {
  return getRuleContext<YWParser::UriKeywordContext>(0);
}

YWParser::UriTemplateContext* YWParser::UriContext::uriTemplate() {
  return getRuleContext<YWParser::UriTemplateContext>(0);
}


size_t YWParser::UriContext::getRuleIndex() const {
  return YWParser::RuleUri;
}

void YWParser::UriContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUri(this);
}

void YWParser::UriContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUri(this);
}

YWParser::UriContext* YWParser::uri() {
  UriContext *_localctx = _tracker.createInstance<UriContext>(_ctx, getState());
  enterRule(_localctx, 30, YWParser::RuleUri);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    uriKeyword();
    setState(175);
    uriTemplate();
   
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
  enterRule(_localctx, 32, YWParser::RuleAsKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
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
  enterRule(_localctx, 34, YWParser::RuleBeginKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
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
  enterRule(_localctx, 36, YWParser::RuleCallKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(YWParser::T__2);
   
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
    setState(183);
    match(YWParser::T__3);
   
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
    setState(185);
    match(YWParser::T__4);
   
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
    setState(187);
    match(YWParser::T__5);
   
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
    setState(189);
    match(YWParser::T__6);
   
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
    setState(191);
    match(YWParser::T__7);
   
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
    setState(193);
    match(YWParser::T__8);
   
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
    setState(195);
    match(YWParser::T__9);
   
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
    setState(197);
    match(YWParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableNameContext ------------------------------------------------------------------

YWParser::VariableNameContext::VariableNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::VariableNameContext::ID() {
  return getToken(YWParser::ID, 0);
}


size_t YWParser::VariableNameContext::getRuleIndex() const {
  return YWParser::RuleVariableName;
}

void YWParser::VariableNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableName(this);
}

void YWParser::VariableNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableName(this);
}

YWParser::VariableNameContext* YWParser::variableName() {
  VariableNameContext *_localctx = _tracker.createInstance<VariableNameContext>(_ctx, getState());
  enterRule(_localctx, 54, YWParser::RuleVariableName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(YWParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AliasContext ------------------------------------------------------------------

YWParser::AliasContext::AliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::AliasContext::ID() {
  return getToken(YWParser::ID, 0);
}


size_t YWParser::AliasContext::getRuleIndex() const {
  return YWParser::RuleAlias;
}

void YWParser::AliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlias(this);
}

void YWParser::AliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlias(this);
}

YWParser::AliasContext* YWParser::alias() {
  AliasContext *_localctx = _tracker.createInstance<AliasContext>(_ctx, getState());
  enterRule(_localctx, 56, YWParser::RuleAlias);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
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
    setState(206);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YWParser::T__11

    || _la == YWParser::T__12) {
      setState(203);
      scheme();
      setState(204);
      match(YWParser::T__10);
    }
    setState(208);
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
    setState(210);
    _la = _input->LA(1);
    if (!(_la == YWParser::T__11

    || _la == YWParser::T__12)) {
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

// Static vars and initialization.
std::vector<dfa::DFA> YWParser::_decisionToDFA;
atn::PredictionContextCache YWParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN YWParser::_atn;
std::vector<uint16_t> YWParser::_serializedATN;

std::vector<std::string> YWParser::_ruleNames = {
  "script", "block", "blockAnnotation", "inputPort", "outputPort", "portAnnotation", 
  "as", "begin", "call", "end", "file", "in", "out", "param", "ret", "uri", 
  "asKeyword", "beginKeyword", "callKeyword", "endKeyword", "fileKeyword", 
  "inKeyword", "outKeyword", "paramKeyword", "returnKeyword", "uriKeyword", 
  "blockName", "variableName", "alias", "uriTemplate", "scheme"
};

std::vector<std::string> YWParser::_literalNames = {
  "", "'@as'", "'@begin'", "'@call'", "'@end'", "'@file'", "'@in'", "'@out'", 
  "'@param'", "'@return'", "'@uri'", "':'", "'file'", "'http'"
};

std::vector<std::string> YWParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ID", "PATH_TEMPLATE", 
  "EOL", "WS"
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
    0x3, 0x13, 0xd7, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 
    0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 
    0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 
    0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x3, 0x2, 0x6, 0x2, 0x42, 0xa, 0x2, 
    0xd, 0x2, 0xe, 0x2, 0x43, 0x3, 0x3, 0x7, 0x3, 0x47, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x4a, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x4e, 0xa, 0x3, 
    0xc, 0x3, 0xe, 0x3, 0x51, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x55, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x58, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 
    0x3, 0x5c, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x5f, 0xb, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x64, 0xa, 0x4, 0x3, 0x4, 0x7, 0x4, 0x67, 0xa, 
    0x4, 0xc, 0x4, 0xe, 0x4, 0x6a, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x6e, 0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 0x71, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x74, 0xb, 0x5, 0x3, 0x5, 0x7, 0x5, 0x77, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0x7a, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x7e, 0xa, 0x6, 0x3, 0x6, 
    0x7, 0x6, 0x81, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x84, 0xb, 0x6, 0x3, 0x6, 
    0x7, 0x6, 0x87, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x8a, 0xb, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0x8e, 0xa, 0x7, 0x3, 0x7, 0x7, 0x7, 0x91, 0xa, 0x7, 
    0xc, 0x7, 0xe, 0x7, 0x94, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0xd1, 0xa, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x2, 0x2, 0x21, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x3e, 0x2, 0x3, 0x3, 0x2, 0xe, 0xf, 0x2, 0xc9, 0x2, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x48, 0x3, 0x2, 0x2, 0x2, 0x6, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x6d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xe, 0x95, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x98, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x14, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x18, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xaa, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0xad, 0x3, 0x2, 0x2, 0x2, 0x20, 0xb0, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0xb3, 0x3, 0x2, 0x2, 0x2, 0x24, 0xb5, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x28, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0xbb, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xbf, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x32, 0xc3, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x36, 0xc7, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x3a, 0xcb, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0xd0, 0x3, 0x2, 0x2, 0x2, 0x3e, 0xd4, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x42, 0x5, 0x4, 0x3, 0x2, 0x41, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x3, 0x3, 0x2, 0x2, 0x2, 0x45, 0x47, 0x7, 
    0x12, 0x2, 0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x4f, 0x5, 0x10, 0x9, 0x2, 0x4c, 0x4e, 0x7, 0x12, 0x2, 0x2, 0x4d, 
    0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x56, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x55, 0x5, 0x4, 
    0x3, 0x2, 0x53, 0x55, 0x5, 0x6, 0x4, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5d, 
    0x5, 0x14, 0xb, 0x2, 0x5a, 0x5c, 0x7, 0x12, 0x2, 0x2, 0x5b, 0x5a, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x60, 0x64, 0x5, 0x8, 0x5, 0x2, 
    0x61, 0x64, 0x5, 0xa, 0x6, 0x2, 0x62, 0x64, 0x5, 0x12, 0xa, 0x2, 0x63, 
    0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x68, 0x3, 0x2, 0x2, 0x2, 0x65, 0x67, 0x7, 
    0x12, 0x2, 0x2, 0x66, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x7, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 
    0x6b, 0x6e, 0x5, 0x18, 0xd, 0x2, 0x6c, 0x6e, 0x5, 0x1c, 0xf, 0x2, 0x6d, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x6f, 0x71, 0x7, 0x12, 0x2, 0x2, 0x70, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x74, 0x3, 0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 
    0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x75, 0x77, 0x5, 0xc, 0x7, 0x2, 
    0x76, 0x75, 0x3, 0x2, 0x2, 0x2, 0x77, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7e, 0x5, 
    0x1a, 0xe, 0x2, 0x7c, 0x7e, 0x5, 0x1e, 0x10, 0x2, 0x7d, 0x7b, 0x3, 0x2, 
    0x2, 0x2, 0x7d, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x81, 0x7, 0x12, 0x2, 0x2, 0x80, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x81, 0x84, 0x3, 0x2, 0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x88, 0x3, 0x2, 0x2, 0x2, 0x84, 0x82, 
    0x3, 0x2, 0x2, 0x2, 0x85, 0x87, 0x5, 0xc, 0x7, 0x2, 0x86, 0x85, 0x3, 
    0x2, 0x2, 0x2, 0x87, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x88, 0x86, 0x3, 0x2, 
    0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 0x2, 0x2, 0x89, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8e, 0x5, 0xe, 0x8, 0x2, 
    0x8c, 0x8e, 0x5, 0x20, 0x11, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 
    0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x92, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x91, 
    0x7, 0x12, 0x2, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x94, 0x3, 
    0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 
    0x2, 0x2, 0x93, 0xd, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x95, 0x96, 0x5, 0x22, 0x12, 0x2, 0x96, 0x97, 0x5, 0x3a, 0x1e, 
    0x2, 0x97, 0xf, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x5, 0x24, 0x13, 0x2, 
    0x99, 0x9a, 0x5, 0x36, 0x1c, 0x2, 0x9a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x9c, 0x5, 0x26, 0x14, 0x2, 0x9c, 0x9d, 0x5, 0x36, 0x1c, 0x2, 0x9d, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x5, 0x28, 0x15, 0x2, 0x9f, 0xa0, 
    0x5, 0x36, 0x1c, 0x2, 0xa0, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x5, 
    0x2a, 0x16, 0x2, 0xa2, 0xa3, 0x7, 0x11, 0x2, 0x2, 0xa3, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0xa5, 0x5, 0x2c, 0x17, 0x2, 0xa5, 0xa6, 0x5, 0x38, 0x1d, 
    0x2, 0xa6, 0x19, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x5, 0x2e, 0x18, 0x2, 
    0xa8, 0xa9, 0x5, 0x38, 0x1d, 0x2, 0xa9, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xaa, 
    0xab, 0x5, 0x30, 0x19, 0x2, 0xab, 0xac, 0x5, 0x38, 0x1d, 0x2, 0xac, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x5, 0x32, 0x1a, 0x2, 0xae, 0xaf, 
    0x5, 0x38, 0x1d, 0x2, 0xaf, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x5, 
    0x34, 0x1b, 0x2, 0xb1, 0xb2, 0x5, 0x3c, 0x1f, 0x2, 0xb2, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x3, 0x2, 0x2, 0xb4, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xb6, 0x7, 0x4, 0x2, 0x2, 0xb6, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0xb7, 0xb8, 0x7, 0x5, 0x2, 0x2, 0xb8, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0xb9, 0xba, 0x7, 0x6, 0x2, 0x2, 0xba, 0x29, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0xbc, 0x7, 0x7, 0x2, 0x2, 0xbc, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 
    0x7, 0x8, 0x2, 0x2, 0xbe, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x7, 
    0x9, 0x2, 0x2, 0xc0, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x7, 0xa, 
    0x2, 0x2, 0xc2, 0x31, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0xb, 0x2, 
    0x2, 0xc4, 0x33, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x7, 0xc, 0x2, 0x2, 
    0xc6, 0x35, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 0x7, 0x10, 0x2, 0x2, 0xc8, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x10, 0x2, 0x2, 0xca, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x10, 0x2, 0x2, 0xcc, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x3e, 0x20, 0x2, 0xce, 0xcf, 0x7, 0xd, 
    0x2, 0x2, 0xcf, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xcd, 0x3, 0x2, 0x2, 
    0x2, 0xd0, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 
    0xd2, 0xd3, 0x7, 0x11, 0x2, 0x2, 0xd3, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xd4, 
    0xd5, 0x9, 0x2, 0x2, 0x2, 0xd5, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x13, 0x43, 
    0x48, 0x4f, 0x54, 0x56, 0x5d, 0x63, 0x68, 0x6d, 0x72, 0x78, 0x7d, 0x82, 
    0x88, 0x8d, 0x92, 0xd0, 
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
