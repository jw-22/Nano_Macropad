#Jason Watts 11/25/2021
#Script for taking character output from Arduino

import serial
import subprocess

ser = 0

#COM port which the Arduino is connected
#on windows, use device manager to determine the COM port used
def serial_con(): 
    global ser
    ser = serial.Serial('COM11', 9600)

#Change path to applications for each key
#Example of path for applications
def key_press1():
    subprocess.Popen(['C:\\Program Files (x86)\\Steam\\Steam.exe'])

def key_press2():
    subprocess.Popen(['C:\\Program Files\\Mozilla Firefox\\firefox.exe'])

def key_press3():
    subprocess.Popen(['Place path to application here'])

def key_press4():
    subprocess.Popen(['Place path to application here'])

#Establish Serial Connection
serial_con()    

while True:
    try:
        msg = ser.read()
        msg = msg.decode("utf-8")

        if msg == 'd':
            key_press1()

        elif msg == 'c':
            key_press2()

        elif msg == 'b':
            key_press3()

        elif msg == 'a':
            key_press4()

    except:
        print("Interrupt")
        break
    