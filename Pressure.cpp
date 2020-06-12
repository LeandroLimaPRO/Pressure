/*
Lib Pressure
version: 1.0.0
author: Leandro L. Nascimento 
sentence: Pressure differential MXP serie
paragraph: library for reading differential pressure / gauge sensors from the manufacturer NXP. With pressure return in KPA, PSI, BAR, CMH2O quantities.
category: Sensor Analogic Pressure
*/
#include "Pressure.h"

Pressure::Pressure(uint8_t pinAnalog)// obj Pressure, insert the analog pin
{
    PinAn = pinAnalog; // PIN ANALOGC FOR GET VALUE
}
Pressure::Pressure(uint8_t pinAnalog, double vfso)// obj Pressure, insert the analog pin, then measure the AD voltage with a multimeter, and enter the value.
{
    PinAn = pinAnalog; // PIN ANALOGC FOR GET VALUE
    VFSO = vfso; // VOLTAGE OPERATION SENSOR.
}
void Pressure::Init()// Func. Initialize, set into setup
{
    pinMode(PinAn, INPUT); //SET PIN AS INPUT
}

float Pressure::Modo(float val___Analog,  uint8_t Model)// PRESSURE SENSOR MODEL
{
    
    switch (Model)
    {
        
    case 0: // MXP5010
         return ((((val___Analog/1023)*VFSO)-0.2)/0.45); // SENSOR TRANSFER FUNCTION OBTAINED FROM DATASHEET
        break;
    case 1: // MXP5050 // SENSOR TRANSFER FUNCTION OBTAINED FROM DATASHEET
            return ((((val___Analog/1023)*VFSO)-0.2)/0.09); // INSERT TRANSFER FUNCTION IN THE PLACE OF "NULL"
        break;
     case 2: // MXP5700 // SENSOR TRANSFER FUNCTION OBTAINED FROM DATASHEET
            return ((((val___Analog/1023)*VFSO)-0.2)/0.006429); // INSERT TRANSFER FUNCTION IN THE PLACE OF "NULL"
        break;
    case 3: // MXP5050 // SENSOR TRANSFER FUNCTION OBTAINED FROM DATASHEET
            return ((((val___Analog/1023)*VFSO)-0.2)/0.004505); // INSERT TRANSFER FUNCTION IN THE PLACE OF "NULL"
        break; // MPX5999D 
    default:// MXP5010 //// ADD DEFINE IN .H FOR OTHER MODELS END INSERT FUNCTION TRANSFER IN CASE N+1
        return ((((val___Analog/1023)*VFSO)-0.2)/0.45);
        break;
    }
}
/*
Get (GREATNESS, SENSOR MODEL)
GREATNESS OF RETURN: KPA, BAR, PSI, CMH2O (DEFAULT: KPA)
SENSOR MODEL: MXP5010 (DEFAULT MXP5010)
*/
float Pressure::Get(uint8_t model){
    int val___Analog = analogRead(PinAn); // GET ADC VALUE
    float v_pressure = Modo(val___Analog, model); // CALCULATE PRESSURE BASED MODEL
    return v_pressure;
}
float Pressure::Get( uint8_t model,  uint8_t gran){
        int val___Analog = analogRead(PinAn); // GET ADC VALUE
        float v_pressure = Modo(val___Analog, model); // CALCULATE PRESSURE BASED MODEL
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
            return v_pressure*10.01972;
            break;
        default: // KPA
            return v_pressure;
            break;
        }

}
