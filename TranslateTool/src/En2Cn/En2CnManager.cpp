#include "En2CnManager.h"

#include "En2CnKeyFile.h"
#include "En2CnTableModel.h"

//static
CEn2CnManager* CEn2CnManager::sm_pInstance = nullptr;

//static
CEn2CnManager* CEn2CnManager::Instance()
{
    if(nullptr == sm_pInstance)
    {
        sm_pInstance = new CEn2CnManager();
    }

    return sm_pInstance;
}

//static
void CEn2CnManager::Release()
{
    if(nullptr != sm_pInstance)
    {
        delete sm_pInstance;
        sm_pInstance = nullptr;
    }
}

CEn2CnManager::CEn2CnManager(QObject *parent)
    : QObject(parent)
    , m_pKeyFile(nullptr)
    , m_pKeyModel(nullptr)
{

}

CEn2CnManager::~CEn2CnManager()
{

}

CEn2CnKeyFile* CEn2CnManager::GetKeyFile()
{
    if(nullptr == m_pKeyFile)
    {
        m_pKeyFile = new CEn2CnKeyFile();
    }

    return m_pKeyFile;
}

CEn2CnTableModel* CEn2CnManager::GetKeyModel()
{
    if(nullptr == m_pKeyModel)
    {
        m_pKeyModel = new CEn2CnTableModel(this);
    }

    return m_pKeyModel;
}

//统一管理英文翻译成中文的增删改查
void CEn2CnManager::AddKeyInfo(const CEn2CnKeyInfo& keyInfo)
{
    GetKeyFile()->AddKeyInfo(keyInfo);
}

void CEn2CnManager::AddKeyInfo(int iKeyId, const QString& strEnKey, const QString& strCnKey)
{
    GetKeyFile()->AddKeyInfo(iKeyId, strEnKey, strCnKey);
}

void CEn2CnManager::UpdateKeyInfo(int iKeyId, const QString& strEnKey, const QString& strCnKey)
{
    GetKeyFile()->UpdateKeyInfo(iKeyId, strEnKey, strCnKey);
}

void CEn2CnManager::UpdateKeyInfo(const QString& strEnKey, const QString& strCnKey)
{
    GetKeyFile()->UpdateKeyInfo(strEnKey, strCnKey);
}

void CEn2CnManager::DelKeyInfo(int iKeyId)
{
    GetKeyFile()->DelKeyInfo(iKeyId);
}

void CEn2CnManager::DelKeyInfo(const QString& strEnKey)
{
    GetKeyFile()->DelKeyInfo(strEnKey);
}

void CEn2CnManager::DelAllKey()
{
    GetKeyFile()->DelAllKey();
}

bool CEn2CnManager::ExistKey(const QString& strEnKey)
{
    return GetKeyFile()->ExistKey(strEnKey);
}

int CEn2CnManager::GetMaxKeyId()
{
    return GetKeyFile()->GetMaxKeyId();
}

