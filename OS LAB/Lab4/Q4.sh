file=$1
echo "Enter path to the folder"
read path
cd ~
cd $path
echo "Enter w for wordcount, c for character count or l for line count"
read opt
case $opt in
'c')wc -c $file;;
'w')wc -w $file;;
'l')wc -l $file;;
esac
