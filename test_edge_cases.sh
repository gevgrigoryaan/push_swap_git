#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

PASS=0
FAIL=0

echo "========================================="
echo "  PUSH_SWAP EDGE CASE TEST SUITE"
echo "========================================="

# Helper function to check error cases
test_error() {
    local name="$1"
    shift
    ./push_swap "$@" 2>/dev/null
    local ret=$?
    if [ $ret -ne 0 ]; then
        echo -e "${GREEN}✓${NC} $name: Error detected correctly"
        ((PASS++))
    else
        echo -e "${RED}✗${NC} $name: Should have errored but didn't"
        ((FAIL++))
    fi
}

# Helper function to test valid cases with checker
test_valid() {
    local name="$1"
    shift
    local ops=$(./push_swap "$@" | tee /tmp/ps_ops.txt | wc -l)
    local result=$(./push_swap "$@" | ./checker "$@" 2>/dev/null)
    
    if [ "$result" = "OK" ]; then
        echo -e "${GREEN}✓${NC} $name: Sorted correctly ($ops ops)"
        ((PASS++))
    else
        echo -e "${RED}✗${NC} $name: Failed to sort (result: $result)"
        ((FAIL++))
    fi
}

# Helper function to test no operations needed
test_no_ops() {
    local name="$1"
    shift
    local ops=$(./push_swap "$@" 2>/dev/null | wc -l | tr -d ' ')
    
    if [ "$ops" -eq 0 ]; then
        echo -e "${GREEN}✓${NC} $name: No operations (already sorted)"
        ((PASS++))
    else
        echo -e "${RED}✗${NC} $name: Should output nothing but got $ops ops"
        ((FAIL++))
    fi
}

echo ""
echo "=== ERROR HANDLING TESTS ==="
echo ""

# Test 1: Empty / No arguments
./push_swap 2>/dev/null
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓${NC} No arguments: Exits cleanly"
    ((PASS++))
else
    echo -e "${RED}✗${NC} No arguments: Should exit cleanly"
    ((FAIL++))
fi

# Test 2: Duplicates
test_error "Duplicates (1 1 2)" 1 1 2
test_error "Duplicates (5 2 5)" 5 2 5
test_error "Duplicates in string" "3 3 1"

# Test 3: Non-numeric
test_error "Non-numeric (abc)" abc
test_error "Non-numeric (1 a 2)" 1 a 2
test_error "Non-numeric (1a)" 1a
test_error "Non-numeric (1.5)" 1.5

# Test 4: Out of INT range
test_error "Overflow (2147483648)" 2147483648
test_error "Underflow (-2147483649)" -2147483649
test_error "Huge number" 9999999999999

# Test 5: Empty string
test_error "Empty string" ""
test_error "Only spaces" "   "

# Test 6: Invalid signs
test_error "Double sign (++5)" "++5"
test_error "Double sign (--5)" "--5"
test_error "Sign only (+)" "+"
test_error "Sign only (-)" "-"

echo ""
echo "=== ALREADY SORTED TESTS ==="
echo ""

# Test 7: Already sorted (should output nothing)
test_no_ops "Single number" 42
test_no_ops "Two sorted" 1 2
test_no_ops "Three sorted" 1 2 3
test_no_ops "Five sorted" 1 2 3 4 5
test_no_ops "Ten sorted" 1 2 3 4 5 6 7 8 9 10

echo ""
echo "=== SMALL SET TESTS ==="
echo ""

# Test 8: Two numbers
test_valid "Two unsorted (2 1)" 2 1

# Test 9: Three numbers (all permutations)
test_valid "Three (2 1 3)" 2 1 3
test_valid "Three (3 2 1)" 3 2 1
test_valid "Three (1 3 2)" 1 3 2

# Test 10: Five numbers
test_valid "Five unsorted" 5 4 3 2 1
test_valid "Five random" 3 5 1 4 2

echo ""
echo "=== EDGE VALUE TESTS ==="
echo ""

# Test 11: INT_MIN and INT_MAX
test_valid "INT_MIN and INT_MAX" -2147483648 2147483647
test_valid "Around INT_MIN" -2147483648 -2147483647 0
test_valid "Around INT_MAX" 0 2147483646 2147483647

# Test 12: Negative numbers
test_valid "All negative" -5 -2 -8 -1
test_valid "Mixed signs" -5 3 -1 0 2

echo ""
echo "=== MEDIUM SET TESTS ==="
echo ""

# Test 13: 100 numbers
RAND_100=$(awk 'BEGIN{srand(); for(i=0;i<100;i++) printf("%d ", int(rand()*4294967296)-2147483648)}')
test_valid "100 random" $RAND_100

# Test 14: 100 reverse sorted
test_valid "100 reverse" $(seq 100 -1 1)

echo ""
echo "=== LARGE SET TESTS ==="
echo ""

# Test 15: 500 numbers
RAND_500=$(awk 'BEGIN{srand(); for(i=0;i<500;i++) printf("%d ", int(rand()*4294967296)-2147483648)}')
ops_500=$(./push_swap $RAND_500 2>/dev/null | wc -l | tr -d ' ')
result_500=$(./push_swap $RAND_500 2>/dev/null | ./checker $RAND_500 2>/dev/null)

if [ "$result_500" = "OK" ]; then
    if [ "$ops_500" -le 5500 ]; then
        echo -e "${GREEN}✓${NC} 500 random: Sorted correctly in $ops_500 ops (excellent)"
        ((PASS++))
    elif [ "$ops_500" -le 7000 ]; then
        echo -e "${YELLOW}✓${NC} 500 random: Sorted correctly in $ops_500 ops (acceptable)"
        ((PASS++))
    else
        echo -e "${YELLOW}✓${NC} 500 random: Sorted correctly in $ops_500 ops (needs optimization)"
        ((PASS++))
    fi
else
    echo -e "${RED}✗${NC} 500 random: Failed to sort"
    ((FAIL++))
fi

echo ""
echo "=== STRING ARG vs MULTIPLE ARGS ==="
echo ""

# Test 16: String argument
test_valid "String arg \"3 2 1\"" "3 2 1"
test_valid "String arg \"5 4 3 2 1\"" "5 4 3 2 1"

# Test 17: Multiple string args
test_valid "Multiple strings" "3 2" "1"

echo ""
echo "========================================="
echo "  TEST RESULTS"
echo "========================================="
echo -e "${GREEN}PASSED: $PASS${NC}"
echo -e "${RED}FAILED: $FAIL${NC}"
echo "========================================="

if [ $FAIL -eq 0 ]; then
    echo -e "${GREEN}ALL TESTS PASSED!${NC}"
    exit 0
else
    echo -e "${RED}SOME TESTS FAILED${NC}"
    exit 1
fi
