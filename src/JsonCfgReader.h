/*
 * JsonCfgReader.h
 *  Created on: 18. märts 2017
 */

#ifndef JSONCFGREADER_H
#define JSONCFGREADER_H

#include <string>
#include <fstream>
#include <json/json.h>

class JsonCfgReader
{
public:
	JsonCfgReader(const std::string& cfg_file_name);
	virtual ~JsonCfgReader();
	//
	std::string GetStringVal(const std::string& key);
	unsigned int GetUintVal(const std::string& key);

private:
	std::ifstream ifs;
	Json::Reader jreader;
	Json::Value jroot;
};

#endif
