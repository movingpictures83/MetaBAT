#ifndef METABATPLUGIN_H
#define METABATPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>
#include <vector>

class MetaBATPlugin : public Plugin
{
public: 
 std::string toString() {return "MetaBAT";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string myInputFile;
 std::string assemblyfile;
 std::vector<std::string> bamfiles;
};

#endif
