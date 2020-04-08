#ifndef SYSINFO_H
#define SYSINFO_H

// This class is a singleton, its mean we garentee there will only one instance of SysInfo
// and that this instance will accessible only from a single point
class SysInfo
{
public:
    // unique access point for the singleton
    static SysInfo& instance();
    virtual ~SysInfo();

    virtual void init() = 0;
    virtual double cpuLoadAverage() = 0;
    virtual double memoryUsed() = 0;

protected:
    // Change the visibility of the constructor to protected to garentee that only this class
    // and child classes can access it
    explicit SysInfo();

private:
    // Change visibilty of constructor by copy to private to disable it
    SysInfo(const SysInfo& rhs);
    SysInfo& operator=(const SysInfo& rhs);
};

#endif // SYSINFO_H
