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

QBRecordCollection QBRecordDatabase::QBFindMatchingRecords( /*const std::string & columnName*/ const ColumnID columnID, const std::string & matchString)
{
	QBRecordCollection result;

	std::copy_if(m_records.begin(), m_records.end(), std::inserter(result, result.end()), [&](decltype(m_records)::value_type const& entry) {
		auto recPtr = entry.second;
		if (columnID == recPtr->column0.id) {
			try
			{
				uint32_t matchValue = std::stoul(matchString);//String to unsigned 32 bit integer conversion. Throws exception upon failed conversion!
				return matchValue == recPtr->column0.value;
			}
			catch (...)
			{
				return false;
			}
		}
		else if (columnID == recPtr->column1.id) {
			return recPtr->column1.value.find(matchString) != std::string::npos;
		}
		else if (columnID == recPtr->column2.id) {
			try
			{
				long matchValue = std::stol(matchString);//String to signed 32 bit integer conversion. Throws exception upon failed conversion!
				return matchValue == recPtr->column2.value;
			}
			catch (...)
			{
				return false;
			}
		}
		else if (columnID == recPtr->column3.id) {
			return recPtr->column3.value.find(matchString) != std::string::npos;
		}
		else {
			return false;
		}
	});//Copies <uin32_t, shared_ptr<QBRecord>> pair into result whose column contains the string value that is being searched for.
	   //Ref counter for shared_ptr will increase by 1.
	return result;
}

void QBRecordDatabase::DeleteRecordByID(uint32_t id)
{
	if (m_records.empty())
		return;

	m_records.erase(id);
}
