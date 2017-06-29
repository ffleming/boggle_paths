#!/bin/sh

BIN="./boggle_paths"
QUIET="-q"
BIGNUM="-b"
TIME="/usr/bin/time"

if [ "$1" == "--long" ] ; then
  SIDES=(1 2 3 4 5)
else
  SIDES=(1 2 3 4)
fi

echo "Standard Solver"
echo "---------------"
for i in ${SIDES[@]}; do
  echo "$i sides:"
  $TIME $BIN $QUIET $i > /dev/null
done

echo "Bignum Solver"
echo "---------------"
for i in ${SIDES[@]}; do
  echo "$i sides:"
  $TIME $BIN $QUIET $BIGNUM $i > /dev/null
done
