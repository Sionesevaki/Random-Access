//
//  Student.cpp
//  RandomAccesLab
//
//  Created by Sione on 13/11/17.
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#include "Student.hpp"

Student::Student(const char* newName, int newIdNumber,int score0, int score1, int score2)
{
    memset(this, 0, sizeof(Student)); // clear memory held by this Student to zero
    
    idNumber = newIdNumber;
    strncpy (name, newName, 63);      // copy in the name (but don't overflow)
    scores[0] = score0;
    scores[1] = score1;
    scores[2] = score2;
    calculateAverageAndGrade ();
    return;
}

Student::Student(void)
{
    strncpy (name, "Blank", 63);
    idNumber = 0;
    scores[0] = 0;
    scores[1] = 0;
    scores[2] = 0;
    average = -1;
    grade = 'X';
}

void Student::calculateAverageAndGrade()
{
    average = (scores[0] + scores[1] + scores[2]) / 3;
    
    if(average > 89.99 && average <= 100.00)
        grade = 'A';
    else if(average > 79.99 && average <= 89.99)
        grade = 'B';
    else if (average > 69.99 && average <= 79.99)
        grade = 'C';
    else if(average > 59.99 && average <= 69.99)
        grade = 'D';
    else
        grade = 'F';
}

void Student::write (ostream& outfile) const
{
    outfile << setw(10) << idNumber << ' '
    << setw(15) << setiosflags(ios::left) << name << resetiosflags(ios::left);
    for(int testIndx = 0; testIndx < 3; testIndx++)
    {//testIndx = 0 to NUMBER_OF_TESTS-1
        outfile << setw (4) << scores[testIndx];
    }
    outfile << setiosflags (ios::fixed|ios::showpoint) << setw (6) << setprecision (2)
    << average << setw(2) << grade << endl;
    return;
}

void Student::read(istream& infile)
{

    infile >> idNumber >> name >> scores[0] >> scores[1] >> scores[2];
    calculateAverageAndGrade ();
    return;
}  // end Student::read

char* Student::getDataRecordLocation(void)
{
    return reinterpret_cast<char*>(this);
}

int Student::getDataRecordSize(void) const
{
    return sizeof(Student);
}

int Student::getIdNumber(void) const
{
    return idNumber;
}

void Student::adjustScore(int scorenum, int newscore)
{
    scores[scorenum-1] = newscore;
    calculateAverageAndGrade();
}

std::ostream& operator << (std::ostream& outfile, const Student& s)
{
    s.write(outfile);
    
    return outfile;
}

std::istream& operator >> (std::istream& infile, Student& s)
{
    s.read(infile);
    return infile;
}
