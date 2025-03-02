#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[])
{
	
	std::string file_path;
	std::string key;
	
	if(argc == 3)
	{
		file_path = argv[1];
	}
	else
	{
		std::cout << "Enter the file's path: ";
		std::getline(std::cin, file_path);
	}
	
	std::fstream file(file_path, std::ios::in | std::ios::out | std::ios::binary);
	
	if(!file)
	{
		std::cout << "Error: Unable to open " << file_path << "\n";
		return 1;
	}
		
	if(argc == 3)
	{
		key = argv[2];
	}
	else
	{		
		std::cout << "Enter the key: ";
		std::getline(std::cin, key);
	}
	
	int key_character_index = 0;
	char input_character;
	while(file.get(input_character))
	{
		char key_character = key[key_character_index % key.length()];
		char output_character = input_character ^ key_character;
		file.seekp(-1, std::ios::cur);
		file.write(&output_character, 1);
		file.flush();
		key_character_index++;
	}
	
	file.close();
	
	std::cout << "Done!\n";
	
	return 0;	
}
