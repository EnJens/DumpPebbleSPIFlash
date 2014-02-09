DumpPebbleSPIFlash
==================

Notes
------

This will dump all parts of the 32Mbit (4MB) SPI flash
that is attached to the Pebble on SPI port 1.

It *requires* a firmware with MPU disabled to work.
If this app is run on a firmware with MPU enabled, it
will be killed and return and AppFault.

Since the Pebble Firmware also accesses the SPI flash,
there is some magic (aka hacks) to avoid conflicting with the firmware.
If you have trouble, experiment with lowering the blocksize and/or
increasing the psleep.

Usage
-----

 - The smallest area this can dump is 32 bytes.
 - Edit the memory ranges DUMP_{START,END} in DumpPebSPI.c
 - Edit the blocksize BLOCK_SIZE in DumpPebSPI.c 
 - pebble.py build
 - pebble.py install 
 - pebble.py logs &> dump.txt
 - Now launch the app on your watch

In another shell...:

 - decode_dump.py dump.txt
 - Default offsets dump all of the SPI Flash
 - Expect it to take 20-30 minutes
 - Once it's done, your region will be dumped as dump.txt.bin
