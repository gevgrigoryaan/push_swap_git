#!/bin/bash
FLAGS=("--simple" "--medium" "--complex" "--adaptive")

for f in "${FLAGS[@]}"; do
  ok=0
  fail=0

  test_ok() {
    local input="$1"
    local label="$2"
    local out
    out=$(./push_swap $f $input | ./checker $input 2>/dev/null || true)
    if [[ "$out" == "OK" ]]; then
      ok=$((ok + 1))
    else
      echo "[$f] FAIL sort: $label => ${out:-<empty>}"
      fail=$((fail + 1))
    fi
  }

  test_err() {
    local arg="$1"
    local label="$2"
    ./push_swap $f "$arg" >/dev/null 2>/dev/null
    if [[ $? -ne 0 ]]; then
      ok=$((ok + 1))
    else
      echo "[$f] FAIL error: $label => exit 0"
      fail=$((fail + 1))
    fi
  }

  test_ok "2 1" "2 1"
  test_ok "3 2 1" "3 2 1"
  test_ok "5 4 3 2 1" "5 4 3 2 1"
  test_ok "3 5 1 4 2" "3 5 1 4 2"
  test_ok "-5 3 -1 0 2" "mixed signs"
  test_ok "2147483647 -2147483648" "INT_MAX INT_MIN"

  args100=$(awk 'BEGIN{srand(); for(i=0;i<100;i++) a[i]=i+1; for(i=99;i>0;i--){j=int(rand()*(i+1)); t=a[i]; a[i]=a[j]; a[j]=t} for(i=0;i<100;i++) printf "%d ", a[i]-50}')
  out100=$(./push_swap $f $args100 | ./checker $args100 2>/dev/null || true)
  if [[ "$out100" == "OK" ]]; then
    ok=$((ok + 1))
  else
    echo "[$f] FAIL sort: random100 => ${out100:-<empty>}"
    fail=$((fail + 1))
  fi

  test_err "-" "minus only"
  test_err "+" "plus only"
  test_err "1 1" "duplicate"
  test_err "2147483648" "overflow"

  args50=$(awk 'BEGIN{srand(); for(i=0;i<50;i++) printf "%d ", int(rand()*1000)-500}')
  ./push_swap $f --bench $args50 >/dev/null 2>/tmp/bench_test.txt || true
  if grep -q "\[bench\] total ops" /tmp/bench_test.txt; then
    ok=$((ok + 1))
  else
    echo "[$f] FAIL bench output"
    fail=$((fail + 1))
  fi

  echo "[$f] PASS=$ok FAIL=$fail"
  echo
 done
