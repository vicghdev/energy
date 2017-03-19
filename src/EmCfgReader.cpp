/*
 * EmCfgReader.cpp
 *  Created on: 18. märts 2017
 */

#include "EmCfgReader.h"

using namespace std;

EmCfgReader::EmCfgReader()
: cfgReader("EmCfg.json")
{
}

//

string EmCfgReader::GetPortName()
{
	return cfgReader.GetStringVal("Port");
}

unsigned int EmCfgReader::GetSpeed()
{
	return cfgReader.GetUintVal("Speed");
}

int EmCfgReader::GetSlaveId()
{
	return cfgReader.GetUintVal("SlaveId");
}

string EmCfgReader::GetResultsFilename()
{
	return cfgReader.GetStringVal("ResFile");
}

