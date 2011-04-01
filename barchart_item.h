#ifndef BARCHART_ITEM_H
#define BARCHART_ITEM_H

#include <qwt_plot_item.h>
#include <qwt_text.h>

#include <QList>

class BarChartItem
	: public QwtPlotItem
{

	public:
		BarChartItem(const QwtText &title = QwtText());

		void setBarHeights(const QList<int> &heights);
		const QList<int> &barHeights(void) const;

		void draw(QPainter *painter, const QwtScaleMap &xMap, const QwtScaleMap &yMap, const QRect &canvasRect) const;

	private:
		QList<int> m_barHeights;

};

#endif

