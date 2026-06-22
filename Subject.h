#include <iostream>

#include "Teacher.h"

#ifndef EDUCATIONAL_INSTITUTION_SUBJECT_H
#define EDUCATIONAL_INSTITUTION_SUBJECT_H

#endif //EDUCATIONAL_INSTITUTION_SUBJECT_H
#pragma once
using namespace std;
struct Subject {
    char name[100];
    char group[100];
    float hours;
    char teacherSurname[200];

    void fillSubject() {
        cin.ignore();

        cout << "Subject name: ";
        cin.getline(name, 100);

        cout << "Group: ";
        cin.getline(group, 100);

        cout << "Hours: ";
        cin >> hours;
        cin.ignore();

        cout << "Teacher surname: ";
        cin.getline(teacherSurname, 100);
    }
    void showSubject() {
        cout << name << " | " << group << " | " << "Hours: " << hours << " | " << "Teacher surname: " << teacherSurname << endl;

    }
};