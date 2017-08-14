#include "gvc.h"
#include "xdot.h"

extern gvplugin_library_t gvplugin_dot_layout_LTX_library;
extern gvplugin_library_t gvplugin_core_LTX_library;
extern gvplugin_library_t gvplugin_pango_LTX_library;

lt_symlist_t lt_preloaded_symbols[] = { 
    { "gvplugin_dot_layout_LTX_library", &gvplugin_dot_layout_LTX_library },
    { "gvplugin_core_LTX_library", &gvplugin_core_LTX_library },
    { "gvplugin_pango_LTX_library", &gvplugin_pango_LTX_library },
    { 0, 0 } 
};

int main(int argc, char **argv)
{
    Agraph_t *g;
    Agnode_t *n, *m;
    Agedge_t *e;
    GVC_t *gvc;

    gvc = gvContextPlugins(lt_preloaded_symbols, FALSE);

    g = agopen("g", Agdirected, &AgDefaultDisc);
    n = agnode(g, "n", 1);
    m = agnode(g, "m", 1);
    e = agedge(g, n, m, 0, 1);

    agsafeset(n, "color", "red", "");
    gvLayout(gvc, g, "dot");
    gvRender(gvc, g, "png", stdout);
    gvFreeLayout(gvc, g);
    agclose(g);
    gvFreeContext(gvc);

    return 0;
}