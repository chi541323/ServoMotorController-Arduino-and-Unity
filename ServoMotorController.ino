#include <Servo.h>

//Servo Motor Pin
#define firstServoPin 7
#define secondServoPin 8
#define thirdServoPin 9

//Sensor Pin
#define firstSensorPin 4
#define secondSensorPin 5
#define thirdSensorPin 6

Servo servoMotor1, servoMotor2, servoMotor3;
String incomingStr;
int motorNum, angle;

// put your setup code here, to run once:
void setup() {
  // set the serial port's Baud rate and parameters
  Serial.begin(115200);
  Serial.setTimeout(10);
  
  // attaches the servo motor #1,#2,#3 on pin 7,8,9 to the servo object
  servoMotor1.attach(firstServoPin); 
  servoMotor2.attach(secondServoPin); 
  servoMotor3.attach(thirdServoPin); 
  
  // set the Pin mode
  pinMode(firstSensorPin, INPUT);
  pinMode(secondSensorPin, INPUT);
  pinMode(thirdSensorPin, INPUT);
}

// put your main code here, to run repeatedly:
void loop() {
  
  actuateMotor();
  getSensorData();
}

// receive the motor's data from Unity
void serialEvent() {
  String incomingStr = Serial.readStringUntil('\n');
  motorNum = getValue(incomingStr, ',', 0).toInt(); // save the motor number to motorNum
  angle = getValue(incomingStr, ',', 1).toInt();  // save the rotate angle to angle
}

void sendToUnity(){
  // use "Serial.print()" or "Serial.println()" to send the sensor's data to Unity
 /* Serial.print(sensorValue0);
    Serial.print(",");
    Serial.println(sensorValue1); */
}

// actuate the motor
void actuateMotor(){
  switch(motorNum){
    case 1:
      servoMotor1.write(angle);
      break;
    case 2:
      servoMotor2.write(angle);
      break;
    case 3:
      servoMotor3.write(angle);
      break;
  }
}

void getSensorData(){
  // put your code which read the sensor's value here, to run repeatedly
}

// split the string
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length() - 1;

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;  //if i == maxIndex,then strIndex[1] = i + 1, else strIndex[1] = i
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : ""; //if found > index, then return myString.substring(from, to), else return ""
}   
