#pragma once

#include "ywdb.h"
#include "stdio_recorders.h"
#include "YWBaseListener.h"
#include <iostream>

namespace yw {
    namespace extract {

        class AnnotationListener : public YWBaseListener {

            struct AnnotationRange { long start; long end; };

        protected:
            yw::db::YesWorkflowDB& ywdb;
            const row_id extractionId;
            const row_id sourceId;
            std::shared_ptr<yw::db::Annotation> currentPrimaryAnnotation = nullptr;
            std::stack<std::shared_ptr<yw::db::Annotation>> primaryAnnotationStack;
            yw::db::Annotation::Tag portTag;
            row_id portLineId;
            std::string portKeyword;
            yw::nullable_string portName;
            yw::db::Flow::Direction portDirection;
            std::shared_ptr<yw::db::Annotation> lastPortAnnotation;
            AnnotationRange portRangeInLine;
            StderrRecorder stderrRecorder;
            long currentLineNumber = 0;
            long currentRankOnLine = 0;

        public:
            AnnotationListener(
                yw::db::YesWorkflowDB& ywdb,
                const row_id& extractionId,
                const row_id& sourceId
            ) : ywdb(ywdb), extractionId(extractionId), sourceId(sourceId)
            {
                //std::cout << "constructor" << std::endl;
            }

            virtual ~AnnotationListener() {
                //std::cout << "destructor" << std::endl;
            }

            void enterBegin(YWParser::BeginContext *context) override;
            void enterEnd(YWParser::EndContext *context) override;
            void enterBlockDesc(YWParser::BlockDescContext *context) override;
            void enterPortDesc(YWParser::PortDescContext *context) override;
            void enterPort(YWParser::PortContext *context) override;
            void exitPort(YWParser::PortContext *port) override;
            void enterPortName(YWParser::PortNameContext *context) override;
            void enterAlias(YWParser::AliasContext *context) override;
            void enterIo(YWParser::IoContext *context) override;
            void exitIo(YWParser::IoContext *context) override;

        protected:
            bool AnnotationListener::inProgramBlock();
            row_id getLineId(antlr4::ParserRuleContext* context);
            AnnotationRange getRangeInLine(antlr4::ParserRuleContext* context);
        };

        size_t safelyGetStartLineNumber(antlr4::ParserRuleContext* context) noexcept;
        size_t safelyGetStartColumnNumber(antlr4::ParserRuleContext* context) noexcept;
        
        std::string safelyGetAsKeywordText(YWParser::AliasContext *as) noexcept;
        std::string safelyGetBeginKeywordText(YWParser::BeginContext *begin) noexcept;
        std::string safelyGetBlockDescKeywordText(YWParser::BlockDescContext *desc) noexcept;
        std::string safelyGetEndKeywordText(YWParser::EndContext *end) noexcept;
        std::string safelyGetPortDescKeywordText(YWParser::PortDescContext *desc) noexcept;
        std::string safelyGetPortKeywordText(YWParser::PortContext* port) noexcept;


        std::string safelyGetBlockNameFromBeginContext(YWParser::BeginContext *begin);
        nullable_string safelyGetOptionalBlockNameFromEndContext(YWParser::EndContext *end);
        std::string safelyDescriptionTextFromBlockDescContext(YWParser::BlockDescContext *desc);
        std::string safelyDescriptionTextFromPortDescContext(YWParser::PortDescContext *desc);
        std::string safelyGetPortNameFromPortNameContext(YWParser::PortNameContext *portName);
        std::string safelyGetAliasNameFromAliasContext(YWParser::AliasContext *alias);
        yw::db::Annotation::Tag safelyGetPortTagFromPortContext(YWParser::PortContext *port);
        yw::db::Flow::Direction safelyGetPortDirection(YWParser::PortContext *port);

    }
}

