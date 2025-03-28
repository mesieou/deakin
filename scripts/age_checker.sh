#!/bin/bash

echo "What is your age?"
read age

while [ $age -lt 1 -o $age -gt 100 ]; do
  echo "Please enter a valid age"
  echo "What is your age?"
  read age
done

if [ $age -gt 17 ]; then
  echo "You are an adult"
else
  echo "You are not an adult"
fi