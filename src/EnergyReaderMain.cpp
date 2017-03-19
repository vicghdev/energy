//============================================================================
// Name        : BaseN.cpp
// Author      : Io
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include "EmCfgReader.h"
#include "EmResultsWriter.h"
#include "EnergyMeterDevice.h"

using namespace std;

int main() {

	try
	{	// Reads cfg
		EmCfgReader cfgReader;
		// Get readings from device
		EnergyMeterDevice endev(cfgReader.GetPortName().c_str(), cfgReader.GetSlaveId(), cfgReader.GetSpeed());
		EmResultsWriter resWriter(cfgReader.GetResultsFilename());
		// Simulates reading 10 times
		for (int i=0; i<10; i++ )
		{
			unsigned int kwh = endev.ReadKwh();
			// Write result to file
			resWriter.WriteKwh(kwh);
		}
	}
	catch (Json::Exception err)
	{
		cout << "Wrong format in cfg file:" << err.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error occurred" << endl;
	}

	return 0;
}
