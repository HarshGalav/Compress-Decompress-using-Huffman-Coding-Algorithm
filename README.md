# Compress-Decompress-using-Huffman-Coding-Algorithm

## 📌 Description

This project enables compression and decompression of text files using Huffman Coding. It builds a Huffman tree, generates binary codes for characters, and compresses data efficiently. A frequency file is also generated to enable accurate decompression.

## 🚀 Usage (macOS)

Make sure you have run `make` to build the project first.

### 🔹 Compress a sample file

```bash
./build/huffman_compression compress sample.txt compressed.huff
```

This command compresses `sample.txt` and generates:
- `compressed.huff` (compressed data)
- `frequencies.bin` (needed for decompression)

### 🔹 Decompress the compressed file

```bash
./build/huffman_compression decompress compressed.huff recovered.txt
```

This will generate `recovered.txt`, which should match `sample.txt`.

### 🔹 Clean build files

```bash
make clean
```

### 🔹 Build with debug info (for troubleshooting)

```bash
make debug
```

### 🔹 Run the compiled program directly (if supported in Makefile)

```bash
make run
```
