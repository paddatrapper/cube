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
        unsigned long time {500};
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
        states.push_back(getState(Coordinate {0, 0, 0}));

        Coordinate c[9];
        int i = 0;
        for (double j = -1; j < 2; j++) {
            for (double k = -1; k < 2; k++) {
                c[i++] = Coordinate {j, k, 1};
            }
        }
         
        std::vector<Vertex> v;
        for (auto coord : c)
            v.push_back(Vertex {getCathodePin(coord), getAnodePin(coord), 225});
        states.push_back(State {500, v});
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
