// Initial Menu skeleton.

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
    int year;           // 1, 2, 3, or 4
    int current_sem;    // 1 to 8
    float sgpa[8];      // SGPA for up to 8 semesters (0.0 if not completed)
    float cgpa;         // Calculated average of available SGPAs
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void calculateCGPA(Student *s);
void preloadStudents();
void displayMenu();

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
            case 9:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Feature under development.\n");
        }
    }
    return 0;
}