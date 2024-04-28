#even or odd
echo "Checking if entered number is even or odd"
echo "Enter a number:"
read num
if [ $num -eq 0 ]
then 
    echo "$num is neither even nor odd"
elif [ $((num % 2)) -eq 0 ]
then 
    echo "$num is Even" 
else 
    echo "$num is Odd"       
fi 

#largest of 3 numbers 
echo "Find the largest of 3 numbers"
echo "Enter first number:"
read n1
echo "Enter second number:"
read n2
echo "Enter third number:"
read n3
if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]
then 
    echo "$n1 is greatest"
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ]
then 
    echo "$n2 is greatest"
else
    echo "$n3 is greatest"    
fi


#leap year
echo "check if the year is leap year or not"
echo "Enter year"
read year
if [ $((year % 4)) -eq 0 ] && [ $((year % 100)) -ne 0 ] || [ $((year % 400)) -eq 0 ]
then 
    echo "$year is a leap year"
else
    echo "$year is not a leap year"   
fi


#calculate balance of the account
echo "Enter account balance: "
read bal
echo "Enter withdrawal amount: "
read wd

if [ $wd -gt $bal ]; then 
    echo "Insufficient balance"
else 
    tax=0 
    if [ $wd -lt 1500 ]; then 
        tax=$(( wd * 3 / 100 ))
    elif [ $wd -ge 1500 ] && [ $wd -lt 3000 ]; then 
        tax=$(( wd * 4 / 100 ))
    else 
        tax=$(( wd * 5 / 100 ))  
    fi
    k=$(( wd - tax ))
    echo "Amount Withdrawn : $wd" 
    echo "Tax deducted : $tax"
    echo "Amount withdrawn after tax : $k"
fi  
