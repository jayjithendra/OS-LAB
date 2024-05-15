echo "Enter path to folder"
read path
cd ~
cd $path
cat $1 > duplicate$1
echo "Successful"
