#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MetaBATPlugin.h"

#include <fstream>

void MetaBATPlugin::input(std::string file) {
 myInputFile = file;
 std::ifstream myfile(myInputFile.c_str(), std::ios::in);
 getline(myfile, assemblyfile);
 while (!myfile.eof()) {
   std::string bamfile;
   getline(myfile, bamfile);
   bamfiles.push_back(bamfile);
 }
}

void MetaBATPlugin::run() {}

void MetaBATPlugin::output(std::string file) {
 std::string myOutputFile = file;
 std::string myCommand = "";
myCommand += "metabat";
myCommand += " ";
myCommand += "-i";
myCommand += " ";
myCommand += assemblyfile + " ";
myCommand += "-o";
myCommand += " ";
myCommand += myOutputFile + " ";
for (int i = 0; i < bamfiles.size(); i++) {
   myCommand += bamfiles[i];
   myCommand += " ";
}
 system(myCommand.c_str());
}

PluginProxy<MetaBATPlugin> MetaBATPluginProxy = PluginProxy<MetaBATPlugin>("MetaBAT", PluginManager::getInstance());
