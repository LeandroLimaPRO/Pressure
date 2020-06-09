
#ifndef Pressure_h
#define Pressure_h
/*
Lib Pressure
version: 1.0.0
author: Leandro L. Nascimento 
sentence: Pressure differential MXP serie
paragraph: library for reading differential pressure / gauge sensors from the manufacturer NXP. With pressure return in KPA, PSI, BAR, CMH2O quantities.
category: Sensor Analogic Pressure
*/
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
            float Get(uint8_t); // set model, for return value in KPA
            float Get( uint8_t,  uint8_t); //set model and measure type

        private:
            int va__nalog;
            float pressure;
            float VFSO = 4.71;
            uint8_t PinAn;
            float Modo(float, uint8_t);

};
#endif
