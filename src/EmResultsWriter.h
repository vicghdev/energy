/*
 * EmJsonResultsWriter.h
 *  Created on: 18. märts 2017
 */

#ifndef EMJSONRESULTSWRITER_H
#define EMJSONRESULTSWRITER_H

#include "JsonFileWriter.h"

class EmResultsWriter
{
public:
	EmResultsWriter(const std::string& filename);
	virtual ~EmResultsWriter();
	//
	void WriteKwh(unsigned int kwh);

private:
	JsonFileWriter jsonFileWriter;

	// Helpers
	void WriteUintVal(const std::string& key, unsigned int val);
};

#endif
