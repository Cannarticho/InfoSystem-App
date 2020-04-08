#include "cpuwidget.h"
#include "sysinfo.h"

// Recommended since all Qt Charts classes are defined in namespace QtCharts
using namespace QtCharts;

CpuWidget::CpuWidget(QWidget *parent) :
    SysInfoWidget(parent),
    series_(new QPieSeries(this))
{
    // Create series
    series_->setHoleSize(0.35);
    series_->append("CPU Load", 30.0);
    series_->append("CPU Free", 70.0);

    // Add series to the chart
    // We get QChart from SysInfoWidget via chartView()
    QChart* chart = chartView().chart();
    chart->addSeries(series_);
    chart->setTitle("CPU Average load");
}

void CpuWidget::updateSeries()
{
    auto cpuLoad = SysInfo::instance().cpuLoadAverage();
    series_->clear();
    series_->append("Load", cpuLoad);
    series_->append("Free", 100.0 - cpuLoad);
}
