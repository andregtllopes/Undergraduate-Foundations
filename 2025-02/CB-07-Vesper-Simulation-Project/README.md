# CB-07 Vesper Flight Dynamics Simulation

## 📌 Project Overview

This project presents a comprehensive **Flight Dynamics Simulation and Control Analysis** tool for the **CB-07 Vesper**, a lightweight aircraft designed for ultralight aviation research. Developed for the **Aeronautical Engineering Laboratory** at **UFMG**, the simulation provides detailed 6-degree-of-freedom (6-DOF) flight dynamics analysis using coupled aerodynamic coefficients and real aircraft geometry data.

The repository demonstrates the application of rigid-body mechanics, aerodynamic modeling using AVL (Athena Vortex Lattice), trim analysis, and stability derivatives to predict aircraft behavior across the complete flight envelope (**78 km/h stall to 230 km/h cruise**).

---

# 🛠️ Technical Pipeline

The simulation framework is built as a modular Python-based system, encompassing five key simulation stages:

## 1. Geometric Modeling & Aerodynamic Database
Integration of aircraft geometry (**vesper.avl**) and mass properties (**vesper_740kg.mass**) from AVL preprocessor. This stage generates aerodynamic coefficients (lift, drag, pitching moment) and stability derivatives across the operational envelope.

## 2. Trim Analysis & Equilibrium Calculation
Automated longitudinal trim analysis that iterates through discrete velocity points using the AVL solver. For each velocity, the algorithm:
- Enforces **Level Flight** constraint
- Computes equilibrium **angle of attack (α)** and **elevator deflection (δe)** via moment balance
- Extracts the **lift coefficient (CL)** and pitching moment derivatives

## 3. 6-DOF Equations of Motion
Implementation of Euler-Newton rigid body dynamics with twelve state variables:

$$\mathbf{x} = [u, v, w, p, q, r, \phi, \theta, \psi, x, y, h]$$

Where:
- **(u, v, w):** Velocity components in body-fixed frame [m/s]
- **(p, q, r):** Angular rates [rad/s]
- **(φ, θ, ψ):** Euler angles [rad]
- **(x, y, h):** Position in earth-fixed frame [m]

## 4. Aerodynamic Coefficient Expansion
Taylor series linearization of non-linear aerodynamic effects around trim conditions:

$$C_L = C_{L,ref} + C_{L_\alpha} \Delta\alpha + C_{L_{\delta_e}} \Delta\delta_e + C_{L_q} \hat{q}$$

This approach captures **longitudinal stability** and **control effectiveness** across the flight envelope.

## 5. Control Input Generation & Perturbation Analysis
Two types of pilot inputs are simulated:
- **Pulse:** Single-step control surface deflection
- **Doublet:** Symmetrical deflection pair for frequency response analysis

The system supports **aileron**, **elevator**, and **rudder** perturbations with configurable amplitude and timing.

---

# 📊 Aircraft Specifications

### Physical Characteristics
- **Empty Weight:** 150 kg (estimated)
- **Gross Weight (Design Case):** 740 kg
- **Wing Area:** ~11.5 m²
- **Wing Span:** ~12.0 m
- **Mean Aerodynamic Chord:** ~1.0 m

### Operational Envelope
- **Stall Velocity:** 78 km/h (21.67 m/s)
- **Cruise Velocity:** 100–150 km/h
- **Never Exceed (V_NE):** 230 km/h (63.89 m/s)

### Reference Conditions (Local)
- **Density (ρ):** 1.225 kg/m³ (sea level, ISA)
- **Gravity (g):** 9.78 m/s² (Belo Horizonte, MG)

---

# 💼 Engineering Impact

- **Stability Prediction:** Longitudinal stability margins are quantified across the flight envelope, guiding control law design.
- **Control Authority Analysis:** Elevator effectiveness derivatives inform autopilot tuning requirements.
- **Transient Response:** Doublet and pulse simulations reveal time-domain behavior (damping, frequency, overshoot) critical for pilot control assessment.
- **Envelope Validation:** Ensures aircraft remains within safe operating margins from stall to maximum speed.

---

# 🚀 Setup & Reproducibility

The simulation framework is modular and self-contained. All critical parameters are pre-configured for the Vesper test case.

## 1. Prerequisites

- **Python 3.10+**
- **NumPy** (Numerical arrays and linear algebra)
- **SciPy** (ODE integration via `solve_ivp`)
- **Matplotlib** (2D trajectory and response plotting)
- **AVL 3.36+** (For aerodynamic database generation)

## 2. Installation

```bash
pip install numpy scipy matplotlib
```

For AVL integration (optional), ensure the AVL binary is available and the path is correctly specified in `Analise_Trimagem.ipynb`.

## 3. Project Structure

```
CB-07-Vesper-Simulation-Project/
├── Python/
│   ├── Analise_Trimagem.ipynb          # Trim analysis and stability curves
│   ├── simulacoes.ipynb                # Interactive 6-DOF flight simulation
│   └── simulacoes.py                   # Modular physics engine (importable)
├── AVL/
│   ├── vesper.avl                      # Geometry definition
│   ├── vesper_740kg.mass               # Mass and inertia properties
└── Relatorio_CB_07_Vesper.pdf          # Complete technical report
```

## 4. Execution Workflow

### Step 1: Trim Analysis
1. Open `Analise_Trimagem.ipynb`
2. Configure the AVL binary path (absolute path to `avl.exe`)
3. Run all cells to generate trim curves (**α, δe, CL** vs. velocity)
4. Output: Equilibrium database stored in Python dictionaries

### Step 2: Dynamic Simulation
1. Open `simulacoes.ipynb`
2. Load the trim data from Step 1
3. Define simulation parameters:
   - Input type: `'pulse'` or `'doublet'`
   - Control surface: `'aileron'`, `'elevator'`, or `'rudder'`
   - Amplitude: degrees of deflection
4. Execute integration cells to compute 6-DOF response
5. Visualize: Velocity, attitude angles, and trajectory plots

### Step 3: Batch Simulations (Optional)
Use `simulacoes.py` as a library:

```python
from simulacoes import equations_of_motion
from scipy.integrate import solve_ivp

# Define initial state and config
state0 = [25.0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000]  # [u, v, w, p, q, r, φ, θ, ψ, x, y, h]
config = {...}  # Trim data and derivatives

# Integrate
sol = solve_ivp(equations_of_motion, [0, 60], state0, args=(config, sim_type), dense_output=True)
```

---

# ✅ Validation & Test Cases

The notebook includes reference test cases against known stability criteria:

- **Longitudinal Stability:** Positive **C_Mα** (pitch stiffness) ensures recovery from disturbances.
- **Control Power:** Elevator effectiveness (**C_Mδe**) is sufficient for full trim envelope.
- **Frequency Response:** Natural frequencies and damping ratios are extracted from doublet responses.

---

> [!NOTE]
> **AVL Integration:** The trim analysis automates AVL execution via subprocess calls. Ensure the AVL binary path matches your system configuration. On Windows, use absolute paths or modify `subprocess` calls accordingly.

> [!IMPORTANT]
> **Mass Properties:** The current configuration uses **740 kg** (maximum design case). For different loading scenarios, edit `vesper_740kg.mass` and regenerate trim curves.
