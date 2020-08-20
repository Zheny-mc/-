#include "zipper.h"


class Power 
{
private:
	int argc;  //количество аргументов
	string* argv;  //аргументы
	int mode;  //режим запуска
	//Zipper archive;  //архив

public:
	Power(int _argc, const char** _argv) : argc(_argc-1), argv(new string[_argc-1])  
	{
		for(int i = 0; i < argc; i++)
			argv[i] = _argv[i+1];	
	}

	~Power()
	{
		delete[] argv;
	}

	void check_args();
	void poll();
	void run();
};





int main(int argc, const char** argv)
{
	string name = "test.zip";
	vector<string> args = {"file1.dat", "file2.dat"};
	string Key = "123";

	//Zipper arch2(name, args, Key);
	//arch2.Pack();
	//arch2.UnPack();	




	return 0;
}

