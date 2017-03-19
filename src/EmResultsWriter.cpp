/*
 * EmJsonResultsWriter.cpp
 *  Created on: 18. märts 2017
 */

#include <ctime>
#include "EmResultsWriter.h"
using namespace std;

EmResultsWriter::EmResultsWriter(const std::string& filename)
: jsonFileWriter(filename)
{
}

EmResultsWriter::~EmResultsWriter()
{
}

void EmResultsWriter::WriteKwh(unsigned int kwh)
{
	WriteUintVal("Kwh", kwh);
}

// Helpers

void EmResultsWriter::WriteUintVal(const std::string& key, unsigned int val)
{
	char mbstr[100];
	 std::time_t t = std::time(NULL);
	strftime(mbstr, sizeof(mbstr), "%a %d/%m/%Y %H:%M:%S", std::localtime(&t));
	string str_now = mbstr;
	string kwh_timestamped = str_now + "-" + key;
	jsonFileWriter.WriteUintVal(kwh_timestamped, val);
}
