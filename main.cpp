// Author: Ethan R. Burgess

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// Returns a success check on recieving the colors, pass-by-reference allows for transfering the colors as well.
bool inputColor(string filename, int inputType, vector<int>& color);
//Auxillary, converts for input color
vector<int> hexToRgb(string hex);
// calculates the differences so they may be assigned to the differences vector.
vector<int> absoluteDifference(vector<int> color1, vector<int> color2);

int main() {
    // Initialized to ensure while loop operates atleast once.
    double sensitivity = 2;
    int cbType;
    // Colorblindness type
    int inputType;
    // Dictates if user is using a file with sRGB or Hex values
    bool compatible = false;
    // Indicates that the colors from the file were successfully pulled
    bool fileAccessed = false;
    // File to be accessed
    string filename;
    // vectors for color in format of RRR GGG BBB
    vector<int> color1;
    vector<int> color2;
    // Vector giving absolute difference value for RRR GGG BBB
    vector<int> differences;

    /*
    Commented out for this version of deliverable, I want to eventually convert the sRGB and hex to linear rgb or a measurement that more accurately matches human vision so more meaningful analysis can be done. 
    
    double lr1;
    double lg1;
    double lb1;
    double lr2;
    double lg2;
    double lb2;
    
    */

    // This is setup to have user enter two as I wanted to maintain 1 as a valid input even if it would not be of much valuable, it effectively neccessitates monochrome.
    cout << "Hello, please specify the color blindness sensitivity percentage setting.\nFor more information enter 2\n";
    cin >> sensitivity;

    while (sensitivity >= 1 || sensitivity <= 0) {
        cout << "This setting sets a percentage threshhold for Red, Green, and Blue that will flag a poor visibility warning.\n";
        cout << "Please enter a percent as a decimal, we recommend a minimum of 0.07.\n";
        cin >> sensitivity;
    }

    cout << "Color sensitivity set to " << sensitivity * 100 << "%\n";

    do {
        cout << "What color blindness type are we testing for?\n 1 - Red-Green or Green-Red\n 2 - Blue-Yellow\n";
        cin >> cbType;
    } while (cbType != 1 && cbType != 2);

    do {
        cout << "Now we'll read the colors from files, are the colors in your files written in sRGB or Hex?\n1 - sRGB\n2 - Hex\n";
        cin >> inputType;
    } while (inputType != 1 && inputType != 2);

    if (inputType == 1) {
        cout << "Please confirm that each file contains one color written as RRR GGG BBB before selection\n";
    }
    else {
        cout << "Please confirm that each file contains one color written as 6 hex digits (exclude # and spaces) before selection\n";
    }

    for (int i = 0; i < 2; i++) {
        do {
            if (i == 0) {
                cout << "Input the file name for your first color\n";
                cin >> filename;
                fileAccessed = inputColor(filename, inputType, color1);
            }
            else {
                cout << "Input the file name for your second color\n";
                cin >> filename;
                fileAccessed = inputColor(filename, inputType, color2);
            }

            if (!fileAccessed) {
                cout << "Couldn't read a color from " << filename << ", please try again.\n";
            }
        } while (!fileAccessed);
    }
    cout << "Color one's vector is: ";
    for (int color : color1) {
      cout << color << " ";
    }

    cout << endl;

    cout << "Color two's vector is: ";
    for (int color : color2) {
      cout << color << " ";
    }

    cout << endl;

    // Assigning the values to the differences vector
    differences = absoluteDifference(color1, color2);

    if (cbType == 1) {
        cout << "Inorder to test compatability for Red-Green color-blindness we will only examine the Blue Axis:\n";
        compatible = (differences[2] >= 255 * sensitivity);
    }
    else {
        cout << "Inorder to test compatability for Blue-Yellow color-blindness we will only examine the Red and Green Axes:\n";
        compatible = ((differences[0] + differences[1]) >= 255 * sensitivity);
    }

    if (compatible) {
        cout << "Compatible\n";
    }
    else {
        cout << "Not Compatible\n";
    }

    return 0;
}

//handles inputting of colors through files
bool inputColor(string filename, int inputType, vector<int>& color) {
    int r;
    int g;
    int b;
    bool success = false;
    string hex = "";
    ifstream file;

    file.open(filename);

    if (file.is_open()) {
        if (inputType == 1) {
            file >> r >> g >> b;
            success = !file.fail();

            if (success) {
                color = {r, g, b};
            }
        }
        else {
            file >> hex;
            success = !file.fail();

            if (success) {
                color = hexToRgb(hex);
            }
        }

        file.close();
    }

    return success;
}

//Auxillary function for inputColor designed to convert from hex
vector<int> hexToRgb(string hex) {
    int r = 0;
    int g = 0;
    int b = 0;

    r = stoi(hex.substr(0, 2), 0, 16);
    g = stoi(hex.substr(2, 2), 0, 16);
    b = stoi(hex.substr(4, 2), 0, 16);

    return {r, g, b};
}

//calculates the differences
vector<int> absoluteDifference(vector<int> color1, vector<int> color2) {
    vector<int> difference;

    for (int i = 0; i < 3; i++) {
        if (color1[i] > color2[i]) {
            difference.push_back(color1[i] - color2[i]);
        }
        else {
            difference.push_back(color2[i] - color1[i]);
        }
    }

    return difference;
}