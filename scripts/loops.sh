#!/bin/bash
echo "Enter the number of seconds for the countdown:"
read seconds

for ((i = 0; i <= seconds; i++));
do
  echo "Time remaining: $((seconds - i))"
done
echo "Time's up!"