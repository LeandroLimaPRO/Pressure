# 💻😷 Library for NXP differential pressure sensors
### project resulting from the hidden pandemic, by the MakersMA group. Released for use, provided that it assigns the copyright to the repository dententor.
## Summary 
library for reading differential pressure / gauge sensors from the manufacturer NXP. With pressure return in KPA, PSI, BAR, CMH2O quantities.

> https://www.nxp.com/products/sensors/pressure-sensors:DRSNSPRSSR

### Basic Library step-by-step
-  Call the library and create a Pressure object, containing at least the address of the analog port to which the sensor is located.

```C++
#include "Pressure.h"

Pressure Sensor(A0);
``` 
Or with the help of a multimeter take the operating voltage from the microcontroller to calibrate the sensor:

```C++
#include "Pressure.h"

Pressure Sensor(A0, 4.85);
```

-  Insert the `Init ()` function in the arduino setup

```C++
void setup(){
Sensor.Init();
}
```
- Use `get(MODEL,TYPE OF PRESSURE MEASUREMENT)` to obtain the pressure value. Do this by entering two information 1- Sensor model and 2 - response magnitude.

```C++
void loop(){
float value = Sensor.Get(MXP5010,BAR);
}
```
### Reference 
#### Constants
| MODELS        | TYPE  OF PRESSURE MEASUREMENT| OBS
| --------------------- |:-------------:               |:-------------:|
| MXP5010 👍      | KPA 👍            |   Default     |
| MXP5050 💻      | BAR 👍            |               |
| MXP3700 💻      | PSI 👍            |               |
| -               | CMH2O 👍           |               |

 
```diff 
legend:
👍 is runing,
👎 removed, 
💻 in development
```
## AUTHORS
+ Leandro L. (library developer)
+ Jessica Santos (mathematical modeler)
+ Valdioleno (electronic validation)
#### By Leandro L. N.