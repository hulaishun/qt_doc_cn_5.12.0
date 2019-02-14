#include "JsonFile.h"

#include <QtCore/qfile.h>
#include <QtCore/qdir.h>

CJsonFile::CJsonFile()
{
}

CJsonFile::~CJsonFile()
{
}

//¶ÁÈ¡
bool CJsonFile::ReadByteArray(const QString& strFile, QByteArray& baData)
{
    baData.clear();
    if (strFile.isEmpty() || !QFile::exists(strFile))
    {
        return false;
    }

    QFile file(strFile);
    if (!file.open(QIODevice::Text | QIODevice::ReadOnly))
    {
        file.close();
        return false;
    }

    baData = file.readAll();
    file.close();

    return true;
}

bool CJsonFile::ReadJsonDocument(const QString& strFile, QJsonDocument& jsonDoc)
{
    QByteArray baData;
    bool bret = ReadByteArray(strFile, baData);

    QJsonParseError jpe;
    jsonDoc = QJsonDocument::fromJson(baData, &jpe);
    if (QJsonParseError::NoError != jpe.error)
    {
        bret = false;
    }

    return bret;
}

//±£´æ
void CJsonFile::WriteByteArray(const QString & strFile, const QByteArray & baData)
{
    if (strFile.isEmpty() || baData.isEmpty())
    {
        return;
    }

    QString strPath = strFile;
    strPath = strPath.replace("\\", "/");
    int iindex = strPath.lastIndexOf("/");
    if (iindex >= 0 && iindex < strPath.count())
    {
        strPath = strPath.left(iindex);
    }
    QDir dir(strPath);
    dir.mkpath(strPath);

    if (QFile::exists(strFile))
    {
        QFile::remove(strFile);
    }

    QFile file(strFile);
    if (!file.open(QIODevice::Text | QIODevice::WriteOnly))
    {
        file.close();
        return;
    }

    file.write(baData);
    file.close();

    return;
}

void CJsonFile::WriteJsonObject(const QString& strFile, const QJsonObject& jsonObj)
{
    QJsonDocument doc(jsonObj);

    QByteArray baData = doc.toJson(QJsonDocument::Indented);

    WriteByteArray(strFile, baData);
}

void CJsonFile::WriteJsonArray(const QString& strFile, const QJsonArray& jsonArray)
{
    QJsonDocument doc(jsonArray);

    QByteArray baData = doc.toJson(QJsonDocument::Indented);

    WriteByteArray(strFile, baData);
}
