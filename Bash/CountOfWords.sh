echo "Enter a string:"
read str

word_count=$(echo "$str" | wc -w)

echo "Number of words: $word_count"