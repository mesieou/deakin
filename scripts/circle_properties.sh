#!/bin/bash

PI="3.14"
radius=5

circumference=$(echo "scale=2; 2 * $PI * $radius" | bc)

area=$(echo "scale=2; $PI * $radius * $radius" | bc)

echo "For a circle with radius $radius:"
echo "Circumference: $circumference"
echo "Area: $area"