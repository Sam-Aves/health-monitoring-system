# Health Monitoring System

A desktop health monitoring application built with **Qt 6** and **C++**, featuring user authentication, five health metric monitors, doctor's appointment scheduling, and an SQLite database backend.

Built as a semester-end C++ project — solo development.

---

## Features

### Authentication
- User registration with first name, last name, username, password, email, age, gender, and country
- Login with username/password validated against SQLite database
- Session-based username passing across all dialogs after login

### Health Monitors
| Monitor | Reference Range | What it checks |
|---|---|---|
| **Temperature** | 36.5°C – 37.3°C | Normal / outside range |
| **Blood Pressure** | <120/80 mmHg | Systolic + diastolic, flags hypotension and hypertension |
| **Oxygen (SpO₂)** | 95% – 100% | Low / normal / high |
| **Glucose** | 70 – 140 mg/dL | Low / normal / high |
| **Goals** | — | Set and track personal health goals |

### Appointments
- Browse available time slots (9 AM – 8 PM)
- Book appointment — saved to user's record in SQLite
- Cancel appointment dialog

### Recommended Plans
- Four selectable health plans (90-day, 200-day, 360-day, 600-day)
- Plan details update dynamically on selection

---

## Tech Stack

| Layer | Technology |
|---|---|
| Language | C++17 |
| GUI Framework | Qt 6.7 |
| Database | SQLite via Qt SQL module (`QSQLITE`) |
| Build System | qmake (`.pro` file) |
| IDE | Qt Creator |

---

## Database Schema

```sql
CREATE TABLE users (
    id          INTEGER PRIMARY KEY AUTOINCREMENT,
    first_name  TEXT NOT NULL,
    last_name   TEXT NOT NULL,
    username    TEXT UNIQUE NOT NULL,
    password    TEXT NOT NULL,
    email       TEXT UNIQUE NOT NULL,
    age         TEXT,
    gender      TEXT,
    country     TEXT,
    appointments TEXT
);
```

Database file: `HealthMonitoringDatabase.sqlite` (auto-created on first run in the working directory)

---

## Build & Run

**Requirements:**
- Qt 6.7+ with `sql` and `widgets` modules
- Qt Creator (recommended) or qmake + compatible C++ compiler

**Steps:**
1. Clone the repository
2. Open `HealthMonitoring.pro` in Qt Creator
3. Configure the kit (Desktop Qt 6.x MinGW or MSVC)
4. Click **Build → Run** (Ctrl+R)

The SQLite database is created automatically on first launch — no setup needed.

---

## Project Structure

```
health-monitoring-system/
├── main.cpp                          # App entry, DB initialization
├── mainwindow.cpp / .h / .ui         # Login screen
├── registrationdialog.cpp / .h / .ui # Registration form
├── secdialog.cpp / .h / .ui          # Post-login landing screen
├── navigationwindow.cpp / .h / .ui   # Main navigation hub
├── temperaturemonitordialog.*        # Temperature monitor
├── bloodpressuremonitordialog.*      # Blood pressure monitor
├── oxygenmonitordialog.*             # Oxygen (SpO₂) monitor
├── glucosemonitordialog.*            # Glucose monitor
├── goalsdialog.*                     # Health goals tracker
├── recommendedplansdialog.*          # Health plan selection
├── doctorsappointmentdialog.*        # Appointment hub
├── scheduleappointmentdialog.*       # Book appointment
├── cancelappointmentdialog.*         # Cancel appointment
├── HealthMonitoring.pro              # Qt project file
└── README.md
```

---

## Application Flow

```
Launch
  │
  ▼
Login Screen (MainWindow)
  ├── [Register] → Registration Dialog → SQLite INSERT
  └── [Login]    → SQLite query → session username set
                        │
                        ▼
               Post-Login Screen (SecDialog)
                        │
                        ▼
               Navigation Window
          ┌────────────┼────────────────┐
          ▼            ▼                ▼
    Health Monitors  Goals      Doctor's Appointment
    (Temp/BP/O₂/     Tracker    ├── Schedule → SQLite UPDATE
     Glucose)                   └── Cancel
```

---

## Known Limitations

- **Passwords are stored in plaintext** — a real application would use hashing (e.g. bcrypt or Qt's `QCryptographicHash`). Not addressed here as security was outside the project scope.
- Appointment cancellation does not query the database — the cancel dialog shows a static slot list and does not remove the actual booked record.
- Health readings are not persisted — monitoring dialogs calculate and display results in-session only, no history is saved to the database.
- Goals are session-only — text entered in the goals dialog is not written to the database.

---

## Author

**Asliraf Samaylan** — IIUC, CSE
Solo semester-end project — C++ with Qt course
