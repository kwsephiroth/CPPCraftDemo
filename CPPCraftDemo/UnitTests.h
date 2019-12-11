#pragma once
#include "QBLogger.h"
#include "QBRecordCollectionOperators.h"
#include "QBRecordDatabase.h"
#include "QBBaseImplementation.h"
#include <assert.h>
#include <chrono>
#include <string>

void PerformanceComparison()
{
	std::string testName = "PerformanceComparison";
	QBLogger::WriteToConsole("Running test: " + testName);

	using namespace std::chrono;
	//Using Base Implementation 
	{
		// populate a bunch of data
		auto data = QBBasePopulateDummyData("testdata", 1000);

		// Find a record that contains and measure the perf
		auto startTime = steady_clock::now();
		auto filteredSet = QBBaseFindMatchingRecords(data, "column1", "testdata500");
		auto filteredSet2 = QBBaseFindMatchingRecords(data, "column2", "24");
		auto finishTime = steady_clock::now();
		auto message = ("Base Implementation execution time:		" + std::to_string((double((finishTime - startTime).count()) * steady_clock::period::num / steady_clock::period::den)) + " seconds\n");
		QBLogger::WriteToConsole(message);

		// make sure that the function is correct
		assert(filteredSet.size() == (size_t)1);
	}

	//Using QBRecordCollectionOperators
	{
		// populate a bunch of data
		auto data = QBRecordCollectionOperators::PopulateDummyData("testdata", 1000);
		// Find a record that contains and measure the perf
		auto startTime = steady_clock::now();
		auto filteredSet = QBRecordCollectionOperators::QBFindMatchingRecords(data, ColumnID::Column1, "testdata500");
		auto filteredSet2 = QBRecordCollectionOperators::QBFindMatchingRecords(data, ColumnID::Column2, "24");
		auto finishTime = steady_clock::now();
		auto message = ("QBRecordCollectionOperators execution time:	" + std::to_string((double((finishTime - startTime).count()) * steady_clock::period::num / steady_clock::period::den)) + " seconds\n");
		QBLogger::WriteToConsole(message);

		// make sure that the function is correct
		assert(filteredSet.size() == (size_t)1);
	}

	//Using QBRRecordDatabase
	{
		// populate a bunch of data
		QBRecordDatabase rdb;
		rdb.PopulateDummyData("testdata", 1000);

		// Find a record that contains and measure the perf
		auto startTime = steady_clock::now();
		auto filteredSet = rdb.QBFindMatchingRecords(ColumnID::Column1, "testdata500");
		auto filteredSet2 = rdb.QBFindMatchingRecords(ColumnID::Column2, "24");
		auto finishTime = steady_clock::now();
		auto message = ("QBRecordDatabase execution time:		" + std::to_string((double((finishTime - startTime).count()) * steady_clock::period::num / steady_clock::period::den)) + " seconds\n");
		QBLogger::WriteToConsole(message);

		// make sure that the function is correct
		assert(filteredSet.size() == (size_t)1);
	}
}

void DeleteRecordsByID()
{
	std::string testName = "DeleteRecordsByID";
	QBLogger::WriteToConsole("Running test: " + testName);

	{
		// populate a bunch of data
		auto data = QBRecordCollectionOperators::PopulateDummyData("testdata", 1000);
		auto filteredSet = QBRecordCollectionOperators::QBFindMatchingRecords(data, ColumnID::Column1, "testdata500");
		assert(filteredSet.size() == (size_t)1);
		QBRecordCollectionOperators::DeleteRecordByID(data, 500);
		filteredSet = QBRecordCollectionOperators::QBFindMatchingRecords(data, ColumnID::Column1, "testdata500");
		assert(filteredSet.size() == (size_t)0);
	}
}

void AlphaMatchingStringForNumericColumn()
{
	std::string testName = "AlphaMatchingStringForNumericColumn";
	QBLogger::WriteToConsole("Running test: " + testName);

	auto data = QBRecordCollectionOperators::PopulateDummyData("testdata", 1000);
	auto filteredSet = QBRecordCollectionOperators::QBFindMatchingRecords(data, ColumnID::Column0, "testdata500");//String to integer conversion attempted
																												  //Exception thrown and caught upon failure
																												  //No record added.
	assert(filteredSet.size() == (size_t)0);
}

void RunAllTests()
{
	PerformanceComparison();
	DeleteRecordsByID();
	AlphaMatchingStringForNumericColumn();
}
