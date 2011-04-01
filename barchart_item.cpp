#include "barchart_item.h"

#include <qwt_scale_map.h>
#include <qwt_plot.h>

#include <QPainter>
#include <QPen>
#include <QBrush>

BarChartItem::BarChartItem(const QwtText &title)
	: QwtPlotItem(title)
{
}

void BarChartItem::setBarHeights(const QList<int> &heights)
{
	m_barHeights = heights;

	// Set X axis
	plot()->setAxisScale(QwtPlot::xBottom, 0, (heights.size()*2)-1);

	// Set Y axis
	int max;
	QList<int>::const_iterator itr;
	for(max = 0,itr = heights.begin();itr != heights.end();++itr)
	{
		if(*itr > max)
			max = *itr;
	}
	plot()->setAxisScale(QwtPlot::yLeft, 0, max);
}

const QList<int> &BarChartItem::barHeights(void) const
{
	return m_barHeights;
}

void BarChartItem::draw(QPainter *painter, const QwtScaleMap &xmap, const QwtScaleMap &ymap, const QRect &canvasRect) const
{
	int i;
	for(i = 0;i < m_barHeights.size();++i)
	{
		// Paint the bar
		painter->fillRect(xmap.transform(i*2),
		                  ymap.transform(0),
		                  xmap.transform((i*2)+1) - xmap.transform(i*2),
		                  ymap.transform(m_barHeights[i]) - ymap.transform(0),
		                  QBrush(Qt::red));
	}
}

