#!/bin/sh

# if [ ! -f out.txt ]; then
#     touch out.txt
# else
#     rm out.txt
#     touch out.txt
# fi


# for i in {1..500}
# do
#     echo "hi\n" | nc ec2-18-216-96-228.us-east-2.compute.amazonaws.com 8000 >> out.txt
# done

nc ec2-18-216-96-228.us-east-2.compute.amazonaws.com 8000
echo "hi!\n"