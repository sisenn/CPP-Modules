#include <iostream>
#include <fstream>

void replaceAllOccurrencesInLine(std::string& line, const std::string& oldWord, const std::string& newWord) {
	
	size_t position = 0;
	if((position = line.find(oldWord, position)) == std::string::npos)
	{
		std::cerr << "Error: Old word not found." << std::endl;
			exit (EXIT_FAILURE);
	}
	while ((position = line.find(oldWord, position)) != std::string::npos)
	{
			line.erase(position, oldWord.length());
			line.insert(position, newWord);
			position += newWord.length();
	}
}

int main(int argc, char* argv[])
{
	if (argc != 4) {
        std::cout << "Insufficient/Incorrect Arguments." << std::endl;
        std::cout << "Example: " << argv[0] << " filename.txt oldword newword" << std::endl;
        return 1;
    }

	const std::string filename = argv[1];
	const std::string s1 = argv[2];
	const std::string s2 = argv[3];

	std::ifstream inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cout << "Failed to open the file: " << filename << std::endl;
		return 1;
	}

	std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
	inputFile.close();
	if (inputFile.is_open()) {
        std::cout << "Error: File is still open after closing." << std::endl;
        return 1;
    }

	replaceAllOccurrencesInLine(content, s1, s2);

	std::ofstream outputFile(filename + ".replace");
	if (!outputFile.is_open())
	{
		std::cout << "Couldn't create a new file: " << filename + ".replace" << std::endl;
		return 1;
	}

	outputFile << content;
	std::cout << "Replace is done! Check from " << filename + ".replace" << std::endl;
	outputFile.close();
    if (outputFile.is_open()) {
        std::cout << "Error: File is still open after closing." << std::endl;
        return 1;
    }
	return 0;
}
