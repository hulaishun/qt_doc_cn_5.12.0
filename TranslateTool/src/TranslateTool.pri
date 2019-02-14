INCLUDEPATH += $$PWD/En2Cn
INCLUDEPATH += $$PWD/Cn2Cn
INCLUDEPATH += $$PWD/common

SOURCES += \
        main.cpp \
        MainWindow.cpp \
    $$PWD/Cn2Cn/Cn2CnKeyForm.cpp \
    $$PWD/En2Cn/En2CnKeyFile.cpp \
    $$PWD/En2Cn/En2CnKeyForm.cpp \
    $$PWD/En2Cn/En2CnKeyInfo.cpp \
    $$PWD/En2Cn/En2CnListModel.cpp \
    $$PWD/En2Cn/En2CnManager.cpp \
    $$PWD/En2Cn/En2CnDef.cpp \
    $$PWD/common/JsonFile.cpp

HEADERS += \
        MainWindow.h \
    $$PWD/Cn2Cn/Cn2CnKeyForm.h \
    $$PWD/En2Cn/En2CnKeyFile.h \
    $$PWD/En2Cn/En2CnKeyForm.h \
    $$PWD/En2Cn/En2CnKeyInfo.h \
    $$PWD/En2Cn/En2CnListModel.h \
    $$PWD/En2Cn/En2CnManager.h \
    $$PWD/En2Cn/En2CnDef.h \
    $$PWD/common/JsonFile.h

FORMS += \
        MainWindow.ui \
    $$PWD/En2Cn/En2CnKeyForm.ui \
    $$PWD/Cn2Cn/Cn2CnKeyForm.ui

DISTFILES += \
    $$PWD/Data/Cn2CnKey.json \
    $$PWD/Data/En2CnKey.json
