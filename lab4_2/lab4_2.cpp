#include <stdio.h>

struct Student {
    char name[50];
    double grade;
};


struct StudentList {
    struct Student students[100]; 
    int count;
};


void addStudent(struct StudentList* list, const char* name, double grade) {
    if (list->count < 100) {
        
        struct Student newStudent;
        snprintf(newStudent.name, sizeof(newStudent.name), "%s", name);
        newStudent.grade = grade;

        list->students[list->count++] = newStudent;
    }
    else {
        printf("Student list is full.\n");
    }
}
struct Student getStudentWithMaxGrade(struct StudentList* list) {
    if (list->count == 0) {
        
        struct Student emptyStudent = { "", 0 };
        return emptyStudent;
    }

    struct Student maxStudent = list->students[0];
    for (int i = 1; i < list->count; ++i) {
        if (list->students[i].grade > maxStudent.grade) {
            maxStudent = list->students[i];
        }
    }

    return maxStudent;
}

int main() {
    
    struct StudentList studentList = { 0 };

    addStudent(&studentList, "Ovidiu", 9.0);
    addStudent(&studentList, "Vlad", 8.5);
    addStudent(&studentList, "Adonis", 9.5);

    struct Student studentWithMaxGrade = getStudentWithMaxGrade(&studentList);

    if (studentWithMaxGrade.grade > 0) {
        printf("The student with the maximum grade is %s with a grade of %2f .\n", studentWithMaxGrade.name, studentWithMaxGrade.grade);
    }
    else {
        printf("No students in the list.\n");
    }

    return 0;
}
