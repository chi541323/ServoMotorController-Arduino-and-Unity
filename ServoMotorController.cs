using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ServoMotorController : MonoBehaviour
{
    [Range(0, 180)]
    public int servoMotor1, servoMotor2, servoMotor3; // current motor's angle
    int preServoMotor1, preServoMotor2, preServoMotor3; // previous motor's angle
    CommWithArduino commWithArduino;
    // Start is called before the first frame update
    void Start()
    {
        commWithArduino = GameObject.FindObjectOfType(typeof(CommWithArduino)) as CommWithArduino;
        preServoMotor1 = servoMotor1;
        preServoMotor2 = servoMotor2;
        preServoMotor3 = servoMotor3; 
    }

    // Update is called once per frame
    void Update()
    {
        ActuateMotor();
    }

    void ActuateMotor()
    {
        if(preServoMotor1 != servoMotor1)
        {
            commWithArduino.SendToArduino('1', servoMotor1);
        }
        if (preServoMotor2 != servoMotor2)
        {
            commWithArduino.SendToArduino('2', servoMotor2);
        }
        if (preServoMotor3 != servoMotor3)
        {
            commWithArduino.SendToArduino('3', servoMotor3);
        }
        UpdateMotorAngle();
    }

    void UpdateMotorAngle()
    {
        preServoMotor1 = servoMotor1;
        preServoMotor2 = servoMotor2;
        preServoMotor3 = servoMotor3;
    }
}
