# Critical Path Optimizer

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)

A program to calculate and optimize the critical path in a processor network, allowing for high-speed processor replacements to minimize completion time.

## Table of Contents
- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Folder Structure](#folder-structure)
- [Contributing](#contributing)
- [License](#license)

## Overview
The Critical Path Optimizer is designed to calculate the minimum completion time for a processor network. It supports iterative optimization by replacing processors with high-speed alternatives, up to a specified limit. The program can handle direct inputs or file-based inputs for flexibility.

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/Coding-battle.git
   cd Coding-battle
   ```

2. **Compile the source code**:
   - For direct input version:
     ```bash
     g++ -o critical_path_optimizer_direct_inputs src/critical_path_optimizer_direct_inputs.cpp
     ```
   - For file input version:
     ```bash
     g++ -o critical_path_optimizer_Files_Input src/critical_path_optimizer_Files_input.cpp
     ```

3. **Ensure scripts are executable**:
   ```bash
   chmod +x Scripts/*.sh
   ```

## Usage

### Running the Program
- **Direct Input Version**:
  ```bash
  ./critical_path_optimizer_direct_inputs
  ```
  Provide inputs directly via the terminal.

- **File Input Version**:
  ```bash
  ./critical_path_optimizer_Files_Input < Test\ Cases/Input/SampleInput1.txt
  ```

### Running All Test Cases
1. Ensure all input files are in `Test Cases/Input/` and corresponding expected output files are in `Test Cases/Output/`.
2. Run the test case script:
   ```bash
   ./Scripts/run_all_test_cases.sh
   ```

### Generating Missing Output Files
If some input files do not have corresponding output files, use the following script:
```bash
./Scripts/generate_output_files.sh
```

## Features
- **Critical Path Calculation**: Computes the minimum completion time for a processor network.
- **Optimization**: Iteratively replaces processors with high-speed alternatives to minimize completion time.
- **Flexible Input**: Supports both direct and file-based inputs.
- **Test Automation**: Includes scripts to run and validate test cases.

## Folder Structure
```
Project/
├── Test Cases/
│   ├── Input/       # Input test cases
│   ├── Output/      # Expected output test cases
├── Scripts/         # Utility scripts for testing and validation
├── src/             # Source code files
├── README.md        # Project documentation
└── a.out            # Compiled binary (if applicable)
```

## License
This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
