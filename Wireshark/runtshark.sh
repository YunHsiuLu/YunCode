tshark -i en0 -b duration:$1 -a duration:$2 -w data_test/testpks.pcap -F pcap