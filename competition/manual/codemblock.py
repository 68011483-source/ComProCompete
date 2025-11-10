from cyberpi import *
import gamepad

#set parameter
dig_ser = 'S4'
mic_ser = 'S2'
mot_l = 'M1'
mot_r = 'M2'

dig_ser_val = 90
mic_ser_val = 90

em_power =50

#set 0
mbot2.servo_set(dig_ser_val, dig_ser)
mbot2.servo_set(mic_ser_val, mic_ser)

while True:
    #movement
    x = gamepad.get_joystick('Lx')
    y = gamepad.get_joystick('Ly')

    l = -(x+y)
    r = -(y-x)

    mbot2.motor_set(l, mot_l)
    mbot2.motor_set(r, mot_r)

    #shooter
    dig_ser_val = int((gamepad.get_joystick('Rx')+100)*180/200)
    mbot2.servo_set(dig_ser_val, dig_ser)

    #Lift
    mbot2.drive_power(0, 0)
    if gamepad.is_key_pressed('Up'):
        mbot2.drive_power(-em_power, 0)
    if gamepad.is_key_pressed('Down'):
        mbot2.drive_power(em_power, 0)

    #Grip
    if gamepad.is_key_pressed('Right'):
        mic_ser_val += 1
        if mic_ser_val>180:
            mic_ser_val = 180
        mbot2.servo_set(mic_ser_val, mic_ser)
    if gamepad.is_key_pressed('Left'):
        mic_ser_val -= 1
        if mic_ser_val<0:
            mic_ser_val = 0
        mbot2.servo_set(mic_ser_val, mic_ser)