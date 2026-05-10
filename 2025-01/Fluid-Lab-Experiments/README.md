# Fluid-Lab_experiments: Experimental Fluid Mechanics & Technical Computing

This repository contains the complete set of experimental reports and computational analyses developed for the **Fluid Mechanics Laboratory (TEA2)** course during the **2025.1** semester at the **Federal University of Minas Gerais (UFMG)**.

## 📌 Overview
The project documents the characterization of hydraulic and pneumatic systems—including centrifugal pumps, blowers, and flow measurement devices—through rigorous laboratory testing. The core differentiator of this repository is the complete automation of data processing: for every experiment, a Python-based workflow was developed to handle SI unit conversions, fetch real-time thermophysical properties, and perform automated uncertainty propagation.

## 🛠️ Key Academic Focus
* **Hydrodynamics & Turbomachinery:** Performance study of centrifugal pumps in series and parallel configurations, as well as centrifugal blowers.
* **Metrology & Uncertainty Analysis:** Rigorous implementation of error propagation for all physical measurements (pressure, flow rate, frequency) using the `uncertainties` library.
* **Computational Thermophysics:** Integration with the `CoolProp` library to obtain high-accuracy density and viscosity values for air and water based on real-time ambient conditions.
* **Technical Standardization:** Application of iterative numerical methods to calculate discharge coefficients (Cd) for orifice plates according to the **ISO 5167** standard.

## 🚀 Highlighted Project
* **[Blower Similarity Laws (Rateau)](./blower_similarity_laws.ipynb):** This project validates Rateau's Similarity Laws by predicting a blower's performance at 60 Hz using data acquired at 30 Hz. The implementation features an iterative solver for the Reynolds number and friction factor, ensuring scientific convergence and immediate theoretical validation of experimental results.

## 📂 Repository Structure
| File | Description |
| :--- | :--- |
| `centrifugal_pump_analysis` | Characterization of H-Q curves for individual pumps and comparison with manufacturer data. |
| `centrifugal_pump_arrangements_analysis` | Performance analysis of pumps operating in series and parallel associations. |
| `drag_flow_analysis` | Determination of mass flow rate via drag on a confined sphere vs. orifice plate methods. |
| `blower_similarity_laws` | Centrifugal blower characterization and validation of similarity laws (Rateau). |

---