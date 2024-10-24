#include "Student.h"

Student::Student(int hoursStudy,
                 int sleepHours, 
                 string schoolType, 
                 string gender, 
                 int examScore)
    :
    hoursStudy(hoursStudy),
    sleepHours(sleepHours),
    schoolType(schoolType),
    gender(gender),
    examScore(examScore)
    {}