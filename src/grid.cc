#include "grid.hpp"

#define GRID(obj) (reinterpret_cast<GtkGrid*>(obj))

namespace gtk {

Grid::Grid() : Container(gtk_grid_new()) {}

void Grid::attach(Widget* w, int left, int top, int width, int height) { gtk_grid_attach(GRID(m_widget), w->getBase(), left, top, width, height); }

};
