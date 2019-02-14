#ifndef EN2CN_LIST_MODEL_H
#define EN2CN_LIST_MODEL_H

#include <QObject>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qlist.h>
#include <QtCore/qvariant.h>
#include "En2CnKeyInfo.h"

class CEn2CnTableModel : public QAbstractTableModel
{
public:
    explicit CEn2CnTableModel(QObject* parent = nullptr);
    ~CEn2CnTableModel();

    enum EKeyRole
    {
        KeyIdRole           = Qt::UserRole+1,
        KeyEnNameRole,
        KeyCnNameRole
    };

	enum ETableColumn
	{
		TABLE_COLUMN_0_EN_NAME	= 0,
		TABLE_COLUMN_1_CN_NAME	= 1,

		TABLE_COLUMN_COUNT = 2
	};

    void ClearData();

public:
    //对模型数据的增删改查
    void AddKeyInfo(const CEn2CnKeyInfo& keyInfo);
    void UpdateKeyInfo(const QModelIndex& index, const QString& strEnText, const QString& strCnText);
    void DelKeyInfo(int iKeyId);
    void DelKeyInfo(const QModelIndex& index);
    QModelIndex IndexOfKeyId(int iKeyId);
    QModelIndex IndexOfEnText(const QString& strEnText);
	QList<CEn2CnKeyInfo> GetDataList();

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

protected:
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
	virtual Qt::ItemFlags flags(const QModelIndex &index) const;
	virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;

private:
    QList<CEn2CnKeyInfo>                m_listData;
};

#endif // EN2CN_LIST_MODEL_H
