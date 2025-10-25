echo "enter number 1: "
read a
echo "enter a number 2 : "
read b
echo "menu"
echo "1. +"
echo "2. -"
echo "3. *"
echo "4. /"
echo "enter the operation no. : "
read op
case $op in
1)e=$(($a+$b))
	echo "result is "$e;;
2)e=$(($a-$b))
	echo "result is" $e;;
3)e=$(($a*$b))
	echo "result is "$e;;
4)e=$(($a/$b))
	echo "result is "$e;;
*)echo wrong choice;;
esac
