#!/bin/bash

# Exit immediately if a command exits with a non-zero status.
set -e

# Define the build directory
BUILD_DIR="build"

# Clean up previous build artifacts
if [ -d "$BUILD_DIR" ]; then
  echo "Removing previous build directory..."
  rm -rf "$BUILD_DIR"
fi

# Create a new build directory
echo "Creating build directory..."
mkdir "$BUILD_DIR"

# Navigate into the build directory
cd "$BUILD_DIR"

# Run CMake to configure the project
echo "Configuring project with CMake..."
cmake ..

# Compile the project
echo "Compiling the project with make..."
make

# Navigate back to the project root
cd ..

# Run the executable
echo "Running the benchmark..."
./"$BUILD_DIR"/knapsack_problem

echo "Script finished successfully. Results are in knapsack_results.csv"