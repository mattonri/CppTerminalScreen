#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {
private:
    int screenHeight;
    int screenWidth;
    char blankChar;
    char** matrix;

public:
    Screen(int screenHeight, int screenWidth, char blankChar);

    // Setters
    void writePixel(int xCoord, int yCoord, char newChar);
    void clearScreen();

    // Getters
    std::string returnScreen();
    std::string returnHLine(int yCoord);
};
#endif