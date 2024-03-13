#include "treeitem.h"

TreeItem::TreeItem(const QString& name,
        const QVariant& value,
        bool fuzz,
        const QVariant& selectionWave,
        const QVariant& fuzzMin,
        const QVariant& fuzzMax,
        TreeItem* parent)
{
    m_parentItem = parent;
    m_itemData = {QVariant(name), value, selectionWave, fuzz, fuzzMin, fuzzMax, 0};//selectionWave,
    m_lastFuzz.start();
}

TreeItem::~TreeItem()
{
    qDeleteAll(m_childItems);
}

void TreeItem::appendChild(TreeItem* item)
{
    m_childItems.append(item);
}

TreeItem* TreeItem::child(int row)
{
    return m_childItems.value(row);
}

QList<TreeItem*> TreeItem::children()
{
    return m_childItems;
}

int TreeItem::childCount() const
{
    return m_childItems.count();
}

int TreeItem::columnCount() const
{
    return m_itemData.count();
}

QVariant TreeItem::data(TreeItem::Type type) const
{
    switch (type)
    {
    case Type::Name:
        return m_itemData.value(0);
    case Type::Value:
        return m_itemData.value(1);
    case Type::Fuzz:
        return m_itemData.value(2);
    case Type::FuzzMin:
        return m_itemData.value(4);
    case Type::SelectionWave:
        return m_itemData.value(3);
    case Type::FuzzMax:
        return m_itemData.value(5);
    case Type::FuzzInterval_s:
        return m_itemData.value(6);
    default:
        return QVariant();
    }
}

bool TreeItem::setData(TreeItem::Type type, const QVariant& data)
{
    switch (type)
    {
    case Type::Name:
        m_itemData[0] = data;
        break;
    case Type::Value:
        m_itemData[1] = data;
        break;
    case Type::Fuzz:
        m_itemData[2] = data;
        break;
    case Type::FuzzMin:
        m_itemData[4] = data;
        break;
    case Type::FuzzMax:
        m_itemData[5] = data;
        break;
    case Type::FuzzInterval_s:
        m_itemData[6] = data;
        break;
    case Type::SelectionWave:
        m_itemData[3] = data;
        break;
    default:
        return false;
    }
    return true;
}

TreeItem* TreeItem::parentItem()
{
    return m_parentItem;
}

void TreeItem::resetFuzzTimer()
{
    m_lastFuzz.start();
}

int TreeItem::timeElapsedSinceFuzz_ms()
{
    return m_lastFuzz.elapsed();
}

int TreeItem::row() const
{
    if (m_parentItem)
    {
        return m_parentItem->m_childItems.indexOf(const_cast<TreeItem*>(this));
    }
    return 0;
}
