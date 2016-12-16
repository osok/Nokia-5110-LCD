#Library
Library for easy interface to the Nokia 5110 LCD 84 x 48 LCD Screen from Sparkfun.
Could work with others, just not tested.

There are other Librarys out there.  This one is based on the code example on the SparkFun site.
http://playground.arduino.cc/Code/PCD8544.

All I have done is :
* make it into a Library
* add pre-compiler directives to reduce the set of characters (to save code space)


#Install
To download. 
* Click the DOWNLOADS button in the top right corner, rename the uncompressed folder Nokia-LCD. 
* Check that the Nokia-LCD folder contains NokiaLCD.cpp and NokiaLCD.h. 
* Place the Nokia-LCD library folder your /libraries/ folder. 
* You may need to create the libraries subfolder if its your first library. 
* Restart the IDE.



# Where to get one
##Compatible
* Sparkfun :  https://www.sparkfun.com/products/10168

##Should be compatible
* ebay : Buyer beware, the pin outs are not the same and I have not yet figured out how to make 
them work with this library.  If anyone can I have three, so I"m very interested
* AdaFruit : https://www.adafruit.com/product/338


#Example
Alphabet-Screen.ino simply writes A-J to each column and repeats for each row.

There are elements of the example that are further extracted in my SimpleScreen class.  

Hookup Guide: https://learn.sparkfun.com/tutorials/graphic-lcd-hookup-guide

#License
(c) Michael Caughey, 2016

The Library is licensed under a [Creative Commons Attribution 3.0 License](https://creativecommons.org/licenses/by/3.0/). 