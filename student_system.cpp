#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
};

vector<Student> students;

void addStudent() {
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;
    cout << "Enter name: ";
    cin >> s.name;
    cout << "Enter age: ";
    cin >> s.age;
    cout << "Enter course: ";
    cin >> s.course;

    students.push_back(s);
    cout << "Student added!\n";
}

void showStudents() {
    if (students.size() == 0) {
        cout << "No students yet.\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", Age: " << students[i].age
             << ", Course: " << students[i].course << endl;
    }
}

void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            cout << "Found: " << students[i].name << ", "
                 << students[i].age << ", " << students[i].course << endl;
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add student\n";
        cout << "2. Show all students\n";
        cout << "3. Search student\n";
        cout << "4. Delete student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) showStudents();
        else if (choice == 3) searchStudent();
        else if (choice == 4) deleteStudent();
        else if (choice == 5) cout << "Bye!\n";
        else cout << "Wrong choice, try again.\n";

    } while (choice != 5);

    return 0;
}
