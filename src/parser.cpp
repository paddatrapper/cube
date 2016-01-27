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

    State Parser::getState(Coordinate c) {
        unsigned long time {75};
        Vertex v {getCathodePin(c), getAnodePin(c), 255};
        std::vector<Vertex> sVector {v};
        return State {time, sVector};
    }

    void Parser::addDown(double x, double y, std::vector<State>& states)
    {
        for (double i = 1; i > -2; i--) {
            states.push_back(getState(Coordinate {x, y, i}));
        }
    }

    void Parser::addUp(double x, double y, std::vector<State>& states)
    {
        for (double i = -1; i < 2; i++) {
            states.push_back(getState(Coordinate {x, y, i}));
        }
    }

    std::vector<State>& Parser::getStates(std::vector<State>& states)
    {
        states = std::vector<State> {};
        addDown(1, 0, states);
        addUp(1, 1, states);
        addDown(0, 1, states);
        addUp(-1, 1, states);
        addDown(-1, 0, states);
        addUp(-1, -1, states);
        addDown(0, -1, states);
        addUp(1, -1, states);
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
