#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include "plugin.h"
#include "library.h"

class PluginManager {
public:
    PluginManager() = default;
    ~PluginManager();
    
    bool loadPlugin(const char* path);
    AbstractPlugin* getPluginInstance();
    
private:
    Library mLib;
    Plugin* mPlugin = nullptr;
    AbstractPlugin* mPluginInstance = nullptr;
};

#endif // PLUGINMANAGER_H
