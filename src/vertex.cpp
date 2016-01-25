/**
 *    Description:  Defines a 3D point in space
 *        Version:  1.0
 *        Created:  25/01/2016 08:52:23
 *       Revision:  none
 *       Compiler:  avr-g++
 *
 *         Author:  Kyle Robbertze (kr), paddatrapper@gmail.com
 */

#include <Arduino.h>
#include "vertex.h"

namespace cube {
    Vertex::Vertex(int cathodePin, int anodePin, int intensity)
    {
        this->cathodePin = cathodePin;
        this->anodePin = anodePin;
        this->intensity = intensity;
        initialiseLed();
    }

    void Vertex::show()
    {
        analogWrite(cathodePin, intensity);
        digitalWrite(anodePin, HIGH);
    }

    void Vertex::clear()
    {
        digitalWrite(cathodePin, LOW);
        digitalWrite(anodePin, LOW);
    }

    void Vertex::initialiseLed()
    {
        pinMode(cathodePin, OUTPUT);
        pinMode(anodePin, OUTPUT);
    }
}
