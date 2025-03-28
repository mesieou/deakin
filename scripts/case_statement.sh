#!/bin/bash

echo "Choose an option: Start, Stop, Status"
read option

case $option in
  "Start")
    echo "System starting";;
  "Stop")
    echo "System stopping...";;
  "Status")
    echo "System status: All systems go!";;
esac