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
    {
    }

    std::vector<State>& Parser::getStates(std::vector<State>& states)
    {
        unsigned long t1 {3 * 1000};
        Coordinate c1 = {0, 0, 0};
        Vertex v1 {getCathodePin(c1), getAnodePin(c1)};
        std::vector<Vertex> s1Vector {v1};
        State s1 {t1, s1Vector};
        
        unsigned long t2 {3 * 1000};
        Coordinate c2 = {1, -1, 0};
        Coordinate c3 = {-1, 1, 0};
        Vertex v2 {getCathodePin(c2), getAnodePin(c2)};
        Vertex v3 {getCathodePin(c3), getAnodePin(c3)};
        std::vector<Vertex> s2Vector {v2, v3};
        State s2 {t2, s2Vector};

        states = std::vector<State> {s1, s2};
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
