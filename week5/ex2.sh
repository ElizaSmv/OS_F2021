lockfile -r 0 file.lock || exit 1

while true
do
    var=$(tail -1 file.txt | grep -oE '^[0-9]+$')
    echo $((var + 1)) >> file.txt
done

rm -f file.lock
