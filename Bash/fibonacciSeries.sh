echo "enter a number: "
read n
first=0
second=1
echo "fibonacci series :"
echo $first
echo $second
for((i=3;i<=$n;i++))
do
next=$(($first+$second))
echo $next
first=$second
second=$next
done
