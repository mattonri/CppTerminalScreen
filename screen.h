#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {
private:
    int screenHeight;
    int screenWidth;
    char** matrix = new char*[screenHeight];

public:
    Screen(int screenHeight, int screenWidth);

    // Setters
    void writePixel(int xCoord, int yCoord);
    void writeVLine(int xCoord);
    void writeHLine(int yCoord);
    void clearScreen();

    // Getters
    std::string returnScreen();
    std::string returnHLine(int yCoord);
};
#endif