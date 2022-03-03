/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Brayan
 *
 * Created on December 1, 2021, 5:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class Day1 {

    void part1() {
        ifstream inFile;
        inFile.open("day1.txt");
        vector<int> numbers;
        int counter = 0;
        int number;

        //storing the numbers from the file into the vector
        while (inFile >> number) {
            numbers.push_back(number);
        }
        for (int i = 0; i < numbers.size(); i++) {

            if (numbers[i + 1] > numbers[i]) {
                counter++;
            }
        }

        cout << "Day 1 Part 1: " << counter << endl;
    }

    void part2() {
        ifstream inFile;
        inFile.open("input.txt");
        vector<int> numbers;
        int counter = 0;
        int number;

        //storing the numbers from the file into the vector
        while (inFile >> number) {
            numbers.push_back(number);
        }
        for (int i = 0; i < numbers.size(); i++) {
            int firstMeasurement = numbers[i] + numbers[i + 1] + numbers[i + 2];
            int secondMeasurement = numbers[i + 1] + numbers[i + 2] + numbers[i + 3];

            if (secondMeasurement > firstMeasurement) {
                counter++;
            }
        }

        cout << "Day 1 Part 2: " << counter << endl;
    }
};

class Day2 {
public:

    void part1() {
        ifstream inFile("day2.txt");
        int depthTotal = 0;
        int horizontalPosition = 0;
        int number;
        string command;

        while (inFile >> command >> number) {
            if (command.compare("forward") == 0) {
                horizontalPosition += number;
            } else if (command.compare("up") == 0) {
                depthTotal -= number;
            } else if (command.compare("down") == 0) {
                depthTotal += number;
            }
        }
        cout << "Day 2 Part 1: " << depthTotal * horizontalPosition << endl;
    }

    void part2() {
        ifstream inFile;
        inFile.open("day2.txt");
        int depthTotal = 0;
        int horizontalPosition = 0;
        int aim = 0;
        int number;
        string command;

        while (inFile >> command >> number) {
            if (command.compare("forward") == 0) {
                horizontalPosition += number;
                depthTotal += number*aim;
            } else if (command.compare("up") == 0) {
                aim -= number;
            } else if (command.compare("down") == 0) {
                aim += number;
            }
        }
        cout << "Day 2 Part 2: " << depthTotal * horizontalPosition << endl;
    }
};

class Day3 {
public:

    void part1() {
        ifstream inFile("day3.txt");
        //final two binary numbers, counters and string to turn append
        int one, zero;
        string gammaBinary, epsilonBinary;

        //variables to store the binaries
        string binaryReader;
        vector<string> binaries;

        //reading in each binary
        while (inFile >> binaryReader) {
            binaries.push_back(binaryReader);
        }
        
       
        //looping 12 times to iterate through each binary 
        for (int j = 0; j < binaries[0].size(); j++) {
            //looping to check each binary number but comparing the specified index in each one
            for (int i = 0; i < binaries.size(); i++) {
                //if the specified index of the binary is one
                if (binaries[i].at(j) == '1') {
                    //increment the one counter
                    one++;
                } else {
                    //else increment the zero counter
                    zero++;
                }
            }

            //if one was found more often
            if (one > zero) {
                //append one to the string
                gammaBinary += "1";
                epsilonBinary += "0";
                one = 0;
                zero = 0;
            } else {
                //else append zero to the string
                gammaBinary += "0";
                epsilonBinary += "1";
                one = 0;
                zero = 0;
            }
        }

        auto intGamma = stoi(gammaBinary, nullptr, 2);
        auto intEpsilon = stoi(epsilonBinary, nullptr, 2);

        cout << "Day 3 Part 1: " << intGamma * intEpsilon << endl;
    }

    /*void part2() {
        ifstream inFile("input.txt");
        //final two binary numbers, counters and string to turn append
        int one, zero;
        string oxygenBinary, carbonBinary;

        //variables to store the binaries
        string binaryReader;
        vector<string> binaries;
        

        //reading in each binary
        while (inFile >> binaryReader) {
            binaries.push_back(binaryReader);
            
        }
        vector<string> oxygenSearch = binaries;
        vector<string> carbonSearch = binaries;
        cout<<oxygenSearch.size();

        /* while (binaries.size() > 1) {
             for (int j = 0; j < 12; j++) {
                 //O2 rating
                 for (int i = 0; i < binaries.size(); i++) {
                     if (binaries[i].at(j) == '1') {
                         one++;
                     } else {
                         zero++;
                     }
                 }
                 //if one was found more often
                 if (one >= zero) {
                     for (int i = 0; i < binaries.size(); i++) {
                         if (binaries[i].at(j) == '0') {
                             binaries.erase(binaries.begin() + i);
                         }
                     }
                     one = 0;
                     zero = 0;

                 } else{
                     for (int i = 0; i < binaries.size(); i++) {
                         if (binaries[i].at(j) == '1') {
                             binaries.erase(binaries.begin() + i);
                         }
                     }
                     one = 0;
                     zero = 0;
                 }

                 if (binaries.size() == 1) {
                     oxygenBinary = binaries[0];
                     break;
                 }
             }

         }

        while (binaries.size() > 1) {
            for (int j = 0; j < binaries[0].size(); j++) {
                // CO2 rating
                for (int i = 0; i < binaries.size(); i++) {
                    if (binaries[i].at(j) == '1') {
                        one++;
                    } else {
                        zero++;
                    }
                }
                //if one was found more often
                if (one >= zero) {
                    for (int i = 0; i < binaries.size(); i++) {
                        if (binaries[i].at(j) == '1') {
                            carbonSearch[i] = binaries[i];
                        }
                    }
                    one = 0;
                    zero = 0;

                } else {
                    for (int i = 0; i < binaries.size(); i++) {
                        if (binaries[i].at(j) == '0') {
                            binaries.erase(binaries.begin() + i);
                        }
                    }
                    one = 0;
                    zero = 0;
                }
                if (carbonSearch.size() == 1) {
                    carbonBinary = carbonSearch[0];
                    break;
                }
            }
        }
        cout << binaries.size() << endl;


        //auto dOxygen = stoi(oxygenBinary, nullptr, 2);
        auto dCarbon = stoi(carbonBinary, nullptr, 2);

        cout << "Day 3 Part 2: " << dCarbon << endl;
        cout << "Day 3 Part 2: " << 303 * 533 << endl;
    }*/

};

int main(int argc, char** argv) {


    //Advent of Code
    Day2 day2;
    day2.part1();
    day2.part2();
   
    return 0;
}

