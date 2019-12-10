#include "QBRecordDatabase.h"

void QBRecordDatabase::PopulateDummyData(const std::string & prefix, uint32_t numRecords)
{
	for (uint32_t i = 0; i < numRecords; i++)
	{
		auto recPtr = std::make_shared<QBRecord>();
		recPtr->column0.value = i;
		recPtr->column1.value = prefix + std::to_string(i);
		recPtr->column2.value = i % 100;
		recPtr->column3.value = std::to_string(i) + prefix;
		m_records.emplace(i, std::move(recPtr));
	}
}

QBRecordCollection QBRecordDatabase::QBFindMatchingRecords(const std::string & columnName, const std::string & matchString)
{
	QBRecordCollection result;

	std::copy_if(m_records.begin(), m_records.end(), std::inserter(result, result.end()), [&](decltype(m_records)::value_type const& entry) {
		auto recPtr = entry.second;
		if (columnName == recPtr->column0.name) {
			uint32_t matchValue = std::stoul(matchString);//String to unsigned 32 bit integer conversion
			return matchValue == recPtr->column0.value;
		}
		else if (columnName == recPtr->column1.name) {
			return recPtr->column1.value.find(matchString) != std::string::npos;
		}
		else if (columnName == recPtr->column2.name) {
			long matchValue = std::stol(matchString);//String to signed 32 bit integer conversion
			return matchValue == recPtr->column2.value;
		}
		else if (columnName == recPtr->column3.name) {
			return recPtr->column3.value.find(matchString) != std::string::npos;
		}
		else {
			return false;
		}
	});//Copies <uin32_t, shared_ptr<QBRecord>> pair into result whose column contains the string that is being searched for.
	   //Ref counter for shared_ptr will increase by 1.
	return result;
}

void QBRecordDatabase::DeleteRecordByID(uint32_t id)
{
	if (m_records.empty())
		return;

	m_records.erase(id);
}
