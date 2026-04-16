# Linear Systems Solver: Lower Triangular Systems (DCC001)

This repository contains my **very first programming project**, developed during the second semester of my Aerospace Engineering degree at UFMG (2023/2). It marks the beginning of my journey into computational engineering and algorithmic thinking.

## 📌 Context
Developed as part of the *Introduction to Programming* course, this project focuses on the intersection of Linear Algebra and Computer Science. It was my first hands-on experience translating mathematical models into executable code.

## 🛠️ Mathematical Implementation
The solver is designed to process systems of the form $Lx = b$, where $L$ is a lower triangular matrix. It utilizes the **Forward Substitution** method:

$$X_i = \frac{B_i - \sum_{j=1}^{i-1} L_{ij}X_j}{L_{ii}}$$

## 🚀 Key Features
* **Input Validation:** Robust handling of user inputs to ensure only real numbers are processed.
* **Convergence Guarantee:** Automated check for non-zero values on the main diagonal to prevent division by zero and ensure system solvability.
* **Scientific Formatting:** Results are presented with three-decimal precision for technical clarity.

## 💻 How to Run

This project is a **Jupyter Notebook** (.ipynb). Since the program is interactive and relies on standard Python `input()` functions, it is best experienced in a live environment.

1. **Clone the repository:**
   ```bash
   git clone https://github.com/andregtllopes/Undergraduate-Foundations.git
2. **Navigate to the project folder:**
   ```bash
   cd 2023-02/Numerical-Methods-Linear-Systems
3. **Run the Notebook:**
   Open the file in VS Code, Jupyter Lab, or Google Colab.
4. **Execution:**
   Simply run the cells. The program will prompt you for the number of equations and the specific coefficients in the terminal/console.

**First-Principles Note:** This implementation uses only standard Python. No external dependencies or libraries (such as NumPy) are required, keeping the code strictly tied to the fundamental mathematical logic.

## 🧠 Lessons Learned
Being my first project, it was fundamental for understanding:
1. The importance of **First-Principles** (understanding the math before the code).
2. Basic data structures (nested lists representing matrices).
3. The necessity of predicting and handling user errors (Edge Case testing).
