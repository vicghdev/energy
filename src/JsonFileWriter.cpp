/*
 * JsonFileWriter.cpp
 *  Created on: 18. märts 2017
 */

#include "JsonFileWriter.h"

JsonFileWriter::JsonFileWriter(const std::string& filename)
: outFile(filename.c_str(), std::ios_base::app),	// open output file for append
  jstyledStream()
{
}

JsonFileWriter::~JsonFileWriter()
{
	outFile.flush();
	outFile.close();
}

//

void JsonFileWriter::WriteStringVal(const std::string& key, const std::string& strval)
{
    Json::Value jval;
    jval[key] = strval;
    jstyledStream.write(outFile, jval);
}

void JsonFileWriter::WriteUintVal(const std::string& key, unsigned int val)
{
    Json::Value jval;
    jval[key] = val;
    jstyledStream.write(outFile, jval);
}

