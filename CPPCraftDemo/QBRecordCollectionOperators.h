#pragma once
#include "QBLogger.h"
#include "QBDatabaseTypes.h"
#include <iterator>
#include <algorithm>

class QBRecordCollectionOperators
{
private:
	QBRecordCollectionOperators(void);

public:
	~QBRecordCollectionOperators(void);

	static QBRecordCollection QBFindMatchingRecords(const QBRecordCollection& records, const ColumnID columnID, const std::string& matchString)
	{
		QBRecordCollection result;

		for (const auto& pair : records)
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
					QBLogger::WriteToConsole("ERROR: Failed to convert match string \"" + matchString + "\" to integer : " + e.what());
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
					QBLogger::WriteToConsole("ERROR: Failed to convert match string \"" + matchString + "\" to integer : " + e.what());
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

	static QBRecordCollection PopulateDummyData(const std::string& prefix, uint32_t numRecords)
	{
		QBRecordCollection data;
		for (uint32_t i = 0; i < numRecords; i++)
		{
			auto recPtr = std::make_shared<QBRecord>();
			recPtr->column0.value = i;
			recPtr->column1.value = prefix + std::to_string(i);
			recPtr->column2.value = i % 100;
			recPtr->column3.value = std::to_string(i) + prefix;
			data.emplace(i, std::move(recPtr));
		}
		return data;//since C++11, this temporary container will be MOVED, not COPIED
	}

	static void DeleteRecordByID(QBRecordCollection& records, uint32_t id)
	{
		if (records.empty())
			return;

		records.erase(id);
	}
};

