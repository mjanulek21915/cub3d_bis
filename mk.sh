FILE=$1
if [ -z "$FILE" ]
then
    FILE=main
fi
gcc -g main/$FILE.c mlx_src/*.c debug/*.c -L /usr/include/lib -I include -I /usr/include -lXext -lX11 -lm -lbsd -lmlx -lXrandr