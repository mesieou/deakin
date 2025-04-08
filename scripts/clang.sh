echo "🔍 Compiling all C++ files in the current directory..."
read files

clang++ *.cpp -l SplashKit -o program

if [ $? -eq 0 ]; then
    echo "✅ Compilation successful! Running program..."
    ./program
else
    echo "❌ Compilation failed."
fi