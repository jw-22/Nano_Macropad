#Jason Watts 11/25/2021
#Script for taking character output from Arduino

import serial
import subprocess

ser = 0

#Port which the Arduino is connected

def serial_con(): 
    global ser
    ser = serial.Serial('/dev/cu.usbserial-1220', 9600)
    
#Change path to applications for each key
#Example of path for applications
def key_press1():
    subprocess.Popen(["open", "/Applications/Firefox.app"])

def key_press2():
    subprocess.Popen(["open", "/Applications/Termius.app"])

def key_press3():
    subprocess.Popen(["open", "/Applications/Spotify.app"])

def key_press4():
    subprocess.Popen(["open", "/Applications/iTerm.app"])

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
    