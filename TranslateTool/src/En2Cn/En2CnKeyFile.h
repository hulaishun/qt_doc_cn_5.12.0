#ifndef CN2ENKEYFILE_H
#define CN2ENKEYFILE_H

#include <QObject>
#include <QtCore/qlist.h>

#include <En2CnKeyInfo.h>

class CEn2CnKeyFile : public QObject
{
Q_OBJECT
public:
    explicit CEn2CnKeyFile(QObject *parent = nullptr);
    ~CEn2CnKeyFile();

    void ClearData();

signals:

public slots:

public:
    void ReadFromFile(const QString& strFileName);
    void WriteToFile(const QString& strFileName);

    void AddKeyInfo(const CEn2CnKeyInfo& keyInfo);
    void AddKeyInfo(int iKeyId, const QString& strEnKey, const QString& strCnKey);
    void UpdateKeyInfo(int iKeyId, const QString& strEnKey, const QString& strCnKey);
    void UpdateKeyInfo(const QString& strEnKey, const QString& strCnKey);
    void DelKeyInfo(int iKeyId);
    void DelKeyInfo(const QString& strEnKey);
    void DelAllKey();
    bool ExistKey(const QString& strEnKey);
    int GetMaxKeyId();

    QList<CEn2CnKeyInfo> GetKeyList() const;

private:
    QList<CEn2CnKeyInfo>            m_listKey;      //英翻中的关键字的所有列表
};

#endif // CN2ENKEYFILE_H
