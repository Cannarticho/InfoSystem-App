#include "sysinfowidget.h"
#include "ui_sysinfowidget.h"

#include <QVBoxLayout>

SysInfoWidget::SysInfoWidget(QWidget *parent, int startDelays, int updateSeriesDelayMs) :
    QWidget(parent),
    chartView_(this)
{
    refreshTimer_.setInterval(updateSeriesDelayMs);
    connect(&refreshTimer_, &QTimer::timeout, this, &SysInfoWidget::updateSeries);
    refreshTimer_.start(startDelays);

    chartView_.setRenderHint(QPainter::Antialiasing);
    chartView_.chart()->legend()->setVisible(false);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(&chartView_);
    this->setLayout(layout);
}

SysInfoWidget::~SysInfoWidget()
{

}
