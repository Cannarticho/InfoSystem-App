#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include <QtCharts/QPieSeries>

#include "sysinfowidget.h"

class CpuWidget : public SysInfoWidget
{
    // We have to add Q_OBJECT to make updateSeries slot able
    // to respond to Qtimer::timeout
    Q_OBJECT
public:
    explicit CpuWidget(QWidget* parent = 0);

protected slots:
    void updateSeries() override;

private:
    QtCharts::QPieSeries* series_;
};

#endif // CPUWIDGET_H
