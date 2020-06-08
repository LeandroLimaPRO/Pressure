/*
Lib Pressure
version: 0.0.1
author: Leandro L. Nascimento 
sentence: Pressure differential MXP serie
paragraph: library for reading differential pressure / gauge sensors from the manufacturer NXP. With pressure return in KPA, PSI, BAR, CMH2O quantities.
category: Sensor Analogic Pressure
*/
#ifndef Pressure_h
#define Pressure_h
#include "Arduino.h"
class Pressure 
{
        //### relacionado à definição de tipos de sensores
        #define MXP5010 0
        //### relacionado à conversões
        #define KPA 0
        #define BAR 1
        #define PSI 2
        #define CMH2O 3
        public:
            Pressure(uint8_t);
            Pressure(uint8_t, double);
            void Init();
            float Get( uint8_t,  uint8_t);


        private:
            int vanalog;
            uint8_t PinAn;
            float pressure;
            float Modo(float valor, uint8_t modo);
            float VFSO = 4.71;

};
#endif
