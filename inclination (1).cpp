#include "Arduino.h"
#include "inclination.h"

Inclination ::Inclination(int channel_pin1,int channel_pin2)
{
  pinMode(channel_pin1,INPUT);
  pinMode(channel_pin2,INPUT);

  _channel_pin1=channel_pin1;
  _channel_pin2=channel_pin2;
  }
Inclination::double readAnalog_voltage(double voltage_x,double voltage_y)
{ 
  int reading1_x = analogRead(channel_pin1);//analog data read from  pin 2
 int reading2_y = analogRead(channel_pin2);//analog data read from  pin 15
 
 double voltage_x= (double)reading1_x*3.30;//convert analog data to voltage reading for x-axis
 voltage_x= voltage_x/pow(2,12); // incoming voltage along x-axis
 delay(200);
                                                                                                              
double voltage_y = (double)reading2_y*3.30;//convert analog data to voltage reading for y-axis
voltage_y = voltage_y/pow(2,12);//incoming voltage along y-axis

Serial.print("\t voltage_x = ");
Serial.print(voltage_x,4);//print voltage along x-axis

Serial.print("\t voltage_y = ");
Serial.println(voltage_y,4);//print voltage along y-axis
return(voltage_x);
return(voltage_y);
  }
Inclination::int readAngle(int angle_1,int angle_2)
{
int angle_1 = 248.8743+(-283.4196)*readAnalog_voltage(voltage_x); //angle along x-axis
int angle_2 = 283.8643+(-318.0734)*readAnalog_voltage(voltage_y); //angle along y-axis

Serial.print("\t angle_1 = ");
Serial.print(angle_1);//print angle along x-axis

Serial.print("\t angle_2 = ");
Serial.println(angle_2);//print angle along y-axis

return(angle_1);
return(angle_2);
delay(1000);//1s delay

}
