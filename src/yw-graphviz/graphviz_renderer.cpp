#include "graphviz_renderer.h"

#include "gvc.h"

extern "C" gvplugin_library_t gvplugin_dot_layout_LTX_library;
extern "C" gvplugin_library_t gvplugin_core_LTX_library;
extern "C" gvplugin_library_t gvplugin_pango_LTX_library;

lt_symlist_t lt_preloaded_symbols[] = {
    { "gvplugin_dot_layout_LTX_library", &gvplugin_dot_layout_LTX_library },
    { "gvplugin_core_LTX_library", &gvplugin_core_LTX_library },
    { "gvplugin_pango_LTX_library", &gvplugin_pango_LTX_library },
    { 0, 0 }
};

namespace yw {
    namespace graphviz {

        GraphvizRenderer::GraphvizRenderer(
            std::string dotText,
            std::string layoutEngine,
            std::string imageFormat
        ) : dotText(dotText), layoutEngine(layoutEngine), imageFormat(imageFormat) 
        {
            context = gvContextPlugins(lt_preloaded_symbols, FALSE);
            graph = agmemread(dotText.c_str());
            gvLayout(context, graph, layoutEngine.c_str());
        }

        GraphvizRenderer::~GraphvizRenderer() {
            gvFreeLayout(context, graph);
            agclose(graph);
            gvFreeContext(context);
        }

        void GraphvizRenderer::write(FILE* file) {
            gvRender(context, graph, imageFormat.c_str(), file);
        }

        std::string GraphvizRenderer::str() {
            char* result;
            unsigned int length;
            gvRenderData(context, graph, imageFormat.c_str(), &result, &length);
            std::string imageString{ result };
            gvFreeRenderData(result);
            return imageString;
        }
    }
}