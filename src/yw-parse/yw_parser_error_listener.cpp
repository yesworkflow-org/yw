#include "yw_parser_error_listener.h"
#include "misplaced_begin_child_exception.h"
#include "misplaced_port_child_exception.h"
#include "misplaced_end_exception.h"

namespace yw {
    namespace parse {

        static std::set<std::string> beginChildrenTokens{ "@in", "@IN", "@desc", "@DESC", "@out", "@OUT", "@param", "@PARAM" };
        static std::set<std::string> portChildrenTokens{ "@as", "@AS", "@file", "@FILE", "@uri", "@URI" };
        static std::set<std::string> endTokens{ "@end", "@END" };

        void YWParserErrorListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token * offendingSymbol, size_t line, size_t charPositionInLine,
            const std::string &msg, std::exception_ptr e_ptr)
        {
            auto offendingSymbolText = offendingSymbol->getText();

            if (beginChildrenTokens.find(offendingSymbolText) != beginChildrenTokens.end()) {
                throw yw::parse::MisplacedBeginChildException(offendingSymbolText, charPositionInLine + 1, line);
            }

            if (portChildrenTokens.find(offendingSymbolText) != portChildrenTokens.end()) {
                throw yw::parse::MisplacedPortChildException(offendingSymbolText, charPositionInLine + 1, line);
            }

            if (endTokens.find(offendingSymbolText) != endTokens.end()) {
                throw yw::parse::MisplacedEndException(offendingSymbolText, charPositionInLine + 1, line);
            }

            //if (offendingSymbolText == "<EOF>" ) {
            //    throw yw::parse::ParsingException();
            //}

            //if (e_ptr) {
            //    try {
            //        std::rethrow_exception(e_ptr);
            //    }
            //    catch (antlr4::InputMismatchException e) {
            //    }
            //}
        }

        void YWParserErrorListener::reportAmbiguity(antlr4::Parser *recognizer, const  antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex, bool exact,
            const antlrcpp::BitSet &ambigAlts, antlr4::atn::ATNConfigSet *configs) 
        {
            std::cerr << "report ambiguity" << std::endl;
        }

        void YWParserErrorListener::reportAttemptingFullContext(antlr4::Parser *recognizer, const  antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
            const antlrcpp::BitSet &conflictingAlts, antlr4::atn::ATNConfigSet *configs)
        {
            std::cerr << "report attempting full context" << std::endl;
        }

        void YWParserErrorListener::reportContextSensitivity(antlr4::Parser *recognizer, const  antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
            size_t prediction, antlr4::atn::ATNConfigSet *configs) 
        {
            std::cerr << "report context sensitivity" << std::endl;
        }
    }
}