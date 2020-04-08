#ifndef MEMORYWIDGET_H
#define MEMORYWIDGET_H

#include <QtCharts/QLineSeries>

#include "sysinfowidget.h"

class MemoryWidget : public SysInfoWidget
{
    Q_OBJECT
public:
    MemoryWidget(QWidget* parent = 0);

protected slots:
    void updateSeries() override;

private:
    QtCharts::QLineSeries* series_;
    qint64 pointPosition_;

};

#endif // MEMORYWIDGET_H
