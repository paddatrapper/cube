/**
 *    Description:  Translates a folder of Wavefront OBJ files into a series of 
 *                  states
 *        Version:  1.0
 *        Created:  25/01/2016 15:29:50
 *       Revision:  none
 *       Compiler:  avr-g++
 *
 *         Author:  Kyle Robbertze (kr), paddatrapper@gmail.com
 */

#ifndef _PARSER_H
#define _PARSER_H

#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <StandardCplusplus.h> 
#include <vector>
#include "state.h"

namespace cube {
struct Coordinate
{
    double x;
    double y;
    double z;
};

class Parser
{
    public:
        Parser(int numRows, int numColumns, int numLevels);
        std::vector<State>& getStates(std::vector<State>& states);
    private:
        int getAnodePin(Coordinate c);
        int getCathodePin(Coordinate c);
        int getPin(int c, int total);

        const int LED_PIN_OFFSET = 4;
        const int LEVEL_PIN_OFFSET = 13;
        int numRows;
        int numColumns;
        int numLevels;

};
}
#endif
