# Build Guide

This is the logo for the band August Burns Red.  The parts are designed to fit an Adafruit Circuit Playground inside with wires leading through the body to NeoPixel strips on the inside of the flames.  However, it can also be printed and displayed as is without any lighting.  Here's a full description of the build process.

1. Print the base as is (upside down) and the base cover with [eSun PLA Pro Black](https://www.amazon.com/eSUN-1-75mm-Printer-Filament-2-2lbs/dp/B01EKEMDA6/ref=sr_1_1?dchild=1&keywords=esun+pla+pro+black&qid=1592619232&s=industrial&sr=1-1).

2. Print the flame with [eSun PLA Pro Orange](https://www.amazon.com/eSUN-1-75mm-Orange-Printer-Filament/dp/B01EKEMA2M/ref=sxts_sxwds-bia-wc-p13n1_0?cv_ct_cx=esun+pla+pro+orange&dchild=1&keywords=esun+pla+pro+orange&pd_rd_i=B01EKEMA2M&pd_rd_r=f235727d-881f-474d-b4a0-ccaba20a42bb&pd_rd_w=LZsGZ&pd_rd_wg=OOB1j&pf_rd_p=1da5beeb-8f71-435c-b5c5-3279a6171294&pf_rd_r=GV8FYNQ0MHPTW8NV29DV&psc=1&qid=1592618957&sr=1-1-70f7c15d-07d8-466a-b325-4be35d7258cc).

3. Carefully sand the flame and hills of the base using 60/120/240 grit sandpaper (dry) followed by 400/800/1200/1500 grit sandpaper (wet).

4. Super glue the flame to the base.

5. Cut [NeoPixel](https://www.adafruit.com/?q=neopixel%20strip) strips into two sections that fit the flame and solder leads onto each strip.  Feed the wires through the hole at the bottom of the flame and into the base.  If you can't fit all 6 wires through the hole it's safe to open it up a bit with a drill.  I needed to go up between 3.5mm and 4mm.

6. Get a [Circuit Playground Classic](https://www.adafruit.com/product/3000) and solder the 5v leads to the 3.3v pin (this works just fine with legit NeoPixels) and the ground leads to GND.

7. Solder the lead of the data pin from the longest NeoPixel strip to pin 9 and the shorter strip to pin 6.  If you want to change the pins in the code you can do so on lines 10 and 11.

8. Get a [DC barrel jack](https://www.amazon.com/TOTOT-5-5mm-Female-Socket-Electrical/dp/B077YB75N3/ref=sr_1_11?crid=J48RKTBEQFQ7&dchild=1&keywords=dc+barrel+jack&qid=1596396947&sprefix=dc+barrel%2Caps%2C148&sr=8-11) and a [JST jumper](https://www.amazon.com/daier-Micro-2-Pin-Connector-Female/dp/B01DUC1O68/ref=sr_1_2?dchild=1&keywords=jst+jumper&qid=1596397207&sr=8-2).  Solder the JST jumper to the barrel jack and super-glue the barrel jack onto the port on the back of the base.  You'll plug the JST jumper into the Circuit Playground after you mount it in step 10.

9. Upload [this code](https://github.com/sud0nick/ABR-Flame/blob/master/ABR-Flame.ino) to the board.

10. Mount the board inside the base using the 2 screw hole mounts.  2mm screws should fit just fine and it's best to use pins 12 and SCL#3 as mount points.

11. Close up the base, plug it in, and enjoy the lights! Make sure you use a 5v power supply only! The Circuit Playground Classic can only handle up to 6V input so using a USB port from your computer or a 5V rated power supply will be best.