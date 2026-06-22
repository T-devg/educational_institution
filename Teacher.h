#ifndef EDUCATIONAL_INSTITUTION_TEACHER_H
#define EDUCATIONAL_INSTITUTION_TEACHER_H

#endif //EDUCATIONAL_INSTITUTION_TEACHER_H
#include <iostream>
#pragma once
using namespace std;
struct Teacher{
    char surname[50];
    char name[50];
    char fatherName[50];
    char specialty[100];
    char status[100];
    unsigned int yearOfBirth;
    char phone[100];

    void fillTeacher() {
        cin.ignore();
        cout << "Name: ";
        cin.getline(name, 50);
        cout << "Surname: ";
        cin.getline(surname, 50);
        cout << "Father name: ";
        cin.getline(fatherName, 50);
        cout << "Specification: ";
        cin.getline(specialty,100);
        cout << "Status: ";
        cin.getline(status,100);
        cout << "Year of Birth: ";
        cin >> yearOfBirth;
        cin.ignore();
        cout << "Telephone: ";
        cin.getline(phone,100);
        cout << endl;
    }
    void showTeacher() {
        cout << name << " " << surname << " " << fatherName << " | " << specialty << " | " << status << " | " << yearOfBirth << " | " << phone << endl;
    }
};