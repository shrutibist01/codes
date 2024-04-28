# Grade and GPA calculator 

echo "GPA Calculator"
echo "Enter GPA in DBMS: "
read dbms
echo "Enter GPA in M3: "
read m3
echo "Enter GPA in OS: "
read os
echo "Enter GPA in Java"
read java

gpa=$((dbms + m3 + os + java))
gpa=$((gpa / 4))
echo "Your final GPA is $gpa"

if [ $gpa == 10 ]; then 
echo "Grade obtained = O"
elif [ $gpa -ge 9 -a $gpa -lt 10 ]; then 
echo "Grade obtained = A"
elif [ "$gpa" -ge 8 -a "$gpa" -lt 9 ]; then
echo "Grade obtained = B"
elif [ "$gpa" -ge 7 -a "$gpa" -lt 8 ]; then
echo "Grade obtained = C"
elif [ "$gpa" -ge 6 -a "$gpa" -lt 7 ]; then
echo "Grade obtained = D"
elif [ "$gpa" -ge 4 -a "$gpa" -lt 6 ]; then 
echo "Grade obtained = P"
else
echo "Grade obtained = F"
fi
