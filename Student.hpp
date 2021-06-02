//
//  Student.hpp
//  RandomAccesLab
//
//  Created by Sione on 13/11/17.
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

class Student
{
public:
    Student // used for debugging
    (const char* newName, int newIdNumber,
     int score0, int score1, int score2);
    Student // initialized as blank
    (void);
    void        read
    (std::istream& infile);
    void        write
    (std::ostream& outfile) const;
    int         getIdNumber
    (void) const;
    char*       getDataRecordLocation
    (void); // const => compiler error
    int         getDataRecordSize
    (void) const;
    void adjustScore(int scorenum, int newscore);
private:
    char        name [64];
    int         idNumber;
    int         scores [3];
    double      average;
    char        grade;
    void        calculateAverageAndGrade
    (void);
};
std::istream& operator >>
(std::istream& infile, Student& s);
std::ostream& operator <<
(std::ostream& outfile, const Student& s);

#endif /* Student_hpp */
