#include "screen.h"
#include <iostream>

Screen::Screen(int screenHeight, int screenWidth, char blankChar) {
    this->screenHeight = screenHeight;
    this->screenWidth = screenWidth;
    this->blankChar = blankChar;
    matrix = new char*[screenHeight];
    for (int i = 0; i < screenHeight; ++i) {
        matrix[i] = new char[screenWidth];
    }
    for (int i = 0; i < screenHeight; ++i) {
        for (int j = 0; j < screenWidth; ++j) {
            matrix[i][j] = blankChar;
        }
    }
}
// Setters
void Screen::writePixel(int xCoord, int yCoord, char newChar) {
    matrix[yCoord][xCoord] = newChar;
}
void Screen::clearScreen() {
    for (int i = 0; i < screenHeight; ++i) {
        for (int j = 0; j < screenWidth; ++j) {
            matrix[i][j] = blankChar;
        }
    }
}

// Getters
std::string Screen::returnScreen() {
    std::string output = "";
    for (int i = 0; i < screenHeight; ++i) {
        for (int j = 0; j < screenWidth; ++j) {
            output += matrix[i][j];
        }
        output += '\n';
    }
    return output;
}
std::string Screen::returnHLine(int yCoord) {
    std::string output = "";
        for (int j = 0; j < screenWidth; ++j) {
            output += matrix[yCoord][j];
        }
    return output;
}