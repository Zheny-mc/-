#include "zipper.h"




int main()
{
	string name = "test.zip";
	vector<string> args = {"file1.dat", "file2.dat"};
	string Key = "123";

	Zipper arch1(name, args);
	Zipper arch2(name, args, Key);
	//arch.Pack();
	//arch.UnPack();	
	/*
	string key;

	key = Code(name);
	std::cout << name << '\n';

	DeCode(name, key);
	std::cout << name << '\n';
	*/
	

	return 0;
}

