openssl rand -out /home/kyoyachuan/data/sample.txt -base64 792917038; truncate -s-1 /home/kyoyachuan/data/sample.txt
sudo mount -t tmpfs -o size=3G tmpfs /home/kyoyachuan/data/
sudo swapoff -a && swapon -a
sudo sh -c 'echo 3 > /proc/sys/vm/drop_caches'