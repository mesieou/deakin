#!/bin/bash

echo "What is your full name?"
read firstname lastname
echo "hello $firstname $lastname"
echo "What is your favourite color?"
read colour

case $colour in
  red) echo "You chose red!";;
  blue) echo "You chose blue!";;
  green) echo "You chose green!";;
  *) echo "Sorry, I don't know that color.";;
esac

for i in {1..5}; do
  echo "Iteration $i"
done