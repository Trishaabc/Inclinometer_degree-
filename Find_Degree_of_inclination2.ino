
#include <math.h>
const int channel_pin1 =2;
const int channel_pin2 =15;
                                                                                  
int sum_angle_x=0;
int sum_angle_y=0;

int avg_angle_x;
int avg_angle_y;
unsigned long int event_time=500;
unsigned long int previous_time=0;
unsigned long int current_time=millis();
int count1=0;
int count2=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
void loop()
{
  // put your main code here, to run repeatedly:
 int reading1_x = analogRead(channel_pin1);
  int reading2_y = analogRead(channel_pin2);
// Serial.print("reading1");
 //Serial.print(reading1_x);

// Serial.print("\t reading2");
 //Serial.println(reading2_y);
 
 double voltage_x= (double)reading1_x*3.30;
 voltage_x= voltage_x/pow(2,12); // incoming voltage along x-axis
 delay(200);
                                                                                                              
double voltage_y = (double)reading2_y*3.30;
voltage_y = voltage_y/pow(2,12);//incoming voltage along y-axis

Serial.print("\t voltage_x = ");
Serial.print(voltage_x,4);//print voltage along x-axis

Serial.print("\t voltage_y = ");
Serial.println(voltage_y,4);//print voltage along y-axis

int angle_1 = 248.8743+(-283.4196)*voltage_x; //angle along x-axis
int angle_2 = 283.8643+(-318.0734)*voltage_y; //angle along y-axis

Serial.print("\t angle_1 = ");
Serial.print(angle_1);//print angle along x-axis

Serial.print("\t angle_2 = ");
Serial.println(angle_2);//print angle along y-axis


/*if(current_time-previous_time<= event_time)
  {
  sum_angle_x = sum_angle_x+ angle_1;
  count1++;
  }
  avg_angle_x = sum_angle_x/count1; //avg angle along x axis
  Serial.print("\t avg_angle_x");
  Serial.println(avg_angle_x);

  
if(current_time-previous_time<= event_time)
{
  sum_angle_y= sum_angle_y+ angle_2;
  count2++;
}
 avg_angle_y = sum_angle_y/count2;
 Serial.print("\t avg_angle_y");
 Serial.println(avg_angle_y);

   /* for(int i=0;i<=10;i++)
  {
   sum_angle_y= sum_angle_y+ angle_2 ;
   }
 avg_angle_y = sum_angle_y/10;  // avg angle along y axis
 
*/
delay(1000);//1s delay
}
