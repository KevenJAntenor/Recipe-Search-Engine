# 🍽️🧑‍🍳🔎 Recipe Search Engine

## Description
This project is a C program that enables recipe searching within a database. The database is loaded from a file (passed as an argument) into a linked list. The search can be performed by category and optionally with a keyword. Additionally, the program can generate statistics from the input file when invoked with a specific option.

## Features
- **Recipe Search**: 
  - By category.
  - By category and keyword (case-insensitive).
- **Statistics Generation**:
  - Count of lines, unique words, and total words.
  - Most frequent letter and most popular category.
  - Longest recipe name.
- **Modular Design**:
  - Linked list implementation for categories and recipes.
  - Separate modules for main logic, statistics, and linked list operations.
- **Robust Error Handling**:
  - Validates command-line arguments and input files.
  - Handles invalid or unsupported searches gracefully.
- **Testing Framework**:
  - Uses CUnit for unit testing with a required test coverage of at least 70%.

## File Structure
- **`main.c`**: Contains the main logic for the program.
- **`list.c`, `list.h`**: Manages linked list operations for categories and recipes.
- **`statistiques.c`, `statistiques.h`**: Handles statistical analysis of the database.
- **`recherche.c`, `recherche.h`**: Implements the search functionality.
- **`test/`**: Contains unit tests for various modules.
- **`Makefile`**: Automates the build process.
- **`stats.txt`**: Output file for statistics (if specified).

## 🚀 How to Run
Follow these steps to compile and execute the program:

### 1. **Clone the Repository**
   Clone the repository to your local machine:
   ```bash
   git clone https://github.com/KevenJAntenor/Recipe-Search-Engine.git
   cd Recipe-Search-Engine
```
2. Compile the Program
Use the provided Makefile to compile the project:

```bash
make
```
This will generate the executable recherche.

3. Run the Program
Search Mode:

```bash
./recherche <input_file>
```
Replace <input_file> with the path to the database file (e.g., recipes.txt).

Statistics Mode:

```bash
./recherche <input_file> -S <output_file>
```
Replace <output_file> with the desired path for the statistics output.

4. Test the Program
Run the unit tests using CUnit:

```bash
make test
```
This will execute the tests in the test/ directory and display the results.

5. Clean Up
To remove generated files (executables, object files, etc.):

```bash
make clean
```
