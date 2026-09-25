#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
int sr1;
int sg1;
int sb1;
int sr2;
int sg2;
int sb2;
/*
Commented out for initial deliverable, I want to eventually convert the sRGB and hex to linear rgb or a measurement that more accurately matches human vision so more meaningful analysis can be done. 
double lr1;
double lg1;
double lb1;
double lr2;
double lg2;
double lb2;
*/
double sensitivity = 2;
int CBType;
int InputType;
std::string Hex1;
std::string Hex2;

std::cout << "Hello, please specify the color blindness sensitivity percentage setting.\nFor more information enter 2\n";
std::cin >> sensitivity;

while (sensitivity >= 1 || sensitivity <=0) {

    std::cout << "This setting sets a percentage threshhold for Red, Green, and Blue that will flag a poor visibility warning.\n Note for future versions: Traditional sRGB values are not linear and this program attempts to linearize them as part of the algorithm.\n This means values may not directly backflow to differences in RGB.\n";
    std::cout << "Please enter a percent as a decimal, we recommend a minimum of 0.07.\n";
    std::cin  >> sensitivity;
}

std::cout << "Color sensitivity set to " << sensitivity*100 << "%\n";
std::cout << "What color blindness type are we testing for?\n 1 - Red-Green or Green-Red\n 2 - Blue-Yellow\n";
std::cin >> CBType;

std::cout << "Now we'll enter the colors, are we using sRGB or Hex?\n1 - sRGB\n2 - Hex\n";
std::cin >> InputType;

switch (InputType) {
    //sRGB
    case 1: {
        std::cout << "Input your first color's RGB value as follows RR GG BB\n";
        std::cin >> sr1 >> sg1 >> sb1;

        std::cout << "Input your second color's RGB value as follows RR GG BB\n";
        std::cin >> sr2 >> sg2 >> sb2;
    }
        switch (CBType) {
            //sRGB-Red-Green
            case 1:
            std::cout << "Inorder to test compatability for Red-Green color-blindness we will only examine the Blue Axis:\n";
            if (std::abs(sb1-sb2)>=255*sensitivity) {
            std::cout << "Compatible";
            }
            else {
            std::cout << "Not Compatible";
            }
            break;
            //sRGB - Blue-Yellow 
            case 2:
            std::cout << "Inorder to test compatability for Red-Green color-blindness we will only examine the Red and Green Axes:\n";
            if (std::abs(sr1-sr2)>=255*sensitivity || std::abs(sg1-sg2)>=255*sensitivity || (std::abs(sr1-sr2)+std::abs(sg1-sg2))>=255*sensitivity) {
            std::cout << "Compatible";
            }
            else {
            std::cout << "Not Compatible";
            }
            break;
            //sRGB error output
            default:
            std::cout << "Code recognizes you're in RGB but another error occured after that. My apologies";
            break;
}
    break;
    
    //Hex
    case 2: {
    std::cout << "Input your first color's Hex value, 6 digits, exclude #\n";
    std::cin >> Hex1;
    std::string StringR1 = Hex1.substr(0,2);
    std::string StringG1 = Hex1.substr(2,2);
    std::string StringB1 = Hex1.substr(4,2);

//This converrts the string segments into base 16 values
    sr1 = std::stoi(StringR1, 0, 16);
    sg1 = std::stoi(StringG1, 0, 16);
    sb1 = std::stoi(StringB1, 0, 16); 


    std::cout << "Input your second color's Hex value\n";
    std::cin >> Hex2;
    std::string StringR2 = Hex2.substr(0,2);
    std::string StringG2 = Hex2.substr(2,2);
    std::string StringB2 = Hex2.substr(4,2);

    sr2 = std::stoi(StringR2, 0, 16);
    sg2 = std::stoi(StringG2, 0, 16);
    sb2 = std::stoi(StringB2, 0, 16); 

    switch(CBType) {
            //Hex-Red-Green
                case 1:
            std::cout << "Inorder to test compatability for Red-Green color-blindness we will only examine the Blue Axis:\n";
            if (std::abs(sb1-sb2)>=255*sensitivity) {
            std::cout << "Compatible";
            }
            else {
            std::cout << "Not Compatible";
            }
            break;
            //sRGB - Blue-Yellow 
            case 2:
            std::cout << "Inorder to test compatability for Red-Green color-blindness we will only examine the Red and Green Axes:\n";
            if (std::abs(sr1-sr2)>=255*sensitivity || std::abs(sg1-sg2)>=255*sensitivity || (std::abs(sr1-sr2)+std::abs(sg1-sg2))>=255*sensitivity) {
            std::cout << "Compatible";
            }
            else {
            std::cout << "Not Compatible";
            }
            break;
            //hex error output
            default:
            std::cout << "Code recognizes you're in Hex but another error occured after that. My apologies";
            break;            
    }
}
}
    return 0;
}