#include <iostream>
#include <fstream>
#include <string>


void partOne()
{
    std::string line;
    int sum = 0;
    int rTotal = 12;
    int gTotal = 13;
    int bTotal = 14;
    size_t counter = 0;
    bool possible;

    std::fstream File("Input data.txt");

    while(std::getline(File, line))
    {
        int r = 0;
        int g = 0;
        int b = 0;
        counter++;
        possible = true;
        line += ";";

        for(size_t i = 7; i < line.size(); i++)
        {
            if(line[i] == ';')
            {
                if(r > rTotal || b > bTotal || g > gTotal)
                {
                    possible = false;
                    break;
                }
                r = 0;
                g = 0;
                b = 0;
                continue;
            }

            char firstDigit = line[i - 3];
            char secondDigit = line[i - 2];
            
            if(line[i] == 'r')
            {
                r = std::stoi(std::string() + firstDigit + secondDigit);
                i++;
            }

            if(line[i] == 'g')
            {               
                g = std::stoi(std::string() + firstDigit + secondDigit);
                i++;
            }

            if(line[i] == 'b')
            {
                b = std::stoi(std::string() + firstDigit + secondDigit);
                i++;
            }
        }
        if(possible)
            sum += counter;        
    }

    std::cout << sum;
}

int main()
{
    partOne();
    
}