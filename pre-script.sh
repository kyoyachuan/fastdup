sudo mount -t tmpfs -o size=3G tmpfs ${DATA_PATH}
openssl rand -out ${DATA_PATH}/sample.txt -base64 792917038; truncate -s-1 ${DATA_PATH}/sample.txt
sudo swapoff -a && swapon -a
sudo sh -c 'echo 3 > /proc/sys/vm/drop_caches'