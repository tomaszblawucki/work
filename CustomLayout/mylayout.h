#ifndef MYLAYOUT_H
#define MYLAYOUT_H

#include <QLayout>
#include <QList>

class MyLayout : public QLayout
{
private:
    QList<QLayoutItem*> list;
    int m_hSpace;
    int m_vSpace;

public:   

    explicit MyLayout(QWidget *parent, int margin = -1, int hSpacing = 40, int vSpacing = 40);
    explicit MyLayout(const QLayout &latout, int margin = -1, int hSpacing = 40, int vSpacing = 40);
   // MyLayout(QWidget *parent/* int dist*/):QLayout(parent){}
   // MyLayout(QLayout &parent/* int dist*/):QLayout(parent){}
    MyLayout():QLayout(){}
    ~MyLayout();
    void addItem(QLayoutItem *item) override;//ok
    QSize sizeHint() const;
    QSize minimumSize() const;
    int count() const;
    QLayoutItem *itemAt(int) const;
    QLayoutItem *takeAt(int);
    void setGeometry(const QRect &rect);
    void reorder(int);//0=width, 1=height

};

#endif // MYLAYOUT_H
