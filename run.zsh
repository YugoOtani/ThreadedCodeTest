#!/bin/zsh

output_file="results.txt"

echo -n > "$output_file"

for i in {1..1000}; do
    ./baseline >> "$output_file"
done