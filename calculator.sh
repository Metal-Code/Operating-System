#/!/bin/bash
echo "Enter Two Numbers"
read a
read b
echo "1 = Addition"
echo "2 = Subtraction"
echo "3 = Multiplication"
echo "4 = Division"
read n
case $n in
1) echo "Sum is = " 'expr $a + $b ';;
2) echo "Difference is =" 'expr $a - $b ';;
3) echo "Product is =" 'expr $a \* $b ';;
4) echo "Quotent is = "
echo "scale=2; $a/$b" | bc ;; 
*) echo "Wrong Choice" ;;
esac
