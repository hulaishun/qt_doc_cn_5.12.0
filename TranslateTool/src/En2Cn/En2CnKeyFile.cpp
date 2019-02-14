#include "En2CnKeyFile.h"

#include "JsonFile.h"
#include <QtCore/qjsondocument.h>
#include <QtCore/qjsonarray.h>
#include <QtCore/qjsonvalue.h>

CEn2CnKeyFile::CEn2CnKeyFile(QObject *parent) : QObject(parent)
{

}

CEn2CnKeyFile::~CEn2CnKeyFile()
{
    ClearData();
}

void CEn2CnKeyFile::ClearData()
{
    m_listKey.clear();
}

void CEn2CnKeyFile::ReadFromFile(const QString& strFileName)
{
    if(strFileName.isEmpty())
    {
        return;
    }

    QJsonDocument jsondoc;
    if(!CJsonFile::ReadJsonDocument(strFileName, jsondoc))
    {
        return;
    }

    if(jsondoc.isNull() || jsondoc.isEmpty() || !jsondoc.isArray())
    {
        return;
    }

    QJsonArray jsonKeyList = jsondoc.array();
    for(int i=0;i<jsonKeyList.count();++i)
    {
        CEn2CnKeyInfo keyInfo;
        keyInfo.FromJsonObject(jsonKeyList[i].toObject());
        m_listKey << keyInfo;
    }
}

void CEn2CnKeyFile::WriteToFile(const QString& strFileName)
{
    if(strFileName.isEmpty())
    {
        return;
    }

    QJsonArray jsonKeyList;
    for(auto& keyinfo: m_listKey)
    {
        jsonKeyList << keyinfo.ToJsonObject();
    }

    CJsonFile::WriteJsonArray(strFileName, jsonKeyList);
}

void CEn2CnKeyFile::AddKeyInfo(const CEn2CnKeyInfo& keyInfo)
{
    m_listKey << keyInfo;

    //test
    QString strFile = "G://hulaishun//qt_doc_cn_5.12.0//TranslateTool//src//Data//En2CnKey.json";

    WriteToFile(strFile);
}

void CEn2CnKeyFile::AddKeyInfo(int iKeyId, const QString& strEnKey, const QString& strCnKey)
{
    CEn2CnKeyInfo keyinfo(iKeyId, strEnKey, strCnKey);

    AddKeyInfo(keyinfo);
}

void CEn2CnKeyFile::UpdateKeyInfo(int iKeyId, const QString& strEnKey, const QString& strCnKey)
{
    for(int i=0;i<m_listKey.count();++i)
    {
        if(m_listKey[i].GetKeyId() == iKeyId)
        {
            m_listKey[i].SetEnKey(strEnKey);
            m_listKey[i].SetCnKey(strCnKey);
        }
    }

    //test
    QString strFile = "G://hulaishun//qt_doc_cn_5.12.0//TranslateTool//src//Data//En2CnKey.json";

    WriteToFile(strFile);
}

void CEn2CnKeyFile::UpdateKeyInfo(const QString& strEnKey, const QString& strCnKey)
{
    for(int i=0;i<m_listKey.count();++i)
    {
        if(m_listKey[i].GetEnKey() == strEnKey)
        {
            m_listKey[i].SetCnKey(strCnKey);
        }
    }

    //test
    QString strFile = "G://hulaishun//qt_doc_cn_5.12.0//TranslateTool//src//Data//En2CnKey.json";

    WriteToFile(strFile);
}

void CEn2CnKeyFile::DelKeyInfo(int iKeyId)
{
    for(int i=0;i<m_listKey.count();++i)
    {
        if(iKeyId == m_listKey[i].GetKeyId())
        {
            m_listKey.removeAt(i);
            break;
        }
    }

    //test
    QString strFile = "G://hulaishun//qt_doc_cn_5.12.0//TranslateTool//src//Data//En2CnKey.json";

    WriteToFile(strFile);
}

void CEn2CnKeyFile::DelKeyInfo(const QString& strEnKey)
{
    for(int i=0;i<m_listKey.count();++i)
    {
        if(strEnKey == m_listKey[i].GetEnKey())
        {
            m_listKey.removeAt(i);
            break;
        }
    }

    //test
    QString strFile = "G://hulaishun//qt_doc_cn_5.12.0//TranslateTool//src//Data//En2CnKey.json";

    WriteToFile(strFile);
}

void CEn2CnKeyFile::DelAllKey()
{
    m_listKey.clear();

    //test
    QString strFile = "G://hulaishun//qt_doc_cn_5.12.0//TranslateTool//src//Data//En2CnKey.json";

    WriteToFile(strFile);
}

bool CEn2CnKeyFile::ExistKey(const QString& strEnKey)
{
    if(strEnKey.isEmpty())
    {
        return false;
    }

    for(int i=0; i<m_listKey.count(); ++i)
    {
        if(m_listKey[i].GetEnKey() == strEnKey)
        {
            return true;
        }
    }

    return false;
}

QList<CEn2CnKeyInfo> CEn2CnKeyFile::GetKeyList() const
{
    return m_listKey;
}

int CEn2CnKeyFile::GetMaxKeyId()
{
    int imaxid = 0;
    for(int i=0;i<m_listKey.count();++i)
    {
        if(m_listKey[i].GetKeyId() > imaxid)
        {
            imaxid = m_listKey[i].GetKeyId();
        }
    }

    return imaxid;
}
