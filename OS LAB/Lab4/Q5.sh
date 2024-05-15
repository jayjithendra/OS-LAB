cd ~
echo "Enter the path to the folder"
read path
cd $path
echo "Input file name"
read file
echo "Enter option"
read opt
case $opt in
'a')
for i in "$@"; do
grep $i $file
done;;
'b')
for i in "$@"; do
grep -v $i $file>temp && mv temp $file
done
cat $file;;
'c')exit
esac
exit
