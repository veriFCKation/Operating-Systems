gcc -w publisher.c -o publisher
gcc -w subscriber.c -o subscriber

for (( i = 1; i <= $1; i++ ))
do
	gnome-terminal -- ./subscriber
done
./publisher $1
