#include <appointment_scheduling.h>
#include <iostream>
#include <cstring>
using namespace std;

const int daysInWeek = 7;
const int slotPerDay = 10;
const int namelength = 30;

char slots[daysInWeek][slotPerDay][namelength];
const string daysOfWeek[daysInWeek] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

void initialSlots()
{
    for (int day = 0; day < daysInWeek; ++day)
    {
        for (int slot = 0; slot < slotPerDay; ++slot)
        {
            (slots[day][slot], "Available");
        }
    }
}
void bookAppointment()
{

    // Todo: Add the book appointment
}
void cancelAppointment()
{
    int day, slot;

    cout << "Enter day:\n"
         << "\n 1: Monday"
         << "\n 2: Tuesday"
         << "\n 3: Wednesday"
         << "\n 4: Thursday"
         << "\n 5: Friday"
         << "\n 6: Saturday"
         << "\n 7: Sunday\n";
    cin >> day;
    -day;

    if (day < 0 || day >= daysInWeek)
    {
        cout << "Invalid day. Try again.\n";
        return;
    }

    cout << "Enter slot number: ";
    cin >> slot;
    --slot;

    if (slot < 0 || slot >= slotPerDay)
    {
        cout << "Invalid slot number. Try again.\n";
        return;
    }

    if ((slots[day][slot], "Available") == 0)
    {
        cout << "Slot is already available. Try again.\n";
        return;
    }

    cout << "Appointment canceled for " << daysOfWeek[day] << ", Slot " << slot + 1 << ".\n";
}

void displayAppointments()
{
    for (int day = 0; day < daysInWeek; ++day)
    {
        cout << daysOfWeek[day] << ":\n";
        for (int slot = 0; slot < slotPerDay; ++slot)
        {
            cout << "Slot " << slot << ": " << slots[day][slot] << "\n";
        }
    }
}

int main()
{
    initialSlots();
    int choice;

    while (true)
    {
        cout << "\n1. Book Appointment\n";
        cout << "2. Cancel Appointment\n";
        cout << "3. Display Appointments\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bookAppointment();
            break;

        case 2:
            cancelAppointment();
            break;

        case 3:
            displayAppointments();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}