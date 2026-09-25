# Color Conversion and Color-Blindness Compatibility Check

## Description

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
 Note for future versions: Traditional sRGB values are not linear and this program attempts to linearize them as part of the algorithm.
 This means values may not directly backflow to differences in RGB.
Please enter a percent as a decimal, we recommend a minimum of 0.07.
.1
Color sensitivity set to 10%
What color blindness type are we testing for?
 1 - Red-Green or Green-Red
 2 - Blue-Yellow
1
Now we'll enter the colors, are we using sRGB or Hex?
1 - sRGB
2 - Hex
1
Input your first color's RGB value as follows RR GG BB
12 68 48
Input your second color's RGB value as follows RR GG BB
0 112 34
Inorder to test compatability for Red-Green color-blindness we will only examine the Blue Axis:
Not Compatible
```
