EESchema Schematic File Version 4
EELAYER 29 0
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
L power:GND #PWR04
U 1 1 5CC483AC
P 6050 2400
F 0 "#PWR04" H 6050 2150 50  0001 C CNN
F 1 "GND" H 6055 2227 50  0000 C CNN
F 2 "" H 6050 2400 50  0001 C CNN
F 3 "" H 6050 2400 50  0001 C CNN
	1    6050 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5950 2300 6050 2300
Wire Wire Line
	6050 2300 6050 2400
$Comp
L power:GND #PWR05
U 1 1 5CC48A2D
P 7350 3300
F 0 "#PWR05" H 7350 3050 50  0001 C CNN
F 1 "GND" H 7355 3127 50  0000 C CNN
F 2 "" H 7350 3300 50  0001 C CNN
F 3 "" H 7350 3300 50  0001 C CNN
	1    7350 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 3200 7350 3200
Wire Wire Line
	7350 3200 7350 3300
$Comp
L Connector_Generic:Conn_01x02 J2
U 1 1 5CC47475
P 5750 2300
F 0 "J2" H 6200 2200 50  0000 C CNN
F 1 "Conector Bateria" H 6200 2300 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 5750 2300 50  0001 C CNN
F 3 "~" H 5750 2300 50  0001 C CNN
	1    5750 2300
	-1   0    0    1   
$EndComp
$Comp
L power:+BATT #PWR03
U 1 1 5CC4CB57
P 6050 2050
F 0 "#PWR03" H 6050 1900 50  0001 C CNN
F 1 "+BATT" H 6065 2223 50  0000 C CNN
F 2 "" H 6050 2050 50  0001 C CNN
F 3 "" H 6050 2050 50  0001 C CNN
	1    6050 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 2050 6050 2200
Wire Wire Line
	6050 2200 5950 2200
Wire Wire Line
	4000 4500 3900 4500
Wire Wire Line
	4000 4350 4000 4500
$Comp
L power:+BATT #PWR01
U 1 1 5CC4D1DF
P 4000 4350
F 0 "#PWR01" H 4000 4200 50  0001 C CNN
F 1 "+BATT" H 4015 4523 50  0000 C CNN
F 2 "" H 4000 4350 50  0001 C CNN
F 3 "" H 4000 4350 50  0001 C CNN
	1    4000 4350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 5CC49630
P 3700 4600
F 0 "J1" H 4050 4550 50  0000 C CNN
F 1 "Conector PIR" H 4050 4650 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3700 4600 50  0001 C CNN
F 3 "~" H 3700 4600 50  0001 C CNN
	1    3700 4600
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4000 4700 4000 4850
Wire Wire Line
	3900 4700 4000 4700
$Comp
L power:GND #PWR02
U 1 1 5CC4A9A5
P 4000 4850
F 0 "#PWR02" H 4000 4600 50  0001 C CNN
F 1 "GND" H 4005 4677 50  0000 C CNN
F 2 "" H 4000 4850 50  0001 C CNN
F 3 "" H 4000 4850 50  0001 C CNN
	1    4000 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 4600 3900 4600
$Comp
L Librerias:NodeMCU-32S U?
U 1 1 5CC45E29
P 5800 3750
F 0 "U?" H 5875 4615 50  0000 C CNN
F 1 "NodeMCU-32S" H 5875 4524 50  0000 C CNN
F 2 "" H 5250 3950 50  0001 C CNN
F 3 "" H 5250 3950 50  0001 C CNN
	1    5800 3750
	1    0    0    -1  
$EndComp
$EndSCHEMATC
