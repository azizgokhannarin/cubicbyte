# cubicbyte
Cubic expression of byte value

# Cubic and 3D Representation of Byte Values

CubicByte is an innovative algorithm that represents byte (8-bit) values cubically and visualizes them in 3D dimensions. This algorithm aims to present byte data in a more understandable and interactive manner, suitable for data visualization, digital art, education, and other fields.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Cubic Representation:** Each byte value is represented by a cube with specific dimensions and colors.
- **3D Visualization:** Visualizes byte data in a three-dimensional environment for a deeper understanding.
- **Flexible and Scalable:** Easily adaptable to different datasets and applications.
- **Open Source:** Open to community contributions and continuously being developed.

## Installation

### Requirements

- **CMake**: Version 3.10 or higher
- **C++ Compiler**: Supporting C++11 or higher (e.g., GCC, Clang, MSVC)

### Steps

1. **Clone the Repository:**
    ```bash
    git clone https://github.com/azizgokhannarin/cubicbyte.git
    cd cubicbyte
    ```
2. **Create a Build Directory:**
    ```bash
    mkdir build
    cd build
    ```

3. **Configure the Project with CMake:**
    ```bash
    cmake ..
    ```
    *If you need to specify custom installation paths or enable/disable features, you can pass additional flags to CMake. For example:*
    ```bash
    cmake -DCMAKE_INSTALL_PREFIX=/desired/install/path -DENABLE_ASSIMP=ON ..
    ```

4. **Build the Project:**
    ```bash
    cmake --build .
    ```
    *Alternatively, you can use make or your preferred build system:*
    ```bash
    make
    ```

5. **Install the Project (Optional):**
    ```bash
    cmake --install .
    ```
    *This step installs the built binaries and resources to the specified installation directory.*

## Usage

To convert your byte data in 3D using the CubicByte algorithm, follow these steps:

1. **Prepare Your Data:**
The encode method takes the value you want to convert and a reference value to write the encoded variable. The changed value, which is Boolean, places vector values ​​in the form of X,Y,Z if false, or Y,X,Z if true, into the encoded value.

2. **Run the Algorithm:**
    // Test X - Y
    for (size_t i = 0; i < 256; i++) {
        cubicByte.encode(i, encoded, false);
        cubicByte.decode(outputValue, encoded, false);
        std::cout << "Input Value = "  << i << "  Output Value = " << static_cast<int>(outputValue) << std::endl;
    }

    // Test Y - X
    for (size_t i = 0; i < 256; i++) {
        cubicByte.encode(i, encoded, true);
        cubicByte.decode(outputValue, encoded, true);
        std::cout << "Input Value = "  << i << "  Output Value = " << static_cast<int>(outputValue) << std::endl;
    }


## Examples


### Simple Byte Data

## Contributing

We welcome your contributions! To contribute to the project, follow these steps:

1. **Fork the Repository:** Fork the project repository on GitHub.
2. **Create a New Branch:** 
    ```bash
    git checkout -b feature/FeatureName
    ```
3. **Make Your Changes:** Add or fix code as needed.
4. **Commit Your Changes:** 
    ```bash
    git commit -m "Descriptive commit message"
    ```
5. **Push to the Branch:** 
    ```bash
    git push origin feature/FeatureName
    ```
6. **Open a Pull Request:** Submit a pull request to integrate your changes into the main repository.

## License

This project is licensed under the [Apache 2.0](LICENSE). For more details, please refer to the `LICENSE` file.
