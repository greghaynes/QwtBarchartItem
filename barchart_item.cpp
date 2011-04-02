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

void BarChartItem::setData(const QList< QPair<int, QString> > &data)
{
	m_data = data;

	// Set X axis
	plot()->setAxisScale(QwtPlot::xBottom, 0, (m_data.size()*2)-1);

	// Set Y axis
	int max;
	QList< QPair<int, QString> >::const_iterator itr;
	for(max = 0,itr = m_data.begin();itr != m_data.end();++itr)
	{
		if((*itr).first > max)
			max = (*itr).first;
	}
	plot()->setAxisScale(QwtPlot::yLeft, 0, max);
}

const QList< QPair<int, QString> > &BarChartItem::data(void) const
{
	return m_data;
}

void BarChartItem::draw(QPainter *painter, const QwtScaleMap &xmap, const QwtScaleMap &ymap, const QRect &canvasRect) const
{
	int i;
	for(i = 0;i < m_data.size();++i)
	{
		// Paint the bar
		painter->fillRect(xmap.transform(i*2),
		                  ymap.transform(0),
		                  xmap.transform((i*2)+1) - xmap.transform(i*2),
		                  ymap.transform(m_data[i].first) - ymap.transform(0),
		                  QBrush(Qt::red));
	}
}

