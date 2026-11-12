#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    long sap_id;
    char roll_no[20];
    char name[50];
    char phone[15];
    char email[50];
    int year;
    int current_sem;
    float sgpa[8];
    float cgpa;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void calculateCGPA(Student *s);
void preloadStudents();
void displayMenu();
void printStudentDetails(Student s);
void addStudent();
void searchStudent();
void displayAllStudents();
void deleteStudent();
void averageCGPAByYear();
void sortBySAPID();
void sortByName();

void calculateCGPA(Student *s) {
    float sum = 0.0;
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (s->sgpa[i] > 0.0) {
            sum += s->sgpa[i];
            count++;
        }
    }
    s->cgpa = (count > 0) ? (sum / count) : 0.0;
}

void preloadStudents() {
    Student initial[5] = {
        {590032060, "R214226060", "Abhishek Khanna", "9876543210", "590032060@stu.upes.ac.in", 1, 2, {8.8, 9.1, 0, 0, 0, 0, 0, 0}, 0.0},
        {590032065, "R214226065", "Diya Verma", "9876543211", "590032065@stu.upes.ac.in", 2, 4, {7.5, 7.8, 7.6, 7.9, 0, 0, 0, 0}, 0.0},
        {590032062, "R214226062", "Rohan Gupta", "9876543212", "590032062@stu.upes.ac.in", 3, 6, {6.2, 6.0, 5.8, 6.4, 6.1, 6.3, 0, 0}, 0.0},
        {590032064, "R214226064", "Sneha Nair", "9876543213", "590032064@stu.upes.ac.in", 4, 8, {4.8, 5.0, 4.5, 4.9, 5.1, 4.7, 5.0, 5.2}, 0.0},
        {590032063, "R214226063", "Kabir Singh", "9876543214", "590032063@stu.upes.ac.in", 1, 1, {8.2, 0, 0, 0, 0, 0, 0, 0}, 0.0}
    };

    for (int i = 0; i < 5; i++) {
        calculateCGPA(&initial[i]);
        students[student_count++] = initial[i];
    }
}

void displayMenu() {
    printf("\n====================================================\n");
    printf("   AI-ASSISTED STUDENT RECORD & RESULT MANAGEMENT   \n");
    printf("====================================================\n");
    printf("1. Add Student Record\n");
    printf("2. Search & Display Student Record\n");
    printf("3. Display All Student Records\n");
    printf("4. Delete Student Record\n");
    printf("5. Calculate Average CGPA by Year\n");
    printf("6. Display Records Sorted by SAP ID (Increasing)\n");
    printf("7. Display Records Sorted by Name (Increasing)\n");
    printf("8. AI-Assisted Academic Advisor\n");
    printf("9. Exit\n");
    printf("----------------------------------------------------\n");
    printf("Enter your choice: ");
}

void printStudentDetails(Student s) {
    printf("\n----------------------------------------------------\n");
    printf("SAP ID      : %ld\n", s.sap_id);
    printf("Roll No.    : %s\n", s.roll_no);
    printf("Name        : %s\n", s.name);
    printf("Phone No.   : %s\n", s.phone);
    printf("Email ID    : %s\n", s.email);
    printf("Year / Sem  : Year %d / Semester %d\n", s.year, s.current_sem);
    printf("SGPAs       : ");
    for (int i = 0; i < 8; i++) {
        if (s.sgpa[i] > 0.0) {
            printf("S%d:%.2f ", i + 1, s.sgpa[i]);
        }
    }
    printf("\nCGPA        : %.2f\n", s.cgpa);
    printf("----------------------------------------------------\n");
}

void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("Database full! Cannot add more students.\n");
        return;
    }

    Student s;
    printf("\nEnter SAP ID: ");
    scanf("%ld", &s.sap_id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].sap_id == s.sap_id) {
            printf("Error: A student with SAP ID %ld already exists!\n", s.sap_id);
            return;
        }
    }

    printf("Enter Roll No.: ");
    scanf("%19s", s.roll_no);
    getchar();

    printf("Enter Full Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    printf("Enter Phone No.: ");
    scanf("%14s", s.phone);

    printf("Enter Email ID: ");
    scanf("%49s", s.email);

    printf("Enter Year (1-4): ");
    scanf("%d", &s.year);

    printf("Enter Current Semester (1-8): ");
    scanf("%d", &s.current_sem);

    for (int i = 0; i < 8; i++) {
        if (i < s.current_sem) {
            printf("Enter SGPA for Semester %d: ", i + 1);
            scanf("%f", &s.sgpa[i]);
        } else {
            s.sgpa[i] = 0.0;
        }
    }

    calculateCGPA(&s);
    students[student_count++] = s;
    printf("Student record added successfully! Calculated CGPA: %.2f\n", s.cgpa);
}

void searchStudent() {
    long target_sap;
    printf("\nEnter SAP ID to search: ");
    scanf("%ld", &target_sap);

    for (int i = 0; i < student_count; i++) {
        if (students[i].sap_id == target_sap) {
            printStudentDetails(students[i]);
            return;
        }
    }
    printf("Student with SAP ID %ld not found.\n", target_sap);
}

void displayAllStudents() {
    if (student_count == 0) {
        printf("\nNo student records available.\n");
        return;
    }
    printf("\n=== ALL STUDENT RECORDS (%d) ===\n", student_count);
    for (int i = 0; i < student_count; i++) {
        printStudentDetails(students[i]);
    }
}

void deleteStudent() {
    long target_sap;
    printf("\nEnter SAP ID to delete: ");
    scanf("%ld", &target_sap);

    int found_idx = -1;
    for (int i = 0; i < student_count; i++) {
        if (students[i].sap_id == target_sap) {
            found_idx = i;
            break;
        }
    }

    if (found_idx == -1) {
        printf("Student with SAP ID %ld not found.\n", target_sap);
        return;
    }

    for (int i = found_idx; i < student_count - 1; i++) {
        students[i] = students[i + 1];
    }
    student_count--;
    printf("Student record (SAP ID: %ld) deleted successfully.\n", target_sap);
}

void averageCGPAByYear() {
    float year_sum[5] = {0.0};
    int year_count[5] = {0};

    for (int i = 0; i < student_count; i++) {
        int y = students[i].year;
        if (y >= 1 && y <= 4) {
            year_sum[y] += students[i].cgpa;
            year_count[y]++;
        }
    }

    printf("\n=== YEAR-WISE AVERAGE CGPA ===\n");
    for (int y = 1; y <= 4; y++) {
        if (year_count[y] > 0) {
            printf("Year %d (%d student(s)) : %.2f\n", y, year_count[y], year_sum[y] / year_count[y]);
        } else {
            printf("Year %d (0 students)   : N/A\n", y);
        }
    }
}

// Sorting and YEar wise CGPA functions.

void sortBySAPID() {
    if (student_count == 0) {
        printf("\nNo records to sort.\n");
        return;
    }

    Student temp[MAX_STUDENTS];
    memcpy(temp, students, student_count * sizeof(Student));

    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (temp[j].sap_id > temp[j + 1].sap_id) {
                Student swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    printf("\n=== RECORDS SORTED BY SAP ID (INCREASING) ===\n");
    for (int i = 0; i < student_count; i++) {
        printStudentDetails(temp[i]);
    }
}

void sortByName() {
    if (student_count == 0) {
        printf("\nNo records to sort.\n");
        return;
    }

    Student temp[MAX_STUDENTS];
    memcpy(temp, students, student_count * sizeof(Student));

    for (int i = 0; i < student_count - 1; i++) {
        for (int j = 0; j < student_count - i - 1; j++) {
            if (strcmp(temp[j].name, temp[j + 1].name) > 0) {
                Student swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    printf("\n=== RECORDS SORTED BY NAME (ALPHABETICAL) ===\n");
    for (int i = 0; i < student_count; i++) {
        printStudentDetails(temp[i]);
    }
}

int main() {
    preloadStudents();
    int choice;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number between 1 and 9.\n");
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: searchStudent(); break;
            case 3: displayAllStudents(); break;
            case 4: deleteStudent(); break;
            case 5: averageCGPAByYear(); break;
            case 6: sortBySAPID(); break;
            case 7: sortByName(); break;
            case 9:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Feature under development.\n");
        }
    }
    return 0;
}