# PandaPi is a software for 3D printer
##  Use Raspberry Pi as a brain that run the Marlin&Octoprint on Raspberry Pi directly. Improve print speed and smoothness
   If you want to run PandaPi on RPi, you need one following extra board that can be droppd in creality Ender3 printer with this board+Raspberry Pi ,just need to print one case for it.

![](https://raw.githubusercontent.com/markniu/PandaPi/master/doc/image/91109225253.jpg)

1. ### High process speed.
 
     If you want to do more higher speed or print some short line or corner the higher process speed is very important,otherwise there will be some slight on the surface. so 32 bit MCU is better,but if you want add more function like web camera,HDMI LCD... little space,for friendly easy to use this PandaPi runs on the powerful Raspberry Pi is the best. 

2. ### Octoprint + marlin.

    the marlin code is very stable and are familiar with us, if we have a good idea or control algorithm, we can change it easily. 
    
3. ### Easy to use

    just wiring & flashing the img. 
    edit/compile/run (use web browser to edit instead of Arduino IDE/platformio)

* ##  FAQ：
1. what's the difference from Klipper

    PandaPi: use RPi to control 3D printer directly,except the temperature control which is just to maintain the temperature.

    Klipper: uses a RPi to parse G-code,map out curves,set accelerations,and then send the motor command to the MCU via uart.

     the obvious difference is that PandaPi control the motor directly.the gpio on the RPi speed being able to signal at 10+ Mhz as compared to 8/32bit MCU limit of about 10Khz/200khz for steps.that is one of my main reason to explore this project. although the <100Khz speed is enough for our FDM printer now.

2. Why is there a mcu?

   RPi has not enough GPIO pin for handle all the motors,hotend,bed,endstop,LCD,auto bed level,run out sensor.

3. how do this assure the real time control?

   about the real-time, I did a [test](https://hackaday.io/project/166466-3dprinter-firmware-run-on-raspberrypi/log/167122-upgrade-to-real-time-linux) . it is not real time actually,but we guarantee motor coordination. and the RPi is more than fast enough that it is not a problem.and I test it with pi4 the cpu speed is quickly than pi3! BTW I test it with all the function like camera octoprint,they are used a lot of RAM but little CPU.

* ##   [Guides](https://github.com/markniu/PandaPi/wiki) 
1. **Quick start guide**：
 
   [Flashing RaspberrPi img](https://github.com/markniu/PandaPi/wiki/How-to-Flash-img-&-WIFI-setup)

   [Wiring](https://github.com/markniu/PandaPi/wiki/How-to-wire)

2. **Advanced topics:**

   [How to Edit Marlin code](https://github.com/markniu/PandaPi/wiki/How-to-Edit-Marlin-code)

   [How to Find Raspberry IP](https://github.com/markniu/PandaPi/wiki/How-to-Find-Raspberry-IP)

   [How to run OctoPrint](https://github.com/markniu/PandaPi/wiki/How-to-run-OctoPrint)


   [where to download board case](https://github.com/markniu/PandaPi/wiki/where-to-download--board-case)

   [How to flash MCU firmware](https://github.com/markniu/PandaPi/wiki/How-to-flash-MCU-firmware)

   [How to wire BLtouch](https://github.com/markniu/PandaPi/wiki/How-to-wire-BLtouch)

* ## Hardware resources v1.0 
RaspberryPi | Pi 4B/3B/3B+  | .
--- | --- | --- 
Extruders | 	1 | 	 
Controlled Fans | 	3	 |  1 board self controlled
Heaters   | 	2	 |  
Endstops   | 	3	 | 
Temp sens   | 	2	 |  100K NTC (thermal resistance)	
SWD   | 	1	 | STlinkV2
Serial port chip   | 	CH340G	 | 
stepper driver   |  4*(TMC2209/TMC2208/A4988/TMC2130)	 | Modular, replaceable,uart for TMC2209 sensorless endstop
Input   | 	9~35V 20A max	 | power both the board and the Raspberry Pi
heater Output   | 	15Amax	 | 
MCU   | 	stm32	 |  
LCD   | 	Graphic128*64/CrealityLCD128*64/HDMI	 | 
on board FAN   | 	silent 24V self auto controlled	 | 
Spacer screw   | 	Nylon spacer screw	 | 
filament detect pin    | 	  reuse the SWD pin   | 	
Bed leveling    | 	  BLtouch  | 	
Protection    | 	 4 autorecovery fuses and isolation components  | 	 on board for over-current and reverse polarity protection for board,drivers,raspberry pi.

* ## Block diagram
![Opensource](https://raw.githubusercontent.com/markniu/PandaPi/master/doc/dlg.png)

* ###   Printing quality


![Opensource](https://raw.githubusercontent.com/markniu/PandaPi/master/doc/image/xyz.jpg)


* ###  Facebook group
<a href="https://www.facebook.com/groups/380795976169477/"><img src="https://raw.githubusercontent.com/markniu/PandaPi/master/doc/Facebook.png" alt="facebook group" width="100" height="100"></a>

 [Tindie store](https://www.tindie.com/products/niujl123/upgrade-your-3d-printer-to-64-bit/)






