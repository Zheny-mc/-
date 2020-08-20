#include "zipper.h"
#include "Xor.cpp"

Zipper::Zipper(const string& name, const vector<string>& FileNames)
{
	/*Архивация без шифрования*/
	this->name = name;
	this->FileNames = FileNames;
}

Zipper::Zipper(const string& name, const vector<string>& FileNames, const string& key)
{
	/*Архивация с шифрованием*/
    this->name = name;
	this->FileNames = FileNames;
    this->key = key;
}

Zipper::~Zipper()
{}

void Zipper::Pack()
{
    /*Создает архив из текстовых файлов
	<count_file> <name_file_len><name_file><Datalen><Data> <name_file_len><name_file><Datalen><Data>...*/
	vector<int> fileLens = FileLens(FileNames);
	FILE* fIn = NULL;
	FILE* fOut = fopen(name.c_str(), "wb");
	char ch;//символ для считывания
	int count = FileNames.size(); // Количество файлов
	int nameLen; //Количество символов в файле

	fwrite(&count, sizeof(int), 1, fOut); //запись количества файлов

	for (int i = 0; i < count; i++)
	{
		if (fileLens[i] == -1)
		{
			std::cout << FileNames[i] << ": " << "Error" << std::endl;
			continue;
		}
		//запись имени файла
		nameLen = FileNames[i].size();
		fwrite(&nameLen, sizeof(int), 1, fOut);
		fwrite(FileNames[i].c_str(), sizeof(char), nameLen, fOut);
		
		//запись даннных
		fwrite(&fileLens[i], sizeof(int), 1, fOut);
		fIn = fopen(FileNames[i].c_str(), "rb");
		
		while(fread(&ch, sizeof(char), 1, fIn))
			fwrite(&ch, sizeof(char), 1, fOut);

		std::cout << FileNames[i] << std::endl;
	}

	fclose(fOut);
}

void Zipper::UnPack()
{
    FILE* fIn = NULL;
	FILE* fOut = fopen(name.c_str(), "rb");
	string FileName;
	char ch;
	int count;  //Количество файлов
	int nameLen;  //Количество символов в имени файла
	int fileLen;  //Количество символов в файле

	fread(&count, sizeof(int), 1, fOut);

	for (int i = 0; i < count; i++)
	{
		fread(&nameLen, sizeof(int), 1, fOut);  //считывание длины файла
		for (int i = 0; i < nameLen; i++)  //чтение имени файла
		{
			fread(&ch, sizeof(char), 1, fOut);
			FileName.push_back(ch);
		}

		fIn = fopen(FileName.c_str(), "wb");
		fread(&fileLen, sizeof(int), 1, fOut);  //считывание длины файла
		for (int i = 0; i < fileLen; i++)  //чтение имени файла
		{
			fread(&ch, sizeof(char), 1, fOut);
			fwrite(&ch, sizeof(char), 1, fIn);
		}
		fclose(fIn);
		std::cout << FileName << std::endl; FileName = "";  //Выводим и Зачищаем строку для нового имени файла
	}

	fclose(fOut);
}

void Zipper::help()
{
    std::cout << "I will help" << std::endl;
}

int FileLen(FILE* f)
{
	/*Находит количество символов в файле*/
	int count = 0;
	char ch;

	while (fread(&ch, sizeof(char), 1, f))
		count++;

	return count;
}

vector<int> FileLens(const vector<string>& FileNames)
{
	/*находит количество символов в каждом файле*/
	vector<int> lens;
	FILE* file = NULL;

	for (int i = 0; i < FileNames.size(); i++)
	{
		file = fopen(FileNames[i].c_str(), "rb");
		
		if (file != NULL)
		{
			lens.push_back(FileLen(file));
			fclose(file);
		}
		else
			lens.push_back(ERROR);
	}
	return lens;
}


void Zipper::encrypion()  //шифрование
{
	//Xor();
}

void Zipper::decryption()  //расшифровка
{

}