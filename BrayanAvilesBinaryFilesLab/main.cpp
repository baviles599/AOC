/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Brayan
 *
 * Created on July 13, 2021, 11:52 AM
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class Status{
public:
    int x, y;
    float angle;
    unsigned int maxHP, hp;
    bool active;
    Status(){
        
    }
    
};

class Hero:public Status{
public:
    string name;
    Status status;
    Hero(){
        
    }
    void display(){
        cout <<"Name: "<<name<<endl;
        cout <<"Angle: "<<status.angle<<endl;
        cout <<"Max HP: "<<status.maxHP<<endl;
        cout <<"HP: "<<status.hp<<endl;
        cout <<"Active: "<<status.active<<endl;
    }
    
    void load(){
        //code to read in from a binary file
        ifstream in("Hero.dat", ios::in | ios::binary);
        //type cast the contents inside status to char
        in.read((char*)&status, sizeof(Status));
        in.close();
    }
    
    void save(){
        //code to write to a binary file
        ofstream out("Hero.dat", ios::out | ios::binary);
        //type cast the contents inside status to char
        out.write((char*)&status, sizeof(status));
        out.close();
    }
};

int main(int argc, char** argv) {
    Hero hero1;
    
    hero1.status.active = true;
    hero1.status.angle = 12.2;
    hero1.status.hp = 100;
    hero1.status.maxHP = 120;
    hero1.name = "Zam";
    hero1.status.x =1;
    hero1.status.y = 2;
    hero1.display();
    hero1.save();
    cout<<endl;
    Hero hero2;
    hero2.name = "Hold";
    hero2.load();
    hero2.display();
    return 0;
}

