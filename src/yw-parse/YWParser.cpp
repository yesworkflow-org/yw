
// Generated from YW.g4 by ANTLR 4.7


#include "YWListener.h"

#include "YWParser.h"


using namespace antlrcpp;
using namespace yw;
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

std::vector<YWParser::WsContext *> YWParser::ScriptContext::ws() {
  return getRuleContexts<YWParser::WsContext>();
}

YWParser::WsContext* YWParser::ScriptContext::ws(size_t i) {
  return getRuleContext<YWParser::WsContext>(i);
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
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(49);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YWParser::SPACE

    || _la == YWParser::NEWLINE) {
      setState(48);
      ws();
    }
    setState(51);
    block();
    setState(57);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(52);
        ws();
        setState(53);
        block(); 
      }
      setState(59);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(61);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YWParser::SPACE

    || _la == YWParser::NEWLINE) {
      setState(60);
      ws();
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

YWParser::BeginContext* YWParser::BlockContext::begin() {
  return getRuleContext<YWParser::BeginContext>(0);
}

std::vector<YWParser::WsContext *> YWParser::BlockContext::ws() {
  return getRuleContexts<YWParser::WsContext>();
}

YWParser::WsContext* YWParser::BlockContext::ws(size_t i) {
  return getRuleContext<YWParser::WsContext>(i);
}

YWParser::EndContext* YWParser::BlockContext::end() {
  return getRuleContext<YWParser::EndContext>(0);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(63);
    begin();
    setState(69);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(64);
        ws();
        setState(65);
        blockAttribute(); 
      }
      setState(71);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
    setState(77);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(72);
        ws();
        setState(73);
        block(); 
      }
      setState(79);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(80);
    ws();
    setState(81);
    end();
   
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

YWParser::PortContext* YWParser::BlockAttributeContext::port() {
  return getRuleContext<YWParser::PortContext>(0);
}

YWParser::DescContext* YWParser::BlockAttributeContext::desc() {
  return getRuleContext<YWParser::DescContext>(0);
}

YWParser::CallContext* YWParser::BlockAttributeContext::call() {
  return getRuleContext<YWParser::CallContext>(0);
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
    setState(86);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::InKeyword:
      case YWParser::OutKeyword:
      case YWParser::ParamKeyword:
      case YWParser::ReturnKeyword: {
        enterOuterAlt(_localctx, 1);
        setState(83);
        port();
        break;
      }

      case YWParser::DescKeyword: {
        enterOuterAlt(_localctx, 2);
        setState(84);
        desc();
        break;
      }

      case YWParser::CallKeyword: {
        enterOuterAlt(_localctx, 3);
        setState(85);
        call();
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

//----------------- PortContext ------------------------------------------------------------------

YWParser::PortContext::PortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::InputKeywordContext* YWParser::PortContext::inputKeyword() {
  return getRuleContext<YWParser::InputKeywordContext>(0);
}

YWParser::OutputKeywordContext* YWParser::PortContext::outputKeyword() {
  return getRuleContext<YWParser::OutputKeywordContext>(0);
}

std::vector<YWParser::PortNameContext *> YWParser::PortContext::portName() {
  return getRuleContexts<YWParser::PortNameContext>();
}

YWParser::PortNameContext* YWParser::PortContext::portName(size_t i) {
  return getRuleContext<YWParser::PortNameContext>(i);
}

std::vector<YWParser::WsContext *> YWParser::PortContext::ws() {
  return getRuleContexts<YWParser::WsContext>();
}

YWParser::WsContext* YWParser::PortContext::ws(size_t i) {
  return getRuleContext<YWParser::WsContext>(i);
}

std::vector<YWParser::PortAttributeContext *> YWParser::PortContext::portAttribute() {
  return getRuleContexts<YWParser::PortAttributeContext>();
}

YWParser::PortAttributeContext* YWParser::PortContext::portAttribute(size_t i) {
  return getRuleContext<YWParser::PortAttributeContext>(i);
}

std::vector<tree::TerminalNode *> YWParser::PortContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::PortContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
}


size_t YWParser::PortContext::getRuleIndex() const {
  return YWParser::RulePort;
}

void YWParser::PortContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPort(this);
}

void YWParser::PortContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPort(this);
}

YWParser::PortContext* YWParser::port() {
  PortContext *_localctx = _tracker.createInstance<PortContext>(_ctx, getState());
  enterRule(_localctx, 6, YWParser::RulePort);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(90);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::InKeyword:
      case YWParser::ParamKeyword: {
        setState(88);
        inputKeyword();
        break;
      }

      case YWParser::OutKeyword:
      case YWParser::ReturnKeyword: {
        setState(89);
        outputKeyword();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(98); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(93); 
              _errHandler->sync(this);
              _la = _input->LA(1);
              do {
                setState(92);
                match(YWParser::SPACE);
                setState(95); 
                _errHandler->sync(this);
                _la = _input->LA(1);
              } while (_la == YWParser::SPACE);
              setState(97);
              portName();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(100); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(107);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(102);
        ws();
        setState(103);
        portAttribute(); 
      }
      setState(109);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx);
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

YWParser::DescContext* YWParser::PortAttributeContext::desc() {
  return getRuleContext<YWParser::DescContext>(0);
}

YWParser::AliasContext* YWParser::PortAttributeContext::alias() {
  return getRuleContext<YWParser::AliasContext>(0);
}

YWParser::ResourceContext* YWParser::PortAttributeContext::resource() {
  return getRuleContext<YWParser::ResourceContext>(0);
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
  enterRule(_localctx, 8, YWParser::RulePortAttribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(113);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::DescKeyword: {
        enterOuterAlt(_localctx, 1);
        setState(110);
        desc();
        break;
      }

      case YWParser::AsKeyword: {
        enterOuterAlt(_localctx, 2);
        setState(111);
        alias();
        break;
      }

      case YWParser::FileKeyword:
      case YWParser::UriKeyword: {
        enterOuterAlt(_localctx, 3);
        setState(112);
        resource();
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

//----------------- BeginContext ------------------------------------------------------------------

YWParser::BeginContext::BeginContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::BeginContext::BeginKeyword() {
  return getToken(YWParser::BeginKeyword, 0);
}

YWParser::BlockNameContext* YWParser::BeginContext::blockName() {
  return getRuleContext<YWParser::BlockNameContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::BeginContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::BeginContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
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
  enterRule(_localctx, 10, YWParser::RuleBegin);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(YWParser::BeginKeyword);
    setState(117); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(116);
      match(YWParser::SPACE);
      setState(119); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::SPACE);
    setState(121);
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

tree::TerminalNode* YWParser::EndContext::EndKeyword() {
  return getToken(YWParser::EndKeyword, 0);
}

YWParser::BlockNameContext* YWParser::EndContext::blockName() {
  return getRuleContext<YWParser::BlockNameContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::EndContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::EndContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
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
  enterRule(_localctx, 12, YWParser::RuleEnd);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(YWParser::EndKeyword);
    setState(130);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(125); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(124);
        match(YWParser::SPACE);
        setState(127); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == YWParser::SPACE);

      setState(129);
      blockName();
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

//----------------- DescContext ------------------------------------------------------------------

YWParser::DescContext::DescContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::DescContext::DescKeyword() {
  return getToken(YWParser::DescKeyword, 0);
}

YWParser::DescriptionContext* YWParser::DescContext::description() {
  return getRuleContext<YWParser::DescriptionContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::DescContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::DescContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
}


size_t YWParser::DescContext::getRuleIndex() const {
  return YWParser::RuleDesc;
}

void YWParser::DescContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDesc(this);
}

void YWParser::DescContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDesc(this);
}

YWParser::DescContext* YWParser::desc() {
  DescContext *_localctx = _tracker.createInstance<DescContext>(_ctx, getState());
  enterRule(_localctx, 14, YWParser::RuleDesc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    match(YWParser::DescKeyword);
    setState(134); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(133);
      match(YWParser::SPACE);
      setState(136); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::SPACE);
    setState(138);
    description();
   
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

tree::TerminalNode* YWParser::AliasContext::AsKeyword() {
  return getToken(YWParser::AsKeyword, 0);
}

YWParser::DataNameContext* YWParser::AliasContext::dataName() {
  return getRuleContext<YWParser::DataNameContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::AliasContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::AliasContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
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
  enterRule(_localctx, 16, YWParser::RuleAlias);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    match(YWParser::AsKeyword);
    setState(142); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(141);
      match(YWParser::SPACE);
      setState(144); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::SPACE);
    setState(146);
    dataName();
   
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

tree::TerminalNode* YWParser::CallContext::CallKeyword() {
  return getToken(YWParser::CallKeyword, 0);
}

std::vector<tree::TerminalNode *> YWParser::CallContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::CallContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
}

std::vector<YWParser::BlockNameContext *> YWParser::CallContext::blockName() {
  return getRuleContexts<YWParser::BlockNameContext>();
}

YWParser::BlockNameContext* YWParser::CallContext::blockName(size_t i) {
  return getRuleContext<YWParser::BlockNameContext>(i);
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
  enterRule(_localctx, 18, YWParser::RuleCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    match(YWParser::CallKeyword);
    setState(150); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(149);
      match(YWParser::SPACE);
      setState(152); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::SPACE);
    setState(155); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(154);
      blockName();
      setState(157); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::Word);
   
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

tree::TerminalNode* YWParser::UriContext::UriKeyword() {
  return getToken(YWParser::UriKeyword, 0);
}

YWParser::UriTemplateContext* YWParser::UriContext::uriTemplate() {
  return getRuleContext<YWParser::UriTemplateContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::UriContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::UriContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
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
  enterRule(_localctx, 20, YWParser::RuleUri);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(YWParser::UriKeyword);
    setState(161); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(160);
      match(YWParser::SPACE);
      setState(163); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::SPACE);
    setState(165);
    uriTemplate();
   
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

tree::TerminalNode* YWParser::FileContext::FileKeyword() {
  return getToken(YWParser::FileKeyword, 0);
}

YWParser::PathTemplateContext* YWParser::FileContext::pathTemplate() {
  return getRuleContext<YWParser::PathTemplateContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::FileContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::FileContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
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
  enterRule(_localctx, 22, YWParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    match(YWParser::FileKeyword);
    setState(169); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(168);
      match(YWParser::SPACE);
      setState(171); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::SPACE);
    setState(173);
    pathTemplate();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResourceContext ------------------------------------------------------------------

YWParser::ResourceContext::ResourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::UriContext* YWParser::ResourceContext::uri() {
  return getRuleContext<YWParser::UriContext>(0);
}

YWParser::FileContext* YWParser::ResourceContext::file() {
  return getRuleContext<YWParser::FileContext>(0);
}


size_t YWParser::ResourceContext::getRuleIndex() const {
  return YWParser::RuleResource;
}

void YWParser::ResourceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResource(this);
}

void YWParser::ResourceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResource(this);
}

YWParser::ResourceContext* YWParser::resource() {
  ResourceContext *_localctx = _tracker.createInstance<ResourceContext>(_ctx, getState());
  enterRule(_localctx, 24, YWParser::RuleResource);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::UriKeyword: {
        enterOuterAlt(_localctx, 1);
        setState(175);
        uri();
        break;
      }

      case YWParser::FileKeyword: {
        enterOuterAlt(_localctx, 2);
        setState(176);
        file();
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

//----------------- InputKeywordContext ------------------------------------------------------------------

YWParser::InputKeywordContext::InputKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::InputKeywordContext::InKeyword() {
  return getToken(YWParser::InKeyword, 0);
}

tree::TerminalNode* YWParser::InputKeywordContext::ParamKeyword() {
  return getToken(YWParser::ParamKeyword, 0);
}


size_t YWParser::InputKeywordContext::getRuleIndex() const {
  return YWParser::RuleInputKeyword;
}

void YWParser::InputKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInputKeyword(this);
}

void YWParser::InputKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInputKeyword(this);
}

YWParser::InputKeywordContext* YWParser::inputKeyword() {
  InputKeywordContext *_localctx = _tracker.createInstance<InputKeywordContext>(_ctx, getState());
  enterRule(_localctx, 26, YWParser::RuleInputKeyword);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    _la = _input->LA(1);
    if (!(_la == YWParser::InKeyword

    || _la == YWParser::ParamKeyword)) {
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

//----------------- OutputKeywordContext ------------------------------------------------------------------

YWParser::OutputKeywordContext::OutputKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::OutputKeywordContext::OutKeyword() {
  return getToken(YWParser::OutKeyword, 0);
}

tree::TerminalNode* YWParser::OutputKeywordContext::ReturnKeyword() {
  return getToken(YWParser::ReturnKeyword, 0);
}


size_t YWParser::OutputKeywordContext::getRuleIndex() const {
  return YWParser::RuleOutputKeyword;
}

void YWParser::OutputKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOutputKeyword(this);
}

void YWParser::OutputKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOutputKeyword(this);
}

YWParser::OutputKeywordContext* YWParser::outputKeyword() {
  OutputKeywordContext *_localctx = _tracker.createInstance<OutputKeywordContext>(_ctx, getState());
  enterRule(_localctx, 28, YWParser::RuleOutputKeyword);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    _la = _input->LA(1);
    if (!(_la == YWParser::OutKeyword

    || _la == YWParser::ReturnKeyword)) {
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

//----------------- BlockNameContext ------------------------------------------------------------------

YWParser::BlockNameContext::BlockNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::PhraseContext* YWParser::BlockNameContext::phrase() {
  return getRuleContext<YWParser::PhraseContext>(0);
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
  enterRule(_localctx, 30, YWParser::RuleBlockName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    phrase();
   
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

tree::TerminalNode* YWParser::PortNameContext::Word() {
  return getToken(YWParser::Word, 0);
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
  enterRule(_localctx, 32, YWParser::RulePortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    match(YWParser::Word);
   
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

YWParser::PhraseContext* YWParser::DataNameContext::phrase() {
  return getRuleContext<YWParser::PhraseContext>(0);
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
  enterRule(_localctx, 34, YWParser::RuleDataName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(187);
    phrase();
   
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

YWParser::PathTemplateContext* YWParser::UriTemplateContext::pathTemplate() {
  return getRuleContext<YWParser::PathTemplateContext>(0);
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
  enterRule(_localctx, 36, YWParser::RuleUriTemplate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YWParser::T__1

    || _la == YWParser::T__2) {
      setState(189);
      scheme();
      setState(190);
      match(YWParser::T__0);
    }
    setState(194);
    pathTemplate();
   
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
  enterRule(_localctx, 38, YWParser::RuleScheme);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    _la = _input->LA(1);
    if (!(_la == YWParser::T__1

    || _la == YWParser::T__2)) {
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

YWParser::PhraseContext* YWParser::DescriptionContext::phrase() {
  return getRuleContext<YWParser::PhraseContext>(0);
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
  enterRule(_localctx, 40, YWParser::RuleDescription);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    phrase();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PhraseContext ------------------------------------------------------------------

YWParser::PhraseContext::PhraseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> YWParser::PhraseContext::Word() {
  return getTokens(YWParser::Word);
}

tree::TerminalNode* YWParser::PhraseContext::Word(size_t i) {
  return getToken(YWParser::Word, i);
}

std::vector<tree::TerminalNode *> YWParser::PhraseContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::PhraseContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
}


size_t YWParser::PhraseContext::getRuleIndex() const {
  return YWParser::RulePhrase;
}

void YWParser::PhraseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPhrase(this);
}

void YWParser::PhraseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPhrase(this);
}

YWParser::PhraseContext* YWParser::phrase() {
  PhraseContext *_localctx = _tracker.createInstance<PhraseContext>(_ctx, getState());
  enterRule(_localctx, 42, YWParser::RulePhrase);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(YWParser::Word);
    setState(209);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(202); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(201);
          match(YWParser::SPACE);
          setState(204); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == YWParser::SPACE);
        setState(206);
        match(YWParser::Word); 
      }
      setState(211);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathTemplateContext ------------------------------------------------------------------

YWParser::PathTemplateContext::PathTemplateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::PathTemplateContext::Word() {
  return getToken(YWParser::Word, 0);
}


size_t YWParser::PathTemplateContext::getRuleIndex() const {
  return YWParser::RulePathTemplate;
}

void YWParser::PathTemplateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPathTemplate(this);
}

void YWParser::PathTemplateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPathTemplate(this);
}

YWParser::PathTemplateContext* YWParser::pathTemplate() {
  PathTemplateContext *_localctx = _tracker.createInstance<PathTemplateContext>(_ctx, getState());
  enterRule(_localctx, 44, YWParser::RulePathTemplate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(YWParser::Word);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WsContext ------------------------------------------------------------------

YWParser::WsContext::WsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> YWParser::WsContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::WsContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
}

std::vector<tree::TerminalNode *> YWParser::WsContext::NEWLINE() {
  return getTokens(YWParser::NEWLINE);
}

tree::TerminalNode* YWParser::WsContext::NEWLINE(size_t i) {
  return getToken(YWParser::NEWLINE, i);
}


size_t YWParser::WsContext::getRuleIndex() const {
  return YWParser::RuleWs;
}

void YWParser::WsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWs(this);
}

void YWParser::WsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWs(this);
}

YWParser::WsContext* YWParser::ws() {
  WsContext *_localctx = _tracker.createInstance<WsContext>(_ctx, getState());
  enterRule(_localctx, 46, YWParser::RuleWs);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(214);
      _la = _input->LA(1);
      if (!(_la == YWParser::SPACE

      || _la == YWParser::NEWLINE)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(217); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::SPACE

    || _la == YWParser::NEWLINE);
   
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
  "script", "block", "blockAttribute", "port", "portAttribute", "begin", 
  "end", "desc", "alias", "call", "uri", "file", "resource", "inputKeyword", 
  "outputKeyword", "blockName", "portName", "dataName", "uriTemplate", "scheme", 
  "description", "phrase", "pathTemplate", "ws"
};

std::vector<std::string> YWParser::_literalNames = {
  "", "':'", "'file'", "'http'", "'@as'", "'@begin'", "'@call'", "'@desc'", 
  "'@end'", "'@file'", "'@in'", "'@out'", "'@param'", "'@return'", "'@uri'"
};

std::vector<std::string> YWParser::_symbolicNames = {
  "", "", "", "", "AsKeyword", "BeginKeyword", "CallKeyword", "DescKeyword", 
  "EndKeyword", "FileKeyword", "InKeyword", "OutKeyword", "ParamKeyword", 
  "ReturnKeyword", "UriKeyword", "SPACE", "NEWLINE", "Word"
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
    0x3, 0x13, 0xde, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 
    0x4, 0x19, 0x9, 0x19, 0x3, 0x2, 0x5, 0x2, 0x34, 0xa, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x3a, 0xa, 0x2, 0xc, 0x2, 0xe, 
    0x2, 0x3d, 0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0x40, 0xa, 0x2, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x46, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 
    0x49, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x4e, 0xa, 0x3, 
    0xc, 0x3, 0xe, 0x3, 0x51, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x59, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x5d, 0xa, 0x5, 0x3, 0x5, 0x6, 0x5, 0x60, 0xa, 0x5, 0xd, 0x5, 
    0xe, 0x5, 0x61, 0x3, 0x5, 0x6, 0x5, 0x65, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 
    0x66, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x6c, 0xa, 0x5, 0xc, 0x5, 
    0xe, 0x5, 0x6f, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x74, 
    0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x78, 0xa, 0x7, 0xd, 0x7, 0xe, 
    0x7, 0x79, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x6, 0x8, 0x80, 0xa, 
    0x8, 0xd, 0x8, 0xe, 0x8, 0x81, 0x3, 0x8, 0x5, 0x8, 0x85, 0xa, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x6, 0x9, 0x89, 0xa, 0x9, 0xd, 0x9, 0xe, 0x9, 0x8a, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x6, 0xa, 0x91, 0xa, 0xa, 0xd, 0xa, 
    0xe, 0xa, 0x92, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x6, 0xb, 0x99, 
    0xa, 0xb, 0xd, 0xb, 0xe, 0xb, 0x9a, 0x3, 0xb, 0x6, 0xb, 0x9e, 0xa, 0xb, 
    0xd, 0xb, 0xe, 0xb, 0x9f, 0x3, 0xc, 0x3, 0xc, 0x6, 0xc, 0xa4, 0xa, 0xc, 
    0xd, 0xc, 0xe, 0xc, 0xa5, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x6, 
    0xd, 0xac, 0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0xad, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x5, 0xe, 0xb4, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xc3, 0xa, 0x14, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x6, 0x17, 0xcd, 0xa, 0x17, 0xd, 0x17, 0xe, 0x17, 0xce, 0x3, 
    0x17, 0x7, 0x17, 0xd2, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0xd5, 0xb, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x6, 0x19, 0xda, 0xa, 0x19, 0xd, 0x19, 
    0xe, 0x19, 0xdb, 0x3, 0x19, 0x2, 0x2, 0x1a, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x2, 0x6, 0x4, 0x2, 0xc, 0xc, 
    0xe, 0xe, 0x4, 0x2, 0xd, 0xd, 0xf, 0xf, 0x3, 0x2, 0x4, 0x5, 0x3, 0x2, 
    0x11, 0x12, 0x2, 0xe0, 0x2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x4, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x58, 0x3, 0x2, 0x2, 0x2, 0x8, 0x5c, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x73, 0x3, 0x2, 0x2, 0x2, 0xc, 0x75, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x10, 0x86, 0x3, 0x2, 0x2, 0x2, 0x12, 0x8e, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x96, 0x3, 0x2, 0x2, 0x2, 0x16, 0xa1, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xb3, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xb7, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x22, 0xbb, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x26, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x28, 
    0xc6, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xca, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0xd6, 0x3, 0x2, 0x2, 0x2, 0x30, 0xd9, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x34, 0x5, 0x30, 0x19, 0x2, 0x33, 0x32, 0x3, 0x2, 
    0x2, 0x2, 0x33, 0x34, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x3b, 0x5, 0x4, 0x3, 0x2, 0x36, 0x37, 0x5, 0x30, 0x19, 0x2, 
    0x37, 0x38, 0x5, 0x4, 0x3, 0x2, 0x38, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x39, 
    0x36, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 
    0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x5, 0x30, 
    0x19, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x3, 0x3, 0x2, 0x2, 0x2, 0x41, 0x47, 0x5, 0xc, 0x7, 0x2, 
    0x42, 0x43, 0x5, 0x30, 0x19, 0x2, 0x43, 0x44, 0x5, 0x6, 0x4, 0x2, 0x44, 
    0x46, 0x3, 0x2, 0x2, 0x2, 0x45, 0x42, 0x3, 0x2, 0x2, 0x2, 0x46, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x47, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x4b, 0x5, 0x30, 0x19, 0x2, 0x4b, 0x4c, 0x5, 0x4, 0x3, 
    0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x5, 0x30, 0x19, 0x2, 0x53, 0x54, 0x5, 
    0xe, 0x8, 0x2, 0x54, 0x5, 0x3, 0x2, 0x2, 0x2, 0x55, 0x59, 0x5, 0x8, 
    0x5, 0x2, 0x56, 0x59, 0x5, 0x10, 0x9, 0x2, 0x57, 0x59, 0x5, 0x14, 0xb, 
    0x2, 0x58, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 
    0x58, 0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x5d, 0x5, 0x1c, 0xf, 0x2, 0x5b, 0x5d, 0x5, 0x1e, 0x10, 0x2, 0x5c, 0x5a, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x5e, 0x60, 0x7, 0x11, 0x2, 0x2, 0x5f, 0x5e, 0x3, 0x2, 
    0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x61, 0x62, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x63, 0x65, 0x5, 0x22, 0x12, 0x2, 0x64, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x65, 
    0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x5, 
    0x30, 0x19, 0x2, 0x69, 0x6a, 0x5, 0xa, 0x6, 0x2, 0x6a, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x6b, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x9, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x74, 0x5, 0x10, 0x9, 0x2, 0x71, 0x74, 0x5, 0x12, 0xa, 0x2, 0x72, 0x74, 
    0x5, 0x1a, 0xe, 0x2, 0x73, 0x70, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 0x3, 
    0x2, 0x2, 0x2, 0x73, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x75, 0x77, 0x7, 0x7, 0x2, 0x2, 0x76, 0x78, 0x7, 0x11, 0x2, 
    0x2, 0x77, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 
    0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 
    0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x5, 0x20, 0x11, 0x2, 0x7c, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x7d, 0x84, 0x7, 0xa, 0x2, 0x2, 0x7e, 0x80, 0x7, 
    0x11, 0x2, 0x2, 0x7f, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x85, 0x5, 0x20, 0x11, 0x2, 
    0x84, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x86, 0x88, 0x7, 0x9, 0x2, 0x2, 0x87, 0x89, 
    0x7, 0x11, 0x2, 0x2, 0x88, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x2a, 0x16, 
    0x2, 0x8d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x90, 0x7, 0x6, 0x2, 0x2, 
    0x8f, 0x91, 0x7, 0x11, 0x2, 0x2, 0x90, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 
    0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x5, 
    0x24, 0x13, 0x2, 0x95, 0x13, 0x3, 0x2, 0x2, 0x2, 0x96, 0x98, 0x7, 0x8, 
    0x2, 0x2, 0x97, 0x99, 0x7, 0x11, 0x2, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x9e, 0x5, 0x20, 0x11, 0x2, 0x9d, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa3, 0x7, 0x10, 
    0x2, 0x2, 0xa2, 0xa4, 0x7, 0x11, 0x2, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 
    0xa8, 0x5, 0x26, 0x14, 0x2, 0xa8, 0x17, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xab, 
    0x7, 0xb, 0x2, 0x2, 0xaa, 0xac, 0x7, 0x11, 0x2, 0x2, 0xab, 0xaa, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0xb0, 0x5, 0x2e, 0x18, 0x2, 0xb0, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xb4, 0x5, 0x16, 0xc, 0x2, 0xb2, 0xb4, 0x5, 0x18, 0xd, 0x2, 0xb3, 
    0xb1, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x9, 0x2, 0x2, 0x2, 0xb6, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0xb8, 0x9, 0x3, 0x2, 0x2, 0xb8, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0xb9, 0xba, 0x5, 0x2c, 0x17, 0x2, 0xba, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0xbb, 0xbc, 0x7, 0x13, 0x2, 0x2, 0xbc, 0x23, 0x3, 0x2, 0x2, 0x2, 
    0xbd, 0xbe, 0x5, 0x2c, 0x17, 0x2, 0xbe, 0x25, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xc0, 0x5, 0x28, 0x15, 0x2, 0xc0, 0xc1, 0x7, 0x3, 0x2, 0x2, 0xc1, 0xc3, 
    0x3, 0x2, 0x2, 0x2, 0xc2, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 
    0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 0x5, 0x2e, 
    0x18, 0x2, 0xc5, 0x27, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x9, 0x4, 0x2, 
    0x2, 0xc7, 0x29, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x5, 0x2c, 0x17, 0x2, 
    0xc9, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xca, 0xd3, 0x7, 0x13, 0x2, 0x2, 0xcb, 
    0xcd, 0x7, 0x11, 0x2, 0x2, 0xcc, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 
    0x3, 0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 
    0x2, 0x2, 0x2, 0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd2, 0x7, 0x13, 
    0x2, 0x2, 0xd1, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd5, 0x3, 0x2, 0x2, 
    0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 
    0xd4, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd6, 
    0xd7, 0x7, 0x13, 0x2, 0x2, 0xd7, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xda, 
    0x9, 0x5, 0x2, 0x2, 0xd9, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdb, 0x3, 
    0x2, 0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 
    0x2, 0x2, 0xdc, 0x31, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x33, 0x3b, 0x3f, 0x47, 
    0x4f, 0x58, 0x5c, 0x61, 0x66, 0x6d, 0x73, 0x79, 0x81, 0x84, 0x8a, 0x92, 
    0x9a, 0x9f, 0xa5, 0xad, 0xb3, 0xc2, 0xce, 0xd3, 0xdb, 
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
