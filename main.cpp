//
//  main.cpp
//  RandomAccesLab
//
//  Created by Sione on 13/11/17.
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <string>
#include "Student.hpp"
#include "RandomAccessFile.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    RandomAccessFile studentFile("randomAccessFile", 10);
    
    ifstream infile ("oop11in.txt", ios::in);
    if (! infile)
    {
        cout << "file not found!\n";
        exit (1);
    }
    Student newStudent;  // additions
    int     idNumber;    // prints, updates
    int     scoreNumber; // updates
    int     newScore;    // updates
    
    string option;
    infile >> option;
    while (option != "quit") // quit
    {
        if(option ==  "add") // add
        {
            infile >> newStudent;
            studentFile.addRecord(newStudent);
        }
        else if(option == "print") // print
        {
            infile >> idNumber;
            studentFile.printRecord(idNumber);
        }
        else if(option == "list") // list
        {
            studentFile.listRecords();
        }
        else if (option == "update") // update
        {
            infile >> idNumber >> scoreNumber >> newScore;
            studentFile.updateRecord(idNumber, scoreNumber, newScore);
        }
        else
        {
            cout << option << " is undefined option\n";
        }
        
        infile >> option;
    }  // end while option != quit
    
    infile.close ();
    
    return 0;
}
