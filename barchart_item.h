#ifndef BARCHART_ITEM_H
#define BARCHART_ITEM_H

#include <qwt_plot_item.h>
#include <qwt_text.h>

#include <QList>
#include <QPair>

class BarChartItem
	: public QwtPlotItem
{

	public:
		BarChartItem(const QwtText &title = QwtText());

		void setData(const QList< QPair<int, QString> > &heights);
		const QList< QPair<int, QString> > &data(void) const;

		void draw(QPainter *painter, const QwtScaleMap &xMap, const QwtScaleMap &yMap, const QRect &canvasRect) const;

	private:
		QList< QPair<int, QString> > m_data;

};

#endif

