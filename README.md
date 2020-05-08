## 64-bit 3D printer controller.                                             
 Run Marlin & Octoprint on Raspberry Pi directly.             ([Where to buy](https://www.pandapi3d.com/))
   
1. ###  better prints at faster speeds
     If you want to do more higher speed or print some short line or corner the higher process speed is very important,otherwise there will be some slight on the surface. so 32 bit MCU is better,but if you want add more function like web camera,HDMI LCD... little space,for friendly easy to use this PandaPi runs on the powerful Raspberry Pi is the best. 
2. ### Octoprint + marlin.
    the marlin code is very stable and are familiar with us, if we have a good idea or control algorithm, we can change it easily.   
3. ### No arduino, no platformIO.
    online compile.
    
<img width="800"  src="https://raw.githubusercontent.com/markniu/doc_test/master/imges/504185717.jpg"/> 

If you want to run PandaPi on RPi, you need one PandaPi extra board that can be droppd in creality Ender3 printer with this board+Raspberry Pi ,just need to print one case for it.

* HDMI LCD，camera,...
<img  width="550"  src="https://raw.githubusercontent.com/markniu/doc_test/master/imges/620.jpg"/>

* ##   [Hardware resources](https://github.com/markniu/PandaPi/wiki/Hardware-resources) 
RaspberryPi | Pi 4B/3B/3B+  | .
--- | --- | --- 
Extruders | 	2 | 	 
Controlled Fans | 	3	 |  FAN0:hotend cooler,it will be opened if the temperature is higher than 60°C.FAN1:model cooler, controlled by the gcode file or gcode command, M106: Set Fan Speed "M106 S255", M107: Fan Off.FAN2:board cooler,If the driver is working, it will be opened.
Heaters   | 	3	 |  
Endstops   | 	3	 | 
Temp sens   | 	3	 |  100K NTC (thermal resistance)	
SWD   | 	1	 | STlinkV2
Serial port chip   | 	CH340G	 | 
stepper driver   |  6*(TMC2209/TMC2208/A4988)	 | Modular, replaceable,uart for TMC2209 sensorless endstop
Input   | 	9~28V 20A max	 | power both the board and the Raspberry Pi
heater Output   | 	15Amax	 | 
MCU   | 	stm32	 |  
LCD   | 	Graphic128*64/CrealityLCD128*64/HDMI	 | 
on board FAN   | 	silent 24V self auto controlled	 | 
Spacer screw   | 	Nylon spacer screw	 | 
filament detect pin    | 	  reuse the SWD pin   | 	
Bed leveling    | 	  BLtouch  | 	support wild range voltage 5V~36V Inductive sensor NPN, since it have optocoupler.
Protection    | 	 4 autorecovery fuses and isolation components  | 	 on board for over-current and reverse polarity protection for board,drivers,raspberry pi.

* ## Block diagram
<img width="450" src="https://raw.githubusercontent.com/markniu/doc_test/master/imges/dlg2.png"/>

* ##   [Guides](https://github.com/markniu/PandaPi/wiki) 
**Quick start guide**：
 
* [Flashing RaspberrPi img](https://github.com/markniu/PandaPi/wiki/How-to-Flash-img-&-WIFI-setup)

* [Wiring](https://github.com/markniu/PandaPi/wiki/How-to-wire)

**Advanced topics:**

* [How to Edit Marlin code](https://github.com/markniu/PandaPi/wiki/How-to-Edit-Marlin-code)

* [How to Find Raspberry IP](https://github.com/markniu/PandaPi/wiki/How-to-Find-Raspberry-IP)

* [How to run OctoPrint](https://github.com/markniu/PandaPi/wiki/How-to-run-OctoPrint)

* [where to download board case](https://github.com/markniu/PandaPi/wiki/where-to-download--board-case)

* [How to flash MCU firmware](https://github.com/markniu/PandaPi/wiki/How-to-flash-MCU-firmware)

* [How to wire BLtouch](https://github.com/markniu/PandaPi/wiki/How-to-wire-BLtouch)

* [How-to-install-desktop(HDMI_LCD)](https://github.com/markniu/PandaPi/wiki/How-to-install-desktop(HDMI_LCD))

* [How-to-run-TMC2209-&-Sensorless-homing](https://github.com/markniu/PandaPi/wiki/How-to-run-TMC2209-&-Sensorless-homing(V2.0))
* [How-to-plugin-OctoPrint-Enclosure](https://github.com/markniu/PandaPi/wiki/How-to-plugin-OctoPrint-Enclosure(DTH11-temperature-humidity-sensor))
* [How-to-use-PID-auto-tune](https://github.com/markniu/PandaPi/wiki/How-to-use-PID-auto-tune)
* [How-to-wiring-filament-runout-sensor](https://github.com/markniu/PandaPi/wiki/How-to-wiring-filament-runout-sensor)
* [How-to-wire-Proximity-sensor](https://github.com/markniu/PandaPi/wiki/How-to-wire-Proximity-sensor)
* [Pins-Map](https://github.com/markniu/PandaPi/wiki/Pins-Map)


* ##  FAQ：
1. what's the difference from Klipper

    PandaPi: use RPi to control 3D printer directly,except the temperature control which is just to maintain the temperature.

    Klipper: uses a RPi to parse G-code,map out curves,set accelerations,and then send the motor command to the MCU via uart.

     the obvious difference is that PandaPi control the motor directly.the gpio on the RPi speed being able to signal at 10+ Mhz as compared to 8/32bit MCU limit of about 10Khz/200khz for steps.that is one of my reason to explore this project. although the <100Khz speed is enough for our FDM printer recently but not the future.

2. Why is there a mcu?

   RPi has not enough GPIO pin for handle all the motors,hotend,bed,endstop,LCD,auto bed level,run out sensor.

3. how do this assure the real time control?

   about the real-time, here is the result that is almost perfect for real time control drivers. the output signal of the one raspberryPI's GPIO,and displayed by the oscilloscope.
<img  width="750"  src="https://raw.githubusercontent.com/markniu/doc_test/master/imges/60632064_o.jpg"/>

## [Join Facebook](https://www.facebook.com/groups/380795976169477/)

## [Where to buy](https://www.pandapi3d.com/)  
thanks for your support! and have fun with 3D printer world!





