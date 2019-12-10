#pragma once
#include "QBRecordCollectionOperators.h"
#include "QBRecordDatabase.h"
#include "QBBaseImplementation.h"
#include <assert.h>
#include <chrono>
#include <string>
#include <iostream>

void PerformanceComparison()
{
	std::string testName = "PerformanceComparison";
	std::cout << "Running test: " << testName << std::endl;
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
		std::cout << message.c_str() << std::endl;

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
		std::cout << message.c_str() << std::endl;

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
		auto message = ("QBRecordDatabase execution time:			" + std::to_string((double((finishTime - startTime).count()) * steady_clock::period::num / steady_clock::period::den)) + " seconds\n");
		std::cout << message.c_str() << std::endl;

		// make sure that the function is correct
		assert(filteredSet.size() == (size_t)1);
	}
}

void DeleteRecordsByID()
{
	std::string testName = "DeleteRecordsByID";
	std::cout << "Running test: " << testName << std::endl;

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

