#include "grid.hpp"


namespace gtk {

Grid::Grid() : Container(gtk_grid_new()) {}

void Grid::attach(Widget* w, int left, int top, int width, int height) { gtk_grid_attach(GTK_GRID(m_object), GTK_WIDGET(w->getBase()), left, top, width, height); }

};
