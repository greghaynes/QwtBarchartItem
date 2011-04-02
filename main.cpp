#include <QApplication>
#include <QPen>

#include <qwt_plot.h>
#include <qwt_plot_grid.h>

#include "barchart_item.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QwtPlot plot;
    plot.setCanvasBackground(QColor(Qt::white));
    plot.setTitle("Bar Chart");

	QwtPlotGrid *grid = new QwtPlotGrid;
	grid->enableX(false);
	grid->enableYMin(true);
	grid->setMajPen(QPen(Qt::black, 0, Qt::DotLine));
	grid->setMinPen(QPen(Qt::gray, 0 , Qt::DotLine));
	grid->attach(&plot);

	BarChartItem *item = new BarChartItem();
	item->attach(&plot);
	QList< QPair<int, QString> > barHeights;
	barHeights.append(QPair<int, QString>(10, ""));
	barHeights.append(QPair<int, QString>(100, ""));
	barHeights.append(QPair<int, QString>(20, ""));
	item->setData(barHeights);

	plot.enableAxis(QwtPlot::xBottom, false);

	plot.resize(600, 400);
	plot.show();

	return app.exec();
}

