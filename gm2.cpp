#include <iostream>
#include <string>
#include <array>
#include <bitset>

std::array<bool,4> indextocode(int i);

auto const printcontainer = [](auto container){for(auto& i : container) std::cout << i;
std::cout << '\n';};

auto strtoboolarr = [](auto& container, std::string input)
{int it = 0; for (auto& i: input){container.at(it) = (i == '1'); ++it;}};

int gm2loop()
{
    std::string input;
    std::array<bool,4> code;
    std::cout << "Input your code\n>";
    std::cin >> input;
    strtoboolarr(code,input);
    printcontainer(indextocode(2));
    printcontainer(indextocode(4));
    printcontainer(indextocode(8)); 
    printcontainer(indextocode(15));
    return 9000;
}


std::array<bool,4> indextocode(int i){
    std::string codestr = std::bitset<4>(i).to_string();
    std::array<bool,4> code;
    strtoboolarr(code,codestr);
    return code;
}
