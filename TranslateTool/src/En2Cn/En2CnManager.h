#ifndef EN2CNMANAGER_H
#define EN2CNMANAGER_H

#include <QObject>

#include "En2CnKeyInfo.h"

class CEn2CnKeyFile;
class CEn2CnTableModel;

#if defined(gEn2CnMgr)
    #undef gEn2CnMgr
#endif
#define gEn2CnMgr (CEn2CnManager::Instance())

//英文翻译成中文的管理器
class CEn2CnManager : public QObject
{
Q_OBJECT
private:
    explicit CEn2CnManager(QObject *parent = nullptr);
    ~CEn2CnManager();

public:
    static CEn2CnManager* Instance();
    static void Release();

public:
    CEn2CnKeyFile* GetKeyFile();
	CEn2CnTableModel* GetKeyModel();

    //统一管理英文翻译成中文的增删改查
    void AddKeyInfo(const CEn2CnKeyInfo& keyInfo);
    void AddKeyInfo(int iKeyId, const QString& strEnKey, const QString& strCnKey);
    void UpdateKeyInfo(int iKeyId, const QString& strEnKey, const QString& strCnKey);
    void UpdateKeyInfo(const QString& strEnKey, const QString& strCnKey);
    void DelKeyInfo(int iKeyId);
    void DelKeyInfo(const QString& strEnKey);
    void DelAllKey();
    bool ExistKey(const QString& strEnKey);
    int GetMaxKeyId();

signals:

public slots:

private:
    static CEn2CnManager* sm_pInstance;

private:
    CEn2CnKeyFile*              m_pKeyFile;         //英文翻译成中文的文件
	CEn2CnTableModel*            m_pKeyModel;
};

#endif // EN2CNMANAGER_H
