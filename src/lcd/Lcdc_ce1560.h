#ifndef LCDC_CE1560_H
#define LCDC_CE1560_H


#include "Lcdc.h"
#include "hd61102.h"

class Clcdc_ce1560:public Clcdc{
public:
    virtual bool	init(void);
    void disp(void);				//display LCDC data to screen
    void disp_symb(void);
    const char*	GetClassName(){ return("Clcdc_e500");}

    int computeSL(CHD61102* pCtrl,int ord);
    int symbSL(int x);
    int x2a[100];
    int pixels[192][64];


    Clcdc_ce1560(CPObject *parent, QRect _lcdRect, QRect _symbRect, QString _lcdfname=QString(), QString _symbfname=QString());
    virtual ~Clcdc_ce1560()
    {						//[constructor]
    }

};



#endif // LCDC_CE1560_H
