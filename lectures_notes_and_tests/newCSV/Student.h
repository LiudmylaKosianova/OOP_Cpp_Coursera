#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Student
{
    public:
    int hoursStudy;
    int sleepHours;
    string schoolType;
    string gender;
    int examScore;

    Student(int hoursStudy, int sleepHours, string schoolType, string gender, int examScore);

};