/*
 * JsonCfgReader.cpp
 *  Created on: 18. märts 2017
 */

#include "JsonCfgReader.h"

using namespace std;

JsonCfgReader::JsonCfgReader(const std::string& cfg_file_name)
: ifs(cfg_file_name.c_str()),
  jreader(),
  jroot()
{
	jreader.parse(ifs, jroot);
}

JsonCfgReader::~JsonCfgReader()
{
	ifs.close();
}

//
string JsonCfgReader::GetStringVal(const std::string& key)
{
	return jroot[key].asString();
}

unsigned int JsonCfgReader::GetUintVal(const std::string& key)
{
	return jroot[key].asUInt();
}
