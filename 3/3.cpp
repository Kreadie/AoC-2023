#include <iostream>
#include <string>
#include <vector>
#include <fstream>

const size_t n = 140;

bool findSymbol(std::vector<char> symbols, char symbol)
{
    for(size_t i = 0; i < symbols.size(); i++)
    {
        if(symbol == symbols[i])
           return true;
    }
    return false;
}

void checkNearby(size_t I, size_t J, char input[n][n], int& sum, std::string num)
{
    std::vector<char> symbols = {'*', '$', '-', '%', '/', '=', '&', '+', '#', '@'};
    size_t i = I - 1;
    size_t j = J - 1;
    size_t endI = I + 1;
    size_t endJ;

    if(num.size() == 1)
        endJ = J + 1;
    else if(num.size() == 2)
        endJ = J + 2;
    else 
    {
        j = J - 2;
        endJ = J + 2;
    }

    if(i > n)
        i = 0;
    if(j > n)
        j = 0;

    J = j;

    for(i; i <= endI; i++)
    {
        for(j; j <= endJ; j++)
        {
            bool foundSymbol = findSymbol(symbols, input[i][j]);

            if(foundSymbol)
            {
                int a = std::stoi(num);
                sum += a;
                return;
            }
        }
        j = J;
    }
}

std::string makeNumber(char digit, char first, char second)
{
    std::string result = std::string() + digit;
    if(isdigit(first))
    {
        result += first;
        if(isdigit(second))
            result += second;
    }
    return result;
}

void firstPart()
{
    std::string line;
    int sum = 0;
    int k = 0;
    char input[n][n];
    
    bool isPart = false;

    std::fstream File("Input data.txt");

    while(std::getline(File, line))
    {
        for(size_t i = 0; i < line.size(); i++)
        {
            input[k][i] = line[i];
        }
        k++;
    }

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(isdigit(input[i][j]))
            {
                std::string number = makeNumber(input[i][j], input[i][j + 1], input[i][j + 2]);
                (number.size() == 1 || number.size() == 2) ? 
                checkNearby(i, j, input, sum, number) : 
                checkNearby(i, j + 1, input, sum, number);
                
                if(number.size() == 1)
                    j += 1;
                else 
                    j += 2;
            }
        }
    }
    std::cout << "First part: " << sum << "\n";
}

std::string makeNumber2(char digit, char firstL, char secondL, char firstR, char secondR)
{

    if(isdigit(firstL))
    {
        if(isdigit(secondL))
            return std::string() + secondL + firstL + digit;
        else if(isdigit(firstR))
            return std::string() + firstL + digit + firstR;
        else if(!isdigit(secondL))
            return std::string() + firstL + digit;
    }
    else if(isdigit(firstR))
    {
        if(isdigit(secondR))
            return std::string() + digit + firstR + secondR;
        else if(!isdigit(secondR))
            return std::string() + digit + firstR;
    }
    return std::string() + digit;
}

int checkGear(int I, int J, char input[n][n])
{
    size_t i = I - 1;
    size_t j = J - 1;
    size_t endI = I + 1;
    size_t endJ = J + 1;
    int first = 0;
    int second = 0;

    I = i;
    J = j;
    for(i; i <= endI; i++)
    {
        for(j; j <= endJ; j++)
        {
            if(isdigit(input[i][j]))
            {
                char secondLeft = input[i][j - 2];
                char firstLeft = input[i][j - 1];
                char secondRight = input[i][j + 2];
                char firstRight = input[i][j + 1];

                std::string number = makeNumber2(input[i][j], firstLeft, secondLeft, firstRight, secondRight);
                if(!first)
                    first = std::stoi(number);
                else if(std::stoi(number) != first)
                    second = std::stoi(number);

                if(first && second) return first * second;
            }
        }
        j = J;
    }
    return first * second;
}

void secondPart()
{
    int sum = 0;
    int k = 0;
    char input[n][n];
    std::string line;

    std::ifstream File("Input data.txt");

    while(std::getline(File, line))
    {
        for(size_t i = 0; i < line.size(); i++)
        {
            input[k][i] = line[i];
        }
        k++;
    }

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(input[i][j] == '*')
                sum += checkGear(i, j, input);
        }
    }
    std::cout << "Second part: " << sum << "\n";
}

int main()
{
    firstPart();
    secondPart();
}