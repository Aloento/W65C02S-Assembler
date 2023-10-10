#!/bin/bash

TESTDIR=/home/bodri/okt/forditoprogramok/coas22/bodri5/A4tests
EXEDIR=.

for i in `ls $TESTDIR/test*.asm`
do
  j=${i#$TESTDIR/}
  k=${j%.asm}
  echo -n $k
  $EXEDIR/a.out <$i >$TESTDIR/$k.hex 2>&1
  if diff -i  $TESTDIR/${k}_expected.hex $TESTDIR/$k.hex > /dev/null
  then
    echo " PASS"
  else
    echo " FAIL"
  fi
done
