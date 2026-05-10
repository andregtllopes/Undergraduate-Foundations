# Space Invaders: Classic Arcade Engine in C

## 📌 Project Overview
This repository contains a full-scale clone of the classic arcade game **Space Invaders**, developed during the first semester of 2025 as the final project for **Programming and Software Development I (PDS I)** at the **Universidade Federal de Minas Gerais (UFMG)**. 

The project represents a milestone in my academic trajectory, consolidating fundamental concepts of the **C language** and **Structured Programming**. Developed 100% manually without AI assistance, the software manages complex game states, real-time event handling, and multimedia integration using the **Allegro 5** library.

## 🛠️ Technical Pipeline
The engine was built using a modular architecture focused on memory efficiency and logical synchronization:

1.  **Structured Entity Modeling:** Use of complex `structs` to encapsulate the properties of the Cannon (player), Aliens, Projectiles, and Power-ups. This ensured a "single source of truth" for the state of every object on the screen.
2.  **Event-Driven Game Loop:** Implementation of a robust main loop synchronized at 100 FPS. The system handles concurrent events from the keyboard, mouse, and high-resolution timers to ensure smooth gameplay.
3.  **Physics & Collision Algorithms:** * **AABB (Axis-Aligned Bounding Box):** Used for precise rectangular collision detection between entities.
    * **Circular Hitboxes:** Implementation of the distance formula ($d = \sqrt{(x_2-x_1)^2 + (y_2-y_1)^2}$) for projectile logic.
4.  **Multimedia Management:** Integration of multiple Allegro 5 modules:
    * `Primitives`: For procedural rendering of game assets.
    * `Audio & Acodec`: For background music and sound effect streams.
    * `Font & TTF`: For dynamic UI rendering (score, levels, menus).
5.  **Data Persistence (File I/O):** A system for reading and writing to `recorde.txt`, allowing the "High Score" to persist across different gaming sessions.

## 📊 Notable Algorithms & Logic
* **Synchronized Horde "March":** A collective movement algorithm that monitors the screen boundaries for the entire alien block. When one alien hits the edge, the entire group shifts downward and reverses horizontal velocity.
* **Dynamic Environment:** Implementation of a parallax "Starfield" and a smooth day-to-night sky cycle using a timer-based color interpolation function (`amanhece`).
* **Power-up Strategy:** A randomized generator that drops temporary buffs (Piercing Shot, Double Shot, or Rapid Fire) upon alien destruction, adding a layer of strategic depth.

## 💼 Academic Validation
This project was awarded a **100% score (Maximum Grade)**. During the technical defense at UFMG, I successfully performed a "live coding" challenge, re-structuring the firing logic under pressure to prove full mastery of the system's architecture. It served as the foundation for my transition from structured logic to Object-Oriented Programming (OOP).

## 🚀 Setup & Execution
The repository is designed to be **Self-Contained**. For Windows users, the necessary `.dll` is included to ensure the game runs "out of the box" without complex environment configurations.

### 1. Prerequisites
* **GCC Compiler** (MinGW recommended for Windows).
* **Allegro 5.0.10** (Development libraries if you wish to recompile).

### 2. How to Run
1.  Clone the repository.
2.  Ensure `allegro-5.0.10-monolith-mt.dll`, `battle.ogg`, and `Heroes Legend.ttf` are in the same folder as the executable.
3.  **To Compile (Optional):** Use the provided `Makefile`:
    ```bash
    make
    ```
4.  **To Play:** Run the generated executable or the `space_invaders_engine.c` (if compiled).

## 🎮 Controls
* **A / D:** Move Left/Right.
* **Spacebar:** Standard Fire.
* **C:** Special Fire (requires Power-up).
* **Mouse:** Menu navigation and level selection.

---
> **Note:** This project is preserved in its original form as a testament to my first semester of Computer Science Minor studies.