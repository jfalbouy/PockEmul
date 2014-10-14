#ifndef RENDERVIEW_H
#define RENDERVIEW_H

#include <QQuickWidget>

class CPObject;
class CViewObject;

class CrenderView : public QQuickWidget
{
    Q_OBJECT

public:
    CrenderView(QWidget *parent = 0);

    QObject *object;
    QWidget * parent;

public slots:
    Q_INVOKABLE void warning(QString msg);
    Q_INVOKABLE void keypressed(QString Id, int k, int m, int scan);
    Q_INVOKABLE void keyreleased(QString Id, int k, int m, int scan);
    Q_INVOKABLE void contextMenu(QString Id, int x, int y);
    Q_INVOKABLE void click(QString Id, int x, int y);
    Q_INVOKABLE void unclick(QString Id, int x, int y);
    Q_INVOKABLE void setzoom(int x,int y,int z);
    Q_INVOKABLE void movepocket(QString Id, int x, int y);
    Q_INVOKABLE void moveallpocket(int x, int y);
    void pocketUpdated(CPObject* pObject);
    void newPObject(CPObject *pObject);
    void delPObject(CPObject *pObject);
    void movePObject(CViewObject*pObject, QPoint pos);
    void sizePObject(CViewObject*pObject, QSize size);
    void stackPosChanged();
};

#endif // RENDERVIEW_H