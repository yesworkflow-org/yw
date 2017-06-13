
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
    setState(47);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YWParser::BeginKeyword) {
      setState(44);
      block();
      setState(49);
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
    setState(50);
    beginTag();
    setState(54);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(51);
        match(YWParser::WS); 
      }
      setState(56);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(60);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YWParser::CallKeyword)
      | (1ULL << YWParser::DescKeyword)
      | (1ULL << YWParser::InKeyword)
      | (1ULL << YWParser::OutKeyword)
      | (1ULL << YWParser::ParamKeyword)
      | (1ULL << YWParser::ReturnKeyword))) != 0)) {
      setState(57);
      blockAttribute();
      setState(62);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(66);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(63);
        match(YWParser::WS); 
      }
      setState(68);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
    setState(72);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YWParser::BeginKeyword) {
      setState(69);
      block();
      setState(74);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(78);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YWParser::WS) {
      setState(75);
      match(YWParser::WS);
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(81);
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
    setState(86);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::DescKeyword: {
        enterOuterAlt(_localctx, 1);
        setState(83);
        descTag();
        break;
      }

      case YWParser::InKeyword:
      case YWParser::OutKeyword:
      case YWParser::ParamKeyword:
      case YWParser::ReturnKeyword: {
        enterOuterAlt(_localctx, 2);
        setState(84);
        portTag();
        break;
      }

      case YWParser::CallKeyword: {
        enterOuterAlt(_localctx, 3);
        setState(85);
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
    setState(91);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::DescKeyword: {
        enterOuterAlt(_localctx, 1);
        setState(88);
        descTag();
        break;
      }

      case YWParser::AsKeyword: {
        enterOuterAlt(_localctx, 2);
        setState(89);
        aliasTag();
        break;
      }

      case YWParser::FileKeyword:
      case YWParser::UriKeyword: {
        enterOuterAlt(_localctx, 3);
        setState(90);
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
  enterRule(_localctx, 8, YWParser::RuleBeginTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(YWParser::BeginKeyword);
    setState(95); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(94);
      match(YWParser::HS);
      setState(97); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(99);
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
  enterRule(_localctx, 10, YWParser::RuleEndTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(101);
    match(YWParser::EndKeyword);
    setState(103); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(102);
      match(YWParser::HS);
      setState(105); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(108);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YWParser::ID) {
      setState(107);
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
  enterRule(_localctx, 12, YWParser::RuleDescTag);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    match(YWParser::DescKeyword);
    setState(112); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(111);
      match(YWParser::HS);
      setState(114); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(116);
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
    setState(120);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::InKeyword:
      case YWParser::ParamKeyword: {
        setState(118);
        inputPortKeyword();
        break;
      }

      case YWParser::OutKeyword:
      case YWParser::ReturnKeyword: {
        setState(119);
        outputPortKeyword();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(141); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
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
      setState(127);
      portName();
      setState(139);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(129); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(128);
                  match(YWParser::HS);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(131); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        setState(136);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(133);
            portAttribute(); 
          }
          setState(138);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
        }
        break;
      }

      }
      setState(143); 
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
    setState(145);
    match(YWParser::AsKeyword);
    setState(147); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(146);
      match(YWParser::HS);
      setState(149); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(151);
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
    setState(153);
    match(YWParser::CallKeyword);
    setState(155); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(154);
      match(YWParser::HS);
      setState(157); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(160); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(159);
      blockName();
      setState(162); 
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
    setState(164);
    match(YWParser::UriKeyword);
    setState(166); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(165);
      match(YWParser::HS);
      setState(168); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(170);
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

tree::TerminalNode* YWParser::FileTagContext::PathTemplate() {
  return getToken(YWParser::PathTemplate, 0);
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
    setState(172);
    match(YWParser::FileKeyword);
    setState(174); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(173);
      match(YWParser::HS);
      setState(176); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::HS);
    setState(178);
    match(YWParser::PathTemplate);
   
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
    setState(182);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::UriKeyword: {
        enterOuterAlt(_localctx, 1);
        setState(180);
        uriTag();
        break;
      }

      case YWParser::FileKeyword: {
        enterOuterAlt(_localctx, 2);
        setState(181);
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
    setState(184);
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
    setState(186);
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
    setState(188);
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
  enterRule(_localctx, 32, YWParser::RulePortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
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
  enterRule(_localctx, 34, YWParser::RuleDataName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
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

tree::TerminalNode* YWParser::UriTemplateContext::PathTemplate() {
  return getToken(YWParser::PathTemplate, 0);
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
    setState(197);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YWParser::T__1

    || _la == YWParser::T__2) {
      setState(194);
      scheme();
      setState(195);
      match(YWParser::T__0);
    }
    setState(199);
    match(YWParser::PathTemplate);
   
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
    setState(201);
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
    setState(203);
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

std::vector<tree::TerminalNode *> YWParser::PhraseContext::ID() {
  return getTokens(YWParser::ID);
}

tree::TerminalNode* YWParser::PhraseContext::ID(size_t i) {
  return getToken(YWParser::ID, i);
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
    setState(205);
    match(YWParser::ID);
    setState(214);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(207); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(206);
          match(YWParser::HS);
          setState(209); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == YWParser::HS);
        setState(211);
        match(YWParser::ID); 
      }
      setState(216);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
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
  "script", "block", "blockAttribute", "portAttribute", "beginTag", "endTag", 
  "descTag", "portTag", "aliasTag", "callTag", "uriTag", "fileTag", "resourceTag", 
  "inputPortKeyword", "outputPortKeyword", "blockName", "portName", "dataName", 
  "uriTemplate", "scheme", "description", "phrase"
};

std::vector<std::string> YWParser::_literalNames = {
  "", "':'", "'file'", "'http'", "'@as'", "'@begin'", "'@call'", "'@desc'", 
  "'@end'", "'@file'", "'@in'", "'@out'", "'@param'", "'@return'", "'@uri'"
};

std::vector<std::string> YWParser::_symbolicNames = {
  "", "", "", "", "AsKeyword", "BeginKeyword", "CallKeyword", "DescKeyword", 
  "EndKeyword", "FileKeyword", "InKeyword", "OutKeyword", "ParamKeyword", 
  "ReturnKeyword", "UriKeyword", "VS", "HS", "NL", "ID", "PathTemplate", 
  "WS", "SP"
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
    0x3, 0x17, 0xdc, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x3, 0x2, 0x7, 0x2, 
    0x30, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x33, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x37, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x3a, 0xb, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x3d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x40, 0xb, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x43, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x46, 0xb, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x49, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x4c, 0xb, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x4f, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x52, 0xb, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x59, 0xa, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x5e, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x6, 0x6, 0x62, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x63, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x6a, 0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 0x6b, 
    0x3, 0x7, 0x5, 0x7, 0x6f, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x6, 0x8, 0x73, 
    0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x74, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x7b, 0xa, 0x9, 0x3, 0x9, 0x6, 0x9, 0x7e, 0xa, 0x9, 0xd, 
    0x9, 0xe, 0x9, 0x7f, 0x3, 0x9, 0x3, 0x9, 0x6, 0x9, 0x84, 0xa, 0x9, 0xd, 
    0x9, 0xe, 0x9, 0x85, 0x3, 0x9, 0x7, 0x9, 0x89, 0xa, 0x9, 0xc, 0x9, 0xe, 
    0x9, 0x8c, 0xb, 0x9, 0x5, 0x9, 0x8e, 0xa, 0x9, 0x6, 0x9, 0x90, 0xa, 
    0x9, 0xd, 0x9, 0xe, 0x9, 0x91, 0x3, 0xa, 0x3, 0xa, 0x6, 0xa, 0x96, 0xa, 
    0xa, 0xd, 0xa, 0xe, 0xa, 0x97, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 
    0x6, 0xb, 0x9e, 0xa, 0xb, 0xd, 0xb, 0xe, 0xb, 0x9f, 0x3, 0xb, 0x6, 0xb, 
    0xa3, 0xa, 0xb, 0xd, 0xb, 0xe, 0xb, 0xa4, 0x3, 0xc, 0x3, 0xc, 0x6, 0xc, 
    0xa9, 0xa, 0xc, 0xd, 0xc, 0xe, 0xc, 0xaa, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x6, 0xd, 0xb1, 0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0xb2, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xb9, 0xa, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0xc8, 
    0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x17, 0x3, 0x17, 0x6, 0x17, 0xd2, 0xa, 0x17, 0xd, 0x17, 0xe, 
    0x17, 0xd3, 0x3, 0x17, 0x7, 0x17, 0xd7, 0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 
    0xda, 0xb, 0x17, 0x3, 0x17, 0x2, 0x2, 0x18, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2, 0x5, 0x4, 0x2, 0xc, 0xc, 0xe, 0xe, 
    0x4, 0x2, 0xd, 0xd, 0xf, 0xf, 0x3, 0x2, 0x4, 0x5, 0x2, 0xe2, 0x2, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x34, 0x3, 0x2, 0x2, 0x2, 0x6, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0x5d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5f, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x67, 0x3, 0x2, 0x2, 0x2, 0xe, 0x70, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x12, 0x93, 0x3, 0x2, 0x2, 0x2, 0x14, 0x9b, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x18, 0xae, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x20, 0xbe, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0xc0, 0x3, 0x2, 0x2, 0x2, 0x24, 0xc2, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x28, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0xcd, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x30, 
    0x5, 0x4, 0x3, 0x2, 0x2f, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x30, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x3, 0x3, 0x2, 0x2, 0x2, 0x33, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x38, 0x5, 0xa, 0x6, 0x2, 0x35, 0x37, 0x7, 0x16, 0x2, 0x2, 
    0x36, 0x35, 0x3, 0x2, 0x2, 0x2, 0x37, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3e, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3d, 0x5, 
    0x6, 0x4, 0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x40, 0x3, 0x2, 
    0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x44, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x43, 0x7, 0x16, 0x2, 0x2, 0x42, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 
    0x46, 0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x45, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x46, 0x44, 0x3, 
    0x2, 0x2, 0x2, 0x47, 0x49, 0x5, 0x4, 0x3, 0x2, 0x48, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x49, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 
    0x2, 0x4a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x50, 0x3, 0x2, 0x2, 0x2, 
    0x4c, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4f, 0x7, 0x16, 0x2, 0x2, 0x4e, 
    0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x52, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 
    0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0x53, 0x3, 
    0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x5, 0xc, 
    0x7, 0x2, 0x54, 0x5, 0x3, 0x2, 0x2, 0x2, 0x55, 0x59, 0x5, 0xe, 0x8, 
    0x2, 0x56, 0x59, 0x5, 0x10, 0x9, 0x2, 0x57, 0x59, 0x5, 0x14, 0xb, 0x2, 
    0x58, 0x55, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x57, 0x3, 0x2, 0x2, 0x2, 0x59, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5e, 
    0x5, 0xe, 0x8, 0x2, 0x5b, 0x5e, 0x5, 0x12, 0xa, 0x2, 0x5c, 0x5e, 0x5, 
    0x1a, 0xe, 0x2, 0x5d, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 
    0x2, 0x2, 0x5d, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0x61, 0x7, 0x7, 0x2, 0x2, 0x60, 0x62, 0x7, 0x12, 0x2, 0x2, 
    0x61, 0x60, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x5, 0x20, 0x11, 0x2, 0x66, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x69, 0x7, 0xa, 0x2, 0x2, 0x68, 0x6a, 0x7, 0x12, 
    0x2, 0x2, 0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 0x5, 0x20, 0x11, 0x2, 0x6e, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0xd, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x72, 0x7, 0x9, 0x2, 0x2, 0x71, 0x73, 0x7, 
    0x12, 0x2, 0x2, 0x72, 0x71, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 
    0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 
    0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x5, 0x2a, 0x16, 0x2, 
    0x77, 0xf, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7b, 0x5, 0x1c, 0xf, 0x2, 0x79, 
    0x7b, 0x5, 0x1e, 0x10, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x79, 
    0x3, 0x2, 0x2, 0x2, 0x7b, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7e, 0x7, 
    0x12, 0x2, 0x2, 0x7d, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 
    0x2, 0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 
    0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x8d, 0x5, 0x22, 0x12, 0x2, 
    0x82, 0x84, 0x7, 0x12, 0x2, 0x2, 0x83, 0x82, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x87, 0x89, 0x5, 
    0x8, 0x5, 0x2, 0x88, 0x87, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8c, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 0x2, 
    0x2, 0x8b, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x8d, 0x83, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 
    0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0x92, 0x11, 0x3, 0x2, 0x2, 0x2, 0x93, 0x95, 0x7, 0x6, 
    0x2, 0x2, 0x94, 0x96, 0x7, 0x12, 0x2, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 
    0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x97, 0x98, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x9a, 0x5, 0x24, 0x13, 0x2, 0x9a, 0x13, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9d, 
    0x7, 0x8, 0x2, 0x2, 0x9c, 0x9e, 0x7, 0x12, 0x2, 0x2, 0x9d, 0x9c, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 0x3, 0x2, 
    0x2, 0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa2, 0x3, 0x2, 0x2, 
    0x2, 0xa1, 0xa3, 0x5, 0x20, 0x11, 0x2, 0xa2, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 
    0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa8, 
    0x7, 0x10, 0x2, 0x2, 0xa7, 0xa9, 0x7, 0x12, 0x2, 0x2, 0xa8, 0xa7, 0x3, 
    0x2, 0x2, 0x2, 0xa9, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 
    0x2, 0xac, 0xad, 0x5, 0x26, 0x14, 0x2, 0xad, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0xae, 0xb0, 0x7, 0xb, 0x2, 0x2, 0xaf, 0xb1, 0x7, 0x12, 0x2, 0x2, 0xb0, 
    0xaf, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x15, 0x2, 0x2, 0xb5, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb9, 0x5, 0x16, 0xc, 0x2, 0xb7, 0xb9, 0x5, 0x18, 0xd, 
    0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 
    0xb9, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x9, 0x2, 0x2, 0x2, 0xbb, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x9, 0x3, 0x2, 0x2, 0xbd, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x2c, 0x17, 0x2, 0xbf, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xc1, 0x7, 0x14, 0x2, 0x2, 0xc1, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0xc2, 0xc3, 0x7, 0x14, 0x2, 0x2, 0xc3, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0xc4, 0xc5, 0x5, 0x28, 0x15, 0x2, 0xc5, 0xc6, 0x7, 0x3, 0x2, 0x2, 
    0xc6, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xc8, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 
    0x7, 0x15, 0x2, 0x2, 0xca, 0x27, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x9, 
    0x4, 0x2, 0x2, 0xcc, 0x29, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x2c, 
    0x17, 0x2, 0xce, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd8, 0x7, 0x14, 0x2, 
    0x2, 0xd0, 0xd2, 0x7, 0x12, 0x2, 0x2, 0xd1, 0xd0, 0x3, 0x2, 0x2, 0x2, 
    0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd3, 
    0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd7, 
    0x7, 0x14, 0x2, 0x2, 0xd6, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xda, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x3, 0x2, 
    0x2, 0x2, 0xd9, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 
    0x2, 0x1d, 0x31, 0x38, 0x3e, 0x44, 0x4a, 0x50, 0x58, 0x5d, 0x63, 0x6b, 
    0x6e, 0x74, 0x7a, 0x7f, 0x85, 0x8a, 0x8d, 0x91, 0x97, 0x9f, 0xa4, 0xaa, 
    0xb2, 0xb8, 0xc7, 0xd3, 0xd8, 
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
