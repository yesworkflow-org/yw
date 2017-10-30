#pragma once

#include "yw_parse_tests.h"

namespace yw {
    namespace parse {

        class StubYWListener : public YWBaseListener {
        private:
            std::stringstream _log;
        public:
            std::string log() { return _log.str(); }
            void enterScript(YWParser::ScriptContext *context) override { _log << "entered script" << std::endl; }
            void exitScript(YWParser::ScriptContext *context) override { _log << "exited script" << std::endl; }
            void enterBlock(YWParser::BlockContext *context) override { _log << "entered block" << std::endl; }
            void exitBlock(YWParser::BlockContext *context) override { _log << "exited block" << std::endl; }
            void enterBlockAttribute(YWParser::BlockAttributeContext *context) override { _log << "entered block attribute" << std::endl; }
            void exitBlockAttribute(YWParser::BlockAttributeContext *context) override { _log << "exited block attribute" << std::endl; }
            void enterPortAttribute(YWParser::PortAttributeContext *context) override { _log << "entered port attribute" << std::endl; }
            void exitPortAttribute(YWParser::PortAttributeContext *context) override { _log << "exited port attribute" << std::endl; }

            void enterBegin(YWParser::BeginContext *context) override { _log << "entered begin" << std::endl; }
            void exitBegin(YWParser::BeginContext *context) override { _log << "exited begin" << std::endl; }
            void enterEnd(YWParser::EndContext *context) override { _log << "entered end" << std::endl; }
            void exitEnd(YWParser::EndContext *context) override { _log << "exited end" << std::endl; }
            void enterBlockDesc(YWParser::BlockDescContext *context) override { _log << "entered block desc" << std::endl; }
            void exitBlockDesc(YWParser::BlockDescContext *context) override { _log << "exited block desc" << std::endl; }
            void enterIo(YWParser::IoContext *context) override { _log << "entered io" << std::endl; }
            void exitIo(YWParser::IoContext *context) override { _log << "exited io" << std::endl; }
            void enterPort(YWParser::PortContext *context) override { _log << "entered port" << std::endl; }
            void exitPort(YWParser::PortContext *context) override { _log << "exited port" << std::endl; }
            void enterPortDesc(YWParser::PortDescContext *context) override { _log << "entered port desc" << std::endl; }
            void exitPortDesc(YWParser::PortDescContext *context) override { _log << "exited port desc" << std::endl; }
            void enterAlias(YWParser::AliasContext *context) override { _log << "entered alias" << std::endl; }
            void exitAlias(YWParser::AliasContext *context) override { _log << "exited alias" << std::endl; }
            void enterUri(YWParser::UriContext *context) override { _log << "entered uri" << std::endl; }
            void exitUri(YWParser::UriContext *context) override { _log << "exited uri" << std::endl; }
            void enterFile(YWParser::FileContext *context) override { _log << "entered file" << std::endl; }
            void exitFile(YWParser::FileContext *context) override { _log << "exited file" << std::endl; }
            void enterResource(YWParser::ResourceContext *context) override { _log << "entered resource" << std::endl; }
            void exitResource(YWParser::ResourceContext *context) override { _log << "exited resource" << std::endl; }

            void enterInputKeyword(YWParser::InputKeywordContext *context) override { _log << "entered input port keyword" << std::endl; }
            void exitInputKeyword(YWParser::InputKeywordContext *context) override { _log << "exited input port keyword" << std::endl; }
            void enterOutputKeyword(YWParser::OutputKeywordContext *context) override { _log << "entered output port keyword" << std::endl; }
            void exitOutputKeyword(YWParser::OutputKeywordContext *context) override { _log << "exited output port keyword" << std::endl; }

            void enterBlockName(YWParser::BlockNameContext *context) override { _log << "entered block name" << std::endl; }
            void exitBlockName(YWParser::BlockNameContext *context) override { _log << "exited block name" << std::endl; }
            void enterPortName(YWParser::PortNameContext *context) override { _log << "entered port name" << std::endl; }
            void exitPortName(YWParser::PortNameContext *context) override { _log << "exited port name" << std::endl; }
            void enterDataName(YWParser::DataNameContext *context) override { _log << "entered data name" << std::endl; }
            void exitDataName(YWParser::DataNameContext *context) override { _log << "exited data name" << std::endl; }
            void enterDescription(YWParser::DescriptionContext *context) override { _log << "entered description" << std::endl; }
            void exitDescription(YWParser::DescriptionContext *context) override { _log << "exited description" << std::endl; }
        };
    }
}
