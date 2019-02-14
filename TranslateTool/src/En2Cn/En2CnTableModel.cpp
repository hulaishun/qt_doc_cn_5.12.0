#include "En2CnTableModel.h"

CEn2CnTableModel::CEn2CnTableModel(QObject* parent /*= nullptr*/)
    :QAbstractTableModel(parent)
{

}

CEn2CnTableModel::~CEn2CnTableModel()
{
    ClearData();
}

void CEn2CnTableModel::ClearData()
{
    m_listData.clear();
}

//对模型数据的增删改查
void CEn2CnTableModel::AddKeyInfo(const CEn2CnKeyInfo& keyInfo)
{
    int iOldCount = rowCount();
    beginInsertRows(QModelIndex(), iOldCount, iOldCount);
    m_listData << keyInfo;
    endInsertRows();
}

void CEn2CnTableModel::UpdateKeyInfo(const QModelIndex& index, const QString& strEnText, const QString& strCnText)
{
    if(!index.isValid() || index.row() >= m_listData.count() || strEnText.isEmpty() || strCnText.isEmpty())
    {
        return;
    }

    m_listData[index.row()].SetEnKey(strEnText);
    m_listData[index.row()].SetCnKey(strCnText);
}

void CEn2CnTableModel::DelKeyInfo(int iKeyId)
{
    QModelIndex index = IndexOfKeyId(iKeyId);
    if(!index.isValid() || index.row() >= m_listData.count())
    {
        return;
    }

    beginRemoveRows(QModelIndex(), index.row(), index.row());
    m_listData.removeAt(index.row());
    endRemoveRows();
}

void CEn2CnTableModel::DelKeyInfo(const QModelIndex& index)
{
    if(!index.isValid() || index.row() >= m_listData.count())
    {
        return;
    }

    beginRemoveRows(QModelIndex(), index.row(), index.row());
    m_listData.removeAt(index.row());
    endRemoveRows();
}

QModelIndex CEn2CnTableModel::IndexOfKeyId(int iKeyId)
{
    for(int i=0;i<m_listData.count();++i)
    {
        if(m_listData[i].GetKeyId() == iKeyId)
        {
            return index(i, 0);
        }
    }

    //返回无效索引
    return index(-1, -1);
}

QModelIndex CEn2CnTableModel::IndexOfEnText(const QString& strEnText)
{
    for(int i=0;i<m_listData.count();++i)
    {
        if(m_listData[i].GetEnKey() == strEnText)
        {
            return index(i, 0);
        }
    }

    //返回无效索引
    return index(-1, -1);
}

QList<CEn2CnKeyInfo> CEn2CnTableModel::GetDataList()
{
	return m_listData;
}

//virtual
int CEn2CnTableModel::rowCount(const QModelIndex &parent /*= QModelIndex()*/) const
{
	Q_UNUSED(parent);
    return m_listData.count();
}

//virtual
QVariant CEn2CnTableModel::data(const QModelIndex &index, int role /*= Qt::DisplayRole*/) const
{
    if(!index.isValid() || index.row() >= m_listData.count())
    {
        return QVariant();
    }

    CEn2CnKeyInfo keyinfo = m_listData.at(index.row());
    if(KeyIdRole == role)
    {
        return keyinfo.GetKeyId();
    }
    else if(KeyEnNameRole == role)
    {
        return keyinfo.GetEnKey();
    }
    else if(KeyCnNameRole == role)
    {
        return keyinfo.GetCnKey();
    }

	if (Qt::DisplayRole == role)
	{
		if (TABLE_COLUMN_0_EN_NAME == index.column())
		{
			return keyinfo.GetEnKey();
		}
		else if (TABLE_COLUMN_1_CN_NAME == index.column())
		{
			return keyinfo.GetCnKey();
		}

		return QVariant();
	}

    return QVariant();
}

//virtual
Qt::ItemFlags CEn2CnTableModel::flags(const QModelIndex &index) const
{
	Q_UNUSED(index);

	return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemNeverHasChildren;
}

//virtual
QVariant CEn2CnTableModel::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
{
	if (Qt::DisplayRole == role && Qt::Horizontal == orientation)
	{
		if (TABLE_COLUMN_0_EN_NAME == section)
		{
			return QStringLiteral("英文原文");
		}
		else if (TABLE_COLUMN_1_CN_NAME == section)
		{
			return QStringLiteral("中文译文");
		}
	}

	return QVariant();
}

//virtual
int CEn2CnTableModel::columnCount(const QModelIndex &parent /*= QModelIndex()*/) const
{
	Q_UNUSED(parent);

	return TABLE_COLUMN_COUNT;
}
