# Space Invaders: Classic Arcade Engine in C

## 📌 Project Overview
This repository contains a full-scale clone of the classic arcade game **Space Invaders**, developed in early 2025 as the final project for **Programming and Software Development I (PDS I)** at the **Universidade Federal de Minas Gerais (UFMG)**. 

The project represents a milestone in my academic trajectory, consolidating fundamental concepts of the **C language** and **Structured Programming**. Developed 100% manually during my first semester, the software manages complex game states, real-time event handling, and multimedia integration using the **Allegro 5** library. It demonstrates the transition from basic logic to event-oriented system architecture.

## 🛠️ Technical Pipeline
The engine was built using a modular architecture focused on memory efficiency and logical synchronization:

1.  **Structured Entity Modeling:** Implementation of custom `structs` (`canhao`, `alien`, `tiro`, `super`) to encapsulate properties. This ensures a "single source of truth" for the state of every object, managing coordinates, velocities, and health status (alive/dead).
2.  **Event-Driven Game Loop:** A robust main loop synchronized at **100 FPS**. The system handles concurrent inputs from the keyboard (movement/firing) and mouse (UI interaction) while maintaining a high-resolution timer to regulate game logic independently of rendering speed.
3.  **Hybrid Collision System:** * **AABB (Axis-Aligned Bounding Box):** Used for rectangular intersections between aliens and the defensive line.
    * **Circular Hitboxes:** Implementation of the distance formula ($d^2 = \Delta x^2 + \Delta y^2$) to detect if a projectile (circle) has entered an alien's (rectangle) hitbox, ensuring pixel-perfect interactions.
4.  **Data Persistence (File I/O):** A record-keeping system using standard C file handling (`fopen`, `fscanf`, `fprintf`). The game reads the highest score from `recorde.txt` at startup and updates it globally if the player breaks the current record.

## 📊 Logic & Advanced Features

### 🌅 Dynamic Atmospheric Cycle ("Amanhece")
The project features a procedural sky background that transitions over time. The `amanhece` function utilizes linear interpolation (LERP) of RGB values based on the global timer.
* **Logic:** The sky color shifts from a deep night blue to a vibrant dawn orange ($RGB: 244, 158, 18$).
* **Parallax Effect:** A 1000-point starfield is generated with varying vertical velocities, creating a sense of depth and motion behind the primary gameplay plane.

### ⚡ Strategic Power-up System
To modernize the classic gameplay, I implemented a randomized drop system. When an alien is destroyed, there is a probability of spawning a "Super Power" token.
1.  **Power 1 (Rapid Fire):** Increases projectile velocity and size ($r = 15$), significantly boosting the cannon's kinetic output.
2.  **Power 2 (Double Shot):** Enables a secondary projectile slot, allowing the player to maintain two active shots on screen simultaneously, doubling the coverage area.
3.  **Power 3 (Piercing Shot):** Modifies the collision logic so the projectile is not destroyed upon impact. The shot traverses the entire alien horde, eliminating every enemy in its vertical trajectory.
* **Temporal Management:** Each buff is managed by independent Allegro timers (`cooldown1, 2, 3`), ensuring a strictly balanced 5-second duration.

## 💼 Academic Validation
This project was awarded a **100% score (Maximum Grade)**. During the technical defense at UFMG, I performed a "live coding" challenge, re-structuring the firing logic to demonstrate full mastery of the system's architecture. The project was praised for its technical robustness and for exceeding the basic requirements through its modular level selection and high-fidelity UI.

## 🚀 Setup & Execution
The repository is **Self-Contained**. For Windows users, the required `.dll` is included to allow execution without complex environment setups.

### 1. Prerequisites
* **GCC Compiler** (MinGW recommended for Windows).
* **Allegro 5.0.10** Development libraries (if recompiling from source).

### 2. Installation & Running
1.  Clone the repository.
2.  Ensure `allegro-5.0.10-monolith-mt.dll`, `battle.ogg`, and `Heroes Legend.ttf` remain in the root folder.
3.  **To Compile:**
    ```bash
    make
    ```
4.  **To Play:** Run the `space_invaders_engine.exe` (or your compiled binary).

## 🎮 Controls
* **A / D:** Horizontal Movement.
* **Spacebar:** Standard Cannon Fire.
* **C:** Special Fire (requires active Power-up).
* **Mouse:** Navigate menus and select difficulty levels.

---
> **Note:** This project is preserved in its original form as a testament to my technical foundation in Computer Science and Aerospace Engineering.