EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:makey-floating-pcb-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LED D1
U 1 1 5B5F916F
P 5500 3250
F 0 "D1" H 5500 3350 50  0000 C CNN
F 1 "LED" H 5500 3150 50  0000 C CNN
F 2 "LEDs:LED_0603" H 5500 3250 50  0001 C CNN
F 3 "" H 5500 3250 50  0001 C CNN
	1    5500 3250
	0    -1   -1   0   
$EndComp
$Comp
L LED D2
U 1 1 5B5F91EC
P 5900 3250
F 0 "D2" H 5900 3350 50  0000 C CNN
F 1 "LED" H 5900 3150 50  0000 C CNN
F 2 "LEDs:LED_0603" H 5900 3250 50  0001 C CNN
F 3 "" H 5900 3250 50  0001 C CNN
	1    5900 3250
	0    -1   -1   0   
$EndComp
$Comp
L LED D3
U 1 1 5B5F924C
P 7500 3250
F 0 "D3" H 7500 3350 50  0000 C CNN
F 1 "LED" H 7500 3150 50  0000 C CNN
F 2 "LEDs:LED_0603" H 7500 3250 50  0001 C CNN
F 3 "" H 7500 3250 50  0001 C CNN
	1    7500 3250
	0    -1   -1   0   
$EndComp
$Comp
L LED D4
U 1 1 5B5F9285
P 7100 3250
F 0 "D4" H 7100 3350 50  0000 C CNN
F 1 "LED" H 7100 3150 50  0000 C CNN
F 2 "LEDs:LED_0603" H 7100 3250 50  0001 C CNN
F 3 "" H 7100 3250 50  0001 C CNN
	1    7100 3250
	0    -1   -1   0   
$EndComp
$Comp
L LED D5
U 1 1 5B5F932B
P 6300 3250
F 0 "D5" H 6300 3350 50  0000 C CNN
F 1 "LED" H 6300 3150 50  0000 C CNN
F 2 "LEDs:LED_D3.0mm_Horizontal_O1.27mm_Z2.0mm" H 6300 3250 50  0001 C CNN
F 3 "" H 6300 3250 50  0001 C CNN
	1    6300 3250
	0    -1   -1   0   
$EndComp
$Comp
L LED D6
U 1 1 5B5F9368
P 6700 3250
F 0 "D6" H 6700 3350 50  0000 C CNN
F 1 "LED" H 6700 3150 50  0000 C CNN
F 2 "LEDs:LED_D3.0mm_Horizontal_O1.27mm_Z2.0mm" H 6700 3250 50  0001 C CNN
F 3 "" H 6700 3250 50  0001 C CNN
	1    6700 3250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5500 3100 5500 3000
Wire Wire Line
	5500 3000 6300 3000
Wire Wire Line
	6300 2900 6300 3100
Wire Wire Line
	5900 3100 5900 3000
Connection ~ 5900 3000
Wire Wire Line
	5500 3400 5500 3500
Wire Wire Line
	5200 3500 7500 3500
Wire Wire Line
	6300 3500 6300 3400
Wire Wire Line
	5900 3400 5900 3500
Connection ~ 5900 3500
Wire Wire Line
	6700 2800 6700 3100
Wire Wire Line
	6700 3000 7500 3000
Wire Wire Line
	7500 3000 7500 3100
Wire Wire Line
	7100 3100 7100 3000
Connection ~ 7100 3000
Wire Wire Line
	6700 3500 6700 3400
Wire Wire Line
	7100 3500 7100 3400
Connection ~ 7100 3500
Connection ~ 6700 3500
Connection ~ 6300 3500
$Comp
L Conn_01x03 J1
U 1 1 5B5F9607
P 4900 2900
F 0 "J1" H 4900 3100 50  0000 C CNN
F 1 "Conn_01x03" H 4900 2700 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 4900 2900 50  0001 C CNN
F 3 "" H 4900 2900 50  0001 C CNN
	1    4900 2900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5200 3500 5200 3000
Wire Wire Line
	5200 3000 5100 3000
Connection ~ 5500 3500
Connection ~ 6300 3000
Connection ~ 6700 3000
Wire Wire Line
	7500 3500 7500 3400
Wire Wire Line
	5100 2900 6300 2900
Wire Wire Line
	5100 2800 6700 2800
$EndSCHEMATC
