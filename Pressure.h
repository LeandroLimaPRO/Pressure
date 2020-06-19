
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
        #define MPX5010 0
        #define MPX5050 1
        #define MPX5700 2
        #define MPX5999 3
        //### relacionado à conversões
        #define KPA 0
        #define BAR 1
        #define PSI 2
        #define CMH2O 3
        public:
            Pressure(uint8_t); //pin
            Pressure(uint8_t, uint8_t);// pin, model
            Pressure(uint8_t, double); // pin, vsfo
            Pressure(uint8_t, uint8_t, double); // pin, model, vsfo
            void Init();
            float Get(); // set model, for return value in KPA
            float Get(uint8_t); // measure type
            float GetBulk(uint8_t, float); // get volume (time, area)
        private:
            int va__nalog; //val sensor
            float VFSO = 4.75; //default vsfo
            uint8_t Pin___An; //pin analog
            uint8_t Modelo___op; // save model sensor
            uint8_t last__time; // save last temp
            float Modo(float); // selected model

};
#endif
