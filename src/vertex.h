/**
 *    Description:  Defines a 3D point in space
 *        Version:  1.0
 *        Created:  25/01/2016 08:45:41
 *       Revision:  none
 *       Compiler:  avr-g++
 *
 *         Author:  Kyle Robbertze (kr), paddatrapper@gmail.com
 */

#ifndef _VERTEX_H
#define _VERTEX_H
namespace cube {
class Vertex
{
    public:
        Vertex(int cathodePin, int anodePin, int intensity=255);

        void show();
        void clear();

    private:
        void initialiseLed();

        int intensity;
        int cathodePin;
        int anodePin;

};
}
#endif
