#ifndef SYSINFOWINDOWSIMPL_H
#define SYSINFOWINDOWSIMPL_H

#include <QVector>
#include <QtGlobal>

#include "sysinfo.h"

typedef struct _FILETIME FILETIME;

class SysInfoWindowsImpl : public SysInfo
{
public:
    SysInfoWindowsImpl();

    void init() override;
    double memoryUsed() override;
    double cpuLoadAverage() override;

private:
    QVector<qulonglong> cpuRawData();
    qulonglong convertFileTime(const FILETIME& filetime) const;

    QVector<qulonglong> cpuLoadLastValues_;
};

#endif // SYSINFOWINDOWSIMPL_H
