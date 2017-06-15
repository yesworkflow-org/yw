#pragma once

#include "stdafx.h"
#include "YWBaseListener.h"

namespace yw_parse_tests
{
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

        void enterBeginTag(YWParser::BeginTagContext *context) override { _log << "entered begin tag" << std::endl; }
        void exitBeginTag(YWParser::BeginTagContext *context) override { _log << "exited begin tag" << std::endl; }
        void enterEndTag(YWParser::EndTagContext *context) override { _log << "entered end tag" << std::endl; }
        void exitEndTag(YWParser::EndTagContext *context) override { _log << "exited end tag" << std::endl; }
        void enterDescTag(YWParser::DescTagContext *context) override { _log << "entered desc tag" << std::endl; }
        void exitDescTag(YWParser::DescTagContext *context) override { _log << "exited desc tag" << std::endl; }
        void enterPort(YWParser::PortContext *context) override { _log << "entered port" << std::endl; }
        void exitPort(YWParser::PortContext *context) override { _log << "exited port" << std::endl; }
        void enterAliasTag(YWParser::AliasTagContext *context) override { _log << "entered alias tag" << std::endl; }
        void exitAliasTag(YWParser::AliasTagContext *context) override { _log << "exited alias tag" << std::endl; }
        void enterCallTag(YWParser::CallTagContext *context) override { _log << "entered call tag" << std::endl; }
        void exitCallTag(YWParser::CallTagContext *context) override { _log << "exited call tag" << std::endl; }
        void enterUriTag(YWParser::UriTagContext *context) override { _log << "entered uri tag" << std::endl; }
        void exitUriTag(YWParser::UriTagContext *context) override { _log << "exited uri tag" << std::endl; }
        void enterFileTag(YWParser::FileTagContext *context) override { _log << "entered file tag" << std::endl; }
        void exitFileTag(YWParser::FileTagContext *context) override { _log << "exited file tag" << std::endl; }
        void enterResourceTag(YWParser::ResourceTagContext *context) override { _log << "entered resource tag" << std::endl; }
        void exitResourceTag(YWParser::ResourceTagContext *context) override { _log << "exited resource tag" << std::endl; }

        void enterInputPortKeyword(YWParser::InputPortKeywordContext *context) override { _log << "entered input port keyword" << std::endl; }
        void exitInputPortKeyword(YWParser::InputPortKeywordContext *context) override { _log << "exited input port keyword" << std::endl; }
        void enterOutputPortKeyword(YWParser::OutputPortKeywordContext *context) override { _log << "entered output port keyword" << std::endl; }
        void exitOutputPortKeyword(YWParser::OutputPortKeywordContext *context) override { _log << "exited output port keyword" << std::endl; }

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
