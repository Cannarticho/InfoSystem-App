#ifndef SYSINFOWIDGET_H
#define SYSINFOWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QtCharts/QChartView>

namespace Ui {
class SysInfoWidget;
}


// Define base widget
class SysInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SysInfoWidget(QWidget *parent = nullptr,
                           int startDelays = 500,
                           int updateSeriesDelayMs = 500);
    ~SysInfoWidget();

protected:
    QtCharts::QChartView& chartView() { return chartView_; };

protected slots:
    virtual void updateSeries() = 0;

private:
    QTimer refreshTimer_;
    QtCharts::QChartView chartView_;
};

#endif // SYSINFOWIDGET_H
