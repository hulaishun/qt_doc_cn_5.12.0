#ifndef JSON_FILE_H_
#define JSON_FILE_H_

#include <QtCore/qstring.h>

#include <QtCore/qjsondocument.h>
#include <QtCore/qstring.h>

//json�ļ�
//ֻ����json�ļ��Ķ���д�������json���ݸ�ʽ�ɵ������Լ�����
class CJsonFile
{
private:
    CJsonFile();
    ~CJsonFile();

public:
    //��ȡ
    static bool ReadByteArray(const QString& strFile, QByteArray& baData);
    static bool ReadJsonDocument(const QString& strFile, QJsonDocument& jsonDoc);

    //����
    static void WriteByteArray(const QString& strFile, const QByteArray& baData);
    static void WriteJsonObject(const QString& strFile, const QJsonObject& jsonObj);
    static void WriteJsonArray(const QString& strFile, const QJsonArray& jsonArray);
};

#endif //JSON_FILE_H_
