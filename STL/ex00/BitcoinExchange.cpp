#include "BitcoinExchange.hpp"

static std::string& trim(std::string& s)
{
    s.erase(0, s.find_first_not_of(" \t\n\r"));
    s.erase(s.find_last_not_of(" \t\n\r") + 1);
    return s;
}

Btc::Btc() : readFlag(1) {
    std::ifstream file("./data.csv");
    if (!file) {
        readFlag = 0;
        return;
    }
    std::string line;
    bool isFirstLine = true;
    while (std::getline(file, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }
        std::vector<std::string> tokens = splitString(line, ',');
        if (tokens.size() < 2) {
            std::cerr << "Error: Invalid line format" << std::endl;
            continue;
        }
        std::string date = trim(tokens[0]);
        float value = atof(trim(tokens[1]).c_str());
        setData(date, value);
    }
}

Btc::~Btc()
{
}

Btc &Btc::operator=(Btc const &var)
{
	this->data = var.data;
	return (*this);
}

Btc::Btc(Btc const &var)
{
	*this = var;
}

void Btc::setData(std::string date, float value)
{
	this->data.insert(std::make_pair(date, value));
}

std::map<std::string, float> Btc::getData()
{
	return (this->data);
}

std::vector<std::string> Btc::splitString(std::string str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void Btc::readInput(const std::string& inputPath) {
    std::ifstream file(inputPath.c_str());
    if (!file) {
        this->readFlag = -1;
        return;
    }
    std::string line;
    bool isFirstLine = true;
    while (std::getline(file, line)) {
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }

        std::vector<std::string> vectorLine = splitString(line, '|');
        if (vectorLine.size() < 2 || vectorLine[1].empty()) {
            std::cout << "Error: bad input => " << vectorLine[0] << std::endl;
            continue;
        }

        std::string date = trim(vectorLine[0]);
        std::istringstream iss(vectorLine[1]);
        double value;
        iss >> value;

        if (iss.fail() || !iss.eof()) {
            std::cout << "Error: Input Not A Number" << std::endl;
            continue;
        }

        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        } else if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = this->data.upper_bound(date);
        if (it != this->data.begin()) {
            --it;
            std::cout << date << " => " << vectorLine[1] << " = " << value * it->second << std::endl;
        }
    }
    file.close();
}