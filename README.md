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

That’s it.

There are no streaks, deadlines, reminders, or scores in v1.

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
- No network access
- No external dependencies

All runtime data lives in the local `data/` directory and is ignored by git.

See `data/README.md` for details.

---

## Project Status

Alfred v1 is complete.

The project is personal and experimental by nature.
Future versions may add features, but only if they align with the core philosophy.

Stability, simplicity, and daily usability come first.

---

## Why Alfred Exists

Alfred exists to answer one simple question:

> *“Did today align with how I want to live?”*

Once that question is answered, the day is over.

Close the terminal.  
Move on.

