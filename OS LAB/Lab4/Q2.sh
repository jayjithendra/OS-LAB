echo "Enter path to folder"
read path
cd ~
cd $path
for i in "$@"; do
   rm -i "$i"
done
