/**
 *    Description:  Definitions for the cube
 *        Version:  1.0
 *        Created:  24/01/2016 19:55:31
 *       Revision:  none
 *       Compiler:  arv-g++
 *
 *         Author:  Kyle Robbertze (kr), paddatrapper@gmail.com
 */

#ifndef _CUBE_H
#define _CUBE_H

#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <StandardCplusplus.h> 
#include <vector>
#include "state.h"

namespace cube {
class Cube
{
    public:
        Cube() { };
        Cube(int numLevels, int numRows);
        Cube(int numLevels, int numRows, 
                int numColmumns);

        void update();
    private:
        int numLeds;
        int numLevels;
        int numRows;
        int numColumns;
        unsigned int currentState;
        std::vector<State> states;
};
}
#endif
