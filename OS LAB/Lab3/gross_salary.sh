echo "Enter that value of basics and TA:"
read b a
echo "The gross salary is:"
echo "$b+$a+0.1*$b" | bc -l

