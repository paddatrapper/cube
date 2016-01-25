/**
 *    Description:  A cube
 *        Version:  1.0
 *        Created:  24/01/2016 20:45:25
 *       Revision:  none
 *       Compiler:  avr-g++
 *
 *         Author:  Kyle Robbertze (kr), paddatrapper@gmail.com
 */

#include "cube.h"
#include "parser.h"

namespace cube {
    Cube::Cube(int numLevels, int numRows, int numColumns) :
        numLeds {numRows * numColumns * numLevels},
        numLevels {numLevels},
        numRows {numRows},
        numColumns {numColumns}
    {
        Parser p {numRows, numColumns, numLevels};
        states = p.getStates(states);
        currentState = 0;
    }

    Cube::Cube(int numLevels, int numRows) : 
        Cube(numLevels, numRows, numRows)
    { }

    void Cube::update()
    {
        if (currentState >= states.size())
            currentState = 0;
        states[currentState++].draw();
    }
}
