#include "En2CnKeyInfo.h"

#include "En2CnDef.h"

CEn2CnKeyInfo::CEn2CnKeyInfo()
    :m_iKeyId(0)
    ,m_strEnKey("")
    ,m_strCnKey("")
{

}

CEn2CnKeyInfo::CEn2CnKeyInfo(int iKeyId, const QString& strEnKey,const QString& strCnKey)
    :m_iKeyId(iKeyId)
    ,m_strEnKey(strEnKey)
    ,m_strCnKey(strCnKey)
{

}

CEn2CnKeyInfo::~CEn2CnKeyInfo()
{
    ClearData();
}

CEn2CnKeyInfo::CEn2CnKeyInfo(const CEn2CnKeyInfo& that)
{
    if(this == &that)
    {
        return;
    }

    CopyFrom(&that);
}

CEn2CnKeyInfo& CEn2CnKeyInfo::operator=(const CEn2CnKeyInfo& that)
{
    if(this != &that)
    {
        CopyFrom(&that);
    }

    return *this;
}

void CEn2CnKeyInfo::CopyFrom(const CEn2CnKeyInfo* pthat)
{
    if(nullptr == pthat)
    {
        return;
    }

    m_iKeyId = pthat->m_iKeyId;
    m_strEnKey = pthat->m_strEnKey;
    m_strCnKey = pthat->m_strCnKey;
}

void CEn2CnKeyInfo::ClearData()
{
    m_iKeyId = 0;
    m_strEnKey = "";
    m_strCnKey = "";
}

void CEn2CnKeyInfo::FromJsonObject(const QJsonObject& jsonKeyInfo)
{
    ClearData();

    if(jsonKeyInfo.isEmpty())
    {
        return;
    }

    m_iKeyId = jsonKeyInfo.value(KEY_EN2CN_KEY_ID).toInt();
    m_strEnKey = jsonKeyInfo.value(KEY_EN2CN_EN_NAME).toString();
    m_strCnKey = jsonKeyInfo.value(KEY_EN2CN_CN_NAME).toString();
}

QJsonObject CEn2CnKeyInfo::ToJsonObject()
{
    QJsonObject jsonobj;

    jsonobj.insert(KEY_EN2CN_KEY_ID, m_iKeyId);
    jsonobj.insert(KEY_EN2CN_EN_NAME, m_strEnKey);
    jsonobj.insert(KEY_EN2CN_CN_NAME, m_strCnKey);

    return jsonobj;
}

//变量的获取和设置的函数接口
int CEn2CnKeyInfo::GetKeyId() const
{
    return m_iKeyId;
}

void CEn2CnKeyInfo::SetKeyId(int iKeyId)
{
    m_iKeyId = iKeyId;
}

QString CEn2CnKeyInfo::GetEnKey() const
{
    return m_strEnKey;
}

void CEn2CnKeyInfo::SetEnKey(const QString& strEnKey)
{
    m_strEnKey = strEnKey;
}

QString CEn2CnKeyInfo::GetCnKey() const
{
    return m_strCnKey;
}

void CEn2CnKeyInfo::SetCnKey(const QString& strCnKey)
{
    m_strCnKey = strCnKey;
}
