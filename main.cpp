#include <iostream>
#include <vector>

int gm1loop();
int gm2loop();

int main()
{
    std::cout << "enter (1) for Gamemode 1\nenter (2) for Gamemode2\n>";
    int mode = 0;
    std::cin >> mode;
    switch(mode){
    case 1:
        gm1loop(); break;
    case 2:
        gm2loop();
        break;
    }
    return 0;
}
