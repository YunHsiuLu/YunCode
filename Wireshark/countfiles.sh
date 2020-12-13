sleep_sec=$(($1 + 2))
for i in $(seq 1 $2);
do
    sleep $1
    cd data_test
        arr=(*.pcap)
        echo "Files done: $i"
    cd ../
    source pcap2csv.sh ${arr[$i]}
done
