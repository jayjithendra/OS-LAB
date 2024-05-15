echo "Enter file type:"
read ft
echo "Enter folder to move :"
read fold
for file in *$ft; do
mv $file $fold
done
