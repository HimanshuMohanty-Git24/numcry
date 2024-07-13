# NumCry 🧮🚀

NumCry is a C++ library that mimics the functionality of NumPy, providing powerful numerical computing capabilities. It's designed to be simple, efficient, and easy to use.

## Features 🌟

- Basic matrix operations ➕➖✖️➗
- Advanced mathematical functions 📊📈
- Linear algebra operations 🔢🔀
- User-friendly command-line interface 💻🖥️

## Getting Started 🚀

### Prerequisites

- C++ compiler with C++17 support (e.g., GCC, Clang)

### Compilation 🛠️

To compile NumCry, use the following command in the project root directory:

```bash
g++ -std=c++17 -Iinclude src/*.cpp main.cpp -o num_cry
```

This command compiles all the source files and creates an executable named `num_cry`.

### Running NumCry 🏃‍♂️

After compilation, you can run NumCry using:

```bash
./num_cry  # On Unix-like systems
num_cry.exe  # On Windows
```

## Usage 📚

NumCry provides a menu-driven interface with the following options:

1. Basic Matrix Operations
2. Advanced Mathematical Operations
3. Linear Algebra Operations
4. Exit

Simply choose an option by entering the corresponding number when prompted.

## Examples 💡

Here are some examples of what you can do with NumCry:

```cpp
// Create a 2x2 matrix
Array a(2, 2);
a(0, 0) = 1; a(0, 1) = 2;
a(1, 0) = 3; a(1, 1) = 4;

// Perform matrix addition
Array b = MathOps::add(a, a);

// Calculate the determinant
double det = LinAlg::determinant(a);

// Find eigenvalues and eigenvectors
auto [eigenvalue, eigenvector] = LinAlg::eigenDecomposition(a);
```

## Contributing 🤝

Contributions to NumCry are welcome! Please feel free to submit a Pull Request.

## License 📄

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments 🙏

- Inspired by NumPy
- Built with love for numerical computing ❤️

Happy Computing! 🎉🧮
