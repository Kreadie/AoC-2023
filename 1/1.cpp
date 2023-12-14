#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

void firstPart()
{
    std::string line;
    int sum = 0;

    std::ifstream File("Input data.txt");

    while(std::getline(File, line))
    {
        std::vector<int> digits;
        for(size_t i = 0; i < line.length(); i++)
        {
            if(isdigit(line[i]))
                digits.push_back(line[i] - '0');
        }

        if(digits.size() == 1)
            digits.push_back(digits[0]);

        sum += std::stoi(std::to_string(digits[0] ) + std::to_string(digits[digits.size() - 1]));
    }
    std::cout << "First part: " << sum << "\n";
}

void secondPart()
{
    std::vector<std::string> letDigits = {"one", "two", "three",
                                          "four", "five", "six", 
                                          "seven", "eight", "nine"};

    std::string line;
    int sum = 0;
    
    std::fstream File("Input data.txt");

    while(std::getline(File, line))
    {
        size_t found = 0;
        size_t searchIndex = 0;
        std::map<int, int> positions;

        for(size_t i = 0; i < letDigits.size(); i++)
        {
            if(line.find(letDigits[i], searchIndex) != line.npos)
            {
                found = line.find(letDigits[i], searchIndex);
                positions[found] = i + 1;
                searchIndex = found + 1;
                i--;
            }
            else 
                searchIndex = 0;
        }

        for(size_t i = 0; i < line.size(); i++)
        {
            if(isdigit(line[i]))
                positions[i] = line[i] - '0';
        }

        sum += std::stoi(std::to_string(positions.begin()->second) + std::to_string(positions.rbegin()->second));
    }  
    std::cout << "Second part: " << sum;
}

int main()
{
    firstPart();
    secondPart();
}