#!/bin/sh

BIN="./boggle_paths"
ARGS="-q"
GREP="/usr/bin/env grep"
function testcase() {
  sides=$1
  answer=$2
  out=$($BIN $ARGS $sides)
  return $(echo "$out" | $GREP -q $answer)
}

SIDES=(2 3 4)
ANSWERS=(64 10305  12029640)
EXITCODE=0

for i in 0 1 2; do
  if testcase ${SIDES[$i]} ${ANSWERS[$i]}; then
    echo "* ${SIDES[$i]} sides correctly returns ${ANSWERS[$i]}"
  else
    echo "x ${SIDES[$i]} sides did NOT return ${ANSWERS[$i]}"
    EXITCODE=1
  fi
done
exit $EXITCODE
