#!/bin/bash


echo "Choose an option: Start, Stop, Status, Quit"
read option

while [ $option != "Quit" ]; do
    case $option in
    "Start")
        echo "System starting";;
    "Stop")
        echo "System stopping...";;
    "Status")
        echo "System status: All systems go!";;
    esac
    echo "Choose an option: Start, Stop, Status, Quit"
    read option
done

