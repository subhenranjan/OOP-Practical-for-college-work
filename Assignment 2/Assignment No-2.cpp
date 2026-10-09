#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNumber;
    string name;
    string course;
    int admissionYear;

public:
    // Function to input student data
    void inputDetails()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Course: ";
        getline(cin, course);
        cout << "Enter Admission Year: ";
        cin >> admissionYear;
        cout << "---------------------\n";
    }

    // Function to display student data
    void displayDetails() const
    {
        cout << "Roll Number: " << rollNumber << "\n";
        cout << "Name: " << name << "\n";
        cout << "Course: " << course << "\n";
        cout << "Admission Year: " << admissionYear << "\n";
        cout << "---------------------\n";
    }

    // Function to get Roll Number
    int getRollNumber() const
    {
        return rollNumber;
    }
};

int main()
{
    const int MAX_STUDENTS = 100;
    Student database[MAX_STUDENTS]; // Array of Student objects
    int currentCount = 0;
    int choice;

    cout << "=== College Record Digitization System ===\n";
    do
    {
        cout << "\n1. Add New Student Record\n";
        cout << "2. Display All Student Records\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
            if (currentCount < MAX_STUDENTS)
            {
                cout << "--- Enter Details for Student " << currentCount + 1 << " ---\n";
                database[currentCount].inputDetails();
                currentCount++;
                cout << "Record saved successfully!\n";
            }
            else
            {
                cout << "Database full! Cannot add more records.\n";
            }
            break;

        case 2:
            if (currentCount == 0)
            {
                cout << "No student records available.\n";
            }
            else
            {
                cout << "--- Total Student Records ---\n";
                for (int i = 0; i < currentCount; i++)
                {
                    database[i].displayDetails();
                }
            }
            break;

        case 3:
        {
            if (currentCount == 0)
            {
                cout << "No student records available to search.\n";
                break;
            }
            int searchRoll;
            bool found = false;
            cout << "Enter Roll Number to search: ";
            cin >> searchRoll;
            cout << "\n";

            for (int i = 0; i < currentCount; i++)
            {
                if (database[i].getRollNumber() == searchRoll)
                {
                    cout << "--- Record Found ---\n";
                    database[i].displayDetails();
                    found = true;
                    break;
                }
            }

            if (found == false)
            {
                cout << "Student with Roll Number " << searchRoll << " not found.\n";
            }
            break;
        }

        case 4:
            cout << "Exiting system. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Please choose between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}