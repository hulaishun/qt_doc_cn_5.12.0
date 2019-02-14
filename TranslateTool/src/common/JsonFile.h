#ifndef JSON_FILE_H_
#define JSON_FILE_H_

#include <QtCore/qstring.h>

#include <QtCore/qjsondocument.h>
#include <QtCore/qstring.h>

//json文件
//只进行json文件的读和写，具体的json数据格式由调用者自己处理
class CJsonFile
{
private:
    CJsonFile();
    ~CJsonFile();

public:
    //读取
    static bool ReadByteArray(const QString& strFile, QByteArray& baData);
    static bool ReadJsonDocument(const QString& strFile, QJsonDocument& jsonDoc);

    //保存
    static void WriteByteArray(const QString& strFile, const QByteArray& baData);
    static void WriteJsonObject(const QString& strFile, const QJsonObject& jsonObj);
    static void WriteJsonArray(const QString& strFile, const QJsonArray& jsonArray);
};

#endif //JSON_FILE_H_
