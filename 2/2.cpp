#include <iostream>
#include <fstream>
#include <string>

int main()
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

        for(size_t i = 7; i < line.size(); i++)
        {

        }
    }

    std::cout << sum;
    
}