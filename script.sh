module=$1
echo "Test: ${module}.cpp"

sh pre-script.sh
g++ ${module}.cpp -o dup
perf stat ./dup ${DATA_PATH}/sample.txt ${DATA_PATH}/dst.txt

sh cleaning-up.sh