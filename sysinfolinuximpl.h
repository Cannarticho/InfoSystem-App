#ifndef SYSINFOLINUXIMPL_H
#define SYSINFOLINUXIMPL_H

#include "sysinfo.h"

#include <QtGlobal>
#include <QVector>

class SysInfoLinuxImpl : public SysInfo
{
public:
    SysInfoLinuxImpl();

    void init() override;
    double memoryUsed() override;
    double cpuLoadAverage() override;

private:
    QVector<qulonglong> cpuRawData();
    QVector<qulonglong> cpuLoadLastValues_;
};

#endif // SYSINFOLINUXIMPL_H
