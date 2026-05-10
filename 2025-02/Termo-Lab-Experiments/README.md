# Thermal Laboratory Experiments: Convection & Radiation Analysis

## 📌 Project Overview

This project presents a comprehensive **Experimental Heat Transfer Analysis** framework for the **Thermal Laboratory (LABTERM)** at **UFMG**. The repository contains three independent experimental investigations into **natural convection**, **forced convection**, and **radiation heat transfer** from a resistively heated wire, with rigorous uncertainty propagation and property evaluation using industrial thermodynamic databases.

The repository demonstrates the application of classical heat transfer correlations (Nusselt, Grashof, Rayleigh numbers), experimental data reduction with propagated measurement uncertainties, and validation against theoretical predictions.

---

# 🛠️ Technical Pipeline

The experimental framework is structured around five computational stages:

## 1. Data Acquisition & Processing
Experimental measurements recorded in tabulated form with associated uncertainties:

**Measured Parameters:**
- **Voltage (V_ab):** ±3% precision (electrical power input)
- **Current (I):** ±3% precision (electrical power input)
- **Wire Length (L):** ±0.5 mm (geometric dimension)
- **Wire Diameter (d):** ±0.1 mm (geometric dimension)
- **Surface Temperature (T_s):** Three thermocouple readings, ±1 K uncertainty each
- **Ambient Temperature (T_amb):** Two thermocouple readings, ±1 K uncertainty each

All measurements are stored as **UFLoat objects** (uncertain floats) via the `uncertainties` package, enabling automatic error propagation throughout calculations.

## 2. Property Retrieval via CoolProp
Integration of the **CoolProp thermodynamic database** for accurate air properties at the film temperature:

$$T_{film} = \frac{T_s + T_{amb}}{2}$$

Properties retrieved:
- **Dynamic Viscosity (μ):** Pa·s
- **Density (ρ):** kg/m³
- **Thermal Conductivity (k):** W/(m·K)
- **Specific Heat (c_p):** J/(kg·K)
- **Prandtl Number (Pr):** Dimensionless

**Advantages:**
- Eliminates manual property table interpolation errors
- Automatically accounts for non-ideal gas behavior at high pressures
- Valid across wide temperature and pressure ranges

## 3. Heat Transfer Rate Calculation
Electrical power dissipation in the wire:

$$\dot{Q} = V_{ab} \cdot I \, [\text{W}]$$

Surface heat flux:
$$q'' = \frac{\dot{Q}}{A_s} = \frac{\dot{Q}}{\pi d L} \, [\text{W/m}^2]$$

Temperature difference:
$$\Delta T = T_s - T_{amb} \, [\text{K}]$$

All intermediate calculations propagate uncertainties using first-order Taylor expansion:
$$\sigma_Q^2 = \left(\frac{\partial Q}{\partial V}\right)^2 \sigma_V^2 + \left(\frac{\partial Q}{\partial I}\right)^2 \sigma_I^2 + \ldots$$

## 4. Dimensionless Group Characterization
Classification of heat transfer regime via dimensionless numbers:

### Natural Convection (Experiment 1)
**Rayleigh Number:**
$$Ra_L = \frac{g \beta (T_s - T_{amb}) L^3}{\nu \alpha} = Gr_L \cdot Pr$$

Where:
- **g:** Local gravitational acceleration (9.78 m/s² at Belo Horizonte)
- **β:** Volumetric thermal expansion coefficient
- **ν:** Kinematic viscosity [m²/s]
- **α:** Thermal diffusivity [m²/s]

**Flow Regime:**
- $Ra_L < 10^4$: Laminar natural convection
- $10^4 < Ra_L < 10^9$: Transitional
- $Ra_L > 10^9$: Turbulent natural convection

### Forced Convection (Experiment 2)
**Reynolds Number:**
$$Re_d = \frac{V_{air} \cdot d}{\nu}$$

**Nusselt Number (Churchill-Bernstein Correlation for cylinder):**
$$Nu_d = 0.3 + \frac{0.62 \, Re_d^{0.5} Pr^{1/3}}{[1 + (0.4/Pr)^{2/3}]^{1/4}} \left[1 + \left(\frac{Re_d}{282000}\right)^{5/8}\right]^{4/5}$$

### Radiation (All Experiments)
**Radiative Heat Transfer:**
$$\dot{Q}_{rad} = \epsilon \sigma A_s (T_s^4 - T_{amb}^4)$$

Where:
- **ε:** Emissivity of wire surface (0.56 for oxidized steel)
- **σ:** Stefan-Boltzmann constant ($5.67 \times 10^{-8}$ W/(m²·K⁴))

## 5. Experimental vs. Theoretical Comparison
Calculation of **convection coefficient (h_exp)** from energy balance:

$$h_{exp} = \frac{\dot{Q}}{A_s \Delta T}$$

Comparison with theoretical correlation:
$$h_{theory} = \frac{k}{d} Nu_d$$

**Error Analysis:**
$$\text{Percent Error} = \frac{|h_{exp} - h_{theory}|}{h_{theory}} \times 100\%$$

Uncertainties in both experimental and theoretical values are reported with confidence intervals.

---

# 📊 Experimental Conditions & Specifications

### Test Apparatus
- **Heating Element:** Nichrome wire (Ø ~25 mm, L ~194 mm)
- **Temperature Measurement:** Type K thermocouples (±1 K), 3 surface stations
- **Power Supply:** DC regulated source (±3% voltage and current control)
- **Environmental Chamber:** Open laboratory at Belo Horizonte (P_atm ≈ 692 mbar)

### Experiment Variants

| Experiment | Configuration | Objective |
|---|---|---|
| **Exp 1** | Natural Convection | Validate Rayleigh correlation for vertical cylinder |
| **Exp 2** | Forced Convection | Characterize Churchill-Bernstein transition |
| **Exp 3** | Combined Convection + Radiation | Total heat transfer partitioning |

### Local Conditions (Belo Horizonte, MG)
- **Altitude:** ~850 m above sea level
- **Atmospheric Pressure:** ~692 mbar (92.3 kPa)
- **Local Gravity:** g = 9.78 m/s²
- **Reference Temperature (Ambient):** ~24–25°C

---

# 💼 Engineering Impact

- **Correlation Validation:** Experimental data confirm classical empirical correlations under controlled laboratory conditions.
- **Property Sensitivity:** Demonstrate how air properties (μ, ρ, Pr) vary with temperature and affect heat transfer rates.
- **Measurement Uncertainty Quantification:** Rigorous error propagation reveals dominant sources of uncertainty (power measurement vs. geometry).
- **Data Reduction Methodology:** Provides a reproducible framework for future thermal experiments with automated uncertainty tracking.

---

# 🚀 Setup & Reproducibility

The experimental analysis notebooks are self-contained with configurable experiment variants and automated plotting.

## 1. Prerequisites

- **Python 3.10+**
- **NumPy** (Numerical arrays)
- **Matplotlib** (2D visualization)
- **CoolProp** (Thermodynamic property database)
- **uncertainties** (Automatic error propagation)

## 2. Installation

```bash
pip install numpy matplotlib scipy CoolProp uncertainties
```

## 3. Project Structure

```
Termo-Lab-Experiments/
├── experimento1.ipynb                 # Natural convection experiment
├── experimento2.ipynb                 # Forced convection experiment
├── experimento3.ipynb                 # Combined convection + radiation
├── PDFfiles/                          # Supporting documentation
└── README.md                          # This file
```

## 4. Execution Workflow

### Step 1: Environment Setup
1. Install required packages (see above)
2. Verify CoolProp installation:
   ```python
   import CoolProp.CoolProp as CP
   mu = CP.PropsSI('V', 'T', 300, 'P', 101325, 'Air')  # Should return ~1.84e-5
   ```

### Step 2: Select Experiment
1. Open the desired notebook (`experimento1.ipynb`, `experimento2.ipynb`, or `experimento3.ipynb`)
2. Verify that the `v` flag selects the correct experimental run (e.g., `v = 1` or `v = 2`)

### Step 3: Input Experimental Data
1. Locate the **measured data dictionary** in the notebook
2. Update values based on laboratory measurements:
   ```python
   dados_medidos = {
       "V_ab": ufloat(30.0, 30.0 * 0.03),      # Voltage ±3%
       "I": ufloat(0.369, 0.369 * 0.03),       # Current ±3%
       "L": ufloat(194.0, 0.5),                # Length ±0.5 mm
       "d": ufloat(25.5, 0.1),                 # Diameter ±0.1 mm
       "T_s1_leituras": [ufloat(80.5, 1.0), ...],  # Surface temps (3 readings)
       "T_amb_leituras": [ufloat(24.7, 1.0), ...] # Ambient temps (2 readings)
   }
   ```
3. Run data processing cells to compute averages and standard errors

### Step 4: Property Retrieval
1. Execute cells that compute **T_film** (film temperature)
2. CoolProp automatically queries air properties at local conditions:
   ```python
   def obter_propriedades_ar(T_filme_K, P_pascal):
       mu = CP.PropsSI('V', 'T', T_nom, 'P', P_pascal, 'Air')
       rho = CP.PropsSI('D', 'T', T_nom, 'P', P_pascal, 'Air')
       Pr = CP.PropsSI('Prandtl', 'T', T_nom, 'P', P_pascal, 'Air')
       return mu, rho, Pr
   ```

### Step 5: Heat Transfer Calculation
1. Run cells to compute:
   - Electrical power **Q̇ = V·I**
   - Surface area **A_s = π·d·L**
   - Heat flux **q'' = Q̇/A_s**
   - Experimental convection coefficient **h_exp = Q̇/(A_s·ΔT)**

### Step 6: Dimensionless Characterization
1. Compute **Ra, Gr, Pr** (natural convection) or **Re, Nu** (forced convection)
2. Evaluate theoretical correlations
3. Compare **h_exp vs. h_theory** with uncertainty bands

### Step 7: Visualization & Reporting
1. Generate plots:
   - Power vs. temperature rise
   - Convection coefficient vs. temperature
   - Nusselt vs. Rayleigh/Reynolds
   - Error comparison
2. Log all results with propagated uncertainties
3. Export summary tables (CSV or Excel)

---

# ✅ Validation & Test Cases

Each experiment includes reference comparison against published correlations:

### Natural Convection (Exp 1)
**Correlation:** Morgan correlation for vertical cylinders (vertical extent >> diameter)
$$Nu_L = 0.671 \, Ra_L^{0.25}$$

### Forced Convection (Exp 2)
**Correlation:** Churchill-Bernstein equation for single cylinder in cross-flow
(See Section 4 for full form)

### Combined (Exp 3)
**Total Heat Transfer Decomposition:**
$$\dot{Q}_{total} = \dot{Q}_{conv} + \dot{Q}_{rad}$$

Fraction of radiation typically 5–15% for lab conditions.

---

# 📈 Advanced Features

- **Monte Carlo Uncertainty:** Optional: replace first-order propagation with Monte Carlo sampling (1000 trials) for non-linear effects
- **Property Sensitivity:** Parametric study showing impact of air property variation on **Nu**
- **Iterative Film Temperature:** Refinement loop for film temperature calculation (T_film depends on h, which depends on T_film)
- **Batch Processing:** Process multiple experiment runs in sequence with automated report generation

---

# 🔄 Data Flow Diagram

```
Raw Measurements (V, I, L, d, T_s, T_amb)
       ↓
Uncertainty Encoding (UFLoat)
       ↓
Derived Quantities (Q̇, A_s, q'', ΔT)
       ↓
CoolProp Property Query (μ, ρ, Pr, k)
       ↓
Dimensionless Numbers (Ra, Gr, Re, Nu)
       ↓
Correlation Evaluation (h_theory)
       ↓
Experimental h Calculation (h_exp)
       ↓
Error Analysis & Visualization
       ↓
Summary Report with Uncertainty Bands
```

---

> [!NOTE]
> **CoolProp Database:** Always verify that the atmospheric pressure (692 mbar at Belo Horizonte) is correctly specified in property queries. Standard atmosphere (101.325 kPa) may introduce errors.

> [!IMPORTANT]
> **Radiation Effects:** For natural convection experiments at low temperatures, radiation typically contributes <10% of total heat transfer. However, at high surface temperatures (>80°C), radiation can exceed convection; ensure proper decomposition in Experiment 3.

> [!TIP]
> **Iterative Property Evaluation:** Properties should be evaluated at film temperature **T_film = (T_s + T_amb) / 2**. If h depends on properties, implement an iterative refinement loop until convergence.
