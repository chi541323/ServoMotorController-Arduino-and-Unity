using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.IO.Ports;

public class CommWithArduino : MonoBehaviour
{
    // set the port varilb
    public string portName;
    public int baudRate = 115200;
    SerialPort arduinoSerial;

    // Start is called before the first frame update
    void Start()
    {
        arduinoSerial = new SerialPort(portName, baudRate);
        arduinoSerial.ReadTimeout = 10;
        arduinoSerial.Open();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    //Read the data from the Arduino
    public void ReadFromArduino()
    {
        string str = null;
        try
        {
            str = arduinoSerial.ReadLine();
            string[] words = str.Split(',');
        }

        catch (TimeoutException e)
        {
        }
    }

    //Send the servo motor's data to the arduino
    public void SendToArduino(char MotorNum, int degree)
    {
        // check the port is available
        if (arduinoSerial.IsOpen)
        {
            arduinoSerial.WriteLine(MotorNum + "," + degree);
            Debug.Log(MotorNum + " , " + degree); // print the info
        }
    }
}
