#ifndef EDUCATIONAL_INSTITUTION_EDUFUNCTIONS_H
#define EDUCATIONAL_INSTITUTION_EDUFUNCTIONS_H
#endif //EDUCATIONAL_INSTITUTION_EDUFUNCTIONS_H
#include "Subject.h"
#include "Teacher.h"
#include "ArrayTemplate.h"
#include <cstdio>
#pragma once
//Main logic
void addTeacher() {
    Teacher teacher;
    teacher.fillTeacher();
    FILE* fileBin = fopen("teachers.bin", "ab");
    if (fileBin == NULL) {
        cout << "Error opening file" << endl;
        return;
    }
    else {
        fwrite(&teacher, sizeof(Teacher), 1, fileBin);
        fclose(fileBin);
    }
}
void showTeachers() {
    FILE* file = fopen("teachers.bin", "rb");
    if (file == NULL) {
        cout << "Error opening file" << endl;
        return;
    }
    else {
            Teacher teacher;
            cout << "\n=== TEACHERS ===\n";
            while (fread(&teacher, sizeof(Teacher), 1, file)) {
                teacher.showTeacher();
            }
            fclose(file);
        }
    }

void addSubject() {
    Subject subject;
    subject.fillSubject();

    FILE* fileBin = fopen("subjects.bin", "ab");
    if (fileBin == NULL) {
        cout << "Error opening file" << endl;
        return;
    }
    fwrite(&subject, sizeof(Subject), 1, fileBin);
    fclose(fileBin);
}
void showSubjects() {
    FILE* file = fopen("subjects.bin", "rb");
    if (file == NULL) {
        cout << "Error opening file" << endl;
        return;
    }
    else {
        Subject subject;
        cout << "\n=== SUBJECTS ===\n";
        while (fread(&subject, sizeof(Subject), 1, file)) {
            subject.showSubject();
        }
        fclose(file);
    }
}
// ================= SEARCH =================

void findTeacher() {
    char surname[100];
    cin.ignore();
    cout << "Enter teacher surname: ";
    cin.getline(surname, 100);
    FILE* file = fopen("teachers.bin", "rb");
    if (!file) return;
    Teacher teacher;
    bool found = false;
    while (fread(&teacher, sizeof(Teacher), 1, file)) {
        if (strcmp(teacher.surname, surname) == 0) {
            teacher.showTeacher();
            found = true;
        }
    }
    if (!found)
        cout << "Teacher not found\n";
    fclose(file);
}


void findSubject() {
    char name[100];
    cin.ignore();
    cout << "Enter subject name: ";
    cin.getline(name, 100);
    FILE* f = fopen("subjects.bin", "rb");
    if (!f) return;
    Subject subject;
    bool found = false;
    cout << "\nSubjects:\n";
    while (fread(&subject, sizeof(Subject), 1, f)) {
        if (strcmp(subject.name, name) == 0) {
            subject.showSubject();
            found = true;
        }
    }
    if (!found)
        cout << "No subject info was found!\n";
    fclose(f);
}

void deleteTeacher() {
    char surname[100];
    cin.ignore();
    cout << "Enter teacher surname: ";
    cin.getline(surname, 100);
    FILE* file = fopen("teachers.bin", "rb");
    FILE* temp = fopen("temp.bin", "wb");
    if (!file || !temp) {
        cout << "Error opening file\n";
        return;
    }
    Teacher teacher;
    bool found = false;
    while (fread(&teacher, sizeof(Teacher), 1, file)) {
        if (strcmp(teacher.surname, surname) != 0) {
            fwrite(&teacher, sizeof(Teacher), 1, temp);
        }
        else {
            found = true;
        }
    }

    fclose(file);
    fclose(temp);
    remove("teachers.bin"); //видаляє файл
    rename("temp.bin", "teachers.bin"); //змінює назву
    if (found)
        cout << "Teacher deleted\n";
    else
        cout << "Teacher not found\n";
    }

void deleteSubject() {
    char subjectName[100];
    cin.ignore();
    cout << "Enter subject name: ";
    cin.getline(subjectName, 100);
    FILE* file = fopen("subjects.bin", "rb");
    FILE* temp = fopen("temp.bin", "wb");
    if (!file || !temp) {
        cout << "Error opening file\n";
        return;
    }
    Subject subject;
    bool found = false;
    while (fread(&subject, sizeof(Subject), 1, file)) {
        if (strcmp(subject.name, subjectName) != 0) {
            fwrite(&subject, sizeof(Subject), 1, temp);
        }
        else {
            found = true;
        }
    }

    fclose(file);
    fclose(temp);
    remove("subjects.bin");
    rename("temp.bin", "subjects.bin");
    if (found)
        cout << "Subject deleted\n";
    else
        cout << "Subject not found\n";

    }
void deleteAllTeachers() {
    FILE* file = fopen("teachers.bin", "wb");
    if (!file) {
        cout << "Error opening file\n";
        return;
    }
    fclose(file);
    cout << "All teachers deleted\n";
    }
void deleteAllSubjects() {
    FILE* file = fopen("subjects.bin", "wb");
    if (!file) {
        cout << "Error opening file\n";
        return;
    }
    fclose(file);
    cout << "All subjects deleted\n";
    }
//////////
///
/// Sorting
void sortSubjectsByHours() {
    FILE* file = fopen("subjects.bin", "rb");
    if (!file) {
        cout << "Error opening file\n";
        return;
    }
    Subject subjects[100];
    int count = 0;
    while (fread(&subjects[count], sizeof(Subject), 1, file))
        count++;
    fclose(file);
    // for (int i = 0; i < count - 1; i++) {
    //     for (int j = 0; j < count - i - 1; j++) {   //Бульбашкове сортування
    //
    //         if (subjects[j].hours < subjects[j + 1].hours) {
    //             Subject temp = subjects[j];
    //             subjects[j] = subjects[j + 1];
    //             subjects[j + 1] = temp;
    //         }
    //     }
    // }
    mySort(subjects, count, [](Subject a, Subject b) {return a.hours < b.hours;} );
    file = fopen("subjects.bin", "wb");
    if (!file) {
        cout << "Error opening file\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        fwrite(&subjects[i], sizeof(Subject), 1, file);
    }
    fclose(file);
    cout << "Subjects sorted by hours\n";
    }

void sortTeachersBySurname() {
    FILE* file = fopen("teachers.bin", "rb");
    if (!file) {
        cout << "Error opening file\n";
        return;
    }
    Teacher teachers[100];
    int count = 0;
    while (fread(&teachers[count], sizeof(Teacher), 1, file))
        count++;
    fclose(file);

    // for (int i = 0; i < count - 1; i++) {
    //     for (int j = 0; j < count - i - 1; j++) {
    //
    //         if (strcmp(teachers[j].surname,
    //                    teachers[j + 1].surname) > 0) {
    //
    //             Teacher temp = teachers[j];
    //             teachers[j] = teachers[j + 1];
    //             teachers[j + 1] = temp;
    //                    }
    //     }
    // }
    mySort(teachers, count, [](Teacher a, Teacher b) {return strcmp(a.surname, b.surname) > 0;} );
    file = fopen("teachers.bin", "wb");
    for (int i = 0; i < count; i++)
        fwrite(&teachers[i], sizeof(Teacher), 1, file);
    fclose(file);
    cout << "Teachers sorted by surname\n";
    }

//
///Edit
///
void editTeacher() {
    char surname[100];
    cin.ignore();
    cout << "Enter teacher surname: ";
    cin.getline(surname, 100);
    FILE* file = fopen("teachers.bin", "rb");
    FILE* temp = fopen("temp.bin", "wb");
    if (!file || !temp) {
        cout << "Error opening file\n";
        return;
    }
    Teacher teacher;
    bool found = false;
    while (fread(&teacher, sizeof(Teacher), 1, file)) {
        if (strcmp(teacher.surname, surname) == 0) {
            cout << "\nCurrent information:\n";
            teacher.showTeacher();
            cout << "\nEnter new information:\n";
            teacher.fillTeacher();
            found = true;
        }

        fwrite(&teacher, sizeof(Teacher), 1, temp);
    }
    fclose(file);
    fclose(temp);
    remove("teachers.bin");
    rename("temp.bin", "teachers.bin");
    if (found)
        cout << "Teacher updated\n";
    else
        cout << "Teacher not found\n";
    }
void editSubject() {
    char name[100];
    cin.ignore();
    cout << "Enter subject name: ";
    cin.getline(name, 100);
    FILE* file = fopen("subjects.bin", "rb");
    FILE* temp = fopen("temp.bin", "wb");
    if (!file || !temp) {
        cout << "Error opening file\n";
        return;
    }
    Subject subject;
    bool found = false;
    while (fread(&subject, sizeof(Subject), 1, file)) {

        if (strcmp(subject.name, name) == 0) {
            cout << "\nCurrent information:\n";
            subject.showSubject();

            cout << "\nEnter new information:\n";
            subject.fillSubject();

            found = true;
        }
        fwrite(&subject, sizeof(Subject), 1, temp);
    }
    fclose(file);
    fclose(temp);
    remove("subjects.bin");
    rename("temp.bin", "subjects.bin");
    if (found)
        cout << "Subject updated\n";
    else
        cout << "Subject not found\n";
    }
