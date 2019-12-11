#pragma once
#include <string>
#include <iostream>


class QBLogger
{
public:
	static void WriteToConsole(const std::string& message)
	{
		std::cout << message << std::endl;
	}
};