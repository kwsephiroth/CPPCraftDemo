#pragma once
#include <string>
#include <unordered_map>
#include <sstream>

enum class ColumnID
{
	Column0,
	Column1,
	Column2,
	Column3
};

template<typename T>
struct QBRecordColumn
{
	//std::string name;
	ColumnID id;//TODO: Currently this is publicly modifiable. Realistically, we'd want this value to be private, unique, and constant
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
		//column0.name = "column0";
		//column1.name = "column1";
		//column2.name = "column2";
		//column3.name = "column3";
		column0.id = ColumnID::Column0;
		column1.id = ColumnID::Column1;
		column2.id = ColumnID::Column2;
		column3.id = ColumnID::Column3;
	}

	std::string to_string()
	{
		std::stringstream ss;
		ss << "Column0 : " << column0.value << "\n";
		ss << "Column1 : " << column1.value << "\n";
		ss << "Column2 : " << column2.value << "\n";
		ss << "Column3 : " << column3.value << "\n";
		return ss.str();
	}
};

using QBRecordCollection = std::unordered_map<uint32_t, std::shared_ptr<struct QBRecord>>;//Map of Unique ID -> QBRecord pairs
