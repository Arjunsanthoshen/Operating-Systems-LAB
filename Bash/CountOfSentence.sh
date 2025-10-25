echo "Enter a string:"
read str

sentence_count=$(echo "$str" | grep -o '[.!?]' | wc -l)

echo "Number of sentences: $sentence_count"