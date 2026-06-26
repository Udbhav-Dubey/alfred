# Alfred

Alfred is a **personal, terminal-based reflection tool**.

It is designed to be used **once a day**, at the end of the day, and to take **no more than a few minutes**.

No accounts.  
No cloud.  
No analytics.  
No pressure.

Just a quiet place in your terminal to close the day honestly.

---

## What Alfred Is

Alfred is a **daily closing ritual**, not a productivity system.

It helps you:

- write a short journal entry
- mark whether you followed your habits today
- reflect briefly before ending the day

Alfred does not try to optimize you.  
It simply records what happened.

---

## Core Workflow (v1)

Alfred follows the same flow every day:

1. **Journal**  
   Write freely about your day — thoughts, events, reflections.

2. **Habit logging**  
   Answer simple yes/no questions for your habits.

3. **Exit**  
   A random quote is shown as a closing thought.

That's it.

There are no streaks, deadlines, reminders, or scores in v1.

---

## What's Coming (v2)

v2 extends Alfred without changing what it is.

The terminal ritual stays exactly the same. Two things are being added underneath:

**SQLite storage**  
CSV is being replaced with a local SQLite database. Same data, better structure. No external server, no change to how Alfred feels to use — just a proper foundation.

**Android companion app**  
A minimal Android app for quick journal capture when you're away from your terminal. One text field. One save button. One sync.

The phone is not a replacement for Alfred. It's a longer arm — a way to write something down in the moment so it's there when you sit down at night.

Sync happens over LAN. No internet required. No accounts. Still local-first.

---

## Design Principles

Alfred is built around a few strict principles:

- **Local-first**  
  All data lives on your machine.

- **Low friction**  
  The entire flow is designed to take under 5 minutes.

- **No pressure mechanics**  
  No streaks, no alarms, no failure states.

- **Honest reflection over optimization**  
  Alfred records reality instead of judging it.

- **Terminal-native**  
  Built for people who live in their terminal.

These principles carry into v2. The Android app is input-only. The SQLite migration is invisible at the surface. Nothing about the daily ritual changes.

---

## Current Features (v1)

- Daily journaling
- Daily habit logging (binary: yes / no)
- Configurable habits via a local file
- Local CSV-based data storage
- Menu-driven terminal interface
- Random quote displayed on exit

---

## What Alfred Is *Not*

Alfred is intentionally **not**:

- a task manager
- a deadline tracker
- a productivity dashboard
- a gamified habit app
- a replacement for external services (e.g. LeetCode, calendars)

If a metric is already obvious or tracked elsewhere, Alfred does not repeat it.

---

## Platform & Build

- Designed for **Linux**
- Built as a **terminal application**
- Written in C++
- Built using CMake

Other platforms are not a priority.

---

## Data & Privacy

- No telemetry
- No tracking
- No external dependencies

All runtime data lives in the local `data/` directory and is ignored by git.

In v2, data is stored in a local SQLite database (`data/alfred.db`). The Android app syncs over LAN only — nothing leaves your network.

See `data/README.md` for details.

---

## Project Status

Alfred v1 is complete.

v2 is in planning. See open issues for what's being worked on.

The project is personal and experimental by nature. Features are only added if they align with the core philosophy.

Stability, simplicity, and daily usability come first.

---

## Why Alfred Exists

Alfred exists to answer one simple question:

> *"Did today align with how I want to live?"*

Once that question is answered, the day is over.

Close the terminal.  
Move on.
