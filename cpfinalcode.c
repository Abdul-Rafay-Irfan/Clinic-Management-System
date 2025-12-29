#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// structure to store patient information
struct Patient
{
    int id;
    char name[50];
    int age;
    char gender[10];
    char disease[50];
    char doctor[50];
};

// structure to store doctor information
struct Doctor
{
    int id;
    char name[50];
    char gender[10];
    char specialization[50];
    int experience;
};

// structure to store appointment information
struct Appointment
{
    char patient_name[50];
    char doctor_name[50];
    char date[20];
    char time[20];
};

// functions
void continuekey();
void aboutclinic();
void addPatient();
void viewPatients();
void searchPatient();
void updatePatient();
void deletePatient();
void addDoctor();
void viewDoctor();
void bookAppointment();
void viewAppointments();

int main()
{
    int choice;

    // main menu keeps repeating until user press 11 for exit
    while (1)
    {
        printf("\n\n\n\t\t\t\t======= CLINIC MANAGEMENT SYSTEM =======\n");
        printf("1. About our clinic\n");
        printf("2. Add Patient\n");
        printf("3. View All Patients\n");
        printf("4. Search Patient by ID\n");
        printf("5. Update Patient Record\n");
        printf("6. Delete Patient Record\n");
        printf("7. Add New Doctor\n");
        printf("8. View All Doctors\n");
        printf("9. Book Appointment\n");
        printf("10. View Appointments\n");
        printf("11. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        // menu selection using switch
        switch (choice)
        {
        case 1:
            aboutclinic();
            break;

        case 2:
            addPatient();
            break;

        case 3:
            viewPatients();
            break;

        case 4:
            searchPatient();
            break;

        case 5:
            updatePatient();
            break;

        case 6:
            deletePatient();
            break;

        case 7:
            addDoctor();
            break;

        case 8:
            viewDoctor();
            break;

        case 9:
            bookAppointment();
            break;

        case 10:
            viewAppointments();
            break;

        case 11:
            printf("\nExiting... Have a good day!\n");
            printf("\n\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}

// pauses program until user press a key
void continuekey()
{
    printf("\nPress any key to continue...");
    getch(); // this will wait for a key press
    system("cls");
}

// Function to give information to user about our clinic
void aboutclinic()
{
    system("cls");
    printf("\n\t\t\t\tWelcome to LifeCare Clinic!\n");
    printf("At LifeCare Clinic, we are dedicated to providing quality healthcare with compassion and efficiency.\n");
    printf("Our clinic offers general checkups, specialist consultations, and diagnostic services.\n");
    printf("Clinic Timings: Monday to Saturday — 12:10 PM to 11:55 PM\n");
    printf("Address: LifeCare Clinic, Block 5, Gulshan-e-Iqbal, Karachi, Pakistan\n");
    printf("Contact: +92-300-1234567\n");

    // wait until user press any key
    continuekey();
}

// Function to add new patient record into file
void addPatient()
{
    system("cls");
    struct Patient p;
    // Open patients.txt in append mode
    FILE *fp = fopen("patients.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
    }

    printf("\t----ADD PATIENT----\n");
    printf("Enter Patient ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Gender: ");
    scanf(" %[^\n]", p.gender);
    printf("Enter Disease: ");
    scanf(" %[^\n]", p.disease);
    printf("Enter your doctor Name: ");
    scanf(" %[^\n]", p.doctor);

    // writing patient data line by line into file
    fprintf(fp, "ID: %d\n", p.id);
    fprintf(fp, "Name: %s\n", p.name);
    fprintf(fp, "Age: %d\n", p.age);
    fprintf(fp, "Gender: %s\n", p.gender);
    fprintf(fp, "Disease: %s\n", p.disease);
    fprintf(fp, "Doctor: %s\n\n", p.doctor);
    fprintf(fp, "-------------------------\n");

    fclose(fp);
    printf("\nPatient added successfully!\n");

    // wait until user press any key
    continuekey();
}

// Function to display all saved patient records
void viewPatients()
{
    system("cls");
    struct Patient p;
    // Open patient.txt in read mode
    FILE *fp = fopen("patients.txt", "r");

    printf("\n-----PATIENTS LIST-----\n");

    if (fp == NULL)
    {
        printf("No records found.\n");
    }

    // reading one full patient block and print it one by one
    while (fscanf(fp, "ID: %d\n", &p.id) == 1)
    {
        fscanf(fp, "Name: %[^\n]\n", p.name);
        fscanf(fp, "Age: %d\n", &p.age);
        fscanf(fp, "Gender: %[^\n]\n", p.gender);
        fscanf(fp, "Disease: %[^\n]\n", p.disease);
        fscanf(fp, "Doctor: %[^\n]\n", p.doctor);
        fscanf(fp, "-------------------------\n");

        printf("\nID: %d\nName: %s\nAge: %d\nGender: %s\nDisease: %s\nDoctor: %s\n",
               p.id, p.name, p.age, p.gender, p.disease, p.doctor);
    }

    fclose(fp);

    // wait until user press any key
    continuekey();
}

// Function to search a specific patient using ID
void searchPatient()
{

    system("cls");
    struct Patient p;
    int id, found = 0;
    // Open patients.txt in read mode
    FILE *fp = fopen("patients.txt", "r");

    printf("\t----SEARCH PATIENT----\n");

    if (fp == NULL)
    {
        printf("No records found.\n");
    }

    // taking input which patient user want to search
    printf("\nEnter Patient ID to search: ");
    scanf("%d", &id);

    // scanning record by record to match id
    while (fscanf(fp, "ID: %d\n", &p.id) == 1)
    {
        fscanf(fp, "Name: %[^\n]\n", p.name);
        fscanf(fp, "Age: %d\n", &p.age);
        fscanf(fp, "Gender: %[^\n]\n", p.gender);
        fscanf(fp, "Disease: %[^\n]\n", p.disease);
        fscanf(fp, "Doctor: %[^\n]\n", p.doctor);
        fscanf(fp, "-------------------------\n");

        // when id match print its record
        if (p.id == id)
        {
            found = 1;
            printf("\nRecord Found\n\n");
            printf("ID: %d\nName: %s\nAge: %d\nGender: %s\nDisease: %s\nDoctor: %s\n",
                   p.id, p.name, p.age, p.gender, p.disease, p.doctor);
        }
    }

    // if id doen't match then print not found
    if (!found)
        printf("\nNo patient found with ID %d\n", id);

    fclose(fp);

    // wait until user press any key
    continuekey();
}

// Function to update an existing patient record by rewriting the file
void updatePatient()
{
    system("cls");
    struct Patient p;
    FILE *fp, *temp;
    int id, found = 0;

    // Open patients.txt in read mode
    fp = fopen("patients.txt", "r");
    // Open temp.txt in write mode
    temp = fopen("temp.txt", "w");

    printf("\t----UPDATE PATIENT----\n");

    if (fp == NULL)
    {
        printf("No records found.\n");
    }

    // taking input which patient user want to update
    printf("\nEnter patient ID to update: ");
    scanf("%d", &id);

    // reading patient records one by one
    while (fscanf(fp, "ID: %d\n", &p.id) == 1)
    {
        fscanf(fp, "Name: %[^\n]\n", p.name);
        fscanf(fp, "Age: %d\n", &p.age);
        fscanf(fp, "Gender: %[^\n]\n", p.gender);
        fscanf(fp, "Disease: %[^\n]\n", p.disease);
        fscanf(fp, "Doctor: %[^\n]\n", p.doctor);
        fscanf(fp, "-------------------------\n");

        // if record matches ask user to input new details
        if (p.id == id)
        {
            found = 1;
            printf("Enter new details:\n\n");
            printf("Enter new name: ");
            scanf(" %[^\n]", p.name);
            printf("Enter Age: ");
            scanf("%d", &p.age);
            printf("Enter Gender: ");
            scanf("%s", p.gender);
            printf("Enter disease: ");
            scanf(" %[^\n]", p.disease);
            printf("Enter doctor name: ");
            scanf(" %[^\n]", p.doctor);
        }

        // writing record back to temporary file
        fprintf(temp, "ID: %d\n", p.id);
        fprintf(temp, "Name: %s\n", p.name);
        fprintf(temp, "Age: %d\n", p.age);
        fprintf(temp, "Gender: %s\n", p.gender);
        fprintf(temp, "Disease: %s\n", p.disease);
        fprintf(temp, "Doctor: %s\n\n", p.doctor);
        fprintf(temp, "-------------------------\n");
    }
    fclose(fp);
    fclose(temp);

    // replacing old file with updated one
    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (found)
        printf("\nRecord updated successfully\n");

    // if id doen't match then print not found
    else
        printf("\nNo patient found with ID %d\n", id);

    // wait until user press any key
    continuekey();
}

// Function to delete patient record by skipping it while rewriting remaining file records
void deletePatient()
{

    system("cls");
    struct Patient p;
    FILE *fp, *temp;
    int id, found = 0;

    // Open patients.txt in read mode
    fp = fopen("patients.txt", "r");
    // Open temp.txt in write mode
    temp = fopen("temp.txt", "w");

    printf("\t----DELETE PATIENT----\n");

    if (fp == NULL)
    {
        printf("No records found");
    }

    printf("Enter patient ID to delete: ");
    scanf("%d", &id);

    // reading all records to find the one to remove
    while (fscanf(fp, "ID: %d\n", &p.id) == 1)
    {
        fscanf(fp, "Name: %[^\n]\n", p.name);
        fscanf(fp, "Age: %d\n", &p.age);
        fscanf(fp, "Gender: %[^\n]\n", p.gender);
        fscanf(fp, "Disease: %[^\n]\n", p.disease);
        fscanf(fp, "Doctor: %[^\n]\n", p.doctor);
        fscanf(fp, "-------------------------\n");

        // record found → skip writing it into temp file
        if (p.id == id)
        {
            found = 1;
            printf("\nDeleting record of patient with id %d\n", p.id);
            continue;
        }

        // writing remaining records to temp file
        fprintf(temp, "ID: %d\n", p.id);
        fprintf(temp, "Name: %s\n", p.name);
        fprintf(temp, "Age: %d\n", p.age);
        fprintf(temp, "Gender: %s\n", p.gender);
        fprintf(temp, "Disease: %s\n", p.disease);
        fprintf(temp, "Doctor: %s\n\n", p.doctor);
        fprintf(temp, "-------------------------\n");
    }

    fclose(fp);
    fclose(temp);

    // replacing old file with the new temp file
    remove("patients.txt");
    rename("temp.txt", "patients.txt");

    if (found)
        printf("\nRecord deleted successfully\n");

    // if id doen't match then print not found
    else
        printf("\nNo patient found with ID %d\n", id);

    // wait until user press any key
    continuekey();
}

// Function to add new doctor record into file
void addDoctor()
{
    system("cls");
    struct Doctor d;
    // Open doctors.txt in append mode
    FILE *fp = fopen("doctors.txt", "a");

    printf("\t----ADD DOCTOR----\n");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
    }

    printf("Enter Doctor ID: ");
    scanf("%d", &d.id);
    printf("Enter Doctor Name: ");
    scanf(" %[^\n]", d.name);
    printf("Enter gender: ");
    scanf(" %[^\n]", d.gender);
    printf("Enter specialization: ");
    scanf(" %[^\n]", d.specialization);
    printf("Enter experience(years): ");
    scanf("%d", &d.experience);

    // writing doctor information into file
    fprintf(fp, "ID: %d\n", d.id);
    fprintf(fp, "Name: %s\n", d.name);
    fprintf(fp, "Gender: %s\n", d.gender);
    fprintf(fp, "Specialization: %s\n", d.specialization);
    fprintf(fp, "Experience: %d years\n\n", d.experience);
    fprintf(fp, "-------------------------\n");

    fclose(fp);
    printf("\nDoctor added successfully\n");

    // wait until user press any key
    continuekey();
}

// Function to display all saved doctor records
void viewDoctor()
{
    system("cls");
    struct Doctor d;
    // Open doctors.txt in read mode
    FILE *fp = fopen("doctors.txt", "r");

    printf("\n-----DOCTORS LIST-----\n");

    if (fp == NULL)
    {
        printf("No doctor records found!\n");
    }

    // reading doctor information block by block and paste it one by one
    while (fscanf(fp, "ID: %d\n", &d.id) == 1)
    {
        fscanf(fp, "Name: %[^\n]\n", d.name);
        fscanf(fp, "Gender: %[^\n]\n", d.gender);
        fscanf(fp, "Specialization: %[^\n]\n", d.specialization);
        fscanf(fp, "Experience: %d years\n", &d.experience);
        fscanf(fp, "-------------------------\n");

        printf("\nID: %d\nName: %s\nGender: %s\nSpecialization: %s\nExperience: %d\n",
               d.id, d.name, d.gender, d.specialization, d.experience);
    }

    fclose(fp);

    // wait until user press any key
    continuekey();
}

// Function to book new appointment between doctor and patient
void bookAppointment()
{
    system("cls");
    struct Appointment a;

    // Open appointments.txt in append mode
    FILE *fp = fopen("appointments.txt", "a");

    printf("\t----BOOK YOUR APPOINTMENT----\n");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
    }

    printf("Enter Patient name: ");
    scanf(" %[^\n]", &a.patient_name);
    printf("Enter Doctor name: ");
    scanf(" %[^\n]", &a.doctor_name);
    printf("Enter Date (DD/MM/YYYY): ");
    scanf(" %[^\n]", a.date);
    printf("Enter Time (HH:MM): ");
    scanf(" %[^\n]", a.time);

    // writing appointment records in file
    fprintf(fp, "Patient Name: %s\n", a.patient_name);
    fprintf(fp, "Doctor Name: %s\n", a.doctor_name);
    fprintf(fp, "Date: %s\n", a.date);
    fprintf(fp, "Time: %s\n\n", a.time);
    fprintf(fp, "-------------------------\n");

    fclose(fp);
    printf("\nAppointment booked successfully!\n");

    // wait until user press any key
    continuekey();
}

// Function to show all saved appointments
void viewAppointments()
{
    system("cls");
    struct Appointment a;
    // Open appointments.txt in read mode
    FILE *fp = fopen("appointments.txt", "r");

    printf("\n-----APPOINTMENTS LIST-----\n");

    if (fp == NULL)
    {
        printf("No appointment records found!\n");
    }

    // reading every appointment block and print it one by one
    while (fscanf(fp, "Patient Name: %[^\n]\n", a.patient_name) == 1)
    {
        fscanf(fp, "Doctor Name: %[^\n]\n", a.doctor_name);
        fscanf(fp, "Date: %[^\n]\n", a.date);
        fscanf(fp, "Time: %[^\n] PM\n", a.time);
        fscanf(fp, "-------------------------\n");

        printf("\n\nPatient name: %s\nDoctor name: %s\nDate: %s\nTime: %s\n",
               a.patient_name, a.doctor_name, a.date, a.time);
    }

    fclose(fp);

    // wait until user press any key
    continuekey();
}