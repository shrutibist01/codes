#compare two strings
echo "Enter First string:"
read s1
echo "Enter second string:"
read s2
if [ "$s1" == "$s2" ]; then
    echo "String are equal"
else 
    echo "Strings are not equal"
fi

#concatenate two strings
concat = "$s1$s2"
echo "concatenated string is: $concat"

#length of string
length = $(expr length "$concat")
echo "the length of the concatenated string is $length"

#print odd-position characters
length1= $(expr length "$s2")
for((i=0;i<length; i+=2))
do 
    echo "${s2:i:1}"
done

#checking palindrome
if [ "$concat" == "$reverse"]; then
    echo "This is a palindrome"
else 
    echo "This is not a palindrome"
fi

#reverse
reverse=""
for((i=length-1; i>=0; i--))
do 
    reverse="$reverse${concat:i:1}"
done
echo "reversed string is $reverse"

#occurence of a character in a string
echo "Enter a string:"
read st
echo "Enter character you want to search for:"
read char
count= `echo $st| grep -o "$char" |wc -l`
echo "The character '$char' appears $count times in the string '$st'"