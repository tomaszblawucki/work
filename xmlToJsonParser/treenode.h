#ifndef TREECONTAINER_H
#define TREECONTAINER_H

#include <QVector>


template<class T>
class TreeNode
{
private:
    TreeNode *parent;
    QVector<TreeNode *> children;

public:
    TreeContainer();
};

#endif // TREECONTAINER_H
