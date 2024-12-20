#include "Header.h"
#include "SystemBaseCode.h"
int main(int argc, char* argv[])
{
	// Generate random seed
	srand(static_cast<unsigned int>(time(nullptr)));

	cout << argc << endl;
	for (int i = 0; i < argc; i++) {
		cout << argv[i] << " ";
	}
	cout << "\n";
	string Command_Mode = argv[1];
	if (argc <= 4) {
		cout << "Input is not valid...\n";
	}
	else if (Command_Mode == "-a") 
	{
		AlgorithmsMode(argc, argv);
	}
	else if (Command_Mode == "-c") 
	{
		CompareMode(argc, argv);
	}
}
