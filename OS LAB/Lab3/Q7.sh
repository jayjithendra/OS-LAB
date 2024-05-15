echo "Enter file name"
read name
sed -i '2~2d' "$name"
