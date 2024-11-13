# KEMU

Welcome to **KEMU**, an experimental, lightweight virtual machine written in C. This project aims to simulate a simple 16-bit virtual machine with fundamental memory management, CPU emulation, and custom assembly instructions. Inspired by classic systems like the 386, KEMU provides a foundation for learning about computer architecture, CPU registers, stack management, and basic machine instructions.

## Project Goals

1. **Learn and Experiment**: This VM project was started as a hands-on experiment to learn how virtual machines work by building one from scratch.
2. **Build a Functional 16-bit VM**: The initial goal is to create a 16-bit CPU with basic memory and CPU functionality.
3. **Introduce a Simple Instruction Set**: Implement a custom assembly language and interpreter to process VM instructions.

## Features

- **16-bit CPU**: KEMU includes a CPU structure with general-purpose registers (A, B, C, X), a stack pointer, and an instruction pointer.
- **Memory Management**: 65 KB of memory is accessible, modeled after classic systems.
- **Custom Instruction Set**: A simple set of opcodes enables basic operations, allowing for straightforward computation and memory handling.
- **Modular Design**: CPU, memory, and program components are modular, making it easy to extend with additional functionality.

## Requirements

- **Bash Build System**: This project leverages the `Bash.bs` build system to generate base C files. Download it from the [Doctor Birch Repo](https://repo.doctorbirch.com/).
- **BirchUtils**: Essential utilities and macros, available in the same repository.

## Project Structure

- `KEMU.c` – Main implementation file with entry-level setup and initialization of VM structures.
- `KEMU.h` – Header file defining data structures such as CPU, memory, and opcodes.
- `Makefile` – Script to compile KEMU with virtual tools and dependencies.
- `program.c` – Contains the sequence of instructions (custom opcodes) for KEMU to execute.

## Getting Started

1. Clone the project repository.
2. Install dependencies:
   ```bash
   sudo apt-get install gcc make
   ```
3. Build the project:
   ```bash
   make
   ```
4. Run KEMU:
   ```bash
   ./KEMU
   ```

## Contributing

Suggestions and improvements are welcome! To contribute:

1. Fork the project.
2. Create a branch.
3. Make your changes.
4. Submit a pull request.

## Notes

- **This project is experimental** and may not yet handle all edge cases.
- **Community Feedback**: Feedback on the data structure, register naming, and memory management is highly encouraged.
- **Future Enhancements**: Adding disk emulation, serial I/O, and expanding the instruction set.

Thank you for exploring KEMU!