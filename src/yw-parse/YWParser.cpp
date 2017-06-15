
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
    setState(51);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YWParser::BeginKeyword)
      | (1ULL << YWParser::HS)
      | (1ULL << YWParser::NL))) != 0)) {
      setState(48);
      block();
      setState(53);
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

std::vector<YWParser::WsContext *> YWParser::BlockContext::ws() {
  return getRuleContexts<YWParser::WsContext>();
}

YWParser::WsContext* YWParser::BlockContext::ws(size_t i) {
  return getRuleContext<YWParser::WsContext>(i);
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
    setState(57);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YWParser::HS

    || _la == YWParser::NL) {
      setState(54);
      ws();
      setState(59);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(60);
    beginTag();
    setState(64);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(61);
        ws(); 
      }
      setState(66);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(70);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YWParser::CallKeyword)
      | (1ULL << YWParser::DescKeyword)
      | (1ULL << YWParser::InKeyword)
      | (1ULL << YWParser::OutKeyword)
      | (1ULL << YWParser::ParamKeyword)
      | (1ULL << YWParser::ReturnKeyword))) != 0)) {
      setState(67);
      blockAttribute();
      setState(72);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(76);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(73);
        ws(); 
      }
      setState(78);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(82);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(79);
        block(); 
      }
      setState(84);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(88);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YWParser::HS

    || _la == YWParser::NL) {
      setState(85);
      ws();
      setState(90);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(91);
    endTag();
    setState(95);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(92);
        ws(); 
      }
      setState(97);
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

//----------------- BlockAttributeContext ------------------------------------------------------------------

YWParser::BlockAttributeContext::BlockAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::PortContext* YWParser::BlockAttributeContext::port() {
  return getRuleContext<YWParser::PortContext>(0);
}

YWParser::DescTagContext* YWParser::BlockAttributeContext::descTag() {
  return getRuleContext<YWParser::DescTagContext>(0);
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
    setState(101);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::InKeyword:
      case YWParser::OutKeyword:
      case YWParser::ParamKeyword:
      case YWParser::ReturnKeyword: {
        enterOuterAlt(_localctx, 1);
        setState(98);
        port();
        break;
      }

      case YWParser::DescKeyword: {
        enterOuterAlt(_localctx, 2);
        setState(99);
        descTag();
        break;
      }

      case YWParser::CallKeyword: {
        enterOuterAlt(_localctx, 3);
        setState(100);
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

//----------------- PortContext ------------------------------------------------------------------

YWParser::PortContext::PortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::InputPortKeywordContext* YWParser::PortContext::inputPortKeyword() {
  return getRuleContext<YWParser::InputPortKeywordContext>(0);
}

YWParser::OutputPortKeywordContext* YWParser::PortContext::outputPortKeyword() {
  return getRuleContext<YWParser::OutputPortKeywordContext>(0);
}

std::vector<YWParser::PortNameContext *> YWParser::PortContext::portName() {
  return getRuleContexts<YWParser::PortNameContext>();
}

YWParser::PortNameContext* YWParser::PortContext::portName(size_t i) {
  return getRuleContext<YWParser::PortNameContext>(i);
}

std::vector<tree::TerminalNode *> YWParser::PortContext::HS() {
  return getTokens(YWParser::HS);
}

tree::TerminalNode* YWParser::PortContext::HS(size_t i) {
  return getToken(YWParser::HS, i);
}

std::vector<YWParser::PortAttributeContext *> YWParser::PortContext::portAttribute() {
  return getRuleContexts<YWParser::PortAttributeContext>();
}

YWParser::PortAttributeContext* YWParser::PortContext::portAttribute(size_t i) {
  return getRuleContext<YWParser::PortAttributeContext>(i);
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
    setState(105);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::InKeyword:
      case YWParser::ParamKeyword: {
        setState(103);
        inputPortKeyword();
        break;
      }

      case YWParser::OutKeyword:
      case YWParser::ReturnKeyword: {
        setState(104);
        outputPortKeyword();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(144);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(113); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(108); 
                _errHandler->sync(this);
                _la = _input->LA(1);
                do {
                  setState(107);
                  match(YWParser::HS);
                  setState(110); 
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                } while (_la == YWParser::HS);
                setState(112);
                portName();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(115); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      setState(125);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(118); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(117);
            match(YWParser::HS);
            setState(120); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == YWParser::HS);
          setState(122);
          portName(); 
        }
        setState(127);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
      }
      setState(129); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(128);
        match(YWParser::HS);
        setState(131); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == YWParser::HS);
      setState(133);
      portName();
      setState(135); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(134);
        match(YWParser::HS);
        setState(137); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == YWParser::HS);
      setState(140); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(139);
                portAttribute();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(142); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
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
  enterRule(_localctx, 8, YWParser::RulePortAttribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(149);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::DescKeyword: {
        enterOuterAlt(_localctx, 1);
        setState(146);
        descTag();
        break;
      }

      case YWParser::AsKeyword: {
        enterOuterAlt(_localctx, 2);
        setState(147);
        aliasTag();
        break;
      }

      case YWParser::FileKeyword:
      case YWParser::UriKeyword: {
        enterOuterAlt(_localctx, 3);
        setState(148);
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

tree::TerminalNode* YWParser::BeginTagContext::BeginKeyword() {
  return getToken(YWParser::BeginKeyword, 0);
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
  enterRule(_localctx, 10, YWParser::RuleBeginTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    match(YWParser::BeginKeyword);
    setState(153); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(152);
      match(YWParser::HS);
      setState(155); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
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

//----------------- EndTagContext ------------------------------------------------------------------

YWParser::EndTagContext::EndTagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::EndTagContext::EndKeyword() {
  return getToken(YWParser::EndKeyword, 0);
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
  enterRule(_localctx, 12, YWParser::RuleEndTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(YWParser::EndKeyword);
    setState(161); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(160);
              match(YWParser::HS);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(163); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(166);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YWParser::Word) {
      setState(165);
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

tree::TerminalNode* YWParser::DescTagContext::DescKeyword() {
  return getToken(YWParser::DescKeyword, 0);
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
  enterRule(_localctx, 14, YWParser::RuleDescTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(168);
    match(YWParser::DescKeyword);
    setState(170); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(169);
      match(YWParser::HS);
      setState(172); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(174);
    description();
   
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

tree::TerminalNode* YWParser::AliasTagContext::AsKeyword() {
  return getToken(YWParser::AsKeyword, 0);
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
    setState(176);
    match(YWParser::AsKeyword);
    setState(178); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(177);
      match(YWParser::HS);
      setState(180); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(182);
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

tree::TerminalNode* YWParser::CallTagContext::CallKeyword() {
  return getToken(YWParser::CallKeyword, 0);
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
    setState(184);
    match(YWParser::CallKeyword);
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
    setState(191); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(190);
      blockName();
      setState(193); 
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

//----------------- UriTagContext ------------------------------------------------------------------

YWParser::UriTagContext::UriTagContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::UriTagContext::UriKeyword() {
  return getToken(YWParser::UriKeyword, 0);
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
    setState(195);
    match(YWParser::UriKeyword);
    setState(197); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(196);
      match(YWParser::HS);
      setState(199); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(201);
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

tree::TerminalNode* YWParser::FileTagContext::FileKeyword() {
  return getToken(YWParser::FileKeyword, 0);
}

YWParser::PathTemplateContext* YWParser::FileTagContext::pathTemplate() {
  return getRuleContext<YWParser::PathTemplateContext>(0);
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
    setState(203);
    match(YWParser::FileKeyword);
    setState(205); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(204);
      match(YWParser::HS);
      setState(207); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(209);
    pathTemplate();
   
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
    setState(213);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::UriKeyword: {
        enterOuterAlt(_localctx, 1);
        setState(211);
        uriTag();
        break;
      }

      case YWParser::FileKeyword: {
        enterOuterAlt(_localctx, 2);
        setState(212);
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

tree::TerminalNode* YWParser::InputPortKeywordContext::InKeyword() {
  return getToken(YWParser::InKeyword, 0);
}

tree::TerminalNode* YWParser::InputPortKeywordContext::ParamKeyword() {
  return getToken(YWParser::ParamKeyword, 0);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
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

//----------------- OutputPortKeywordContext ------------------------------------------------------------------

YWParser::OutputPortKeywordContext::OutputPortKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::OutputPortKeywordContext::OutKeyword() {
  return getToken(YWParser::OutKeyword, 0);
}

tree::TerminalNode* YWParser::OutputPortKeywordContext::ReturnKeyword() {
  return getToken(YWParser::ReturnKeyword, 0);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
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
    setState(219);
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
    setState(221);
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
    setState(223);
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
    setState(228);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YWParser::T__1

    || _la == YWParser::T__2) {
      setState(225);
      scheme();
      setState(226);
      match(YWParser::T__0);
    }
    setState(230);
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
    setState(232);
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
    setState(234);
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

std::vector<tree::TerminalNode *> YWParser::PhraseContext::HS() {
  return getTokens(YWParser::HS);
}

tree::TerminalNode* YWParser::PhraseContext::HS(size_t i) {
  return getToken(YWParser::HS, i);
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
    setState(236);
    match(YWParser::Word);
    setState(245);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(238); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(237);
          match(YWParser::HS);
          setState(240); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == YWParser::HS);
        setState(242);
        match(YWParser::Word); 
      }
      setState(247);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
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
    setState(248);
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

std::vector<tree::TerminalNode *> YWParser::WsContext::HS() {
  return getTokens(YWParser::HS);
}

tree::TerminalNode* YWParser::WsContext::HS(size_t i) {
  return getToken(YWParser::HS, i);
}

std::vector<tree::TerminalNode *> YWParser::WsContext::NL() {
  return getTokens(YWParser::NL);
}

tree::TerminalNode* YWParser::WsContext::NL(size_t i) {
  return getToken(YWParser::NL, i);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(278);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::HS: {
        enterOuterAlt(_localctx, 1);
        setState(251); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(250);
                  match(YWParser::HS);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(253); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        setState(258);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(255);
            match(YWParser::NL); 
          }
          setState(260);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
        }
        setState(264);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(261);
            match(YWParser::HS); 
          }
          setState(266);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
        }
        break;
      }

      case YWParser::NL: {
        enterOuterAlt(_localctx, 2);
        setState(268); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(267);
                  match(YWParser::NL);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(270); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        setState(275);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(272);
            match(YWParser::HS); 
          }
          setState(277);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
        }
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

// Static vars and initialization.
std::vector<dfa::DFA> YWParser::_decisionToDFA;
atn::PredictionContextCache YWParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN YWParser::_atn;
std::vector<uint16_t> YWParser::_serializedATN;

std::vector<std::string> YWParser::_ruleNames = {
  "script", "block", "blockAttribute", "port", "portAttribute", "beginTag", 
  "endTag", "descTag", "aliasTag", "callTag", "uriTag", "fileTag", "resourceTag", 
  "inputPortKeyword", "outputPortKeyword", "blockName", "portName", "dataName", 
  "uriTemplate", "scheme", "description", "phrase", "pathTemplate", "ws"
};

std::vector<std::string> YWParser::_literalNames = {
  "", "':'", "'file'", "'http'", "'@as'", "'@begin'", "'@call'", "'@desc'", 
  "'@end'", "'@file'", "'@in'", "'@out'", "'@param'", "'@return'", "'@uri'"
};

std::vector<std::string> YWParser::_symbolicNames = {
  "", "", "", "", "AsKeyword", "BeginKeyword", "CallKeyword", "DescKeyword", 
  "EndKeyword", "FileKeyword", "InKeyword", "OutKeyword", "ParamKeyword", 
  "ReturnKeyword", "UriKeyword", "VS", "HS", "NL", "Word"
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
    0x3, 0x14, 0x11b, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x3, 0x2, 0x7, 0x2, 0x34, 0xa, 0x2, 0xc, 
    0x2, 0xe, 0x2, 0x37, 0xb, 0x2, 0x3, 0x3, 0x7, 0x3, 0x3a, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x3d, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x41, 0xa, 
    0x3, 0xc, 0x3, 0xe, 0x3, 0x44, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 0x47, 0xa, 
    0x3, 0xc, 0x3, 0xe, 0x3, 0x4a, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 0x4d, 0xa, 
    0x3, 0xc, 0x3, 0xe, 0x3, 0x50, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 0x53, 0xa, 
    0x3, 0xc, 0x3, 0xe, 0x3, 0x56, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 0x59, 0xa, 
    0x3, 0xc, 0x3, 0xe, 0x3, 0x5c, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 
    0x60, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x63, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x68, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x6c, 
    0xa, 0x5, 0x3, 0x5, 0x6, 0x5, 0x6f, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x70, 
    0x3, 0x5, 0x6, 0x5, 0x74, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x75, 0x3, 0x5, 
    0x6, 0x5, 0x79, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x7a, 0x3, 0x5, 0x7, 0x5, 
    0x7e, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x81, 0xb, 0x5, 0x3, 0x5, 0x6, 0x5, 
    0x84, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x85, 0x3, 0x5, 0x3, 0x5, 0x6, 0x5, 
    0x8a, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x8b, 0x3, 0x5, 0x6, 0x5, 0x8f, 
    0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x90, 0x5, 0x5, 0x93, 0xa, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x98, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x6, 
    0x7, 0x9c, 0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 0x9d, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x6, 0x8, 0xa4, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0xa5, 0x3, 
    0x8, 0x5, 0x8, 0xa9, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x6, 0x9, 0xad, 0xa, 
    0x9, 0xd, 0x9, 0xe, 0x9, 0xae, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x6, 0xa, 0xb5, 0xa, 0xa, 0xd, 0xa, 0xe, 0xa, 0xb6, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x6, 0xb, 0xbd, 0xa, 0xb, 0xd, 0xb, 0xe, 0xb, 0xbe, 
    0x3, 0xb, 0x6, 0xb, 0xc2, 0xa, 0xb, 0xd, 0xb, 0xe, 0xb, 0xc3, 0x3, 0xc, 
    0x3, 0xc, 0x6, 0xc, 0xc8, 0xa, 0xc, 0xd, 0xc, 0xe, 0xc, 0xc9, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x6, 0xd, 0xd0, 0xa, 0xd, 0xd, 0xd, 0xe, 
    0xd, 0xd1, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xd8, 0xa, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x14, 0x5, 0x14, 0xe7, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x6, 0x17, 0xf1, 0xa, 
    0x17, 0xd, 0x17, 0xe, 0x17, 0xf2, 0x3, 0x17, 0x7, 0x17, 0xf6, 0xa, 0x17, 
    0xc, 0x17, 0xe, 0x17, 0xf9, 0xb, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 
    0x6, 0x19, 0xfe, 0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 0xff, 0x3, 0x19, 0x7, 
    0x19, 0x103, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x106, 0xb, 0x19, 0x3, 
    0x19, 0x7, 0x19, 0x109, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x10c, 0xb, 
    0x19, 0x3, 0x19, 0x6, 0x19, 0x10f, 0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 
    0x110, 0x3, 0x19, 0x7, 0x19, 0x114, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 
    0x117, 0xb, 0x19, 0x5, 0x19, 0x119, 0xa, 0x19, 0x3, 0x19, 0x2, 0x2, 
    0x1a, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x2, 0x5, 0x4, 0x2, 0xc, 0xc, 0xe, 0xe, 0x4, 0x2, 0xd, 0xd, 0xf, 0xf, 
    0x3, 0x2, 0x4, 0x5, 0x2, 0x12a, 0x2, 0x35, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x67, 0x3, 0x2, 0x2, 0x2, 0x8, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x97, 0x3, 0x2, 0x2, 0x2, 0xc, 0x99, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x10, 0xaa, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xb2, 0x3, 0x2, 0x2, 0x2, 0x14, 0xba, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xc5, 0x3, 0x2, 0x2, 0x2, 0x18, 0xcd, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xd7, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xdb, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x22, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xe1, 0x3, 0x2, 0x2, 0x2, 0x26, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xea, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xec, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xee, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xfa, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x118, 0x3, 0x2, 0x2, 0x2, 0x32, 0x34, 0x5, 0x4, 0x3, 0x2, 0x33, 
    0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x37, 0x3, 0x2, 0x2, 0x2, 0x35, 0x33, 
    0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 0x3, 0x2, 0x2, 0x2, 0x36, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x37, 0x35, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3a, 0x5, 0x30, 
    0x19, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x42, 0x5, 0xc, 0x7, 0x2, 0x3f, 0x41, 0x5, 0x30, 0x19, 0x2, 0x40, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x44, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 
    0x2, 0x2, 0x2, 0x42, 0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x48, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x45, 0x47, 0x5, 0x6, 0x4, 
    0x2, 0x46, 0x45, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4a, 0x3, 0x2, 0x2, 0x2, 
    0x48, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x3, 0x2, 0x2, 0x2, 0x49, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4d, 
    0x5, 0x30, 0x19, 0x2, 0x4c, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x4e, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x4f, 0x54, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 
    0x2, 0x51, 0x53, 0x5, 0x4, 0x3, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 0x2, 
    0x53, 0x56, 0x3, 0x2, 0x2, 0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 
    0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x56, 0x54, 
    0x3, 0x2, 0x2, 0x2, 0x57, 0x59, 0x5, 0x30, 0x19, 0x2, 0x58, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x5a, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5d, 0x3, 0x2, 0x2, 
    0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x61, 0x5, 0xe, 0x8, 0x2, 
    0x5e, 0x60, 0x5, 0x30, 0x19, 0x2, 0x5f, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x61, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x62, 0x5, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x68, 0x5, 0x8, 0x5, 0x2, 0x65, 0x68, 0x5, 0x10, 
    0x9, 0x2, 0x66, 0x68, 0x5, 0x14, 0xb, 0x2, 0x67, 0x64, 0x3, 0x2, 0x2, 
    0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 0x2, 
    0x68, 0x7, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6c, 0x5, 0x1c, 0xf, 0x2, 0x6a, 
    0x6c, 0x5, 0x1e, 0x10, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6a, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x92, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 0x7, 
    0x12, 0x2, 0x2, 0x6e, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 
    0x2, 0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 
    0x2, 0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0x74, 0x5, 0x22, 0x12, 0x2, 
    0x73, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x77, 0x79, 0x7, 0x12, 0x2, 0x2, 0x78, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x7e, 0x5, 0x22, 0x12, 0x2, 0x7d, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 
    0x3, 0x2, 0x2, 0x2, 0x82, 0x84, 0x7, 0x12, 0x2, 0x2, 0x83, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x85, 0x86, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x87, 0x89, 0x5, 0x22, 0x12, 0x2, 0x88, 0x8a, 0x7, 0x12, 0x2, 0x2, 
    0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8b, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8e, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x8f, 0x5, 0xa, 0x6, 0x2, 0x8e, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x92, 0x73, 0x3, 0x2, 0x2, 0x2, 0x92, 0x7f, 0x3, 0x2, 0x2, 0x2, 
    0x93, 0x9, 0x3, 0x2, 0x2, 0x2, 0x94, 0x98, 0x5, 0x10, 0x9, 0x2, 0x95, 
    0x98, 0x5, 0x12, 0xa, 0x2, 0x96, 0x98, 0x5, 0x1a, 0xe, 0x2, 0x97, 0x94, 
    0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0xb, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9b, 0x7, 0x7, 
    0x2, 0x2, 0x9a, 0x9c, 0x7, 0x12, 0x2, 0x2, 0x9b, 0x9a, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 
    0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 
    0xa0, 0x5, 0x20, 0x11, 0x2, 0xa0, 0xd, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa3, 
    0x7, 0xa, 0x2, 0x2, 0xa2, 0xa4, 0x7, 0x12, 0x2, 0x2, 0xa3, 0xa2, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 
    0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa8, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0xa9, 0x5, 0x20, 0x11, 0x2, 0xa8, 0xa7, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xf, 0x3, 0x2, 0x2, 0x2, 0xaa, 
    0xac, 0x7, 0x9, 0x2, 0x2, 0xab, 0xad, 0x7, 0x12, 0x2, 0x2, 0xac, 0xab, 
    0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xac, 0x3, 
    0x2, 0x2, 0x2, 0xae, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 0x2, 
    0x2, 0x2, 0xb0, 0xb1, 0x5, 0x2a, 0x16, 0x2, 0xb1, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0xb2, 0xb4, 0x7, 0x6, 0x2, 0x2, 0xb3, 0xb5, 0x7, 0x12, 0x2, 0x2, 
    0xb4, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb6, 
    0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 
    0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x5, 0x24, 0x13, 0x2, 0xb9, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0xba, 0xbc, 0x7, 0x8, 0x2, 0x2, 0xbb, 0xbd, 0x7, 0x12, 
    0x2, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbe, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0x20, 0x11, 0x2, 0xc1, 
    0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0xc5, 0xc7, 0x7, 0x10, 0x2, 0x2, 0xc6, 0xc8, 0x7, 0x12, 
    0x2, 0x2, 0xc7, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0xc9, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 0x2, 
    0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x26, 0x14, 0x2, 0xcc, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xcf, 0x7, 0xb, 0x2, 0x2, 0xce, 0xd0, 
    0x7, 0x12, 0x2, 0x2, 0xcf, 0xce, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xd1, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0x2e, 0x18, 
    0x2, 0xd4, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd8, 0x5, 0x16, 0xc, 0x2, 
    0xd6, 0xd8, 0x5, 0x18, 0xd, 0x2, 0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd7, 
    0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 
    0x9, 0x2, 0x2, 0x2, 0xda, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x9, 
    0x3, 0x2, 0x2, 0xdc, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x5, 0x2c, 
    0x17, 0x2, 0xde, 0x21, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x14, 0x2, 
    0x2, 0xe0, 0x23, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x5, 0x2c, 0x17, 0x2, 
    0xe2, 0x25, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0x28, 0x15, 0x2, 0xe4, 
    0xe5, 0x7, 0x3, 0x2, 0x2, 0xe5, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 
    0x2, 0x2, 0x2, 0xe8, 0xe9, 0x5, 0x2e, 0x18, 0x2, 0xe9, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0xea, 0xeb, 0x9, 0x4, 0x2, 0x2, 0xeb, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0xec, 0xed, 0x5, 0x2c, 0x17, 0x2, 0xed, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0xee, 0xf7, 0x7, 0x14, 0x2, 0x2, 0xef, 0xf1, 0x7, 0x12, 0x2, 0x2, 0xf0, 
    0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 
    0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 
    0x2, 0x2, 0x2, 0xf4, 0xf6, 0x7, 0x14, 0x2, 0x2, 0xf5, 0xf0, 0x3, 0x2, 
    0x2, 0x2, 0xf6, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 
    0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0xf9, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x14, 0x2, 0x2, 0xfb, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfe, 0x7, 0x12, 0x2, 0x2, 0xfd, 0xfc, 
    0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 0xff, 0xfd, 0x3, 
    0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 0x2, 0x100, 0x104, 0x3, 0x2, 
    0x2, 0x2, 0x101, 0x103, 0x7, 0x13, 0x2, 0x2, 0x102, 0x101, 0x3, 0x2, 
    0x2, 0x2, 0x103, 0x106, 0x3, 0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 0x2, 
    0x2, 0x2, 0x104, 0x105, 0x3, 0x2, 0x2, 0x2, 0x105, 0x10a, 0x3, 0x2, 
    0x2, 0x2, 0x106, 0x104, 0x3, 0x2, 0x2, 0x2, 0x107, 0x109, 0x7, 0x12, 
    0x2, 0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10c, 0x3, 0x2, 
    0x2, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0x119, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10a, 0x3, 0x2, 
    0x2, 0x2, 0x10d, 0x10f, 0x7, 0x13, 0x2, 0x2, 0x10e, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0x110, 0x3, 0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 
    0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 0x2, 0x111, 0x115, 0x3, 0x2, 
    0x2, 0x2, 0x112, 0x114, 0x7, 0x12, 0x2, 0x2, 0x113, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x114, 0x117, 0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x115, 0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 0x119, 0x3, 0x2, 
    0x2, 0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 0x118, 0xfd, 0x3, 0x2, 0x2, 
    0x2, 0x118, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x119, 0x31, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x35, 0x3b, 0x42, 0x48, 0x4e, 0x54, 0x5a, 0x61, 0x67, 0x6b, 0x70, 
    0x75, 0x7a, 0x7f, 0x85, 0x8b, 0x90, 0x92, 0x97, 0x9d, 0xa5, 0xa8, 0xae, 
    0xb6, 0xbe, 0xc3, 0xc9, 0xd1, 0xd7, 0xe6, 0xf2, 0xf7, 0xff, 0x104, 0x10a, 
    0x110, 0x115, 0x118, 
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
