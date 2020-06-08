/*
Lib Pressure
version: 0.0.1
author: Leandro L. Nascimento 
sentence: Pressure differential MXP serie
paragraph: library for reading differential pressure / gauge sensors from the manufacturer NXP. With pressure return in KPA, PSI, BAR, CMH2O quantities.
category: Sensor Analogic Pressure
*/
#include "Pressure.h"

Pressure::Pressure(uint8_t pinAnalog)// obj Pressure, insert the analog pin
{
    PinAn = pinAnalog;
}
Pressure::Pressure(uint8_t pinAnalog, float vfso)// obj Pressure, insert the analog pin, then measure the AD voltage with a multimeter, and enter the value.
{
    PinAn = pinAnalog;
    VFSO = vfso;
}
void Pressure::Init()// Func. Initialize, set into setup
{
    pinMode(PinAn, INPUT);
}

float Pressure::Modo(float valor,  uint8_t Modo)// PRESSURE SENSOR MODEL
{
    
    switch (Modo)
    {
        
    case 0: // MXP5010
         return ((((valor/1023)*VFSO)-0.2)/0.45); // FUNC. DE TRANFERENCIA DO SENSOR OBTIDO NO DATASHEET
        break;
    
    default:// MXP5010 //// ADD DEFINE IN .H FOR OTHER MODELS END INSERT FUNCTION TRANSFER IN CASE N+1
        return ((((valor/1023)*VFSO)-0.2)/0.45);
        break;
    }
}
/*
Get (RETURN GREATNESS, SENSOR MODEL)
GREATNESS OF RETURN: KPA, BAR, PSI, CMH2O (DEFAULT: KPA)
SENSOR MODEL: MXP5010 (DEFAULT MXP5010)
*/
float Pressure::Get( uint8_t ref,  uint8_t gran){
        int val = analogRead(PinAn); // GET ADC VALUE
        float v_pressure = Modo(val, ref); // CALCULATE PRESSURE BASED MODEL
        switch (gran)
        {
            
        case 0: // KPA
            return v_pressure;
            break;
            
        case 1: // BAR
            return v_pressure/100;
            break;
            
        case 2: // PSI
            return v_pressure/6.895;
            break;
        case 3: // CMH2O
            return v_pressure*10.197;
            break;
        default: // KPA
            return v_pressure;
            break;
        }

}
