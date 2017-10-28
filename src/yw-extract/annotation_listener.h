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

        private:
            long currentLineNumber = 0;
            long currentRankOnLine = 0;
            //yw::StderrRecorder stderrRecorder;

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
            void enterDesc(YWParser::DescContext *context) override;
            void enterPort(YWParser::PortContext *context) override;
            void exitPort(YWParser::PortContext *port) override;
            void enterPortName(YWParser::PortNameContext *context) override;
            void enterAlias(YWParser::AliasContext *context) override;
            void enterIo(YWParser::IoContext *context) override;
            void exitIo(YWParser::IoContext *context) override;
            //void enterMisplacedBeginChild(YWParser::MisplacedBeginChildContext * context) override;
            //void enterMisplacedPortChild(YWParser::MisplacedPortChildContext* context) override;
            //void enterMisplacedEnd(YWParser::MisplacedEndContext * context) override;

        private:
            bool AnnotationListener::inProgramBlock();
            auto getLineId(antlr4::ParserRuleContext* context);
            auto getRangeInLine(antlr4::ParserRuleContext* context);
        };
    }
}

