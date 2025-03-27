#!/bin/bash

echo "🚀 Starting Chrome with remote debugging..."
/Applications/Google\ Chrome.app/Contents/MacOS/Google\ Chrome --remote-debugging-port=9222 &

# Wait for 5 seconds to ensure Chrome is running
sleep 5

echo "📝 Starting the time and Chrome tab logger..."
./log_chrome_tabs.sh

