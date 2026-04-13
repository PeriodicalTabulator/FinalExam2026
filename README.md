# FinalExam2026

This repository contains more or less 15 practical question for final exam on SPSIT

Every question is separeted in directory. Please build only specific directory if README file doesnt say otherwise


# 1.meranie

point is to count how long is button holded 
when button is holded buzzer will make sound and LED is lighted
code is in Sketch.ino (it is writen in wokwi emulator so I let it in .ino file for straight forwardnes)
note that I used lcd I2C mainly cuz of the easiest connection to the Arduino
Library is needed (LiquidCrystal_I2C.h) in #include


# Main.py
it is backend for one of the questions for angular and fastapi
cuz of Void linux changes in 2023 i need to create env but probablly you dont idk (its always best to create virtual env before executing)


# WAN eigrp
create wan with eigrp protocol (commands are in txt)
remember to add HWIC-2T modules to routers
| Device | Interface | IP address | Mask | Default gateway |
|------------|-----------|-----------|-------|-----------------|
| HQ         | G0/0      | 192.168.0.1 | /25 | - |
| HQ         | G0/1      | 192.168.0.129 | /26 | - |
| HQ         | S0/1/0    | 192.168.2.1 | /30 | - |
| HQ         | S0/1/1    | 192.168.2.5 | /30 | - |
| R1         | G0/0      | 192.168.1.1 | /26 | - |
| R1         | S0/1/0    | 192.168.2.2 | /30 | - |
| R2         | G0/0      | 192.168.1.65 | /27 | - |
| R2         | S0/1/1    | 192.168.2.6 | /30 | - |
| PC_HQ1     | NIC       | 192.168.0.2 | /25 | 192.168.0.1 |
| PC_HQ2     | NIC       | 192.168.0.130 | /26 | 192.168.0.129 |
| PC_R1      | NIC       | 192.168.1.2 | /26 | 192.168.1.1 |
| PC_R2      | NIC       | 192.168.1.66 | /27 | 192.168.1.65 |
