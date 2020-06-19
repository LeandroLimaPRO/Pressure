/*
Lib Pressure
version: 1.0.0
author: Leandro L. Nascimento 
sentence: Pressure differential MXP serie
paragraph: library for reading differential pressure / gauge sensors from the manufacturer NXP. With pressure return in KPA, PSI, BAR, CMH2O quantities.
category: Sensor Analogic Pressure
*/
#include "Pressure.h"

Pressure::Pressure(uint8_t Pin___Analog)// obj Pressure, insert the analog pin
{
    Pin___An = Pin___Analog; // PIN ANALOGC FOR GET VALUE
}
Pressure::Pressure(uint8_t Pin___Analog, uint8_t model___op)// obj Pressure, insert the analog pin, then measure the AD voltage with a multimeter, and enter the value.
{
    Pin___An = Pin___Analog; // PIN ANALOGC FOR GET VALUE
    Modelo___op = model___op; // VOLTAGE OPERATION SENSOR.
}
Pressure::Pressure(uint8_t Pin___Analog, double vfso)// obj Pressure, insert the analog pin, then measure the AD voltage with a multimeter, and enter the value.
{
    Pin___An = Pin___Analog; // PIN ANALOGC FOR GET VALUE
    VFSO = vfso; // VOLTAGE OPERATION SENSOR.
}
Pressure::Pressure(uint8_t Pin___Analog, uint8_t model___op, double vfso)// obj Pressure, insert the analog pin, then measure the AD voltage with a multimeter, and enter the value.
{
    Pin___An = Pin___Analog; // PIN ANALOGC FOR GET VALUE
    Modelo___op = model___op;
    VFSO = vfso; // VOLTAGE OPERATION SENSOR.
    
}
void Pressure::Init()// Func. Initialize, set into setup
{
    pinMode(Pin___An, INPUT); //SET PIN AS INPUT
}

float Pressure::Modo(float val___Analog)// PRESSURE SENSOR MODEL
{
    
    switch (Modelo___op)
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
float Pressure::Get(){
    int val___Analog = analogRead(Pin___An); // GET ADC VALUE
    float v___pressure = Modo(val___Analog); // CALCULATE PRESSURE BASED MODEL
    return v___pressure;
}
float Pressure::Get(uint8_t gran){
        int val___Analog = analogRead(Pin___An); // GET ADC VALUE
        float v___pressure = Modo(val___Analog); // CALCULATE PRESSURE BASED MODEL
        switch (gran)
        {
            
        case 0: // KPA
            return v___pressure;
            break;
            
        case 1: // BAR
            return v___pressure/100;
            break;
            
        case 2: // PSI
            return v___pressure/6.895;
            break;
        case 3: // CMH2O
            return v___pressure*10.01972;
            break;
        default: // KPA
            return v___pressure;
            break;
        }

}
