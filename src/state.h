/**
 *    Description:  Defines one state of the cube in time
 *        Version:  1.0
 *        Created:  25/01/2016 08:59:28
 *       Revision:  none
 *       Compiler:  avr-g++
 *
 *         Author:  Kyle Robbertze (kr), paddatrapper@gmail.com
 */

#ifndef _STATE_H
#define _STATE_H

#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <StandardCplusplus.h> 
#include <vector>
#include "vertex.h"

namespace cube {
class State
{
    public:
        State(unsigned long time, std::vector<Vertex> vertices);
        void draw();
    private:
        unsigned long time;
        std::vector<Vertex> vertices;
};
}
#endif
