
// Generated from ywcli.g4 by ANTLR 4.7


#include "ywcliLexer.h"


using namespace antlr4;

using namespace yw;

ywcliLexer::ywcliLexer(CharStream *input) : Lexer(input) {
  _interpreter = new atn::LexerATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ywcliLexer::~ywcliLexer() {
  delete _interpreter;
}

std::string ywcliLexer::getGrammarFileName() const {
  return "ywcli.g4";
}

const std::vector<std::string>& ywcliLexer::getRuleNames() const {
  return _ruleNames;
}

const std::vector<std::string>& ywcliLexer::getChannelNames() const {
  return _channelNames;
}

const std::vector<std::string>& ywcliLexer::getModeNames() const {
  return _modeNames;
}

const std::vector<std::string>& ywcliLexer::getTokenNames() const {
  return _tokenNames;
}

dfa::Vocabulary& ywcliLexer::getVocabulary() const {
  return _vocabulary;
}

const std::vector<uint16_t> ywcliLexer::getSerializedATN() const {
  return _serializedATN;
}

const atn::ATN& ywcliLexer::getATN() const {
  return _atn;
}




// Static vars and initialization.
std::vector<dfa::DFA> ywcliLexer::_decisionToDFA;
atn::PredictionContextCache ywcliLexer::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ywcliLexer::_atn;
std::vector<uint16_t> ywcliLexer::_serializedATN;

std::vector<std::string> ywcliLexer::_ruleNames = {
  u8"T__0", u8"T__1", u8"T__2", u8"T__3", u8"T__4", u8"T__5", u8"T__6", 
  u8"T__7", u8"NEWLINE", u8"SPACE", u8"DQ", u8"SQ", u8"WORD"
};

std::vector<std::string> ywcliLexer::_channelNames = {
  "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
};

std::vector<std::string> ywcliLexer::_modeNames = {
  u8"DEFAULT_MODE"
};

std::vector<std::string> ywcliLexer::_literalNames = {
  "", u8"'-h'", u8"'--help'", u8"'-v'", u8"'--version'", u8"'-c'", u8"'-config'", 
  u8"'--config'", u8"'='", "", "", u8"'\"'", u8"'''"
};

std::vector<std::string> ywcliLexer::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", u8"NEWLINE", u8"SPACE", u8"DQ", u8"SQ", 
  u8"WORD"
};

dfa::Vocabulary ywcliLexer::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ywcliLexer::_tokenNames;

ywcliLexer::Initializer::Initializer() {
  // This code could be in a static initializer lambda, but VS doesn't allow access to private class members from there.
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
    0x2, 0xf, 0x5a, 0x8, 0x1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 
    0x4, 0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
    0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 
    0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 
    0xe, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x5, 0xa, 0x4c, 0xa, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xe, 0x6, 0xe, 0x57, 0xa, 0xe, 0xd, 0xe, 0xe, 0xe, 0x58, 
    0x2, 0x2, 0xf, 0x3, 0x3, 0x5, 0x4, 0x7, 0x5, 0x9, 0x6, 0xb, 0x7, 0xd, 
    0x8, 0xf, 0x9, 0x11, 0xa, 0x13, 0xb, 0x15, 0xc, 0x17, 0xd, 0x19, 0xe, 
    0x1b, 0xf, 0x3, 0x2, 0x4, 0x3, 0x2, 0x22, 0x22, 0x8, 0x2, 0xb, 0xc, 
    0xf, 0xf, 0x22, 0x22, 0x24, 0x24, 0x29, 0x29, 0x3f, 0x3f, 0x2, 0x5b, 
    0x2, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x5, 0x3, 0x2, 0x2, 0x2, 0x2, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x9, 0x3, 0x2, 0x2, 0x2, 0x2, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0xd, 0x3, 0x2, 0x2, 0x2, 0x2, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0x2, 0x11, 0x3, 0x2, 0x2, 0x2, 0x2, 0x13, 0x3, 0x2, 0x2, 0x2, 0x2, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x2, 0x17, 0x3, 0x2, 0x2, 0x2, 0x2, 0x19, 0x3, 0x2, 
    0x2, 0x2, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x3, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x5, 0x20, 0x3, 0x2, 0x2, 0x2, 0x7, 0x27, 0x3, 0x2, 0x2, 0x2, 0x9, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0xb, 0x34, 0x3, 0x2, 0x2, 0x2, 0xd, 0x37, 0x3, 0x2, 
    0x2, 0x2, 0xf, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x11, 0x48, 0x3, 0x2, 0x2, 
    0x2, 0x13, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x15, 0x4f, 0x3, 0x2, 0x2, 0x2, 
    0x17, 0x51, 0x3, 0x2, 0x2, 0x2, 0x19, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1b, 
    0x56, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x7, 0x2f, 0x2, 0x2, 0x1e, 0x1f, 
    0x7, 0x6a, 0x2, 0x2, 0x1f, 0x4, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x7, 
    0x2f, 0x2, 0x2, 0x21, 0x22, 0x7, 0x2f, 0x2, 0x2, 0x22, 0x23, 0x7, 0x6a, 
    0x2, 0x2, 0x23, 0x24, 0x7, 0x67, 0x2, 0x2, 0x24, 0x25, 0x7, 0x6e, 0x2, 
    0x2, 0x25, 0x26, 0x7, 0x72, 0x2, 0x2, 0x26, 0x6, 0x3, 0x2, 0x2, 0x2, 
    0x27, 0x28, 0x7, 0x2f, 0x2, 0x2, 0x28, 0x29, 0x7, 0x78, 0x2, 0x2, 0x29, 
    0x8, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x7, 0x2f, 0x2, 0x2, 0x2b, 0x2c, 
    0x7, 0x2f, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x78, 0x2, 0x2, 0x2d, 0x2e, 0x7, 
    0x67, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x74, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x75, 
    0x2, 0x2, 0x30, 0x31, 0x7, 0x6b, 0x2, 0x2, 0x31, 0x32, 0x7, 0x71, 0x2, 
    0x2, 0x32, 0x33, 0x7, 0x70, 0x2, 0x2, 0x33, 0xa, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x35, 0x7, 0x2f, 0x2, 0x2, 0x35, 0x36, 0x7, 0x65, 0x2, 0x2, 0x36, 
    0xc, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 0x2f, 0x2, 0x2, 0x38, 0x39, 
    0x7, 0x65, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x71, 0x2, 0x2, 0x3a, 0x3b, 0x7, 
    0x70, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x68, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x6b, 
    0x2, 0x2, 0x3d, 0x3e, 0x7, 0x69, 0x2, 0x2, 0x3e, 0xe, 0x3, 0x2, 0x2, 
    0x2, 0x3f, 0x40, 0x7, 0x2f, 0x2, 0x2, 0x40, 0x41, 0x7, 0x2f, 0x2, 0x2, 
    0x41, 0x42, 0x7, 0x65, 0x2, 0x2, 0x42, 0x43, 0x7, 0x71, 0x2, 0x2, 0x43, 
    0x44, 0x7, 0x70, 0x2, 0x2, 0x44, 0x45, 0x7, 0x68, 0x2, 0x2, 0x45, 0x46, 
    0x7, 0x6b, 0x2, 0x2, 0x46, 0x47, 0x7, 0x69, 0x2, 0x2, 0x47, 0x10, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 0x3f, 0x2, 0x2, 0x49, 0x12, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x4c, 0x7, 0xf, 0x2, 0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x4e, 0x7, 0xc, 0x2, 0x2, 0x4e, 0x14, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x50, 0x9, 0x2, 0x2, 0x2, 0x50, 0x16, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 
    0x7, 0x24, 0x2, 0x2, 0x52, 0x18, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 
    0x29, 0x2, 0x2, 0x54, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x55, 0x57, 0xa, 0x3, 
    0x2, 0x2, 0x56, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x5, 0x2, 0x4b, 0x58, 0x2, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ywcliLexer::Initializer ywcliLexer::_init;