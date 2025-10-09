# GitHub Copilot Instructions

This workspace is a collection of C++ learning exercises and small personal projects. The primary goal is to learn and practice C++ concepts.

## Workspace Structure

The workspace is organized into two main directories:

- `C++/learncpp.com`: Contains exercises from the learncpp.com website, organized by chapter. Each chapter folder contains subfolders for specific lessons and quizzes.
- `C++/Personal projects`: Contains small, standalone personal projects.

Each exercise or project is a self-contained C++ program.

## Development Workflow

Each C++ file is a standalone program and can be compiled and run independently.

### Compilation

To compile a C++ file, use `g++`. For example, to compile you can use the following command:

```bash
g++ -std=c++26 {filename}.cpp -o {filename}
```

### Running

After compiling, you can run the executable:

```bash
./{filename}
```

There are also VS Code build tasks configured. You can use the "C/C++: g++ build active file" or "C/C++: clang build active file" tasks to compile the currently open file.

## Coding Conventions

- The code generally follows the conventions and style taught on learncpp.com.
- Each C++ file should be a complete, runnable program.
- Use comments to explain the purpose of the code, especially for more complex concepts.
- For the `learncpp.com` exercises, the file and folder structure should match the chapter and lesson structure of the website.
