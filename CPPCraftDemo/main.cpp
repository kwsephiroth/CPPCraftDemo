//#include "stdafx.h"
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <assert.h>
//#include <chrono>
//#include <iostream>
//#include <ratio>
//#include "QBRecordCollectionHelpers.h"
//#include "QBRecordDatabase.h"
//#include "QBBaseImplementation.h"

int main(int argc, char* argv[])
{
	//using namespace std::chrono;
	//auto resolution = TimeResolution::Seconds;
	//// populate a bunch of data
	//auto data = QBBasePopulateDummyData("testdata", 1000);
	//// Find a record that contains and measure the perf
	//auto startTimer = steady_clock::now();
	//auto filteredSet = QBBaseFindMatchingRecords(data, "column1", "testdata500");
	//auto filteredSet2 = QBBaseFindMatchingRecords(data, "column2", "24");
	//auto finish = steady_clock::now();
	//std::cout << "profiler: " << double((finish - startTimer).count()) * steady_clock::period::num / steady_clock::period::den << " seconds" << std::endl;
	//std::cout << "my profiler: " << ExecutionTimer::GetExecutionTime(startTimer, finish, resolution) << " " << TimeResolutionToString(resolution) << std::endl;
	//std::cout << "filteredSet.size() = " << filteredSet.size() << std::endl;
	//std::cout << "filteredSet2.size() = " << filteredSet2.size() << std::endl;
	//// make sure that the function is correct
	//assert(filteredSet.size() == 1);

	//// populate a bunch of data
	//auto data = QBRecordCollectionHelpers::PopulateDummyData("testdata", 1000);
	//// Find a record that contains and measure the perf
	//auto startTimer = steady_clock::now();
	//auto filteredSet = QBRecordCollectionHelpers::QBFindMatchingRecords(data, "column1", "testdata500");
	//auto filteredSet2 = QBRecordCollectionHelpers::QBFindMatchingRecords(data, "column2", "24");
	//std::cout << "profiler: " << double((steady_clock::now() - startTimer).count()) * steady_clock::period::num / steady_clock::period::den << std::endl;
	//std::cout << "filteredSet.size() = " << filteredSet.size() << std::endl;
	//std::cout << "filteredSet2.size() = " << filteredSet2.size() << std::endl;
	//// make sure that the function is correct
	//assert(filteredSet.size() == 1);

	//QBRecordCollectionHelpers::DeleteRecordByID(data, 500);
	//std::cout << "filteredSet.size() = " << filteredSet.size() << std::endl;


	//// populate a bunch of data
	//QBRecordDatabase rdb;
	//rdb.PopulateDummyData("testdata", 1000);
	//// Find a record that contains and measure the perf
	//auto startTimer = steady_clock::now();
	//auto filteredSet = rdb.QBFindMatchingRecords("column1", "testdata500");
	//auto filteredSet2 = rdb.QBFindMatchingRecords("column2", "24");
	//std::cout << "profiler: " << double((steady_clock::now() - startTimer).count()) * steady_clock::period::num / steady_clock::period::den << std::endl;
	//std::cout << "filteredSet.size() = " << filteredSet.size() << std::endl;
	//std::cout << "filteredSet2.size() = " << filteredSet2.size() << std::endl;
	//// make sure that the function is correct
	//assert(filteredSet.size() == 1);

	//QBRecordCollectionHelpers::DeleteRecordByID(filteredSet, 500);
	//std::cout << "filteredSet.size() = " << filteredSet.size() << std::endl;
	
	return 0;
}

