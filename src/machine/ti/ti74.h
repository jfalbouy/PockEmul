#ifndef TI74_H
#define TI74_H


class CPObject;
class Ctms70c46;
class CHD44780;

#include "pcxxxx.h"

class Cti74 : public CpcXXXX
{
    Q_OBJECT

public:
    Cti74(CPObject *parent = 0);
    virtual ~Cti74();

    virtual bool	Chk_Adr(UINT32 *d,UINT32 data);
    virtual bool	Chk_Adr_R(UINT32 *d, UINT32 *data);
    virtual UINT8 in(UINT8 address,QString sender=QString());
    virtual UINT8 out(UINT8 address,UINT8 value,QString sender=QString());

    virtual bool	Set_Connector(Cbus *_bus = 0);
    virtual bool	Get_Connector(Cbus *_bus = 0);

    bool init();

    virtual bool run();

    virtual void Reset();

    void TurnON();
    void TurnOFF();
    bool SaveConfig(QXmlStreamWriter *xmlOut);
    bool LoadConfig(QXmlStreamReader *xmlIn);

    virtual void ComputeKey(KEYEVENT ke = KEY_PRESSED,int scancode=0,QMouseEvent *event=0);

    Ctms70c46 *ptms70c46cpu;
    CHD44780 *pHD44780;

    quint8 ks;
    virtual quint8 getKey();
    UINT8 m_clock_control;
    UINT8 m_banks;
    UINT8 m_power;
    UINT8 m_bus_control;

    virtual void initExtension(void);



    void clock_w(UINT8 data);
    UINT8 clock_r();

    bool slotChanged;
    int currentSlot;

protected slots:
        void addModule(QString item, CPObject *pPC);
};

class Cti95 : public Cti74
{
    Q_OBJECT

public:
    Cti95(CPObject *parent = 0);
    virtual ~Cti95();

    virtual bool run();
    virtual quint8 getKey();
};

#endif // TI74_H
