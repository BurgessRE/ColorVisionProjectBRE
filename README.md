# Color Conversion and Color-Blindness Compatibility Check

## Description

**version 2.0**

The program has been updated to utilize functions rather than nested if and switch statements. This will help future scalability of the program. Additionally the program has been moved towards using files as inputs rather than user command line cin statements.


**version 1.0**

The program takes hex or rgb values and calculates colorblind distinguishable between two colors for red-green, green-red, and blue-yellow sever colorblindness.


## Developer

Ethan R. Burgess

## Example

To run the program, give the following commands:

```
g++ --std=c++11 *.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
Hello, please specify the color blindness sensitivity percentage setting.
For more information enter 2
2 
This setting sets a percentage threshhold for Red, Green, and Blue that will flag a poor visibility warning.
Please enter a percent as a decimal, we recommend a minimum of 0.07.
.07
Color sensitivity set to 7%
What color blindness type are we testing for?
 1 - Red-Green or Green-Red
 2 - Blue-Yellow
1
Now we'll read the colors from files, are the colors in your files written in sRGB or Hex?
1 - sRGB
2 - Hex
1
Please confirm that each file contains one color written as RRR GGG BBB before selection
Input the file name for your first color
lightgray_rgb.txt
Input the file name for your second color
darkgray_rgb.txt
Color one's vector is: 165 165 165 
Color two's vector is: 25 25 25 
Inorder to test compatability for Red-Green color-blindness we will only examine the Blue Axis:
Compatible
```
