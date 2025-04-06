# **HuffZip**

#### Description:

This project implements a file compression and decompression utility using the **Huffman Coding** algorithm. It allows users to compress and decompress text files by building a Huffman tree, generating Huffman codes, and then storing the compressed file. Additionally, the project provides a mechanism to handle file frequencies, which are necessary for decompression.

The program consists of several modules:

- **Huffman coding** for compressing and decompressing text files.
- **Min-heap data structure** used to build the Huffman tree.
- **File handling** for reading and writing files.
- **Compression and decompression utilities** for file operations.

#### Features:

- **Compression**: Compress text files using Huffman coding.
- **Decompression**: Decompress files that were compressed using this algorithm, utilizing the frequencies of characters stored in a separate file.
- **Memory Management**: Efficient memory handling for the Huffman tree.
- **Flexible File Operations**: Handle files with different character sets and manage compression and decompression output.

#### Installation:

1. Clone this repository:

   ```bash
   https://github.com/Ayush272002/HuffZip.git
   cd HuffZip
   ```

2. Build the project using `make`:

   ```bash
   make
   ```

3. Once built, the executable `huffman_compression` will be located in the `build` directory.

#### Usage:

1. **Compression**:
   To compress a file, run the following command:

   ```bash
   ./build/huffman_compression compress <input_file> <output_file>
   ```

   This will compress the input file and save the compressed output to the output file.

2. **Decompression**:
   To decompress a file, you will need the frequencies file (`frequencies.bin`) generated during compression:
   ```bash
   ./build/huffman_compression decompress <input_file> <output_file>
   ```
   This will decompress the input file and save the result in the output file.

#### Makefile Commands:

- **Build**: `make`  
   Compiles the source files and generates the executable `huffman_compression` in the `build` directory.

- **Clean**: `make clean`  
   Removes object files and the executable from the `build` directory.

- **Run**: `make run`  
   Builds the project and runs the executable for testing purposes.

- **Debug**: `make debug`  
   Builds the project with debugging symbols, which can be helpful for tracing issues during development.

#### File Structure:

```
/huffman-compression
├── /src                  # Source code files
│   ├── main.c            # Main program entry point
│   ├── huffman.c         # Huffman coding and tree construction
│   ├── minheap.c         # Min-heap data structure for Huffman tree
│   └── file_handler.c    # File handling operations for reading and writing
├── /include              # Header files
│   ├── huffman.h         # Declarations for Huffman coding
│   ├── minheap.h         # Declarations for min-heap data structure
│   └── file_handler.h    # Declarations for file operations
├── /build                # Build directory (created on `make`)
├── Makefile              # Makefile to automate building and cleaning
└── README.md             # Project README
```

#### Example Workflow:

1. **Compress a file**:

   ```bash
   ./build/huffman_compression compress test.txt test_compressed.txt
   ```

2. **Decompress the file**:

   ```bash
   ./build/huffman_compression decompress test_compressed.txt decompressed.txt
   ```

3. **Check the content of the decompressed file** to verify if the process worked as expected.

#### Troubleshooting:

- If you encounter a **segmentation fault** or other issues, ensure that your input file is correctly formatted and does not contain unexpected characters. Additionally, debug with `make debug` to help track down memory issues.
- **Missing Huffman Codes**: If the program complains about missing Huffman codes for certain characters during compression, make sure all characters in the input file are handled properly by the `generateCodes` function.

#### Contributing:

Feel free to contribute to this project by forking the repository and submitting a pull request. If you find any bugs or have ideas for improvements, don't hesitate to open an issue!

#### License:

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
