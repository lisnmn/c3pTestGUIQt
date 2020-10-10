#ifndef UTILDYNAMICINTERFACEADV_H
#define UTILDYNAMICINTERFACEADV_H

#include <QBoxLayout>

#include "inifile.h"

class DynamicUI : public QObject {
    Q_OBJECT
public:
    DynamicUI();
    ~DynamicUI();
    void loadInterface(const char* filepath, QBoxLayout* layout);
    void buildInterface(const char* sectionName);
    void destroyInterface();
    int saveIniFile();
    const char* saveIniFile(const char* path);
    inifile::IniFile& getIniFile();

private:
    QBoxLayout* mMainLayout;
    QList<QWidget*> layoutItems;
    inifile::IniFile mIniFile;
    std::string iniSavePath;
};

#endif // UTILDYNAMICINTERFACEADV_H
