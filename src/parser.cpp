/**
 *    Description:  Translates a folder of Wavefront OBJ files into a series of
 *                  states
 *        Version:  1.0
 *        Created:  25/01/2016 15:35:27
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Kyle Robbertze (kr), paddatrapper@gmail.com
 */

#include "parser.h"
#include "vertex.h"

namespace cube {
    Parser::Parser(int numRows, int numColumns, int numLevels) :
        numRows {numRows},
        numColumns {numColumns},
        numLevels {numLevels}
    { }

    State Parser::getState(unsigned long time, Coordinate c) {
        Vertex v {getCathodePin(c), getAnodePin(c)};
        std::vector<Vertex> sVector {v};
        return State {time, sVector};
    }

    std::vector<State>& Parser::getStates(std::vector<State>& states)
    {
        states = std::vector<State> {};
        for (double i = 0; i < numLevels; i++) {
            for (double j = 0; j < numRows; j++) {
                for (double k = 0; k < numColumns; k++) {
                    unsigned long t {1 * 100};
                    Coordinate c = {k, j, j};
                    states.push_back(getState(t, c));
                }
            }
        }
        return states;
    }

    int Parser::getAnodePin(Coordinate c)
    {
        return getPin(c.z, numLevels) + LEVEL_PIN_OFFSET;
    }

    int Parser::getCathodePin(Coordinate c)
    {
        int cathodeX = getPin(c.x, numColumns);
        int cathodeY = getPin(c.y, numRows);

        return numRows * cathodeY + cathodeX + LED_PIN_OFFSET;
    }

    int Parser::getPin(int c, int total)
    {
        if (total % 2 == 0)
            return c + total / 2;
        else
            return c + (total - 1) / 2;
    }
}
