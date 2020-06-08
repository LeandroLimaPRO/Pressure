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
            Pressure(uint8_t pinAnalog);
            Pressure(uint8_t pinAnalog, float vfso);
            void Init();
            float Get( uint8_t ref,  uint8_t gran);


        private:
            int vanalog;
            uint8_t PinAn;
            float pressure;
            float Modo(float valor, uint8_t modo);
            float VFSO = 4.71;

};
#endif
