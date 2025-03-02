# XOR File Encryptor

A simple C++ program that performs XOR encryption and decryption on a file using a user-provided key.

## Features

- Encrypts or decrypts a file using a given key.
- Can be used via command line arguments or interactive command line input.

## How It Works

This program applies the XOR cipher to each byte in the file using a repeating key. If you run the program on an encrypted file with the same key, it will decrypt it back to its original state.

## Usage

### Compilation

To compile the program, use the following command:

```sh
 g++ -o bin/linux.exe src/main.cpp
```

If you're on Linux but want to compile an executable for Windows, use MinGW:

```sh
 x86_64-w64-mingw32-g++ -o bin/windows.exe src/main.cpp
```

If you're on Linux, you can also use the provided `compile.bash` script which compiles executables for Linux and Windows:

```sh
 ./compile.bash
```

### Running the Program

You can run the program in two ways:

#### 1. Using Command Line Arguments

```sh
 ./bin/linux.exe <file_path> <key>
```
or
```sh
 ./bin/windows.exe <file_path> <key>
```

Example:

```sh
 ./bin/linux.exe example.txt secretkey
```
or
```sh
 ./bin/windows.exe example.txt secretkey
```

#### 2. Interactive Mode

If you run the program without arguments, it will prompt you for the file path and encryption key:

```sh
 ./bin/linux.exe
```
or
```sh
 ./bin/windows.exe
```

You'll then be asked to enter:

- The file's path
- The encryption key

## Example

Suppose `example.txt` contains:

```
Hello, World!
```

If you run:

```sh
 ./bin/linux.exe example.txt mykey
```

The file content will be encrypted. Running the same command again with the same key will decrypt it.

## Notes

- Be sure to use the same key for encryption and decryption.
- The program modifies the file in place, so make a backup before using it.

## License

This project is open-source and available under the MIT License.

