
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

tree::TerminalNode* YWParser::ScriptContext::EOF() {
  return getToken(YWParser::EOF, 0);
}

std::vector<YWParser::NaContext *> YWParser::ScriptContext::na() {
  return getRuleContexts<YWParser::NaContext>();
}

YWParser::NaContext* YWParser::ScriptContext::na(size_t i) {
  return getRuleContext<YWParser::NaContext>(i);
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
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YWParser::DQ)
      | (1ULL << YWParser::SQ)
      | (1ULL << YWParser::SPACE)
      | (1ULL << YWParser::SLASH)
      | (1ULL << YWParser::LEFTBRACE)
      | (1ULL << YWParser::RIGHTBRACE)
      | (1ULL << YWParser::NEWLINE)
      | (1ULL << YWParser::COLON)
      | (1ULL << YWParser::WORD)
      | (1ULL << YWParser::OTHER))) != 0)) {
      setState(76);
      na();
    }
    setState(79);
    block();
    setState(86);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(81);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << YWParser::DQ)
          | (1ULL << YWParser::SQ)
          | (1ULL << YWParser::SPACE)
          | (1ULL << YWParser::SLASH)
          | (1ULL << YWParser::LEFTBRACE)
          | (1ULL << YWParser::RIGHTBRACE)
          | (1ULL << YWParser::NEWLINE)
          | (1ULL << YWParser::COLON)
          | (1ULL << YWParser::WORD)
          | (1ULL << YWParser::OTHER))) != 0)) {
          setState(80);
          na();
        }
        setState(83);
        block(); 
      }
      setState(88);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(90);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YWParser::DQ)
      | (1ULL << YWParser::SQ)
      | (1ULL << YWParser::SPACE)
      | (1ULL << YWParser::SLASH)
      | (1ULL << YWParser::LEFTBRACE)
      | (1ULL << YWParser::RIGHTBRACE)
      | (1ULL << YWParser::NEWLINE)
      | (1ULL << YWParser::COLON)
      | (1ULL << YWParser::WORD)
      | (1ULL << YWParser::OTHER))) != 0)) {
      setState(89);
      na();
    }
    setState(92);
    match(YWParser::EOF);
   
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

YWParser::NestedBlocksContext* YWParser::BlockContext::nestedBlocks() {
  return getRuleContext<YWParser::NestedBlocksContext>(0);
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

std::vector<YWParser::IoContext *> YWParser::BlockContext::io() {
  return getRuleContexts<YWParser::IoContext>();
}

YWParser::IoContext* YWParser::BlockContext::io(size_t i) {
  return getRuleContext<YWParser::IoContext>(i);
}

std::vector<YWParser::NaContext *> YWParser::BlockContext::na() {
  return getRuleContexts<YWParser::NaContext>();
}

YWParser::NaContext* YWParser::BlockContext::na(size_t i) {
  return getRuleContext<YWParser::NaContext>(i);
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
    setState(94);
    begin();
    setState(101);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(96);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << YWParser::DQ)
          | (1ULL << YWParser::SQ)
          | (1ULL << YWParser::SPACE)
          | (1ULL << YWParser::SLASH)
          | (1ULL << YWParser::LEFTBRACE)
          | (1ULL << YWParser::RIGHTBRACE)
          | (1ULL << YWParser::NEWLINE)
          | (1ULL << YWParser::COLON)
          | (1ULL << YWParser::WORD)
          | (1ULL << YWParser::OTHER))) != 0)) {
          setState(95);
          na();
        }
        setState(98);
        blockAttribute(); 
      }
      setState(103);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(110);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(105);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << YWParser::DQ)
          | (1ULL << YWParser::SQ)
          | (1ULL << YWParser::SPACE)
          | (1ULL << YWParser::SLASH)
          | (1ULL << YWParser::LEFTBRACE)
          | (1ULL << YWParser::RIGHTBRACE)
          | (1ULL << YWParser::NEWLINE)
          | (1ULL << YWParser::COLON)
          | (1ULL << YWParser::WORD)
          | (1ULL << YWParser::OTHER))) != 0)) {
          setState(104);
          na();
        }
        setState(107);
        io(); 
      }
      setState(112);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
    setState(113);
    nestedBlocks();
    setState(115);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YWParser::DQ)
      | (1ULL << YWParser::SQ)
      | (1ULL << YWParser::SPACE)
      | (1ULL << YWParser::SLASH)
      | (1ULL << YWParser::LEFTBRACE)
      | (1ULL << YWParser::RIGHTBRACE)
      | (1ULL << YWParser::NEWLINE)
      | (1ULL << YWParser::COLON)
      | (1ULL << YWParser::WORD)
      | (1ULL << YWParser::OTHER))) != 0)) {
      setState(114);
      na();
    }
    setState(117);
    end();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NestedBlocksContext ------------------------------------------------------------------

YWParser::NestedBlocksContext::NestedBlocksContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<YWParser::BlockContext *> YWParser::NestedBlocksContext::block() {
  return getRuleContexts<YWParser::BlockContext>();
}

YWParser::BlockContext* YWParser::NestedBlocksContext::block(size_t i) {
  return getRuleContext<YWParser::BlockContext>(i);
}

std::vector<YWParser::NaContext *> YWParser::NestedBlocksContext::na() {
  return getRuleContexts<YWParser::NaContext>();
}

YWParser::NaContext* YWParser::NestedBlocksContext::na(size_t i) {
  return getRuleContext<YWParser::NaContext>(i);
}


size_t YWParser::NestedBlocksContext::getRuleIndex() const {
  return YWParser::RuleNestedBlocks;
}

void YWParser::NestedBlocksContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNestedBlocks(this);
}

void YWParser::NestedBlocksContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNestedBlocks(this);
}

YWParser::NestedBlocksContext* YWParser::nestedBlocks() {
  NestedBlocksContext *_localctx = _tracker.createInstance<NestedBlocksContext>(_ctx, getState());
  enterRule(_localctx, 4, YWParser::RuleNestedBlocks);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(125);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(120);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << YWParser::DQ)
          | (1ULL << YWParser::SQ)
          | (1ULL << YWParser::SPACE)
          | (1ULL << YWParser::SLASH)
          | (1ULL << YWParser::LEFTBRACE)
          | (1ULL << YWParser::RIGHTBRACE)
          | (1ULL << YWParser::NEWLINE)
          | (1ULL << YWParser::COLON)
          | (1ULL << YWParser::WORD)
          | (1ULL << YWParser::OTHER))) != 0)) {
          setState(119);
          na();
        }
        setState(122);
        block(); 
      }
      setState(127);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
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

YWParser::BlockDescContext* YWParser::BlockAttributeContext::blockDesc() {
  return getRuleContext<YWParser::BlockDescContext>(0);
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
  enterRule(_localctx, 6, YWParser::RuleBlockAttribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(128);
    blockDesc();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IoContext ------------------------------------------------------------------

YWParser::IoContext::IoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::PortContext* YWParser::IoContext::port() {
  return getRuleContext<YWParser::PortContext>(0);
}

std::vector<YWParser::PortAttributeContext *> YWParser::IoContext::portAttribute() {
  return getRuleContexts<YWParser::PortAttributeContext>();
}

YWParser::PortAttributeContext* YWParser::IoContext::portAttribute(size_t i) {
  return getRuleContext<YWParser::PortAttributeContext>(i);
}

std::vector<YWParser::NaContext *> YWParser::IoContext::na() {
  return getRuleContexts<YWParser::NaContext>();
}

YWParser::NaContext* YWParser::IoContext::na(size_t i) {
  return getRuleContext<YWParser::NaContext>(i);
}


size_t YWParser::IoContext::getRuleIndex() const {
  return YWParser::RuleIo;
}

void YWParser::IoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIo(this);
}

void YWParser::IoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIo(this);
}

YWParser::IoContext* YWParser::io() {
  IoContext *_localctx = _tracker.createInstance<IoContext>(_ctx, getState());
  enterRule(_localctx, 8, YWParser::RuleIo);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(130);
    port();
    setState(137);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(132);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << YWParser::DQ)
          | (1ULL << YWParser::SQ)
          | (1ULL << YWParser::SPACE)
          | (1ULL << YWParser::SLASH)
          | (1ULL << YWParser::LEFTBRACE)
          | (1ULL << YWParser::RIGHTBRACE)
          | (1ULL << YWParser::NEWLINE)
          | (1ULL << YWParser::COLON)
          | (1ULL << YWParser::WORD)
          | (1ULL << YWParser::OTHER))) != 0)) {
          setState(131);
          na();
        }
        setState(134);
        portAttribute(); 
      }
      setState(139);
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

//----------------- PortContext ------------------------------------------------------------------

YWParser::PortContext::PortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::PortKeywordContext* YWParser::PortContext::portKeyword() {
  return getRuleContext<YWParser::PortKeywordContext>(0);
}

std::vector<YWParser::PortNameContext *> YWParser::PortContext::portName() {
  return getRuleContexts<YWParser::PortNameContext>();
}

YWParser::PortNameContext* YWParser::PortContext::portName(size_t i) {
  return getRuleContext<YWParser::PortNameContext>(i);
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
  enterRule(_localctx, 10, YWParser::RulePort);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(140);
    portKeyword();
    setState(147); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
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
              portName();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(149); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
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

YWParser::PortDescContext* YWParser::PortAttributeContext::portDesc() {
  return getRuleContext<YWParser::PortDescContext>(0);
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
  enterRule(_localctx, 12, YWParser::RulePortAttribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(154);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::DescKeyword: {
        enterOuterAlt(_localctx, 1);
        setState(151);
        portDesc();
        break;
      }

      case YWParser::AsKeyword: {
        enterOuterAlt(_localctx, 2);
        setState(152);
        alias();
        break;
      }

      case YWParser::FileKeyword:
      case YWParser::UriKeyword: {
        enterOuterAlt(_localctx, 3);
        setState(153);
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
  enterRule(_localctx, 14, YWParser::RuleAlias);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(YWParser::AsKeyword);
    setState(158); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(157);
      match(YWParser::SPACE);
      setState(160); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::SPACE);
    setState(162);
    dataName();
   
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
  enterRule(_localctx, 16, YWParser::RuleBegin);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    match(YWParser::BeginKeyword);
    setState(166); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(165);
      match(YWParser::SPACE);
      setState(168); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::SPACE);
    setState(170);
    blockName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockDescContext ------------------------------------------------------------------

YWParser::BlockDescContext::BlockDescContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::BlockDescContext::DescKeyword() {
  return getToken(YWParser::DescKeyword, 0);
}

YWParser::DescriptionContext* YWParser::BlockDescContext::description() {
  return getRuleContext<YWParser::DescriptionContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::BlockDescContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::BlockDescContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
}


size_t YWParser::BlockDescContext::getRuleIndex() const {
  return YWParser::RuleBlockDesc;
}

void YWParser::BlockDescContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockDesc(this);
}

void YWParser::BlockDescContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockDesc(this);
}

YWParser::BlockDescContext* YWParser::blockDesc() {
  BlockDescContext *_localctx = _tracker.createInstance<BlockDescContext>(_ctx, getState());
  enterRule(_localctx, 18, YWParser::RuleBlockDesc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(172);
    match(YWParser::DescKeyword);
    setState(174); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(173);
      match(YWParser::SPACE);
      setState(176); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::SPACE);
    setState(178);
    description();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PortDescContext ------------------------------------------------------------------

YWParser::PortDescContext::PortDescContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::PortDescContext::DescKeyword() {
  return getToken(YWParser::DescKeyword, 0);
}

YWParser::DescriptionContext* YWParser::PortDescContext::description() {
  return getRuleContext<YWParser::DescriptionContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::PortDescContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::PortDescContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
}


size_t YWParser::PortDescContext::getRuleIndex() const {
  return YWParser::RulePortDesc;
}

void YWParser::PortDescContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortDesc(this);
}

void YWParser::PortDescContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortDesc(this);
}

YWParser::PortDescContext* YWParser::portDesc() {
  PortDescContext *_localctx = _tracker.createInstance<PortDescContext>(_ctx, getState());
  enterRule(_localctx, 20, YWParser::RulePortDesc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    match(YWParser::DescKeyword);
    setState(182); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(181);
      match(YWParser::SPACE);
      setState(184); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == YWParser::SPACE);
    setState(186);
    description();
   
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
  enterRule(_localctx, 22, YWParser::RuleEnd);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    match(YWParser::EndKeyword);
    setState(195);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(190); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(189);
        match(YWParser::SPACE);
        setState(192); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == YWParser::SPACE);

      setState(194);
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
  enterRule(_localctx, 24, YWParser::RuleFile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(197);
    match(YWParser::FileKeyword);
    setState(199); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(198);
              match(YWParser::SPACE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(201); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(203);
    pathTemplate();
   
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
  enterRule(_localctx, 26, YWParser::RuleUri);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(YWParser::UriKeyword);
    setState(207); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(206);
              match(YWParser::SPACE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(209); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(211);
    uriTemplate();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MisplacedEndContext ------------------------------------------------------------------

YWParser::MisplacedEndContext::MisplacedEndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::MisplacedEndContext::EndKeyword() {
  return getToken(YWParser::EndKeyword, 0);
}


size_t YWParser::MisplacedEndContext::getRuleIndex() const {
  return YWParser::RuleMisplacedEnd;
}

void YWParser::MisplacedEndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMisplacedEnd(this);
}

void YWParser::MisplacedEndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMisplacedEnd(this);
}

YWParser::MisplacedEndContext* YWParser::misplacedEnd() {
  MisplacedEndContext *_localctx = _tracker.createInstance<MisplacedEndContext>(_ctx, getState());
  enterRule(_localctx, 28, YWParser::RuleMisplacedEnd);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(YWParser::EndKeyword);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MisplacedBeginChildContext ------------------------------------------------------------------

YWParser::MisplacedBeginChildContext::MisplacedBeginChildContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::MisplacedBeginChildContext::DescKeyword() {
  return getToken(YWParser::DescKeyword, 0);
}

tree::TerminalNode* YWParser::MisplacedBeginChildContext::InKeyword() {
  return getToken(YWParser::InKeyword, 0);
}

tree::TerminalNode* YWParser::MisplacedBeginChildContext::OutKeyword() {
  return getToken(YWParser::OutKeyword, 0);
}

tree::TerminalNode* YWParser::MisplacedBeginChildContext::ParamKeyword() {
  return getToken(YWParser::ParamKeyword, 0);
}


size_t YWParser::MisplacedBeginChildContext::getRuleIndex() const {
  return YWParser::RuleMisplacedBeginChild;
}

void YWParser::MisplacedBeginChildContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMisplacedBeginChild(this);
}

void YWParser::MisplacedBeginChildContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMisplacedBeginChild(this);
}

YWParser::MisplacedBeginChildContext* YWParser::misplacedBeginChild() {
  MisplacedBeginChildContext *_localctx = _tracker.createInstance<MisplacedBeginChildContext>(_ctx, getState());
  enterRule(_localctx, 30, YWParser::RuleMisplacedBeginChild);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YWParser::DescKeyword)
      | (1ULL << YWParser::InKeyword)
      | (1ULL << YWParser::OutKeyword)
      | (1ULL << YWParser::ParamKeyword))) != 0))) {
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

//----------------- MisplacedPortChildContext ------------------------------------------------------------------

YWParser::MisplacedPortChildContext::MisplacedPortChildContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::MisplacedPortChildContext::AsKeyword() {
  return getToken(YWParser::AsKeyword, 0);
}

tree::TerminalNode* YWParser::MisplacedPortChildContext::DescKeyword() {
  return getToken(YWParser::DescKeyword, 0);
}

tree::TerminalNode* YWParser::MisplacedPortChildContext::FileKeyword() {
  return getToken(YWParser::FileKeyword, 0);
}

tree::TerminalNode* YWParser::MisplacedPortChildContext::UriKeyword() {
  return getToken(YWParser::UriKeyword, 0);
}


size_t YWParser::MisplacedPortChildContext::getRuleIndex() const {
  return YWParser::RuleMisplacedPortChild;
}

void YWParser::MisplacedPortChildContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMisplacedPortChild(this);
}

void YWParser::MisplacedPortChildContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMisplacedPortChild(this);
}

YWParser::MisplacedPortChildContext* YWParser::misplacedPortChild() {
  MisplacedPortChildContext *_localctx = _tracker.createInstance<MisplacedPortChildContext>(_ctx, getState());
  enterRule(_localctx, 32, YWParser::RuleMisplacedPortChild);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YWParser::AsKeyword)
      | (1ULL << YWParser::DescKeyword)
      | (1ULL << YWParser::FileKeyword)
      | (1ULL << YWParser::UriKeyword))) != 0))) {
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

//----------------- MisplacedKeywordContext ------------------------------------------------------------------

YWParser::MisplacedKeywordContext::MisplacedKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::MisplacedEndContext* YWParser::MisplacedKeywordContext::misplacedEnd() {
  return getRuleContext<YWParser::MisplacedEndContext>(0);
}

YWParser::MisplacedBeginChildContext* YWParser::MisplacedKeywordContext::misplacedBeginChild() {
  return getRuleContext<YWParser::MisplacedBeginChildContext>(0);
}

YWParser::MisplacedPortChildContext* YWParser::MisplacedKeywordContext::misplacedPortChild() {
  return getRuleContext<YWParser::MisplacedPortChildContext>(0);
}


size_t YWParser::MisplacedKeywordContext::getRuleIndex() const {
  return YWParser::RuleMisplacedKeyword;
}

void YWParser::MisplacedKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMisplacedKeyword(this);
}

void YWParser::MisplacedKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMisplacedKeyword(this);
}

YWParser::MisplacedKeywordContext* YWParser::misplacedKeyword() {
  MisplacedKeywordContext *_localctx = _tracker.createInstance<MisplacedKeywordContext>(_ctx, getState());
  enterRule(_localctx, 34, YWParser::RuleMisplacedKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(222);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(219);
      misplacedEnd();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(220);
      misplacedBeginChild();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(221);
      misplacedPortChild();
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
  enterRule(_localctx, 36, YWParser::RuleResource);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(226);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::UriKeyword: {
        enterOuterAlt(_localctx, 1);
        setState(224);
        uri();
        break;
      }

      case YWParser::FileKeyword: {
        enterOuterAlt(_localctx, 2);
        setState(225);
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

//----------------- PortKeywordContext ------------------------------------------------------------------

YWParser::PortKeywordContext::PortKeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::InputKeywordContext* YWParser::PortKeywordContext::inputKeyword() {
  return getRuleContext<YWParser::InputKeywordContext>(0);
}

YWParser::OutputKeywordContext* YWParser::PortKeywordContext::outputKeyword() {
  return getRuleContext<YWParser::OutputKeywordContext>(0);
}


size_t YWParser::PortKeywordContext::getRuleIndex() const {
  return YWParser::RulePortKeyword;
}

void YWParser::PortKeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortKeyword(this);
}

void YWParser::PortKeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortKeyword(this);
}

YWParser::PortKeywordContext* YWParser::portKeyword() {
  PortKeywordContext *_localctx = _tracker.createInstance<PortKeywordContext>(_ctx, getState());
  enterRule(_localctx, 38, YWParser::RulePortKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(230);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::InKeyword:
      case YWParser::ParamKeyword: {
        enterOuterAlt(_localctx, 1);
        setState(228);
        inputKeyword();
        break;
      }

      case YWParser::OutKeyword: {
        enterOuterAlt(_localctx, 2);
        setState(229);
        outputKeyword();
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
  enterRule(_localctx, 40, YWParser::RuleInputKeyword);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
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
  enterRule(_localctx, 42, YWParser::RuleOutputKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(234);
    match(YWParser::OutKeyword);
   
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
  enterRule(_localctx, 44, YWParser::RuleBlockName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
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

YWParser::WordContext* YWParser::PortNameContext::word() {
  return getRuleContext<YWParser::WordContext>(0);
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
  enterRule(_localctx, 46, YWParser::RulePortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    word();
   
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
  enterRule(_localctx, 48, YWParser::RuleDataName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(240);
    phrase();
   
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
  enterRule(_localctx, 50, YWParser::RuleDescription);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(242);
    phrase();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathElementContext ------------------------------------------------------------------

YWParser::PathElementContext::PathElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<YWParser::PathConstantContext *> YWParser::PathElementContext::pathConstant() {
  return getRuleContexts<YWParser::PathConstantContext>();
}

YWParser::PathConstantContext* YWParser::PathElementContext::pathConstant(size_t i) {
  return getRuleContext<YWParser::PathConstantContext>(i);
}

std::vector<YWParser::PathVariableContext *> YWParser::PathElementContext::pathVariable() {
  return getRuleContexts<YWParser::PathVariableContext>();
}

YWParser::PathVariableContext* YWParser::PathElementContext::pathVariable(size_t i) {
  return getRuleContext<YWParser::PathVariableContext>(i);
}


size_t YWParser::PathElementContext::getRuleIndex() const {
  return YWParser::RulePathElement;
}

void YWParser::PathElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPathElement(this);
}

void YWParser::PathElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPathElement(this);
}

YWParser::PathElementContext* YWParser::pathElement() {
  PathElementContext *_localctx = _tracker.createInstance<PathElementContext>(_ctx, getState());
  enterRule(_localctx, 52, YWParser::RulePathElement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(246); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(246);
              _errHandler->sync(this);
              switch (_input->LA(1)) {
                case YWParser::WORD: {
                  setState(244);
                  pathConstant();
                  break;
                }

                case YWParser::LEFTBRACE: {
                  setState(245);
                  pathVariable();
                  break;
                }

              default:
                throw NoViableAltException(this);
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(248); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathVariableContext ------------------------------------------------------------------

YWParser::PathVariableContext::PathVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::PathVariableContext::LEFTBRACE() {
  return getToken(YWParser::LEFTBRACE, 0);
}

YWParser::VariableNameContext* YWParser::PathVariableContext::variableName() {
  return getRuleContext<YWParser::VariableNameContext>(0);
}

tree::TerminalNode* YWParser::PathVariableContext::RIGHTBRACE() {
  return getToken(YWParser::RIGHTBRACE, 0);
}


size_t YWParser::PathVariableContext::getRuleIndex() const {
  return YWParser::RulePathVariable;
}

void YWParser::PathVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPathVariable(this);
}

void YWParser::PathVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPathVariable(this);
}

YWParser::PathVariableContext* YWParser::pathVariable() {
  PathVariableContext *_localctx = _tracker.createInstance<PathVariableContext>(_ctx, getState());
  enterRule(_localctx, 54, YWParser::RulePathVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    match(YWParser::LEFTBRACE);
    setState(251);
    variableName();
    setState(252);
    match(YWParser::RIGHTBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathConstantContext ------------------------------------------------------------------

YWParser::PathConstantContext::PathConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::PathConstantContext::WORD() {
  return getToken(YWParser::WORD, 0);
}


size_t YWParser::PathConstantContext::getRuleIndex() const {
  return YWParser::RulePathConstant;
}

void YWParser::PathConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPathConstant(this);
}

void YWParser::PathConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPathConstant(this);
}

YWParser::PathConstantContext* YWParser::pathConstant() {
  PathConstantContext *_localctx = _tracker.createInstance<PathConstantContext>(_ctx, getState());
  enterRule(_localctx, 56, YWParser::RulePathConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    match(YWParser::WORD);
   
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

tree::TerminalNode* YWParser::VariableNameContext::WORD() {
  return getToken(YWParser::WORD, 0);
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
  enterRule(_localctx, 58, YWParser::RuleVariableName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    match(YWParser::WORD);
   
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

std::vector<tree::TerminalNode *> YWParser::PathTemplateContext::SLASH() {
  return getTokens(YWParser::SLASH);
}

tree::TerminalNode* YWParser::PathTemplateContext::SLASH(size_t i) {
  return getToken(YWParser::SLASH, i);
}

std::vector<YWParser::PathElementContext *> YWParser::PathTemplateContext::pathElement() {
  return getRuleContexts<YWParser::PathElementContext>();
}

YWParser::PathElementContext* YWParser::PathTemplateContext::pathElement(size_t i) {
  return getRuleContext<YWParser::PathElementContext>(i);
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
  enterRule(_localctx, 60, YWParser::RulePathTemplate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(259);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      setState(258);
      match(YWParser::SLASH);
      break;
    }

    }
    setState(262);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(261);
      pathElement();
      break;
    }

    }
    setState(268);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(264);
        match(YWParser::SLASH);
        setState(265);
        pathElement(); 
      }
      setState(270);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
    setState(272);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      setState(271);
      match(YWParser::SLASH);
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

std::vector<tree::TerminalNode *> YWParser::UriTemplateContext::SLASH() {
  return getTokens(YWParser::SLASH);
}

tree::TerminalNode* YWParser::UriTemplateContext::SLASH(size_t i) {
  return getToken(YWParser::SLASH, i);
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
  enterRule(_localctx, 62, YWParser::RuleUriTemplate);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(277);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      setState(274);
      scheme();
      setState(275);
      match(YWParser::COLON);
      break;
    }

    }
    setState(282);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    while (alt != 1 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1 + 1) {
        setState(279);
        match(YWParser::SLASH); 
      }
      setState(284);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx);
    }
    setState(285);
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

tree::TerminalNode* YWParser::SchemeContext::WORD() {
  return getToken(YWParser::WORD, 0);
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
  enterRule(_localctx, 64, YWParser::RuleScheme);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(YWParser::WORD);
   
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

YWParser::UnquotedPhraseContext* YWParser::PhraseContext::unquotedPhrase() {
  return getRuleContext<YWParser::UnquotedPhraseContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::PhraseContext::SQ() {
  return getTokens(YWParser::SQ);
}

tree::TerminalNode* YWParser::PhraseContext::SQ(size_t i) {
  return getToken(YWParser::SQ, i);
}

std::vector<tree::TerminalNode *> YWParser::PhraseContext::DQ() {
  return getTokens(YWParser::DQ);
}

tree::TerminalNode* YWParser::PhraseContext::DQ(size_t i) {
  return getToken(YWParser::DQ, i);
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
  enterRule(_localctx, 66, YWParser::RulePhrase);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(298);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::WORD: {
        enterOuterAlt(_localctx, 1);
        setState(289);
        unquotedPhrase();
        break;
      }

      case YWParser::SQ: {
        enterOuterAlt(_localctx, 2);
        setState(290);
        match(YWParser::SQ);
        setState(291);
        unquotedPhrase();
        setState(292);
        match(YWParser::SQ);
        break;
      }

      case YWParser::DQ: {
        enterOuterAlt(_localctx, 3);
        setState(294);
        match(YWParser::DQ);
        setState(295);
        unquotedPhrase();
        setState(296);
        match(YWParser::DQ);
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

//----------------- UnquotedPhraseContext ------------------------------------------------------------------

YWParser::UnquotedPhraseContext::UnquotedPhraseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> YWParser::UnquotedPhraseContext::WORD() {
  return getTokens(YWParser::WORD);
}

tree::TerminalNode* YWParser::UnquotedPhraseContext::WORD(size_t i) {
  return getToken(YWParser::WORD, i);
}

std::vector<tree::TerminalNode *> YWParser::UnquotedPhraseContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::UnquotedPhraseContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
}


size_t YWParser::UnquotedPhraseContext::getRuleIndex() const {
  return YWParser::RuleUnquotedPhrase;
}

void YWParser::UnquotedPhraseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnquotedPhrase(this);
}

void YWParser::UnquotedPhraseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnquotedPhrase(this);
}

YWParser::UnquotedPhraseContext* YWParser::unquotedPhrase() {
  UnquotedPhraseContext *_localctx = _tracker.createInstance<UnquotedPhraseContext>(_ctx, getState());
  enterRule(_localctx, 68, YWParser::RuleUnquotedPhrase);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(300);
    match(YWParser::WORD);
    setState(309);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(302); 
        _errHandler->sync(this);
        _la = _input->LA(1);
        do {
          setState(301);
          match(YWParser::SPACE);
          setState(304); 
          _errHandler->sync(this);
          _la = _input->LA(1);
        } while (_la == YWParser::SPACE);
        setState(306);
        match(YWParser::WORD); 
      }
      setState(311);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WordContext ------------------------------------------------------------------

YWParser::WordContext::WordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::UnquotedWordContext* YWParser::WordContext::unquotedWord() {
  return getRuleContext<YWParser::UnquotedWordContext>(0);
}

std::vector<tree::TerminalNode *> YWParser::WordContext::SQ() {
  return getTokens(YWParser::SQ);
}

tree::TerminalNode* YWParser::WordContext::SQ(size_t i) {
  return getToken(YWParser::SQ, i);
}

std::vector<tree::TerminalNode *> YWParser::WordContext::DQ() {
  return getTokens(YWParser::DQ);
}

tree::TerminalNode* YWParser::WordContext::DQ(size_t i) {
  return getToken(YWParser::DQ, i);
}


size_t YWParser::WordContext::getRuleIndex() const {
  return YWParser::RuleWord;
}

void YWParser::WordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWord(this);
}

void YWParser::WordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWord(this);
}

YWParser::WordContext* YWParser::word() {
  WordContext *_localctx = _tracker.createInstance<WordContext>(_ctx, getState());
  enterRule(_localctx, 70, YWParser::RuleWord);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(321);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::WORD: {
        enterOuterAlt(_localctx, 1);
        setState(312);
        unquotedWord();
        break;
      }

      case YWParser::SQ: {
        enterOuterAlt(_localctx, 2);
        setState(313);
        match(YWParser::SQ);
        setState(314);
        unquotedWord();
        setState(315);
        match(YWParser::SQ);
        break;
      }

      case YWParser::DQ: {
        enterOuterAlt(_localctx, 3);
        setState(317);
        match(YWParser::DQ);
        setState(318);
        unquotedWord();
        setState(319);
        match(YWParser::DQ);
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

//----------------- UnquotedWordContext ------------------------------------------------------------------

YWParser::UnquotedWordContext::UnquotedWordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::UnquotedWordContext::WORD() {
  return getToken(YWParser::WORD, 0);
}


size_t YWParser::UnquotedWordContext::getRuleIndex() const {
  return YWParser::RuleUnquotedWord;
}

void YWParser::UnquotedWordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnquotedWord(this);
}

void YWParser::UnquotedWordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnquotedWord(this);
}

YWParser::UnquotedWordContext* YWParser::unquotedWord() {
  UnquotedWordContext *_localctx = _tracker.createInstance<UnquotedWordContext>(_ctx, getState());
  enterRule(_localctx, 72, YWParser::RuleUnquotedWord);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(323);
    match(YWParser::WORD);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NaContext ------------------------------------------------------------------

YWParser::NaContext::NaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> YWParser::NaContext::SPACE() {
  return getTokens(YWParser::SPACE);
}

tree::TerminalNode* YWParser::NaContext::SPACE(size_t i) {
  return getToken(YWParser::SPACE, i);
}

std::vector<tree::TerminalNode *> YWParser::NaContext::NEWLINE() {
  return getTokens(YWParser::NEWLINE);
}

tree::TerminalNode* YWParser::NaContext::NEWLINE(size_t i) {
  return getToken(YWParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> YWParser::NaContext::DQ() {
  return getTokens(YWParser::DQ);
}

tree::TerminalNode* YWParser::NaContext::DQ(size_t i) {
  return getToken(YWParser::DQ, i);
}

std::vector<tree::TerminalNode *> YWParser::NaContext::SQ() {
  return getTokens(YWParser::SQ);
}

tree::TerminalNode* YWParser::NaContext::SQ(size_t i) {
  return getToken(YWParser::SQ, i);
}

std::vector<tree::TerminalNode *> YWParser::NaContext::WORD() {
  return getTokens(YWParser::WORD);
}

tree::TerminalNode* YWParser::NaContext::WORD(size_t i) {
  return getToken(YWParser::WORD, i);
}

std::vector<tree::TerminalNode *> YWParser::NaContext::COLON() {
  return getTokens(YWParser::COLON);
}

tree::TerminalNode* YWParser::NaContext::COLON(size_t i) {
  return getToken(YWParser::COLON, i);
}

std::vector<tree::TerminalNode *> YWParser::NaContext::SLASH() {
  return getTokens(YWParser::SLASH);
}

tree::TerminalNode* YWParser::NaContext::SLASH(size_t i) {
  return getToken(YWParser::SLASH, i);
}

std::vector<tree::TerminalNode *> YWParser::NaContext::LEFTBRACE() {
  return getTokens(YWParser::LEFTBRACE);
}

tree::TerminalNode* YWParser::NaContext::LEFTBRACE(size_t i) {
  return getToken(YWParser::LEFTBRACE, i);
}

std::vector<tree::TerminalNode *> YWParser::NaContext::RIGHTBRACE() {
  return getTokens(YWParser::RIGHTBRACE);
}

tree::TerminalNode* YWParser::NaContext::RIGHTBRACE(size_t i) {
  return getToken(YWParser::RIGHTBRACE, i);
}

std::vector<tree::TerminalNode *> YWParser::NaContext::OTHER() {
  return getTokens(YWParser::OTHER);
}

tree::TerminalNode* YWParser::NaContext::OTHER(size_t i) {
  return getToken(YWParser::OTHER, i);
}


size_t YWParser::NaContext::getRuleIndex() const {
  return YWParser::RuleNa;
}

void YWParser::NaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNa(this);
}

void YWParser::NaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNa(this);
}

YWParser::NaContext* YWParser::na() {
  NaContext *_localctx = _tracker.createInstance<NaContext>(_ctx, getState());
  enterRule(_localctx, 74, YWParser::RuleNa);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(326); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(325);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << YWParser::DQ)
        | (1ULL << YWParser::SQ)
        | (1ULL << YWParser::SPACE)
        | (1ULL << YWParser::SLASH)
        | (1ULL << YWParser::LEFTBRACE)
        | (1ULL << YWParser::RIGHTBRACE)
        | (1ULL << YWParser::NEWLINE)
        | (1ULL << YWParser::COLON)
        | (1ULL << YWParser::WORD)
        | (1ULL << YWParser::OTHER))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(328); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YWParser::DQ)
      | (1ULL << YWParser::SQ)
      | (1ULL << YWParser::SPACE)
      | (1ULL << YWParser::SLASH)
      | (1ULL << YWParser::LEFTBRACE)
      | (1ULL << YWParser::RIGHTBRACE)
      | (1ULL << YWParser::NEWLINE)
      | (1ULL << YWParser::COLON)
      | (1ULL << YWParser::WORD)
      | (1ULL << YWParser::OTHER))) != 0));
   
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
  "script", "block", "nestedBlocks", "blockAttribute", "io", "port", "portAttribute", 
  "alias", "begin", "blockDesc", "portDesc", "end", "file", "uri", "misplacedEnd", 
  "misplacedBeginChild", "misplacedPortChild", "misplacedKeyword", "resource", 
  "portKeyword", "inputKeyword", "outputKeyword", "blockName", "portName", 
  "dataName", "description", "pathElement", "pathVariable", "pathConstant", 
  "variableName", "pathTemplate", "uriTemplate", "scheme", "phrase", "unquotedPhrase", 
  "word", "unquotedWord", "na"
};

std::vector<std::string> YWParser::_literalNames = {
  "", "", "", "", "", "", "", "", "", "", "'\"'", "'''", "", "'/'", "'{'", 
  "'}'", "", "':'"
};

std::vector<std::string> YWParser::_symbolicNames = {
  "", "AsKeyword", "BeginKeyword", "DescKeyword", "EndKeyword", "FileKeyword", 
  "InKeyword", "OutKeyword", "ParamKeyword", "UriKeyword", "DQ", "SQ", "SPACE", 
  "SLASH", "LEFTBRACE", "RIGHTBRACE", "NEWLINE", "COLON", "WORD", "OTHER"
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
    0x3, 0x15, 0x14d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x3, 0x2, 0x5, 0x2, 
    0x50, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x54, 0xa, 0x2, 0x3, 0x2, 
    0x7, 0x2, 0x57, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x5a, 0xb, 0x2, 0x3, 0x2, 
    0x5, 0x2, 0x5d, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x63, 0xa, 0x3, 0x3, 0x3, 0x7, 0x3, 0x66, 0xa, 0x3, 0xc, 0x3, 0xe, 
    0x3, 0x69, 0xb, 0x3, 0x3, 0x3, 0x5, 0x3, 0x6c, 0xa, 0x3, 0x3, 0x3, 0x7, 
    0x3, 0x6f, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x72, 0xb, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x76, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x5, 0x4, 
    0x7b, 0xa, 0x4, 0x3, 0x4, 0x7, 0x4, 0x7e, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 
    0x81, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x87, 
    0xa, 0x6, 0x3, 0x6, 0x7, 0x6, 0x8a, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x8d, 
    0xb, 0x6, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x91, 0xa, 0x7, 0xd, 0x7, 0xe, 
    0x7, 0x92, 0x3, 0x7, 0x6, 0x7, 0x96, 0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 0x97, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x9d, 0xa, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x6, 0x9, 0xa1, 0xa, 0x9, 0xd, 0x9, 0xe, 0x9, 0xa2, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x6, 0xa, 0xa9, 0xa, 0xa, 0xd, 0xa, 0xe, 0xa, 
    0xaa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x6, 0xb, 0xb1, 0xa, 0xb, 
    0xd, 0xb, 0xe, 0xb, 0xb2, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x6, 
    0xc, 0xb9, 0xa, 0xc, 0xd, 0xc, 0xe, 0xc, 0xba, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x6, 0xd, 0xc1, 0xa, 0xd, 0xd, 0xd, 0xe, 0xd, 0xc2, 0x3, 
    0xd, 0x5, 0xd, 0xc6, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x6, 0xe, 0xca, 0xa, 
    0xe, 0xd, 0xe, 0xe, 0xe, 0xcb, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 
    0x6, 0xf, 0xd2, 0xa, 0xf, 0xd, 0xf, 0xe, 0xf, 0xd3, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0xe1, 0xa, 0x13, 0x3, 0x14, 0x3, 
    0x14, 0x5, 0x14, 0xe5, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 0xe9, 
    0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1c, 0x3, 0x1c, 0x6, 0x1c, 0xf9, 0xa, 0x1c, 0xd, 0x1c, 0xe, 0x1c, 
    0xfa, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x5, 0x20, 0x106, 0xa, 0x20, 0x3, 0x20, 
    0x5, 0x20, 0x109, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x10d, 
    0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x110, 0xb, 0x20, 0x3, 0x20, 0x5, 0x20, 
    0x113, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x118, 
    0xa, 0x21, 0x3, 0x21, 0x7, 0x21, 0x11b, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 
    0x11e, 0xb, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x5, 0x23, 0x12d, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 
    0x6, 0x24, 0x131, 0xa, 0x24, 0xd, 0x24, 0xe, 0x24, 0x132, 0x3, 0x24, 
    0x7, 0x24, 0x136, 0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x139, 0xb, 0x24, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
    0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x144, 0xa, 0x25, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x27, 0x6, 0x27, 0x149, 0xa, 0x27, 0xd, 0x27, 0xe, 0x27, 
    0x14a, 0x3, 0x27, 0x3, 0x11c, 0x2, 0x28, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 
    0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x2, 0x6, 0x4, 0x2, 
    0x5, 0x5, 0x8, 0xa, 0x6, 0x2, 0x3, 0x3, 0x5, 0x5, 0x7, 0x7, 0xb, 0xb, 
    0x4, 0x2, 0x8, 0x8, 0xa, 0xa, 0x3, 0x2, 0xc, 0x15, 0x2, 0x152, 0x2, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x4, 0x60, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7f, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x82, 0x3, 0x2, 0x2, 0x2, 0xa, 0x84, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x8e, 0x3, 0x2, 0x2, 0x2, 0xe, 0x9c, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x12, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0xae, 0x3, 0x2, 0x2, 0x2, 0x16, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x18, 0xbe, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xcf, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x20, 0xd9, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x24, 0xe0, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x28, 0xe8, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0xea, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xec, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0x30, 0xf0, 0x3, 0x2, 0x2, 0x2, 0x32, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0xf4, 0x3, 0x2, 0x2, 0x2, 0x36, 0xf8, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x100, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x102, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x105, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x117, 0x3, 0x2, 0x2, 0x2, 0x42, 0x121, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x46, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x143, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x145, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x148, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x50, 0x5, 0x4c, 0x27, 0x2, 0x4f, 0x4e, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 
    0x2, 0x2, 0x51, 0x58, 0x5, 0x4, 0x3, 0x2, 0x52, 0x54, 0x5, 0x4c, 0x27, 
    0x2, 0x53, 0x52, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x57, 0x5, 0x4, 0x3, 0x2, 0x56, 
    0x53, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 
    0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5c, 0x3, 
    0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5d, 0x5, 0x4c, 
    0x27, 0x2, 0x5c, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x3, 0x2, 0x2, 
    0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x2, 0x2, 0x3, 
    0x5f, 0x3, 0x3, 0x2, 0x2, 0x2, 0x60, 0x67, 0x5, 0x12, 0xa, 0x2, 0x61, 
    0x63, 0x5, 0x4c, 0x27, 0x2, 0x62, 0x61, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 
    0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x66, 0x5, 
    0x8, 0x5, 0x2, 0x65, 0x62, 0x3, 0x2, 0x2, 0x2, 0x66, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x70, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x6c, 0x5, 0x4c, 0x27, 0x2, 0x6b, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6b, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 
    0x5, 0xa, 0x6, 0x2, 0x6e, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x72, 0x3, 
    0x2, 0x2, 0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 
    0x2, 0x2, 0x71, 0x73, 0x3, 0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 
    0x2, 0x73, 0x75, 0x5, 0x6, 0x4, 0x2, 0x74, 0x76, 0x5, 0x4c, 0x27, 0x2, 
    0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x5, 0x18, 0xd, 0x2, 0x78, 0x5, 
    0x3, 0x2, 0x2, 0x2, 0x79, 0x7b, 0x5, 0x4c, 0x27, 0x2, 0x7a, 0x79, 0x3, 
    0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x7c, 0x7e, 0x5, 0x4, 0x3, 0x2, 0x7d, 0x7a, 0x3, 0x2, 0x2, 
    0x2, 0x7e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x7, 0x3, 0x2, 0x2, 0x2, 0x81, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x5, 0x14, 0xb, 0x2, 0x83, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x84, 0x8b, 0x5, 0xc, 0x7, 0x2, 0x85, 0x87, 0x5, 
    0x4c, 0x27, 0x2, 0x86, 0x85, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 
    0x2, 0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8a, 0x5, 0xe, 0x8, 
    0x2, 0x89, 0x86, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x8b, 0x89, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x95, 
    0x5, 0x28, 0x15, 0x2, 0x8f, 0x91, 0x7, 0xe, 0x2, 0x2, 0x90, 0x8f, 0x3, 
    0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 
    0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x3, 0x2, 0x2, 
    0x2, 0x94, 0x96, 0x5, 0x30, 0x19, 0x2, 0x95, 0x90, 0x3, 0x2, 0x2, 0x2, 
    0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x97, 
    0x98, 0x3, 0x2, 0x2, 0x2, 0x98, 0xd, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9d, 
    0x5, 0x16, 0xc, 0x2, 0x9a, 0x9d, 0x5, 0x10, 0x9, 0x2, 0x9b, 0x9d, 0x5, 
    0x26, 0x14, 0x2, 0x9c, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9a, 0x3, 0x2, 
    0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0xa0, 0x7, 0x3, 0x2, 0x2, 0x9f, 0xa1, 0x7, 0xe, 0x2, 0x2, 
    0xa0, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 
    0xa0, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 
    0x3, 0x2, 0x2, 0x2, 0xa4, 0xa5, 0x5, 0x32, 0x1a, 0x2, 0xa5, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0xa6, 0xa8, 0x7, 0x4, 0x2, 0x2, 0xa7, 0xa9, 0x7, 0xe, 
    0x2, 0x2, 0xa8, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x3, 0x2, 0x2, 
    0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x3, 0x2, 0x2, 0x2, 
    0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 0xad, 0x5, 0x2e, 0x18, 0x2, 0xad, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb0, 0x7, 0x5, 0x2, 0x2, 0xaf, 0xb1, 
    0x7, 0xe, 0x2, 0x2, 0xb0, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 
    0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb5, 0x5, 0x34, 0x1b, 
    0x2, 0xb5, 0x15, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb8, 0x7, 0x5, 0x2, 0x2, 
    0xb7, 0xb9, 0x7, 0xe, 0x2, 0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 
    0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 
    0x3, 0x2, 0x2, 0x2, 0xbb, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x5, 
    0x34, 0x1b, 0x2, 0xbd, 0x17, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc5, 0x7, 0x6, 
    0x2, 0x2, 0xbf, 0xc1, 0x7, 0xe, 0x2, 0x2, 0xc0, 0xbf, 0x3, 0x2, 0x2, 
    0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 
    0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 
    0xc6, 0x5, 0x2e, 0x18, 0x2, 0xc5, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0xc6, 0x19, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc9, 0x7, 
    0x7, 0x2, 0x2, 0xc8, 0xca, 0x7, 0xe, 0x2, 0x2, 0xc9, 0xc8, 0x3, 0x2, 
    0x2, 0x2, 0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 0x2, 
    0xcd, 0xce, 0x5, 0x3e, 0x20, 0x2, 0xce, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xd1, 0x7, 0xb, 0x2, 0x2, 0xd0, 0xd2, 0x7, 0xe, 0x2, 0x2, 0xd1, 0xd0, 
    0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 
    0x2, 0x2, 0xd5, 0xd6, 0x5, 0x40, 0x21, 0x2, 0xd6, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0xd7, 0xd8, 0x7, 0x6, 0x2, 0x2, 0xd8, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0xd9, 0xda, 0x9, 0x2, 0x2, 0x2, 0xda, 0x21, 0x3, 0x2, 0x2, 0x2, 0xdb, 
    0xdc, 0x9, 0x3, 0x2, 0x2, 0xdc, 0x23, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xe1, 
    0x5, 0x1e, 0x10, 0x2, 0xde, 0xe1, 0x5, 0x20, 0x11, 0x2, 0xdf, 0xe1, 
    0x5, 0x22, 0x12, 0x2, 0xe0, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe1, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0xe2, 0xe5, 0x5, 0x1c, 0xf, 0x2, 0xe3, 0xe5, 0x5, 0x1a, 0xe, 
    0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe3, 0x3, 0x2, 0x2, 0x2, 
    0xe5, 0x27, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe9, 0x5, 0x2a, 0x16, 0x2, 0xe7, 
    0xe9, 0x5, 0x2c, 0x17, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe7, 
    0x3, 0x2, 0x2, 0x2, 0xe9, 0x29, 0x3, 0x2, 0x2, 0x2, 0xea, 0xeb, 0x9, 
    0x4, 0x2, 0x2, 0xeb, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 0x9, 
    0x2, 0x2, 0xed, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x5, 0x44, 0x23, 
    0x2, 0xef, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x5, 0x48, 0x25, 0x2, 
    0xf1, 0x31, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 0x5, 0x44, 0x23, 0x2, 0xf3, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf5, 0x5, 0x44, 0x23, 0x2, 0xf5, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0xf6, 0xf9, 0x5, 0x3a, 0x1e, 0x2, 0xf7, 0xf9, 0x5, 
    0x38, 0x1d, 0x2, 0xf8, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf7, 0x3, 0x2, 
    0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 
    0x2, 0xfa, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfb, 0x37, 0x3, 0x2, 0x2, 0x2, 
    0xfc, 0xfd, 0x7, 0x10, 0x2, 0x2, 0xfd, 0xfe, 0x5, 0x3c, 0x1f, 0x2, 0xfe, 
    0xff, 0x7, 0x11, 0x2, 0x2, 0xff, 0x39, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 
    0x7, 0x14, 0x2, 0x2, 0x101, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 
    0x7, 0x14, 0x2, 0x2, 0x103, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x104, 0x106, 
    0x7, 0xf, 0x2, 0x2, 0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0x108, 0x3, 0x2, 0x2, 0x2, 0x107, 0x109, 
    0x5, 0x36, 0x1c, 0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 
    0x3, 0x2, 0x2, 0x2, 0x109, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 
    0x7, 0xf, 0x2, 0x2, 0x10b, 0x10d, 0x5, 0x36, 0x1c, 0x2, 0x10c, 0x10a, 
    0x3, 0x2, 0x2, 0x2, 0x10d, 0x110, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10c, 
    0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x112, 
    0x3, 0x2, 0x2, 0x2, 0x110, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x111, 0x113, 
    0x7, 0xf, 0x2, 0x2, 0x112, 0x111, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 
    0x3, 0x2, 0x2, 0x2, 0x113, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x5, 
    0x42, 0x22, 0x2, 0x115, 0x116, 0x7, 0x13, 0x2, 0x2, 0x116, 0x118, 0x3, 
    0x2, 0x2, 0x2, 0x117, 0x114, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 0x3, 
    0x2, 0x2, 0x2, 0x118, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11b, 0x7, 
    0xf, 0x2, 0x2, 0x11a, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11e, 0x3, 
    0x2, 0x2, 0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11a, 0x3, 
    0x2, 0x2, 0x2, 0x11d, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11c, 0x3, 
    0x2, 0x2, 0x2, 0x11f, 0x120, 0x5, 0x3e, 0x20, 0x2, 0x120, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x121, 0x122, 0x7, 0x14, 0x2, 0x2, 0x122, 0x43, 0x3, 
    0x2, 0x2, 0x2, 0x123, 0x12d, 0x5, 0x46, 0x24, 0x2, 0x124, 0x125, 0x7, 
    0xd, 0x2, 0x2, 0x125, 0x126, 0x5, 0x46, 0x24, 0x2, 0x126, 0x127, 0x7, 
    0xd, 0x2, 0x2, 0x127, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x7, 
    0xc, 0x2, 0x2, 0x129, 0x12a, 0x5, 0x46, 0x24, 0x2, 0x12a, 0x12b, 0x7, 
    0xc, 0x2, 0x2, 0x12b, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x123, 0x3, 
    0x2, 0x2, 0x2, 0x12c, 0x124, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x128, 0x3, 
    0x2, 0x2, 0x2, 0x12d, 0x45, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x137, 0x7, 0x14, 
    0x2, 0x2, 0x12f, 0x131, 0x7, 0xe, 0x2, 0x2, 0x130, 0x12f, 0x3, 0x2, 
    0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x130, 0x3, 0x2, 
    0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 0x3, 0x2, 
    0x2, 0x2, 0x134, 0x136, 0x7, 0x14, 0x2, 0x2, 0x135, 0x130, 0x3, 0x2, 
    0x2, 0x2, 0x136, 0x139, 0x3, 0x2, 0x2, 0x2, 0x137, 0x135, 0x3, 0x2, 
    0x2, 0x2, 0x137, 0x138, 0x3, 0x2, 0x2, 0x2, 0x138, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x144, 0x5, 0x4a, 0x26, 
    0x2, 0x13b, 0x13c, 0x7, 0xd, 0x2, 0x2, 0x13c, 0x13d, 0x5, 0x4a, 0x26, 
    0x2, 0x13d, 0x13e, 0x7, 0xd, 0x2, 0x2, 0x13e, 0x144, 0x3, 0x2, 0x2, 
    0x2, 0x13f, 0x140, 0x7, 0xc, 0x2, 0x2, 0x140, 0x141, 0x5, 0x4a, 0x26, 
    0x2, 0x141, 0x142, 0x7, 0xc, 0x2, 0x2, 0x142, 0x144, 0x3, 0x2, 0x2, 
    0x2, 0x143, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x143, 0x13b, 0x3, 0x2, 0x2, 
    0x2, 0x143, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x144, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x145, 0x146, 0x7, 0x14, 0x2, 0x2, 0x146, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x147, 0x149, 0x9, 0x5, 0x2, 0x2, 0x148, 0x147, 0x3, 0x2, 0x2, 0x2, 
    0x149, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x148, 0x3, 0x2, 0x2, 0x2, 
    0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x4f, 0x53, 0x58, 0x5c, 0x62, 0x67, 0x6b, 0x70, 0x75, 0x7a, 0x7f, 0x86, 
    0x8b, 0x92, 0x97, 0x9c, 0xa2, 0xaa, 0xb2, 0xba, 0xc2, 0xc5, 0xcb, 0xd3, 
    0xe0, 0xe4, 0xe8, 0xf8, 0xfa, 0x105, 0x108, 0x10e, 0x112, 0x117, 0x11c, 
    0x12c, 0x132, 0x137, 0x143, 0x14a, 
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
