#!/bin/bash

# Directories for test cases
INPUT_DIR="Test Cases/Input"
OUTPUT_DIR="Test Cases/Output"

# Program executable
EXECUTABLE="./critical_path_optimizer_Files_Input"

# Check if the executable exists
if [[ ! -f "$EXECUTABLE" ]]; then
    echo "Error: Executable $EXECUTABLE not found. Please compile your program first."
    exit 1
fi

# Initialize counters for passed and failed test cases
passed_count=0
failed_count=0

echo "--------------------------------------------"
echo "Starting Test Case Execution"
echo "--------------------------------------------"
echo ""

# Loop through all input files in the input directory
for input_file in "$INPUT_DIR"/*.txt; do
    # Get the base name (remove path and file extension)
    base=$(basename "$input_file" .txt)

    # Construct the expected output file path
    output_file="${OUTPUT_DIR}/${base}Output.txt"

    echo "--------------------------------------------"
    echo "Processing Test Case: $base"
    echo "--------------------------------------------"

    echo "  Input File: $input_file"
    echo "  Expected Output File: $output_file"
    echo ""

    # Add spacing for better readability
    echo ""
    echo "  Input Content:"
    echo "  -----------------"
    cat "$input_file"
    echo ""
    
    # Run the program with the input file and capture the output
    program_output=$($EXECUTABLE < "$input_file")

    # Check if the expected output file exists
    if [[ -f "$output_file" ]]; then
        # Read the expected output
        expected_output=$(cat "$output_file")

        # Display the expected output
        echo "  Expected Output:"
        echo "  -----------------"
        echo "  $expected_output"
        echo ""

        # Display the program output
        echo "  Program Output:"
        echo "  -----------------"
        echo "  $program_output"
        echo ""

        # Compare the program output with the expected output
        if [[ "$program_output" == "$expected_output" ]]; then
            echo "  Result:"
            echo "  -----------------"
            echo "  Test Case Passed!"
            passed_count=$((passed_count + 1))
        else
            echo "  Result:"
            echo "  -----------------"
            echo "  Test Case Failed!"
            failed_count=$((failed_count + 1))
            echo ""
            echo "  Difference:"
            echo "  -----------------"
            diff <(echo "$expected_output") <(echo "$program_output")
        fi
    else
        echo "  Expected output file $output_file is missing!"
        echo "  Program Output:"
        echo "  -----------------"
        echo "  $program_output"
        failed_count=$((failed_count + 1))
    fi

    echo ""
done

echo "--------------------------------------------"
echo "Test Case Execution Summary"
echo "--------------------------------------------"
echo "  Total Test Cases: $((passed_count + failed_count))"
echo "  Passed: $passed_count"
echo "  Failed: $failed_count"
echo "--------------------------------------------"