#include "bus.h"

Cbus::Cbus::Cbus()
{
    enable = false;
}

quint64 Cbus::toUInt64() const
{
    quint64 serialized = 0;

    serialized |= (interrupt?1:0) ;
    serialized |= ((writeMode?1:0) << 1);
    serialized |= ((enable?1:0) << 2);
    serialized |= ((quint64)addr & 0xffffffff)<<3;
    serialized |= ((quint64)data & 0xffffff) << 35;

    return serialized;
}

void Cbus::fromUInt64(quint64 val)
{
    interrupt = val &0x01;
    writeMode = (val >> 1) &0x01;
    enable    = (val >> 2) &0x01;
    addr = (val>>3) & 0xffffffff;       // 32bits
    data = (val >>35) & 0xffffff;     // 24bits
}

QString Cbus::toLog() const
{
    QString ret;
    ret = QString("addr=%1").arg(getAddr(),6,16,QChar('0'));
    ret += QString(" - data=%1").arg(getData(),2,16,QChar('0'));
    ret += QString(" Write:%1").arg(writeMode);
    ret += QString(" INT:%1").arg(interrupt);

    return ret;
}

QDebug operator<<(QDebug dbg, const Cbus &bus)
{
    dbg.nospace() << bus.toLog();
    return dbg.maybeSpace();
}

