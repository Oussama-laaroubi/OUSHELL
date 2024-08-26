
#!/bin/bash

# Path to your minishell executable
MINISHELL=./minishell

# Directory to store temporary outputs
TMP_DIR=$(mktemp -d)

# Temporary files to store outputs
BASH_OUTPUT="$TMP_DIR/bash_output.txt"
MINISHELL_OUTPUT="$TMP_DIR/minishell_output.txt"

# Function to run a test case
run_test_case() {
    local description="$1"
    local test_case="$2"

    echo "Running test: $description"

    # Run the command in bash and store the output
    echo "$test_case" | bash > "$BASH_OUTPUT" 2>&1

    # Run the command in minishell and store the output
    echo "$test_case" | $MINISHELL > "$MINISHELL_OUTPUT" 2>&1

    # Compare the outputs
    if diff -q "$BASH_OUTPUT" "$MINISHELL_OUTPUT" > /dev/null; then
        echo "Test passed: $description"
    else
        echo "Test failed: $description"
        echo "Bash output:"
        cat "$BASH_OUTPUT"
        echo "Minishell output:"
        cat "$MINISHELL_OUTPUT"
        echo
    fi
}

# Function to add and run tests
run_all_tests() {
    # Add your test cases here

    # Example tests for echo command
    run_test_case "Echo basic string" 'echo "Hello, World!"'
    run_test_case "Echo with -n option" 'echo -n "No newline"'
    run_test_case "Echo with -e option" 'echo -e "Line 1\nLine 2"'
    run_test_case "Echo with mixed content" 'echo "Mixed words and numbers 123 abc"'
    run_test_case "Echo with -n and -e" 'echo -n -e "No newline, with escape \t Tab"'

    # Add more tests for other commands here
    # Example: run_test_case "Test description" 'your_test_command_here'
}

# Run all the tests
run_all_tests

# Cleanup temporary files
rm -rf "$TMP_DIR"

echo "All tests completed."
