/**
 *    Description:  Translates a Wavefront OBJ file into a 3x3x3 LED cube
 *        Version:  1.0
 *        Created:  24/01/2016 17:20:19
 *       Revision:  none
 *       Compiler:  avr-g++
 *
 *         Author:  Kyle Robbertze (kr), paddatrapper@gmail.com
 */

#include <Arduino.h>
#include "cube.h"

cube::Cube ledCube {3, 3};

void setup()
{
}

void loop()
{
    ledCube.update();
}
