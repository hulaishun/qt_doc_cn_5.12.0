#ifndef CN2ENKEYINFO_H
#define CN2ENKEYINFO_H

#include <QtCore/qstring.h>
#include <QtCore/qjsonobject.h>

//英文转中文的译文信息
class CEn2CnKeyInfo
{
public:
    explicit CEn2CnKeyInfo();
    CEn2CnKeyInfo(int iKeyId, const QString& strEnKey,const QString& strCnKey);
    ~CEn2CnKeyInfo();

    CEn2CnKeyInfo(const CEn2CnKeyInfo& that);
    CEn2CnKeyInfo& operator=(const CEn2CnKeyInfo& that);

    void CopyFrom(const CEn2CnKeyInfo* pthat);

    void ClearData();

    void FromJsonObject(const QJsonObject& jsonKeyInfo);
    QJsonObject ToJsonObject();

public:
    //变量的获取和设置的函数接口
    int GetKeyId() const;
    void SetKeyId(int iKeyId);

    QString GetEnKey() const;
    void SetEnKey(const QString& strEnKey);

    QString GetCnKey() const;
    void SetCnKey(const QString& strCnKey);

private:
    int                 m_iKeyId;       //译文id，唯一关键字
    QString             m_strEnKey;     //英文原文
    QString             m_strCnKey;     //中文译文
};

#endif // CN2ENKEYINFO_H
