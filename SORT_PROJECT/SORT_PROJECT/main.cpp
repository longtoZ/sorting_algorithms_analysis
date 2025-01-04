#include "header.h"
#include "baseFunctions.h"

int main(int argc, char* argv[])
{
	// Generate random seed
	srand(static_cast<unsigned int>(time(nullptr)));

	// Create Functions object to use modes
	Functions function;

	string commandMode = argv[1];
	cout << endl;

	if (argc <= 4) {
		cout << "Input is not valid...\n";
	}
	else if (commandMode == "-a") 
	{
		function.algorithmMode(argc, argv);
	}
	else if (commandMode == "-c") 
	{
		function.comparisonMode(argc, argv);
	}
}
