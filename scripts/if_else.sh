#!/bin/bash

currenttime=$(date +%H)
username=$(whoami)

if [ $currenttime -lt 12 ]; then
  echo "Good morning, $username"
elif [ $currenttime -ge 12 ] && [ $currenttime -le 18 ]; then
  echo "Good Afternoon, $username"
else
  echo "Good Night"
fi
