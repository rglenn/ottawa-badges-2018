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
U 1 1 5B8E1D4F
P 4900 2950
F 0 "D1" H 4900 3050 50  0000 C CNN
F 1 "LED" H 4900 2850 50  0000 C CNN
F 2 "LEDs:LED_D5.0mm" H 4900 2950 50  0001 C CNN
F 3 "" H 4900 2950 50  0001 C CNN
	1    4900 2950
	0    -1   -1   0   
$EndComp
$Comp
L LED D2
U 1 1 5B8E1D9C
P 5400 2950
F 0 "D2" H 5400 3050 50  0000 C CNN
F 1 "LED" H 5400 2850 50  0000 C CNN
F 2 "LEDs:LED_D5.0mm" H 5400 2950 50  0001 C CNN
F 3 "" H 5400 2950 50  0001 C CNN
	1    5400 2950
	0    -1   -1   0   
$EndComp
$Comp
L R R1
U 1 1 5B8E1DC3
P 4900 2450
F 0 "R1" V 4980 2450 50  0000 C CNN
F 1 "470" V 4900 2450 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4830 2450 50  0001 C CNN
F 3 "" H 4900 2450 50  0001 C CNN
	1    4900 2450
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5B8E1E12
P 5400 2450
F 0 "R2" V 5480 2450 50  0000 C CNN
F 1 "470" V 5400 2450 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 5330 2450 50  0001 C CNN
F 3 "" H 5400 2450 50  0001 C CNN
	1    5400 2450
	1    0    0    -1  
$EndComp
$Comp
L Battery_Cell BT1
U 1 1 5B8E1E47
P 3800 2800
F 0 "BT1" H 3900 2900 50  0000 L CNN
F 1 "Battery_Cell" H 3900 2800 50  0000 L CNN
F 2 "BadgeParts:CR2032-SHRAPNEL" V 3800 2860 50  0001 C CNN
F 3 "" V 3800 2860 50  0001 C CNN
	1    3800 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 2600 3800 2200
Wire Wire Line
	3800 2200 5400 2200
Wire Wire Line
	5400 2200 5400 2300
Wire Wire Line
	4900 2300 4900 2200
Connection ~ 4900 2200
Wire Wire Line
	5400 3100 5400 3200
Wire Wire Line
	5400 3200 3800 3200
Wire Wire Line
	3800 3200 3800 2900
Wire Wire Line
	4900 3100 4900 3200
Connection ~ 4900 3200
Wire Wire Line
	4900 2800 4900 2600
Wire Wire Line
	5400 2800 5400 2600
$EndSCHEMATC
