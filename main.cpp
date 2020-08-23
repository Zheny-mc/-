#include "zipper.h"

using std::cout;
using std::endl;

class Power 
{
public:
	int argc;  //количество аргументов
	string* argv;  //аргументы
	string mode;  //режим запуска
	string name;  //имя архива
	vector<string> FileNames;

	Power(int _argc, const char** _argv) : argc(_argc-1), argv(new string[_argc-1])  
	{
		for(int i = 0; i < argc; i++)
			argv[i] = _argv[i+1];	
	}

	~Power()
	{
		delete[] argv;
	}

	bool check_args();
	void poll();
	void run();
};


bool Power::check_args()
{
	// -c - создание архива
	// -x - распаковка архива
	string KeyWords[] = {"-c", "-cz", "-x", "-xz", ".zip", ".zip.z"};  

	if (argc >= 2)
	{
		if ((argv[0] == KeyWords[0] || argv[0] == KeyWords[1] ||
			 argv[0] == KeyWords[2] || argv[0] == KeyWords[3]) && 
			 (argv[1].find(KeyWords[4]) != -1 || argv[1].find(KeyWords[5]) != -1))
		{
			if ((argv[0] == KeyWords[0] || argv[0] == KeyWords[1]) && argc == 2)
			{
				cout << "Nothing packing... Input files" << endl;
				return false;
			}
		}
		else
		{
			cout << "Dont know 1 and 2 arguments" << endl;
			return false; 
		}
	}
	else
	{
		cout << "It is little count argumets" << endl;
		return false;	
	}

	return true;
}

void Power::poll()
{	
	mode = argv[0];
	name = argv[1];
	if (mode == "-c" || mode == "-cz")
	{
		for (int i = 2; i < argc; i++)
			FileNames.push_back(argv[i]);
	}	
}

void Power::run()
{
	Zipper archive(name, FileNames);

	if (name.find(".z") != -1) archive.set_HaveKey();
	
	if (mode == "-c")
	{
		//создание архива
		archive.help();
	}
	else if (mode == "-x")
	{
		//распаковка архива
		archive.UnPack();	
	}
		
}

int main()
{
	/*
	string name = "test.zip";
	vector<string> args = {"file1.dat", "file2.dat"};
	string Key = "123";

	Zipper arch2(name, args);
	arch2.Pack();
	arch2.UnPack();	
	*/

	int argc = 5; 
	const char* argv[] = {"./zipper", "-c", "name.zip.z", "file1.dat", "file2.dat"};

	Power R(argc, argv);

	if (R.check_args())  //проверка правильности аргументов
	{
		R.poll();  //заполнение аргументов
		R.run();  //запуск
	}

	return 0;
}

