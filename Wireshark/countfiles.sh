for i in {1..$1};
do
    sleep 6
    cd data_test
        arr=(*.pcap)
    cd ../
    echo "Files done: $i"
    echo "${arr[$i]}"
done


