// Elevator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	const int iTime2Floor = 10;
	int iCurrentFloor;
	int iRunTime = 0;
	std::string strFloorList;
	std::string strTempList;
	// Display rules
	std::cout << "Elevator R1.1 (Exception Handing added)\n\n";
	std::cout << "Floor list:\n";
	std::cout << "      Must not be empty\n";
	std::cout << "      Does not need to ordered\n";
	std::cout << "      MUST BE comma delineated\n\n";
	std::cout << "      Zero is lobby\n";
	std::cout << "      Underground parking is valid\n\n";
	//input start floor & list of floors
	std::cout << "Enter starting floor for elevator run: ";
	std::cin >> iCurrentFloor;
	std::cout << "Enter floor list: ";
	std::cin >> strFloorList;

	std::string::size_type sz;
	std::string strFloorsVisited = std::to_string(iCurrentFloor);

	while (strFloorList.length() > 0)
	{
		int iNextListFloor;
		// extract next floor from list - setup exception if invalid
		try {
			iNextListFloor = std::stoi(strFloorList, &sz);

			if (iCurrentFloor != iNextListFloor)
			{
				// append to output list string
				strFloorsVisited.append("," + std::to_string(iNextListFloor));

				// update run time
				iRunTime += abs(iCurrentFloor - iNextListFloor) * iTime2Floor;
			}
		}
		catch (const std::invalid_argument& ia) {
			std::cerr << "Invalid argument: " << ia.what() << '\n';
			break;
		}
		int iLen = (int) strFloorList.length();
		if (strFloorList.length() < ++sz)
			break;

		iCurrentFloor = iNextListFloor;
		strTempList = strFloorList.substr(sz);
		strFloorList = strTempList;		
	}
	std::cout << "\nRun Time: ";
	std::cout << iRunTime;
	std::cout << "\nFloor Visited: ";
	std::cout << strFloorsVisited;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
