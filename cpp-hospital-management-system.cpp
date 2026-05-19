// Hospital Management System (Upgraded Version)

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Patient {
private:
    int id;
    string name;
    int age;
    string disease;
    string doctor;
    int days;
    float charges;

public:
    void input() {
        cout << "Enter Patient ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Disease: ";
        getline(cin, disease);

        cout << "Enter Doctor Name: ";
        getline(cin, doctor);

        cout << "Enter Days Admitted: ";
        cin >> days;

        cout << "Enter Daily Charges: ";
        cin >> charges;
    }

    float bill() {
        return days * charges;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nDisease: " << disease;
        cout << "\nDoctor: " << doctor;
        cout << "\nDays: " << days;
        cout << "\nBill: " << bill() << endl;
        cout << "--------------------------\n";
    }

    void saveToFile() {
        ofstream file("patients.txt", ios::app);
        file << id << " " << name << " " << age << " "
             << disease << " " << doctor << " "
             << days << " " << charges << endl;
        file.close();
    }
};

Patient p[100];
int countP = 0;

void addPatient() {
    p[countP].input();
    p[countP].saveToFile();
    countP++;
}

void showPatients() {
    for (int i = 0; i < countP; i++) {
        p[i].display();
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Patient\n";
        cout << "2. Show Patients\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) addPatient();
        else if (choice == 2) showPatients();
        else break;
    }

    return 0;
}
