#!/bin/bash

echo "Enter folder name:"
read folder

echo "🗂️ Creating folder.."
mkdir $folder && cd $folder

echo "📂 Creating main file and bringing utilities..."
touch main.cpp
cp ~/code/mesieou/2025/deakin/introduction-to-programming/utilities/utilities.cpp ./
cp ~/code/mesieou/2025/deakin/introduction-to-programming/utilities/utilities.h ./

echo '#include "utilities.h"' >> main.cpp
echo '#include "splashkit.h"' >> main.cpp

# Add the main function to main.cpp
echo '' >> main.cpp
echo 'int main() {' >> main.cpp
echo '    // Your code goes here' >> main.cpp
echo '    return 0;' >> main.cpp
echo '}' >> main.cpp

# pushing the set up to github
echo "Pushing to Github the  new project..."

git add .
git commit -m "created and set up a new project for $folder"
branch=$(git rev-parse --abbrev-ref HEAD)
git push origin "$branch"

code .

