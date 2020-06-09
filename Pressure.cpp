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

float Pressure::Modo(float valor,  uint8_t Model)// PRESSURE SENSOR MODEL
{
    
    switch (Model)
    {
        
    case 0: // MXP5010
         return ((((valor/1023)*VFSO)-0.2)/0.45); // SENSOR TRANSFER FUNCTION OBTAINED FROM DATASHEET
        break;
    case 1: // MXP3700
            return 0.00; // INSERT TRANSFER FUNCTION IN THE PLACE OF "NULL"
        break;
    default:// MXP5010 //// ADD DEFINE IN .H FOR OTHER MODELS END INSERT FUNCTION TRANSFER IN CASE N+1
        return ((((valor/1023)*VFSO)-0.2)/0.45);
        break;
    }
}
/*
Get (GREATNESS, SENSOR MODEL)
GREATNESS OF RETURN: KPA, BAR, PSI, CMH2O (DEFAULT: KPA)
SENSOR MODEL: MXP5010 (DEFAULT MXP5010)
*/
float Pressure::Get(){
        uint8_t def_tag_pressure = 0;
        int val = analogRead(PinAn); // GET ADC VALUE
        float v_pressure = Modo(val, def_tag_pressure); // CALCULATE PRESSURE BASED MODEL
        switch (def_tag_pressure)
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
float Pressure::Get( uint8_t model){
        int val = analogRead(PinAn); // GET ADC VALUE
        float v_pressure = Modo(val, model); // CALCULATE PRESSURE BASED MODEL
        int8_t gran__P = 0;
        switch (gran__P)
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
float Pressure::Get( uint8_t model,  uint8_t gran){
        int val = analogRead(PinAn); // GET ADC VALUE
        float v_pressure = Modo(val, model); // CALCULATE PRESSURE BASED MODEL
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
