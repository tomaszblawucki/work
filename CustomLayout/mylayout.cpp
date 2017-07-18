#include "mylayout.h"

MyLayout::MyLayout(QWidget *parent, int margin, int hSpacing, int vSpacing):
    QLayout(parent), m_hSpace(hSpacing), m_vSpace(vSpacing)
{
    setContentsMargins(200,200,200,200);

}

MyLayout::MyLayout(const QLayout &layout, int margin, int hSpacing, int vSpacing):
    m_hSpace(hSpacing), m_vSpace(vSpacing)
{
    setContentsMargins(margin, margin, margin, margin);
    setMargin(margin);
    setSpacing(10);
}

MyLayout::~MyLayout()
{
    QLayoutItem *item;
    while((item = takeAt(0)))
        delete item;
}

void MyLayout::addItem(QLayoutItem *item)
{
    item->minimumHeightForWidth(200);
    setSpacing(50);
    list.append(item);

}

QSize MyLayout::sizeHint() const
{
    QSize s(0,0);
    int n = list.count();
    if (n>0)
        s=QSize(300,200);
    int i = 0;

    while(i<n)
    {
        QLayoutItem *o = list.at(i);
        s=s.expandedTo(o->sizeHint());
        ++i;
    }
    return s+n*QSize(spacing(), spacing());
}

QSize MyLayout::minimumSize() const
{
    QSize s(0,0);
    QSize qs(200, 200);
    int n = list.count();
    int i = 0;
    while (i<n)
    {
        QLayoutItem *o = list.at(i);
        s = s.expandedTo(o->minimumSize());
        ++i;
    }
    return s+n*QSize(spacing(),spacing());
}

int MyLayout::count() const
{
    return list.size();
}

QLayoutItem *MyLayout::itemAt(int i) const
{
    return list.value(i);
}

QLayoutItem *MyLayout::takeAt(int i)
{
    return ((i >=0) && (i < list.size())) ? list.takeAt(i):0;
}

void MyLayout::setGeometry(const QRect &rect)
{
    QLayout::setGeometry((rect));
    if(list.size() == 0)
    {
        return;
    }
    int w = (rect.width() - (list.count() - 1)*spacing());
    int h = (rect.height() - (list.count() - 1)*spacing());
    int i = 0;

    while(i < list.size())
    {
        QLayoutItem *o = list.at(i);
        QRect geom(rect.x() + i*spacing(), rect.y()+ i*spacing(), w, h);
        o->setGeometry(geom);
        ++i;
    }

}

void MyLayout::reorder(int c)
{
    QList<QLayoutItem*> tempList;

    QLayoutItem *item;

    switch (c) {
    case 0:
    {
        for(int i =0; i<list.count()-1; i++){
            for(int j =0; j<(list.count()-i-1); j++)
            {
                QRect r1, r2;
                r1 = list[j]->geometry();
                r2 = list[j+1]->geometry();
                if(r1.width() > r2.width())
                {
                    list.swap(j, (j+1));
                }
            }
        }
        break;
    }
    case 1:
    {
        for(int i =0; i<list.count()-1; i++){
            for(int j =0; j<(list.count()-i-1); j++)
            {
                QRect r1, r2;
                r1 = list[j]->geometry();
                r2 = list[j+1]->geometry();
                if(r1.height() > r2.height())
                {
                    list.swap(j, (j+1));
                }
            }
        }
        break;
    }
    default:
        break;
    }


}
