#pragma once
#include <string>
#include <vector>
#include <algorithm>

/**
Represents a Record Object
*/
struct QBBaseRecord
{
	uint32_t column0; // unique id column
	std::string column1;
	long column2;
	std::string column3;
};

/**
Represents a Record Collections
*/
typedef std::vector<QBBaseRecord> QBBaseRecordCollection;

/**
Return records that contains a string in the StringValue field
records - the initial set of records to filter
matchString - the string to search for
*/
QBBaseRecordCollection QBBaseFindMatchingRecords(const QBBaseRecordCollection& records, const std::string & columnName, const std::string& matchString)
{
	QBBaseRecordCollection result;
	std::copy_if(records.begin(), records.end(), std::back_inserter(result), [&](QBBaseRecord rec) {
		if (columnName == "column0") {
			uint32_t matchValue = std::stoul(matchString);//String to unsigned 32 bit integer conversion
			return matchValue == rec.column0;
		}
		else if (columnName == "column1") {
			return rec.column1.find(matchString) != std::string::npos;
		}
		else if (columnName == "column2") {
			long matchValue = std::stol(matchString);//String to signed 32 bit integer conversion
			return matchValue == rec.column2;
		}
		else if (columnName == "column3") {
			return rec.column3.find(matchString) != std::string::npos;
		}
		else {
			return false;
		}
	});//Copies QBRecord objects into result whose column contains the string that is being searched for.
	return result;
}

/**
Utility to populate a record collection
prefix - prefix for the string value for every record
numRecords - number of records to populate in the collection
*/
QBBaseRecordCollection QBBasePopulateDummyData(const std::string& prefix, uint32_t numRecords)
{
	QBBaseRecordCollection data;
	data.reserve(numRecords);
	for (uint32_t i = 0; i < numRecords; i++)
	{
		QBBaseRecord rec = { i, prefix + std::to_string(i), i % 100, std::to_string(i) + prefix };
		data.emplace_back(rec);
	}
	return data;
}
