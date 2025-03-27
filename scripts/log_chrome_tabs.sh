#!/bin/bash

LOGFILE="$HOME/chrome_tab_log.txt"
START_TIME=$(date +"%Y-%m-%d %H:%M:%S")
echo "🟢 Session Started: $START_TIME" >> "$LOGFILE"
echo "---------------------------------" >> "$LOGFILE"

# Get list of open Chrome tabs
echo "🌐 Open Chrome Tabs (Start):" >> "$LOGFILE"
curl -s http://localhost:9222/json | jq -r '.[].title' >> "$LOGFILE"
echo "" >> "$LOGFILE"

read -p "Press Enter when finished..." 

END_TIME=$(date +"%Y-%m-%d %H:%M:%S")
echo "🔴 Session Ended: $END_TIME" >> "$LOGFILE"
echo "---------------------------------" >> "$LOGFILE"

# Get list of open Chrome tabs again
echo "🌐 Open Chrome Tabs (End):" >> "$LOGFILE"
curl -s http://localhost:9222/json | jq -r '.[].title' >> "$LOGFILE"
echo "" >> "$LOGFILE"
echo "✅ Session saved to $LOGFILE"

