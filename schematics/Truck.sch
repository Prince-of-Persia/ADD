EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 6
Title "E-004-Truck"
Date "2020-04-06"
Rev "0"
Comp ""
Comment1 "Initial Design"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Driver_Motor:L298P U?
U 1 1 5E9B3211
P 2400 2750
AR Path="/5E8A288E/5E9B3211" Ref="U?"  Part="1" 
AR Path="/5E8A3142/5E9B3211" Ref="U3"  Part="1" 
F 0 "U3" H 2400 2800 50  0000 C CNN
F 1 "L298P" H 2400 2700 50  0000 C CNN
F 2 "" H 2550 3000 50  0001 C CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00000240.pdf" H 2550 3000 50  0001 C CNN
	1    2400 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 2050 2400 1800
$Comp
L power:+12V #PWR?
U 1 1 5E9B3218
P 2400 1800
AR Path="/5E8A288E/5E9B3218" Ref="#PWR?"  Part="1" 
AR Path="/5E8A3142/5E9B3218" Ref="#PWR046"  Part="1" 
F 0 "#PWR046" H 2400 1650 50  0001 C CNN
F 1 "+12V" H 2415 1973 50  0000 C CNN
F 2 "" H 2400 1800 50  0001 C CNN
F 3 "" H 2400 1800 50  0001 C CNN
	1    2400 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 3450 2400 3650
$Comp
L power:GND #PWR?
U 1 1 5E9B321F
P 2400 3650
AR Path="/5E8A288E/5E9B321F" Ref="#PWR?"  Part="1" 
AR Path="/5E8A3142/5E9B321F" Ref="#PWR047"  Part="1" 
F 0 "#PWR047" H 2400 3400 50  0001 C CNN
F 1 "GND" H 2405 3477 50  0000 C CNN
F 2 "" H 2400 3650 50  0001 C CNN
F 3 "" H 2400 3650 50  0001 C CNN
	1    2400 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3000 2850 3300 2850
Wire Wire Line
	3000 2950 3300 2950
Text HLabel 1500 2650 0    50   Input ~ 0
L298P_IN3
Text HLabel 1500 2750 0    50   Input ~ 0
L298P_IN4
Text HLabel 1500 2850 0    50   Input ~ 0
L298P_EnB
Wire Wire Line
	1800 2650 1500 2650
Wire Wire Line
	1500 2750 1800 2750
Wire Wire Line
	1800 2850 1500 2850
Text Notes 1900 2050 0    50   ~ 0
Note 1, 2
$Comp
L Connector_Generic:Conn_01x02 J10
U 1 1 5E9B3894
P 3500 2850
F 0 "J10" H 3580 2842 50  0000 L CNN
F 1 "DC Motor" H 3580 2751 50  0000 L CNN
F 2 "" H 3500 2850 50  0001 C CNN
F 3 "~" H 3500 2850 50  0001 C CNN
	1    3500 2850
	1    0    0    -1  
$EndComp
Text Notes 8900 1600 0    50   ~ 0
Genaral Notes:\n1. L289P DC Driver shield capable of driving two \nDC motors. Motor A is used for the crane and \nmotor B is used for the truck, refer to E-002\n\n2. Confirm final connections based on the model\nand data sheet\n\n3. The resistor value of the resistor in series with\nthe limit switch must be varified based on the \nrelevant datasheet
$Comp
L power:GND #PWR?
U 1 1 5E9B5B60
P 1600 1300
AR Path="/5E93AA9C/5E9B5B60" Ref="#PWR?"  Part="1" 
AR Path="/5E8A288E/5E9B5B60" Ref="#PWR?"  Part="1" 
AR Path="/5E8A3142/5E9B5B60" Ref="#PWR045"  Part="1" 
F 0 "#PWR045" H 1600 1050 50  0001 C CNN
F 1 "GND" V 1600 1100 50  0000 C CNN
F 2 "" H 1600 1300 50  0001 C CNN
F 3 "" H 1600 1300 50  0001 C CNN
	1    1600 1300
	0    -1   -1   0   
$EndComp
Text HLabel 1350 1300 0    50   Input ~ 0
GND
Wire Wire Line
	1350 1300 1600 1300
$Comp
L power:+12V #PWR?
U 1 1 5E9B5B6A
P 1600 850
AR Path="/5E8A288E/5E9B5B6A" Ref="#PWR?"  Part="1" 
AR Path="/5E8A3142/5E9B5B6A" Ref="#PWR043"  Part="1" 
F 0 "#PWR043" H 1600 700 50  0001 C CNN
F 1 "+12V" V 1615 978 50  0000 L CNN
F 2 "" H 1600 850 50  0001 C CNN
F 3 "" H 1600 850 50  0001 C CNN
	1    1600 850 
	0    1    1    0   
$EndComp
Text HLabel 1350 850  0    50   Input ~ 0
+12V
Wire Wire Line
	1350 850  1600 850 
$Comp
L Connector_Generic:Conn_01x03 J?
U 1 1 5E8CE3B4
P 8550 2850
AR Path="/5E93AA9C/5E8CE3B4" Ref="J?"  Part="1" 
AR Path="/5E8A288E/5E8CE3B4" Ref="J?"  Part="1" 
AR Path="/5E8A3142/5E8CE3B4" Ref="J11"  Part="1" 
F 0 "J11" H 8630 2892 50  0000 L CNN
F 1 "Force Sensing Resistor" H 8630 2801 50  0000 L CNN
F 2 "" H 8550 2850 50  0001 C CNN
F 3 "~" H 8550 2850 50  0001 C CNN
	1    8550 2850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E8CE3BA
P 8250 3150
AR Path="/5E93AA9C/5E8CE3BA" Ref="#PWR?"  Part="1" 
AR Path="/5E8A288E/5E8CE3BA" Ref="#PWR?"  Part="1" 
AR Path="/5E8A3142/5E8CE3BA" Ref="#PWR053"  Part="1" 
F 0 "#PWR053" H 8250 2900 50  0001 C CNN
F 1 "GND" H 8255 2977 50  0000 C CNN
F 2 "" H 8250 3150 50  0001 C CNN
F 3 "" H 8250 3150 50  0001 C CNN
	1    8250 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 2950 8250 2950
Wire Wire Line
	8250 2950 8250 3150
Wire Wire Line
	8350 2850 8050 2850
Text HLabel 8050 2850 0    50   Input ~ 0
FSR
$Comp
L power:+5V #PWR?
U 1 1 5E8CE3C4
P 8250 2600
AR Path="/5E93AA9C/5E8CE3C4" Ref="#PWR?"  Part="1" 
AR Path="/5E8A288E/5E8CE3C4" Ref="#PWR?"  Part="1" 
AR Path="/5E8A3142/5E8CE3C4" Ref="#PWR052"  Part="1" 
F 0 "#PWR052" H 8250 2450 50  0001 C CNN
F 1 "+5V" H 8265 2773 50  0000 C CNN
F 2 "" H 8250 2600 50  0001 C CNN
F 3 "" H 8250 2600 50  0001 C CNN
	1    8250 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 2600 8250 2750
Wire Wire Line
	8250 2750 8350 2750
$Comp
L power:+5V #PWR?
U 1 1 5E8CE3CC
P 4850 2200
AR Path="/5E8A288E/5E8CE3CC" Ref="#PWR?"  Part="1" 
AR Path="/5E8A3142/5E8CE3CC" Ref="#PWR048"  Part="1" 
F 0 "#PWR048" H 4850 2050 50  0001 C CNN
F 1 "+5V" H 4865 2373 50  0000 C CNN
F 2 "" H 4850 2200 50  0001 C CNN
F 3 "" H 4850 2200 50  0001 C CNN
	1    4850 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E8CE3D2
P 4850 2550
AR Path="/5E8A288E/5E8CE3D2" Ref="R?"  Part="1" 
AR Path="/5E8A3142/5E8CE3D2" Ref="R4"  Part="1" 
F 0 "R4" H 4920 2596 50  0000 L CNN
F 1 "10k" H 4920 2505 50  0000 L CNN
F 2 "" V 4780 2550 50  0001 C CNN
F 3 "~" H 4850 2550 50  0001 C CNN
	1    4850 2550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5E8CE3D8
P 4850 3250
AR Path="/5E8A288E/5E8CE3D8" Ref="SW?"  Part="1" 
AR Path="/5E8A3142/5E8CE3D8" Ref="SW4"  Part="1" 
F 0 "SW4" V 4804 3398 50  0000 L CNN
F 1 "Limit Switch" V 4895 3398 50  0000 L CNN
F 2 "" H 4850 3450 50  0001 C CNN
F 3 "~" H 4850 3450 50  0001 C CNN
	1    4850 3250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E8CE3DE
P 4850 3600
AR Path="/5E8A288E/5E8CE3DE" Ref="#PWR?"  Part="1" 
AR Path="/5E8A3142/5E8CE3DE" Ref="#PWR049"  Part="1" 
F 0 "#PWR049" H 4850 3350 50  0001 C CNN
F 1 "GND" H 4855 3427 50  0000 C CNN
F 2 "" H 4850 3600 50  0001 C CNN
F 3 "" H 4850 3600 50  0001 C CNN
	1    4850 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 2200 4850 2400
Wire Wire Line
	4850 2700 4850 2900
Wire Wire Line
	4850 3450 4850 3600
Connection ~ 4850 2900
Wire Wire Line
	4850 2900 4850 3050
Wire Wire Line
	4850 2900 5150 2900
Text HLabel 5150 2900 2    50   Input ~ 0
LimitSwitch4
$Comp
L power:+5V #PWR?
U 1 1 5E8CE3EB
P 6050 2200
AR Path="/5E8A288E/5E8CE3EB" Ref="#PWR?"  Part="1" 
AR Path="/5E8A3142/5E8CE3EB" Ref="#PWR050"  Part="1" 
F 0 "#PWR050" H 6050 2050 50  0001 C CNN
F 1 "+5V" H 6065 2373 50  0000 C CNN
F 2 "" H 6050 2200 50  0001 C CNN
F 3 "" H 6050 2200 50  0001 C CNN
	1    6050 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E8CE3F1
P 6050 2550
AR Path="/5E8A288E/5E8CE3F1" Ref="R?"  Part="1" 
AR Path="/5E8A3142/5E8CE3F1" Ref="R5"  Part="1" 
F 0 "R5" H 6120 2596 50  0000 L CNN
F 1 "10k" H 6120 2505 50  0000 L CNN
F 2 "" V 5980 2550 50  0001 C CNN
F 3 "~" H 6050 2550 50  0001 C CNN
	1    6050 2550
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW?
U 1 1 5E8CE3F7
P 6050 3250
AR Path="/5E8A288E/5E8CE3F7" Ref="SW?"  Part="1" 
AR Path="/5E8A3142/5E8CE3F7" Ref="SW5"  Part="1" 
F 0 "SW5" V 6004 3398 50  0000 L CNN
F 1 "Limit Switch" V 6095 3398 50  0000 L CNN
F 2 "" H 6050 3450 50  0001 C CNN
F 3 "~" H 6050 3450 50  0001 C CNN
	1    6050 3250
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E8CE3FD
P 6050 3600
AR Path="/5E8A288E/5E8CE3FD" Ref="#PWR?"  Part="1" 
AR Path="/5E8A3142/5E8CE3FD" Ref="#PWR051"  Part="1" 
F 0 "#PWR051" H 6050 3350 50  0001 C CNN
F 1 "GND" H 6055 3427 50  0000 C CNN
F 2 "" H 6050 3600 50  0001 C CNN
F 3 "" H 6050 3600 50  0001 C CNN
	1    6050 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 2200 6050 2400
Wire Wire Line
	6050 2700 6050 2900
Wire Wire Line
	6050 3450 6050 3600
Connection ~ 6050 2900
Wire Wire Line
	6050 2900 6050 3050
Wire Wire Line
	6050 2900 6350 2900
Text HLabel 6350 2900 2    50   Input ~ 0
LimitSwitch5
Text Notes 4750 2700 1    50   ~ 0
Note 3
Text Notes 5950 2700 1    50   ~ 0
Note 3
$Comp
L power:+5V #PWR?
U 1 1 5E8F1494
P 1600 1100
AR Path="/5E93AA9C/5E8F1494" Ref="#PWR?"  Part="1" 
AR Path="/5E8A3142/5E8F1494" Ref="#PWR044"  Part="1" 
F 0 "#PWR044" H 1600 950 50  0001 C CNN
F 1 "+5V" V 1600 1300 50  0000 C CNN
F 2 "" H 1600 1100 50  0001 C CNN
F 3 "" H 1600 1100 50  0001 C CNN
	1    1600 1100
	0    1    1    0   
$EndComp
Text HLabel 1350 1100 0    50   Input ~ 0
+5V
Wire Wire Line
	1350 1100 1600 1100
$EndSCHEMATC
