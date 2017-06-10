
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
    while (_la == YWParser::T__1) {
      setState(60);
      block();
      setState(65);
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

YWParser::BeginKeywordContext* YWParser::BlockContext::beginKeyword() {
  return getRuleContext<YWParser::BeginKeywordContext>(0);
}

std::vector<YWParser::BlockNameContext *> YWParser::BlockContext::blockName() {
  return getRuleContexts<YWParser::BlockNameContext>();
}

YWParser::BlockNameContext* YWParser::BlockContext::blockName(size_t i) {
  return getRuleContext<YWParser::BlockNameContext>(i);
}

YWParser::EndKeywordContext* YWParser::BlockContext::endKeyword() {
  return getRuleContext<YWParser::EndKeywordContext>(0);
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
    enterOuterAlt(_localctx, 1);
    setState(66);
    beginKeyword();
    setState(67);
    blockName();
    setState(71);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << YWParser::T__2)
      | (1ULL << YWParser::T__5)
      | (1ULL << YWParser::T__6)
      | (1ULL << YWParser::T__7)
      | (1ULL << YWParser::T__8)
      | (1ULL << YWParser::T__10))) != 0)) {
      setState(68);
      blockAttribute();
      setState(73);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(77);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == YWParser::T__1) {
      setState(74);
      block();
      setState(79);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(80);
    endKeyword();
    setState(82);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YWParser::ID) {
      setState(81);
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

//----------------- BlockAttributeContext ------------------------------------------------------------------

YWParser::BlockAttributeContext::BlockAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::DescriptionContext* YWParser::BlockAttributeContext::description() {
  return getRuleContext<YWParser::DescriptionContext>(0);
}

YWParser::PortContext* YWParser::BlockAttributeContext::port() {
  return getRuleContext<YWParser::PortContext>(0);
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
    setState(87);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__10: {
        enterOuterAlt(_localctx, 1);
        setState(84);
        description();
        break;
      }

      case YWParser::T__5:
      case YWParser::T__6:
      case YWParser::T__7:
      case YWParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(85);
        port();
        break;
      }

      case YWParser::T__2: {
        enterOuterAlt(_localctx, 3);
        setState(86);
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

//----------------- DescriptionContext ------------------------------------------------------------------

YWParser::DescriptionContext::DescriptionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::DescKeywordContext* YWParser::DescriptionContext::descKeyword() {
  return getRuleContext<YWParser::DescKeywordContext>(0);
}

YWParser::TextContext* YWParser::DescriptionContext::text() {
  return getRuleContext<YWParser::TextContext>(0);
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
  enterRule(_localctx, 6, YWParser::RuleDescription);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    descKeyword();
    setState(90);
    text();
   
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
  enterRule(_localctx, 8, YWParser::RulePort);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(94);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__5:
      case YWParser::T__7: {
        setState(92);
        inputPortKeyword();
        break;
      }

      case YWParser::T__6:
      case YWParser::T__8: {
        setState(93);
        outputPortKeyword();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(103); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(96);
      portName();
      setState(100);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(97);
          portAttribute(); 
        }
        setState(102);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
      }
      setState(105); 
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

//----------------- CallContext ------------------------------------------------------------------

YWParser::CallContext::CallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::CallKeywordContext* YWParser::CallContext::callKeyword() {
  return getRuleContext<YWParser::CallKeywordContext>(0);
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
  enterRule(_localctx, 10, YWParser::RuleCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    callKeyword();
    setState(109); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(108);
      blockName();
      setState(111); 
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
  enterRule(_localctx, 12, YWParser::RuleInputPortKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(115);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__5: {
        enterOuterAlt(_localctx, 1);
        setState(113);
        inKeyword();
        break;
      }

      case YWParser::T__7: {
        enterOuterAlt(_localctx, 2);
        setState(114);
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
  enterRule(_localctx, 14, YWParser::RuleOutputPortKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__6: {
        enterOuterAlt(_localctx, 1);
        setState(117);
        outKeyword();
        break;
      }

      case YWParser::T__8: {
        enterOuterAlt(_localctx, 2);
        setState(118);
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

//----------------- PortAttributeContext ------------------------------------------------------------------

YWParser::PortAttributeContext::PortAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::DescriptionContext* YWParser::PortAttributeContext::description() {
  return getRuleContext<YWParser::DescriptionContext>(0);
}

YWParser::PortAliasContext* YWParser::PortAttributeContext::portAlias() {
  return getRuleContext<YWParser::PortAliasContext>(0);
}

YWParser::ResourceDeclContext* YWParser::PortAttributeContext::resourceDecl() {
  return getRuleContext<YWParser::ResourceDeclContext>(0);
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
  enterRule(_localctx, 16, YWParser::RulePortAttribute);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(124);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__10: {
        enterOuterAlt(_localctx, 1);
        setState(121);
        description();
        break;
      }

      case YWParser::T__0: {
        enterOuterAlt(_localctx, 2);
        setState(122);
        portAlias();
        break;
      }

      case YWParser::T__4:
      case YWParser::T__9: {
        enterOuterAlt(_localctx, 3);
        setState(123);
        resourceDecl();
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

//----------------- PortAliasContext ------------------------------------------------------------------

YWParser::PortAliasContext::PortAliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::AsKeywordContext* YWParser::PortAliasContext::asKeyword() {
  return getRuleContext<YWParser::AsKeywordContext>(0);
}

YWParser::DataNameContext* YWParser::PortAliasContext::dataName() {
  return getRuleContext<YWParser::DataNameContext>(0);
}


size_t YWParser::PortAliasContext::getRuleIndex() const {
  return YWParser::RulePortAlias;
}

void YWParser::PortAliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPortAlias(this);
}

void YWParser::PortAliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPortAlias(this);
}

YWParser::PortAliasContext* YWParser::portAlias() {
  PortAliasContext *_localctx = _tracker.createInstance<PortAliasContext>(_ctx, getState());
  enterRule(_localctx, 18, YWParser::RulePortAlias);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    asKeyword();
    setState(127);
    dataName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResourceDeclContext ------------------------------------------------------------------

YWParser::ResourceDeclContext::ResourceDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::UriDeclContext* YWParser::ResourceDeclContext::uriDecl() {
  return getRuleContext<YWParser::UriDeclContext>(0);
}

YWParser::FileDeclContext* YWParser::ResourceDeclContext::fileDecl() {
  return getRuleContext<YWParser::FileDeclContext>(0);
}


size_t YWParser::ResourceDeclContext::getRuleIndex() const {
  return YWParser::RuleResourceDecl;
}

void YWParser::ResourceDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResourceDecl(this);
}

void YWParser::ResourceDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResourceDecl(this);
}

YWParser::ResourceDeclContext* YWParser::resourceDecl() {
  ResourceDeclContext *_localctx = _tracker.createInstance<ResourceDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, YWParser::RuleResourceDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(131);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case YWParser::T__9: {
        enterOuterAlt(_localctx, 1);
        setState(129);
        uriDecl();
        break;
      }

      case YWParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(130);
        fileDecl();
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

//----------------- UriDeclContext ------------------------------------------------------------------

YWParser::UriDeclContext::UriDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::UriKeywordContext* YWParser::UriDeclContext::uriKeyword() {
  return getRuleContext<YWParser::UriKeywordContext>(0);
}

YWParser::UriTemplateContext* YWParser::UriDeclContext::uriTemplate() {
  return getRuleContext<YWParser::UriTemplateContext>(0);
}


size_t YWParser::UriDeclContext::getRuleIndex() const {
  return YWParser::RuleUriDecl;
}

void YWParser::UriDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUriDecl(this);
}

void YWParser::UriDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUriDecl(this);
}

YWParser::UriDeclContext* YWParser::uriDecl() {
  UriDeclContext *_localctx = _tracker.createInstance<UriDeclContext>(_ctx, getState());
  enterRule(_localctx, 22, YWParser::RuleUriDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(133);
    uriKeyword();
    setState(134);
    uriTemplate();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FileDeclContext ------------------------------------------------------------------

YWParser::FileDeclContext::FileDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

YWParser::FileKeywordContext* YWParser::FileDeclContext::fileKeyword() {
  return getRuleContext<YWParser::FileKeywordContext>(0);
}

tree::TerminalNode* YWParser::FileDeclContext::PATH_TEMPLATE() {
  return getToken(YWParser::PATH_TEMPLATE, 0);
}


size_t YWParser::FileDeclContext::getRuleIndex() const {
  return YWParser::RuleFileDecl;
}

void YWParser::FileDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFileDecl(this);
}

void YWParser::FileDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFileDecl(this);
}

YWParser::FileDeclContext* YWParser::fileDecl() {
  FileDeclContext *_localctx = _tracker.createInstance<FileDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, YWParser::RuleFileDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    fileKeyword();
    setState(137);
    match(YWParser::PATH_TEMPLATE);
   
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
  enterRule(_localctx, 26, YWParser::RuleAsKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
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
  enterRule(_localctx, 28, YWParser::RuleBeginKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
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
  enterRule(_localctx, 30, YWParser::RuleCallKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(143);
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
  enterRule(_localctx, 32, YWParser::RuleEndKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
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
  enterRule(_localctx, 34, YWParser::RuleFileKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(147);
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
  enterRule(_localctx, 36, YWParser::RuleInKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
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
  enterRule(_localctx, 38, YWParser::RuleOutKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
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
  enterRule(_localctx, 40, YWParser::RuleParamKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
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
  enterRule(_localctx, 42, YWParser::RuleReturnKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
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
  enterRule(_localctx, 44, YWParser::RuleUriKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(YWParser::T__9);
   
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
  enterRule(_localctx, 46, YWParser::RuleDescKeyword);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
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
  enterRule(_localctx, 48, YWParser::RuleBlockName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
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
  enterRule(_localctx, 50, YWParser::RulePortName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
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
  enterRule(_localctx, 52, YWParser::RuleDataName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
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
  enterRule(_localctx, 54, YWParser::RuleUriTemplate);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == YWParser::T__12

    || _la == YWParser::T__13) {
      setState(167);
      scheme();
      setState(168);
      match(YWParser::T__11);
    }
    setState(172);
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
  enterRule(_localctx, 56, YWParser::RuleScheme);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
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

//----------------- TextContext ------------------------------------------------------------------

YWParser::TextContext::TextContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* YWParser::TextContext::ID() {
  return getToken(YWParser::ID, 0);
}


size_t YWParser::TextContext::getRuleIndex() const {
  return YWParser::RuleText;
}

void YWParser::TextContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterText(this);
}

void YWParser::TextContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<YWListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitText(this);
}

YWParser::TextContext* YWParser::text() {
  TextContext *_localctx = _tracker.createInstance<TextContext>(_ctx, getState());
  enterRule(_localctx, 58, YWParser::RuleText);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(176);
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
  "script", "block", "blockAttribute", "description", "port", "call", "inputPortKeyword", 
  "outputPortKeyword", "portAttribute", "portAlias", "resourceDecl", "uriDecl", 
  "fileDecl", "asKeyword", "beginKeyword", "callKeyword", "endKeyword", 
  "fileKeyword", "inKeyword", "outKeyword", "paramKeyword", "returnKeyword", 
  "uriKeyword", "descKeyword", "blockName", "portName", "dataName", "uriTemplate", 
  "scheme", "text"
};

std::vector<std::string> YWParser::_literalNames = {
  "", "'@as'", "'@begin'", "'@call'", "'@end'", "'@file'", "'@in'", "'@out'", 
  "'@param'", "'@return'", "'@uri'", "'@desc'", "':'", "'file'", "'http'"
};

std::vector<std::string> YWParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "ID", "PATH_TEMPLATE"
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
    0x3, 0x12, 0xb5, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 
    0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 
    0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 
    0x9, 0x1f, 0x3, 0x2, 0x7, 0x2, 0x40, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x43, 
    0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x48, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x4b, 0xb, 0x3, 0x3, 0x3, 0x7, 0x3, 0x4e, 0xa, 0x3, 0xc, 
    0x3, 0xe, 0x3, 0x51, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x55, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5a, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x61, 0xa, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x65, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x68, 0xb, 
    0x6, 0x6, 0x6, 0x6a, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x6b, 0x3, 0x7, 0x3, 
    0x7, 0x6, 0x7, 0x70, 0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 0x71, 0x3, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0x76, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x7a, 0xa, 
    0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x7f, 0xa, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x86, 0xa, 0xc, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0xad, 0xa, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x2, 0x2, 0x20, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x2, 0x3, 0x3, 0x2, 
    0xf, 0x10, 0x2, 0xa6, 0x2, 0x41, 0x3, 0x2, 0x2, 0x2, 0x4, 0x44, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x59, 0x3, 0x2, 0x2, 0x2, 0x8, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x60, 0x3, 0x2, 0x2, 0x2, 0xc, 0x6d, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x75, 0x3, 0x2, 0x2, 0x2, 0x10, 0x79, 0x3, 0x2, 0x2, 0x2, 0x12, 0x7e, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x80, 0x3, 0x2, 0x2, 0x2, 0x16, 0x85, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x87, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x8a, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x91, 0x3, 0x2, 0x2, 0x2, 0x22, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0x95, 0x3, 0x2, 0x2, 0x2, 0x26, 0x97, 0x3, 0x2, 0x2, 0x2, 0x28, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x30, 0xa1, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x34, 0xa5, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x38, 0xac, 0x3, 0x2, 0x2, 
    0x2, 0x3a, 0xb0, 0x3, 0x2, 0x2, 0x2, 0x3c, 0xb2, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x40, 0x5, 0x4, 0x3, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x3, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x45, 0x5, 0x1e, 0x10, 0x2, 0x45, 0x49, 0x5, 0x32, 
    0x1a, 0x2, 0x46, 0x48, 0x5, 0x6, 0x4, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x48, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x49, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4b, 
    0x49, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4e, 0x5, 0x4, 0x3, 0x2, 0x4d, 0x4c, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 0x3, 0x2, 
    0x2, 0x2, 0x51, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x54, 0x5, 0x22, 0x12, 
    0x2, 0x53, 0x55, 0x5, 0x32, 0x1a, 0x2, 0x54, 0x53, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x5, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x5a, 0x5, 0x8, 0x5, 0x2, 0x57, 0x5a, 0x5, 0xa, 0x6, 0x2, 0x58, 0x5a, 
    0x5, 0xc, 0x7, 0x2, 0x59, 0x56, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x59, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x5b, 0x5c, 0x5, 0x30, 0x19, 0x2, 0x5c, 0x5d, 0x5, 0x3c, 0x1f, 
    0x2, 0x5d, 0x9, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x61, 0x5, 0xe, 0x8, 0x2, 
    0x5f, 0x61, 0x5, 0x10, 0x9, 0x2, 0x60, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x5f, 0x3, 0x2, 0x2, 0x2, 0x61, 0x69, 0x3, 0x2, 0x2, 0x2, 0x62, 0x66, 
    0x5, 0x34, 0x1b, 0x2, 0x63, 0x65, 0x5, 0x12, 0xa, 0x2, 0x64, 0x63, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x68, 0x3, 0x2, 0x2, 0x2, 0x66, 0x64, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 0x6a, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x69, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6f, 
    0x5, 0x20, 0x11, 0x2, 0x6e, 0x70, 0x5, 0x32, 0x1a, 0x2, 0x6f, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x71, 0x72, 0x3, 0x2, 0x2, 0x2, 0x72, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x73, 0x76, 0x5, 0x26, 0x14, 0x2, 0x74, 0x76, 0x5, 0x2a, 0x16, 
    0x2, 0x75, 0x73, 0x3, 0x2, 0x2, 0x2, 0x75, 0x74, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0xf, 0x3, 0x2, 0x2, 0x2, 0x77, 0x7a, 0x5, 0x28, 0x15, 0x2, 0x78, 
    0x7a, 0x5, 0x2c, 0x17, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0x78, 
    0x3, 0x2, 0x2, 0x2, 0x7a, 0x11, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7f, 0x5, 
    0x8, 0x5, 0x2, 0x7c, 0x7f, 0x5, 0x14, 0xb, 0x2, 0x7d, 0x7f, 0x5, 0x16, 
    0xc, 0x2, 0x7e, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7c, 0x3, 0x2, 0x2, 
    0x2, 0x7e, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x80, 0x81, 0x5, 0x1c, 0xf, 0x2, 0x81, 0x82, 0x5, 0x36, 0x1c, 0x2, 0x82, 
    0x15, 0x3, 0x2, 0x2, 0x2, 0x83, 0x86, 0x5, 0x18, 0xd, 0x2, 0x84, 0x86, 
    0x5, 0x1a, 0xe, 0x2, 0x85, 0x83, 0x3, 0x2, 0x2, 0x2, 0x85, 0x84, 0x3, 
    0x2, 0x2, 0x2, 0x86, 0x17, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x5, 0x2e, 
    0x18, 0x2, 0x88, 0x89, 0x5, 0x38, 0x1d, 0x2, 0x89, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x8b, 0x5, 0x24, 0x13, 0x2, 0x8b, 0x8c, 0x7, 0x12, 0x2, 0x2, 
    0x8c, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x3, 0x2, 0x2, 0x8e, 
    0x1d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x4, 0x2, 0x2, 0x90, 0x1f, 
    0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x7, 0x5, 0x2, 0x2, 0x92, 0x21, 0x3, 
    0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0x6, 0x2, 0x2, 0x94, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0x95, 0x96, 0x7, 0x7, 0x2, 0x2, 0x96, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x97, 0x98, 0x7, 0x8, 0x2, 0x2, 0x98, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x99, 0x9a, 0x7, 0x9, 0x2, 0x2, 0x9a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x9c, 0x7, 0xa, 0x2, 0x2, 0x9c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 
    0x7, 0xb, 0x2, 0x2, 0x9e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x7, 
    0xc, 0x2, 0x2, 0xa0, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0xd, 
    0x2, 0x2, 0xa2, 0x31, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x7, 0x11, 0x2, 
    0x2, 0xa4, 0x33, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x11, 0x2, 0x2, 
    0xa6, 0x35, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x11, 0x2, 0x2, 0xa8, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x5, 0x3a, 0x1e, 0x2, 0xaa, 0xab, 
    0x7, 0xe, 0x2, 0x2, 0xab, 0xad, 0x3, 0x2, 0x2, 0x2, 0xac, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xaf, 0x7, 0x12, 0x2, 0x2, 0xaf, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0xb0, 0xb1, 0x9, 0x2, 0x2, 0x2, 0xb1, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0xb2, 0xb3, 0x7, 0x11, 0x2, 0x2, 0xb3, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x41, 0x49, 0x4f, 0x54, 0x59, 0x60, 0x66, 0x6b, 0x71, 0x75, 0x79, 0x7e, 
    0x85, 0xac, 
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
