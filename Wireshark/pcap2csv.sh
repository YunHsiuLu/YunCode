filename=$1
echo $filename
str="test${filename:8:5}.csv"
echo $str
#tshark -r $i -T fields -e frame.number -e eth.src -e eth.dst -e ip.src -e ip.dst -e frame.len -E header=y -E separator=, > "data_csv"/$str
