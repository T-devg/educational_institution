#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Teacher.h"
#include "Subject.h"
#include "EducationFunctions.h"
#include "ArrayTemplate.h"
#pragma once
void clearScreen() {
#ifdef _WIN32
   system("cls");
#else
   system("clear");
#endif
}

void menu() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Show teachers\n";
        cout << "2. Show subjects\n";
        cout << "3. Add teacher\n";
        cout << "4. Add subject\n";
        cout << "5. Edit teacher info\n";
        cout << "6. Edit subject info\n";
        cout << "7. Find teacher info\n";
        cout << "8. Find subject info \n";
        cout << "9. Sort teachers by surnames\n";
        cout << "10. Sort all subjects by hours\n";
        cout << "11. Delete teacher info\n";
        cout << "12. Delete subject info\n";
        cout << "13. Delete all teachers info\n";
        cout << "14. Delete all subjects info\n";
        cout << "15.Clear console\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: showTeachers(); break;
            case 2: showSubjects(); break;
            case 3: addTeacher(); break;
            case 4: addSubject(); break;
            case 5: editTeacher(); break;
            case 6: editSubject(); break;
            case 7: findTeacher(); break;
            case 8: findSubject(); break;
            case 9: sortTeachersBySurname(); break;
            case 10: sortSubjectsByHours(); break;
            case 11: deleteTeacher(); break;
            case 12: deleteSubject(); break;
            case 13: deleteAllTeachers(); break;
            case 14: deleteAllSubjects(); break;
            case 15: clearScreen(); break;
            default:
                cout << "Invalid inputz!\n";
                break;

        }} while (choice != 0);
}
using namespace std;

int main() {
    //====================================MENU=====================================
    menu();
}