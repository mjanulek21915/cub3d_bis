FILE=$1
if [ -z "$FILE" ]
then
    FILE=main
fi
gcc -g db_m_print/src/*.c _cub3d_debug/*.c lib/*.c main/$FILE.c src/*.c mlx_src/*.c debug/*.c -I db_m_print/include -L /usr/include/lib -I include -I /usr/include  -I db_m_print/include -lXext -lX11 -lm -lbsd -lXrandr