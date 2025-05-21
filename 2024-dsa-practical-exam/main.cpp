/*
    Create a simple Hospital Management System using Linked Lists. Focus on using the defined linkedList.
*/

#include <iostream>
#include <string>
#include <regex>
#include <ctime>

using namespace std;

/*
    Patient class with patientId INT, name STRING, dob STRING, gender STRING
*/
class Patient
{
public:
    int patientId;
    string name;
    string dob;
    string gender;

    Patient(int patientId, string name, string dob, string gender) : patientId(patientId), name(name), dob(dob), gender(gender) {}
};

/*
    Doctor class with doctorId INT, name STRING, specialization STRING
*/
class Doctor
{
public:
    int doctorId;
    string name;
    string specialization;

    Doctor(int doctorId, string name, string specialization) : doctorId(doctorId), name(name), specialization(specialization) {}
};

/*
    Appointment class with appointmentId INT, patientId INT, doctorId INT, date STRING
*/

class Appointment
{
public:
    int appointmentId;
    int patientId;
    int doctorId;
    string appointmentDate;

    Appointment(int appointmentId, int patientId, int doctorId, string date) : appointmentId(appointmentId), patientId(patientId), doctorId(doctorId), appointmentDate(date) {}
};

/*
    PatientsLL class with Node struct inside it
    Node struct has Patient object and next pointer
    PatientsLL has head pointer
*/

class PatientsLL
{
public:
    struct Node
    {
        Patient patient;
        Node *next;
        Node(Patient patient) : patient(patient), next(nullptr) {}
    };

    Node *head;

    PatientsLL() : head(nullptr) {}

    /*
        addPatient method to add a new patient to the linked list & Verify if the patient already exists
    */

    void addPatient(int patientId, string name, string dob, string gender)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->patient.patientId == patientId)
            {
                cout << "! ------------------- Patient with ID " << patientId << " already exists. Use (1) --------------------- !" << endl;
                return;
            }
            temp = temp->next;
        }

        Patient patient(patientId, name, dob, gender);
        Node *newNode = new Node(patient);

        // Check if the linkedlist is empty, then adds the head as the first node
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            // If the linkedlist is not empty, then add the new node to the end of the patient list as the last node
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "! ------------------ Patient with ID " << patientId << " has been added successfully. ----------------------- !" << endl;
    }

    /*
        displayAllActivePatients method to display all the patients in the linked list
    */
    void displayAllActivePatients()
    {
        if (head == nullptr)
        {
            cout << "! --------------- No Patients available. Please add a patient first. Use (1) ------------------- !" << endl;
            return;
        }
        Node *temp = head;
        cout << " * ---------------- * ------------------ * ----------------- * ----------------- *" << endl;
        while (temp != nullptr)
        {
            cout << "    Patient ID: " << temp->patient.patientId << "  ,  " << " Name: " << temp->patient.name << " ,  " << " DOB: " << temp->patient.dob << " , " << "GENDER: " << temp->patient.gender << endl;
            temp = temp->next;
        }
        cout << " * ---------------- * ------------------ * ----------------- * ----------------- *" << endl;
    }
};

/*
    DoctorsLL class with Node struct inside it
    Node struct has Doctor object and next pointer
    DoctorsLL has head pointer
*/

class DoctorsLL
{
public:
    struct Node
    {
        Doctor doctor;
        Node *next;
        Node(Doctor doctor) : doctor(doctor), next(nullptr) {}
    };

    Node *head;

    // Constructor to initialize the head pointer
    DoctorsLL() : head(nullptr) {}

    void addDoctor(int doctorId, string name, string specialization)
    {
        // Check if doctor with the given ID already exists
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->doctor.doctorId == doctorId)
            {
                cout << "! ---------------- Doctor with ID " << doctorId << " already exists. Use (2) ------------- !" << endl;
                return;
            }
            temp = temp->next;
        }

        Doctor doctor(doctorId, name, specialization);
        Node *newNode = new Node(doctor);

        // Check if the linkedlist is empty, then adds the head as the first node
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            // If the linkedlist is not empty, then add the new node to the end of the doctor list as the last node
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "! ------------------ Doctor with ID " << doctorId << " has been added successfully. ----------------------- !" << endl;
    }

    void displayActiveDoctors()
    {
        // Check if the linkedlist is empty
        if (head == nullptr)
        {
            cout << "! --------------- No Doctors available. Please add a doctor first. Use (2) ------------------ !" << endl;
            return;
        }

        Node *temp = head;
        cout << " * ---------------- * ------------------ * ----------------- *" << endl;
        while (temp != nullptr)
        {
            cout << "    Doctor ID: " << temp->doctor.doctorId << "  , " << " Name: " << temp->doctor.name << "  ,  " << " Specialization: " << temp->doctor.specialization << endl;
            temp = temp->next;
        }
        cout << " * ---------------- * ------------------ * ----------------- *" << endl;
    }
};

/*
    AppointmentsLL class with Node struct inside it
    Node struct has Appointment object and next pointer
    AppointmentsLL has head pointer
*/

class AppointmentsLL
{
public:
    struct Node
    {
        Appointment appointment;
        Node *next;
        Node(Appointment appointment) : appointment(appointment), next(nullptr) {}
    };

    Node *head;
    PatientsLL &patientsLL;
    DoctorsLL &doctorsLL;

    // Constructor to initialize the head pointer, PatientsLL and DoctorsLL objects as references
    AppointmentsLL(PatientsLL &patientsLL, DoctorsLL &doctorsLL) : head(nullptr), patientsLL(patientsLL), doctorsLL(doctorsLL) {}

    // Method to check if the patient with the given ID exists
    bool isPatientExists(int patientId)
    {
        PatientsLL::Node *tempPatient = patientsLL.head;
        // Loop through the patients linked list to check if the patient with the given ID exists, if it exists return true
        while (tempPatient != nullptr)
        {
            if (tempPatient->patient.patientId == patientId)
            {
                return true;
            }
            tempPatient = tempPatient->next;
        }
        return false;
    }

    // Method to check if the doctor with the given ID exists
    bool isDoctorExists(int doctorId)
    {
        DoctorsLL::Node *tempDoctor = doctorsLL.head;
        // Loop through the doctors linked list to check if the doctor with the given ID exists, if it exists return true
        while (tempDoctor != nullptr)
        {
            if (tempDoctor->doctor.doctorId == doctorId)
            {
                return true;
            }
            tempDoctor = tempDoctor->next;
        }
        return false;
    }

    // Method to register an appointment basing on the given appointmentId, patientId, doctorId and date
    void registerAppointment(int appointmentId, int patientId, int doctorId, string date)
    {

        if (!isPatientExists(patientId))
        {
            cout << "! ------------------ Patient with ID " << patientId << " does not exist. ----------------------- !" << endl;
        }
        else if (!isDoctorExists(doctorId))
        {
            cout << "! ------------------ Doctor with ID " << doctorId << " does not exist. ------------------------- !" << endl;
        }
        else
        {
            Node *temp = head;
            // Loop through the appointments linked list to check if the appointment with the given ID exists
            while (temp != nullptr)
            {
                if (temp->appointment.appointmentId == appointmentId)
                {
                    cout << "! ------------------ Appointment with ID " << appointmentId << " already exists. ----------------------- !" << endl;
                    return;
                }
                temp = temp->next;
            }

            Appointment appointment(appointmentId, patientId, doctorId, date);
            Node *newNode = new Node(appointment);

            // Check if the linkedlist is empty, then adds the head as the first node
            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                Node *temp = head;
                // If the linkedlist is not empty, then add the new node to the end of the appointment list as the last node
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            cout << "! ------------------ Appointment with ID " << appointmentId << " has been registered successfully. ----------------------- !" << endl;
        }
    }

    // Method to display all the appointments in the linked list
    void displayAppointments()
    {
        // Check if the linkedlist is empty
        if (head == nullptr)
        {
            cout << "! --------------- No Appointments available. Please register an appointment first. Use (3) ------------------ !" << endl;
            return;
        }

        Node *temp = head;
        cout << " * ---------------- * ------------------ * ----------------- * ----------------- *" << endl;
        // Loop through the appointments linked list to display all the appointments
        while (temp != nullptr)
        {
            cout << "    Appointment ID: " << temp->appointment.appointmentId << " , Patient ID: " << temp->appointment.patientId << " , Doctor ID: " << temp->appointment.doctorId << " , Date: " << temp->appointment.appointmentDate << endl;
            temp = temp->next;
        }
        cout << " * ---------------- * ------------------ * ----------------- * ----------------- *" << endl;
    }
};

// Method to validate the id input
void validateInput(int &input)
{
    while (true)
    {
        if (cin.fail())
        {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore();
            cin >> input;
        }
        else
        {
            break;
        }
    }
}

// Method to validate the empty string input
void validateEmptyString(string &input)
{
    while (true)
    {
        if (input.empty())
        {
            cout << "Invalid input. Please enter a valid string input." << endl;
            cin.clear();
            cin.ignore();
            getline(cin, input);
        }
        else
        {
            break;
        }
    }
}

bool isValidDateFormat(const string &date)
{
    // Regular expression to match the date format DD/MM/YYYY
    regex datePattern(R"(^\d{2}/\d{2}/\d{4}$)");
    return regex_match(date, datePattern);
}

bool isPastDate(const string &date)
{
    // Extract day, month, year from the input date
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    // Get current date
    time_t t = time(0);
    tm *now = localtime(&t);

    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    // Check if the date is in the past
    if (year < currentYear)
        return true;
    if (year == currentYear && month < currentMonth)
        return true;
    if (year == currentYear && month == currentMonth && day < currentDay)
        return true;

    return false;
}

bool isValidDate(const string &date)
{
    if (!isValidDateFormat(date))
        return false;

    // Extract day, month, year from the input date
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    // Check if the date is valid
    if (month < 1 || month > 12)
        return false;

    // Days in each month
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        daysInMonth[1] = 29;
    }

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return !isPastDate(date);
}

int main()
{
    PatientsLL patientsLL;
    DoctorsLL doctorsLL;
    AppointmentsLL appointmentsLL(patientsLL, doctorsLL);

    // Unless the user chooses to exit, the program will keep running
    while (true)
    {
        cout << "1. Register a Patient" << endl;
        cout << "2. Register a Doctor" << endl;
        cout << "3. Register Appointment" << endl;
        cout << "4. Display Patients" << endl;
        cout << "5. Display Doctors" << endl;
        cout << "6. Display Appointments" << endl;
        cout << "7. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            int patientId;
            string name, dob, gender;
            cout << "----------------------------" << endl;
            cout << "PATIENT REGISTRATION        " << endl;
            cout << "----------------------------" << endl;
            cout << "ID: ";
            cin >> patientId;
            validateInput(patientId);
            cout << "NAME: ";
            cin.ignore();
            getline(cin, name);
            validateEmptyString(name);
            cout << "DoB (DD/MM/YYYY): ";
            getline(cin, dob);
            validateEmptyString(dob);
            cout << "GENDER: ";
            getline(cin, gender);
            validateEmptyString(gender);
            patientsLL.addPatient(patientId, name, dob, gender);
            break;
        }
        case 2:
        {
            int doctorId;
            string name, specialization;
            cout << "----------------------------" << endl;
            cout << "DOCTOR REGISTRATION         " << endl;
            cout << "----------------------------" << endl;
            cout << "ID: ";
            cin >> doctorId;
            validateInput(doctorId);
            cout << "NAME: ";
            cin.ignore();
            getline(cin, name);
            validateEmptyString(name);
            cout << "SPECIALIZATION: ";
            getline(cin, specialization);
            validateEmptyString(specialization);
            doctorsLL.addDoctor(doctorId, name, specialization);
            break;
        }
        case 3:
        {
            int appointmentId, patientId, doctorId;
            string date;
            cout << "----------------------------" << endl;
            cout << "APPOINTMENT REGISTRATION        " << endl;
            cout << "----------------------------" << endl;
            cout << "ID: ";
            cin >> appointmentId;
            validateInput(appointmentId);
            cout << "P_ID(Patiend ID): ";
            cin >> patientId;
            validateInput(patientId);
            while (!appointmentsLL.isPatientExists(patientId))
            {
                cout << "Patient with ID " << patientId << " does not exist. Please enter a valid Patient ID." << endl;
                cout << "P_ID(Patiend ID): ";
                cin >> patientId;
            }
            cout << "D_ID(Doctor ID): ";
            cin >> doctorId;
            validateInput(doctorId);
            while (!appointmentsLL.isDoctorExists(doctorId))
            {
                cout << "Doctor with ID " << doctorId << " does not exist. Please enter a valid Doctor ID." << endl;
                cout << "D_ID(Doctor ID): ";
                cin >> doctorId;
            }
            cin.ignore();
            cout << "DATE (DD/MM/YYYY): ";
            getline(cin, date);
            while (!isValidDate(date))
            {
                cout << "Invalid date format or date is in the past. Please enter a valid date (DD/MM/YYYY)." << endl;
                cout << "DATE (DD/MM/YYYY): ";
                getline(cin, date);
            }
            appointmentsLL.registerAppointment(appointmentId, patientId, doctorId, date);
            break;
        }
        case 4:
            patientsLL.displayAllActivePatients();
            break;
        case 5:
            doctorsLL.displayActiveDoctors();
            break;
        case 6:
            appointmentsLL.displayAppointments();
            break;
        case 7:
            cout << "Quit. /bye" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
        }

        cout << endl;
    }

    return 0;
}
