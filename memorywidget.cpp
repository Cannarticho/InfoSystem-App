#include "memorywidget.h"
#include "sysinfo.h"

#include <QtCharts/QAreaSeries>
#include <QPen>

using namespace QtCharts;

const int CHART_X_RANGE_COUNT = 50;
const int CHART_X_RANGE_MAX = CHART_X_RANGE_COUNT - 1;
const int COLOR_DARK_BLUE = 0x209fdf;
const int COLOR_LIGHT_BLUE = 0xbfdfef;
const int PEN_WIDTH = 3;


MemoryWidget::MemoryWidget(QWidget *parent) :
    SysInfoWidget(parent),
    series_(new QLineSeries(this)),
    pointPosition_(0)
{
    QPen pen(COLOR_DARK_BLUE);
    pen.setWidth(PEN_WIDTH);
    QLinearGradient gradient(QPointF(0, 0), QPointF(0, 1));
    gradient.setColorAt(1.0, COLOR_DARK_BLUE);
    gradient.setColorAt(0.0, COLOR_LIGHT_BLUE);
    gradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    QAreaSeries* areaSeries = new QAreaSeries(series_);
    areaSeries->setPen(pen);
    areaSeries->setBrush(gradient);

    QChart* chart = chartView().chart();
    chart->addSeries(areaSeries);
    chart->setTitle("Memory used");
    chart->createDefaultAxes();
    auto axeX = chart->axes(Qt::Orientation::Vertical).first();
    auto axeY = chart->axes(Qt::Orientation::Horizontal).first();
    axeX->setVisible();
    axeX->setRange(0, CHART_X_RANGE_MAX);
    axeY->setRange(0, 100);
}

void MemoryWidget::updateSeries()
{
    auto memory = SysInfo::instance().memoryUsed();
    series_->append(pointPosition_++, memory);
    if (series_->count() > CHART_X_RANGE_COUNT) {
        QChart* chart = chartView().chart();
        chart->scroll(chart->plotArea().width() / CHART_X_RANGE_MAX, 0);
        series_->remove(0);
    }
}
