# health-management-project
Health management system project for fundamental of programming I course group project

### Simplified Project Scope
1. Patient Management:
   - Store and display basic patient information (name, ID, age, and medical history summary).
   - Only implement viewing and adding patient records.
   
2. Appointment Scheduling:
   - Allow simple appointment booking and cancellation.
   - Use a static array for appointment slots (e.g., 10 slots/day).

3. User Authentication:
   - Implement a basic login system with hardcoded usernames and passwords.

4. Staff Management (Demo):
   - Only manage staff attendance (present/absent status).
   - Store a list of staff names and mark attendance.

---

### Reclassified Tasks

#### Member 1: Patient Management (Data Entry and Display)
- store patient details (name, ID, age, medical history).
- Write a function to add a new patient.
- Write a function to display all patients' information.
- Use a static array to store patient records (limit: 20 patients).

---

#### Member 2: Appointment Scheduling (Static Slots)
- Use a static array to represent appointment slots (e.g., char slots[10][30] for 10 slots with patient names).
- Write a function to:
  - Book an appointment by entering patient name and slot number.
  - Cancel an appointment by clearing the slot.
- Display all appointment slots and their status (booked or available).

---

#### Member 3: User Authentication (Hardcoded Login)
- Create two hardcoded users with usernames and passwords.
- Write a login function:
  - Ask for username and password using string input.
  - Validate credentials with a simple if statement.
- Display a success or failure message based on login.

---

#### Member 4: Staff Attendance (Basic Tracking)
- Create a static array to store staff names and their attendance status.
- Write functions to:
  - Mark attendance as present or absent for a specific staff member.
  - Display the attendance status of all staff.
- Use a loop to update and display attendance.

---

#### Member 5: System Integration and Menu
- Create a menu-driven program using switch or if statements.
- Integrate:
  - Patient management functions.
  - Appointment scheduling functions.
  - User authentication and staff attendance functions.
- Ensure the menu loops until the user chooses to exit.

---

#### Member 6: Testing and Debugging
- Test each module individually to ensure correct functionality:
  - Patient management.
  - Appointment scheduling.
  - User authentication.
  - Staff attendance.
- Test the integrated system for smooth navigation and transitions.
- Handle basic edge cases like:
  - Invalid slot numbers.
  - Attempting to book a full appointment slot.

---

### Key Simplifications
1. No dynamic memory allocation—static arrays only.
2. Hardcoded data for user authentication.
3. Limited features for patient management and staff attendance.
4. No complex analytics or performance evaluations.

---
