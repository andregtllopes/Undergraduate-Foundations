# Höppler Viscometer: Design, Simulation, and Optimization

## 📌 Project Overview

This project presents a professional Engineering simulation and R&D tool for the design of a **Höppler Falling Ball Viscometer**. Developed for the **Fluid Mechanics Laboratory (TEA2)** at **UFMG**, the goal was to design an instrument capable of measuring fluid viscosities between **0.6 mPa.s and 60 mPa.s** using a specific laboratory tube (**600 mm length, 22 mm internal diameter**).

The repository demonstrates the application of classical fluid dynamics, wall-effect corrections, and numerical optimization to identify the ideal sphere materials and diameters for high-precision measurements.

---

# 🛠️ Technical Pipeline

The simulation was built using a modular pipeline in Python, divided into five logical stages:

## 1. Core Physics Engine
Implementation of terminal velocity calculations based on the balance of weight, buoyancy, and viscous drag (**Stokes Flow**).

## 2. Faxén Wall Correction
Integration of boundary layer correction factors to account for the proximity of the **22 mm** tube walls, which significantly impacts velocity in narrow geometries.

## 3. Feasibility Grid Mapping
Automated generation of **Feasibility Maps** that iterate through thousands of diameter/viscosity combinations to find the **optimal operating window**.

## 4. Constraint Logic
Real-time verification of laboratory criteria:

- **Reynolds Number:** Monitoring the transition from laminar to turbulent flow.
- **Acceleration Distance:** Ensuring terminal velocity is reached within the required threshold.
- **Measurement Path:** Guaranteeing at least **40 cm** for manual timing.
- **Human Factor:** Ensuring measurement times fall between **3 s and 600 s** for manual stopwatch accuracy.

## 5. Diameter Optimizer
An algorithm that searches for a single sphere diameter capable of covering the entire target viscosity range (**0.6 – 60 mPa.s**) for a given material.

---

# 📊 Logic & "Lab Reality" Factor

A key differentiator of this project is its **pragmatic approach to laboratory constraints**.

While theoretical physics often demands a Reynolds number strictly below **1.0**, the **"Lab Reality"** logic in this script allows for adjustments (up to **Re < 2400**) to identify viable measurement points that would otherwise be considered **impossible** under standard equipment limitations.

---

# 💼 Engineering Impact

- **Material Selection:** The tool identified that **PEAD (High-Density Polyethylene)** is the superior choice for low-viscosity fluids (like water), whereas **Stainless Steel** is unsuitable for the target range due to excessive fall speeds.
- **Design Validation:** Provided a mathematical foundation for the mechanical drawings and material procurement phase of the laboratory project.
- **Error Mitigation:** By simulating the acceleration distance, the project prevents measurement errors caused by timing the sphere before it reaches terminal velocity.

---

# 🚀 Setup & Reproducibility

The notebook is designed to be **self-contained**. All physical constants (**local gravity in Belo Horizonte, tube dimensions**) are pre-configured.

## 1. Prerequisites

- **Python 3.10+**
- **NumPy** (Numerical arrays)
- **Matplotlib** (Visualization)

## 2. Installation

```bash
pip install numpy matplotlib
```

## 3. Execution

1. Open the `hoppler_viscometer_optimization_UFMG.ipynb` notebook.
2. Run **Block 1 & 2** to initialize the environment and physical constants.
3. Run **Block 3 to 5** to load the calculation engine and plotting tools.
4. Execute **Block 6** to generate the Feasibility Maps for **PEAD**, **Glass**, and **Stainless Steel**.

---

# ✅ Validation Case

The script includes a **Test Case Block (Block 7)** using the specific laboratory values described in the final report to validate the math against known experimental results, providing a detailed log of every physical metric calculated.

---

> [!NOTE]
> **Faxén Correction:** The script uses a **5th-order polynomial** for Faxén's correction, which is essential when the ratio of sphere diameter to tube diameter exceeds **0.1**.
