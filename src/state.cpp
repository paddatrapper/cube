/**
 *    Description:  Defines one state of the cube in time
 *        Version:  1.0
 *        Created:  25/01/2016 09:07:33
 *       Revision:  none
 *       Compiler:  avr-g++
 *
 *         Author:  Kyle Robbertze (kr), paddatrapper@gmail.com
 */

#include <Arduino.h>
#include "state.h"

namespace cube {
    State::State(unsigned long time, std::vector<Vertex> vertices)
    {
        this->time = time;
        this->vertices = vertices;
    }

    void State::draw()
    {
        unsigned long startSystemTime = millis();
        while (millis() - startSystemTime < time) {
            for (auto &vertex : vertices) {
                vertex.show();
                vertex.clear();
            }
        }
    }
}
