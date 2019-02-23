EESchema Schematic File Version 4
LIBS:Retruino-cache
EELAYER 26 0
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
L Arduino:Arduino_Pro_Mini U1
U 1 1 5C5F1999
P 4550 2900
F 0 "U1" H 4575 1264 50  0000 C CNN
F 1 "Arduino_Pro_Mini" H 4575 1173 50  0000 C CNN
F 2 "Retruino:Arduino_pro_mini" H 5000 1400 50  0001 C CNN
F 3 "" H 5000 1400 50  0001 C CNN
	1    4550 2900
	1    0    0    -1  
$EndComp
$Comp
L Arduino:1.8_TFT_DISPLAY U3
U 1 1 5C5F1CA6
P 6250 5000
F 0 "U3" H 6728 5178 50  0000 L CNN
F 1 "1.8_TFT_DISPLAY" H 6728 5087 50  0000 L CNN
F 2 "Retruino:1.8_TFT_Display" H 6450 4850 50  0001 C CNN
F 3 "" H 6450 4850 50  0001 C CNN
	1    6250 5000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4950 3900 5050 3900
Wire Wire Line
	5050 3900 5050 5100
Wire Wire Line
	5050 5100 5600 5100
Wire Wire Line
	4950 4100 5150 4100
Wire Wire Line
	5150 4100 5150 5000
Wire Wire Line
	5150 5000 5600 5000
Wire Wire Line
	4950 4200 5250 4200
Wire Wire Line
	5250 4200 5250 4700
Wire Wire Line
	5250 4700 5600 4700
Wire Wire Line
	4150 4200 4050 4200
Wire Wire Line
	4050 4200 4050 4800
Wire Wire Line
	4050 4800 5600 4800
Wire Wire Line
	4150 4100 3950 4100
Wire Wire Line
	3950 4100 3950 4900
Wire Wire Line
	3950 4900 5600 4900
Wire Wire Line
	4950 3400 5350 3400
Wire Wire Line
	5350 3400 5350 5200
Wire Wire Line
	5350 5200 5600 5200
Wire Wire Line
	4950 3200 5450 3200
Wire Wire Line
	5450 3200 5450 3500
Wire Wire Line
	5450 5300 5600 5300
$Comp
L Arduino:Joystick U2
U 1 1 5C5F3039
P 5950 2900
F 0 "U2" H 6178 2865 50  0000 L CNN
F 1 "Joystick" H 6178 2774 50  0000 L CNN
F 2 "Retruino:Joystick" H 6250 2600 50  0001 C CNN
F 3 "" H 6250 2600 50  0001 C CNN
	1    5950 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 3400 5800 3400
Wire Wire Line
	5800 3400 5800 3200
Connection ~ 5350 3400
Wire Wire Line
	4950 3800 5900 3800
Wire Wire Line
	5900 3800 5900 3200
Wire Wire Line
	4950 3700 6000 3700
Wire Wire Line
	6000 3700 6000 3200
Wire Wire Line
	5450 3500 6100 3500
Wire Wire Line
	6100 3500 6100 3200
Connection ~ 5450 3500
Wire Wire Line
	5450 3500 5450 5300
$Comp
L Arduino:Charger U4
U 1 1 5C603495
P 2800 3000
F 0 "U4" H 3428 2678 50  0000 L CNN
F 1 "Charger" H 3428 2587 50  0000 L CNN
F 2 "Retruino:Charger" H 3500 2250 50  0001 C CNN
F 3 "" H 3500 2250 50  0001 C CNN
	1    2800 3000
	1    0    0    -1  
$EndComp
$Comp
L Arduino:Buzzer U5
U 1 1 5C603535
P 3500 3800
F 0 "U5" H 3828 3678 50  0000 L CNN
F 1 "Buzzer" H 3828 3587 50  0000 L CNN
F 2 "Retruino:Buzzer" H 3850 3400 50  0001 C CNN
F 3 "" H 3850 3400 50  0001 C CNN
	1    3500 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 2600 4500 2750
Wire Wire Line
	2900 3000 2900 2650
Wire Wire Line
	2900 2650 3800 2650
Wire Wire Line
	4400 2650 4400 2750
Wire Wire Line
	3750 3800 3750 3400
Wire Wire Line
	3750 3400 4150 3400
Wire Wire Line
	3500 3800 3500 3500
Wire Wire Line
	3500 3500 4150 3500
$Comp
L Arduino:Switch U6
U 1 1 5C608FB0
P 3650 2500
F 0 "U6" H 3928 2403 50  0000 L CNN
F 1 "Switch" H 3928 2312 50  0000 L CNN
F 2 "Retruino:Switch" H 4000 2300 50  0001 C CNN
F 3 "" H 4000 2300 50  0001 C CNN
	1    3650 2500
	-1   0    0    1   
$EndComp
Wire Wire Line
	4500 2600 3550 2600
Wire Wire Line
	3550 2600 3550 2500
Wire Wire Line
	2800 3000 2800 2500
Wire Wire Line
	2800 2500 3450 2500
Wire Wire Line
	3300 3000 3300 2750
Wire Wire Line
	3300 2750 3650 2750
Wire Wire Line
	3650 2750 3650 2500
Wire Wire Line
	3200 3000 3200 2950
Wire Wire Line
	3200 2950 3800 2950
Wire Wire Line
	3800 2950 3800 2650
Connection ~ 3800 2650
Wire Wire Line
	3800 2650 4400 2650
$EndSCHEMATC
