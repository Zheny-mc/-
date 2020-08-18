#include "zipper.h"

int main()
{
	string name = "test.zip";
	vector<string> args = {"file1.dat", "file2.dat"};
	
	Zipper arch(args, name);
	//arch.Pack();
	arch.UnPack();	




	return 0;
}

