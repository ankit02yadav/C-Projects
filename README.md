# 🎯 Multi-Functional Console Application in C
This is a multi-module C project that brings together various small applications into one console-based interface. Whether you want to manage a bakery, play some games, find the day of a date, maintain a to-do list, manage student records, or get movie recommendations — this project has it all!

# 📁 Modules Included
## 1. Bakery Management System (BMS)
Admin and Customer modes

Admin can:
Add or update menu items

Customers can:
View menu
Place orders
View past orders by ID
Update (remake) their orders

Customer orders are stored in individual CSV files with auto-generated order IDs.

## 2. Game Menu
Currently includes placeholder or external games - expected to be included via games.c.

## 3. Day Finder
Input a date to find out the day of the week.
Handles invalid date input, leap years, and humorously incorrect entries.

## 4. To-Do List
Feature details are managed in tdlist.c. Likely includes creation and viewing of tasks.

## 5. Student Record System
Details pending implementation in students.c.

## 6. Movie Recommendation System
Included via movie.c - functionality based on user preference is expected.

## 🛠️ Tech Stack
Language: C (GCC-compatible)
Storage: CSV files for data persistence
Modules: Modular design using .c and .h separation
UI: Console-based with colored ASCII art banners

## 🚀 How to Run
Clone the repository:

```bash
    https://github.com/ankit02yadav/C-Projects.git
    cd C-Projects
```
Compile the project: Make sure all .c files are available in the appropriate folders.

```bash
  gcc main.c -o app
```
Run the application:

```bash
  ./app
```
💡 On Windows, use gcc main.c -o app.exe and then run app.exe.

## 📂 File Structure

.
├── bakery/  \n
│   ├── bms.c \n
│   ├── menu.csv \n
│   ├── customer.csv \n
│   ├── admin.csv \n
│   └── id_alloted.csv \n
├── games/ \n
│   └── games.c \n
├── day date/ \n
│   └── day_tm.c \n
├── to do list/ \n
│   └── tdlist.c \n
├── students record/ \n
│   └── students.c \n
├── movie recommand/ \n
│   └── movie.c \n
└── main.c \n

# ✅ Features
- Modular design for better code management
- Real-time system date and time logging
- Easy CSV-based data handling
- Admin authentication
- Color-coded terminal UI for better UX

# 🧠 Future Improvements
- Add more games under the games/ module
- Expand the Student Record System
- Improve the movie recommendation logic
- Use .h headers for cleaner module inclusion
- Add file existence checks for safer execution

# 🧑‍💻 Author
Ankit Yadav
[GitHub](https://github.com/ankit02yadav)
