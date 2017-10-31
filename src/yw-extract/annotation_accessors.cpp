#include "annotation_listener.h"
#include "annotation.h"
#include "annotation_syntax_exception.h"
#include "unexpected_annotation_exception.h"
#include "invalid_argument_exception.h"
#include "missing_argument_exception.h"
#include "misplaced_begin_child_exception.h"
#include "misplaced_port_child_exception.h"
#include "misplaced_end_exception.h"

#include <iostream>
#include <istream>

namespace yw {
    namespace extract {

        size_t safelyGetStartLineNumber(antlr4::ParserRuleContext* context) noexcept {
            antlr4::Token* start;
            if (context == nullptr || (start = context->getStart()) == nullptr) {
                std::cerr << "yw::extract::safelyGetStartLineNumber() encountered null pointer" << std::endl;
                return 0;
            }
            return start->getLine();
        }

        size_t safelyGetStartColumnNumber(antlr4::ParserRuleContext* context) noexcept {
            antlr4::Token* start;
            if (context == nullptr || (start = context->getStart()) == nullptr) {
                std::cerr << "yw::extract::safelyGetStartColumnNumber() encountered null pointer" << std::endl;
                return 0;
            }
            return start->getCharPositionInLine() + 1;
        }

        std::string safelyGetBeginKeywordText(YWParser::BeginContext *begin) noexcept {
            antlr4::tree::TerminalNode* keyword;
            if (begin == nullptr || (keyword = begin->BeginKeyword()) == nullptr) {
                std::cerr << "yw::extract::safelyGetBeginKeywordText() encountered null pointer" << std::endl;
                return 0;
            }
            return keyword->getText();
        }

        std::string safelyGetBlockDescKeywordText(YWParser::BlockDescContext *desc) noexcept {
            antlr4::tree::TerminalNode* keyword;
            if (desc == nullptr || (keyword = desc->DescKeyword()) == nullptr) {
                std::cerr << "yw::extract::safelyGetBlockDescKeywordText() encountered null pointer" << std::endl;
                return 0;
            }
            return keyword->getText();
        }

        std::string safelyGetPortDescKeywordText(YWParser::PortDescContext *desc) noexcept {
            antlr4::tree::TerminalNode* keyword;
            if (desc == nullptr || (keyword = desc->DescKeyword()) == nullptr) {
                std::cerr << "yw::extract::safelyGetPortDescKeywordText() encountered null pointer" << std::endl;
                return 0;
            }
            return keyword->getText();
        }

        std::string safelyGetAsKeywordText(YWParser::AliasContext *as) noexcept {
            antlr4::tree::TerminalNode* keyword;
            if (as == nullptr || (keyword = as->AsKeyword()) == nullptr) {
                std::cerr << "yw::extract::safelyGetAsKeywordText() encountered null pointer" << std::endl;
                return 0;
            }
            return keyword->getText();
        }

        std::string safelyGetPortKeywordText(YWParser::PortContext* port) noexcept {
            YWParser::PortKeywordContext* portKeyword;
            if (port == nullptr || (portKeyword = port->portKeyword()) == nullptr) {
                std::cerr << "yw::extract::safelyGetPortKeywordText() encountered null pointer" << std::endl;
                return 0;
            }
            return portKeyword->getText();
        }

        std::string safelyGetBlockNameFromBeginContext(YWParser::BeginContext *begin) {

            YWParser::BlockNameContext* blockName;
            YWParser::PhraseContext* phrase;
            YWParser::UnquotedPhraseContext* unquotedPhrase;
            std::string blockNameText;

            if (begin == nullptr ||
                ((blockName = begin->blockName()) == nullptr) ||
                ((phrase = blockName->phrase()) == nullptr) ||
                ((unquotedPhrase = phrase->unquotedPhrase()) == nullptr ||
                ((blockNameText = unquotedPhrase->getText())) == "<missing WORD>") ||
                (blockNameText.empty())
                ) {
                throw yw::parse::MissingArgumentException(
                    safelyGetBeginKeywordText(begin),
                    "block name",
                    safelyGetStartColumnNumber(begin),
                    safelyGetStartLineNumber(begin)
                );
            }

            return blockNameText;
        }

        std::string safelyDescriptionTextFromBlockDescContext(YWParser::BlockDescContext *desc) {

            YWParser::DescriptionContext* description;
            YWParser::PhraseContext* phrase;
            YWParser::UnquotedPhraseContext* unquotedPhrase;
            std::string descriptionText;

            if (desc == nullptr ||
                (description = desc->description()) == nullptr ||
                (phrase = description->phrase()) == nullptr ||
                (unquotedPhrase = phrase->unquotedPhrase()) == nullptr ||
                (descriptionText = unquotedPhrase->getText()) == "<missing WORD>" ||
                descriptionText.empty()
                ) {
                throw yw::parse::MissingArgumentException(
                    safelyGetBlockDescKeywordText(desc),
                    "block description",
                    safelyGetStartColumnNumber(desc),
                    safelyGetStartLineNumber(desc)
                );
            }
            return descriptionText;
        }

        std::string safelyDescriptionTextFromPortDescContext(YWParser::PortDescContext *desc) {

            YWParser::DescriptionContext* description;
            YWParser::PhraseContext* phrase;
            YWParser::UnquotedPhraseContext* unquotedPhrase;
            std::string descriptionText;

            if (desc == nullptr ||
                (description = desc->description()) == nullptr ||
                (phrase = description->phrase()) == nullptr ||
                (unquotedPhrase = phrase->unquotedPhrase()) == nullptr ||
                (descriptionText = unquotedPhrase->getText()) == "<missing WORD>" ||
                descriptionText.empty()
                ) {
                throw yw::parse::MissingArgumentException(
                    safelyGetPortDescKeywordText(desc),
                    "port description",
                    safelyGetStartColumnNumber(desc),
                    safelyGetStartLineNumber(desc)
                );
            }
            return descriptionText;
        }

        std::string safelyGetAliasNameFromAliasContext(YWParser::AliasContext *alias) {

            YWParser::DataNameContext* dataName;
            YWParser::PhraseContext* phrase;
            YWParser::UnquotedPhraseContext* unquotedPhrase;
            std::string aliasText;

            if (alias == nullptr ||
                (dataName = alias->dataName()) == nullptr ||
                (phrase = dataName->phrase()) == nullptr ||
                (unquotedPhrase = phrase->unquotedPhrase()) == nullptr ||
                (aliasText = unquotedPhrase->getText()) == "<missing WORD>" ||
                aliasText.empty()
                ) {
                throw yw::parse::MissingArgumentException(
                    safelyGetAsKeywordText(alias),
                    "data name",
                    safelyGetStartColumnNumber(alias),
                    safelyGetStartLineNumber(alias)
                );
            }

            return aliasText;
        }

        std::string safelyGetPortNameFromPortNameContext(YWParser::PortNameContext *portName) {
            YWParser::WordContext* word;
            YWParser::UnquotedWordContext* unquotedWord;
            std::string portNameText;

            if (portName == nullptr ||
                (word = portName->word()) == nullptr ||
                (unquotedWord = word->unquotedWord()) == nullptr ||
                (portNameText = unquotedWord->getText()) == "<missing WORD>" ||
                portNameText.empty()
                ) {

                auto portContext = (YWParser::PortContext*)(portName->parent);

                throw yw::parse::MissingArgumentException(
                    safelyGetPortKeywordText(portContext),
                    "port name",
                    safelyGetStartColumnNumber(portContext),
                    safelyGetStartLineNumber(portContext)
                );
            }

            return portNameText;
        }
    }
}