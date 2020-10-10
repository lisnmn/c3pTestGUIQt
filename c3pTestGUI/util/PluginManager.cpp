#include "PluginManager.h"

#include <iostream>

PluginManager::~PluginManager() {
    if(mPluginInstance != nullptr) {
        delete mPluginInstance;
        mPluginInstance = nullptr;
    }
    if(mPlugin != nullptr) {
        // This struct has been deleted by Library
        //delete mPlugin;
        mPlugin = nullptr;
    }
}

bool PluginManager::loadPlugin(const char* path) {
    if(!mLib.open(path)) {
        return false;
    }
    
    if(!mLib.symbol("exports", (void**)(&mPlugin))) {
        return false;
    }
    
    std::cout << "name: " << mPlugin->mPluginName << " version: " << mPlugin->mPluginVersion << std::endl;
    
    if(mPluginInstance != nullptr) {
        delete mPluginInstance;
        mPluginInstance = nullptr;
    }
    
    mPluginInstance = mPlugin->mCreateFunc();
    if(mPluginInstance == nullptr) {
        std::cout << "Plugin Instance is null." << std::endl;
        return false;
    } else {
        std::cout << "Plugin Instancing succeed." << std::endl;
        return true;
    }
}

AbstractPlugin* PluginManager::getPluginInstance() {
    return mPluginInstance;
}

