#pragma once
#include <iterator>
#include <algorithm>
#include "QBDatabaseTypes.h"
#include "QBLogger.h"

class QBRecordDatabase
{
private:
	QBRecordCollection m_records;

public:
	QBRecordDatabase(void) = default;
	~QBRecordDatabase(void) = default;

	void PopulateDummyData(const std::string& prefix, uint32_t numRecords);
	QBRecordCollection QBFindMatchingRecords( /*const std::string & columnName*/ const ColumnID columnID, const std::string& matchString);//Returns a collection subset containing matching records
	void DeleteRecordByID(uint32_t id);//Deletes record from main record collection using the unique record id
	size_t size() const { return m_records.size(); }
	void DeleteAllRecords() { m_records.clear(); }
};

