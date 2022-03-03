/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package filelab;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author Brayan
 */
class BadInputException extends Exception {

    String s;

    BadInputException(String s) {
        this.s = s;
    }

    @Override
    public String toString() {
        return s;
    }
}

public class FileLab {

    public static void main(String[] args) throws IOException {
        //variables and object for input
        Scanner in = new Scanner(System.in);
        int choice = 0;
        String newEntry = "";

        //objects for writing and reading
        FileWriter fw;
        FileReader fr;
        BufferedReader br;
        BufferedWriter bw;
        //variable to read in each line
        String read;

        //variable and array to store into an array
        int x = 0;
        String[] names = new String[100];

        do {
            System.out.println("1. Display Data");
            System.out.println("2. Add New Entry");
            System.out.println("3. Edit Entry");
            System.out.println("4. Remove Entry");
            System.out.println("5. Quit");
            System.out.print(">> ");
            choice = in.nextInt();
            in.nextLine();
            System.out.println("");

            try {
                //go through each menu selection
                switch (choice) {
                    case 1:
                        //opening and closing the file in each case
                        fr = new FileReader("names.txt");
                        br = new BufferedReader(fr);
                        x = 0;
                        //looping until end of file
                        System.out.println("Names");
                        while ((read = br.readLine()) != null) {
                            x++;
                            System.out.println(x + ". " + read);
                        }
                        br.close();
                        System.out.println("");
                        break;
                    case 2:
                        //opening and closing the file in each case
                        fw = new FileWriter("names.txt", true);
                        bw = new BufferedWriter(fw);

                        //taking in the new entry to append to the file
                        System.out.print("Enter new entry >> ");
                        newEntry = in.nextLine();

                        //converting entry into a char array to check each character
                        char[] characters = newEntry.toCharArray();
                        for (char c : characters) {
                            //if a character in the string is a digit/number
                            if (Character.isDigit(c)) {
                                //throw the exception
                                throw new BadInputException("Name cannot include numbers");
                            }
                        }

                        //if the exception isn't thrown, validation passed
                        bw.append(newEntry + "\n");
                        bw.close();
                        System.out.println("");
                        break;
                    case 3:
                        //opening and closing the file in each case
                        fr = new FileReader("names.txt");
                        br = new BufferedReader(fr);
                        x = 0;
                        String newName;
                        System.out.println("Names");

                        //copying all the data in the file into the array to edit
                        while ((read = br.readLine()) != null) {
                            names[x] = read;
                            x++;
                            System.out.println(x + ". " + read);
                        }
                        //name that will be changed/edit
                        System.out.print("Choose entry you want to edit>> ");
                        x = in.nextInt();

                        //exceptions for out of bounds and elements without names
                        if (x == 0 || x > 100) {
                            throw new BadInputException("Entry is not allowed");
                        } else if (names[x - 1] == null) {
                            throw new BadInputException("Entry has no name");
                        }
                        //clearing the stream
                        in.nextLine();
                        //displaying the name that will be edited
                        System.out.println("Name you are editing: " + names[x - 1]);
                        System.out.print("New name: ");
                        newName = in.nextLine();
                        char[] characters2 = newName.toCharArray();
                        for (char c : characters2) {
                            //if a character in the string is a digit/number
                            if (Character.isDigit(c)) {
                                //throw the exception
                                throw new BadInputException("Name cannot include numbers");
                            }
                        }
                        //change the old name to the new name at the same position
                        names[x - 1] = newName;
                        br.close();
                        //opening and closing the file to overwrite
                        fw = new FileWriter("names.txt");
                        bw = new BufferedWriter(fw);

                        //looping through the array to overwrite the elements
                        for (int i = 0; i < names.length; i++) {
                            if (names[i] != null) {//array has a size of 100
                                bw.write(names[i] + "\n");//there are null values
                            }
                        }
                        bw.close();
                        System.out.println("");
                        break;
                    case 4:
                        //opening and closing the file in each case
                        fr = new FileReader("names.txt");
                        br = new BufferedReader(fr);
                        x = 0;
                        System.out.println("Names");
                        //copying all the data int the file into the array to edit
                        while ((read = br.readLine()) != null) {
                            names[x] = read;
                            x++;
                            System.out.println(x + ". " + read);
                        }
                        System.out.print("Choose entry you want to remove>> ");
                        x = in.nextInt();

                        if (x == 0 || x > 100) {
                            throw new BadInputException("Entry is not allowed");
                        } else if (names[x - 1] == null) {
                            throw new BadInputException("Entry has no name");
                        }
                        br.close();

                        fw = new FileWriter("names.txt");
                        bw = new BufferedWriter(fw);
                        //using a new array to copy original but without the removed name
                        String[] copy = new String[100];
                        for(int i =0, j=0; i<names.length; i++){
                            if(i!=x-1){
                                copy[j]=names[i];
                                j++;
                            }
                        }
                        
                        //looping through the array to overwrite the elements
                        for (int i = 0; i < names.length; i++) {
                            if (copy[i] != null) {//array has a size of 100
                                bw.write(copy[i] + "\n");//there are null values
                            }
                        }
                        
                        //assigning the old array to the new array
                        //the computer uses names so when a name is removed it needs to use the upated array
                        names = copy;
                        
                        bw.close();
                        break;
                    case 5:
                        System.out.println("Program Exited");
                        break;
                    default:
                        System.out.println("Not a choice");
                        break;
                }

            } catch (BadInputException s) {
                System.out.println(s.toString() + "\n");

            }

        } while (choice != 5);

    }

}
