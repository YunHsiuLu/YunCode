dur_b=$1
dur_a=$2
end=$((dur_a/dur_b))
echo "round: $dur_b s, stop: $dur_a s, files: $end"

source runtshark.sh $dur_b $dur_a &> tshark_output.out &
source countfiles.sh $end &