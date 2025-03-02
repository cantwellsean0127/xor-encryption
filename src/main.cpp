#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
	
int main(int argc, char* argv[])
{
	
	// This variable stores the file path of the file to encrypt/decrypt. It can be set by using the -f argument or if this argument is not used, the program will ask for it.		
	std::string file_path = "";
	
	// This variable stores the encryption/decryption key. It can be set by using the -k argument or if this argument is not used, the program will ask for it.
	std::string key = "";
	
	// Here, we go through the different arguments passed into the program.
	int opt;
    while ((opt = getopt(argc, argv, "f:k:")) != -1) {
        switch (opt) {
            case 'f':
            	file_path = optarg;
            	break;
            case 'k':
            	key = optarg;
            	break;
            case '?':
            case ':':
            default:
	           return 1;
        }
    }
	
	// If the file path was not set by the arguments, we must ask the user for it.
	if(file_path == "")
	{
		std::cout << "Enter the file's path: ";
		std::getline(std::cin, file_path);
	}
	
	// Here, we open the file in read/write/binary mode
	std::fstream file(file_path, std::ios::in | std::ios::out | std::ios::binary);
	
	// If we failed opening the file, we exit and alert the user
	if(!file)
	{
		std::cerr << "Error: Unable to open " << file_path << "\n";
		return 1;
	}
	
	// If the encryption/decryption key was not set by the arguments, we must ask the user for it.
	if(key == "")
	{		
		std::cout << "Enter the key: ";
		std::getline(std::cin, key);
	}
	
	// Here we go through each character in the file and overwrite it with the XOR equivalent	
	int key_character_index = 0;
	char input_character;
	while(file.get(input_character))
	{
		if(key_character_index == key.length())
		{
			key_character_index = 0;
		}
		char key_character = key[key_character_index];
		char output_character = input_character ^ key_character;
		file.seekp(-1, std::ios::cur);
		file.write(&output_character, 1);
		file.flush();
		key_character_index++;
	}
	
	// Now that we're done, we can close the file and alert the user that we've finished
	file.close();
	std::cout << "Done!\n";
	
	// Exit the program with status code 0 (successful exit)
	return 0;	
}
