echo "Enter the limit"
read n

# Read array elements
for ((i = 0; i < n; i++))
do
    read a[$i]
done

# Print elements in ascending order
echo "Numbers in ascending order:"
for i in "${a[@]}"
do
    echo $i
done | sort -n
ascending