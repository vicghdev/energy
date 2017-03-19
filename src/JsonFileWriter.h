/*
 * JsonFileWriter.h
 *  Created on: 18. märts 2017
 */

#ifndef JSONFILEWRITER_H
#define JSONFILEWRITER_H

#include <fstream>
#include <json/json.h>

class JsonFileWriter
{
public:
	JsonFileWriter(const std::string& filename);
	virtual ~JsonFileWriter();
	//
	void WriteStringVal(const std::string& key, const std::string& val);
	void WriteUintVal(const std::string& key, unsigned int val);

private:
    std::ofstream outFile;
    Json::StyledStreamWriter jstyledStream;
};

#endif
