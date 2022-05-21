diff ${DATA_PATH}/sample.txt ${DATA_PATH}/dst.txt
rm ${DATA_PATH}/dst.txt
rm ${DATA_PATH}/sample.txt
rm dup
sudo umount -f ${DATA_PATH}