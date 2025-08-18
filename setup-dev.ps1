# Development Setup Script for Windows
# Run this script to set up the build environment

# Set CMake path
$env:PATH = "C:\cmake-4.0.3-windows-x86_64\bin;" + $env:PATH

# Verify CMake is available
Write-Host "Checking CMake installation..."
cmake --version

# Create build directory if it doesn't exist
if (!(Test-Path "build")) {
    New-Item -ItemType Directory -Name "build"
    Write-Host "Created build directory"
}

# Configure and build
Write-Host "Configuring project..."
cmake -S . -B build

Write-Host "Building project..."
cmake --build build

Write-Host "Running tests..."
& "build\Debug\test-monitor.exe"

Write-Host "Development setup complete!"
