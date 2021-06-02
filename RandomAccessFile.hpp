//
//  RandomAccessFile.hpp
//  RandomAccesLab
//
//  Created by Sione on 13/11/17.
//  Copyright © 2017 FangaiuihaCode. All rights reserved.
//

#ifndef RandomAccessFile_hpp
#define RandomAccessFile_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Student.hpp"

using namespace std;

class RandomAccessFile
{
public:
    RandomAccessFile
    (const std::string& diskFileName, int numberOfRecords);
    void    addRecord
    (Student newStudent);
    void    updateRecord
    (int updateIdNumber, int updateScoreNumber, int newScore);
    void    deleteRecord
    (int idNumberToDelete);
    void    printRecord
    (int retrieveIdNumber);
    void    listRecords
    (void);

private:
    void    sequentialRead
    (Student& s);
    void    sequentialWrite
    (Student  s);
    void    randomRead
    (Student& s, int recordNumber);
    void    randomWrite
    (Student  s, int recordNumber);
private:
    std::string  fileName;
    int          numberRecordsInFile;
    std::fstream diskFile;
};

#endif /* RandomAccessFile_hpp */
