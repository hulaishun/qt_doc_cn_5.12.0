#ifndef CN2ENKEYINFO_H
#define CN2ENKEYINFO_H

#include <QtCore/qstring.h>
#include <QtCore/qjsonobject.h>

//Ӣ��ת���ĵ�������Ϣ
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
    //�����Ļ�ȡ�����õĺ����ӿ�
    int GetKeyId() const;
    void SetKeyId(int iKeyId);

    QString GetEnKey() const;
    void SetEnKey(const QString& strEnKey);

    QString GetCnKey() const;
    void SetCnKey(const QString& strCnKey);

private:
    int                 m_iKeyId;       //����id��Ψһ�ؼ���
    QString             m_strEnKey;     //Ӣ��ԭ��
    QString             m_strCnKey;     //��������
};

#endif // CN2ENKEYINFO_H
