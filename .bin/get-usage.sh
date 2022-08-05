#!/bin/bash
root=$(df -h | awk '{ if ($6 == "/") print $4 }')
root_int=${root::-1}
home=$(df -h | awk '{ if ($6 == "/home") print $4 }')
freemen_per=$(free -m | awk 'NR==2{print $3*100/$2 }')
freemen_per_int=$(printf "%.0f\n" "$freemen_per")
date=$(date +"%m/%d %H:%M")
cpu=$(awk '{u=$2+$4; t=$2+$4+$5; if (NR==1){u1=u; t1=t;} else print ($2+$4-u1) * 100 / (t-t1) "%"; }' \
<(grep 'cpu ' /proc/stat) <(sleep 1;grep 'cpu ' /proc/stat))
cpu_per_int=$(printf "%.0f\n" "$cpu")

status=""

status+="
|$cpu_per_int%
|$freemen_per_int%
|$root_int""g 
ﴤ|$home
|$date
"
echo $status
