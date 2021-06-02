//
//  RandomAccessFile.cpp
//  RandomAccesLab
//
//  Created by Sione on 13/11/17.
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#include "RandomAccessFile.hpp"

RandomAccessFile::RandomAccessFile (const std::string& diskFileName, int numberOfRecords)
{
    // put name & size parameters in private data
    fileName = diskFileName;
    numberRecordsInFile = numberOfRecords;
    // open disk file for output using "ios::out|ios::binary"
    diskFile.open(fileName, ios::out | ios::binary);
    
    
    Student blank; // object with intentionally "blank" data
    
    for(int studentIndx = 0; studentIndx <= numberOfRecords - 1; studentIndx++)
    {// studentIndx = 0 to numberRecordsInFile-1
        sequentialWrite(blank);
    }
    
    diskFile.close(); // close disk file
    
    return;
}  // end RandomAccessFile::RandomAccessFile

void RandomAccessFile::sequentialWrite (Student s)
{
    diskFile.write (s.getDataRecordLocation(), s.getDataRecordSize());
    return;
}  // end RandomAccessFile::sequentialWrite

void RandomAccessFile::sequentialRead(Student& s)
{
    diskFile.read(s.getDataRecordLocation(), s.getDataRecordSize());
    return;
}

void RandomAccessFile::listRecords (void)
{
    diskFile.open(fileName,ios::in|ios::binary);// open disk file for input using "ios::in|ios::binary"
    cout << "sequential list of file: \n";
    for(int recordNumber = 0; recordNumber <= numberRecordsInFile - 1; recordNumber++)// for recordNumber = 0 to numberRecordsInFile - 1
    {
        Student retrievedStudent;
        sequentialRead (retrievedStudent);
        cout << setw(2) << recordNumber << ' ' << retrievedStudent;
    }  // end for
    cout << endl;  // extra blank line
    // close disk file
    diskFile.close();
    return;
}  // end RandomAccessfile::listRecords

void RandomAccessFile::addRecord (Student newStudent)
{
    diskFile.open(fileName, ios::in | ios::out | ios::binary);// open the disk file for input & output with "ios::in|ios::out|ios::binary"
    diskFile.seekp(newStudent.getIdNumber() * newStudent.getDataRecordSize());
    sequentialWrite(newStudent);
    diskFile.close();// close the disk file
    cout << "added " << newStudent.getIdNumber() << endl << endl;
    return;
}  // end RandomAccessFile::addRecord

void RandomAccessFile::randomWrite (Student s, int recordNumber)
{
    diskFile.seekp(recordNumber * s.getDataRecordSize());
    diskFile.write(s.getDataRecordLocation(), recordNumber);// same write as sequentialWrite
    return;
}  // add randomAccessFile::randomWrite

void RandomAccessFile::printRecord(int retrieveIdNumber)
{
    diskFile.open(fileName,ios::in|ios::binary);
    Student retrievedStudent;
    diskFile.seekg(retrieveIdNumber * retrievedStudent.getDataRecordSize());
    sequentialRead(retrievedStudent);
    cout << retrievedStudent << endl;
    diskFile.close();
}

void RandomAccessFile::updateRecord (int updateIdNumber,int scoreNumber,int newScore)
{
    diskFile.open(fileName,ios::in | ios::out |ios::binary);
    Student retrievedStudent;
    diskFile.seekg(updateIdNumber * retrievedStudent.getDataRecordSize());
    sequentialRead(retrievedStudent);
    retrievedStudent.adjustScore(scoreNumber, newScore);
    diskFile.seekp(updateIdNumber * retrievedStudent.getDataRecordSize());
    sequentialWrite(retrievedStudent);
    diskFile.close();
    cout << "updated " << retrievedStudent.getIdNumber() << endl << endl;
}

