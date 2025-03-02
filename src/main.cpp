#include <iostream>
#include <string>
#include <fstream>

int main()
{
	std::cout << "Enter the file's path: ";
	std::string file_path;
	std::cin >> file_path;
	
	if(!file)
	{
		std::cout << "Error: Unable to open " << file_path << "\n";
		return 1;
	}
	
	std::cout << "Enter the key: ";
	std::string key;
	std::cin >> key;
	
	std::fstream file(file_path, std::ios::in | std::ios::out | std::ios::binary);
	
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
