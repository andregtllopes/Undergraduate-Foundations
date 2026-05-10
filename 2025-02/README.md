# Semester 2025/02: Aerospace Core Consolidation and Advanced Software Engineering

This semester represented a critical inflection point in my academic trajectory, marking the culmination of foundational aerospace theory with advanced computational modeling and software development practices. It combines rigorous aeronautical engineering with industrial-grade programming methodologies, establishing the technical competencies essential for aerospace R&D and autonomous systems development.

## 📌 Overview

The focus of this period was the mastery of **Flight Dynamics Simulation**, **Aerodynamic Theory** (from potential flow to boundary layer effects), and **Manufacturing Processes** within the aerospace core, while simultaneously advancing software architecture through systematic development practices. This semester solidified the role of computational simulation as the primary tool for aircraft design, control analysis, and thermal-fluid system optimization.

## 🛠️ Key Academic Focus

### Aerospace Core Disciplines

**Aerodynamics (EMA254):** Comprehensive transition from potential flow theory to physical reality through advanced aerodynamic modeling.
- **Finite Wing Theory:** Application of Prandtl's Lifting Line Theory to compute wing efficiency factors and induced drag in three-dimensional flow fields.
- **Boundary Layer Theory:** Analysis of laminar and turbulent boundary layer development, including separation criteria and wall shear stress calculations.
- **Aerodynamic Coefficients:** Development of empirical and theoretical models for lift, drag, and pitching moment across the complete flight envelope.
- **Physical Interpretation:** Extraction of fundamental aerodynamic principles necessary for aircraft design and performance prediction.

**Flight Mechanics (EMA250):** Complete modeling of aircraft as rigid bodies in three-dimensional space.
- **6-Degree-of-Freedom Dynamics:** Formulation and integration of Euler-Newton equations of motion with full state representation: linear velocities (u, v, w), angular rates (p, q, r), Euler angles (φ, θ, ψ), and position (x, y, h).
- **Linearized Equations:** Development of perturbation models around trim conditions for stability and control analysis.
- **Trim Analysis:** Automated calculation of equilibrium states across the operational envelope via moment balance and constraint enforcement.
- **Stability Derivatives:** Extraction of aerodynamic derivatives (CLα, CMα, CMq, etc.) essential for predicting aircraft response to disturbances and control inputs.
- **Eulerian Simulation:** Implementation of time-domain integration schemes for non-linear flight dynamics and transient response prediction.

**Manufacturing Processes (EMA249):** Advanced metallurgy and material processing fundamentals critical for aerospace structures.
- **Phase Diagrams:** Exhaustive study of the Iron-Carbon phase diagram, including austenite, ferrite, cementite, and pearlite phases.
- **Phase Transformations:** Analysis of martensitic and bainitic transformations, with implications for hardness, strength, and toughness in structural steels.
- **Mechanical Forming Processes:** Analysis of forging, rolling, and extrusion under stress-strain states, with emphasis on material flow and microstructural evolution.
- **Material Selection:** Integration of physical metallurgy knowledge with design constraints for aerospace component fabrication.

### Software Development (PDS2) — Advanced Practices

**Programming & Software Development II (DCC204):** Transition from functional programming to systematic software engineering.

- **Software Correctness & Testing:** Implementation of rigorous development cycles based on formal specifications, exhaustive test case generation, unit testing frameworks, and systematic debugging strategies (identification and mitigation of syntax, logic, and runtime errors).

- **Defensive Programming & Robustness:** Validation of function inputs and parameters, exception handling, and prevention of critical failures (stack overflow, memory leaks) to ensure production-grade software reliability.

- **Architecture & Design Patterns:** Introduction to version control systems (Git), API design, modular libraries, and best practices in abstraction, encapsulation, and information hiding. Continuous refactoring for code quality improvement.

- **Data Structures & Memory Management:** In-depth study of dynamic memory allocation, linked lists, doubly-linked lists, and binary trees. Understanding memory hierarchy (primary, secondary, virtual) and reference locality for high-performance algorithm development.

- **Object-Oriented Programming (OOP):** Transition to object-oriented paradigm with classes, attributes, and methods. Introduction to inheritance and polymorphism as foundations for scalable, modular system architecture.

---

# 🚀 Noteworthy Academic Projects

## ✈️ CB-07 Vesper: Flight Dynamics Simulation & Control Analysis

A comprehensive **6-DOF flight dynamics simulator** developed in Python for the ultralight aircraft *Vesper CB-07*, integrating aerodynamic data from AVL (Athena Vortex Lattice) with rigid-body mechanics.

### Technical Achievements:
- **Trim Analysis Pipeline:** Automated longitudinal equilibrium calculation across the operational envelope (78–230 km/h), extracting stability derivatives and control effectiveness parameters.
- **Aerodynamic Integration:** Coupling of AVL-generated aerodynamic coefficients with non-linear 6-DOF equations of motion.
- **Control Analysis:** Implementation of pulse and doublet input generators for frequency response characterization and pilot-induced oscillation (PIO) assessment.
- **Real-World Data:** Incorporation of actual aircraft mass properties (740 kg maximum case) and local gravity correction (Belo Horizonte, MG).

### Engineering Impact:
Provides the mathematical foundation for autopilot design, handling qualities assessment, and certification of flight envelope margins. Enables rapid evaluation of control law modifications without costly flight testing.

---

##  Thermal Laboratory: Convection & Radiation Experiments

A rigorous **experimental heat transfer characterization** framework demonstrating natural convection, forced convection, and radiation phenomena with uncertainty propagation.

### Technical Achievements:
- **Automatic Uncertainty Propagation:** Implementation of first-order Taylor expansion for error analysis across all derived quantities (power, heat flux, convection coefficient).
- **Thermodynamic Property Integration:** Seamless integration with **CoolProp** database for accurate air properties (viscosity, density, Prandtl number, thermal conductivity) at film temperature.
- **Dimensionless Number Characterization:** Computation of Rayleigh, Grashof, Reynolds, and Nusselt numbers for regime classification and correlation validation.
- **Three Independent Experiments:** 
  - Natural convection validation against Morgan correlation
  - Forced convection verification using Churchill-Bernstein equation
  - Combined convection + radiation heat transfer decomposition
- **Laboratory Automation:** Data reduction pipeline with automatic plot generation and statistical summary reporting.

### Engineering Impact:
Provides experimental validation of classical heat transfer correlations under controlled laboratory conditions (Belo Horizonte: 692 mbar, g = 9.78 m/s²). Quantifies measurement uncertainty sources and establishes reproducible experimental methodology for future thermal characterization studies.

---

##  Finite Difference Method: 2D Heat Transfer Solver

A production-grade **numerical PDE solver** for steady-state 2D heat conduction with mixed boundary conditions and internal heat sources.

### Technical Achievements:
- **Adaptive Mesh Generation:** Structured grid creation with configurable aspect ratio and non-uniform spacing for boundary layer refinement.
- **FDM Discretization:** Second-order central difference approximations of Laplacian operator with coefficient formulation for interior and boundary points.
- **Mixed Boundary Conditions:** Dirichlet (fixed temperature), Neumann (prescribed flux), and Robin (convective) boundary conditions with ghost cell extrapolation.
- **Sparse System Assembly:** Matrix formation for elliptic PDE with pentadiagonal sparsity pattern; capability for dense or sparse matrix solvers.
- **Parametric Studies:** Convergence analysis (h-refinement), sensitivity to thermal conductivity and convection parameters, and verification against analytical solutions.

### Engineering Impact:
Rapid prototyping tool for thermal design validation of composite structures with spatially-varying heat sources. Enables optimization of cooling strategies and materials selection without iterative experimental cycles.

---

## 🧮 Advanced Software Projects: Data Structures & Algorithms

Implementation of production-grade code with rigorous testing and architectural best practices, demonstrating mastery of defensive programming and OOP principles in complex problem domains.

### Competencies Demonstrated:
- Comprehensive test case design and unit testing frameworks
- Memory-safe implementations with dynamic data structures
- Modular API design with clear separation of concerns
- Refactoring strategies for progressive code quality improvement
- Exception handling and error recovery mechanisms

---

# 💼 Engineering & Research Competencies Developed

## Theoretical Foundations
- **Aerodynamic Modeling:** From classical lifting line theory to modern CFD-equivalent correlation methods
- **Dynamical Systems:** Linearization, stability analysis (Routh-Hurwitz), and frequency response characterization
- **Thermal-Fluid Systems:** Heat transfer mechanisms, boundary layer effects, and property-dependent transport phenomena

## Computational Skills
- **6-DOF Flight Simulation:** Euler angle kinematics, rigid body dynamics, and aerodynamic coupling
- **Numerical Methods:** Finite difference discretization, sparse matrix solvers, and convergence analysis
- **Data Processing:** Uncertainty quantification, property database integration (CoolProp), and automated report generation

## Software Engineering Practices
- **Modular Architecture:** Clean separation of physics engine, user interface, and data I/O layers
- **Robust Implementation:** Defensive input validation, exception handling, and memory safety
- **Version Control & Collaboration:** Git-based workflow with semantic commit messages and branch management

---

# 📊 Semester Structure & Project Organization

```
2025-02/
├── CB-07-Vesper-Simulation-Project/
│   ├── Python/
│   │   ├── Analise_Trimagem.ipynb           # Trim analysis and stability curves
│   │   ├── simulacoes.ipynb                 # Interactive 6-DOF flight simulation
│   │   └── simulacoes.py                    # Modular physics engine
│   ├── AVL/
│   │   ├── vesper.avl                       # Aircraft geometry definition
│   │   └── vesper_740kg.mass                # Mass and inertia properties
│   ├── Relatorio_CB_07_Vesper.pdf           # Complete technical report
│   └── README.md                            # Project documentation
│
├── Termo-Lab-Experiments/
│   ├── experimento1.ipynb                   # Natural convection analysis
│   ├── experimento2.ipynb                   # Forced convection analysis
│   ├── experimento3.ipynb                   # Combined convection + radiation
│   ├── PDFfiles/                            # Supporting documentation
│   └── README.md                            # Project documentation
│
├── FDM-Solver/
│   ├── trabalhocomsolve.ipynb               # Finite difference method solver
│   ├── TRABALHO_DE_LABTERMO.pdf             # Technical report
│   └── README.md                            # Project documentation
│
└── README.md                                # This semester overview
```

---

# 🧠 Strategic Perspective

This semester marks the maturation of my **dual competency in Aerospace Engineering and Computer Science**. The integration of:
- Advanced aeronautical theory (flight dynamics, aerodynamics, materials)
- Computational engineering (numerical methods, simulation, data processing)
- Software craftsmanship (systematic testing, architecture, defensive programming)

...establishes the technical foundation for autonomous aerospace systems, control law development, and advanced R&D methodologies. The successful execution of complex projects—from CFD-equivalent aerodynamic modeling to thermal design optimization—demonstrates readiness for professional-level aerospace software development and research contributions.

The emphasis on **reproducible science** (uncertainty propagation, validation against theory, automated reporting) and **industrial-grade code quality** (modular architecture, comprehensive testing, version control) reflects a mature engineering mindset aligned with modern best practices in aerospace companies and research laboratories.

---

