#!/bin/bash

echo "Enter folder name:"
read folder

echo "🗂️ Creating folder.."
mkdir $folder && cd $folder

echo "📂 Creating main file and bringing utilities..."
touch main.cpp
cp ~/code/mesieou/2025/deakin/introduction-to-programming/utilities/utilities.cpp $folder
cp ~/code/mesieou/2025/deakin/introduction-to-programming/utilities/utilities.h $folder

echo '#include "utilities.h"' >> main.cpp
echo '#include "splashkit.h"' >> main.cpp

code .
