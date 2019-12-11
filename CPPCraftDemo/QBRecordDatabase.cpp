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

QBRecordCollection QBRecordDatabase::QBFindMatchingRecords(const ColumnID columnID, const std::string & matchString)
{
	QBRecordCollection result;

	for (const auto& pair : m_records)
	{
		auto recPtr = pair.second;
		if (columnID == recPtr->column0.id)
		{
			try
			{
				uint32_t matchValue = std::stoul(matchString);//String to unsigned 32 bit integer conversion. Throws exception upon failed conversion!
				if (matchValue == recPtr->column0.value)
				{
					result.insert(pair);//Copy the pair into result
				}
			}
			catch (std::exception& e)
			{
				std::cout << "ERROR: Failed to convert match string /""" << matchString << "/"" to integer : " << e.what() << std::endl;
				break;
			}
		}
		else if (columnID == recPtr->column1.id)
		{
			if (recPtr->column1.value.find(matchString) != std::string::npos)
			{
				result.insert(pair);
			}
		}
		else if (columnID == recPtr->column2.id)
		{
			try
			{
				long matchValue = std::stol(matchString);//String to signed 32 bit integer conversion. Throws exception upon failed conversion!
				if (matchValue == recPtr->column2.value)
				{
					result.insert(pair);
				}
			}
			catch (std::exception& e)
			{
				std::cout << "ERROR: Failed to convert match string /""" << matchString << "/"" to integer : " << e.what() << std::endl;
				break;
			}
		}
		else if (columnID == recPtr->column3.id)
		{
			if (recPtr->column3.value.find(matchString) != std::string::npos)
			{
				result.insert(pair);
			}
		}
		else
		{
			break;
		}
	}
	return result;
}

void QBRecordDatabase::DeleteRecordByID(uint32_t id)
{
	if (m_records.empty())
		return;

	m_records.erase(id);
}
