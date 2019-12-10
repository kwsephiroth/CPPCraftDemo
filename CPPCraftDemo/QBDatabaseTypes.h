#pragma once
#include <string>
#include <unordered_map>

template<typename T>
struct QBRecordColumn
{
	std::string name;
	T value;
};

struct QBRecord
{
	QBRecordColumn<uint32_t> column0; // unique id column
	QBRecordColumn<std::string> column1;
	QBRecordColumn<long> column2;
	QBRecordColumn <std::string> column3;

	QBRecord()
	{
		//Set default column names
		column0.name = "column0";
		column1.name = "column1";
		column2.name = "column2";
		column3.name = "column3";
	}
};

using QBRecordCollection = std::unordered_map<uint32_t, std::shared_ptr<struct QBRecord>>;//Map of Unique ID -> QBRecord pairs
