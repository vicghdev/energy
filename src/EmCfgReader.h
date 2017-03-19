/*
 * EmCfgReader.h
 *  Created on: 18. märts 2017
 */

#ifndef EMCFGREADER_H
#define EMCFGREADER_H

#include "JsonCfgReader.h"

class EmCfgReader
{
public:
	EmCfgReader();
	//
	std::string GetPortName();
	unsigned int GetSpeed();
	int GetSlaveId();
	std::string GetResultsFilename();

private:
	JsonCfgReader cfgReader;
};

#endif /* EMCFGREADER_H_ */
