for i in {1..$1};
do
    sleep 6
    cd data_test
        arr=(*.pcap)
        echo "Files done: $i"
    cd ../
    #echo "${arr[$i]}"
    source pcap2csv.sh ${arr[$i]}

done


